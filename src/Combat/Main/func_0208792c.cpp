#include <globaldefs.h>

// USA: func_0208792c
extern "C" ARM void func_0208792c(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x800;
    *(int*)(base + 0x58) &= ~0x38;
    base[0x6f] = 0;
    base[0x92] = 0;
}
