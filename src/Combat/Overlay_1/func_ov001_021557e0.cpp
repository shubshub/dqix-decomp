#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

// USA: func_ov001_021557e0

extern "C" int func_ov001_02153994(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void* func_020e2ff8(void);
struct Flags02033fcc;
extern "C" void GameObject_PauseMovement(struct Flags02033fcc* obj);
extern "C" unsigned char GameObject_IsClimbingLadder(char* obj);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
struct Base02010834;
extern "C" void GameState_GetPartyMemberIds(struct Base02010834* base, int index, int* out, int* outCount);
extern "C" void GameObject_ClearHidden(unsigned char* obj);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void* GameState_GetParty(GameState* battleStruct);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);
struct Struct_0205420c;
extern "C" void func_0205420c(struct Struct_0205420c* obj, int a, int b);
extern "C" void func_ov017_02191f4c(int a, int b);
extern "C" void func_ov017_02192400(int a, int b);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" void func_ov017_021917f0(int a, int b);
extern "C" void func_020e3368(unsigned char* base, unsigned char val);
struct Struct_ov001_02154de4;
extern "C" int func_ov001_02154de4(struct Struct_ov001_02154de4* self);

#if defined(jpn)
#define data_ov001_02164bd1 data_ov001_02166171
#endif
extern const char data_ov001_02164bd1[];

#if defined(jpn)
#define COMBATANT_FLAGS_021557e0 0x180
#else
#define COMBATANT_FLAGS_021557e0 0x18c
#endif

struct Struct_ov001_021557e0 {
    char pad0[0xc1];
    unsigned char unknown_c1_0_ : 2;
    char pad1[0x130 - 0xc2];
    unsigned int* unknown_130_;
    char pad2[COMBATANT_FLAGS_021557e0 - 0x134];
    unsigned int unknown_18c_;
};

struct Struct_ov001_021557e0_2 {
    char pad0[0xa];
    unsigned short field_a;
    char pad1[0x12 - 0xc];
    unsigned char f12;
    char pad2[0x50 - 0x13];
    unsigned short unknown_50_;
#if defined(jpn)
    char pad3[0xf4 - 0x52];
#else
    char pad3[0xf8 - 0x52];
#endif
    unsigned int flag_f8 : 27;
    unsigned int unknown_fb_3_ : 5;
    char pad4[0x101 - 0xfc];
    unsigned char unknown_101_;
    char pad5[0x103 - 0x102];
    unsigned char unknown_103_;
    char pad6[0x116 - 0x104];
    signed char f116;
};

extern "C" ARM int func_ov001_021557e0(struct Struct_ov001_021557e0_2* self) {
    GameResources* res = GetGameResources();
    if (IsScreenFullyFaded((GameResources*)res, false) != 0) {
        self->unknown_101_ = 1;
    }
    if (func_ov001_02153994() != 1) {
        return self->field_a;
    }

    void* search = LinkSession_GetInstance();
    GameState* bs = GameState::GetInstance();

    if (self->f12 != 0 && LinkSession_IsGuest(search) != 0) {
        self->unknown_103_ = 1;
        if (self->flag_f8 & 0x10) {
            GameObject* g = func_0200ff1c(bs, 0);
            ((unsigned int*)((char*)g + COMBATANT_FLAGS_021557e0))[0] |= 2;
        }
    }

    if (self->unknown_101_ != 0) {
        for (int i = 0; i < 4; i++) {
            GameObject* m = bs->GetPartyMemberByIndex(i);
            if (m == 0) {
                continue;
            }
            GameObject_PauseMovement((struct Flags02033fcc*)m);
            if (GameObject_IsClimbingLadder((char*)m) == 0 || GameObject_GetLadderClimb(m)->command != 2) {
                m->obj3D_.SetAnimationByName(data_ov001_02164bd1, 0x10);
            }
            GameObject_ResetTrail((unsigned char*)m);
            m->obj3D_.EnableFlag(0x800000);
        }

        int list[4];
        int count;
        GameState_GetPartyMemberIds((struct Base02010834*)bs, GameState_GetProtagonistIndex(bs), list, &count);
        for (int j = 0; j < count; j++) {
            GameObject* m = bs->GetPartyMemberByIndex(list[j]);
            if (m == 0) {
                continue;
            }
            m->obj3D_.SetInheritedAlpha(0x1f);
            GameObject_ClearHidden((unsigned char*)m);
        }

        unsigned int* data = (unsigned int*)GlobalFlags_GetInstance();
        void* arr = GameState_GetParty(bs);
        for (int k = 0; k < 4; k++) {
            struct Struct_ov001_021557e0* c = (struct Struct_ov001_021557e0*)func_0200ff1c(bs, k);
            if (c == 0) {
                continue;
            }
            if (func_02086ef0((struct ArrayContainsByteStruct*)arr, k) != 0) {
                func_0205420c((struct Struct_0205420c*)c, 1, 0);
            }
            func_ov017_02191f4c((int)res, k);
            func_ov017_02192400((int)res, k);
        }
        FlagWord_SetBits(data, 0x20000);
    }

    if (LinkSession_IsActive((int*)search) != 0 && self->f12 != 0 && self->f116 < 0) {
        if (self->unknown_101_ != 0) {
            int limit = GameState_GetLeaderIndex(bs);
            for (int n = 0; n < 4; n++) {
                if (n == limit) {
                    continue;
                }
                struct Struct_ov001_021557e0* c = (struct Struct_ov001_021557e0*)func_0200ff1c(bs, n);
                if (c == 0) {
                    continue;
                }
                c->unknown_c1_0_ |= 1;
                c->unknown_c1_0_ |= 2;
                func_ov017_021917f0(n, 0);
                if (!(*c->unknown_130_ & 1)) {
                    c->unknown_18c_ |= 2;
                }
            }
        }
    } else if (self->f116 >= 0) {
        struct Struct_ov001_021557e0* c = (struct Struct_ov001_021557e0*)func_0200ff1c(bs, self->f116);
        if (c != 0) {
            c->unknown_c1_0_ |= 1;
            c->unknown_c1_0_ |= 2;
            c->unknown_18c_ |= 2;
            func_ov017_021917f0(self->f116, 0);
        }
    }

    SetFlags04(res, 0x1000);

    if (self->unknown_50_ & 0x200) {
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | 0x1100;
    }

    if ((self->flag_f8 & 0x10) && LinkSession_IsHostOrSolo(search) != 0) {
        func_020e3368((unsigned char*)func_020e2ff8(), 1);
        return 0x12;
    }
    return func_ov001_02154de4((struct Struct_ov001_02154de4*)self);
}
