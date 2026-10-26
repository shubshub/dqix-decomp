#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

struct Struct_ov025_021e87f4 {
    char pad[8];
    unsigned char idx;
    char pad2[3];
    int val;
};

struct Struct_ov025_021e87f4_2 {
    unsigned int v[3];
};

struct Struct_ov025_021e87f4_3 {
    char pad[0x50];
    struct Struct_ov025_021e87f4_2 unknown_50_;
};

struct Struct_ov025_021e87f4_4 {
    struct Struct_ov025_021e87f4_2 unknown_0_;
    int id;
    char pad[0x1c];
};

// USA: func_ov025_021e87f4
extern "C" ARM int func_ov025_021e87f4(struct Struct_ov025_021e87f4* a, int b, int unused, void* c) {
    GameState* bs = GameState::GetInstance();
    struct Struct_ov025_021e87f4_4 local;
    if (!func_ov000_021820bc(c, b, a->idx, (int)&local.id)) {
        return 1;
    }
    GameObject* combatant = bs->GetWanderingMonsterByIndex(local.id);
    if (combatant) {
        GameObject_SnapFacing((struct Obj02033874*)combatant, a->val);
    } else {
        combatant = bs->GetGameObjectByIndex(local.id);
        if (!combatant) {
            return 1;
        }
        struct Struct_ov025_021e87f4_3* var3 = (struct Struct_ov025_021e87f4_3*)combatant;
        local.unknown_0_ = var3->unknown_50_;
        local.unknown_0_.v[1] = a->val;
        *(Vector3i*)((int*)&var3->unknown_50_) = *(Vector3i const*)((int*)&local.unknown_0_);
    }
    return 1;
}
