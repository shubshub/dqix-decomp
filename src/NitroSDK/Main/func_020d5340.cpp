#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" int func_020d424c(int a, int b, int c, int d);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d4168(void* a, unsigned int b);

struct Struct_02101680 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned char unknown_a_[6];
    unsigned short type;
    unsigned short unknown_12_;
    unsigned char tail[0x20];
    unsigned short field0x34;
};

struct Struct_020d5340 {
    unsigned short tag;
    unsigned short field2;
    int field4;
    unsigned short field8;
    unsigned short fielda;
    unsigned char unknown_c_[6];
    unsigned short unknown_12_;
    unsigned short unknown_14_;
    unsigned char tail[0x20];
    unsigned short unknown_36_;
    unsigned char pad[4];
};


// USA: func_020d5340
extern "C" ARM int func_020d5340(int a0, struct Struct_02101680* ctx) {
    int r = func_020d424c(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (ctx == NULL) {
        return 6;
    }
    if (ctx->field0 == 0) {
        return 6;
    }
    if (ctx->field4 > 0x400) {
        return 6;
    }
    if (ctx->unknown_12_ > 0x20) {
        return 6;
    }
    if (ctx->type != 0 && ctx->type != 1 && ctx->type != 2 && ctx->type != 3) {
        return 6;
    }
    if ((unsigned short)(ctx->type + 0xfffe) <= 1) {
        if (ctx->field0x34 > 0x20) {
            return 6;
        }
    }
    func_020d404c(0x26, a0);
    struct Struct_020d5340 buf;
    buf.tag = 0x26;
    buf.field2 = ctx->field6;
    buf.field4 = ctx->field0;
    buf.field8 = ctx->field4;
    buf.fielda = ctx->field8;
    VectorizedInvertedMemcpy(ctx->unknown_a_, buf.unknown_c_, 6);
    buf.unknown_12_ = ctx->type;
    buf.unknown_36_ = ctx->field0x34;
    buf.unknown_14_ = ctx->unknown_12_;
    VectorizedInvertedMemcpy(ctx->tail, buf.tail, 0x20);
    r = func_020d4168(&buf, 0x3c);
    return (r == 0) ? 2 : r;
}
