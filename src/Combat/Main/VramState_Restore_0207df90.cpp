#include <globaldefs.h>
#include "Graphics/VramState.h"

void NNS_GfdSetFrmTexVramState(int* saved);
void NNS_GfdSetFrmPlttVramState(int* src);

// Main, originally RestorePairTables0207df90 (USA 0x0207df90, EUR 0x0207dfa0, JPN 0x0207ed10)
ARM void VramState_Restore(char* state) {
    VramState* self = (VramState*)state;
    NNS_GfdSetFrmTexVramState((int*)&self->texture);
    NNS_GfdSetFrmPlttVramState((int*)&self->palette);
}
