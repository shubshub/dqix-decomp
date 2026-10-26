#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"


struct SearchState021c37a4 {
    char unk0[0x100d];
    unsigned char mode;
    char unknown_100e_[0x1029 - 0x100e];
    unsigned char flags;
};

struct Struct_ov017_021c37a4_7 {
    unsigned int flags;
    unsigned short state;
};

struct Struct_ov017_021c37a4_8 {
    char unk0[0x130];
    Struct_ov017_021c37a4_7* status;
    char* name;
#if defined(jpn)
    char unknown_138_[0x180 - 0x138];
#else
    char unknown1_138_[0x18c - 0x138];
#endif
    unsigned int flags;
};

struct Struct_ov017_021c37a4_9 {
    unsigned char data[6];
    signed char first;
    unsigned char a;
    unsigned char b;
    signed char last;
};

struct Struct_ov017_021c37a4_10 {
#if defined(jpn)
    char unk0[0x5a6c];
#else
    char unk0[0x5ccc];
#endif
    unsigned int flags;
#if defined(jpn)
    char unknown_5a70_[0x7280 - 0x5a70];
#else
    char unknown_5cd0_[0x74c0 - 0x5cd0];
#endif
    Struct_ov017_021c37a4_9 slots[3];
    char unknown_74de_[0x7e74 - 0x74de];
    int value;
};

struct Party021c37a4 {
    char unk0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
    char unknown_f7d_[0x2c94 - 0xf7d];
    int value;
};

struct Struct_ov017_021c37a4_2 {
    unsigned char from;
    unsigned char to;
};

struct Struct_ov017_021c37a4_3 {
#if defined(jpn)
    char unk0[0x1b64];
#else
    char unk0[0x64];
#endif
    unsigned short value;
};

struct Field021c37a4 {
#if defined(jpn)
    char unk0[0x860];
#else
    char unk0[0x2340];
#endif
    Struct_ov017_021c37a4_3 timer;
#if defined(jpn)
    char unknown_23c6_[0x2860 - 0x23c6];
#else
    char unknown_23a6_[0x2820 - 0x23a6];
#endif
    unsigned char flag;
    Struct_ov017_021c37a4_3* inline_ov017_021c37a4() { return &timer; }};

struct Actor021c37a4 {
    char unk0[0xc8];
    unsigned char flags;
};

struct Global021c37a4 {
#if defined(jpn)
    char unk0[0x1790];
#else
    char unk0[0x1962];
#endif
    unsigned char flag;
};

struct Struct_02039d84;
struct Struct_0205faf4_13;
struct Struct_0206e2a0;
struct Struct_02061c04_7;
struct TailList020469b4;
struct TailNode020469b4;
struct Struct_020e3004;
struct Struct_020e358c;
struct Struct_020e3814;
struct Actor0209c678;
struct Actor0209c20c;
struct FlagWord020466f4;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_020e2ff8(void);
extern "C" void* func_020e3580(void);
extern "C" void* func_020e3808(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" int LinkSession_GetState(int* obj);
extern "C" void GameState_UpdatePlayClocks(int arg);
extern "C" void __clear(void* buf, int len);
extern "C" void func_02012084(unsigned char* obj);
extern "C" void func_02011af0(void* obj);
extern "C" void func_02046a8c(void* a, void* b);
extern "C" void func_020d84e0(void);
extern "C" void LinkSession_End(void* obj);
extern "C" void LinkMessageQueue_Reset(void* obj);
extern "C" unsigned char GameState_GetProtagonistIndex(GameState* gs);
extern "C" int GameObject_IsClimbingLadder(char* obj);
extern "C" void func_02039d84(Struct_02039d84* obj);
extern "C" GameObject* func_0200ff58(GameState* gs, int idx);
extern "C" int func_020546a8(void* obj);
extern "C" void func_ov017_02190264(void* obj, int idx);
extern "C" void func_ov017_021c32b0(Struct_ov017_021c37a4_2* swap, int count);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" void GameState_SetProtagonistIndex(GameState* gs, int value);
extern "C" void func_020dcd40(void);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void Party_ReformLine(void* obj, int a, int b, int c, int d);
extern "C" void func_020546a0(void* obj, int value);
extern "C" void GameObject_SetFollowedMember(unsigned char* obj, int value);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
extern "C" void* GameState_GetFollowCamera(char* obj);
extern "C" void func_020a2770(void* obj, short value);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_0206e2dc(Struct_0205faf4_13* arr, int idx);
extern "C" void func_020abd20(int arg);
extern "C" void func_0206e2a0(Struct_0206e2a0* arr, int idx);
extern "C" void func_020d9ae8(Struct_02061c04_7* obj, int arg);
extern "C" void func_020d9dc4(char* dst, char* src);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_02086d88(unsigned char* obj, int key);
extern "C" void func_ov017_0218d500(void* obj);
extern "C" void func_020116c8(void* obj);
extern "C" void func_02048150(void* obj, int a, int b);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);
extern "C" void VectorizedMemset(void* dst, int value, int len);
extern "C" char* func_020936f8(void);
extern "C" void func_02093a14(char* obj);
extern "C" Field021c37a4* Zone3D_GetInstance(void);
extern "C" void func_ov017_02195748(unsigned char* obj);
extern "C" void func_020a2718(char* obj);
extern "C" void func_020e3004(Struct_020e3004* p);
extern "C" void func_020e358c(Struct_020e358c* p);
extern "C" void func_020e3814(Struct_020e3814* p);
extern "C" int func_0209c3ac(char* obj);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void BgmPlayer_FadeOut(Actor0209c678* obj, int state);
extern "C" void func_020bbd9c(void);
extern "C" int func_0209c6bc(void* obj);
extern "C" void func_0209c20c(Actor0209c20c* obj);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* obj, unsigned int flags);
extern "C" Global021c37a4* MessageSystem_GetInstance(void);

