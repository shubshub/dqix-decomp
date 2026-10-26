#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short : 14;
};
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
GameObject* FindCombatantByField2_021a2738(void* unused, int value);

// USA: func_ov017_0219e180
extern "C" ARM void func_ov017_0219e180(void* param, int id) {
    GameState* bs = GameState::GetInstance();
    struct Entry_02028bd0* table = ZoneRecords_GetInstance();
    void* search = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)search) != 0) {
        if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search) != 0) {
            return;
        }
    }
    struct Entry_02028bd0* entry = ZoneRecords_Find(table, id);
    if (entry == NULL) {
        return;
    }
    int group = entry->field2;
    for (int i = 0; i < 0xc; i++) {
        GameObject* monster = bs->GetFieldMonsterByIndex(group * 0xc + 0x70 + i);
        if (monster == NULL) {
            continue;
        }
        GameObject* var7 = func_ov017_021a2738(arg0, var6->obj3D_.unknown_2_);
        if (var7 == NULL) {
            continue;
        }
        var7->obj3D_.ShallowCloneModelAndAnimationsTo(&var6->obj3D_);
    }
}
