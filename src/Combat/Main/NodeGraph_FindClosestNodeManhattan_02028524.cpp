#include <globaldefs.h>

struct Struct_02028524_4 {
    short x;
    short y;
    short z;
};

struct Vec3s32_02028524 {
    int x;
    int y;
    int z;
};

struct Struct_02028524_2 {
    unsigned char id;
    unsigned char pad1[3];
    struct Struct_02028524_4 vec;
    unsigned char pad2[6];
};

struct SearchCtx_02028524 {
    unsigned char pad0[2];
    unsigned char count;
    unsigned char pad1;
    struct Struct_02028524_2* nodes;
};

struct Struct_02028524_5;
extern "C" void func_0202861c(Struct_02028524_5*, Struct_02028524_5*);
extern "C" int abs(int x);

// Main, originally func_02028524 (USA 0x02028524, EUR 0x02028534, JPN 0x02027d90)
extern "C" ARM int NodeGraph_FindClosestNodeManhattan(struct SearchCtx_02028524* ctx, struct Vec3s32_02028524* pos) {
    if (ctx->count == 0) return 0;

    int var0 = pos->x << 4;
    int var1 = pos->y << 4;
    int sz = pos->z << 4;
    struct Struct_02028524_2* nodes = ctx->nodes;

    int var4 = 0;
    struct Struct_02028524_4 v0;
    func_0202861c((Struct_02028524_5*)&v0, (Struct_02028524_5*)&nodes[0].vec);
    int var6 = abs(v0.x - (var0 >> 16)) + abs(v0.y - (var1 >> 16)) + abs(v0.z - (sz >> 16));

    for (int i = 1; i < ctx->count; i++) {
        struct Struct_02028524_4 v;
        func_0202861c((Struct_02028524_5*)&v, (Struct_02028524_5*)&nodes[i].vec);
        int d = abs(v.x - (var0 >> 16)) + abs(v.y - (var1 >> 16)) + abs(v.z - (sz >> 16));
        if (d < var6) {
            var4 = i;
            var6 = d;
        }
    }
    return var4;
}