extern Actor021c37a4 g_bgmPlayer;

// USA: func_ov017_021c37a4
extern "C" ARM void func_ov017_021c37a4(void) {
    GameState* gs = GameState::GetInstance();
    Struct_ov017_021c37a4_10* battle = (Struct_ov017_021c37a4_10*)gs;
    SearchState021c37a4* search = (SearchState021c37a4*)LinkSession_GetInstance();
    GameResources* res = GetGameResources();
    void* d100044 = LinkMessageQueue_GetInstance();
    void* var5 = func_020e2ff8();
    void* var6 = func_020e3580();
    void* var7 = func_020e3808();
    void* d114e04 = GlobalFlags_GetInstance();
    int active = LinkSession_IsGuest(search);
    int state = LinkSession_GetState((int*)search);
    int mode = search->mode;
#if defined(jpn)
    char name[0xb];
#else
    char name[0x30];
#endif
    unsigned char bits[0x1a];
    Struct_ov017_021c37a4_2 leader;
    Struct_ov017_021c37a4_2 swap;

    if ((state == 5 && mode > 1) || state == 6) {
        GameState_UpdatePlayClocks(1);
    }

#if !defined(jpn)
    __clear(name, 0x30);
#endif
    if (active) {
#if defined(jpn)
        Struct_ov017_021c37a4_8* first = (Struct_ov017_021c37a4_8*)gs->GetPartyMemberByIndex(0);
        memset(name, 0, sizeof(name));
        char* src = first->name;
#else
        char* src = ((Struct_ov017_021c37a4_8*)gs->GetPartyMemberByIndex(0))->name;
#endif
        memcpy(name, src, strlen(src));
        func_02012084((unsigned char*)gs);
        func_02011af0(gs);
        func_02046a8c(res->fieldTaskQueue_, res->fieldTasks_[0x14]);
    }

    SetFlags00(res, 2);
    func_020d84e0();
    LinkSession_End(search);
    LinkMessageQueue_Reset(d100044);
#if !defined(jpn)
    search->flags &= ~0x10;
#endif

    for (int i = 0; i < 4; i++) {
        if (i == GameState_GetProtagonistIndex(gs)) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (active && member && GameObject_IsClimbingLadder((char*)member)) {
                func_02039d84((Struct_02039d84*)member);
            }
        } else {
            GameObject* combatant = func_0200ff58(gs, i);
            if (combatant && func_020546a8(combatant) == GameState_GetProtagonistIndex(gs)) {
                continue;
            }
            func_ov017_02190264(res, i);
        }
    }

    leader.from = GameState_GetProtagonistIndex(gs);
    leader.to = 0;
    if (leader.from != leader.to) {
        func_ov017_021c32b0(&leader, 1);
    }

    for (int i = 3; i >= 0; i--) {
        GameObject* obj = gs->GetGameObjectByIndex(i);
        if (obj && (obj->obj3D_.unknown_0_ & 0x1000)) {
            int empty = -1;
            for (int j = 3; i < j; j--) {
                if (gs->GetGameObjectByIndex(j) == NULL) {
                    empty = j;
                    break;
                }
            }
            if (empty != -1) {
                swap.from = i;
                swap.to = empty;
                if (swap.from != swap.to) {
                    func_ov017_021c32b0(&swap, 1);
                }
            }
        }
    }

    LinkSession_UpdateMemberCount(search);
    GameState_SetProtagonistIndex(gs, 0);
    if (active) {
        func_020dcd40();
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        func_ov017_02191234(res);
        Party_ReformLine(res, 1, 1, 1, 1);
    }

    for (int i = 0; i < 4; i++) {
        GameObject* combatant = func_0200ff58(gs, i);
        if (combatant) {
            func_020546a0(combatant, GameState_GetProtagonistIndex(gs));
            GameObject_SetFollowedMember((unsigned char*)combatant, GameState_GetProtagonistIndex(gs));
            GameObject_ResetTrail((unsigned char*)combatant);
        }
    }

    void* follower = GameState_GetFollowCamera((char*)gs);
    if (follower) {
        func_020a2770(follower, 0);
    }
    Party_ReformLine(res, 1, 0, 1, 1);
    func_ov017_02191234(res);
    battle->flags |= 2;

    Party021c37a4* party = (Party021c37a4*)GameState_GetParty(gs);
    if (active) {
        void* store = Scenario_GetInstance();
        memset(bits, 0, 0x1a);
        unsigned char* p = bits;
        unsigned char bit = 0;
        for (int i = 0; i < 0xcc; i++) {
            if (func_0206e2dc((Struct_0205faf4_13*)store, i)) {
                *p |= 1 << bit;
            }
            bit++;
            if (bit == 8) {
                p++;
                bit = 0;
            }
        }
        func_020abd20(0);
        party->value = battle->value;

        bit = 0;
        p = bits;
        bool changed = false;
        for (int i = 0; i < 0xcc; i++) {
            if (*p & (1 << bit)) {
                if (!func_0206e2dc((Struct_0205faf4_13*)store, i)) {
                    changed = true;
                }
                func_0206e2a0((Struct_0206e2a0*)store, i);
            }
            bit++;
            if (bit == 8) {
                p++;
                bit = 0;
            }
        }
        if (changed) {
            void* list;
            void* node = res->fieldTasks_[0x31];
            list = res->fieldTaskQueue_;
            func_020d9ae8((Struct_02061c04_7*)node, 0);
            func_020d9dc4((char*)node, name);
            func_020469b4((TailList020469b4*)list, (TailNode020469b4*)node);
        }
    }

    func_02086d88((unsigned char*)party, 0x5612);
    func_ov017_0218d500(res);
    if (active) {
        func_020116c8(gs);
    }

    Struct_ov017_021c37a4_8* hero = (Struct_ov017_021c37a4_8*)gs->GetPartyMemberByIndex(0);
    if (hero && (hero->status->flags & 1)) {
        func_02048150(hero, 0, 1);
        hero->status->state = 1;
        hero->flags &= ~1;
    }

    Party021c37a4* members = (Party021c37a4*)GameState_GetParty(gs);
    for (int i = 0; i < members->memberCount; i++) {
        unsigned char id = members->memberIds[i];
        if (func_0200ff1c(gs, id)) {
            func_ov017_02191aac(res, 0, id, 2);
        }
    }

    Struct_ov017_021c37a4_9* slot = battle->slots;
    for (int i = 0; i < 3; i++, slot++) {
        VectorizedMemset(slot, 0, 6);
        slot->first = -1;
        slot->a = 0;
        slot->b = 0;
        slot->last = -1;
    }

    func_02093a14(func_020936f8());
    Field021c37a4* field = Zone3D_GetInstance();
    Struct_ov017_021c37a4_3* timer = field->inline_ov017_021c37a4();
    timer->value = 0;
    res->unknown_42e2_ = 0;
    func_ov017_02195748((unsigned char*)res);
    func_020a2718((char*)follower);
    func_020e3004((Struct_020e3004*)var5);
    func_020e358c((Struct_020e358c*)var6);
    func_020e3814((Struct_020e3814*)var7);
    field->flag = 1;

    if (func_0209c3ac((char*)&g_bgmPlayer) != 0x7f) {
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
        func_020bbd9c();
    }
    g_bgmPlayer.flags &= ~4;
    if (!func_0209c6bc(&g_bgmPlayer)) {
        func_0209c20c((Actor0209c20c*)&g_bgmPlayer);
    }
    FlagWord_ClearBits((FlagWord020466f4*)d114e04, 0x800);
    MessageSystem_GetInstance()->flag = 0;
}
