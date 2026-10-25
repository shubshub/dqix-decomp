#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Combat/CombatantRecovery.h"

struct Struct_020fdcb0_3 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    unsigned char unknown_14_;
    unsigned char unknown_15_[3];
    int unknown_18_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
};
struct Struct_020fdc60_3 { unsigned char unknown_0_[0x14]; };
struct Struct_02022dc8 {
#if defined(jpn)
    unsigned char unknown_0_[0x8b8];
#else
    unsigned char unknown1_0_[0x950];
#endif
    int unknown_950_;
};
struct Struct_02022dc8_2 : GameObject {
#if defined(jpn)
    unsigned char unknown_13c_[0x144 - 0x13c];
#else
    unsigned char unknown1_13c_[0x150 - 0x13c];
#endif
    Struct_02022dc8* unknown_150_;
    unsigned char unknown_154_[0x38];
    unsigned int unknown_18c_;
};
struct FlagWord02046708;
struct Obj020214f0;
extern State_1f9b8 data_020fdcb0[4];
extern Stopwatch0201f9e8 data_020fdc60[4];
void InitStruct_0201f9b8(State_1f9b8*);
extern "C" void InitStopwatch0201f9e8(Stopwatch0201f9e8*);
unsigned short GetTableValue_0202053c(void*);
FlagWord02046708* GlobalFlags_GetInstance(void);
int TestFlags02046708(FlagWord02046708*, unsigned int);
#if defined(jpn)
extern "C" void func_02022644(Struct_02020554*);
#else
extern "C" void func_02022bb0(Struct_02020554*);
#endif
extern "C" void func_020e0688(Struct_02020554*);
extern "C" void func_02026694(Struct_02020554*);
extern "C" void func_020214f0(Struct_020214f0*);
extern "C" void func_02026bdc(Struct_02020554*, int);

// USA: func_02022dc8
extern "C" ARM void func_02022dc8(Struct_02020554* arg0) {
    GameState* var0 = GameState::GetInstance();
    for (int var1 = 0; var1 < 4; ++var1) {
        if (!var0->GetPartyMemberByIndex(var1)) func_0201f9b8(&data_020fdcb0[var1]);
    }
    int var2 = arg0->unknown_75c_;
    if (var2) {
        for (int var3 = var2; var3 < 4; ++var3) func_0201f9e8(&data_020fdc60[var3]);
    }
    for (int var4 = 0; var4 < arg0->unknown_75c_; ++var4) {
        int var5 = arg0->unknown_758_[var4];
        unsigned char var6 = 1 << var5;
        Struct_020fdcb0_3* var7 = &data_020fdcb0[var5];
        Struct_02022dc8_2* var8 = (Struct_02022dc8_2*)var0->GetPartyMemberByIndex(var5);
        if (!var8 || !(arg0->unknown_55d_ & var6)) continue;
        int var9 = var8->unknown_ac_.unknown_84_->unknown_4_;
        int var10 = var8->baseStats_->primaryStats.maxHP;
        int var11 = var8->unknown_ac_.unknown_84_->unknown_6_;
        int var12 = var8->baseStats_->primaryStats.maxMP;
        int var13 = var8->unknown_150_->unknown_950_;
        unsigned char var14 = func_0202053c(var8);
        int var15 = var8->unknown_ac_.unknown_84_->unknown_0_;
        var7->unknown_1d_ |= var7->unknown_10_ != var13;
        var7->unknown_1d_ |= var7->unknown_14_ != var14;
        var7->unknown_1d_ |= var7->unknown_18_ != var15;
        if (var7->unknown_0_ >= 0) {
            var7->unknown_1c_ |= var7->unknown_1d_;
            var7->unknown_1c_ |= var7->unknown_0_ != var9;
            var7->unknown_1c_ |= var7->unknown_4_ != var11;
            var7->unknown_1c_ |= var7->unknown_8_ != var10;
            var7->unknown_1c_ |= var7->unknown_c_ != var12;
        }
        var7->unknown_0_ = var9;
        var7->unknown_4_ = var11;
        var7->unknown_8_ = var10;
        var7->unknown_c_ = var12;
        var7->unknown_10_ = var13;
        var7->unknown_14_ = var14;
        var7->unknown_18_ = var15;
        if (var7->unknown_0_ > 0) var8->unknown_18c_ &= ~1;
        if (var7->unknown_1e_) {
            var7->unknown_1c_ = 0;
            var7->unknown_1e_ = 0;
        }
    }
    if (TestFlags02046708(GlobalFlags_GetInstance(), 1)) {
#if defined(jpn)
        func_02022644(arg0);
#else
        func_02022bb0(arg0);
#endif
    } else {
        if (arg0->unknown_9c5_ && arg0->unknown_764_) func_020e0688(arg0);
        if (arg0->unknown_9b8_) func_02026694(arg0);
        if (arg0->unknown_9c3_) func_020214f0((Struct_020214f0*)arg0);
        else func_02026bdc(arg0, 1);
    }
}
