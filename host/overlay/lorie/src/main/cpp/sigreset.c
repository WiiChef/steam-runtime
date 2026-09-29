#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <cmd> [args...]\n", argv[0]);
        _exit(127);
    }

    sigset_t s;
    sigemptyset(&s);
    sigprocmask(SIG_SETMASK, &s, NULL);

    for (int sig = 1; sig <= 31; sig++) {
        if (sig != SIGKILL && sig != SIGSTOP) {
            signal(sig, SIG_DFL);
        }
    }

    for (int fd = 3; fd < 1024; fd++) {
        close(fd);
    }

    execv(argv[1], &argv[1]);
    perror("execv failed");
    _exit(127);
}
