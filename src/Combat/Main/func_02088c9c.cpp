#include <globaldefs.h>

// USA: func_02088c9c
extern "C" ARM void func_02088c9c(unsigned char* obj) {
    ((int*)obj)[6] &= ~0x4;
    obj[0x6d] = 0;
    obj[0x90] = 0;
}
