#include <globaldefs.h>

// USA: func_02088cf4
extern "C" ARM void func_02088cf4(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x8;
    obj[0x6b] = 0;
    obj[0x8e] = 0;
}
