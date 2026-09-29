/* robustshim: Android app seccomp returns ENOSYS for set/get_robust_list.
 * glibc still maintains each thread's robust list head in userspace
 * (struct pthread.robust_head); only kernel owner-death cleanup is lost.
 * Steam checks the list via syscall(SYS_get_robust_list) and aborts, so answer
 * that call from userspace. Build: gcc -shared -fPIC -O2 -o librobustshim.so robustshim.c -ldl */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/syscall.h>
#include <unistd.h>

struct rl_head { void *list; long futex_offset; void *pending; };
static long (*real_syscall)(long, ...);
static long head_off = -1;   /* offset of robust_head inside struct pthread */
static int kernel_ok = 0;    /* kernel supports the syscalls: pass through */

static void find_offset(void) {
    char *pd = (char *)pthread_self();
    for (long o = 0; o < 4096; o += 8) {
        struct rl_head *h = (struct rl_head *)(pd + o);
        if (h->list == (void *)h && h->futex_offset == -32) { head_off = o; return; }
    }
}

__attribute__((constructor)) static void init(void) {
    real_syscall = (long (*)(long, ...))dlsym(RTLD_NEXT, "syscall");
    void *h; size_t l;
    kernel_ok = real_syscall(SYS_get_robust_list, 0, &h, &l) == 0;
    if (!kernel_ok) find_offset();
}

long syscall(long n, ...) {
    va_list ap; va_start(ap, n);
    long a[6]; for (int i = 0; i < 6; i++) a[i] = va_arg(ap, long);
    va_end(ap);
    if (!real_syscall) init();
    if (!kernel_ok && head_off >= 0) {
        if (n == SYS_get_robust_list && (a[0] == 0 || a[0] == gettid())) {
            struct rl_head *h = (struct rl_head *)((char *)pthread_self() + head_off);
            if (!h->list) { h->list = h; h->futex_offset = -32; }
            *(void **)a[1] = h; *(size_t *)a[2] = sizeof(*h);
            return 0;
        }
        if (n == SYS_set_robust_list) return 0;
    }
    return real_syscall(n, a[0], a[1], a[2], a[3], a[4], a[5]);
}
