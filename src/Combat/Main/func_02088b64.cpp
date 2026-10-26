#include <globaldefs.h>

// USA: func_02088b64
extern "C" ARM void func_02088b64(unsigned char* obj) {
    obj[0x68] = 6;
    obj[0x8b] = 0;
    ((int*)obj)[5] |= 0x40000000;
}
