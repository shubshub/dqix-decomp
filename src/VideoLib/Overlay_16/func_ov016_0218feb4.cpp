#include <globaldefs.h>

struct Struct_ov016_0218feb4 {
    int unknown_0_;
    int unknown_4_;
};

extern const short data_ov016_0219cef0[];
extern const signed char data_ov016_0219cee0[];

// USA: func_ov016_0218feb4
extern "C" ARM void func_ov016_0218feb4(Struct_ov016_0218feb4* state, unsigned char* input, int length, unsigned int* output) {
    int i = 0;
    if (length <= 0) return;
    do {
        int nibble = input[i];
        int first;
        int var3 = data_ov016_0219cef0[state->unknown_4_];
        state->unknown_4_ += data_ov016_0219cee0[nibble & 7];
        if (state->unknown_4_ < 0) state->unknown_4_ = 0;
        if (state->unknown_4_ > 88) state->unknown_4_ = 88;
        int var4 = var3 >> 3;
        if (nibble & 4) var4 += var3;
        if (nibble & 2) var4 += var3 >> 1;
        if (nibble & 1) var4 += var3 >> 2;
        if (nibble & 8) state->unknown_0_ -= var4;
        else state->unknown_0_ += var4;
        if (state->unknown_0_ < -0x8000) state->unknown_0_ = -0x8000;
        if (state->unknown_0_ > 0x7fff) state->unknown_0_ = 0x7fff;

        nibble >>= 4;
        first = state->unknown_0_;
        int var5 = data_ov016_0219cef0[state->unknown_4_];
        state->unknown_4_ += data_ov016_0219cee0[nibble & 7];
        if (state->unknown_4_ < 0) state->unknown_4_ = 0;
        if (state->unknown_4_ > 88) state->unknown_4_ = 88;
        int var6 = var5 >> 3;
        if (nibble & 4) var6 += var5;
        if (nibble & 2) var6 += var5 >> 1;
        if (nibble & 1) var6 += var5 >> 2;
        if (nibble & 8) state->unknown_0_ -= var6;
        else state->unknown_0_ += var6;
        if (state->unknown_0_ < -0x8000) state->unknown_0_ = -0x8000;
        if (state->unknown_0_ > 0x7fff) state->unknown_0_ = 0x7fff;

        *output++ = (unsigned short)first | (state->unknown_0_ << 16);
        i++;
    } while (i < length);
}
