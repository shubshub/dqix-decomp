#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov026_021db090_668 = 0x218, Enum_ov026_021db090_10416 = 0x28f0, Enum_ov026_021db090_8504 = 0x236c, Enum_ov026_021db090_2456 = 0x868, Enum_ov026_021db090_6491 = 0x1789, Enum_ov026_021db090_2468 = 0x874, Enum_ov026_021db090_6577 = 0x17e1, Enum_ov026_021db090_6492 = 0x178a, Enum_ov026_021db090_6590 = 0x17ee, Enum_ov026_021db090_6579 = 0x17e3 };
#else
enum { Enum_ov026_021db090_668 = 0x29c, Enum_ov026_021db090_10416 = 0x28b0, Enum_ov026_021db090_8504 = 0x2138, Enum_ov026_021db090_2456 = 0x998, Enum_ov026_021db090_6491 = 0x195b, Enum_ov026_021db090_2468 = 0x9a4, Enum_ov026_021db090_6577 = 0x19b1, Enum_ov026_021db090_6492 = 0x195c, Enum_ov026_021db090_6590 = 0x19be, Enum_ov026_021db090_6579 = 0x19b3 };
#endif

#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02161e30;
struct GameResources;
struct SePlayer;

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
};

struct Struct_ov026_021d8ba0_4 {
    char unknown_0_[0xb8];
};

struct Struct_ov026_021db090_4 {
    char unknown_0_[0x10];
    unsigned char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[3];
    signed char unknown_1c_;
};

struct Struct_ov000_02160da0 {
    char unknown_0_[Enum_ov026_021db090_668];
    Struct_ov000_02161e30* unknown_29c_;
    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0xc08];
    int unknown_eac_;
    char unknown_eb0_[Enum_ov026_021db090_10416];
    Struct_ov026_021d8ba0_4 unknown_3760_;
    char unknown_3818_[Enum_ov026_021db090_8504];
    unsigned char unknown_5950_;
};

struct Struct_ov026_021db090 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8];
};

struct Struct_ov000_02182c74 {
    short unknown_0_[4];
};

struct Struct_ov026_021db090_2 {
    char unknown_0_[0x14];
    unsigned int unknown_14_;
};

struct Struct_ov017_021af66c_5 {
    char unknown_0_[0x138];
    Struct_ov026_021db090_2* unknown_138_;
};

struct Struct_ov000_02182a60 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov026_021db090_3 {
    int unknown_0_[3];
};

struct Struct_ov000_0217964c_3 {
    Struct_ov026_021db090_3* unknown_0_;
    char unknown_4_[Enum_ov026_021db090_2456 - 4];
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
    char unknown_9a4_[Enum_ov026_021db090_6491 - Enum_ov026_021db090_2468];
    unsigned char unknown_195b_;
    char unknown_195c_[Enum_ov026_021db090_6577 - Enum_ov026_021db090_6492];
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
    char unknown_19b3_[Enum_ov026_021db090_6590 - Enum_ov026_021db090_6579];
    unsigned char unknown_19be_;
};

struct Struct_ov023_021f2a48_4 {
    char unknown_0_[0x5c];
    char* unknown_5c_;
};

extern "C" void __clear(void* p, int size);
MessageWindow* MessageSystem_GetInstance();
int IsFlag10088Set_02010088(struct S_10088*);
void InitObjFromCombatant020e4c74(void*, GameObject*);
void SetField0x158_02053ec8(void*, int);
void EnqueueEventTag86_021c9ad4(unsigned short);
void SePlayer_Play(SePlayer*, int, int);
void MessageSystem_Reset(char*);
void SetFieldsAndSignalData02184220_ov000_02160d80(void*, int);
CommandSlot* FindSlotById_021dae60(Container_021dae60*, int);

extern "C" {
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
void func_ov000_02162c14(Struct_ov000_02160da0*, int, Struct_ov026_021db090*);
void func_020dd0b0(int, char*);
void Zone3D_GetInstance();
void func_ov017_021a23b0(GameResources*, unsigned short);
#if defined(jpn)
void func_0204500c(Struct_ov000_0217964c_3*, char*, int);
#else
void func_0204500c(Struct_ov000_0217964c_3*, char*, int, int);
#endif
void MessageSystem_Stop(MessageWindow*);
void func_ov000_02160da0(BattleWork*);
}

#if defined(jpn)
extern char data_ov026_021df3fa[];
extern char data_ov026_021df3ff[];
extern char data_ov026_021df423[];
extern char data_ov026_021df465[];
#endif

extern char data_ov026_021dedee[];
extern IdList data_ov026_021de6bc;
extern SePlayer g_sePlayer;

