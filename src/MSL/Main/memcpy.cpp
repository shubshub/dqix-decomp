#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02001a40
extern "C" ARM void* memcpy(void* dst, void* src, unsigned int length) {
    char* d = (char*)dst;
    char* s = (char*)src;
    if (length != 0) {
        do {
            *d++ = *s++;
        } while (--length);
    }
    return dst;
}
