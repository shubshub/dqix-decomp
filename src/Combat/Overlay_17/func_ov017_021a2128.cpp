#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020fdd44;
struct Struct_02073ec4_2;
struct Struct_0206f01c_2;
struct Struct_020283fc;
struct Struct_02072adc;
struct Struct_02033834;
struct Struct_020795e8;
struct Struct_020795e8_2;
struct Struct_02076cc4;
struct Struct_ov017_021a2128_3 { char unknown_0_[0xc]; short unknown_c_; short unknown_e_; };
struct Struct_ov017_021a2128_4 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 14;
    short unknown_4_;
    unsigned short unknown_6_;
#if defined(jpn)
    char unknown_8_[0xc];
#else
    char unknown1_8_[0x10];
#endif
    char unknown_18_[0x48];
    char unknown_60_[0x298];
    char unknown_2f8_[0xc];
    char unknown_304_[0xc];
};
struct Struct_ov017_021a2128_5 {
    Object3D unknown_0_;
    char unknown_ac_[0xc];
    short unknown_b8_;
    char unknown_ba_[0xaa];
    short unknown_164_;
    short unknown_166_;
    short unknown_168_;
    short unknown_16a_;
    char unknown_16c_[0x11];
    unsigned char unknown_17d_;
    char unknown_17e_[2];
    Struct_ov017_021a2128_3* unknown_180_;
    void* unknown_184_;
};
#if defined(jpn)
struct Struct_ov017_021a2128 { char unknown_0_[0x2fe0]; int unknown_31f0_; };
#else
struct Struct_ov017_021a2128 { char unknown_0_[0x31f0]; int unknown_31f0_; };
#endif
Entry_02028bd0* ZoneRecords_GetInstance();
AreaEntry021a2128* FindInlineEntryById(Entry_02028bd0*, int);
MonsterInfo021a2128* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void* FindNodeBySignedId_0206ef18(void*, int);
int FindCombatantWithNegativeField2_021a20c0(int, int, int);
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" int* func_0202ae18();
extern "C" void func_02076a8c(void*);
PairStruct* FindCombatantByField2_021a2738(void*, int);
void CopyPairAndStoreField_02072adc(PairStruct*, PairStruct*);
struct Subentry021a2128 { short field_0; short scale; };
Subentry021a2128* FindSubEntry0209be84(EntryTable0209bd94*, unsigned int, int);
extern "C" int Zone3D_GetGroundHeight(void*, Vector3fix*);
int FindListIndexById(List_020283fc*, int);
void SetVecYFromValue02033874(Obj02033874*, int);
void CopyBitFields020795e8(Dst020795e8*, Src020795e8*);
void TrySetMode02076ccc(void*, int);
void SetField0x16c(S02076cc4*, int);
extern "C" int func_ov017_021a1944();
extern "C" int func_0202b7d8(int*);
extern "C" void func_ov017_021c8f3c(int, int);

// USA: func_ov017_021a2128
extern "C" ARM int func_ov017_021a2128(FieldArena021a2128* arena, unsigned short areaId, int monsterId, int variant, const Vector3fix* position, int y, unsigned short entryId, unsigned char flags) {
    AreaEntry021a2128* area = FindInlineEntryById(ZoneRecords_GetInstance(), areaId);
    if (!area) return 0;
    MonsterInfo021a2128* info = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)area->monsters, (short)monsterId);
    void* node = FindNodeBySignedId_0206ef18(area->nodes, (short)monsterId);
    if (!info) return 0;
    if (!node) return 0;
    GameState* state = GameState::GetInstance();
    unsigned short* currentArea = Zone3D_GetInstance();
    int* manager = func_0202ae18();
    int slot = FindCombatantWithNegativeField2_021a20c0((int)arena, area->category, 12);
    if (slot < 0) return 0;
    FieldMonster021a2128* monster = (FieldMonster021a2128*)state->GetMaybeFieldMonsterByIndex(slot);
    if (!monster) return 0;
    func_02076a8c(monster);
    PairStruct* previous = FindCombatantByField2_021a2738(arena, monsterId);
    if (areaId == *currentArea && previous) CopyPairAndStoreField_02072adc(previous, (PairStruct*)monster);
    int scale = 0x1000;
    Subentry021a2128* entry = FindSubEntry0209be84((EntryTable0209bd94*)area->subentries, monsterId, variant);
    if (entry) scale = entry->scale;
    Vector3fix location __attribute__((aligned(4))) = *position;
    if (areaId == *currentArea) location.y = Zone3D_GetGroundHeight(currentArea, &location);
    monster->object.unknown_2_ = monsterId;
    monster->object.actorIndex_ = slot;
    monster->object.SetField06(areaId);
    monster->variant = variant;
    monster->info = info;
    monster->node = node;
    monster->listIndex = FindListIndexById((List_020283fc*)area->list, entryId);
    monster->entryId = entryId;
    monster->object.position_ = location;
    SetVecYFromValue02033874((Obj02033874*)monster, y);
    monster->object.SetRadius(info->radius << 2);
    monster->object.SetHeight(info->height);
    Src020795e8* fields = (Src020795e8*)FindNodeBySignedId_0206ef18(area->nodes, (short)monsterId);
    if (fields) CopyBitFields020795e8((Dst020795e8*)monster, fields);
    int scaled = (int)(((long long)scale * 0x10a + 0x800) >> 12);
    monster->object.SetScale(scaled, scaled, scaled);
    TrySetMode02076ccc(monster, 0);
    SetField0x16c((S02076cc4*)monster, (int)&arena->context);
    monster->state = func_ov017_021a1944();
    monster->flags |= flags;
    monster->object.MakeVisible();
    ++area->instances;
    if (CheckField0NonZero_0202b7d8(manager)) func_ov017_021c8f3c(slot, -1);
    return slot;
}
