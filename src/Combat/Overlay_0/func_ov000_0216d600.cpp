#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_ov000_0216d368 : Vector3i {};
struct Struct_0202df68 {
    unsigned int unknown_0_;
    Vector3i unknown_4_;
    Vector3i unknown_10_;
    unsigned char unknown_1c_[0x220 - 0x1c];
    unsigned char unknown_220_;
    unsigned char unknown_221_[7];
    int unknown_228_, unknown_22c_, unknown_230_, unknown_234_;
    int unknown_238_, unknown_23c_;
    Vector3i unknown_240_, unknown_24c_;
    int unknown_258_;
};
struct Struct_ov000_0216d600 {
#if defined(jpn)
    unsigned char unknown_0_[0x79e0];
#else
    unsigned char unknown1_0_[0x77f0];
#endif
    int unknown_77f0_;
    Vector3i unknown_77f4_, unknown_7800_;
};
extern "C" void func_ov000_0216d370(AngleTrig0202e9a4*, int, int, int);
void Camera_SetFieldOfView(AngleTrig0202e9a4*, int);
void StoreVec3Words0216d368(Vec3Ints0216d368*, int, int, int);
CombatWorkD600* GetActiveCombatWork_ov000_02160130();
extern "C" void Camera_SetOrbitFromPosition(AngleTrig0202e9a4*);
extern "C" int func_ov000_0216f210(AngleTrig0202e9a4*, int*);

static inline int inline_ov000_0216d600(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }

// USA: func_ov000_0216d600
extern "C" ARM void func_ov000_0216d600(Struct_0202df68* arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, unsigned char arg7) {
    func_ov000_0216d370(arg0, 1, 1, 1);
    arg0->unknown_220_ = 2;
    int var0, var1;
    if (arg1 == 0) { var0 = arg0->unknown_228_; var1 = arg0->unknown_22c_; }
    else { var0 = arg0->unknown_230_; var1 = arg0->unknown_234_; }
    int var2, var3;
    if (arg2 == 0) { var2 = 0x424; var3 = var2 + 0xb50; }
    else {
        Camera_SetFieldOfView(camera, 0x16000);
        scale = 0x5fe;
        factor = 0xed6;
    }
    var0 = inline_ov000_0216d600(var0, var3);
    int var4 = fix32_Divide(var0, (int)(2.2f * (float)var2)) - 0x2800;
    int var5 = inline_ov000_0216d600(var1, var3);
    int var6 = fix32_Divide(var5, (int)(1.5f * (float)var2)) - 0x2800;
    if (var6 >= var4) var4 = var6;
    int var7 = 0x6800;
    if (arg2 != 0) var7 = 0x3000;
    if (var4 < var7) var4 = var7;
    var1 /= 2;
    if (var1 < 0x1333) var1 = 0x1333;
    Struct_ov000_0216d368 var8, var9;
    int var10;
    func_ov000_0216d368(&var8, 0, var1, var4);
    func_ov000_0216d368(&var9, 0, var1, 0);
    if (var8.y > 0x2000) var8.y = 0x2000;
    if (arg2 == 0) {
        if (arg3 == 1) var8.y += 0x1000;
        else if (arg3 == 2) {
            var8.x += (int)(4096.0f * arg4);
            var8.y += (int)(4096.0f * arg5);
            var8.z += (int)(4096.0f * arg6);
        } else if (arg3 == 3) {
            arg0->unknown_238_ = 28;
            arg0->unknown_23c_ = 20;
            var8.x += (int)(4096.0f * arg4);
            var8.y += (int)(4096.0f * arg5);
            var8.z += (int)(4096.0f * arg6);
        }
    }
    if (arg7) {
        Struct_ov000_0216d600* var11 = func_ov000_02160130();
        if (var11 && var11->unknown_77f0_ != -1) {
            func_ov000_0216d368(&var8, var11->unknown_77f4_.x, var11->unknown_77f4_.y, var11->unknown_77f4_.z);
            func_ov000_0216d368(&var9, var11->unknown_7800_.x, var11->unknown_7800_.y, var11->unknown_7800_.z);
        }
    }
    if (side == 0) { eye.z = -eye.z; target.z = -target.z; }
    camera->eye = eye;
    camera->target = target;
    Camera_SetOrbitFromPosition(camera);
    camera->savedEye = eye;
    camera->savedTarget = target;
    camera->field258 = func_ov000_0216f210(camera, &result);
}
