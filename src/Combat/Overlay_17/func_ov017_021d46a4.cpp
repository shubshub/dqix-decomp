#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ListHead02046b38;
struct ListNode02046b38;
struct Struct_02072adc;
struct Obj02033874;
struct Struct_02076cc4;
struct Bytes02033b88;
struct Struct_020795e8;
struct Struct_020795e8_2;
struct Struct_02073ec4_2 { char unknown_0_[4]; };
struct MonsterDefinition {
    unsigned short id_;
    unsigned short category_ : 2;
    unsigned short unknown_2_2_ : 14;
#if defined(jpn)
    char pad4[0x5c - 4];
#else
    char pad4[0x60 - 4];
#endif
    Struct_02073ec4_2 entries_;
    char unknown_64_[0x304 - 0x64];
    char unknown_304_[4];
};
struct Struct_0209be84_2 { unsigned short id_; short scale_; };
struct Struct_ov017_021d46a4_4 {
    unsigned char flags_; unsigned char pad1; unsigned short id_;
    unsigned short unknown_4_; unsigned short zone_;
    unsigned short slot_ : 4; unsigned short unknown_8_4_ : 3; unsigned short unknown_8_7_ : 9;
    unsigned short unknown_a_; unsigned char unknown_c_; unsigned char unknown_d_;
    unsigned short unknown_e_; unsigned short unknown_10_; char pad12[2];
    short angle_; short x_; short y_; short unknown_1a_; unsigned char mode_;
};
struct Struct_ov017_021d46a4 {
    Object3D object_;
    char padAC[0xb8 - 0xac]; unsigned short unknown_b8_;
    char padBA[0x164 - 0xba];
    unsigned short unknown_164_; unsigned short unknown_166_; unsigned short unknown_168_; unsigned short unknown_16a_;
    char unknown_16c_[0x17d - 0x16c]; unsigned char unknown_17d_;
};
struct Struct_ov017_021d46a4_2 { char pad0[0x660]; char unknown_660_[4]; };
struct Struct_ov017_021d46a4_3 {
#if defined(jpn)
    char pad0[0x2980]; Struct_ov017_021d46a4_2 unknown_2b90_;
#else
    char pad0[0x2b90]; Struct_ov017_021d46a4_2 unknown_2b90_;
#endif
    char unknown_31f4_[0x36fc - 0x31f4]; ListHead02046b38* list_;
    char unknown_3700_[0x3718 - 0x3700]; ListNode02046b38* unknown_3718_;
};
struct ZoneState { unsigned short zone_; };
extern "C" ZoneState* Zone3D_GetInstance();
extern "C" void* ZoneRecords_GetInstance();
extern "C" MonsterDefinition* ZoneRecords_FindCurrent();
extern "C" void FieldMonsterState_Init(GameObject*);
extern "C" int func_02046b38(ListHead02046b38*, ListNode02046b38*);
extern "C" Struct_02072adc* func_ov017_021a2738(void*, int);
extern "C" void func_02072adc(Struct_02072adc*, Struct_02072adc*);
extern "C" int Zone3D_GetGroundHeight(ZoneState*, Vector3i*);
extern "C" Struct_0209be84_2* func_0209be84(Struct_02073ec4_2*, unsigned int, int);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_02076cc4(Struct_02076cc4*, int);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_02076ccc(void*, int);
extern "C" void func_0207964c(GameObject*);
extern "C" Struct_020795e8_2* func_0206ef18(void*, int);
extern "C" void func_020795e8(Struct_020795e8*, Struct_020795e8_2*);

// USA: func_ov017_021d46a4
extern "C" ARM void func_ov017_021d46a4(void*, Struct_ov017_021d46a4_4* update) {
    if (!(update->flags_ & 1)) return;
    if (!(update->flags_ & 2)) return;
    update->flags_ = 0;
    update->id_ = 0;
    GameState* state = GameState::GetInstance();
    Struct_ov017_021d46a4_3* world = (Struct_ov017_021d46a4_3*)GetGameResources();
    ZoneState* zone = Zone3D_GetInstance();
    ZoneRecords_GetInstance();
    ListHead02046b38* list = world->list_;
    MonsterDefinition* definition;
    int index;
    GameObject* actor;
    ListNode02046b38* node = world->unknown_3718_;
    if (update->zone_ != zone->zone_) return;
    definition = ZoneRecords_FindCurrent();
    if (!definition) return;
    index = definition->category_ * 12 + 0x70 + update->slot_;
    actor = state->GetFieldMonsterByIndex(index);
    if (!actor) return;
    FieldMonsterState_Init(actor);
    if (!func_02046b38(list, node)) {
        Struct_02072adc* previous = func_ov017_021a2738(world, update->unknown_a_);
        if (previous) func_02072adc(previous, (Struct_02072adc*)actor);
    }
    Vector3i position;
    position.x = update->x_ << 7;
    position.y = update->y_ << 7;
    position.z = update->unknown_1a_ << 7;
    if (update->zone_ == zone->zone_) position.y = Zone3D_GetGroundHeight(zone, &position);
    int scale = 0x1000;
    Struct_0209be84_2* entry = func_0209be84(&definition->entries_, update->unknown_a_, update->unknown_8_7_);
    if (entry) scale = entry->scale_;
    scale = (scale * 266LL + 0x800) >> 12;
    actor->obj3D_.actorIndex_ = index;
    actor->obj3D_.unknown_2_ = update->unknown_a_;
    actor->obj3D_.SetField06(update->zone_);
    actor->obj3D_.position_ = position;
    GameObject_SnapFacing((Obj02033874*)actor, update->angle_);
    actor->obj3D_.SetScale(scale, scale, scale);
    Struct_ov017_021d46a4_2* const resources = &world->unknown_2b90_;
    func_02076cc4((Struct_02076cc4*)actor, (int)resources->unknown_660_);
    Struct_ov017_021d46a4* fields = (Struct_ov017_021d46a4*)actor;
    fields->unknown_16a_ = update->unknown_4_;
    fields->unknown_168_ = update->unknown_8_7_;
    GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
    fields->unknown_17d_ |= update->unknown_c_;
    fields->unknown_b8_ = update->unknown_e_;
    fields->unknown_164_ = update->unknown_10_;
    fields->unknown_166_ = update->unknown_d_;
    func_02076ccc(actor, update->mode_);
    func_0207964c(actor);
    Struct_020795e8_2* saved = func_0206ef18(definition->unknown_304_, (short)update->unknown_a_);
    if (saved) func_020795e8((Struct_020795e8*)actor, saved);
}
