#include <globaldefs.h>

// USA: func_02088220
extern "C" ARM void func_02088220(void* obj, int value) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) |= 0x800000;
    base[0x24] = value;
}
