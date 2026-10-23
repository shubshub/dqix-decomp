#include <globaldefs.h>
#include "Resource/CreationEnums.h"
#include "NitroSDK/ColorEffects.h"

#if defined(jpn)
#endif

extern "C" void func_ov023_021dacd4(void*, int, int);

struct Obj021dac40 {
#if defined(jpn)
    char unknown0[0xd5c];
#else
    char unknown0[0xd98];
#endif
    short fadeTicksRemaining;
    char unknownAfterTimer[2];
    int flags;
};

enum { kFadeDurationTicks = 90, kMaxPolygonAlpha = 31, kMaxBrightnessAdjustment = 16 };

// Overlay 23, originally func_ov023_021dac40 (USA/EUR 0x021dac40, JPN 0x021db4b4)
extern "C" ARM void CharacterCreationUI_UpdateDim(Obj021dac40* obj, int elapsedTicks) {
    if (!(obj->flags & CreationFlag_DimBackground)) return;
    obj->fadeTicksRemaining -= elapsedTicks;
    if (obj->fadeTicksRemaining < 0) obj->fadeTicksRemaining = 0;
    if (obj->flags & CreationFlag_DimWithQuad) {
        int alphaRemaining = obj->fadeTicksRemaining * kMaxPolygonAlpha / kFadeDurationTicks;
        func_ov023_021dacd4(obj, 0, kMaxPolygonAlpha - alphaRemaining);
        return;
    }
    int brightness = -((kFadeDurationTicks - obj->fadeTicksRemaining) * kMaxBrightnessAdjustment) / kFadeDurationTicks;
    ColorEffect_ConfigureBrightnessAdjust(0x4000050, 0x16, brightness);
}
