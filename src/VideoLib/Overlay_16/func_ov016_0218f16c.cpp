#include <globaldefs.h>

struct Struct_ov016_0218f16c_2 {
    const unsigned char* unknown_0_;
    const unsigned char* unknown_4_;
    unsigned short* dst;
    unsigned int pitch;
    int width;
    int height;
    const unsigned char* field_18;
};
struct Struct_ov016_0218f16c {
    char unknown_0_[0x10];
    unsigned int width;
    unsigned int height;
    char unknown_18_[0x24];
    Struct_ov016_0218f16c_2 target;
    char unknown_58_[4];
    const unsigned char** framesY;
    const unsigned char** unknown_60_;
    unsigned int* unknown_64_;
    unsigned char* unknown_68_;
    unsigned char* unknown_6c_;
    char unknown_70_[0x2c];
    unsigned int unknown_9c_;
    unsigned int available;
#if !defined(jpn)
    int unknown_a4_;
#endif
    unsigned int unknown_a8_;
    unsigned int idx[6];
    unsigned int frame;
};
struct Struct_ov016_0218f16c_3 {
    const unsigned char* unknown_0_;
    const unsigned char* unknown_4_;
    unsigned char* unknown_8_;
    unsigned char* unknown_c_;
    int width;
    int height;
    unsigned int unknown_18_;
    void* unknown_1c_;
    int mode;
};
extern "C" void* func_ov016_0218bc8c(unsigned int);
extern "C" void* func_ov016_0218fe30();
extern "C" void func_ov016_0219c514_unk(Struct_ov016_0218f16c_3*);
extern "C" void func_ov016_0218f6b8(Struct_ov016_0218f16c_2*);

// USA: func_ov016_0218f16c
extern "C" ARM int func_ov016_0218f16c(Struct_ov016_0218f16c* state, unsigned short* dst, int pitch, int mode) {
    if (state->unknown_9c_ >= state->available) return 0;
    if (mode) {
        if (!state->unknown_68_) {
            state->unknown_68_ = (unsigned char*)func_ov016_0218bc8c(state->height << 8);
            if (!state->unknown_68_) return 0;
        }
        if (!state->unknown_6c_) {
            state->unknown_6c_ = (unsigned char*)func_ov016_0218bc8c((state->height >> 1) << 8);
            if (!state->unknown_6c_) return 0;
        }
        Struct_ov016_0218f16c_3 var0;
        var0.unknown_0_ = state->framesY[state->frame];
        var0.unknown_4_ = state->unknown_60_[state->frame];
        var0.unknown_8_ = state->unknown_68_;
        var0.unknown_c_ = state->unknown_6c_;
        var0.width = state->width;
        var0.height = state->height;
        var0.unknown_18_ = state->unknown_64_[state->frame];
        var0.unknown_1c_ = func_ov016_0218fe30();
        if (mode == 2) var0.mode = 0;
        else var0.mode = 1;
        func_ov016_0219c514_unk(&var0);
        state->target.unknown_0_ = state->unknown_68_;
        state->target.unknown_4_ = state->unknown_6c_;
    } else {
        state->target.unknown_0_ = state->framesY[state->frame];
        state->target.unknown_4_ = state->unknown_60_[state->frame];
    }
    state->target.dst = dst;
    state->target.pitch = pitch << 1;
    func_ov016_0218f6b8(&state->target);
    state->unknown_9c_++;
    state->frame++;
    if (state->frame == state->unknown_a8_) state->frame = 0;
    return 1;
}
