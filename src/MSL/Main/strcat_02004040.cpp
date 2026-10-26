#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02004040
extern "C" ARM char* strcat(char* dst, const char* src) {
    char* p = dst;
    while (*p++ != 0) {
    }
    p--;
    do {
        char c = *src++;
        char* q = p++;
        *q = c;
        if (*q == 0) {
            break;
        }
    } while (1);
    return dst;
}
