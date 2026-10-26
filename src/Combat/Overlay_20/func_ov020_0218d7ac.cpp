#include <globaldefs.h>



#if defined(jpn)
enum { Enum_ov020_0218d7ac_1256 = 0x478 };
#else
enum { Enum_ov020_0218d7ac_1256 = 0x4e8 };
#endif

extern "C" void GXx_SetMasterBrightness_(short* out, int value);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);

struct Struct_ov020_0218d7ac {
    float currentBrightness;
    int targetBrightness;
    int unknown_8_;
};

struct Struct_ov020_0218b710 {
    char unknown0[Enum_ov020_0218d7ac_1256];
    Struct_ov020_0218d7ac unknown_4e8_;
};

// USA: func_ov020_0218d7ac
extern "C" ARM void func_ov020_0218d7ac(struct Struct_ov020_0218b710* display, int targetBrightness, int arg2) {
    if (arg2 == 0) {
        GXx_SetMasterBrightness_((short*)0x400006c, targetBrightness);
        display->unknown_4e8_.currentBrightness = (float)targetBrightness;
        display->unknown_4e8_.targetBrightness = targetBrightness;
        display->unknown_4e8_.unknown_8_ = 0;
    } else {
        int currentBrightness = GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c);
        display->unknown_4e8_.currentBrightness = (float)currentBrightness;
        display->unknown_4e8_.targetBrightness = targetBrightness;
        display->unknown_4e8_.unknown_8_ = arg2;
    }
}
