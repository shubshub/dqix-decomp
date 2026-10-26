#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02010088;
struct Struct_ov026_021d8ba0_10;
struct Struct_020465c0;
struct Struct_ov026_021d8ba0_4;

struct Struct_ov026_021dd8a8_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_[0xd];
};

struct Struct_ov026_021dd8a8_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov026_021dd8a8_2 unknown_4_[4];
};

struct Struct_ov000_02161e30 {
    char unknown_0_[0x81b0];
    Struct_ov026_021dd8a8_3 unknown_81b0_;
    char unknown_8214_[0xc10];
    int unknown_8e24_;
    char unknown_8e28_[0x21];
    unsigned char unknown_8e49_;
};

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
};

struct Struct_ov026_021db090_3 {
    int unknown_0_[3];
};

struct Struct_ov026_021db090_2 {
    unsigned int unknown_0_;
};

struct Struct_ov017_021af66c_5 {
    char unknown_0_[0x130];
    Struct_ov026_021db090_2* unknown_130_;
    char unknown_134_[0x14];
    void* unknown_148_;
};

struct Struct_ov026_021d8ba0_8 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov026_021dd8a8 {
    char unknown_0_[0x955];
    unsigned char unknown_955_;
};

struct Struct_ov023_021f4c04 {
    char unknown_0_[0x20];
    Struct_ov026_021db090_3* unknown_20_[4];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    char unknown_32_[0x5c - 0x32];
    char* unknown_5c_;
    char unknown_60_[0x998 - 0x60];
    int unknown_998_;
    char unknown_99c_[0x195b - 0x99c];
    unsigned char unknown_195b_;
    char unknown_195c_[0x19b1 - 0x195c];
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19d7 - 0x19b3];
    unsigned char unknown_19d7_;
};

