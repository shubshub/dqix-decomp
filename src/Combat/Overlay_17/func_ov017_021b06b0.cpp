#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov017_021b06b0_3 {
    char pad0[0xa]; unsigned char unknown_a_; char unknown_b_;
    signed char player_; char padD[0x25 - 0xd]; unsigned char phase_;
#if defined(jpn)
    char unknown_26_[0x218 - 0x26]; void* unknown_288_;
#else
    char unknown1_26_[0x288 - 0x26]; void* unknown_288_;
#endif
};
#if defined(jpn)
struct TransferSettings { char pad0[0x27c4]; short unknown_2784_; short unknown_2786_; unsigned char unknown_2788_; };
#else
struct TransferSettings { char pad0[0x2784]; short unknown_2784_; short unknown_2786_; unsigned char unknown_2788_; };
#endif
struct PlayerLocation { unsigned short zone_; Vector3fix16 position_; };
extern "C" TransferSettings* Zone3D_GetInstance();
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_ov017_021cdaa0();
extern "C" void func_ov017_021cf730(int, int);
extern "C" void func_ov017_021cfc74(unsigned char);
extern "C" void func_ov017_021d2184(unsigned char);
extern "C" PlayerLocation* GameState_GetPlayerLocation(char*, unsigned int);
extern "C" void func_ov017_021d360c(int, unsigned char, unsigned short, Vector3fix16);
extern "C" void func_ov017_021d1a18(int, int, int, int);
extern "C" int func_0205e488(void*);
extern "C" void func_ov017_021cdc24(unsigned char, unsigned int);
extern "C" void func_ov017_021d22d4(unsigned char, unsigned short, void*);
struct Struct_ov017_021b06b0 { unsigned int unknown_0_; char unk4[0x18 - 0x4]; };

inline Struct_ov017_021b06b0& inline_ov017_021b06b0() {
    static Struct_ov017_021b06b0 s;
    return s;
}

// USA: func_ov017_021b06b0
extern "C" ARM unsigned char func_ov017_021b06b0(Struct_ov017_021b06b0_3* self) {
    GameState* state = GameState::GetInstance();
    TransferSettings* settings = Zone3D_GetInstance();
    GrottoStruct* grotto = state->GetGrottoStruct();
    void* queue = LinkMessageQueue_GetInstance();
    if (self->phase_ == 0) {
        func_ov017_021cdaa0();
        func_ov017_021cf730(self->player_, 1);
        func_ov017_021cfc74(grotto->unknown_0[3]);
        func_ov017_021d2184(self->player_);
        for (int i = 0; i < 4; ++i) {
            PlayerLocation* location = GameState_GetPlayerLocation((char*)state, i);
            if (location) func_ov017_021d360c(0, i, location->zone_, location->position_);
        }
        if (settings->unknown_2788_) func_ov017_021d1a18(1, -1, 1, 0);
        else func_ov017_021d1a18(settings->unknown_2786_, settings->unknown_2784_, 0, 0);
        self->phase_ = 1;
    } else if (self->phase_ == 1) {
        if (func_0205e488(queue)) {
            inline_ov017_021b06b0().unknown_0_ = 0;
            self->phase_ = 2;
        }
    } else if (self->phase_ == 2) {
        unsigned int offset = inline_ov017_021b06b0().unknown_0_;
        for (int i = 0; i < 48; ++i) {
            func_ov017_021cdc24(self->player_, offset);
            inline_ov017_021b06b0().unknown_0_ += 14;
            offset = inline_ov017_021b06b0().unknown_0_;
            if (offset >= 253) break;
        }
        self->phase_ = 3;
    } else if (self->phase_ == 3) {
        if (func_0205e488(queue)) {
            if (inline_ov017_021b06b0().unknown_0_ >= 253) {
                inline_ov017_021b06b0().unknown_0_ = 0;
                self->phase_ = 4;
            } else self->phase_ = 2;
        }
    } else if (self->phase_ == 4) {
        unsigned int offset = inline_ov017_021b06b0().unknown_0_;
        for (int i = 0; i < 48; ++i) {
            func_ov017_021d22d4(self->player_, offset, self->unknown_288_);
            inline_ov017_021b06b0().unknown_0_ += 14;
            offset = inline_ov017_021b06b0().unknown_0_;
            if (offset >= 736) break;
        }
        self->phase_ = 5;
    } else if (self->phase_ == 5) {
        if (func_0205e488(queue)) {
            if (inline_ov017_021b06b0().unknown_0_ >= 736) return 11;
            self->phase_ = 4;
        }
    }
    return self->unknown_a_;
}
