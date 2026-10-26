#include <globaldefs.h>

// USA: func_02087a20
extern "C" ARM void func_02087a20(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x1000;
    *(int*)(base + 0x58) &= ~0x1c0;
    base[0x70] = 0;
    base[0x93] = 0;
}
