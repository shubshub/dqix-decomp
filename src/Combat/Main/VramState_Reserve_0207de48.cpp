#include <globaldefs.h>
#include "Graphics/VramState.h"

void NNS_GfdGetFrmTexVramState(int* out);
void NNS_GfdGetFrmPlttVramState(int* dst);
extern "C" int NNS_GfdAllocFrmTexVram(unsigned int size, int fromFront, int unused);
extern "C" int NNS_GfdAllocFrmPlttVram(unsigned int size, int b4Pltt, int bAllocFromLo);

// Main, originally func_0207de48 (USA 0x0207de48, EUR 0x0207de58, JPN 0x0207ebc8)
extern "C" ARM void VramState_Reserve(void* state, int textureSize, int paletteSize) {
    struct VramState* self = (struct VramState*)state;
    NNS_GfdGetFrmTexVramState((int*)&self->startTexture);
    self->texture = self->startTexture;
    NNS_GfdGetFrmPlttVramState(self->startPalette.bounds);
    int remaining = textureSize;
    self->palette = self->startPalette;
    self->textureKey = 0;

    while (remaining > 0) {
        if (remaining > 0x20000) {
            self->textureKey = NNS_GfdAllocFrmTexVram(0x20000, 0, 0);
            remaining -= 0x20000;
        } else {
            self->textureKey = NNS_GfdAllocFrmTexVram(remaining, 0, 0);
            remaining = 0;
        }
    }
    if (textureSize != 0 && self->textureKey == 0) textureSize = 0;

    self->paletteKey = 0;
    if (paletteSize != 0) {
        self->paletteKey = NNS_GfdAllocFrmPlttVram(paletteSize, 0, 0);
    }
    if (paletteSize != 0 && self->paletteKey == 0) paletteSize = 0;

    self->textureSize = textureSize;
    self->paletteSize = paletteSize;
}
