#include <globaldefs.h>

// USA: func_0204947c
extern "C" ARM void func_0204947c(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x4d] = value;
    }
}
