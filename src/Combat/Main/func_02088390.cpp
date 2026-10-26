#include <globaldefs.h>

// USA: func_02088390
extern "C" ARM void func_02088390(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x10;
    base[0x5d] = 0;
    base[0x80] = 0;
}
