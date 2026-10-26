#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"

extern "C" void CharacterModel_CancelLoads(void* model);

// Overlay 23, originally DestroyTenAndOne_021e4f18 (USA/EUR 0x021e4f18, JPN 0x021e50fc)
extern "C" ARM void CharacterModel_Destroy(void* obj) {
    CharacterModel* model = (CharacterModel*)obj;
    CharacterModel_CancelLoads(model);
    for (int i = 0; i < 10; i++) {
        model->parts_[i].Initialize();
        model->allocators_[i].Destroy();
    }
    model->animationAllocator_.Destroy();
}
