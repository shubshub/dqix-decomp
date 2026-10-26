#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void* obj, int id);
extern "C" void func_ov000_02174b14(void* obj);

// USA: func_ov000_021813d4
extern "C" ARM void func_ov000_021813d4(void* obj) {
    int i;
    for (i = 0; i < 4; i++) {
        void* slot = func_ov000_02161318(obj, i);
        if (slot) {
            signed char idx = *(signed char*)((char*)slot + 0x18);
            *(unsigned char*)((char*)slot + idx + 0x10) = 0x64;
            unsigned char flags = *(unsigned char*)((char*)slot + 0x24);
            flags &= ~0x4;
            *(unsigned char*)((char*)slot + 0x24) = flags;
            func_ov000_02174b14(obj);
        }
    }
}
