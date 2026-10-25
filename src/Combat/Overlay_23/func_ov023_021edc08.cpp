#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/MonsterDefinition.h"
#include "Resource/GameResources.h"

struct Struct_ov023_021edc08_5 { unsigned int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_0200f3a4_8 { int unknown_0_, unknown_4_; };
struct Struct_02109bf4_4;
struct Struct_020d6f0c;
struct Struct_020d6d18_2;
struct Struct_0203a54c;
struct Struct_020e385c;
struct Struct_ov003_02162f40 {
    char unknown_0_[8]; unsigned short unknown_8_; char unknown_a_[2]; int unknown_c_;
    char unknown_10_[0x25 - 0x10]; unsigned char unknown_25_; char unknown_26_[0x678 - 0x26];
    Struct_0206f01c_2 unknown_678_;
};
struct Struct_ov023_021edc08_6 {
#if defined(jpn)
    char unknown_0_[0x21c]; Struct_ov003_02162f40* unknown_2a0_; char unknown_220_[0xb94 - 0x220];
    int unknown_c18_[1]; char unknown_b98_[0xe20 - 0xb98]; Struct_020d6f0c* unknown_ea4_;
    char unknown_e24_[0x71ec - 0xe24]; char unknown_6ffc_[1];
#else
    char unknown1_0_[0x2a0]; Struct_ov003_02162f40* unknown_2a0_; char unknown_2a4_[0xc18 - 0x2a4];
    int unknown_c18_[1]; char unknown_c1c_[0xea4 - 0xc1c]; Struct_020d6f0c* unknown_ea4_;
    char unknown_ea8_[0x6ffc - 0xea8]; char unknown_6ffc_[1];
#endif

};
struct Struct_ov023_021edc08 {
    int unknown_0_; int unknown_4_[3]; unsigned char unknown_10_; unsigned char unknown_11_;
    unsigned char unknown_12_[4]; char unknown_16_[2]; int unknown_18_; char unknown_1c_[0x20];
    char unknown_3c_[0x6c - 0x3c]; int unknown_6c_; int unknown_70_; char unknown_74_[0xe2 - 0x74];
    unsigned char unknown_e2_; char unknown_e3_; signed char unknown_e4_; signed char unknown_e5_;
    char unknown_e6_[2]; Struct_0200f3a4_8 unknown_e8_; int unknown_f0_; int unknown_f4_[6];
#if defined(jpn)
    Struct_ov023_021edc08_5 unknown_10c_; char unknown_118_[0x2380]; unsigned char unknown_2788_; char unknown_2499_[7];
#else
    Struct_ov023_021edc08_5 unknown_10c_; char unknown_118_[0x2670]; unsigned char unknown_2788_; char unknown_2789_[7];
#endif

};
struct Struct_ov023_021edc08_2 { Struct_ov023_021edc08* unknown_0_; int unknown_4_; int unknown_8_; };
struct Struct_02081870 {
#if defined(jpn)
    char unknown_0_[0x10]; void* unknown_10_; char unknown_14_[0x868 - 0x14]; int unknown_998_;
#else
    char unknown1_0_[0x10]; void* unknown1_10_; char unknown1_14_[0x998 - 0x14]; int unknown_998_;
#endif

};
#if defined(jpn)
struct Struct_ov023_021edc08_3 { char unknown_0_[0x240c]; ActiveGrottoClass unknown_240c_; };
#else
struct Struct_ov023_021edc08_3 { char unknown_0_[0x23ec]; ActiveGrottoClass unknown_23ec_; };
#endif

struct GrottoRewardView { short field0_, field2_; short ids_[3]; };
struct SoundIds { int ids_[6]; };
extern "C" CombatGlobal _ZZ17GetGlobal021ffefcvE1s;
extern Actor0209c678 g_bgmPlayer;
extern const SoundIds data_ov023_021fd870;
#if defined(jpn)
extern const char data_ov023_021fd45c[];
extern "C" void func_0204500c(Struct_02081870*, const char*, int);
#endif
extern "C" void* func_0202ae18();
TextRenderer* MessageSystem_GetInstance();
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
void EnqueueEventTag86_021c9ad4(unsigned short);
extern "C" void func_ov017_021a23b0(GameResources*, int);
void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" void func_ov000_0216d370(void*, int, int, int);
extern "C" void* func_02057924();
extern "C" void func_02057f00(void*, int);
extern "C" void func_020d6f0c(Struct_020d6f0c*);
extern "C" void func_020d6d18(Struct_020d6d18_2*);
extern "C" void func_ov000_021823a4(char*);
extern "C" Struct_0203a54c* func_02039e70();
extern "C" void func_0203a54c(Struct_0203a54c*);
extern "C" void func_0209a338(Struct_0200f3a4_8*);
extern "C" void func_0209a804(int*);
extern "C" void func_ov023_021f52a0(void*);
extern "C" void func_0206efc4(void*);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov023_021f52f8(void*, void*);
extern "C" int func_0202c540(void*);
extern "C" void func_02046380(TextRenderer*);
extern "C" ZoneData* Zone3D_GetInstance();
void Clear12Bytes020e46c4(void*);
void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
extern "C" Words021edf38 func_ov023_021ed804(Words021edf38, void*);
void SetWords_021edf38_021edf38(void*, Words021edf38*);
const char* StandardStrings_Get(int);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_02081870*, const char*, int, int);
#endif
extern "C" void func_0209c6d8(void*, int);
extern "C" int func_0202c508(void*);
extern "C" Struct_020e385c* func_020e3808();
extern "C" void func_020e3994(Struct_020e385c*, int, int);
extern "C" void func_020e392c(Struct_020e385c*, int, int);
extern "C" void func_020e39d4(Struct_020e385c*, int, int, int);

