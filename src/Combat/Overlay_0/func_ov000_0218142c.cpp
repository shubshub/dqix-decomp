#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void* obj, int id);

// USA: func_ov000_0218142c
extern "C" ARM void func_ov000_0218142c(void* obj, int val) {
    if (val < 0) {
        for (int i1 = 0; i1 < 4; i1++) {
            char* entry = (char*)func_ov000_02161318(obj, i1);
            if (entry) {
                signed char off = *(signed char*)(entry + 0x18);
                *(entry + off + 0x10) = 0x66;
            }
        }
    } else {
        for (int i2 = 0; i2 < 4; i2++) {
            char* entry = (char*)func_ov000_02161318(obj, i2);
            if (entry) {
                if (val == *(int*)(entry + 0x4c)) {
                    signed char off = *(signed char*)(entry + 0x18);
                    *(entry + off + 0x10) = 0x66;
                    return;
                }
            }
        }
    }
}
