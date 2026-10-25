#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/HWRegisters.h"


extern "C" void CharacterCreationUI_DrawFullscreenQuad(void*, int, int);

enum { kFadeDurationTicks = 90, kMaxPolygonAlpha = 31, kMaxBrightnessAdjustment = 16 };

// Overlay 23, originally func_ov023_021dac40 (USA/EUR 0x021dac40, JPN 0x021db4b4)
extern "C" ARM void CharacterCreationUI_UpdateDim(CharacterCreationUI* self, int elapsedTicks) {
    if (!(self->flags & CreationFlag_DimBackground)) return;
    self->dimTimer -= elapsedTicks;
    if (self->dimTimer < 0) self->dimTimer = 0;
    if (self->flags & CreationFlag_DimWithQuad) {
        int alphaRemaining = self->dimTimer * kMaxPolygonAlpha / kFadeDurationTicks;
        CharacterCreationUI_DrawFullscreenQuad(self, 0, kMaxPolygonAlpha - alphaRemaining);
        return;
    }
    int brightness = -((kFadeDurationTicks - self->dimTimer) * kMaxBrightnessAdjustment) / kFadeDurationTicks;
    ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, BLEND_TARGET_BG1 | BLEND_TARGET_BG2 | BLEND_TARGET_OBJ, brightness);
}