static inline SafeAllocator* inline_ov000_02166804(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// USA: func_ov023_021edc08
extern "C" ARM int func_ov023_021edc08(Struct_ov023_021edc08_6* arg0) {
#if defined(jpn)
    GameState* var0 = GameState::GetInstance();
#else
    GameState::GetInstance();
#endif

    GameResources* resources = GetGameResources();
    void* mode = func_0202ae18();
    TextRenderer* renderer = MessageSystem_GetInstance();
    FlagWord_SetBits(GlobalFlags_GetInstance(), 0x20000);
    EnqueueEventTag86_021c9ad4(self->battle_->event_);
    func_ov017_021a23b0(resources, self->battle_->event_);
    BgmPlayer_FadeOut(&g_bgmPlayer, 0);
    func_ov000_0216d370(self->camera_, 0, 0, 1);
    void* sound = func_02057924();
    SoundIds sounds = data_ov023_021fd870;
    for (int* id = sounds.ids_; *id >= 0; ++id) func_02057f00(sound, *id);
    if (self->manager_) {
        DestroyAllocatorAt0xa28(self->manager_);
        ConstructEntryManager020d6d18((Container020d6d18*)self->manager_);
        self->manager_ = 0;
    }
    func_ov000_021823a4(arg0->unknown_6ffc_);
    func_0203a54c(func_02039e70());
    SafeAllocator* const var7 = inline_ov000_02166804(var1, 5);
    var7->Reset();
    Struct_ov023_021edc08* var8 = (Struct_ov023_021edc08*)var7->Allocate(sizeof(Struct_ov023_021edc08));
    _ZZ21inline_ov023_021f4c04vE1s.unknown_0_ = var8;
    var8->unknown_0_ = 0;
    var8->unknown_4_[0] = -1;
    var8->unknown_4_[1] = -1;
    var8->unknown_4_[2] = -1;
    var8->unknown_10_ = 0;
    var8->unknown_18_ = -1;
    var8->unknown_70_ = 0;
    var8->unknown_e2_ = 0;
    var8->unknown_e4_ = -1;
    var8->unknown_11_ = 0;
    for (int var9 = 0; var9 < 4; ++var9) var8->unknown_12_[var9] = 0;
    var8->unknown_e5_ = -1;
    memset(var8->unknown_1c_, 0, sizeof(var8->unknown_1c_));
    memset(&var8->unknown_6c_, 0, 4);
    memset(var8->unknown_118_, 0, sizeof(var8->unknown_118_));
    var8->unknown_2788_ = 0;
    func_0209a338(&var8->unknown_e8_);
    func_0209a804(&var8->unknown_f0_);
    func_ov023_021f52a0(var8->unknown_f4_);
    func_0206efc4(&var8->unknown_10c_);
    func_020a1ef0(1);
    func_ov023_021f52f8(_ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_f4_, var7);
    if (func_0202c540(var2) && arg0->unknown_2a0_->unknown_25_) {
#if defined(jpn)
        GameObject* member = game->GetPartyMemberByIndex(0);
        DetailedTreasureMapData* detail = Zone3D_GetInstance()->grotto_.GetDetailedData();
        char message[128];
        sprintf(message, data_ov023_021fd45c, *(const char**)((char*)member + 0x134), (char*)detail + 0x5a);
        func_0204500c(renderer, message, 1);
#else
        func_02046380(renderer);
        GrottoRewardView* rewards = (GrottoRewardView*)&Zone3D_GetInstance()->grotto_.GetDetailedData()->regular_;
        Words021edf38 words;
        Clear12Bytes020e46c4(&words);
        BattleInfo* battle = self->battle_;
        for (int i = 0; i < 3; ++i) {
            void* found = SearchWithComparator0206f4f0(&battle->rewards_, rewards->ids_[i]);
            if (found) {
                const Words021edf38& copy = func_ov023_021ed804(words, found);
                SetWords_021edf38_021edf38(&words, const_cast<Words021edf38*>(&copy));
                renderer->argument_ = &words;
                break;
            }
        }
        char message[256];
        sprintf(message, StandardStrings_Get(200));
        func_0204500c(renderer, message, 1, 0xe3);

#endif
        renderer->active_ = 1;
        ResetAndDispatchActorContext0209c6d8(&g_bgmPlayer, 0x36);
    }
    if (func_0202c508(var2) && arg0->unknown_2a0_->unknown_c_ == 19) {
        Struct_020e385c* var20 = func_020e3808();
        func_020e3994(var20, 1, -1);
        func_020e392c(var20, 1, 0x71e8);
        func_020e39d4(var20, 0, 1, 0x71e8);
    }
    return 1;
}
