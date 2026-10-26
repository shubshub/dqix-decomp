#include <globaldefs.h>

// USA: func_02001ac0
extern "C" ARM void* func_02001ac0(void* s, int c, int n) {
    unsigned char* p = (unsigned char*)s;
    unsigned char ch = (unsigned char)c;
    if (n != 0) {
        do {
            unsigned char b = *p++;
            if (b == ch) {
                return p - 1;
            }
        } while (--n != 0);
    }
    return 0;
}
