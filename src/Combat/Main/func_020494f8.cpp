#include <globaldefs.h>

// USA: func_020494f8
extern "C" ARM void func_020494f8(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    p[8] |= 0x40;
}
