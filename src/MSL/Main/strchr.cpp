#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_020041b8
extern "C" ARM char* strchr(const char* s, int c) {
    char ch = (char)c;
    char v = *s++;
    if (v != 0) {
        do {
            if (v == ch) {
                return (char*)s - 1;
            }
            v = *s++;
        } while (v != 0);
    }
    return (ch != 0) ? (char*)0 : (char*)s - 1;
}
