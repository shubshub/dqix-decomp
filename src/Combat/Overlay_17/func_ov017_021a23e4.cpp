#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"


struct Struct_020fdd44;
struct Struct_0206f01c_2;
struct Struct_02073ec4_3;
struct Struct_ov017_021a23e4 { char unknown_0_[0xc]; short unknown_c_; short unknown_e_; };
struct Struct_ov017_021a23e4_2 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 14;
    short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[0x10];
#if defined(jpn)
    char unknown_18_[0x44];
#else
    char unknown1_18_[0x48];
#endif
    char unknown_60_[0x298];
    char unknown_2f8_[0xc];
    char unknown_304_[0xc];
};
struct Struct_ov017_021a23e4_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};
struct Struct_ov017_021a23e4_4 {
    Object3D unknown_0_;
    char unknown_ac_[0x130 - 0xac];
    int unknown_130_;
    char unknown_134_[4];
    Struct_ov017_021a23e4_3 unknown_138_;
    char unknown_14c_[0x16a - 0x14c];
    unsigned short unknown_16a_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
int GetBitflagForCombatantColor_021a26e8(GameResources* unused0, int combatantId);
extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
Entry_02028bd0* ZoneRecords_GetInstance();
AreaEntry021a23e4* ZoneRecords_Find(Entry_02028bd0*, int);
Entry0209bd94* FindMatchingEntryByMask02073ec4(int mask, void* list);
int SelectWeightedEntry02073fdc(void* p);
MonsterInfo021a23e4* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
int FindCombatantWithNegativeField2_021a20c0(int unused, int mult, int limit);
int GetField0x17dBits4To5IfFlag8_020795cc(unsigned char* obj);
extern "C" int RandomIntBelow(int upperBound);
extern "C" void FieldMonsterState_Init(void* obj);
extern "C" int func_ov017_021a2128(void* arena, int areaId, int monsterId, int variant, const Vector3fix* position, int y, int entryId, int flags);

// USA: func_ov017_021a23e4
extern "C" ARM int func_ov017_021a23e4(GameResources* arena, int combatantId, int mask, int monsterId) {
    GameState* state = GameState::GetInstance();
    if (LinkSession_IsGuest(LinkSession_GetInstance())) return 0;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, combatantId);
    if (!combatant) return 0;
    if (mask == 0) mask = GetBitflagForCombatantColor_021a26e8(arena, combatantId);
    int areaId = combatant->obj3D_.GetField06();
    void* dataBase = Scenario_GetInstance();
    if (Scenario_TestFlag((int)dataBase, (unsigned char*)dataBase + 0x8c, 0x79a) != 0 &&
        monsterId != 0x26 && monsterId != 0x27 && monsterId != 0x28 &&
        areaId >= 0x190 && areaId <= 0x199) {
        return 0;
    }
    AreaEntry021a23e4* area = ZoneRecords_Find(ZoneRecords_GetInstance(), areaId);
    if (!area) return 0;
    Entry0209bd94* entry = FindMatchingEntryByMask02073ec4(mask, area->subentries);
    if (!entry) return 0;
    if (monsterId < 0) {
        monsterId = SelectWeightedEntry02073fdc(entry);
        if (monsterId < 0) return 0;
    }
    MonsterInfo021a23e4* info = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)area->monsters, (short)monsterId);
    if (!info) return 0;
    int radius = info->radius << 2;
    int distance = combatant->obj3D_.GetRadius() / 4 + radius / 2;
    Vector3fix position = combatant->obj3D_.GetPointInFront(distance);
    Vector3fix rotation = combatant->obj3D_.rotation_;
    int angle = fix32ReduceAngle0To2Pi(rotation.y + 0x3244);
    if (FindCombatantWithNegativeField2_021a20c0((int)arena, area->category, 12) < 0) {
        int count = 0;
        int slots[12];
        for (int i = 0; i < 12; i++) {
            int slot = i + (area->category * 12 + 0x70);
            FieldMonster021a23e4* monster = (FieldMonster021a23e4*)state->GetFieldMonsterByIndex(slot);
            if (monster == 0 || monster->state == 9) continue;
            if (GetField0x17dBits4To5IfFlag8_020795cc((unsigned char*)monster) < 0) slots[count++] = slot;
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
    MonsterParams021a23e4 params;
    MonsterParams021a23e4* local = &params;
    MonsterParams021a23e4* current = &monster->params;
    local->f0 = current->f0;
    local->f1 = current->f1;
    local->f2 = current->f2;
    local->f3 = current->f3;
    local->f4 = current->f4;
    local->w140 = current->w140;
    local->w144 = current->w144;
    local->w148 = current->w148;
    params.f0 = 0;
    params.f2 = 0;
    current->f0 = local->f0;
    current->f1 = local->f1;
    current->f2 = local->f2;
    current->f3 = local->f3;
    current->f4 = local->f4;
    current->w140 = local->w140;
    current->w144 = local->w144;
    current->w148 = local->w148;
    return monster->key;
}
