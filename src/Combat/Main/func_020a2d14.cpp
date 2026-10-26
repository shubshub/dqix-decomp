#include <globaldefs.h>

#include "Graphics/Vector.h"
#include "Input/Input.h"

struct GlobalObj0202e6a8;
struct Struct_0202ea4c;
struct Vec3;

struct CamState0202e6c0 {
    int unk0;
    Vector3fix target;
    Vector3fix position;
    char unknown_1c_[0x70 - 0x1C];
    fix32_t yaw;
    fix32_t height;
    fix32_t distance;
    char unknown_7c_[0x218 - 0x7C];
    int mode;
};

extern "C" void func_0202e784(struct GlobalObj0202e6a8* obj, int val);
extern "C" int Camera_GetOrbitDistance(void* obj);
extern "C" int func_0202e7f8(void* obj);
extern "C" void Camera_SetOrbitHeight(struct CamState0202e6c0* obj, int value);
extern "C" void func_0202e9f4(void* obj, struct Vec3* v);
extern "C" void func_0202ea4c(struct Struct_0202ea4c* obj);
extern "C" int func_0202e858(void* obj, int n);
extern "C" void Camera_SetTargetKeepOrbit(char* obj, int* src);

static inline fix32_t FxMul(fix32_t a, fix32_t b) {
    return (fix32_t)(((int64_t)a * b + 0x800) >> 12);
}

static inline void inline_020a2d14(struct CamState0202e6c0* cam, const Vector3fix* position, const Vector3fix* target) {
    cam->position = *position;
    func_0202ea4c((struct Struct_0202ea4c*)cam);
    cam->target = *target;
}

// USA: func_020a2d14
extern "C" ARM void func_020a2d14(struct CamState0202e6c0* cam) {
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
    float speed;
    float scale;
    int moved;
    fix32_t angle;

    if (cam->mode == 0) {
        return;
    }

    Vector3fix pos = cam->position;
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
    speed = 1.0f;
    if (var10) {
        speed = 0.1f;
    }

    if (cam->mode == 2 && var2 == 0 && var3 == 0) {
        return;
    }

    if ((cam->mode == 1 && var5 == 0 && cam->mode == 1 && var4 == 0) || (cam->mode == 2 && var3 == 0)) {
        if (var8) {
            func_0202e784((struct GlobalObj0202e6a8*)cam, -(int)(4096.0f * (0.05f * speed)));
        }
        if (var9) {
            func_0202e784((struct GlobalObj0202e6a8*)cam, (int)(4096.0f * (0.05f * speed)));
        }
        if (var6) {
            fix32_t dist = Camera_GetOrbitDistance(cam);
            fix32_t height = func_0202e7f8(cam);
            fix32_t var18 = FxMul(height, height);
            fix32_t var19 = FxMul(dist, dist);
            fix32_t var20 = fix32_Sqrt(var19 - var18);
            Vector3fix v = {var20, height, 0};
            Matrix4x3 m = RotationMatrixZ((int)(178.72223f * speed));
            Mat4x3_ApplyToVector(&v, &m, &v);
            Camera_SetOrbitHeight(cam, v.y);
        }
        if (var7) {
            fix32_t dist = Camera_GetOrbitDistance(cam);
            fix32_t height = func_0202e7f8(cam);
            fix32_t var25 = FxMul(height, height);
            fix32_t var26 = FxMul(dist, dist);
            fix32_t var27 = fix32_Sqrt(var26 - var25);
            Vector3fix v = {var27, height, 0};
            Matrix4x3 m = RotationMatrixZ(fix32ReduceAngle0To2Pi((int)(-178.72223f * speed)));
            Mat4x3_ApplyToVector(&v, &m, &v);
            Camera_SetOrbitHeight(cam, v.y);
        }
    }

    scale = (float)Camera_GetOrbitDistance(cam) / 10.0f / 4096.0f;
    moved = 0;

    if ((cam->mode == 1 && var5) || (cam->mode == 2 && var3)) {
        Vector3fix dir;
        func_0202e9f4(cam, (struct Vec3*)&dir);
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, (int)(4096.0f * (0.2f * speed * scale)), &dir);
        angle = 0;
        if (var6 && var8) {
            angle = 0xC91;
            moved = 1;
        } else if (var6 && var9) {
            angle = 0x57F7;
            moved = 1;
        } else if (var7 && var8) {
            angle = 0x25B3;
            moved = 1;
        } else if (var7 && var9) {
            angle = 0x3ED5;
            moved = 1;
        } else if (var6) {
            moved = 1;
        } else if (var7) {
            angle = 0x3244;
            moved = 1;
        } else if (var8) {
            angle = 0x1922;
            moved = 1;
        } else if (var9) {
            angle = 0x4B66;
            moved = 1;
        }
        if (moved) {
            Matrix4x3 m = RotationMatrixY(angle);
            Mat4x3_ApplyToVector(&dir, &m, &dir);
            Vector3fix_Add(&pos, &dir, &pos);
        }
    }

    if (cam->mode == 1 && var4) {
        Vector3fix dir;
        Vector3fix var33 = pos;
        int changed;
        fix32_t step;
        func_0202e9f4(cam, (struct Vec3*)&dir);
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, (int)(4096.0f * (0.2f * speed * scale)), &dir);
        angle = 0;
        if (var6 && var8) {
            angle = 0xC91;
            moved = 1;
        } else if (var6 && var9) {
            angle = 0x57F7;
            moved = 1;
        } else if (var7 && var8) {
            angle = 0x25B3;
            moved = 1;
        } else if (var7 && var9) {
            angle = 0x3ED5;
            moved = 1;
        } else if (var6) {
            moved = 1;
        } else if (var7) {
            angle = 0x3244;
            moved = 1;
        } else if (var8) {
            angle = 0x1922;
            moved = 1;
        } else if (var9) {
            angle = 0x4B66;
            moved = 1;
        }
        if (moved) {
            Matrix4x3 m = RotationMatrixY(angle);
            Mat4x3_ApplyToVector(&dir, &m, &dir);
            Vector3fix_Add(&var33, &dir, &var33);
            inline_020a2d14(cam, &var33, &cam->target);
            return;
        }
        changed = 0;
        step = (int)(4096.0f * (0.2f * speed * scale));
        if (var2) {
            var33.y += step;
            changed = 1;
        }
        if (var3) {
            var33.y -= step;
            changed = 1;
        }
        if (changed) {
            inline_020a2d14(cam, &var33, &cam->target);
            return;
        }
    }

    if (cam->mode == 1) {
        fix32_t step = (int)(4096.0f * (0.3f * speed * scale));
        if (var0) {
            func_0202e858(cam, step);
        }
        if (var1) {
            func_0202e858(cam, -step);
        }
    }

    if (cam->mode == 1) {
        fix32_t step = (int)(4096.0f * (0.2f * speed * scale));
        if (var2) {
            pos.y += step;
        }
        if (var3) {
            pos.y -= step;
        }
    }

    if (cam->mode == 2 && moved == 0) {
        fix32_t move = (int)(4096.0f * (0.2f * speed * scale));
        fix32_t zoom = (int)(4096.0f * (0.3f * speed * scale));
        if (var3 && var5) {
            pos.y += move;
        } else if (var3 && var4) {
            pos.y -= move;
        } else if (var5) {
            func_0202e858(cam, zoom);
        } else if (var4) {
            func_0202e858(cam, -zoom);
        }
    }

    Camera_SetTargetKeepOrbit((char*)cam, (int*)&pos);
}
