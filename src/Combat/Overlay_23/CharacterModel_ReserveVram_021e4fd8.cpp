#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"

extern "C" void VramState_Reserve(void* state, int textureSize, int paletteSize);
extern int CharacterModel_partTextureVramSizes[];
extern int CharacterModel_partPaletteVramSizes[];

// Overlay 23, originally InitBlockArray_021e4fd8 (USA/EUR 0x021e4fd8, JPN 0x021e51bc)
ARM void CharacterModel_ReserveVram(void* obj) {
    CharacterModel* model = (CharacterModel*)obj;
    for (int i = 0; i < 10; i++) {
        VramState_Reserve(&model->vramStates_[i], CharacterModel_partTextureVramSizes[i], CharacterModel_partPaletteVramSizes[i]);
    }
}
