#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02004184
extern "C" ARM int strncmp(const char* s1, const char* s2, unsigned int n) {
    if (n != 0) {
        do {
            unsigned char c2 = (unsigned char)*s2++;
            unsigned char c1 = (unsigned char)*s1++;
            if (c1 != c2) {
                return (int)c1 - (int)c2;
            }
            if (c1 == 0) {
                break;
            }
        } while (--n);
    }
    return 0;
}
