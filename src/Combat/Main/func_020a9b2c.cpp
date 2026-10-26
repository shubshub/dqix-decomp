#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance();
extern "C" void VectorizedInvertedMemcpy(void* dst, const void* src, unsigned int size);

struct Struct_020a9b2c {
    unsigned char pad000[0xd98];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned short d;
    unsigned char e;
};

struct Struct_020a9b2c_2 {
    unsigned char pad000[0xc00];
    Struct_020a9b2c params;
};

struct Struct_020a9b2c_3 {
    unsigned char pad000[0x198];
    Struct_020a9b2c_2 unknown_198_;
};

struct Struct_020a9b2c_4 {
    unsigned char pad000[0xb34];
    unsigned int f34;
    unsigned int unknown_b38_;
    unsigned int f3c;
    unsigned char unknown_b40_[0x4];
    unsigned int unknown_b44_;
    unsigned char unknown_b48_[0x19];
    unsigned char unknown_b61_;
};

struct Struct_020a9b2c_5 {
    unsigned char pad000[0x1000];
    Struct_020a9b2c_4 tail;
};

struct Battle020a9b2c {
#if defined(jpn)
    unsigned char pad000[0x860];
#else
    unsigned char pad000[0x840];
#endif
    Struct_020a9b2c_5 block;
};

// USA: func_020a9b2c
// JPN: func_020a9b2c
extern "C" ARM int func_020a9b2c(Struct_020a9b2c_3* ctx) {
    Struct_020a9b2c_2* var0 = &ctx->unknown_198_;
    Struct_020a9b2c* params = &var0->params;
    Battle020a9b2c* battle = static_cast<Battle020a9b2c*>(Zone3D_GetInstance());
    Struct_020a9b2c_5* block = &battle->block;
    block->tail.unknown_b38_ = params->a;
    block->tail.f34 = params->b;
    block->tail.unknown_b44_ = params->c;
    block->tail.f3c = params->d & 0xff;
    block->tail.unknown_b61_ = params->e != 0;
    VectorizedInvertedMemcpy(ctx, block, 0x1b30);
    return 1;
}