extern "C" void __clear(void*, int);
extern "C" void func_02046380(Struct_ov023_021f4c04*);
extern "C" void func_020e4ce8(Struct_ov026_021db090_3*, GameObject*, int);
extern "C" Struct_ov026_021d8ba0_8* func_ov017_021b8478(void*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" void func_020dd0b0(int, char*);
extern "C" void func_0204500c(MessageWork*, char*, int, int);
extern "C" void func_02042b98(MessageWork*, int, int, int, int);
MessageWork* MessageSystem_GetInstance();
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8192Set_021dd3c4(FlagObj_021dd3c4*);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
unsigned char GameState_GetPartyOrder(char*, void*);
void* GetActiveCombatWork_ov000_02160130();
void* GetOffsetPtr02160f08(void*);
void* FindSlotById_021dae60(Container_021dae60*, int);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
char* InitAndClearBuffer_021d8a78(void*);

extern signed char data_ov026_021de6a6[];
extern signed char data_ov026_021de6a8[];
extern char data_ov026_021deebd[];
extern signed char data_ov026_021de6a2[];
extern char data_ov026_021deec7[];
extern char data_ov026_021deed8[];

// USA: func_ov026_021dd8a8
extern "C" ARM void func_ov026_021dd8a8(Struct_ov000_02161e30* arg0, Struct_ov000_0217e870_2* arg1) {
    char var0[0x300];
    Struct_ov026_021db090_3 var1[3];
    unsigned short var2[3];
    unsigned char var3[3];
    unsigned char var4[3];
    unsigned char var5[4];
    GameState* var6;
    void* var7;
    Struct_ov023_021f4c04* var8;
    int var9;
    Struct_ov026_021dd8a8_2* var10;
    int var11;
    int var12;
    int var13;
    int var14;
    int var15;
    unsigned char var16;
    Struct_ov026_021dd8a8_3* var17;
    int var18;
    unsigned char var19;
    int var20;
    void* var21;
    GameResources* var22;
    Struct_ov026_021d8ba0_8* var23;
    char* var24;
    int var25;
    int var26;

    gs = GameState::GetInstance();
    win = MessageSystem_GetInstance();
    if (battle->busy != 0) {
        return;
    }
    func_02046380(var8);
    var17 = &arg0->unknown_81b0_;
    var9 = 0;
    __clear(var3, sizeof(var3));
    __clear(var4, sizeof(var4));
    for (var10 = var17->unknown_4_, var12 = 0; var12 < var17->unknown_1_4_; var10++, var12++) {
        var25 = 0;
        for (int var27 = 0; var27 < var9; var27++) {
            if (var10->unknown_0_ == var2[var27] || var10->unknown_0_ == 0) {
                if (var10->unknown_0_ == var2[var27]) {
                    var3[var27] = 1;
                }
                var25 = 1;
                break;
            }
        }
        if (var25) {
            continue;
        }
        var2[var9] = var10->unknown_0_;
        for (var14 = 0; var14 < var10->unknown_a_0_; var14++) {
            GameObject* var28 = func_0200fea4(var6, var10->unknown_2_[var14] + 0xc0);
            if (var28 == NULL || func_02010088((Struct_02010088*)var28) || func_ov026_021dd3c4((Struct_ov026_021d8ba0_10*)var28)) {
                continue;
            }
            if (((Struct_ov017_021af66c_5*)var28)->unknown_148_ == NULL) {
                continue;
            }
            Struct_ov026_021db090_3* var29 = &var1[var9];
            func_020e4ce8(var29, var28, 1);
            var29->unknown_0_[2] &= ~0x80000000;
            var8->unknown_20_[var9] = var29;
            var4[var9] = var10->unknown_a_0_;
            var9++;
            break;
        }
    }

    var22 = GetGameResources();
    var7 = NULL;
    var23 = NULL;
    var15 = (int)var7;
    if (var22 != NULL) {
        var7 = var22->unknown_ptr_3718;
    }
    var11 = var15 - 1;
    if (var7 != NULL) {
        var23 = func_ov017_021b8478(var7);
    }
    if (var23 != NULL) {
        var11 = var23->unknown_c_;
    }
    var13 = 0;
    if (var4[0] > 1 || var3[0] == 1) {
        func_020465c0((Struct_020465c0*)var8, 0, 0);
        var13 = 1;
    } else {
        func_020465c0((Struct_020465c0*)var8, 0, 1);
    }

    count = GameState_GetPartyOrder((char*)gs, ids);
    idle = 0;
    present = 0;
    slots = GetOffsetPtr02160f08(GetActiveCombatWork_ov000_02160130());
    for (i = 0; i < count; i++) {
        GameObject* c = gs->GetCombatantByIndex(ids[i]);
        FindSlotById_021dae60((Container_021dae60*)slots, ids[i]);
        if (c == NULL) {
            continue;
        }
        if (!func_020a35e0((unsigned char*)arg1, var5[var18])) {
            continue;
        }
        var19++;
        if (!(((Struct_ov017_021af66c_5*)var30)->unknown_130_->unknown_0_ & 1)) {
            var16++;
        }
    }
    var8->unknown_30_ = var19;
    var8->unknown_31_ = var16;

    switch (var9) {
    case 1:
        var26 = 6;
        break;
    case 2:
        var26 = 7;
        {
            int var31 = 1;
            if (var4[1] > 1 || var3[1] == 1) {
                var31 = 0;
            }
            func_020465c0((Struct_020465c0*)var8, 1, var31);
        }
        var13 = 1;
        break;
    default:
        if (var11 == 0x36 || var11 == 0x43 || var11 == 0x50) {
            var26 = 8;
        } else {
            var13 = 1;
            var26 = 9;
        }
        break;
    }

    text = MessageSystem_GetInstance()->text;
    memset(text, 0, 0x960);
    func_020dd0b0(msgId, text);
    strcpy(message, text);
    if (battle->kind == 1) {
        SideInfo* info = (SideInfo*)GetOffsetPtr02160f08(func_ov017_021b8468(zone));
        unsigned char side = party->netId % 2;
        if (info != NULL) {
            info->side = side;
        }
        var26 = data_ov026_021de6a6[var33];
        if (var13) {
            var26 = data_ov026_021de6a8[var33];
            var8->unknown_19d7_ = 1;
        }
        text = MessageSystem_GetInstance()->text;
        memset(text, 0, 0x960);
        func_020dd0b0(msgId, text);
        strcat(message, text);
    } else if (battle->kind == 2) {
        strcat(message, data_ov026_021deebd);
        strcat(message, InitAndClearBuffer_021d8a78((void*)data_ov026_021de6a2[party->netId % 2]));
        if (extra) {
            win->b19d7 = 1;
        }
    }
    if (arg0->unknown_8e49_ != 0) {
        strcat(var0, data_ov026_021deec7);
    } else {
        strcat(var0, data_ov026_021deed8);
    }
    func_0204500c(var8, var0, 0, 0xe3);
    var8->unknown_19b1_ = 0;
    func_02042b98(var8, 2, 0x92, 0xfc, 0x4a);
    var8->unknown_19b2_ = 0;
    var8->unknown_195b_ |= 2;
    var8->unknown_998_ = 1;
}
