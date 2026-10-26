#include <globaldefs.h>

// USA: func_02088bb4
extern "C" ARM void func_02088bb4(unsigned char* obj) {
    obj[0x69] = 6;
    obj[0x8c] = 0;
    ((int*)obj)[5] |= 0x80000000;
}
