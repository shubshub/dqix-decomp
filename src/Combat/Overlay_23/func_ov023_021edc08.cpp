#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/MonsterDefinition.h"
#include "Resource/GameResources.h"

struct Struct_ov023_021edc08_5 { unsigned int unknown_0_, unknown_4_, unknown_8_; };
struct Pair0209a338 { int unknown_0_, unknown_4_; };
struct Actor0209c678;
struct Struct_020d6f0c;
struct Struct_020d6d18_2;
struct Container0203a54c;
struct TagValueEntry020e385c;
struct BattleInfo {
    char pad0[8]; unsigned short unknown_8_; char padA[2]; int type_;
    char pad10[0x25 - 0x10]; unsigned char special_; char unknown_26_[0x678 - 0x26];
    Struct_0206f01c_2 unknown_678_;
};
struct Struct_ov023_021edc08_6 {
#if defined(jpn)
    char pad0[0x21c]; BattleInfo* battle_; char unknown_220_[0xb94 - 0x220];
    int camera_[1]; char unknown_b98_[0xe20 - 0xb98]; Struct_020d6f0c* unknown_ea4_;
    char unknown_e24_[0x71ec - 0xe24]; char entries_[1];
#else
    char pad0[0x2a0]; BattleInfo* battle_; char unknown_2a4_[0xc18 - 0x2a4];
    int camera_[1]; char unknown_c1c_[0xea4 - 0xc1c]; Struct_020d6f0c* unknown_ea4_;
    char unknown_ea8_[0x6ffc - 0xea8]; char entries_[1];
#endif

};
struct Struct_ov023_021edc08 {
    int state_; int tasks_[3]; unsigned char unknown_10_; unsigned char unknown_11_;
    unsigned char flags_[4]; char pad16[2]; int unknown_18_; char buffer_[0x20];
    char unknown_3c_[0x6c - 0x3c]; int unknown_6c_; int unknown_70_; char unknown_74_[0xe2 - 0x74];
    unsigned char unknown_e2_; char unknown_e3_; signed char unknown_e4_; signed char unknown_e5_;
    char unknown_e6_[2]; Pair0209a338 unknown_e8_; int unknown_f0_; int unknown_f4_[6];
#if defined(jpn)
    Struct_ov023_021edc08_5 words_; char unknown_118_[0x2380]; unsigned char unknown_2788_; char unknown_2499_[7];
#else
    Struct_ov023_021edc08_5 words_; char unknown_118_[0x2670]; unsigned char unknown_2788_; char unknown_2789_[7];
#endif

};
struct Struct_ov023_021edc08_2 { Struct_ov023_021edc08* work_; int unknown_4_; int flags_; };
struct TextRenderer {
#if defined(jpn)
    char pad0[0x10]; void* unknown_10_; char unknown_14_[0x868 - 0x14]; int active_;
#else
    char pad0[0x10]; void* unknown1_10_; char unknown1_14_[0x998 - 0x14]; int active_;
#endif

};
#if defined(jpn)
struct ZoneData { char pad0[0x240c]; ActiveGrottoClass grotto_; };
#else
struct ZoneData { char pad0[0x23ec]; ActiveGrottoClass grotto_; };
#endif

struct GrottoRewardView { short unknown_0_, unknown_2_; short unknown_4_[3]; };
struct Struct_ov023_021fd870 { int unknown_0_[6]; };
extern "C" Struct_ov023_021edc08_2 _ZZ21inline_ov023_021f4c04vE1s;
extern Actor0209c678 g_bgmPlayer;
extern const Struct_ov023_021fd870 data_ov023_021fd870;
#if defined(jpn)
extern const char data_ov023_021fd45c[];
extern "C" void func_0204500c(TextRenderer*, const char*, int);
#endif
extern "C" void* LinkSession_GetInstance();
extern "C" TextRenderer* MessageSystem_GetInstance();
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void func_ov017_021c9ad4(unsigned short);
extern "C" void func_ov017_021a23b0(GameResources*, int);
extern "C" void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" void func_ov000_0216d370(void*, int, int, int);
extern "C" void* func_02057924();
extern "C" void func_02057f00(void*, int);
extern "C" void func_020d6f0c(Struct_020d6f0c*);
extern "C" void func_020d6d18(Struct_020d6d18_2*);
extern "C" void func_ov000_021823a4(char*);
extern "C" Container0203a54c* NumberPopups_GetInstance();
extern "C" void NumberPopups_UnloadSprites(Container0203a54c*);
extern "C" void func_0209a338(Pair0209a338*);
extern "C" void func_0209a804(int*);
extern "C" void func_ov023_021f52a0(void*);
extern "C" void func_0206efc4(void*);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov023_021f52f8(void*, void*);
extern "C" int LinkSession_IsGuest(void*);
extern "C" void func_02046380(TextRenderer*);
extern "C" ZoneData* Zone3D_GetInstance();
extern "C" void NameText_Clear(void*);
extern "C" void* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" Struct_ov023_021edc08_5 func_ov023_021ed804(Struct_ov023_021edc08_5, void*);
extern "C" void func_ov023_021edf38(void*, Struct_ov023_021edc08_5*);
extern "C" const char* StandardStrings_Get(int);
#if !defined(jpn)
extern "C" void func_0204500c(TextRenderer*, const char*, int, int);
#endif
extern "C" void func_0209c6d8(void*, int);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" TagValueEntry020e385c* func_020e3808();
extern "C" void func_020e3994(TagValueEntry020e385c*, int, int);
extern "C" void func_020e392c(TagValueEntry020e385c*, int, int);
extern "C" void func_020e39d4(TagValueEntry020e385c*, int, int, int);

