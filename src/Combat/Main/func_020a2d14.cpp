#include <globaldefs.h>

#include "Graphics/Vector.h"
#include "Input/Input.h"

struct Struct_0202e6a8;
struct Struct_0202ea4c;
struct Struct_ov009_0218aa28;

struct Struct_0202e6c0 {
    int unknown_0_;
    Vector3fix unknown_4_;
    Vector3fix unknown_10_;
    char unknown_1c_[0x70 - 0x1C];
    fix32_t unknown_70_;
    fix32_t unknown_74_;
    fix32_t unknown_78_;
    char unknown_7c_[0x218 - 0x7C];
    int unknown_218_;
};

void AddWrappedField0x70_0202e784(struct GlobalObj0202e6a8* obj, int val);
int Camera_GetOrbitDistance(void* obj);
int GetField0x74_0202e7f8(void* obj);
void Camera_SetOrbitHeight(struct CamState0202e6c0* obj, int value);
void SubtractVec3Fields0202e9f4(void* obj, struct Vec3* v);
void ComputeAngleHeightDistance0202ea4c(struct Obj0202ea4c* obj);
int AddAndClampMin0202e858(void* obj, int n);
void Camera_SetTargetKeepOrbit(char* obj, int* src);

static inline fix32_t inline_02061c04_5(fix32_t arg0, fix32_t arg1) {
    return (fix32_t)(((int64_t)arg0 * arg1 + 0x800) >> 12);
}

static inline void inline_020a2d14(struct Struct_0202e6c0* arg0, const Vector3fix* arg1, const Vector3fix* arg2) {
    arg0->unknown_10_ = *arg1;
    func_0202ea4c((struct Struct_0202ea4c*)arg0);
    arg0->unknown_4_ = *arg2;
}

