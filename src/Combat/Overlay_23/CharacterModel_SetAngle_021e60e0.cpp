#include <globaldefs.h>
#include "Graphics/CharacterModel.h"

struct Words021e60c4 { unsigned int x, y, z; };
extern "C" void __clear(void*, int);
extern "C" void Object3D_SetRotation(void* part, struct Words021e60c4* rotation);

// Overlay 23, originally InitWordsQuad_021e60e0 (USA/EUR 0x021e60e0, JPN 0x021e62c4)
extern "C" ARM void CharacterModel_SetAngle(void* model, unsigned int angle) {
    struct Words021e60c4 rotation;
    __clear(&rotation, sizeof(rotation));
    rotation.y = angle;
    CharacterModel* self = (CharacterModel*)model;
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Body], &rotation);
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Feet], &rotation);
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Legs], &rotation);
    Object3D_SetRotation(&self->parts_[CharacterModelPart_Arms], &rotation);
}