static inline SafeAllocator* inline_ov000_02166804(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// USA: func_ov023_021edc08
extern "C" ARM int func_ov023_021edc08(Struct_ov023_021edc08_6* self) {
#if defined(jpn)
    GameState* game = GameState::GetInstance();
#else
    GameState::GetInstance();
#endif

    GameResources* resources = GetGameResources();
    void* mode = LinkSession_GetInstance();
    TextRenderer* renderer = MessageSystem_GetInstance();
    FlagWord_SetBits(GlobalFlags_GetInstance(), 0x20000);
    func_ov017_021c9ad4(self->battle_->unknown_8_);
    func_ov017_021a23b0(resources, self->battle_->unknown_8_);
    BgmPlayer_FadeOut(&g_bgmPlayer, 0);
    func_ov000_0216d370(self->camera_, 0, 0, 1);
    void* sound = func_02057924();
    Struct_ov023_021fd870 sounds = data_ov023_021fd870;
    for (int* id = sounds.unknown_0_; *id >= 0; ++id) func_02057f00(sound, *id);
    if (self->unknown_ea4_) {
        func_020d6f0c(self->unknown_ea4_);
        func_020d6d18((Struct_020d6d18_2*)self->unknown_ea4_);
        self->unknown_ea4_ = 0;
    }
    func_ov000_021823a4(self->entries_);
    NumberPopups_UnloadSprites(NumberPopups_GetInstance());
    SafeAllocator* const allocator = inline_ov000_02166804(resources, 5);
    allocator->Reset();
    Struct_ov023_021edc08* work = (Struct_ov023_021edc08*)allocator->Allocate(sizeof(Struct_ov023_021edc08));
    _ZZ21inline_ov023_021f4c04vE1s.work_ = work;
    work->state_ = 0;
    work->tasks_[0] = -1;
    work->tasks_[1] = -1;
    work->tasks_[2] = -1;
    work->unknown_10_ = 0;
    work->unknown_18_ = -1;
    work->unknown_70_ = 0;
    work->unknown_e2_ = 0;
    work->unknown_e4_ = -1;
    work->unknown_11_ = 0;
    for (int i = 0; i < 4; ++i) work->flags_[i] = 0;
    work->unknown_e5_ = -1;
    memset(work->buffer_, 0, sizeof(work->buffer_));
    memset(&work->unknown_6c_, 0, 4);
    memset(work->unknown_118_, 0, sizeof(work->unknown_118_));
    work->unknown_2788_ = 0;
    func_0209a338(&work->unknown_e8_);
    func_0209a804(&work->unknown_f0_);
    func_ov023_021f52a0(work->unknown_f4_);
    func_0206efc4(&work->words_);
    func_020a1ef0(1);
    func_ov023_021f52f8(_ZZ21inline_ov023_021f4c04vE1s.work_->unknown_f4_, allocator);
    if (LinkSession_IsGuest(mode) && self->battle_->special_) {
#if defined(jpn)
        GameObject* member = game->GetPartyMemberByIndex(0);
        DetailedTreasureMapData* detail = Zone3D_GetInstance()->grotto_.GetDetailedData();
        char message[128];
        sprintf(message, data_ov023_021fd45c, *(const char**)((char*)member + 0x134), (char*)detail + 0x5a);
        func_0204500c(renderer, message, 1);
#else
        func_02046380(renderer);
        GrottoRewardView* rewards = (GrottoRewardView*)&Zone3D_GetInstance()->grotto_.GetDetailedData()->regular_;
        Struct_ov023_021edc08_5 words;
        NameText_Clear(&words);
        BattleInfo* battle = self->battle_;
        for (int i = 0; i < 3; ++i) {
            void* found = func_0206f4f0(&battle->unknown_678_, rewards->unknown_4_[i]);
            if (found) {
                const Struct_ov023_021edc08_5& copy = func_ov023_021ed804(words, found);
                func_ov023_021edf38(&words, const_cast<Struct_ov023_021edc08_5*>(&copy));
                renderer->unknown1_10_ = &words;
                break;
            }
        }
        char message[256];
        sprintf(message, StandardStrings_Get(200));
        func_0204500c(renderer, message, 1, 0xe3);

#endif
        renderer->active_ = 1;
        func_0209c6d8(&g_bgmPlayer, 0x36);
    }
    if (LinkSession_IsHostOrSolo(mode) && self->battle_->type_ == 19) {
        TagValueEntry020e385c* tags = func_020e3808();
        func_020e3994(tags, 1, -1);
        func_020e392c(tags, 1, 0x71e8);
        func_020e39d4(tags, 0, 1, 0x71e8);
    }
    return 1;
}
