#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_ov023_021e2c38(void* obj, int candidate);
extern "C" void* func_ov023_021e2418(void* obj, int candidate);
struct Struct_ov023_021e2868;
extern "C" void func_ov023_021e2b5c(struct Struct_ov023_021e2868* obj, int key, short* out1, short* out2);

// USA: func_ov023_021e29d0
extern "C" ARM int func_ov023_021e29d0(char* obj) {
    if (g_touchInput.pressed_ == 0) return -1;

    int outX, outY;
    g_touchInput.GetTouchPoint(&outX, &outY);

    unsigned short count = *(unsigned short*)(obj + 0x14);
    char* arr = *(char**)(obj + 8);
    unsigned short i;
    for (i = 0; i < count; i++) {
        short candidate = *(short*)(arr + i * 0x18);
        if (!func_ov023_021e2c38(obj, candidate)) continue;

        candidate = *(short*)(arr + i * 0x18);
        void* e = func_ov023_021e2418(obj, candidate);
        if (e == 0 || *((unsigned char*)e + 2) == 0) continue;

        short val = *(short*)e;
        short a, b;
        func_ov023_021e2b5c((struct Struct_ov023_021e2868*)obj, val, &a, &b);
        short eb = *(short*)((char*)e + 8);
        short var11 = *(short*)((char*)e + 0xa);
        short var12 = a + eb;
        short var13 = b + var11;
        if (b > outY) continue;
        if (outY >= var13) continue;
        if (a > outX) continue;
        if (outX < var12) {
            return *(short*)(arr + i * 0x18);
        }
    }
    return -1;
}
