#include <globaldefs.h>

// USA: func_02088560
extern "C" ARM void func_02088560(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x2;
    *(unsigned short*)(obj + 0x22) &= ~0x3;
    *(int*)(obj + 0x14) |= 0x2;
    *(unsigned short*)(obj + 0x22) = (*(unsigned short*)(obj + 0x22) & ~0x3) | 0x2;
}
