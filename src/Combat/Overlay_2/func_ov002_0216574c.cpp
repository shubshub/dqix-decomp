#include <globaldefs.h>

// USA: func_ov002_0216574c
extern "C" ARM void func_ov002_0216574c(void* obj, int cond) {
    unsigned char* p = (unsigned char*)obj;
    int v = p[0xc5];
    if (cond) {
        v |= 0x8;
    } else {
        v &= ~0x8;
    }
    p[0xc5] = v;
}
