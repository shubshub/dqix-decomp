#include <globaldefs.h>

// USA: func_02088a94
extern "C" ARM void func_02088a94(unsigned char* obj) {
    *(int*)(obj + 0x14) = (*(int*)(obj + 0x14) | 0x100000) & ~0x200000;
}
