#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define REGION_LAYOUT(jpnValue, usaValue) jpnValue
#else
#define REGION_LAYOUT(jpnValue, usaValue) usaValue
#endif

struct Struct_ov000_02161e30;
struct Struct_02109bf4_4;
struct Struct_02038598_4;
struct Struct_020727d8;
struct Struct_02072a68_2;
struct Struct_02048150;

struct Struct_ov026_021d8ba0 {
    unsigned char unknown_0_[4];
    signed char unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
};

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
    char unknown_a_[0x20];
    signed char unknown_2a_;
};

struct Struct_ov023_021f4c04 {
    char unknown_0_[0x30];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    char unknown_32_[REGION_LAYOUT(0x836, 0x966)];
    int unknown_998_;
};

struct Struct_ov023_021f4c04_2 {
    unsigned int unknown_0_;
};

struct Struct_ov023_021f4c04_3 {
    char unknown_0_[0x130];
    Struct_ov023_021f4c04_2* unknown_130_;
};

struct Struct_ov000_02160da0 {
    char unknown_0_[0x30];
    char unknown_30_[REGION_LAYOUT(0x108, 0x11c)];
    char unknown_14c_[REGION_LAYOUT(0xe0, 0x150)];
    Struct_ov000_02161e30* unknown_29c_;
    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0x974];
    char unknown_c18_[0x220];
    unsigned char unknown_e38_;
    unsigned char unknown_e39_;
    char unknown_e3a_[0x5e];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x4];
    int unknown_eac_;
    char unknown_eb0_[0x4];
    unsigned char unknown_eb4_;
    unsigned char unknown_eb5_;
    char unknown_eb6_[0x12];
    char unknown_ec8_[REGION_LAYOUT(0x28d8, 0x2898)];
    char unknown_3760_[0xb8];
    char unknown_3818_[0xc4];
    int unknown_38dc_;
    char unknown_38e0_[0x7d0];
    int unknown_40b0_;
    unsigned char unknown_40b4_;
    char unknown_40b5_[REGION_LAYOUT(0x124f, 0x11b7)];
    char unknown_526c_[REGION_LAYOUT(0x1f0, 0x150)];
    char unknown_53bc_[REGION_LAYOUT(0x1c0, 0xc0)];
    int unknown_547c_[8];
    int unknown_549c_[8];
    unsigned char unknown_54bc_;
    char unknown_54bd_[0x3];
    signed char unknown_54c0_[8];
    signed char unknown_54c8_;
    char unknown_54c9_[0x9];
    unsigned short unknown_54d2_;
    char unknown_54d4_[0x4];
    unsigned char unknown_54d8_;
    char unknown_54d9_[0x7];
    unsigned char unknown_54e0_;
    unsigned char unknown_54e1_;
    char unknown_54e2_[0x2];
    Struct_ov026_021d8ba0 unknown_54e4_;
    char unknown_54ee_[0x2];
    int unknown_54f0_;
    int unknown_54f4_[4];
    char unknown_5504_[REGION_LAYOUT(0xd0, 0xd4)];
    int unknown_55d8_;
    char unknown_55dc_[0x18];
    int unknown_55f4_;
    char unknown_55f8_[0x130];
    char unknown_5728_[0x1a6];
    unsigned short unknown_58ce_;
    char unknown_58d0_[0x34];
    char unknown_5904_[0xc];
    char unknown_5910_[0x40];
    unsigned char unknown_5950_;
    char unknown_5951_[0x3];
    char unknown_5954_[0xac];
    char unknown_5a00_[0x23c];
    char unknown_5c3c_[0x1200];
    int unknown_6e3c_;
    int unknown_6e40_;
    char unknown_6e44_[0x8cc];
    signed char unknown_7710_;
    unsigned char unknown_7711_;
    signed char unknown_7712_;
    char unknown_7713_[0x1];
    short unknown_7714_;
    short unknown_7716_[4];
    short unknown_771e_;
    short unknown_7720_;
    short unknown_7722_;
    short unknown_7724_;
    char unknown_7726_[0x9];
    unsigned char unknown_772f_;
    char unknown_7730_[0x4];
    int unknown_7734_;
    int unknown_7738_;
    char unknown_773c_[0xc];
    unsigned char unknown_7748_;
    unsigned char unknown_7749_;
    unsigned char unknown_774a_;
    char unknown_774b_[0x1];
    char unknown_774c_[0x14];
    char unknown_7760_[0x150];
};

