#include <globaldefs.h>

// USA: func_02088874
extern "C" ARM void func_02088874(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x40;
    obj[0x5f] = 0;
    obj[0x82] = 0;
}
