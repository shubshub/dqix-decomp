#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"


struct Entry_02028bd0;
struct Struct_0206f01c_2;
struct Struct_02073ec4_3;
struct Struct_ov017_021a23e4 { char field_0[0xc]; short radius; short height; };
struct AreaEntry021a23e4 {
    short id;
    unsigned short category : 2;
    unsigned short flags : 14;
    short unknown_4_;
    unsigned short unknown_6_;
    char field_8[0x10];
#if defined(jpn)
    char list[0x44];
#else
    char list[0x48];
#endif
    char unknown_60_[0x298];
    char monsters[0xc];
    char nodes[0xc];
};
struct Struct_ov017_021a23e4_3 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};
struct FieldMonster021a23e4 {
    Object3D object;
    char field_ac[0x130 - 0xac];
    int state;
    char unknown_134_[4];
    Struct_ov017_021a23e4_3 params;
    char field_14c[0x16a - 0x14c];
    unsigned short key;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int func_ov017_021a26e8(GameResources* unused0, int combatantId);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" AreaEntry021a23e4* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" Struct_02073ec4_3* func_02073ec4(int mask, void* list);
extern "C" int func_02073fdc(void* p);
extern "C" Struct_ov017_021a23e4* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" int func_ov017_021a20c0(int unused, int mult, int limit);
extern "C" int func_020795cc(unsigned char* obj);
extern "C" int RandomIntBelow(int upperBound);
extern "C" void FieldMonsterState_Init(void* obj);
extern "C" int func_ov017_021a2128(void* arena, int areaId, int monsterId, int variant, const Vector3fix* position, int y, int entryId, int flags);

// USA: func_ov017_021a23e4
extern "C" ARM int func_ov017_021a23e4(GameResources* arena, int combatantId, int mask, int monsterId) {
    GameState* state = GameState::GetInstance();
    if (LinkSession_IsGuest(LinkSession_GetInstance())) return 0;
    GameObject* combatant = func_0200ff1c(state, combatantId);
    if (!combatant) return 0;
    if (mask == 0) mask = func_ov017_021a26e8(arena, combatantId);
    int areaId = combatant->obj3D_.GetField06();
    void* dataBase = Scenario_GetInstance();
    if (Scenario_TestFlag((int)dataBase, (unsigned char*)dataBase + 0x8c, 0x79a) != 0 &&
        monsterId != 0x26 && monsterId != 0x27 && monsterId != 0x28 &&
        areaId >= 0x190 && areaId <= 0x199) {
        return 0;
    }
    AreaEntry021a23e4* area = ZoneRecords_Find(ZoneRecords_GetInstance(), areaId);
    if (!area) return 0;
    Struct_02073ec4_3* entry = func_02073ec4(mask, area->unknown_60_);
    if (!entry) return 0;
    if (monsterId < 0) {
        monsterId = func_02073fdc(entry);
        if (monsterId < 0) return 0;
    }
    Struct_ov017_021a23e4* info = func_0206f4f0((Struct_0206f01c_2*)area->monsters, (short)monsterId);
    if (!info) return 0;
    int radius = info->radius << 2;
    int distance = combatant->obj3D_.GetRadius() / 4 + radius / 2;
    Vector3fix position = combatant->obj3D_.GetPointInFront(distance);
    Vector3fix rotation = combatant->obj3D_.rotation_;
    int angle = fix32ReduceAngle0To2Pi(rotation.y + 0x3244);
    if (func_ov017_021a20c0((int)arena, area->category, 12) < 0) {
        int count = 0;
        int slots[12];
        for (int i = 0; i < 12; i++) {
            int slot = i + (area->category * 12 + 0x70);
            FieldMonster021a23e4* monster = (FieldMonster021a23e4*)state->GetFieldMonsterByIndex(slot);
            if (monster == 0 || monster->state == 9) continue;
            if (func_020795cc((unsigned char*)monster) < 0) slots[count++] = slot;
        }
        GameObject* victim = state->GetFieldMonsterByIndex(slots[RandomIntBelow(count)]);
        if (victim) {
            FieldMonsterState_Init(victim);
            victim->obj3D_.MakeHidden();
        }
    }
    int slot = func_ov017_021a2128(arena, areaId, monsterId, *(unsigned short*)entry, &position, angle, 0, (unsigned char)((combatantId << 4) | 8));
    if (!slot) return 0;
    GameObject* spawned = state->GetFieldMonsterByIndex(slot);
    if (!spawned) return 0;
    FieldMonster021a23e4* monster = (FieldMonster021a23e4*)spawned;
    Struct_ov017_021a23e4_3 params;
    Struct_ov017_021a23e4_3* local = &params;
    Struct_ov017_021a23e4_3* current = &monster->params;
    local->f0 = current->f0;
    local->f1 = current->f1;
    local->f2 = current->f2;
    local->f3 = current->f3;
    local->f4 = current->f4;
    local->unknown_8_ = current->unknown_8_;
    local->unknown_c_ = current->unknown_c_;
    local->unknown_10_ = current->unknown_10_;
    params.f0 = 0;
    params.f2 = 0;
    current->f0 = local->f0;
    current->f1 = local->f1;
    current->f2 = local->f2;
    current->f3 = local->f3;
    current->f4 = local->f4;
    current->unknown_8_ = local->unknown_8_;
    current->unknown_c_ = local->unknown_c_;
    current->unknown_10_ = local->unknown_10_;
    return monster->key;
}
