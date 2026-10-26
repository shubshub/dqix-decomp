#include <globaldefs.h>

struct Struct_ov006_02153a78 {
    short unknown_0_[2];
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
};
struct Struct_ov006_02153a78_2 {
    char unknown_0_[8];
    unsigned char** unknown_8_;
    void* unknown_c_;
    Struct_ov006_02153a78* unknown_10_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    signed char unknown_1a_;
    signed char unknown_1b_;
    signed char unknown_1c_;
};

extern "C" ARM bool func_ov006_02153a78(Struct_ov006_02153a78_2* state, int count)
{
    Struct_ov006_02153a78* var0 = state->unknown_10_;
    if (!var0) return false;
    if (var0->unknown_4_ > 0 && var0->unknown_a_0_ != 0) {
        if (state->unknown_14_ < 0) return false;
        if (state->unknown_1a_ < 0) return false;
        if (var0->unknown_a_0_ * count > state->unknown_8_[state->unknown_1a_][state->unknown_14_]) return false;
    }
    if (var0->unknown_6_ > 0 && var0->unknown_a_4_ != 0) {
        if (state->unknown_16_ < 0) return false;
        if (state->unknown_1b_ < 0) return false;
        if (var0->unknown_a_4_ * count > state->unknown_8_[state->unknown_1b_][state->unknown_16_]) return false;
    }
    if (var0->unknown_8_ > 0 && var0->unknown_b_0_ != 0) {
        if (state->unknown_18_ < 0) return false;
        if (state->unknown_1c_ < 0) return false;
        if (var0->unknown_b_0_ * count > state->unknown_8_[state->unknown_1c_][state->unknown_18_]) return false;
    }
    return true;
}
