#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02046b38;
struct Struct_02046b38_2;
struct Struct_02072adc;
struct Struct_02033834;
struct Struct_02076cc4;
struct Struct_02010604;
struct Struct_020795e8;
struct Struct_020795e8_2;
struct Struct_02073ec4_2 { char unknown_0_[4]; };
struct Struct_0206ef40 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 14;
#if defined(jpn)
    char unknown_4_[0x5c - 4];
#else
    char unknown1_4_[0x60 - 4];
#endif
    Struct_02073ec4_2 unknown_60_;
    char unknown_64_[0x304 - 0x64];
    char unknown_304_[4];
};
struct Struct_0209be84_2 { unsigned short unknown_0_; short unknown_2_; };
struct Struct_ov017_021d46a4_4 {
    unsigned char unknown_0_; unsigned char unknown_1_; unsigned short unknown_2_;
    unsigned short unknown_4_; unsigned short unknown_6_;
    unsigned short unknown_8_0_ : 4; unsigned short unknown_8_4_ : 3; unsigned short unknown_8_7_ : 9;
    unsigned short unknown_a_; unsigned char unknown_c_; unsigned char unknown_d_;
    unsigned short unknown_e_; unsigned short unknown_10_; char unknown_12_[2];
    short unknown_14_; short unknown_16_; short unknown_18_; short unknown_1a_; unsigned char unknown_1c_;
};
struct Struct_ov017_021d46a4 {
    Object3D unknown_0_;
    char unknown_ac_[0xb8 - 0xac]; unsigned short unknown_b8_;
    char unknown_ba_[0x164 - 0xba];
    unsigned short unknown_164_; unsigned short unknown_166_; unsigned short unknown_168_; unsigned short unknown_16a_;
    char unknown_16c_[0x17d - 0x16c]; unsigned char unknown_17d_;
};
struct Struct_ov017_021d46a4_2 { char unknown_0_[0x660]; char unknown_660_[4]; };
struct Struct_ov017_021d46a4_3 {
#if defined(jpn)
    char unknown_0_[0x2980]; Struct_ov017_021d46a4_2 unknown_2b90_;
#else
    char unknown1_0_[0x2b90]; Struct_ov017_021d46a4_2 unknown_2b90_;
#endif
    char unknown_31f4_[0x36fc - 0x31f4]; Struct_02046b38* unknown_36fc_;
    char unknown_3700_[0x3718 - 0x3700]; Struct_02046b38_2* unknown_3718_;
};
struct ZoneState { unsigned short zone_; };
extern "C" ZoneState* Zone3D_GetInstance();
void* ZoneRecords_GetInstance();
MonsterDefinition* FindEntryByCurrentId02027cb0();
extern "C" void func_02076a8c(GameObject*);
int ListContainsNode(ListHead02046b38*, ListNode02046b38*);
PairStruct* FindCombatantByField2_021a2738(void*, int);
void CopyPairAndStoreField_02072adc(PairStruct*, PairStruct*);
extern "C" int Zone3D_GetGroundHeight(ZoneState*, Vector3i*);
SubEntry0209be84* FindSubEntry0209be84(EntryTable0209bd94*, unsigned int, int);
void SetVecYFromValue02033874(Obj02033874*, int);
void SetField0x16c(S02076cc4*, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void TrySetMode02076ccc(void*, int);
extern "C" void func_0207964c(GameObject*);
extern "C" Struct_020795e8_2* func_0206ef18(void*, int);
extern "C" void func_020795e8(Struct_020795e8*, Struct_020795e8_2*);

// USA: func_ov017_021d46a4
extern "C" ARM void func_ov017_021d46a4(void*, MonsterUpdate* update) {
    if (!(update->flags_ & 1)) return;
    if (!(update->flags_ & 2)) return;
    update->flags_ = 0;
    update->id_ = 0;
    GameState* state = GameState::GetInstance();
    WorldState* world = (WorldState*)GetGameResources();
    ZoneState* zone = Zone3D_GetInstance();
    ZoneRecords_GetInstance();
    ListHead02046b38* list = world->list_;
    MonsterDefinition* definition;
    int index;
    GameObject* actor;
    ListNode02046b38* node = world->node_;
    if (update->zone_ != zone->zone_) return;
    definition = FindEntryByCurrentId02027cb0();
    if (!definition) return;
    index = definition->category_ * 12 + 0x70 + update->slot_;
    actor = state->GetMaybeFieldMonsterByIndex(index);
    if (!actor) return;
    func_02076a8c(actor);
    if (!ListContainsNode(list, node)) {
        PairStruct* previous = FindCombatantByField2_021a2738(world, update->monsterId_);
        if (previous) CopyPairAndStoreField_02072adc(previous, (PairStruct*)actor);
    }
    Vector3i position;
    position.x = update->x_ << 7;
    position.y = update->y_ << 7;
    position.z = update->z_ << 7;
    if (update->zone_ == zone->zone_) position.y = Zone3D_GetGroundHeight(zone, &position);
    int scale = 0x1000;
    SubEntry0209be84* entry = FindSubEntry0209be84(&definition->entries_, update->monsterId_, update->variant_);
    if (entry) scale = entry->scale_;
    scale = (scale * 266LL + 0x800) >> 12;
    actor->obj3D_.actorIndex_ = index;
    actor->obj3D_.unknown_2_ = update->monsterId_;
    actor->obj3D_.SetField06(update->zone_);
    actor->obj3D_.position_ = position;
    SetVecYFromValue02033874((Obj02033874*)actor, update->angle_);
    actor->obj3D_.SetScale(scale, scale, scale);
    WorldResources* const resources = &world->resources_;
    SetField0x16c((S02076cc4*)actor, (int)resources->field660_);
    MonsterFields* fields = (MonsterFields*)actor;
    fields->field16A_ = update->field4_;
    fields->variant_ = update->variant_;
    SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
    fields->flags17D_ |= update->flagsC_;
    fields->fieldB8_ = update->fieldE_;
    fields->field164_ = update->field10_;
    fields->field166_ = update->fieldD_;
    TrySetMode02076ccc(actor, update->mode_);
    func_0207964c(actor);
    Src020795e8* saved = FindNodeBySignedId_0206ef18(definition->nodes_, (short)update->monsterId_);
    if (saved) CopyBitFields020795e8((Dst020795e8*)actor, saved);
}
