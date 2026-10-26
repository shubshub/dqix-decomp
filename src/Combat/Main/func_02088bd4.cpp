#include <globaldefs.h>

// USA: func_02088bd4
extern "C" ARM void func_02088bd4(unsigned char* obj) {
    ((int*)obj)[5] &= ~0x80000000;
    obj[0x69] = 0;
    obj[0x8c] = 0;
}
