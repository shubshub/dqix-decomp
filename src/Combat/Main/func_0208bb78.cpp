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
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
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
            int draw = 1;
            if (FieldTaskQueue_GetCurrentKind(head) == 0x2d) slot = draw;
            else if (self->kind == 1) draw = 0;
            if (draw) SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[slot], &values, 0x40, scale, pivot, 1);
        }
    }
    if (self->id != 9999 && self->id >= 0 && self->action != 0 && self->action != 3 && FieldTaskQueue_GetCurrentKind(head) != 0x2d) {
        int* global = GetGlobal02109418_02094d6c();
        int value = GetTableByteOrFF_020965ac((GetTableByteOrFFData*)global, (unsigned char)self->id);
        if (TestBitInByteArrayAt0x84_02096088(global, value)) {
            SrcStruct0208baec values;
            func_0208b788(1, 1.0f, &values, 0);
            SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[1], &values, 0x20, values.scale, pivot, 2);
        }
    }
    return 0;
}
