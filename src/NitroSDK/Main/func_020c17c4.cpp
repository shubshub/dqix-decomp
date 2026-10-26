#include <globaldefs.h>

struct Struct_020c17c4_2 {
    int x;
    int y;
    int z;
};

struct Struct_020c17c4 {
    struct Struct_020c17c4_2 unknown_0_;
    struct Struct_020c17c4_2 unknown_c_;
    struct Struct_020c17c4_2 row2;
};

// USA: func_020c17c4
extern "C" ARM void Mat3x3_ApplyToVector(struct Struct_020c17c4_2* v, struct Struct_020c17c4* m, struct Struct_020c17c4_2* out) {
    int var0 = v->y;
    int var1 = v->x;
    int var2 = v->z;
    out->x = (int)(((long long)var1 * m->unknown_0_.x + (long long)var0 * m->unknown_c_.x + (long long)var2 * m->row2.x) >> 12);
    out->y = (int)(((long long)var1 * m->unknown_0_.y + (long long)var0 * m->unknown_c_.y + (long long)var2 * m->row2.y) >> 12);
    out->z = (int)(((long long)var1 * m->unknown_0_.z + (long long)var0 * m->unknown_c_.z + (long long)var2 * m->row2.z) >> 12);
}