struct Struct_ov023_021ed9f8 {
    void* unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
};

inline Struct_ov023_021ed9f8& inline_ov023_021f4c04() {
    static Struct_ov023_021ed9f8 s;
    return s;
}

extern Actor0209c678 g_bgmPlayer;
extern const char data_ov023_021fe1d8[];
extern const char data_ov023_021fe1ee[];
#if defined(jpn)
extern const char data_ov023_021fd49e[];
extern "C" void func_02073864(void*, void*, const char*, int, int, int);
extern "C" void func_0204500c(void*, const char*, int);
#endif

MessageWork* MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance(void);
void* GlobalFlags_GetInstance();
void* GameState_GetParty(GameState* gameState);
extern "C" void* LinkSession_GetInstance(void);
void SetField0x5729Value_0201075c(char* obj, unsigned char value);
unsigned char GetField0x5729Value_02010750(char* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021d2400(void);
void BgmPlayer_FadeOut(Actor0209c678* actor, int arg);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
void ResetListHeader020727d8(List020727d8* list);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath,
                                    unsigned int* outSize);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a4, int a5,
                              int a6);
void SetFieldForListedCombatants021f50fc();
extern "C" int func_ov000_02163c80(void* work, int mode);
GameObject* FindCombatantByField16a_021a278c(void* unused, int val);
void EnqueueEventTag87_021c9b20(int a, int b);
int TrySetMode02076ccc(void* obj, int mode);
extern "C" void func_ov017_021a23b0(void* base, int v);
unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void func_ov000_0216d370(void* obj, int flagA, int flagB, int flagC);
void* FindEntryByKey_02072a68(TableA68* table, int key);
extern "C" int sprintf(char* buffer, const char* format, ...);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, const char* arg1, int arg2, int arg3);
#endif
extern "C" void func_0209c6d8(void* arg0, int arg1);
extern "C" int func_ov017_021959b4(void);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* s, int val);
void EnqueueEventTag129_021cbfb8(unsigned short a, unsigned char b);
void StopAndReset0209c7fc(void* obj);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* obj);
void SetFieldsAndSignalData02184220_ov000_02160d80(void* p, int val);

