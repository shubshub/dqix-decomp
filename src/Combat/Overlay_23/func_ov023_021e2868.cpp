#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" void* func_ov023_021e2418(void* obj, int key);
struct Struct_ov023_021e2868;
extern "C" void func_ov023_021e2b5c(struct Struct_ov023_021e2868* obj, int key, short* out1, short* out2);

// USA: func_ov023_021e2868
extern "C" ARM int func_ov023_021e2868(void* obj) {
    if (g_touchInput.isRepeatValid_ == 0 || g_touchInput.currentReading_.isHeld == 0) return 0;

    int var0, var1;
    g_touchInput.GetTouchPoint(&var0, &var1);

    char* entry;
    unsigned short i;
    for (i = 0, entry = *(char**)((char*)obj + 8); i < *(unsigned short*)((char*)obj + 0x14); i++, entry = *(char**)((char*)obj + 8) + i * 0x18) {
        if (*(short*)(entry + 0xe) == 0 || !(*(unsigned char*)(entry + 0x16) & 2)) continue;

        void* cand = func_ov023_021db4e4(obj, *(short*)(entry + 0xe));
        while (cand != 0) {
            void* e = func_ov023_021e2418(obj, *(short*)cand);
            if (e == 0) {
                cand = func_ov023_021db4e4(obj, *(short*)((char*)cand + 0x12));
                continue;
            }
            short outB, outA;
            func_ov023_021e2b5c((struct Struct_ov023_021e2868*)obj, *(short*)e, &outB, &outA);
            if (outB > var0 || var0 > outB + *(short*)((char*)e + 8)) {
                cand = func_ov023_021db4e4(obj, *(short*)((char*)cand + 0x12));
                continue;
            }
            if (outA > var1 || var1 > outA + *(short*)((char*)e + 0xa)) {
                cand = func_ov023_021db4e4(obj, *(short*)((char*)cand + 0x12));
                continue;
            }
            return *(short*)cand;
        }
    }
    return 0;
}
