#include <globaldefs.h>

// USA: func_02088338
extern "C" ARM void func_02088338(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x800000;
    obj[0x24] = 0;
    *(int*)(obj + 0x14) &= ~0x80000;
    *(unsigned short*)(obj + 0x22) &= ~0x3c;
    obj[0x21] = 0;
    *(int*)(obj + 0x18) &= ~0x20;
    obj[0x5d] = 1;
    obj[0x80] = 0;
    *(int*)(obj + 0x14) |= 0x10;
}
