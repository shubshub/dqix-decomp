#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0208baec { int unknown_0_, unknown_4_; float unknown_8_; unsigned short unknown_c_; unsigned short unknown_e_; };
struct Struct_0208baec_2 { unsigned char unknown_0_[0xc]; int unknown_c_, unknown_10_, unknown_14_, unknown_18_; unsigned short unknown_1c_; unsigned short unknown_1e_; unsigned short unknown_20_; unsigned char unknown_22_; unsigned char unknown_23_[5]; };
struct Struct_0208bb78 {
    unsigned char unknown_0_[0x60];
    Struct_0208baec_2 unknown_60_;
    unsigned char unknown_88_[0xb4 - 0x88];
    Struct_0208baec_2* unknown_b4_;
    unsigned char unknown_b8_[0xc8 - 0xb8];
    float unknown_c8_;
    float unknown_cc_;
    unsigned char unknown_d0_[2];
    short unknown_d2_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_[2];
    unsigned char unknown_d7_;
    unsigned char unknown_d8_;
    signed char unknown_d9_;
    unsigned short unknown_da_;
};
typedef void (Struct_0208bb78::*Type_01ff8b48_6)();
struct Struct_020e8ce4 { Type_01ff8b48_6 unknown_0_[5]; };
#if defined(jpn)
extern Struct_020e8ce4 data_020e8e00;
#else
extern Struct_020e8ce4 data_020e8ce4;
#endif
extern Action0208bb78 __ptmf_null;
struct HeadNode02046b24;
struct Struct0200fb08;
struct GetTableByteOrFFData;
int AnimateSubBG0Shake0208ca00(ShakeState0208ca00*, int);
extern "C" void func_0208bf78(ShakeState0208ca00*);
extern "C" void func_0208b788(int, float, SrcStruct0208baec*, int);
int SetupDstFromSrcAndScale0208baec(int, DstStruct0208baec*, SrcStruct0208baec*, int, float, int, unsigned char);
unsigned char GameState_GetLanguage(Struct0200fb08*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
int* GetGlobal02109418_02094d6c();
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int TestBitInByteArrayAt0x84_02096088(void*, int);

// USA: func_0208bb78
extern "C" ARM int func_0208bb78(Struct_0208bb78* arg0, int arg1) {
    if (arg0->unknown_d2_ < 0) return 1;
    if (!arg1) arg1 = 1;
    int var0 = func_0208ca00(arg0, (signed char)arg1);
    if (arg0->unknown_d9_) {
        arg0->unknown_d9_ -= arg1;
        if (arg0->unknown_d9_ < 0) arg0->unknown_d9_ = 0;
    }
    if (arg0->unknown_da_ & 0x20) func_0208bf78(arg0);
    else {
#if defined(jpn)
        Struct_020e8ce4 var1 = data_020e8e00;
#else
        Struct_020e8ce4 var1 = data_020e8ce4;
#endif
        actions.actions[4] = __ptmf_null;
        if (!actions.actions[self->action]) return 1;
        (self->*actions.actions[self->action])();
    }
    GameState* state = GameState::GetInstance();
    GameResources* resources = state->GetResources();
    float scale;
    unsigned char slot;
    HeadNode02046b24** head = (HeadNode02046b24**)resources->fieldTaskQueue_;
    if (self->flags & 8) {
        int adjust = (self->flags & 0x100) != 0;
        SrcStruct0208baec values;
        func_0208b788(self->kind, self->factor, &values, adjust);
        scale = values.scale;
        if (!self->kind) scale *= scale;
        slot = 0;
        if (adjust) slot = 1;
        if (self->flags & 0x100) {
            values.y -= 16;
#if defined(jpn)
            func_0208baec((int)&arg0->unknown_60_, &arg0->unknown_b4_[var5], &var8, 0x40, var4, var0, 1);
#else
            func_0208baec((int)&arg0->unknown_60_, &arg0->unknown_b4_[var5], &var8, 0x20, var4, var0, 1);
#endif
            Struct_0208baec var9;
            memcpy(&var9, &var8, sizeof(var9));
            var9.unknown_4_ += 0x38;
#if !defined(jpn)
            if (GameState_GetLanguage((Struct0200fb08*)state) == 5) second.y += 16;
#endif
#if defined(jpn)
            func_0208baec((int)&arg0->unknown_60_, &arg0->unknown_b4_[(unsigned char)(var5 + 1)], &var9, 0x60, var4, var0, 1);
#else
            func_0208baec((int)&arg0->unknown_60_, &arg0->unknown_b4_[(unsigned char)(var5 + 1)], &var9, 0x30, var4, var0, 1);
#endif
        } else {
            int var10 = 1;
            if (func_02046b24(var6) == 0x2d) var5 = var10;
            else if (arg0->unknown_d8_ == 1) var10 = 0;
            if (var10) func_0208baec((int)&arg0->unknown_60_, &arg0->unknown_b4_[var5], &var8, 0x40, var4, var0, 1);
        }
    }
    if (arg0->unknown_d2_ != 9999 && arg0->unknown_d2_ >= 0 && arg0->unknown_d4_ != 0 && arg0->unknown_d4_ != 3 && func_02046b24(var6) != 0x2d) {
        int* var11 = func_02094d6c();
        int var12 = func_020965ac((Struct_02065990_3*)var11, (unsigned char)arg0->unknown_d2_);
        if (func_02096088(var11, var12)) {
            Struct_0208baec var13;
            func_0208b788(1, 1.0f, &var13, 0);
            func_0208baec((int)&arg0->unknown_60_, &arg0->unknown_b4_[1], &var13, 0x20, var13.unknown_8_, var0, 2);
        }
    }
    return 0;
}
