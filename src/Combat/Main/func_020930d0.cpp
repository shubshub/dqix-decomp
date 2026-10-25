#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02038598_5;
struct Struct_02092cd0;

extern "C" void func_02092d60(void* s, int b);
extern "C" int func_020457e0(char* g);
extern "C" unsigned char* func_ov017_021b8478(void* p);
extern "C" void func_02094030(int* obj, short a, short b, int c);
char* MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
void* GameState_GetParty(GameState* gs);
int* GetGlobal02109030_020936f8(void);
unsigned int CountMatchingTableEntries02092cd0(BattlePhaseState020930d0* state, int kind);
int FindMatchingTableIndex02092d18(BattlePhaseState020930d0* state, int kind);
int ListContainsId(struct ListHead02046b60* list, int id);
int CountSetBitsAt0x34_020a35f8(unsigned char* p);

struct Struct_02092cd0 {
    char unknown_0_[0x30];
    short unknown_30_;
    short unknown_32_;
    unsigned char unknown_34_;
    unsigned char unknown_35_;
    char unknown_36_[0x39 - 0x36];
    signed char unknown_39_;
    char unknown_3a_;
    unsigned char unknown_3b_;
};

struct Struct_020930d0 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};

struct Struct_020930d0_2 {
#if defined(jpn)
    char unknown_0_[0x7ca2];
#else
    char unknown1_0_[0x7f76];
#endif
    unsigned char unknown_7f76_[4];
    unsigned char unknown_7f7a_;
};

struct Struct_020930d0_3 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[0x9a0 - 0x99c];
    int unknown_9a0_;
};

// USA: func_020930d0
extern "C" ARM void func_020930d0(struct Struct_02092cd0* arg0) {
    GameResources* var0;
    GameState* var1;
    Struct_020930d0_3* var2;
    int* var3;
    unsigned int var4;
    unsigned char var5;
    int var6;
    struct Struct_020930d0* var7;
    struct Struct_02038598_5* var8;
    unsigned char var9;

    gs = GameState::GetInstance();
    gf = (GlobalBlock020930d0*)MessageSystem_GetInstance();
    res = GetGameResources();
    list = (struct ListHead02046b60*)res->fieldTaskQueue_;
    party = (struct CombatantIndexList020930d0*)GameState_GetParty(gs);
    g = GetGlobal02109030_020936f8();
    state = s->field35;

    if (var9 == 0) {
        arg0->unknown_30_ = 0;
        arg0->unknown_35_++;
        return;
    }

    if (var9 == 1) {
        var4 = func_02092cd0(arg0, 1);
        var5 = 0;
        for (var6 = 0; var6 < 4; var6++) {
            if (var1->GetPartyMemberByIndex(var6)) var5++;
        }
        unsigned char var10 = var7->unknown_f7c_;
        unsigned char var11 = var5 - var10;
        unsigned char var12 = var10 + var11;
        int var13 = 0;
        if (var11 == 0) {
            var13 = 1;
        } else if (var4 == 0) {
            var4 = 0;
            for (int var14 = 0; var14 < 4; var14++) {
                if (((struct Struct_020930d0_2*)var1)->unknown_7f7a_ & (1 << var14)) var4 = (var4 + 1) & 0xff;
            }
            if (var4 >= var11) var13 = 1;
        }
        if (ready) {
            if (s->field32 != 0) return;
            MessageSystem_Reset((char*)gf);
            int next;
            int c0 = CountMatchingTableEntries02092cd0(s, 0);
            int c5 = CountMatchingTableEntries02092cd0(s, 5);
            if (c0 == 4 && missing == 0) {
                next = 8;
            } else {
                var15 = 6;
                if (func_02046b60(var8, 10)) {
                    if (var12 == func_020a35f8(func_ov017_021b8478(var0->unknown_ptr_3718)) && var16 + var17 == 4) arg0->unknown_3b_ = 1;
                }
            }
            arg0->unknown_30_ = var15;
            arg0->unknown_35_ = 3;
        } else {
            if (var2->unknown_998_ != 0) return;
            arg0->unknown_30_ = 5;
            arg0->unknown_35_++;
        }
        return;
    }

    if (var9 == 2) {
        if (var2->unknown_9a0_ != 0) return;
        int var18 = func_020457e0((char*)var2);
        if (var18 == 0) {
            arg0->unknown_35_ = 3;
            func_02092d60(arg0, 0);
            return;
        }
        if (var18 == 1) {
            arg0->unknown_35_ = 1;
            arg0->unknown_32_ = 0;
        }
        return;
    }

    if (var9 == 3) {
        if (arg0->unknown_39_ < 10) {
            arg0->unknown_39_ += var1->GetTickCount();
            return;
        }
        if (arg0->unknown_3b_ != 0) {
            arg0->unknown_3b_ = 0;
            func_02094030(var3, 0x4e24, -1, 0);
        }
        if (func_02092cd0(arg0, 2) > 1) {
            func_02094030(var3, 0x4e22, -1, func_02092d18(arg0, 2));
        } else if (func_02092cd0(arg0, 2) == 1) {
            func_02094030(var3, 0x4e21, -1, func_02092d18(arg0, 2));
        }
        for (unsigned char var19 = 0; var19 < 4; var19++) {
            if (((struct Struct_020930d0_2*)var1)->unknown_7f76_[var19] == 4) {
                func_02094030(var3, 0x2711, -1, (signed char)var19);
            }
        }
        arg0->unknown_35_++;
        return;
    }

    if (var9 == 4) {
        if (var2->unknown_998_ == 0) {
            arg0->unknown_34_ = 4;
            arg0->unknown_35_ = 0;
        }
    }
}
