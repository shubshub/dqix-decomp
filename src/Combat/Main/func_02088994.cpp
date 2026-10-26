#include <globaldefs.h>

// USA: func_02088994
extern "C" ARM void func_02088994(unsigned char* obj) {
    obj[0x62] = 5;
    obj[0x85] = 0;
    ((int*)obj)[5] |= 0x8000000;
}
