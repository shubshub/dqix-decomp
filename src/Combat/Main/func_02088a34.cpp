#include <globaldefs.h>

// USA: func_02088a34
extern "C" ARM void func_02088a34(unsigned char* obj) {
    obj[0x64] = 4;
    obj[0x87] = 0;
    *(int*)(obj + 0x14) |= 0x20000000;
}
