#include <globaldefs.h>

// USA: func_02088d4c
extern "C" ARM void func_02088d4c(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x10;
    obj[0x7b] = 0;
    obj[0x9e] = 0;
}
