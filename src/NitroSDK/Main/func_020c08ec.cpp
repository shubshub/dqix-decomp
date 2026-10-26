#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_020c08ec {
    unsigned int unk0[5];
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned int index;
    unsigned char buffer[0x40];
};

typedef void (*Type_0200fd14)(Struct_020c08ec*, const void*, unsigned int);
extern Type_0200fd14 data_020f2154;

// USA: func_020c08ec
extern "C" ARM void func_020c08ec(Struct_020c08ec* ctx, const unsigned char* src, unsigned int len) {
    unsigned char* buf = ctx->buffer;
    if (len == 0) {
        return;
    }

    unsigned int old = ctx->unknown_14_;
    unsigned int var2 = old + (len << 3);
    if (var2 < old) {
        ctx->unknown_18_ = ctx->unknown_18_ + 1;
    }
    ctx->unknown_18_ = ctx->unknown_18_ + (len >> 0x1d);
    ctx->unknown_14_ = var2;

    unsigned int index = ctx->index;
    if (index != 0) {
        if (index + len >= 0x40) {
            unsigned int fill = 0x40 - index;
            VectorizedInvertedMemcpy(src, buf + index, fill);
            len -= fill;
            src += fill;
            data_020f2154(ctx, buf, 0x40);
            ctx->index = 0;
        } else {
            VectorizedInvertedMemcpy(src, buf + index, len);
            ctx->index = ctx->index + len;
            return;
        }
    }

    if (len >= 0x40) {
        int var5 = len & ~0x3f;
        len -= var5;
        if (((unsigned int)src & 0x3) == 0) {
            data_020f2154(ctx, src, var5);
            src += var5;
        } else {
            do {
                VectorizedInvertedMemcpy(src, buf, 0x40);
                src += 0x40;
                data_020f2154(ctx, buf, 0x40);
                var5 -= 0x40;
            } while (var5 > 0);
        }
    }

    ctx->index = len;
    if (len == 0) {
        return;
    }
    VectorizedInvertedMemcpy(src, buf, len);
}
