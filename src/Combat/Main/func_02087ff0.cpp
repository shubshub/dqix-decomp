#include <globaldefs.h>

// USA: func_02087ff0
extern "C" ARM void func_02087ff0(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x2000000;
    *(int*)(base + 0x58) &= ~0x38000000;
    base[0x77] = 0;
    base[0x9a] = 0;
}