// USA: func_020a2d14
extern "C" ARM void func_020a2d14(struct Struct_0202e6c0* arg0) {
    int var0;
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    int var6;
    int var7;
    int var8;
    int var9;
    int var10;
    float var11;
    float var12;
    int var13;
    fix32_t var14;

    if (arg0->unknown_218_ == 0) {
        return;
    }

    Vector3fix var15 = arg0->unknown_10_;
    var0 = g_keyManager.TestKeysHeld(1);
    var1 = g_keyManager.TestKeysHeld(2);
    var2 = g_keyManager.TestKeysHeld(0x400);
    var3 = g_keyManager.TestKeysHeld(0x800);
    var4 = g_keyManager.TestKeysHeld(0x200);
    var5 = g_keyManager.TestKeysHeld(0x100);
    var6 = g_keyManager.TestKeysHeld(0x40);
    var7 = g_keyManager.TestKeysHeld(0x80);
    var8 = g_keyManager.TestKeysHeld(0x20);
    var9 = g_keyManager.TestKeysHeld(0x10);
    var10 = g_keyManager.TestKeysHeld(8);
    var11 = 1.0f;
    if (var10) {
        var11 = 0.1f;
    }

    if (arg0->unknown_218_ == 2 && var2 == 0 && var3 == 0) {
        return;
    }

    if ((arg0->unknown_218_ == 1 && var5 == 0 && arg0->unknown_218_ == 1 && var4 == 0) || (arg0->unknown_218_ == 2 && var3 == 0)) {
        if (var8) {
            func_0202e784((struct Struct_0202e6a8*)arg0, -(int)(4096.0f * (0.05f * var11)));
        }
        if (var9) {
            func_0202e784((struct Struct_0202e6a8*)arg0, (int)(4096.0f * (0.05f * var11)));
        }
        if (pressUp) {
            fix32_t dist = Camera_GetOrbitDistance(cam);
            fix32_t height = GetField0x74_0202e7f8(cam);
            fix32_t heightSq = FxMul(height, height);
            fix32_t distSq = FxMul(dist, dist);
            fix32_t horiz = fix32_Sqrt(distSq - heightSq);
            Vector3fix v = {horiz, height, 0};
            Matrix4x3 m = RotationMatrixZ((int)(178.72223f * speed));
            Mat4x3_ApplyToVector(&v, &m, &v);
            Camera_SetOrbitHeight(cam, v.y);
        }
        if (pressDown) {
            fix32_t dist = Camera_GetOrbitDistance(cam);
            fix32_t height = GetField0x74_0202e7f8(cam);
            fix32_t heightSq = FxMul(height, height);
            fix32_t distSq = FxMul(dist, dist);
            fix32_t horiz = fix32_Sqrt(distSq - heightSq);
            Vector3fix v = {horiz, height, 0};
            Matrix4x3 m = RotationMatrixZ(fix32ReduceAngle0To2Pi((int)(-178.72223f * speed)));
            Mat4x3_ApplyToVector(&v, &m, &v);
            Camera_SetOrbitHeight(cam, v.y);
        }
    }

    scale = (float)Camera_GetOrbitDistance(cam) / 10.0f / 4096.0f;
    moved = 0;

    if ((arg0->unknown_218_ == 1 && var5) || (arg0->unknown_218_ == 2 && var3)) {
        Vector3fix var30;
        func_0202e9f4(arg0, (struct Struct_ov009_0218aa28*)&var30);
        var30.y = 0;
        Vector3fix_Normalize(&var30, &var30);
        Vector3fixMultiplyScalar(&var30, (int)(4096.0f * (0.2f * var11 * var12)), &var30);
        var14 = 0;
        if (var6 && var8) {
            var14 = 0xC91;
            var13 = 1;
        } else if (var6 && var9) {
            var14 = 0x57F7;
            var13 = 1;
        } else if (var7 && var8) {
            var14 = 0x25B3;
            var13 = 1;
        } else if (var7 && var9) {
            var14 = 0x3ED5;
            var13 = 1;
        } else if (var6) {
            var13 = 1;
        } else if (var7) {
            var14 = 0x3244;
            var13 = 1;
        } else if (var8) {
            var14 = 0x1922;
            var13 = 1;
        } else if (var9) {
            var14 = 0x4B66;
            var13 = 1;
        }
        if (var13) {
            Matrix4x3 var31 = RotationMatrixY(var14);
            Mat4x3_ApplyToVector(&var30, &var31, &var30);
            Vector3fix_Add(&var15, &var30, &var15);
        }
    }

    if (arg0->unknown_218_ == 1 && var4) {
        Vector3fix var32;
        Vector3fix var33 = var15;
        int var34;
        fix32_t var35;
        func_0202e9f4(arg0, (struct Struct_ov009_0218aa28*)&var32);
        var32.y = 0;
        Vector3fix_Normalize(&var32, &var32);
        Vector3fixMultiplyScalar(&var32, (int)(4096.0f * (0.2f * var11 * var12)), &var32);
        var14 = 0;
        if (var6 && var8) {
            var14 = 0xC91;
            var13 = 1;
        } else if (var6 && var9) {
            var14 = 0x57F7;
            var13 = 1;
        } else if (var7 && var8) {
            var14 = 0x25B3;
            var13 = 1;
        } else if (var7 && var9) {
            var14 = 0x3ED5;
            var13 = 1;
        } else if (var6) {
            var13 = 1;
        } else if (var7) {
            var14 = 0x3244;
            var13 = 1;
        } else if (var8) {
            var14 = 0x1922;
            var13 = 1;
        } else if (var9) {
            var14 = 0x4B66;
            var13 = 1;
        }
        if (var13) {
            Matrix4x3 var36 = RotationMatrixY(var14);
            Mat4x3_ApplyToVector(&var32, &var36, &var32);
            Vector3fix_Add(&var33, &var32, &var33);
            inline_020a2d14(arg0, &var33, &arg0->unknown_4_);
            return;
        }
        var34 = 0;
        var35 = (int)(4096.0f * (0.2f * var11 * var12));
        if (var2) {
            var33.y += var35;
            var34 = 1;
        }
        if (var3) {
            var33.y -= var35;
            var34 = 1;
        }
        if (var34) {
            inline_020a2d14(arg0, &var33, &arg0->unknown_4_);
            return;
        }
    }

    if (arg0->unknown_218_ == 1) {
        fix32_t var37 = (int)(4096.0f * (0.3f * var11 * var12));
        if (var0) {
            func_0202e858(arg0, var37);
        }
        if (var1) {
            func_0202e858(arg0, -var37);
        }
    }

    if (arg0->unknown_218_ == 1) {
        fix32_t var38 = (int)(4096.0f * (0.2f * var11 * var12));
        if (var2) {
            var15.y += var38;
        }
        if (var3) {
            var15.y -= var38;
        }
    }

    if (arg0->unknown_218_ == 2 && var13 == 0) {
        fix32_t var39 = (int)(4096.0f * (0.2f * var11 * var12));
        fix32_t var40 = (int)(4096.0f * (0.3f * var11 * var12));
        if (var3 && var5) {
            var15.y += var39;
        } else if (var3 && var4) {
            var15.y -= var39;
        } else if (var5) {
            func_0202e858(arg0, var40);
        } else if (var4) {
            func_0202e858(arg0, -var40);
        }
    }

    Camera_SetTargetKeepOrbit((char*)cam, (int*)&pos);
}
