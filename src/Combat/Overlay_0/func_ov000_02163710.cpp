#include <globaldefs.h>

extern "C" void Zone3D_RestoreElementVisibility(void* ptr, int flag);

#if defined(jpn)
enum { Enum_ov000_02163710_22865 = 0x5b41, effectsOffset = 0xe44, Enum_ov000_02163710_21976 = 0x57c8 };
#else
enum { Enum_ov000_02163710_22865 = 0x5951, effectsOffset = 0xec8, Enum_ov000_02163710_21976 = 0x55d8 };
#endif

struct Struct_ov000_02163710 {
    unsigned char pad0 : 3;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char pad1 : 3;
};

// USA: func_ov000_02163710
extern "C" ARM void func_ov000_02163710(void* obj, int flag) {
    struct Struct_ov000_02163710* f = (struct Struct_ov000_02163710*)((char*)obj + Enum_ov000_02163710_22865);
    if (!f->unknown_0_3_) {
        return;
    }
    if (flag == 0) {
        int val = *(int*)((char*)obj + Enum_ov000_02163710_21976);
        if ((int)f->unknown_0_4_ == val % 2) {
            return;
        }
    }
    Zone3D_RestoreElementVisibility((char*)obj + effectsOffset, 1);
    ((struct Struct_ov000_02163710*)((unsigned int)obj + Enum_ov000_02163710_22865))->unknown_0_3_ = 0;
}
