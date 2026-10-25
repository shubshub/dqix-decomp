#include <globaldefs.h>

#if defined(jpn)
#define func_020c39c8 func_020c5494
#endif


#if defined(jpn)
enum { kFirstFadeOffset = 0x478 };
#else
enum { kFirstFadeOffset = 0x4e8 };
#endif

extern "C" void GXx_SetMasterBrightness_(short* out, int value);
extern "C" int func_020c39c8(volatile unsigned short* p);

struct MasterBrightnessFade {
    float currentBrightness;
    int targetBrightness;
    int remainingMilliseconds;
};

struct FieldGroup4e8_0218d7ac {
    char unknown0[kFirstFadeOffset];
    MasterBrightnessFade mainFade;
};

// USA: func_ov020_0218d7ac
ARM void UpdateFieldGroup4e8_0218d7ac(struct FieldGroup4e8_0218d7ac* display, int targetBrightness, int durationMilliseconds) {
    if (durationMilliseconds == 0) {
        GXx_SetMasterBrightness_((short*)0x400006c, targetBrightness);
        display->mainFade.currentBrightness = (float)targetBrightness;
        display->mainFade.targetBrightness = targetBrightness;
        display->mainFade.remainingMilliseconds = 0;
    } else {
        int currentBrightness = func_020c39c8((volatile unsigned short*)0x400006c);
        display->mainFade.currentBrightness = (float)currentBrightness;
        display->mainFade.targetBrightness = targetBrightness;
        display->mainFade.remainingMilliseconds = durationMilliseconds;
    }
}
