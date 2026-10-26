#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Sub020a299c {
    char pad0[0x10];
    int b;
    Vec3 c;
    Vec3 d;
};

struct Struct_020a299c {
    char pad0[0x10];
    Vec3 pos;
    char pad1[0x220 - 0x1c];
    Vec3 unknown_220_;
    char pad2[0x245 - 0x22c];
    unsigned char flags;
    char pad3[0x298 - 0x246];
    Sub020a299c sub;
};

struct Struct_020a299c_2 {
    char pad0[0x44];
    Vec3 v44;
};

extern "C" void __clear(void* ptr, int size);
extern "C" int Plane_SignedDistance(struct Vec3* a, struct Sub020a299c* b);
int fix32abs(int x);
extern "C" int fix32_Divide(int num, int arg1);
int fix32SignedAngleDistance(int a, int b);
int fix32ReduceAngle0To2Pi(int a);
extern "C" void Vector3fix_Add(const struct Vec3* a, const struct Vec3* b, struct Vec3* out);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
extern "C" void Camera_SetTargetKeepOrbit(char*, int*);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

static inline int FxMul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

static inline int inline_020a299c(int a, int b, int t) {
    int x = FxMul(a, t);
    int y = FxMul(b, 0x1000 - t);
    return y + x;
}

// USA: func_020a299c
extern "C" ARM int func_020a299c(struct Struct_020a299c* obj, const struct Vec3* v, const struct Struct_020a299c_2* arg2) {
    if ((obj->flags & 4) == 0 && (obj->flags & 8) == 0) {
        return 0;
    }
    struct Vec3 tv = arg2->v44;
    struct Vec3 out;
    __clear(&out, 0xc);
    int d = Plane_SignedDistance(&tv, (struct Sub020a299c*)&obj->sub);
    if (d > 0) {
        int t = fix32_Divide(fix32abs(d), obj->sub.b);
        if (t > 0x1000) {
            t = 0x1000;
        }
        if (obj->flags & 4) {
            out.x = fix32ReduceAngle0To2Pi(obj->unknown_220_.x + FxMul(fix32SignedAngleDistance(obj->unknown_220_.x, obj->sub.c.x), t));
        } else if (obj->flags & 8) {
            out.x = obj->unknown_220_.x;
        }
        out.y = inline_020a299c(obj->sub.c.y, obj->unknown_220_.y, t);
        out.z = inline_020a299c(obj->sub.c.z, obj->unknown_220_.z, t);
        struct Vec3 var4;
        struct Vec3 st;
        struct Vec3 tmp;
        struct Vec3 res;
        Vector3fix_Add(&obj->pos, &obj->sub.d, &tmp);
        Vector3fixMultiplyScalar((Vector3i const*)v, (int)(0x1000u - (unsigned int)t), (Vector3i*)&var4);
        Vector3fixMultiplyScalar((Vector3i const*)&tmp, t, (Vector3i*)&st);
        Vector3fix_Add(&var4, &st, &res);
        Camera_SetTargetKeepOrbit((char*)obj, (int*)&res);
        Camera_SetOrbitVector(obj, (int*)&out);
        return 1;
    }
    return 0;
}
