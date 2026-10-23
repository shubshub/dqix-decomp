#include <globaldefs.h>
#include "NitroSDK/HWRegisters.h"
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterModel_Draw(void*, void*);

// Overlay 9, originally func_ov009_02184c30 (USA/EUR 0x02184c30, JPN 0x02185f5c)
extern "C" ARM void CharacterCreationUI_Draw3D(void* storage) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
    if (self->state == CreationTab_Setup || self->state == CreationTab_Done)
        return;
    GXFIFO_MATRIX_PUSH = 0;
    CharacterModel_Draw(self->character, 0);
    if (self->flags & CreationFlag_ShowFinishModels) {
        self->wings.Draw(true);
        self->finishEffect.Draw(true);
    }
    GXFIFO_MATRIX_POP = 1;
}
