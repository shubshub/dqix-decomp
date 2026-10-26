#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct Struct_020db894;
struct Struct_020db264;
struct Struct_020db3f4_3;
struct Struct_020db5ec_2;
struct Struct_020db3f4;

extern "C" void func_020db964(Struct_020db894* obj);
extern "C" int Overlay_IsLoaded(unsigned int idx);
extern "C" void func_020db894(void* obj);
extern "C" int func_020db9a8(Struct_020db264* obj);
extern "C" void func_020db3f4(Struct_020db3f4* obj);
extern "C" void VCountIrq_PushDisable(void);
extern "C" void func_020db844(Struct_020db3f4_3* a, int b, int c, int d);
extern "C" void func_020db264(void* obj, int arg1, int arg2, int arg3, int arg4);
extern "C" void VCountIrq_PopDisable(void);
extern "C" void func_020db5ec(Struct_020db5ec_2* obj);
extern "C" void func_020db814(void*);

// USA: func_020dbae0
extern "C" ARM void func_020dbae0(void* obj) {
    char* p = (char*)obj;
    func_020db964((Struct_020db894*)obj);
    if (!Overlay_IsLoaded(OVERLAY_ID(17))) {
        return;
    }
    void* resources = GetGameResources();
    if (*(unsigned char*)(p + 0x50) == 0 || resources == NULL) {
        func_020db894(obj);
        return;
    }
    if (*(unsigned char*)(p + 0x52) == 0) {
        short delay = *(short*)(p + 0x68);
        if (delay < 0) {
            return;
        }
        if (delay > 0) {
            *(short*)(p + 0x68) = delay - 1;
            func_020db894(obj);
            return;
        }
    }
    int swapBit = func_020db9a8((Struct_020db264*)obj);
    if (*(unsigned char*)(p + 0x51) == 0) {
        *(short*)(p + 0x6a) = *(short*)(p + 0x66);
        func_020db3f4((Struct_020db3f4*)obj);
    } else {
        if (swapBit != *(unsigned char*)(p + 0x3c)) {
            VCountIrq_PushDisable();
            func_020db844((Struct_020db3f4_3*)obj, *(unsigned char*)(p + 0x3c), *(short*)(p + 0x66), 0);
            short target = *(short*)(p + 0x6a);
            unsigned char a = *(unsigned char*)(p + 0x50);
            unsigned char b = *(unsigned char*)(p + 0x52);
            unsigned char c = *(unsigned char*)(p + 0x53);
            unsigned char d = *(unsigned char*)(p + 0x54);
            func_020db894(obj);
            *(short*)(p + 0x68) = 0;
            *(unsigned char*)(p + 0x3c) = swapBit;
            *(short*)(p + 0x6a) = *(short*)(p + 0x66) = target;
            func_020db264(obj, a, b, c, d);
            VCountIrq_PopDisable();
            return;
        }
        func_020db5ec((Struct_020db5ec_2*)obj);
    }
    func_020db814(obj);
}
