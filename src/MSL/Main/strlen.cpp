#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02003f0c
extern "C" ARM unsigned int strlen(const char* s) {
    unsigned int n = (unsigned int)-1;
    do {
        n++;
    } while (*s++ != 0);
    return n;
}