// USA: func_ov026_021db090
extern "C" ARM void func_ov026_021db090(BattleWork* self) {
    GameState* gs = GameState::GetInstance();
    MessageWindow* win = MessageSystem_GetInstance();

    if (arg0->unknown_eac_ == 0) {
#if defined(jpn)
        char var2[0x80];
        char var5[0x40];
#else
        char var3[0x100];
        Struct_ov026_021db090_3 var4;
        unsigned short var5[0x20];
#endif
        Struct_ov026_021db090 var6;
        short var7[4];
        Struct_ov000_02182c74 var8;
        int var9;
#if defined(jpn)
        int var11;
        int var10;
#else
        int var11;
#endif
        int var12;
        char* var13;

#if defined(jpn)
        var0->GetProtagonist();
#else
        sprintf(var3, data_ov026_021dedee);
#endif
        __clear(var5, sizeof(var5));
        var9 = func_ov000_0215e9fc(arg0->unknown_29c_, var7, 4, 0);
        var8 = data_ov026_021de6bc;
#if defined(jpn)
        var11 = 0;
        var10 = 0;
#else
        var11 = 0;
#endif
        for (var12 = 0; var12 < var9; var12++) {
            GameObject* var14 = var0->GetCombatantByIndex(var7[var12]);
            if (var14 == NULL || func_02010088((Struct_02010088*)var14)) {
                continue;
            }
            func_ov000_02162c14(arg0, var7[var12], &var6);
            if (var6.unknown_1_ != 6) {
                continue;
            }
            if (((Struct_ov017_021af66c_5*)var14)->unknown_138_->unknown_14_ & 0x80019) {
                continue;
            }
            var8.unknown_0_[var11] = var7[var12];
#if defined(jpn)
            var11++;
            var10++;
#else
            var11++;
#endif
        }
#if defined(jpn)
        GameObject* var15 = var0->GetCombatantByIndex(var8.unknown_0_[0]);
        if (var15 != NULL) {
            strcpy(var5, (char*)var15->baseStats_);
        }
        if (var10 > 1) {
            strcat(var5, data_ov026_021df3fa);
        }
#else
        func_020e4c74(&var4, var0->GetPartyMemberByIndex(var8.unknown_0_[0]));
#endif

        if (arg0->unknown_5950_ == 2) {
#if defined(jpn)
            sprintf(var2, data_ov026_021df3ff, var5);
#else
            text = ((TextBuffers*)MessageSystem_GetInstance())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(1, text);
            strcat(message, text);
#endif

            int j;
            PartyList* party;
            GameState* state;
            state = GameState::GetInstance();
            party = (PartyList*)GameState_GetParty(state);
            for (j = 0; j < party->count; j++) {
                GameObject* member = GetCombatantWithFlag0x100_0200ff1c(state, party->members[j]);
                if (member != NULL) {
                    SetField0x158_02053ec8(member, 2);
                }
            }
            GameResources* res = GetGameResources();
            Zone3D_GetInstance();
            unsigned short netId = self->party->netId;
            EnqueueEventTag86_021c9ad4(netId);
            func_ov017_021a23b0(res, netId);
        } else if (self->mode == 4) {
#if defined(jpn)
            sprintf(var2, data_ov026_021df423, var5);
#else
            text = ((TextBuffers*)MessageSystem_GetInstance())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(2, text);
            strcat(message, text);
#endif
        } else {
#if defined(jpn)
            sprintf(var2, data_ov026_021df465, var5);
#else
            text = ((TextBuffers*)MessageSystem_GetInstance())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(3, text);
            strcat(message, text);
#endif
        }

#if defined(jpn)
        func_0204500c(var1, var2, 0);
#else
        var1->unknown_0_ = &var4;
        func_0204500c(var1, var3, 0, 0xe3);
#endif
        win->b19b1 = 0;
        win->b19b2 = 0;
        win->b19be = 1;
        win->flags |= 2;
        win->active = 1;
        SePlayer_Play(&g_sePlayer, 9, 0);
        self->state++;
    } else if (win->busy == 0) {
        self->state++;
        if (self->state >= 0x1e) {
            MessageSystem_Reset((char*)win);
            MessageSystem_Stop(win);
            if (self->mode == 2) {
                SetFieldsAndSignalData02184220_ov000_02160d80(self, 4);
            } else {
                for (int var22 = 0; var22 < 4; var22++) {
                    Struct_ov026_021db090_4* var23 = func_ov026_021dae60(&arg0->unknown_3760_, var22);
                    if (var23 != NULL && var23->unknown_1c_ == 6) {
                        var23->unknown_10_[var23->unknown_18_] = 0x66;
                    }
                }
                func_ov000_02160da0(arg0);
            }
        }
    }
}
