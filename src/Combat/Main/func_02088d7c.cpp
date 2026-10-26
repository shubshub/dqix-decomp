#include <globaldefs.h>

// USA: func_02088d7c
extern "C" ARM void func_02088d7c(unsigned char* obj) {
    obj[0x7d] = 5;
    obj[0xa0] = 0;
    *(int*)(obj + 0x18) |= 0x100;
}
