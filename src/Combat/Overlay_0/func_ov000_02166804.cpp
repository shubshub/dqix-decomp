#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1a8
#define REGION_OFFSET_1 0xe34
#else
#define REGION_OFFSET_0 0x1bc
#define REGION_OFFSET_1 0xeb8
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Foo0207df50 {
    char unk_0[0x68];
};
extern "C" void VramState_Rewind(struct Foo0207df50* p);

struct Struct_ov000_02166804 {
    char unk_0[0x44 - sizeof(SafeAllocator)];
    SafeAllocator allocators[2];
    char unknown_58_[REGION_OFFSET_0 - sizeof(struct Foo0207df50) - 0x44 - sizeof(SafeAllocator)];
    struct Foo0207df50 pairTables[2];
    char unknown_224_[REGION_OFFSET_1 - REGION_OFFSET_0 - sizeof(struct Foo0207df50)];
    void* nodes[4];
};

static inline SafeAllocator* inline_ov000_02166804(struct Struct_ov000_02166804* scene, int index) {
    return &scene->allocators[index];
}

static inline struct Foo0207df50* inline_ov000_02166804_2(struct Struct_ov000_02166804* scene, int index) {
    return &scene->pairTables[index];
}

// USA: func_ov000_02166804
extern "C" ARM void func_ov000_02166804(struct Struct_ov000_02166804* scene) {
    GameState* state = GameState::GetInstance();
    short i;
    for (i = 0xc0; i <= 0xc7; i++) {
        GameObject* obj = state->GetGameObjectByIndex(i);
        if (obj != NULL) {
            obj->obj3D_.Destroy();
        }
    }
    for (int j = 0; j < 4; j++) {
        scene->nodes[j] = NULL;
    }
    SafeAllocator* allocator = inline_ov000_02166804(scene, 1);
    struct Foo0207df50* pairTables = inline_ov000_02166804_2(scene, 1);
    allocator->Reset();
    VramState_Rewind(pairTables);
}
