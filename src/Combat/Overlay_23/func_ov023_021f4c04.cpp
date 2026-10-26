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
struct Actor0209c678;
struct FlagWord020466f4;
struct Struct_020727d8;
struct TableA68;
struct ArrayContainsByteStruct;

struct Struct_ov026_021d8ba0 {
    unsigned char b[4];
    signed char c;
    unsigned short d;
    unsigned short e;
};

struct PartyState {
    char pad0[0x8];
    unsigned short id;
    char unknown_a_[0x20];
    signed char kind;
};

struct MessageWork {
    char pad0[0x30];
    unsigned char numMembers;
    unsigned char unknown_31_;
    char unknown_32_[REGION_LAYOUT(0x836, 0x966)];
    int busy;
};

struct Struct_ov023_021f4c04_2 {
    unsigned int flags;
};

struct Struct_ov023_021f4c04_3 {
    char pad0[0x130];
    Struct_ov023_021f4c04_2* stats;
};

struct Struct_ov000_02160da0 {
    char pad0[0x30];
    char alloc[REGION_LAYOUT(0x108, 0x11c)];
    char stateA[REGION_LAYOUT(0xe0, 0x150)];
    Struct_ov000_02161e30* battle;
    PartyState* party;
    char unknown_2a4_[0x974];
    char view[0x220];
    unsigned char unknown_e38_;
    unsigned char unknown_e39_;
    char unknown_e3a_[0x5e];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x4];
    int state;
    char unknown_eb0_[0x4];
    unsigned char unknown_eb4_;
    unsigned char unknown_eb5_;
    char unknown_eb6_[0x12];
    char unknown_ec8_[REGION_LAYOUT(0x28d8, 0x2898)];
    char list[0xb8];
    char unknown_3818_[0xc4];
    int unknown_38dc_;
    char unknown_38e0_[0x7d0];
    int unknown_40b0_;
    unsigned char unknown_40b4_;
    char unknown_40b5_[REGION_LAYOUT(0x124f, 0x11b7)];
    char ownerNames[REGION_LAYOUT(0x1f0, 0x150)];
    char memberNames[REGION_LAYOUT(0x1c0, 0xc0)];
    int unknown_547c_[8];
    int memberIds[8];
    unsigned char groupKind;
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
    Struct_ov026_021d8ba0 cmd;
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
    signed char phase;
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
    int savedField;
    char unknown_773c_[0xc];
    unsigned char unknown_7748_;
    unsigned char unknown_7749_;
    unsigned char unknown_774a_;
    char unknown_774b_[0x1];
    char unknown_774c_[0x14];
    char stateB[0x150];
};

struct Struct_ov023_021ed9f8 {
    void* inner;
    unsigned int elapsed;
    unsigned int flags;
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

extern "C" MessageWork* MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_0201075c(char* obj, unsigned char value);
extern "C" unsigned char func_02010750(char* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021d2400(void);
extern "C" void BgmPlayer_FadeOut(Actor0209c678* actor, int arg);
extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath,
                                    unsigned int* outSize);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a4, int a5,
                              int a6);
extern "C" void func_ov023_021f50fc();
extern "C" int func_ov000_02163c80(void* work, int mode);
extern "C" GameObject* func_ov017_021a278c(void* unused, int val);
extern "C" void func_ov017_021c9b20(int a, int b);
extern "C" int func_02076ccc(void* obj, int mode);
extern "C" void func_ov017_021a23b0(void* base, int v);
extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void func_ov000_0216d370(void* obj, int flagA, int arg2, int flagC);
extern "C" void* func_02072a68(TableA68* table, int key);
extern "C" int sprintf(char* buffer, const char* format, ...);
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, const char* text, int mode, int tag);
#endif
extern "C" void func_0209c6d8(void* actor, int arg);
extern "C" int func_ov017_021959b4(void);
extern "C" int func_02086ef0(ArrayContainsByteStruct* s, int val);
extern "C" void func_ov017_021cbfb8(unsigned short a, unsigned char b);
extern "C" void func_0209c7fc(void* obj);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* obj);
extern "C" void func_ov000_02160d80(void* p, int val);

