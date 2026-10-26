#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220b028 {
    unsigned char pad[0x10];
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned char buffer[0x40];
};

extern "C" void func_ov031_0220abc4(Struct_ov031_0220b028*, const void*);

// USA: func_ov031_0220b028
extern "C" ARM void func_ov031_0220b028(Struct_ov031_0220b028* ctx, const void* input, unsigned int arg2) {
    int i;
    unsigned int index, var2;
    index = (ctx->unknown_10_ >> 3) & 0x3f;
    if ((ctx->unknown_10_ += (arg2 << 3)) < (arg2 << 3)) ctx->unknown_14_++;
    ctx->unknown_14_ += (arg2 >> 29);
    var2 = 0x40 - index;
    if (arg2 >= var2) {
        VectorizedInvertedMemcpy(input, ctx->buffer + index, var2);
        index = 0;
        func_ov031_0220abc4(ctx, ctx->buffer);
        for (i = var2; i + 63 < arg2; i += 64) {
            func_ov031_0220abc4(ctx, (const void*)((unsigned int)input + i));
        }
    } else {
        i = 0;
    }
    VectorizedInvertedMemcpy((const void*)((unsigned int)input + i), ctx->buffer + index, arg2 - i);
}
