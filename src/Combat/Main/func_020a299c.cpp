#include <globaldefs.h>

struct Struct_ov009_0218aa28 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_020a299c_3 {
    char unknown_0_[0x10];
    int unknown_10_;
    Struct_ov009_0218aa28 unknown_14_;
    Struct_ov009_0218aa28 unknown_20_;
};

struct Struct_020a299c {
    char unknown_0_[0x10];
    Struct_ov009_0218aa28 unknown_10_;
    char unknown_1c_[0x220 - 0x1c];
    Struct_ov009_0218aa28 unknown_220_;
    char unknown_22c_[0x245 - 0x22c];
    unsigned char unknown_245_;
    char unknown_246_[0x298 - 0x246];
    Struct_020a299c_3 unknown_298_;
};

struct Struct_020a299c_2 {
    char unknown_0_[0x44];
    Struct_ov009_0218aa28 unknown_44_;
};

extern "C" void __clear(void* ptr, int size);
extern "C" int Plane_SignedDistance(struct Vec3* a, struct Sub020a299c* b);
int fix32abs(int x);
extern "C" int fix32_Divide(int arg0, int arg1);
int fix32SignedAngleDistance(int a, int b);
int fix32ReduceAngle0To2Pi(int a);
extern "C" void Vector3fix_Add(const struct Struct_ov009_0218aa28* arg0, const struct Struct_ov009_0218aa28* arg1, struct Struct_ov009_0218aa28* arg2);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
void Camera_SetTargetKeepOrbit(char*, int*);
void Camera_SetOrbitVector(void* obj, int* vec);

static inline int inline_02061c04_5(int arg0, int arg1) {
    return (int)(((long long)arg0 * arg1 + 0x800) >> 12);
}

static inline int inline_020a299c(int arg0, int arg1, int arg2) {
    int var0 = inline_02061c04_5(arg0, arg2);
    int var1 = inline_02061c04_5(arg1, 0x1000 - arg2);
    return var1 + var0;
}

// USA: func_020a299c
extern "C" ARM int func_020a299c(struct Struct_020a299c* arg0, const struct Struct_ov009_0218aa28* arg1, const struct Struct_020a299c_2* arg2) {
    if ((arg0->unknown_245_ & 4) == 0 && (arg0->unknown_245_ & 8) == 0) {
        return 0;
    }
    struct Vec3 tv = traj->v44;
    struct Vec3 out;
    __clear(&out, 0xc);
    int d = Plane_SignedDistance(&tv, (struct Sub020a299c*)&obj->sub);
    if (d > 0) {
        int t = fix32_Divide(fix32abs(d), obj->sub.b);
        if (t > 0x1000) {
            t = 0x1000;
        }
        if (arg0->unknown_245_ & 4) {
            var1.unknown_0_ = fix32ReduceAngle0To2Pi(arg0->unknown_220_.unknown_0_ + inline_02061c04_5(fix32SignedAngleDistance(arg0->unknown_220_.unknown_0_, arg0->unknown_298_.unknown_14_.unknown_0_), var3));
        } else if (arg0->unknown_245_ & 8) {
            var1.unknown_0_ = arg0->unknown_220_.unknown_0_;
        }
        out.y = Lerp(obj->sub.c.y, obj->v220.y, t);
        out.z = Lerp(obj->sub.c.z, obj->v220.z, t);
        struct Vec3 sv;
        struct Vec3 st;
        struct Vec3 tmp;
        struct Vec3 res;
        Vector3fix_Add(&obj->pos, &obj->sub.d, &tmp);
        Vector3fixMultiplyScalar((Vector3i const*)v, (int)(0x1000u - (unsigned int)t), (Vector3i*)&sv);
        Vector3fixMultiplyScalar((Vector3i const*)&tmp, t, (Vector3i*)&st);
        Vector3fix_Add(&sv, &st, &res);
        Camera_SetTargetKeepOrbit((char*)obj, (int*)&res);
        Camera_SetOrbitVector(obj, (int*)&out);
        return 1;
    }
    return 0;
}
