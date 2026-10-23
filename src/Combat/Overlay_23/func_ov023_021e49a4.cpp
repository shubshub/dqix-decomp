#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/GameResources.h"

struct Struct_02045cac;
struct Struct_ov023_021e49a4_2 {
    unsigned char unknown_0_[0xc00];
    Struct_0201099c_3 unknown_c00_;
};
struct Struct_ov023_021e49a4_3 {
    unsigned char unknown_0_[0x1f8];
    Struct_ov023_021e49a4_2 unknown_1f8_;
};
struct Struct_ov023_021e49a4_4 {
    Struct_ov023_021e49a4_3* unknown_0_;
    unsigned char unknown_4_[0x500 - 4];
    unsigned short unknown_500_[4][16];
    int unknown_580_[4];
    unsigned short unknown_590_[4][10];
    unsigned short unknown_5e0_[8];
    unsigned short unknown_5f0_[4][8];
    unsigned char unknown_630_[0x10];
    char* unknown_640_[2];
};
struct Struct_02000c9c_70 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};
static inline int inline_ov023_021e49a4(Struct_02000c9c_70* arg0) { return arg0->unknown_4_; }
struct Struct_ov023_021e49a4_5 {
    unsigned char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
    unsigned char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};
struct Struct_ov023_021e49a4 {
    unsigned char unknown_0_[0x130];
    Struct_02000c9c_70* unknown_130_;
    char* unknown_134_;
    unsigned char unknown_138_[0x18];
    Struct_ov023_021e49a4_5* unknown_150_;
};
CombatSlots02045cac* GetGlobalField0x1c020421a0();
void InitCombatSlots02045cac(CombatSlots02045cac*);
char* CallFunc020e0434With02153694_020e51cc(int);
int KeyTable_Get(Container020e0310*, int);
int GetByteViaFieldIndirectOffset_021e4250_021e4250(char*);
extern const char data_ov023_021fdcd8[];
extern "C" {
void func_02045d14(Struct_02045cac*, const char*, unsigned short*, int);
int func_020420e8(const char*, int);
int func_ov017_021bdbcc(GameResources*);
void __clear(void*, unsigned int);
int sprintf(char*, const char*, ...);
void func_020439b0(Struct_02045cac*, int);
}

// USA: func_ov023_021e49a4
extern "C" ARM void func_ov023_021e49a4(Struct_ov023_021e49a4_4* arg0) {
    Struct_ov023_021e49a4_2* var0;
    GameState* var1 = GameState::GetInstance();
    unsigned short (*var2)[8];
    unsigned short (*var3)[10];
    unsigned short (*var4)[16];
    Struct_02045cac* var5 = func_020421a0();
    for (int var6 = 0; var6 < 4; var6++) {
        for (int var7 = 0; var7 < 16; var7++) arg0->unknown_500_[var6][var7] = 0xffff;
        for (int var8 = 0; var8 < 10; var8++) arg0->unknown_590_[var6][var8] = 0xffff;
        for (int var9 = 0; var9 < 8; var9++) arg0->unknown_5f0_[var6][var9] = 0xffff;
        arg0->unknown_580_[var6] = 0;
    }
    for (int var10 = 0; var10 < 8; var10++) arg0->unknown_5e0_[var10] = 0xffff;
    func_02045cac(var5);
    var0 = &arg0->unknown_0_->unknown_1f8_;
    func_02045d14(var5, func_020e51cc(0x3f3), arg0->unknown_5e0_, 0);
    for (int var11 = 0; var11 < 4; var11++) {
        var4 = arg0->unknown_500_;
        var3 = arg0->unknown_590_;
        var2 = arg0->unknown_5f0_;
        Struct_ov023_021e49a4* var12 = (Struct_ov023_021e49a4*)func_0200ff1c(var1, var11);
        if (var12 != 0) {
            char* var13 = var12->unknown_134_;
            func_02045d14(var5, var13, var4[var11], 0);
            arg0->unknown_580_[var11] = 35 - func_020420e8(var13, 0) / 2;
            short var14 = var12->unknown_150_->unknown_950_ + 500;
            if (func_ov017_021bdbcc(GetGameResources())) var14 = 500;
            if (inline_ov023_021e49a4(var12->unknown_130_) <= 0) {
                func_02045d14(var5, arg0->unknown_640_[var12->unknown_150_->unknown_49c_0_], var3[var11], 0);
            } else {
                func_02045d14(messages, (const char*)KeyTable_Get(&texts->dictionary, label), labels[i], 0);
            }
            unsigned char var15 = func_ov023_021e4250((char*)var12);
            char var16[16];
            __clear(var16, 16);
            if (var15 != 0) {
                sprintf(var16, data_ov023_021fdcd8, func_ov023_021e4250((char*)var12));
            }
            func_02045d14(var5, var16, var2[var11], 0);
            func_020439b0(var5, 0);
        }
    }
}
