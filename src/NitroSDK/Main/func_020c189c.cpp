#include <globaldefs.h>

struct Struct_020c189c { int x; int y; int z; };

struct FixedMtx43_189c {
    struct Struct_020c189c unknown_0_;
    struct Struct_020c189c unknown_c_;
    struct Struct_020c189c row2;
    struct Struct_020c189c unknown_24_;
};

extern "C" void MI_Copy36B(struct FixedMtx43_189c* src, struct FixedMtx43_189c* dst);

// USA: func_020c189c
extern "C" ARM void Mat4x3_ApplyTranslation(struct FixedMtx43_189c* src, struct FixedMtx43_189c* dst, int x, int y, int z) {
    if (src != dst) MI_Copy36B(src, dst);
    dst->unknown_24_.x = src->unknown_24_.x + (int)(((long long)x * src->unknown_0_.x + (long long)y * src->unknown_c_.x + (long long)z * src->row2.x) >> 12);
    dst->unknown_24_.y = src->unknown_24_.y + (int)(((long long)x * src->unknown_0_.y + (long long)y * src->unknown_c_.y + (long long)z * src->row2.y) >> 12);
    dst->unknown_24_.z = src->unknown_24_.z + (int)(((long long)x * src->unknown_0_.z + (long long)y * src->unknown_c_.z + (long long)z * src->row2.z) >> 12);
}
