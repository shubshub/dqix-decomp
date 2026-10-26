#include <globaldefs.h>

// USA: func_02087b14
extern "C" ARM void func_02087b14(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x2000;
    *(int*)(base + 0x58) &= ~0xe00;
    base[0x71] = 0;
    base[0x94] = 0;
}
