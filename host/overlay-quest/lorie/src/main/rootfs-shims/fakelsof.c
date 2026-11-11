#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

#ifndef __NR_pidfd_open
#define __NR_pidfd_open 434
#endif
#ifndef __NR_pidfd_getfd
#define __NR_pidfd_getfd 438
#endif

static inline int sys_pidfd_open(pid_t pid, unsigned int flags) {
    return syscall(__NR_pidfd_open, pid, flags);
}

static inline int sys_pidfd_getfd(int pidfd, int targetfd, unsigned int flags) {
    return syscall(__NR_pidfd_getfd, pidfd, targetfd, flags);
}

static int get_ppid(pid_t pid) {
    char path[64];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    char buf[1024];
    if (!fgets(buf, sizeof(buf), f)) {
        fclose(f);
        return 0;
    }
    fclose(f);
    char *p = strrchr(buf, ')');
    if (!p) return 0;
    char state;
    int ppid = 0;
    if (sscanf(p + 2, "%c %d", &state, &ppid) == 2) {
        return ppid;
    }
    return 0;
}

static int format_addr(struct sockaddr_storage *ss, char *ip_out, size_t ip_len, int *port_out) {
    if (ss->ss_family == AF_INET) {
        struct sockaddr_in *sin = (struct sockaddr_in *)ss;
        inet_ntop(AF_INET, &sin->sin_addr, ip_out, ip_len);
        *port_out = ntohs(sin->sin_port);
        return 1;
    } else if (ss->ss_family == AF_INET6) {
        struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)ss;
        if (IN6_IS_ADDR_V4MAPPED(&sin6->sin6_addr)) {
            struct in_addr v4addr;
            memcpy(&v4addr, &sin6->sin6_addr.s6_addr[12], 4);
            inet_ntop(AF_INET, &v4addr, ip_out, ip_len);
        } else {
            inet_ntop(AF_INET6, &sin6->sin6_addr, ip_out, ip_len);
        }
        *port_out = ntohs(sin6->sin6_port);
        return 1;
    }
    return 0;
}

