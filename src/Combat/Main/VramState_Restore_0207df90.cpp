#include <globaldefs.h>
#include "Graphics/VramState.h"

extern "C" void NNS_GfdSetFrmTexVramState(int* saved);
extern "C" void NNS_GfdSetFrmPlttVramState(int* src);

// Main, originally RestorePairTables0207df90 (USA 0x0207df90, EUR 0x0207dfa0, JPN 0x0207ed10)
extern "C" ARM void VramState_Restore(char* state) {
    VramState* self = (VramState*)state;
    NNS_GfdSetFrmTexVramState((int*)&self->texture);
    NNS_GfdSetFrmPlttVramState((int*)&self->palette);
}
