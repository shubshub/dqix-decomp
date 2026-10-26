#include <globaldefs.h>

extern "C" void Zone3D_SaveAndOverrideElementVisibility(void* a, int b);

#if defined(jpn)
enum { Enum_ov000_021636ac_22865 = 0x5b41, effectsOffset = 0xe44, Enum_ov000_021636ac_21976 = 0x57c8 };
#else
enum { Enum_ov000_021636ac_22865 = 0x5951, effectsOffset = 0xec8, Enum_ov000_021636ac_21976 = 0x55d8 };
#endif

struct Struct_ov000_021636ac {
    unsigned char unknown_0_0_ : 3;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 3;
};

// USA: func_ov000_021636ac
extern "C" ARM void func_ov000_021636ac(void* objRaw) {
    if (((struct Struct_ov000_021636ac*)((char*)objRaw + Enum_ov000_021636ac_22865))->unknown_0_3_) {
        return;
    }
    Zone3D_SaveAndOverrideElementVisibility((char*)objRaw + effectsOffset, 1);
    ((struct Struct_ov000_021636ac*)((char*)objRaw + Enum_ov000_021636ac_22865))->unknown_0_3_ = 1;
    int v = *(int*)((char*)objRaw + Enum_ov000_021636ac_21976);
    ((struct Struct_ov000_021636ac*)((char*)objRaw + Enum_ov000_021636ac_22865))->unknown_0_4_ = (unsigned char)(v % 2);
}
