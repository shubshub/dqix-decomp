#include <globaldefs.h>

struct Vec3 { int x, y, z; };

extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
struct Struct_02028460_3;
extern "C" int Vector3fix_Distance(struct Struct_02028460_3* a, struct Struct_02028460_3* b);

struct Struct_0202ea4c {
    char pad0[4];
    struct Vec3 unknown_4_;
    struct Vec3 unknown_10_;
    char pad1[0x70 - 0x1c];
    int angle;
    int heightDelta;
    int distance;
};

// USA: func_0202ea4c
extern "C" ARM void func_0202ea4c(struct Struct_0202ea4c* obj) {
    struct Vec3 v;
    Vector3fix_Subtract(&obj->unknown_4_, &obj->unknown_10_, &v);
    v.y = 0;
    Vector3fix_Normalize(&v, &v);
    obj->angle = fix32ReduceAngle0To2Pi(fix32_Atan2(v.x, v.z));
    obj->heightDelta = obj->unknown_4_.y - obj->unknown_10_.y;
    obj->distance = Vector3fix_Distance((struct Struct_02028460_3*)&obj->unknown_4_, (struct Struct_02028460_3*)&obj->unknown_10_);
}
