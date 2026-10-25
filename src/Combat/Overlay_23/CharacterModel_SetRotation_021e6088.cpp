#include <globaldefs.h>
#include "Graphics/CharacterModel.h"

struct Words021e60c4 { unsigned int x, y, z; };
void Object3D_SetRotation(void* part, struct Words021e60c4* rotation);

// Overlay 23, originally SetFourWordBlocks_021e6088 (USA/EUR 0x021e6088, JPN 0x021e626c)
ARM void CharacterModel_SetRotation(void* model, struct Words021e60c4* rotation) {
    CharacterModel* self = (CharacterModel*)model;
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Body], rotation);
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Feet], rotation);
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Legs], rotation);
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Arms], rotation);
}
