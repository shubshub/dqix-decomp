#include <globaldefs.h>
#include <World/Object3D.h>
#include "Graphics/CharacterModel.h"

static inline fix32_t inline_ov023_021e5e68(fix32_t arg0, fix32_t arg1)
{
    return (fix32_t)(((int64_t)arg0 * arg1 + 0x800) >> 12);
}

// Overlay 23, originally func_ov023_021e5e68 (USA/EUR 0x021e5e68, JPN 0x021e604c)
extern "C" ARM void CharacterModel_SetScale(CharacterModel* self, int width, int height)
{
    fix32_t scale = FX_Mul(height, width);
    self->parts_[CharacterModelPart_Body].SetScale(scale, height, scale);
    self->parts_[CharacterModelPart_Feet].SetScale(scale, height, scale);
    self->parts_[CharacterModelPart_Legs].SetScale(scale, height, scale);
    self->parts_[CharacterModelPart_Arms].SetScale(scale, height, scale);

    short inverse = fix32_Divide(0x1000, scale);
    short inverseHeight = fix32_Divide(0x1000, height);
    self->parts_[CharacterModelPart_Weapon].SetScale(inverse, inverseHeight, inverse);
    self->parts_[9].SetScale(inverse, inverseHeight, inverse);

    short x = FX_Mul(inverse, 0x1000);
    short y = FX_Mul(inverseHeight, 0x1000);
    short z = FX_Mul(0x1000, inverse);
    self->parts_[CharacterModelPart_Face].SetScale(x, y, z);
    self->parts_[CharacterModelPart_Hair].SetScale(x, y, z);
    self->parts_[CharacterModelPart_Headgear].SetScale(x, y, z);
}