// USA: func_ov023_021f4c04
extern "C" ARM void func_ov023_021f4c04(Struct_ov000_02160da0* arg0) {
    char var0[REGION_LAYOUT(0x50, 0xb4)];
#if !defined(jpn)
    unsigned int var1;
    unsigned char var2[4];
#endif

    GameState* gs = GameState::GetInstance();
    MessageWork* ctrl = MessageSystem_GetInstance();
    int res = (int)gs->GetResources();
    Zone3D_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FlagWord020466f4* flags = (FlagWord020466f4*)GlobalFlags_GetInstance();
    void* battle = GameState_GetParty(gs);
    void* owner = LinkSession_GetInstance();

    inline_ov023_021f4c04().unknown_4_ += var3->GetEffectiveDeltaTime();
    int var10 = arg0->unknown_eac_;

    if (var10 == 0) {
        func_0201075c((char*)var3, 1);
        for (int var11 = 0; var11 < 4; var11++) {
            GameObject* var12 = var3->GetPartyMemberByIndex(var11);
            if (var12 == NULL) continue;
            if (((Struct_ov023_021f4c04_3*)var12)->unknown_130_->unknown_0_ & 1) continue;
            if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var11)) continue;
            func_0201075c((char*)var3, 0);
        }
        if (GetField0x5729Value_02010750((char*)gs) != 0 && LinkSession_IsActive((int*)owner) != 0) {
            func_ov017_021d2400();
        }
        BgmPlayer_FadeOut(&g_bgmPlayer, 0x1e);
        SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x800000);
        FlagWord_ClearBits(flags, 0x40000);
        GetGlobal021ffefc().elapsed = 0;
        self->state = 1;
    } else if (state == 1) {
        if (GetGlobal021ffefc().elapsed < 1000) return;
        if (loader->GetNumQueuedTasks() > 0) return;
        ((SafeAllocator*)self->alloc)->Reset();
        ResetListHeader020727d8((List020727d8*)self->rosterList);
#if defined(jpn)
        func_02073864(arg0->unknown_5904_, arg0->unknown_30_, data_ov023_021fd49e, 0, 0, 0);
#else
        BackgroundLoader::AddLockGlobal();
        var1 = 0;
        void* var13 = ExtractFileFromGP2(data_ov023_021fe1d8, data_ov023_021fe1ee, &var1);
        if (var13 != NULL) {
            func_020728ac(arg0->unknown_5904_, arg0->unknown_30_, var13, var1, 0, 0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        func_ov023_021f50fc();
        int var14 = arg0->unknown_2a0_->unknown_8_;
        if (func_ov000_02163c80(arg0, 1)) {
            GameObject* var15 = func_ov017_021a278c((void*)var5, var14);
            if (var15 != NULL) {
                func_ov017_021c9b20((unsigned short)var14, 1);
                func_02076ccc(var15, 1);
                *(unsigned char*)((char*)var15 + 0x17d) &= ~0x80;
            }
        } else {
            func_ov017_021c9b20((unsigned short)var14, 0);
            func_ov017_021a23b0((void*)var5, var14);
        }
#if !defined(jpn)
        unsigned char count = GameState_GetPartyOrder((char*)gs, ids);
        unsigned char numMembers = 0;
        unsigned char numAlive = 0;
        for (int j = 0; j < count; j++) {
            GameObject* member = gs->GetCombatantByIndex(ids[j]);
            if (member == NULL) continue;
            if (!TestBitAt0x34_020a35e0((unsigned char*)self->party, ids[j])) continue;
            numMembers++;
            if ((((Combatant021f4c04*)member)->stats->flags & 1) == 0) numAlive++;
        }
        var4->unknown_30_ = var17;
        var4->unknown_31_ = var18;
#endif
        func_ov000_0216d370(arg0->unknown_c18_, 0, 0, 1);
#if defined(jpn)
        int var21 = *(int*)((char*)var3->GetProtagonist() + 0x134);
        sprintf(var0, (const char*)func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x14), var21);
        func_0204500c(var4, var0, 1);
#else
        var3->GetProtagonist();
        sprintf(var0, (const char*)func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x14));
        func_0204500c(var4, var0, 1, 0xe3);
#endif
        ctrl->busy = 1;
        ResetAndDispatchActorContext0209c6d8(&g_bgmPlayer, 0x3a);
        self->state = 2;
    } else if (state == 2) {
        if (func_ov017_021959b4() == 0 && *(unsigned char*)((char*)gs + REGION_LAYOUT(0x54c8, 0x5728)) == 0) {
            if (ctrl->busy != 0) return;
        }
        if (func_02086ef0((Struct_02048150*)var8, arg0->unknown_2a0_->unknown_2a_)) {
            func_ov017_021cbfb8(arg0->unknown_2a0_->unknown_8_, 1);
        }
        *(unsigned char*)((char*)gs + REGION_LAYOUT(0x54c8, 0x5728)) = 0;
        StopAndReset0209c7fc(&g_bgmPlayer);
        MessageSystem_Reset((char*)ctrl);
        MessageSystem_Stop(ctrl);
        SetFieldsAndSignalData02184220_ov000_02160d80(self, 4);
    }
}
