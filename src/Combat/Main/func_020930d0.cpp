#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ListHead02046b60;
struct Struct_02092cd0;

extern "C" void func_02092d60(void* s, int b);
extern "C" int func_020457e0(char* g);
extern "C" unsigned char* func_ov017_021b8478(void* p);
extern "C" void func_02094030(int* obj, short a, short b, int c);
extern "C" char* MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void* GameState_GetParty(GameState* gs);
extern "C" int* func_020936f8(void);
extern "C" unsigned int func_02092cd0(Struct_02092cd0* state, int kind);
extern "C" int func_02092d18(Struct_02092cd0* state, int kind);
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" int func_020a35f8(unsigned char* p);

struct Struct_02092cd0 {
    char unk0[0x30];
    short unknown_30_;
    short field32;
    unsigned char field34;
    unsigned char unknown_35_;
    char unknown_36_[0x39 - 0x36];
    signed char unknown_39_;
    char unknown_3a_;
    unsigned char unknown_3b_;
};

struct CombatantIndexList020930d0 {
    char unk0[0xf7c];
    unsigned char count;
};

struct Struct_020930d0_2 {
#if defined(jpn)
    char unk0[0x7ca2];
#else
    char unk0[0x7f76];
#endif
    unsigned char slots[4];
    unsigned char flags;
};

struct GlobalBlock020930d0 {
#if defined(jpn)
    char unk0[0x868];
#else
    char unk0[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[0x9a0 - 0x99c];
    int unknown_9a0_;
};

// USA: func_020930d0
extern "C" ARM void func_020930d0(struct Struct_02092cd0* s) {
    GameResources* res;
    GameState* gs;
    GlobalBlock020930d0* gf;
    int* g;
    unsigned int tableCount;
    unsigned char present;
    int i;
    struct CombatantIndexList020930d0* party;
    struct ListHead02046b60* list;
    unsigned char state;

    gs = GameState::GetInstance();
    gf = (GlobalBlock020930d0*)MessageSystem_GetInstance();
    res = GetGameResources();
    list = (struct ListHead02046b60*)res->fieldTaskQueue_;
    party = (struct CombatantIndexList020930d0*)GameState_GetParty(gs);
    g = func_020936f8();
    state = s->unknown_35_;

    if (state == 0) {
        s->unknown_30_ = 0;
        s->unknown_35_++;
        return;
    }

    if (state == 1) {
        tableCount = func_02092cd0(s, 1);
        present = 0;
        for (i = 0; i < 4; i++) {
            if (gs->GetPartyMemberByIndex(i)) present++;
        }
        unsigned char var10 = party->count;
        unsigned char var11 = present - var10;
        unsigned char total = var10 + var11;
        int var13 = 0;
        if (var11 == 0) {
            var13 = 1;
        } else if (tableCount == 0) {
            tableCount = 0;
            for (int i = 0; i < 4; i++) {
                if (((struct Struct_020930d0_2*)gs)->flags & (1 << i)) tableCount = (tableCount + 1) & 0xff;
            }
            if (tableCount >= var11) var13 = 1;
        }
        if (var13) {
            if (s->field32 != 0) return;
            MessageSystem_Reset((char*)gf);
            int next;
            int c0 = func_02092cd0(s, 0);
            int var17 = func_02092cd0(s, 5);
            if (c0 == 4 && var11 == 0) {
                next = 8;
            } else {
                next = 6;
                if (func_02046b60(list, 10)) {
                    if (total == func_020a35f8(func_ov017_021b8478(res->unknown_ptr_3718)) && c0 + var17 == 4) s->unknown_3b_ = 1;
                }
            }
            s->unknown_30_ = next;
            s->unknown_35_ = 3;
        } else {
            if (gf->unknown_998_ != 0) return;
            s->unknown_30_ = 5;
            s->unknown_35_++;
        }
        return;
    }

    if (state == 2) {
        if (gf->unknown_9a0_ != 0) return;
        int r = func_020457e0((char*)gf);
        if (r == 0) {
            s->unknown_35_ = 3;
            func_02092d60(s, 0);
            return;
        }
        if (r == 1) {
            s->unknown_35_ = 1;
            s->field32 = 0;
        }
        return;
    }

    if (state == 3) {
        if (s->unknown_39_ < 10) {
            s->unknown_39_ += gs->GetTickCount();
            return;
        }
        if (s->unknown_3b_ != 0) {
            s->unknown_3b_ = 0;
            func_02094030(g, 0x4e24, -1, 0);
        }
        if (func_02092cd0(s, 2) > 1) {
            func_02094030(g, 0x4e22, -1, func_02092d18(s, 2));
        } else if (func_02092cd0(s, 2) == 1) {
            func_02094030(g, 0x4e21, -1, func_02092d18(s, 2));
        }
        for (unsigned char i = 0; i < 4; i++) {
            if (((struct Struct_020930d0_2*)gs)->slots[i] == 4) {
                func_02094030(g, 0x2711, -1, (signed char)i);
            }
        }
        s->unknown_35_++;
        return;
    }

    if (state == 4) {
        if (gf->unknown_998_ == 0) {
            s->field34 = 4;
            s->unknown_35_ = 0;
        }
    }
}
