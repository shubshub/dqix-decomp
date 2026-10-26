#include <globaldefs.h>

// USA: func_02088854
extern "C" ARM void func_02088854(unsigned char* obj) {
    obj[0x5f] = 4;
    obj[0x82] = 0;
    *(int*)(obj + 0x14) |= 0x40;
}
