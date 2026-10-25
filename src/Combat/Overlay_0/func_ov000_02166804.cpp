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

struct Struct_0203d028 {
    char unknown_0_[0x68];
};
void VramState_Rewind(struct Foo0207df50* p);

struct Struct_ov000_02166804 {
    char unknown_0_[0x44 - sizeof(SafeAllocator)];
    SafeAllocator unknown_30_[2];
    char unknown_58_[REGION_OFFSET_0 - sizeof(struct Struct_0203d028) - 0x44 - sizeof(SafeAllocator)];
    struct Struct_0203d028 unknown_154_[2];
    char unknown_224_[REGION_OFFSET_1 - REGION_OFFSET_0 - sizeof(struct Struct_0203d028)];
    void* unknown_eb8_[4];
};

static inline SafeAllocator* inline_ov000_02166804(struct Struct_ov000_02166804* arg0, int arg1) {
    return &arg0->unknown_30_[arg1];
}

static inline struct Struct_0203d028* inline_ov000_02166804_2(struct Struct_ov000_02166804* arg0, int arg1) {
    return &arg0->unknown_154_[arg1];
}

// USA: func_ov000_02166804
extern "C" ARM void func_ov000_02166804(struct Struct_ov000_02166804* arg0) {
    GameState* var0 = GameState::GetInstance();
    short var1;
    for (var1 = 0xc0; var1 <= 0xc7; var1++) {
        GameObject* var2 = var0->GetGameObjectByIndex(var1);
        if (var2 != NULL) {
            var2->obj3D_.Destroy();
        }
    }
    for (int var3 = 0; var3 < 4; var3++) {
        arg0->unknown_eb8_[var3] = NULL;
    }
    SafeAllocator* allocator = GetAllocator(scene, 1);
    struct Foo0207df50* pairTables = GetPairTables(scene, 1);
    allocator->Reset();
    VramState_Rewind(pairTables);
}
