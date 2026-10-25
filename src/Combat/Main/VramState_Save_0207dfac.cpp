#include <globaldefs.h>
#include "Graphics/VramState.h"

void NNS_GfdGetFrmTexVramState(int* out);
void NNS_GfdGetFrmPlttVramState(int* dst);

// Main, originally BackupPairTables0207dfac (USA 0x0207dfac, EUR 0x0207dfbc, JPN 0x0207ed2c)
ARM void VramState_Save(char* state) {
    VramState* self = (VramState*)state;
    NNS_GfdGetFrmTexVramState((int*)&self->texture);
    NNS_GfdGetFrmPlttVramState((int*)&self->palette);
}
