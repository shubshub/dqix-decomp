#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

unsigned char GameState_GetPartyOrder(char* obj, void* dst);
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
unsigned short GetFlagBitFromField150_0215eb20(void* obj, int bit);
struct SePlayer;
extern struct SePlayer g_sePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void* CheckNodeState6_0215e4c0(void* a, int key);
struct Obj021f809c;
extern "C" void func_ov023_021f809c(struct Obj021f809c*, void*);
extern "C" void func_ov023_021fc71c(void*, int, int);
extern "C" void func_020dc7e8(int, int);
extern "C" void func_ov004_0215ee90(void*);
extern "C" void func_ov004_0215f0c0(void*);
extern "C" void func_ov004_0215e5fc(void*, int);
extern "C" void func_ov004_0215eb40(void*);
extern "C" void func_ov004_0215ef14();
extern "C" void func_ov004_0216033c(void*);
extern "C" void func_ov004_02161514(void*);
extern "C" void func_ov004_02161c18(void*);
extern "C" void func_ov004_02162108(void*);
extern "C" void func_ov004_0216276c(void*);
extern "C" void func_ov023_021f66bc(void* arg0, int arg1, void* arg2);

struct Struct_ov004_0215fdfc_2 {
#if defined(jpn)
    char unknown_0_[0x8b8];
#else
    char unknown1_0_[0x950];
#endif
    int unknown_950_;
};

struct Struct_ov004_0215fdfc_3 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov004_0215fdfc_2* unknown_150_;
};

class Struct_ov004_0215fdfc_4 {
public:
    char unknown_0_[0xc];
    unsigned char unknown_c_;
};

struct Struct_ov004_0215fdfc_5 {
    char unknown_0_[0x104];
    short unknown_104_;
    short unknown_106_;
};

extern "C" Struct_ov004_0215fdfc_4* func_ov004_0215e47c(void* arg0, int arg1);

struct Struct_ov004_021707e8_2 {
#if defined(jpn)
    signed char unknown_5_;
    unsigned char unknown1_a_;
    unsigned char unknown_2_;
    unsigned char unknown_1_;
    signed char unknown_6_;
    signed char unknown_9_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_b_;
    unsigned char unknown_3_;
    unsigned char unknown_a_;
    unsigned char unknown_0_;
#else
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    signed char unknown_5_;
    signed char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_9_;
    unsigned char unknown1_a_;
    signed char unknown_b_;
#endif
    char unknown_c_[0x10];
    int unknown_1c_;
#if defined(jpn)
    char unknown_20_[0x40];
#else
    char unknown1_20_[0x4c];
#endif
    int unknown_6c_;
    int unknown_70_;
};

extern Struct_ov004_021707e8_2 data_ov004_021707e8;
#if defined(jpn)
extern int data_ov004_021705c4[];
extern unsigned char data_ov004_021710d5[];
extern "C" void func_ov004_0215fa1c();
#else
extern int data_ov004_0216fe5c[];
#endif
extern int data_ov004_02170854[];
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_02170845[];
extern unsigned char data_ov004_02170b90[];

