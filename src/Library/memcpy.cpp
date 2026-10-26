#include <globaldefs.h>
#include <std_library_functions.h>

ARM void* memcpy(void* dst, void* src, unsigned int length) {
    char* d = (char*)dst;
    char* s = (char*)src;
    if (length == 0) return dst;
    do {
        *d++ = *s++;
    } while (--length);
    return dst;
}
