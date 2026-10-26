#include <globaldefs.h>

struct Struct_02028524_4 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
};

struct Struct_02028524 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_02028524_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_02028524_4 unknown_4_;
    unsigned char unknown_a_[6];
};

struct Struct_02028524_3 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    struct Struct_02028524_2* unknown_4_;
};

struct Struct_02028524_5;
extern "C" void func_0202861c(Struct_02028524_5*, Struct_02028524_5*);
extern "C" int abs(int arg0);

// Main, originally func_02028524 (USA 0x02028524, EUR 0x02028534, JPN 0x02027d90)
extern "C" ARM int NodeGraph_FindClosestNodeManhattan(struct SearchCtx_02028524* ctx, struct Vec3s32_02028524* pos) {
    if (ctx->count == 0) return 0;

    int var0 = arg1->unknown_0_ << 4;
    int var1 = arg1->unknown_4_ << 4;
    int var2 = arg1->unknown_8_ << 4;
    struct Struct_02028524_2* var3 = arg0->unknown_4_;

    int var4 = 0;
    struct Struct_02028524_4 var5;
    func_0202861c((Struct_02028524_5*)&var5, (Struct_02028524_5*)&var3[0].unknown_4_);
    int var6 = abs(var5.unknown_0_ - (var0 >> 16)) + abs(var5.unknown_2_ - (var1 >> 16)) + abs(var5.unknown_4_ - (var2 >> 16));

    for (int var7 = 1; var7 < arg0->unknown_2_; var7++) {
        struct Struct_02028524_4 var8;
        func_0202861c((Struct_02028524_5*)&var8, (Struct_02028524_5*)&var3[var7].unknown_4_);
        int var9 = abs(var8.unknown_0_ - (var0 >> 16)) + abs(var8.unknown_2_ - (var1 >> 16)) + abs(var8.unknown_4_ - (var2 >> 16));
        if (var9 < var6) {
            var4 = var7;
            var6 = var9;
        }
    }
    return var4;
}
