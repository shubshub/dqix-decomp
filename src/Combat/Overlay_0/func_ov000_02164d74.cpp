#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov000_02164d74 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_02164d74_2 {
    char unknown_0_[0x2c];
    int unknown_2c_;
    int unknown_30_;
};

struct Struct_ov000_02164d74_3 {
    char unknown_0_[0x14];
    unsigned int unknown_14_;
};

struct Struct_ov000_02164d74_4 {
    Object3D unknown_0_;
    char unknown_ac_[0xc1 - sizeof(Object3D)];
    unsigned char unknown_c1_0_ : 2;
    unsigned char unknown_c1_2_ : 6;
    char unknown_c2_[0x130 - 0xc2];
    char* unknown_130_;
    char* unknown_134_;
    struct Struct_ov000_02164d74_3* unknown_138_;
#if defined(jpn)
    char unknown_13c_[0x180 - 0x13c];
#else
    char unknown1_13c_[0x18c - 0x13c];
#endif
    unsigned int unknown_18c_;
};

struct Struct_ov000_02164d74_5 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    int unknown_29c_;
    struct Struct_ov000_02164d74_2* unknown_2a0_;
    char unknown_2a4_[0xec8 - 0x2a4];
    unsigned short unknown_ec8_;
#if defined(jpn)
    char unknown_e46_[0x371c - 0xe46];
    char unknown_3760_[0x79c2 - 0x371c];
#else
    char unknown_eca_[0x3760 - 0xeca];
    char unknown_3760_[0x77d2 - 0x3760];
#endif
    unsigned char unknown_77d2_;
    char unknown_77d3_;
    unsigned char unknown_77d4_;
};

struct Struct_02010604;

extern "C" void func_ov000_02163524(void*);
extern "C" void func_ov000_0217feb0(void* arg0, unsigned char arg1, int arg2);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_ov000_02174a50(void* arg0, int arg1);
extern "C" struct Struct_ov000_02164d74_4* func_0200fea4(GameState* arg0, int arg1);
extern "C" void func_02033b88(Struct_02010604*, int);
extern "C" void func_02089560(char* arg0, char* arg1, char* arg2);
extern "C" void func_0208936c(char* arg0, char* arg1, char* arg2);
void ApplyCombatantBuffs(int unused, int combatantId);
extern "C" void func_ov000_02174738(void* arg0, int arg1);
extern "C" void func_ov017_021917f0(int arg0, int arg1);
extern "C" void func_ov000_021675a0(struct Struct_ov000_02164d74_5* arg0);
extern "C" void func_ov000_021676a8(struct Struct_ov000_02164d74_5* arg0);
extern "C" void func_ov017_021901ac(void* arg0);
extern "C" void func_02049f3c(unsigned char* arg0);
extern "C" void func_ov000_021677fc(struct Struct_ov000_02164d74_5* arg0);
extern "C" void func_ov000_02167cd4(struct Struct_ov000_02164d74_5* arg0);
extern "C" void func_ov000_02167dd8(unsigned char* arg0);
extern "C" void func_ov000_02160fa8(void* arg0, int arg1);

#define REG_POWCNT1 (*(volatile unsigned short*)0x04000304)

// USA: func_ov000_02164d74
extern "C" ARM void func_ov000_02164d74(struct Battle02164d74* battle) {
    GameState* gs = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    GetField02163524(battle);
    struct PtrBlock02164d74* pb = (PtrBlock02164d74*)GameState_GetParty(gs);
    int i;
    for (i = 0; i < pb->count; i++) {
        func_ov000_0217feb0(battle->sub3760, 1, pb->ids[i]);
    }
    REG_POWCNT1 |= 0x8000;
    for (var3 = 0; var3 < 4; var3++) {
        if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var3)) {
            func_ov000_02174a50(arg0->unknown_3760_, var3);
            continue;
        }
        struct Struct_ov000_02164d74_4* var4 = (Struct_ov000_02164d74_4*)func_0200ff1c(var0, var3);
        if (var4 == NULL) {
            continue;
        }
        var4->unknown_0_.MakeVisible();
        var4->unknown_c1_0_ |= 3;
        func_02033b88((Struct_02010604*)var4, 0);
        var4->unknown_0_.SetField06(arg0->unknown_ec8_);
        if (arg0->unknown_2a0_->unknown_30_ != 0) {
            func_02089560((char*)var4->unknown_138_, var4->unknown_130_, var4->unknown_134_);
            ApplyCombatantBuffs(arg0->unknown_29c_, (short)var3);
        } else {
            func_0208936c((char*)var4->unknown_138_, var4->unknown_130_, var4->unknown_134_);
        }
        if (!(var4->unknown_138_->unknown_14_ & 1)) {
            var4->unknown_18c_ &= ~1;
        } else {
            func_02033b88((Struct_02010604*)var4, 4);
        }
        func_ov000_02174738(arg0->unknown_3760_, var3);
        func_ov017_021917f0(var3, 1);
    }
    arg0->unknown_77d2_ = 1;
    func_ov000_021675a0(arg0);
    func_ov000_021676a8(arg0);
    func_ov017_021901ac(var1);
    ClearFlags04(var1, 4);
    if (arg0->unknown_2a0_->unknown_2c_ != 0) {
        unsigned char var5 = arg0->unknown_77d4_;
        for (var3 = 0; var3 < 8; var3++) {
            struct Struct_ov000_02164d74_4* var6 = func_0200fea4(var0, var3 + 0xc0);
            if (var6 != NULL && !(var5 & (1 << var3))) {
                var6->unknown_0_.MakeHidden();
                func_02049f3c((unsigned char*)var6);
            }
        }
    }
    func_ov000_021677fc(arg0);
    func_ov000_02167cd4(arg0);
    func_ov000_02167dd8((unsigned char*)arg0);
    func_ov000_02160fa8(arg0, 0x200);
}
