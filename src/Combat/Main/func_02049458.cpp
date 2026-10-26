#include <globaldefs.h>

// USA: func_02049458
extern "C" ARM void func_02049458(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x4c] = value;
    }
}
