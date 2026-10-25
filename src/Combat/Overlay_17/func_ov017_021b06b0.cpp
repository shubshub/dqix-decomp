#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov017_021b06b0_3 {
    char unknown_0_[0xa]; unsigned char unknown_a_; char unknown_b_;
    signed char unknown_c_; char unknown_d_[0x25 - 0xd]; unsigned char unknown_25_;
#if defined(jpn)
    char unknown_26_[0x218 - 0x26]; void* unknown_288_;
#else
    char unknown1_26_[0x288 - 0x26]; void* unknown_288_;
#endif
};
#if defined(jpn)
struct Struct_ov031_0224e1d0 { char unknown_0_[0x27c4]; short unknown_2784_; short unknown_2786_; unsigned char unknown_2788_; };
#else
struct Struct_ov031_0224e1d0 { char unknown_0_[0x2784]; short unknown_2784_; short unknown_2786_; unsigned char unknown_2788_; };
#endif
struct PlayerLocation { unsigned short zone_; Vector3fix16 position_; };
extern "C" TransferSettings* Zone3D_GetInstance();
void* GetData02100044_0202ae24();
void EnqueueEventTag147_021cdaa0();
extern "C" void func_ov017_021cf730(int, int);
extern "C" void func_ov017_021cfc74(unsigned char);
extern "C" void func_ov017_021d2184(unsigned char);
extern "C" Struct_ov017_021b06b0_2* func_020120a0(char*, unsigned int);
extern "C" void func_ov017_021d360c(int, unsigned char, unsigned short, Vector3fix16);
extern "C" void func_ov017_021d1a18(int, int, int, int);
extern "C" int func_0205e488(void*);
extern "C" void func_ov017_021cdc24(unsigned char, unsigned int);
extern "C" void func_ov017_021d22d4(unsigned char, unsigned short, void*);
struct Struct_ov017_021b06b0 { unsigned int unknown_0_; char unknown_4_[0x18 - 0x4]; };

inline Struct_ov017_021b06b0& inline_ov017_021b06b0() {
    static Struct_ov017_021b06b0 s;
    return s;
}

// USA: func_ov017_021b06b0
extern "C" ARM unsigned char func_ov017_021b06b0(TransferState* self) {
    GameState* state = GameState::GetInstance();
    TransferSettings* settings = Zone3D_GetInstance();
    GrottoStruct* grotto = state->GetGrottoStruct();
    void* queue = GetData02100044_0202ae24();
    if (self->phase_ == 0) {
        EnqueueEventTag147_021cdaa0();
        func_ov017_021cf730(self->player_, 1);
        EnqueueEventTag162_021cfc74(grotto->unknown_0[3]);
        func_ov017_021d2184(self->player_);
        for (int i = 0; i < 4; ++i) {
            PlayerLocation* location = GetField0x74deForValidIndex_020120a0((char*)state, i);
            if (location) func_ov017_021d360c(0, i, location->zone_, location->position_);
        }
        if (var1->unknown_2788_) func_ov017_021d1a18(1, -1, 1, 0);
        else func_ov017_021d1a18(var1->unknown_2786_, var1->unknown_2784_, 0, 0);
        arg0->unknown_25_ = 1;
    } else if (arg0->unknown_25_ == 1) {
        if (func_0205e488(var3)) {
            inline_ov017_021b06b0().unknown_0_ = 0;
            arg0->unknown_25_ = 2;
        }
    } else if (arg0->unknown_25_ == 2) {
        unsigned int var6 = inline_ov017_021b06b0().unknown_0_;
        for (int var7 = 0; var7 < 48; ++var7) {
            func_ov017_021cdc24(arg0->unknown_c_, var6);
            inline_ov017_021b06b0().unknown_0_ += 14;
            var6 = inline_ov017_021b06b0().unknown_0_;
            if (var6 >= 253) break;
        }
        arg0->unknown_25_ = 3;
    } else if (arg0->unknown_25_ == 3) {
        if (func_0205e488(var3)) {
            if (inline_ov017_021b06b0().unknown_0_ >= 253) {
                inline_ov017_021b06b0().unknown_0_ = 0;
                arg0->unknown_25_ = 4;
            } else arg0->unknown_25_ = 2;
        }
    } else if (arg0->unknown_25_ == 4) {
        unsigned int var8 = inline_ov017_021b06b0().unknown_0_;
        for (int var9 = 0; var9 < 48; ++var9) {
            func_ov017_021d22d4(arg0->unknown_c_, var8, arg0->unknown_288_);
            inline_ov017_021b06b0().unknown_0_ += 14;
            var8 = inline_ov017_021b06b0().unknown_0_;
            if (var8 >= 736) break;
        }
        arg0->unknown_25_ = 5;
    } else if (arg0->unknown_25_ == 5) {
        if (func_0205e488(var3)) {
            if (inline_ov017_021b06b0().unknown_0_ >= 736) return 11;
            arg0->unknown_25_ = 4;
        }
    }
    return arg0->unknown_a_;
}
