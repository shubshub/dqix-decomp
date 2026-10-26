#include <globaldefs.h>



#if defined(jpn)
enum { Enum_ov020_0218d800_1268 = 0x484 };
#else
enum { Enum_ov020_0218d800_1268 = 0x4f4 };
#endif

extern "C" void GXx_SetMasterBrightness_(short* out, int value);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);

struct Struct_ov020_0218d7ac {
    float currentBrightness;
    int targetBrightness;
    int unknown_8_;
};

struct Struct_ov020_0218b710_2 {
    char unknown0[Enum_ov020_0218d800_1268];
    Struct_ov020_0218d7ac unknown_4f4_;
};

// USA: func_ov020_0218d800
extern "C" ARM void func_ov020_0218d800(struct Struct_ov020_0218b710_2* display, int targetBrightness, int arg2) {
    if (arg2 == 0) {
        GXx_SetMasterBrightness_((short*)0x400106c, targetBrightness);
        display->unknown_4f4_.currentBrightness = (float)targetBrightness;
        display->unknown_4f4_.targetBrightness = targetBrightness;
        display->unknown_4f4_.unknown_8_ = 0;
    } else {
        int currentBrightness = GXx_GetMasterBrightness_((volatile unsigned short*)0x400106c);
        display->unknown_4f4_.currentBrightness = (float)currentBrightness;
        display->unknown_4f4_.targetBrightness = targetBrightness;
        display->unknown_4f4_.unknown_8_ = arg2;
    }
}
