#include <globaldefs.h>



#if defined(jpn)
enum { kSecondFadeOffset = 0x484 };
#else
enum { kSecondFadeOffset = 0x4f4 };
#endif

extern "C" void GXx_SetMasterBrightness_(short* out, int value);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);

struct MasterBrightnessFade {
    float currentBrightness;
    int targetBrightness;
    int remainingMilliseconds;
};

struct FieldGroup4f4_0218d800 {
    char unknown0[kSecondFadeOffset];
    MasterBrightnessFade subFade;
};

// USA: func_ov020_0218d800
ARM void UpdateFieldGroup4f4_0218d800(struct FieldGroup4f4_0218d800* display, int targetBrightness, int durationMilliseconds) {
    if (durationMilliseconds == 0) {
        GXx_SetMasterBrightness_((short*)0x400106c, targetBrightness);
        display->subFade.currentBrightness = (float)targetBrightness;
        display->subFade.targetBrightness = targetBrightness;
        display->subFade.remainingMilliseconds = 0;
    } else {
        int currentBrightness = GXx_GetMasterBrightness_((volatile unsigned short*)0x400106c);
        display->subFade.currentBrightness = (float)currentBrightness;
        display->subFade.targetBrightness = targetBrightness;
        display->subFade.remainingMilliseconds = durationMilliseconds;
    }
}
