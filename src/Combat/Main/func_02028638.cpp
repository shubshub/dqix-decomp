#include <globaldefs.h>

struct Struct_02028460_3 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Struct_02028460_3* a, struct Struct_02028460_3* b);

struct Struct_02028638 {
    unsigned char id;
    unsigned char pad1[3];
    short x;
    short y;
    short z;
    unsigned char pad2[6];
};

struct Struct_02028638_2 {
    unsigned char pad0[2];
    unsigned char count;
    unsigned char pad1[1];
    struct Struct_02028638* nodes;
};

// USA: func_02028638
extern "C" ARM int func_02028638(struct Struct_02028638_2* ctx, struct Struct_02028460_3* pos) {
    if (ctx->count == 0) return 0;

    struct Struct_02028638* nodes = ctx->nodes;
    struct Struct_02028460_3 v0;
    v0.x = (int)nodes[0].x << 12;
    v0.y = (int)nodes[0].y << 12;
    v0.z = (int)nodes[0].z << 12;
    int var2 = 0;
    int var3 = Vector3fix_Distance(pos, &v0);

    for (int i = 1; i < ctx->count; i++) {
        struct Struct_02028460_3 v;
        v.x = (int)nodes[i].x << 12;
        v.y = (int)nodes[i].y << 12;
        v.z = (int)nodes[i].z << 12;
        int d = Vector3fix_Distance(pos, &v);
        if (d < var3) {
            var2 = nodes[i].id;
            var3 = d;
        }
    }
    return var2;
}
