#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_020041f4
extern "C" ARM char* strrchr(const char* s, int c) {
    char ch = (char)c;
    char* p = (char*)s + 1;
    char* found = (char*)0;
    char v = *s;
    if (v != 0) {
        do {
            if (v == ch) {
                found = p - 1;
            }
            v = *p++;
        } while (v != 0);
    }
    if (found != 0) {
        return found;
    }
    return (ch != 0) ? (char*)0 : p - 1;
}