// JPN: func_ov004_0215fdfc (02160780)
// USA: func_ov004_0215fdfc
extern "C" ARM int func_ov004_0215fdfc(void* a) {
    if (data_ov004_021707e8.busy == 1) return 0;
    data_ov004_021707e8.busy = 1;
    GameState* gs;
    GameObject* c;
    unsigned char saved;
    int none;
    int target;
    int n;
    unsigned char order[4];
    gs = GameState::GetInstance();
    n = GameState_GetPartyOrder((char*)gs, order);
    target = data_ov004_021707e8.combatant;
    none = 0;
    saved = data_ov004_021707e8.index;
    if (GetCombatantWithFlag0x100_0200ff1c(gs, target) == NULL) none = 1;
    if (!none) {
        data_ov004_021707e8.index = data_ov004_021707e8.index + 1;
        data_ov004_021707e8.index = (unsigned)data_ov004_021707e8.index % n;
    }
    data_ov004_021707e8.unknown_1c_ = var6[data_ov004_021707e8.unknown1_a_];
    var1 = func_0200ff1c(var0, data_ov004_021707e8.unknown_1c_);
    if (data_ov004_021707e8.unknown_1c_ == var4 && !var3) {
        var1 = NULL;
        while (var1 == NULL) {
            data_ov004_021707e8.unknown1_a_ = data_ov004_021707e8.unknown1_a_ + 1;
            data_ov004_021707e8.unknown1_a_ = (unsigned)data_ov004_021707e8.unknown1_a_ % var5;
            data_ov004_021707e8.unknown_1c_ = var6[data_ov004_021707e8.unknown1_a_];
            if (data_ov004_021707e8.unknown_1c_ == var4) {
                data_ov004_021707e8.unknown1_a_ = var2;
                data_ov004_021707e8.unknown_1c_ = var4;
                data_ov004_021707e8.unknown_0_ = 0;
                Struct_ov004_0215fdfc_4* var7 = func_ov004_0215e47c(arg0, 0x85);
                if (var7) var7->unknown_c_ |= 0x78;
                return 0;
            }
            var1 = func_0200ff1c(var0, data_ov004_021707e8.unknown_1c_);
            if (var1 != NULL) break;
        }
    }
    if (var1 == NULL) {
        while (var1 == NULL) {
            data_ov004_021707e8.unknown1_a_ = data_ov004_021707e8.unknown1_a_ + 1;
            data_ov004_021707e8.unknown1_a_ = (unsigned)data_ov004_021707e8.unknown1_a_ % var5;
            data_ov004_021707e8.unknown_1c_ = var6[data_ov004_021707e8.unknown1_a_];
            if (data_ov004_021707e8.unknown_1c_ == var4) {
                data_ov004_021707e8.unknown1_a_ = var2;
                data_ov004_021707e8.unknown_1c_ = var4;
                data_ov004_021707e8.unknown_0_ = 0;
                Struct_ov004_0215fdfc_4* var8 = func_ov004_0215e47c(arg0, 0x85);
                if (var8) var8->unknown_c_ |= 0x78;
                return 0;
            }
            var1 = func_0200ff1c(var0, data_ov004_021707e8.unknown_1c_);
            if (var1 != NULL) break;
        }
    }
    if (func_02061bd8((struct Struct_0205faf4_11*)var1)) {
        int var9 = 0;
        while (!var9) {
            data_ov004_021707e8.unknown1_a_ = data_ov004_021707e8.unknown1_a_ + 1;
            data_ov004_021707e8.unknown1_a_ = (unsigned)data_ov004_021707e8.unknown1_a_ % var5;
            data_ov004_021707e8.unknown_1c_ = var6[data_ov004_021707e8.unknown1_a_];
            if (data_ov004_021707e8.unknown_1c_ == var4) {
                data_ov004_021707e8.unknown1_a_ = var2;
                data_ov004_021707e8.unknown_1c_ = var4;
                data_ov004_021707e8.unknown_0_ = 0;
                return 0;
            }
            var1 = func_0200ff1c(var0, data_ov004_021707e8.unknown_1c_);
            if (var1 == NULL) {
                data_ov004_021707e8.unknown1_a_ = var2;
                data_ov004_021707e8.unknown_1c_ = var4;
                break;
            }
            if (func_02061bd8((struct Struct_0205faf4_11*)var1) == 0) var9 = 1;
        }
    }
    int var10 = ((Struct_ov004_0215fdfc_3*)var1)->unknown_150_->unknown_950_;
    data_ov004_021707e8.unknown_2_ = var10;
    data_ov004_021707e8.unknown_8_ = 0;
    data_ov004_021707e8.unknown_6c_ = 0;
    int var11 = var10 & 0xff;
    data_ov004_021707e8.unknown_70_ = var11;
    unsigned char var12 = 1;
    unsigned char var13 = 2;
    while (var13 < 0xd) {
#if defined(jpn)
        int var14 = data_ov004_021705c4[var12];
#else
        int var14 = data_ov004_0216fe5c[var12];
#endif
        data_ov004_02170854[var13] = var14;
        if (var11 != var14) {
            var13++;
            var12++;
        } else {
            var12++;
        }
    }
    int var15 = data_ov004_021707e8.unknown_8_;
    while (var11 != data_ov004_02170854[(unsigned char)var15]) {
        data_ov004_021707e8.unknown_8_ = (unsigned char)var15 + 1;
        var15 = data_ov004_021707e8.unknown_8_ % 13;
        data_ov004_021707e8.unknown_8_ = var15;
        if (var11 == data_ov004_02170854[data_ov004_021707e8.unknown_8_]) break;
    }
    for (int var16 = 0; var16 < 13; var16++) {
        if (func_ov004_0215eb20(var1, data_ov004_02170854[var16]) != 0) data_ov004_02170838[var16] = 1;
        else data_ov004_02170838[var16] = 0;
#if defined(jpn)
        if (func_ov004_0215eb20(var1, data_ov004_021705c4[var16]) != 0) data_ov004_021710d5[var16] = 1;
        else data_ov004_021710d5[var16] = 0;
#else
        if (func_ov004_0215eb20(var1, data_ov004_0216fe5c[var16]) != 0) data_ov004_02170845[var16] = 1;
        else data_ov004_02170845[var16] = 0;
#endif
    }
    data_ov004_021707e8.unknown_3_ = data_ov004_021707e8.unknown_8_;
    func_ov004_0215ee90(data_ov004_02170b90);
    data_ov004_021707e8.unknown_9_ = 0;
    data_ov004_021707e8.unknown_5_ = 0;
#if defined(jpn)
    func_ov004_0215e5fc(arg0, data_ov004_021707e8.unknown_1c_);
    func_ov004_0215f0c0(arg0);
#else
    func_ov004_0215f0c0(arg0);
    func_ov004_0215e5fc(arg0, data_ov004_021707e8.unknown_1c_);
#endif
    func_ov004_0215eb40(arg0);
#if defined(jpn)
    func_ov004_0215fa1c();
#else
    func_ov004_0215ef14();
#endif
    data_ov004_021707e8.f1 = 1;
    SePlayer_Play(&g_sePlayer, 1, 0);
    Node0215e47c* nd = func_ov004_0215e47c(a, 0x82);
    func_ov023_021fc71c(nd, data_ov004_021707e8.combatant, 1);
    data_ov004_021707e8.fb = 0;
    data_ov004_021707e8.f6 = 0;
    switch (data_ov004_021707e8.type - 0x64) {
    case 0:
        data_ov004_021707e8.unknown_6_ = data_ov004_021707e8.unknown_9_;
        func_ov004_0216033c(arg0);
        break;
    case 1:
        data_ov004_021707e8.unknown_6_ = data_ov004_021707e8.unknown_5_;
        func_ov004_02161514(arg0);
        break;
    case 2:
        data_ov004_021707e8.unknown_6_ = data_ov004_02170b90[0x23f];
        func_ov004_02161c18(arg0);
        break;
    case 3:
        data_ov004_021707e8.unknown_6_ = data_ov004_02170b90[0x47f];
        func_ov004_02162108(arg0);
        break;
    case 4:
        data_ov004_021707e8.unknown_6_ = 1;
        func_ov004_0216276c(arg0);
        break;
    }
    func_020dc7e8(2, (signed char)data_ov004_021707e8.unknown_1c_);
    func_020dc7e8(5, (signed char)data_ov004_021707e8.unknown_1c_);
    Struct_ov004_0215fdfc_5* var18 = (Struct_ov004_0215fdfc_5*)func_ov004_0215e4c0(arg0, 3);
    var18->unknown_104_ = data_ov004_021707e8.unknown_b_;
    var18->unknown_106_ = data_ov004_021707e8.unknown_6_;
    func_ov023_021f809c((struct Struct_ov004_0215fdfc*)var18, arg0);
    data_ov004_021707e8.unknown_0_ = 0;
    func_ov023_021f66bc(arg0, 0x85, (void*)1);
    return 0;
}