// USA: func_ov023_021f4c04
extern "C" ARM void func_ov023_021f4c04(Struct_ov000_02160da0* self) {
    char text[REGION_LAYOUT(0x50, 0xb4)];
#if !defined(jpn)
    unsigned int len;
    unsigned char ids[4];
#endif

    GameState* gs = GameState::GetInstance();
    MessageWork* ctrl = MessageSystem_GetInstance();
    int res = (int)gs->GetResources();
    Zone3D_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FlagWord020466f4* flags = (FlagWord020466f4*)GlobalFlags_GetInstance();
    void* battle = GameState_GetParty(gs);
    void* owner = LinkSession_GetInstance();

    inline_ov023_021f4c04().elapsed += gs->GetEffectiveDeltaTime();
    int state = self->state;

    if (state == 0) {
        func_0201075c((char*)gs, 1);
        for (int i = 0; i < 4; i++) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (member == NULL) continue;
            if (((Struct_ov023_021f4c04_3*)member)->stats->flags & 1) continue;
            if (func_020a35e0((unsigned char*)self->party, i)) continue;
            func_0201075c((char*)gs, 0);
        }
        if (func_02010750((char*)gs) != 0 && LinkSession_IsActive((int*)owner) != 0) {
            func_ov017_021d2400();
        }
        BgmPlayer_FadeOut(&g_bgmPlayer, 0x1e);
        func_ov000_02160fa8(self, 0x800000);
        FlagWord_ClearBits(flags, 0x40000);
        inline_ov023_021f4c04().elapsed = 0;
        self->state = 1;
    } else if (state == 1) {
        if (inline_ov023_021f4c04().elapsed < 1000) return;
        if (loader->GetNumQueuedTasks() > 0) return;
        ((SafeAllocator*)self->alloc)->Reset();
        func_020727d8((Struct_020727d8*)self->unknown_5904_);
#if defined(jpn)
        func_02073864(self->unknown_5904_, self->alloc, data_ov023_021fd49e, 0, 0, 0);
#else
        BackgroundLoader::AddLockGlobal();
        len = 0;
        void* file = ExtractFileFromGP2(data_ov023_021fe1d8, data_ov023_021fe1ee, &len);
        if (file != NULL) {
            func_020728ac(self->unknown_5904_, self->alloc, file, len, 0, 0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        func_ov023_021f50fc();
        int id = self->party->id;
        if (func_ov000_02163c80(self, 1)) {
            GameObject* target = func_ov017_021a278c((void*)res, id);
            if (target != NULL) {
                func_ov017_021c9b20((unsigned short)id, 1);
                func_02076ccc(target, 1);
                *(unsigned char*)((char*)target + 0x17d) &= ~0x80;
            }
        } else {
            func_ov017_021c9b20((unsigned short)id, 0);
            func_ov017_021a23b0((void*)res, id);
        }
#if !defined(jpn)
        unsigned char count = GameState_GetPartyOrder((char*)gs, ids);
        unsigned char numMembers = 0;
        unsigned char var18 = 0;
        for (int j = 0; j < count; j++) {
            GameObject* member = gs->GetCombatantByIndex(ids[j]);
            if (member == NULL) continue;
            if (!func_020a35e0((unsigned char*)self->party, ids[j])) continue;
            numMembers++;
            if ((((Struct_ov023_021f4c04_3*)member)->stats->flags & 1) == 0) var18++;
        }
        ctrl->numMembers = numMembers;
        ctrl->unknown_31_ = var18;
#endif
        func_ov000_0216d370(self->view, 0, 0, 1);
#if defined(jpn)
        int value = *(int*)((char*)gs->GetProtagonist() + 0x134);
        sprintf(text, (const char*)func_02072a68((TableA68*)self->unknown_5904_, 0x14), value);
        func_0204500c(ctrl, text, 1);
#else
        gs->GetProtagonist();
        sprintf(text, (const char*)func_02072a68((TableA68*)self->unknown_5904_, 0x14));
        func_0204500c(ctrl, text, 1, 0xe3);
#endif
        ctrl->busy = 1;
        func_0209c6d8(&g_bgmPlayer, 0x3a);
        self->state = 2;
    } else if (state == 2) {
        if (func_ov017_021959b4() == 0 && *(unsigned char*)((char*)gs + REGION_LAYOUT(0x54c8, 0x5728)) == 0) {
            if (ctrl->busy != 0) return;
        }
        if (func_02086ef0((ArrayContainsByteStruct*)battle, self->party->kind)) {
            func_ov017_021cbfb8(self->party->id, 1);
        }
        *(unsigned char*)((char*)gs + REGION_LAYOUT(0x54c8, 0x5728)) = 0;
        func_0209c7fc(&g_bgmPlayer);
        MessageSystem_Reset((char*)ctrl);
        MessageSystem_Stop(ctrl);
        func_ov000_02160d80(self, 4);
    }
}
