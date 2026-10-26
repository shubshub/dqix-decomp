#include <globaldefs.h>

// USA: func_02088e64
extern "C" ARM void func_02088e64(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x1000;
    obj[0x7e] = 0;
    obj[0xa1] = 0;
}
