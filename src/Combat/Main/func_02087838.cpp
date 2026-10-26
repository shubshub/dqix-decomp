#include <globaldefs.h>

// USA: func_02087838
extern "C" ARM void func_02087838(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x400;
    *(int*)(base + 0x58) &= ~0x7;
    base[0x6e] = 0;
    base[0x91] = 0;
}