static int matches_endpoint(const char *ip, int port, const char *req_ip, int has_req_ip, int req_port, int has_req_port) {
    if (has_req_port && port != req_port) {
        return 0;
    }
    if (has_req_ip) {
        if (strcmp(ip, req_ip) == 0) return 1;
        if ((strcmp(req_ip, "127.0.0.1") == 0 || strcmp(req_ip, "localhost") == 0) &&
            (strcmp(ip, "0.0.0.0") == 0 || strcmp(ip, "::") == 0 || strcmp(ip, "::1") == 0)) {
            return 1;
        }
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int show_R = 0, show_n = 0, show_f = 1;
    char target_ip[64] = "";
    int target_port = 0;
    int has_target_ip = 0;
    int has_target_port = 0;

    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];
        if (strcmp(arg, "-P") == 0 || strcmp(arg, "-n") == 0 || strcmp(arg, "-a") == 0) {
            continue;
        } else if (strncmp(arg, "-F", 2) == 0) {
            const char *fields = arg + 2;
            if (*fields == '\0' && i + 1 < argc && argv[i + 1][0] != '-') {
                fields = argv[++i];
            }
            if (*fields == '\0') {
                show_R = show_n = show_f = 1;
            } else {
                show_R = (strchr(fields, 'R') != NULL);
                show_n = (strchr(fields, 'n') != NULL);
                show_f = 1;
            }
        } else if (strncmp(arg, "-i", 2) == 0) {
            const char *spec = arg + 2;
            if (*spec == '\0' && i + 1 < argc && argv[i + 1][0] != '-') {
                spec = argv[++i];
            }
            if (strncasecmp(spec, "TCP@", 4) == 0) spec += 4;
            else if (strncasecmp(spec, "TCP:", 4) == 0) spec += 4;
            else if (strncasecmp(spec, "TCP", 3) == 0) spec += 3;
            if (*spec == '@') spec++;

            const char *colon = strrchr(spec, ':');
            if (colon) {
                target_port = atoi(colon + 1);
                has_target_port = 1;
                int ip_len = colon - spec;
                if (ip_len > 0 && ip_len < (int)sizeof(target_ip)) {
                    strncpy(target_ip, spec, ip_len);
                    target_ip[ip_len] = '\0';
                    has_target_ip = 1;
                }
            } else {
                char *endptr;
                long p = strtol(spec, &endptr, 10);
                if (*endptr == '\0' && p > 0 && p <= 65535) {
                    target_port = (int)p;
                    has_target_port = 1;
                } else if (*spec) {
                    strncpy(target_ip, spec, sizeof(target_ip) - 1);
                    has_target_ip = 1;
                }
            }
        }
    }

    DIR *proc = opendir("/proc");
    if (!proc) return 1;

    int total_matches = 0;
    struct dirent *ent;
    while ((ent = readdir(proc)) != NULL) {
        if (!isdigit(ent->d_name[0])) continue;
        pid_t pid = atoi(ent->d_name);
        if (pid <= 0) continue;

        char fd_dir_path[64];
        snprintf(fd_dir_path, sizeof(fd_dir_path), "/proc/%d/fd", pid);
        DIR *fd_dir = opendir(fd_dir_path);
        if (!fd_dir) continue;

        int pidfd = -1;
        int proc_header_printed = 0;
        struct dirent *fd_ent;

        while ((fd_ent = readdir(fd_dir)) != NULL) {
            if (!isdigit(fd_ent->d_name[0])) continue;
            int target_fd = atoi(fd_ent->d_name);

            char link_path[512];
            char link_target[256];
            snprintf(link_path, sizeof(link_path), "/proc/%d/fd/%s", pid, fd_ent->d_name);
            ssize_t len = readlink(link_path, link_target, sizeof(link_target) - 1);
            if (len <= 0) continue;
            link_target[len] = '\0';

            if (strncmp(link_target, "socket:[", 8) != 0) continue;

            if (pidfd < 0) {
                pidfd = sys_pidfd_open(pid, 0);
                if (pidfd < 0) break;
            }

            int sock = sys_pidfd_getfd(pidfd, target_fd, 0);
            if (sock < 0) continue;

            int type = 0;
            socklen_t optlen = sizeof(type);
            if (getsockopt(sock, SOL_SOCKET, SO_TYPE, &type, &optlen) < 0 || type != SOCK_STREAM) {
                close(sock);
                continue;
            }

            struct sockaddr_storage local_ss, peer_ss;
            socklen_t local_len = sizeof(local_ss);
            socklen_t peer_len = sizeof(peer_ss);

            if (getsockname(sock, (struct sockaddr *)&local_ss, &local_len) < 0) {
                close(sock);
                continue;
            }

            int has_peer = (getpeername(sock, (struct sockaddr *)&peer_ss, &peer_len) == 0);
            close(sock);

            char local_ip[INET6_ADDRSTRLEN] = "";
            int local_port = 0;
            if (!format_addr(&local_ss, local_ip, sizeof(local_ip), &local_port)) {
                continue;
            }

            char peer_ip[INET6_ADDRSTRLEN] = "";
            int peer_port = 0;
            if (has_peer) {
                format_addr(&peer_ss, peer_ip, sizeof(peer_ip), &peer_port);
            }

            int local_match = matches_endpoint(local_ip, local_port, target_ip, has_target_ip, target_port, has_target_port);
            int peer_match = has_peer && matches_endpoint(peer_ip, peer_port, target_ip, has_target_ip, target_port, has_target_port);

            if (local_match || peer_match) {
                if (!proc_header_printed) {
                    printf("p%d\n", pid);
                    if (show_R) printf("R%d\n", get_ppid(pid));
                    proc_header_printed = 1;
                }
                if (show_f) printf("f%d\n", target_fd);
                if (show_n) {
                    if (has_peer && peer_port > 0) {
                        printf("n%s:%d->%s:%d\n", local_ip, local_port, peer_ip, peer_port);
                    } else {
                        printf("n%s:%d\n", local_ip, local_port);
                    }
                }
                total_matches++;
            }
        }

        if (pidfd >= 0) close(pidfd);
        closedir(fd_dir);
    }
    closedir(proc);

    return total_matches > 0 ? 0 : 1;
}
