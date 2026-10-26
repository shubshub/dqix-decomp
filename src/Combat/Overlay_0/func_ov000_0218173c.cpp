#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void* obj, int idx);

// USA: func_ov000_0218173c
extern "C" ARM void func_ov000_0218173c(void* obj) {
    int i;
    for (i = 0; i < 4; i++) {
        char* p = (char*)func_ov000_02161318(obj, i);
        if (p != 0) {
            signed char off = *(signed char*)(p + 0x18);
            *(unsigned char*)(p + off + 0x10) = 0x67;
        }
    }
}
