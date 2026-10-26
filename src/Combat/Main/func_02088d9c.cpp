#include <globaldefs.h>

// USA: func_02088d9c
extern "C" ARM void func_02088d9c(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x100;
    obj[0x7d] = 0;
    obj[0xa0] = 0;
}
