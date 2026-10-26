#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Struct_020322c0_2 {
    int x;
    int y;
    int z;
    int w;
};

short fix32cos(int x);
short fix32sin(int x);
extern "C" void Vector3fix_Normalize(struct Vec3* v, struct Vec3* out);
extern "C" int Vector3fix_InnerProduct(struct Vec3* a, struct Vec3* b);

struct Struct_020322c0 {
    char pad0[0x24];
    struct Vec3 f24;
};

// USA: func_020322c0
extern "C" ARM int func_020322c0(const struct Struct_020322c0* self, const struct Struct_020322c0_2* other) {
    struct Vec3 a = self->f24;
    Vector3fix_Normalize(&a, &a);

    int var1 = fix32cos(other->x);
    struct Vec3 dir;
    dir.x = fix32sin(other->x);
    dir.y = 0;
    dir.z = var1;
    Vector3fix_Normalize(&dir, &dir);

    return Vector3fix_InnerProduct(&dir, &a);
}
