#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02206758 {
    char pad[0x10];
    char* unknown_10_;
    int unknown_14_;
    char* unknown_18_;
    int unknown_1c_;
};

// USA: func_ov031_02206758
extern "C" ARM int func_ov031_02206758(char* src, int maxLen, Struct_ov031_02206758* ctx) {
    int var0 = ctx->unknown_14_;
    int var1 = ctx->unknown_1c_;
    if (var0 > maxLen) {
        var0 = maxLen;
        var1 = 0;
    } else {
        int var2 = maxLen - var0;
        if (var1 > var2) {
            var1 = var2;
        }
    }
    if (var0 > 0) {
        VectorizedInvertedMemcpy(ctx->unknown_10_, src, var0);
        ctx->unknown_10_ += var0;
        ctx->unknown_14_ -= var0;
    }
    if (var1 > 0) {
        VectorizedInvertedMemcpy(ctx->unknown_18_, src + var0, var1);
        ctx->unknown_18_ += var1;
        ctx->unknown_1c_ -= var1;
    }
    return var0 + var1;
}
