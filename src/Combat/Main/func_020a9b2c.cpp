#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance();
extern "C" void VectorizedInvertedMemcpy(void* dst, const void* src, unsigned int size);

struct Struct_020a9b2c {
    unsigned char unknown_0_[0xd98];
    unsigned int unknown_d98_;
    unsigned int unknown_d9c_;
    unsigned int unknown_da0_;
    unsigned short unknown_da4_;
    unsigned char unknown_da6_;
};

struct Struct_020a9b2c_2 {
    unsigned char unknown_0_[0xc00];
    Struct_020a9b2c unknown_c00_;
};

struct Struct_020a9b2c_3 {
    unsigned char unknown_0_[0x198];
    Struct_020a9b2c_2 unknown_198_;
};

struct Struct_020a9b2c_4 {
    unsigned char unknown_0_[0xb34];
    unsigned int unknown_b34_;
    unsigned int unknown_b38_;
    unsigned int unknown_b3c_;
    unsigned char unknown_b40_[0x4];
    unsigned int unknown_b44_;
    unsigned char unknown_b48_[0x19];
    unsigned char unknown_b61_;
};

struct Struct_020a9b2c_5 {
    unsigned char unknown_0_[0x1000];
    Struct_020a9b2c_4 unknown_1000_;
};

struct Struct_020a9b2c_6 {
#if defined(jpn)
    unsigned char unknown_0_[0x860];
#else
    unsigned char unknown1_0_[0x840];
#endif
    Struct_020a9b2c_5 unknown_840_;
};

// USA: func_020a9b2c
// JPN: func_020a9b2c
extern "C" ARM int func_020a9b2c(Ctx020a9b2c* ctx) {
    Mid020a9b2c* mid = &ctx->mid;
    Params020a9b2c* params = &mid->params;
    Battle020a9b2c* battle = static_cast<Battle020a9b2c*>(Zone3D_GetInstance());
    Block020a9b2c* block = &battle->block;
    block->tail.f38 = params->a;
    block->tail.f34 = params->b;
    block->tail.f44 = params->c;
    block->tail.f3c = params->d & 0xff;
    block->tail.f61 = params->e != 0;
    VectorizedInvertedMemcpy(ctx, block, 0x1b30);
    return 1;
}
