#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(int seed, EventVec3* v);
struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_FindCurrent(void);
struct Vector3i;

struct U16Field0x6_020375f8;

struct PtrWithU16_021a3338 { unsigned short field0; };
struct EntryField2_021a3338 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_021a3338
ARM void SyncVec3ForFlaggedCombatants_021a3338(void*) {
    GameState* battleStruct = GameState::GetInstance();
    struct PtrWithU16_021a3338* ptr = (struct PtrWithU16_021a3338*)Zone3D_GetInstance();
    unsigned short value = ptr->field0;
    struct Entry_02028bd0* entry = ZoneRecords_FindCurrent();
    if (entry == NULL) return;

    int i;
    for (i = 0; i < 0xc; i++) {
        int idx = ((struct EntryField2_021a3338*)entry)->field2;
        int base = idx * 0xc + 0x70;
        GameObject* combatant = battleStruct->GetFieldMonsterByIndex(i + base);
        if (combatant) {
            if (value == ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06()) {
                EventVec3 v = *(EventVec3*)((char*)combatant + 0x44);
                v.b = Zone3D_GetGroundHeight((int)ptr, &v);
                *(Vector3i*)(&combatant->obj3D_.position_.x) = *(Vector3i const*)((int*)&v);
            }
        }
    }
}
