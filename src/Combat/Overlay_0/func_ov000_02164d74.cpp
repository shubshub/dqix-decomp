#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct PtrBlock02164d74 {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Struct_ov000_02164d74_2 {
    char pad0[0x2c];
    int field2c;
    int unknown_30_;
};

struct Struct_ov000_02164d74_3 {
    char pad0[0x14];
    unsigned int unknown_14_;
};

struct Struct_ov000_02164d74_4 {
    Object3D obj3D;
    char unknown_ac_[0xc1 - sizeof(Object3D)];
    unsigned char unknown_c1_0_ : 2;
    unsigned char unknown_c1_2_ : 6;
    char unknown_c2_[0x130 - 0xc2];
    char* unknown_130_;
    char* unknown_134_;
    struct Struct_ov000_02164d74_3* stats;
#if defined(jpn)
    char unknown_13c_[0x180 - 0x13c];
#else
    char unknown1_13c_[0x18c - 0x13c];
#endif
    unsigned int unknown_18c_;
};

struct Struct_ov000_02164d74_5 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    int unknown_29c_;
    struct Struct_ov000_02164d74_2* info;
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

struct Bytes02033b88;

extern "C" void func_ov000_02163524(void*);
extern "C" void func_ov000_0217feb0(void* obj, unsigned char value, int id);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_ov000_02174a50(void* obj, int combatantId);
extern "C" struct Struct_ov000_02164d74_4* func_0200fea4(GameState* gs, int id);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_02089560(char* dst, char* buf, char* src);
extern "C" void func_0208936c(char* dst, char* arg1, char* src2);
void ApplyCombatantBuffs(int unused, int combatantId);
extern "C" void func_ov000_02174738(void* obj, int combatantId);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void func_ov000_021675a0(struct Struct_ov000_02164d74_5* battle);
extern "C" void func_ov000_021676a8(struct Struct_ov000_02164d74_5* battle);
extern "C" void func_ov017_021901ac(void* ov);
extern "C" void func_02049f3c(unsigned char* obj);
extern "C" void func_ov000_021677fc(struct Struct_ov000_02164d74_5* battle);
extern "C" void func_ov000_02167cd4(struct Struct_ov000_02164d74_5* battle);
extern "C" void func_ov000_02167dd8(unsigned char* obj);
extern "C" void func_ov000_02160fa8(void* work, int mask);

#define REG_POWCNT1 (*(volatile unsigned short*)0x04000304)

// USA: func_ov000_02164d74
extern "C" ARM void func_ov000_02164d74(struct Struct_ov000_02164d74_5* battle) {
    GameState* gs = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    func_ov000_02163524(battle);
    struct PtrBlock02164d74* pb = (PtrBlock02164d74*)GameState_GetParty(gs);
    int i;
    for (i = 0; i < pb->count; i++) {
        func_ov000_0217feb0(battle->unknown_3760_, 1, pb->ids[i]);
    }
    REG_POWCNT1 |= 0x8000;
    for (i = 0; i < 4; i++) {
        if (!func_020a35e0((unsigned char*)battle->info, i)) {
            func_ov000_02174a50(battle->unknown_3760_, i);
            continue;
        }
        struct Struct_ov000_02164d74_4* c = (Struct_ov000_02164d74_4*)func_0200ff1c(gs, i);
        if (c == NULL) {
            continue;
        }
        c->obj3D.MakeVisible();
        c->unknown_c1_0_ |= 3;
        GameObject_ForceMotionState((Bytes02033b88*)c, 0);
        c->obj3D.SetField06(battle->unknown_ec8_);
        if (battle->info->unknown_30_ != 0) {
            func_02089560((char*)c->stats, c->unknown_130_, c->unknown_134_);
            ApplyCombatantBuffs(battle->unknown_29c_, (short)i);
        } else {
            func_0208936c((char*)c->stats, c->unknown_130_, c->unknown_134_);
        }
        if (!(c->stats->unknown_14_ & 1)) {
            c->unknown_18c_ &= ~1;
        } else {
            GameObject_ForceMotionState((Bytes02033b88*)c, 4);
        }
        func_ov000_02174738(battle->unknown_3760_, i);
        func_ov017_021917f0(i, 1);
    }
    battle->unknown_77d2_ = 1;
    func_ov000_021675a0(battle);
    func_ov000_021676a8(battle);
    func_ov017_021901ac(ov);
    ClearFlags04(ov, 4);
    if (battle->info->field2c != 0) {
        unsigned char mask = battle->unknown_77d4_;
        for (i = 0; i < 8; i++) {
            struct Struct_ov000_02164d74_4* c = func_0200fea4(gs, i + 0xc0);
            if (c != NULL && !(mask & (1 << i))) {
                c->obj3D.MakeHidden();
                func_02049f3c((unsigned char*)c);
            }
        }
    }
    func_ov000_021677fc(battle);
    func_ov000_02167cd4(battle);
    func_ov000_02167dd8((unsigned char*)battle);
    func_ov000_02160fa8(battle, 0x200);
}
