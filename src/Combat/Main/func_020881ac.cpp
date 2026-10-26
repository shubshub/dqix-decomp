#include <globaldefs.h>

// USA: func_020881ac
extern "C" ARM void func_020881ac(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x1000000;
    base[0x24] = 0;
}
