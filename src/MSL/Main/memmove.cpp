#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02001a60
extern "C" ARM void* memmove(void* dst, const void* src, unsigned int n) {
    if ((const char*)src >= (const char*)dst) {
        char* d = (char*)dst;
        const char* s = (const char*)src;
        if (n != 0) {
            do {
                *d++ = *s++;
            } while (--n);
        }
        return dst;
    }
    const char* s = (const char*)src + n;
    char* d = (char*)dst + n;
    if (n != 0) {
        do {
            *--d = *--s;
        } while (--n);
    }
    return dst;
}
