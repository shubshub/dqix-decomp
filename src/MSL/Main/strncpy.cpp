#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02003ff0
extern "C" ARM char* strncpy(char* dst, const char* src, unsigned int n) {
    char* d = dst;
    if (n != 0) {
        for (;;) {
            char c = *src++;
            char* q = d;
            *d++ = c;
            if (*q == 0) {
                if (--n != 0) {
                    do {
                        *d++ = 0;
                    } while (--n);
                }
                break;
            }
            if (--n == 0) {
                break;
            }
        }
    }
    return dst;
}
