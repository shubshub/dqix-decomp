#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"

extern unsigned int CharacterModel_partAllocatorSizes[10];

// Overlay 23, originally CreateTenAndOne_021e4f64 (USA/EUR 0x021e4f64, JPN 0x021e5148)
extern "C" ARM void CharacterModel_CreateAllocators(void* obj, SafeAllocator* allocator) {
    CharacterModel* model = (CharacterModel*)obj;
    for (int i = 0; i < 10; i++) {
        unsigned int size = CharacterModel_partAllocatorSizes[i];
        void* buffer = allocator->Allocate(size);
        model->allocators_[i].CreateTypeA(buffer, size);
    }
    void* buffer = allocator->Allocate(0x1000);
    model->animationAllocator_.CreateTypeA(buffer, 0x1000);
}
