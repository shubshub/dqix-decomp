#include <globaldefs.h>

struct Struct_0202e5d8_2 {
    int x;
    int y;
    int z;
};

struct Struct_0202e5d8_3 {
    struct Struct_0202e5d8_2 unknown_0_;
    struct Struct_0202e5d8_2 unknown_c_;
    struct Struct_0202e5d8_2 row2;
    struct Struct_0202e5d8_2 unknown_24_;
};

// USA: func_020c2034
extern "C" ARM void Mat4x3_ApplyToVector(struct Struct_0202e5d8_2* v, struct Struct_0202e5d8_3* m, struct Struct_0202e5d8_2* out) {
    int var0 = v->y;
    int var1 = v->x;
    int var2 = v->z;
    out->x = (int)(((long long)var1 * m->unknown_0_.x + (long long)var0 * m->unknown_c_.x + (long long)var2 * m->row2.x) >> 12);
    out->x += m->unknown_24_.x;
    out->y = (int)(((long long)var1 * m->unknown_0_.y + (long long)var0 * m->unknown_c_.y + (long long)var2 * m->row2.y) >> 12);
    out->y += m->unknown_24_.y;
    out->z = (int)(((long long)var1 * m->unknown_0_.z + (long long)var0 * m->unknown_c_.z + (long long)var2 * m->row2.z) >> 12);
    out->z += m->unknown_24_.z;
}
