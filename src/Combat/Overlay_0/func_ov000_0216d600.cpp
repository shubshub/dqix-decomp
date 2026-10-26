#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_ov000_0216d368 : Vector3i {};
struct AngleTrig0202e9a4 {
    unsigned int angle;
    Vector3i eye;
    Vector3i target;
    unsigned char padding[0x220 - 0x1c];
    unsigned char mode;
    unsigned char unknown_221_[7];
    int unknown_228_, unknown_22c_, unknown_230_, unknown_234_;
    int duration, unknown_23c_;
    Vector3i unknown_240_, unknown_24c_;
    int unknown_258_;
};
struct Struct_ov000_0216d600 {
#if defined(jpn)
    unsigned char padding[0x79e0];
#else
    unsigned char padding[0x77f0];
#endif
    int unknown_77f0_;
    Vector3i eye, target;
};
extern "C" void func_ov000_0216d370(AngleTrig0202e9a4*, int, int, int);
extern "C" void Camera_SetFieldOfView(AngleTrig0202e9a4*, int);
extern "C" void func_ov000_0216d368(Struct_ov000_0216d368*, int, int, int);
extern "C" Struct_ov000_0216d600* func_ov000_02160130();
extern "C" void Camera_SetOrbitFromPosition(AngleTrig0202e9a4*);
extern "C" int func_ov000_0216f210(AngleTrig0202e9a4*, int*);

static inline int inline_ov000_0216d600(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

// USA: func_ov000_0216d600
extern "C" ARM void func_ov000_0216d600(AngleTrig0202e9a4* camera, int arg1, int close, int mode, float x, float y, float z, unsigned char arg7) {
    func_ov000_0216d370(camera, 1, 1, 1);
    camera->mode = 2;
    int width, height;
    if (arg1 == 0) { width = camera->unknown_228_; height = camera->unknown_22c_; }
    else { width = camera->unknown_230_; height = camera->unknown_234_; }
    int scale, var3;
    if (close == 0) { scale = 0x424; var3 = scale + 0xb50; }
    else {
        Camera_SetFieldOfView(camera, 0x16000);
        scale = 0x5fe;
        var3 = 0xed6;
    }
    width = inline_ov000_0216d600(width, var3);
    int distance = fix32_Divide(width, (int)(2.2f * (float)scale)) - 0x2800;
    int var5 = inline_ov000_0216d600(height, var3);
    int var6 = fix32_Divide(var5, (int)(1.5f * (float)scale)) - 0x2800;
    if (var6 >= distance) distance = var6;
    int minimum = 0x6800;
    if (close != 0) minimum = 0x3000;
    if (distance < minimum) distance = minimum;
    height /= 2;
    if (height < 0x1333) height = 0x1333;
    Struct_ov000_0216d368 eye, target;
    int result;
    func_ov000_0216d368(&eye, 0, height, distance);
    func_ov000_0216d368(&target, 0, height, 0);
    if (eye.y > 0x2000) eye.y = 0x2000;
    if (close == 0) {
        if (mode == 1) eye.y += 0x1000;
        else if (mode == 2) {
            eye.x += (int)(4096.0f * x);
            eye.y += (int)(4096.0f * y);
            eye.z += (int)(4096.0f * z);
        } else if (mode == 3) {
            camera->duration = 28;
            camera->unknown_23c_ = 20;
            eye.x += (int)(4096.0f * x);
            eye.y += (int)(4096.0f * y);
            eye.z += (int)(4096.0f * z);
        }
    }
    if (arg7) {
        Struct_ov000_0216d600* work = func_ov000_02160130();
        if (work && work->unknown_77f0_ != -1) {
            func_ov000_0216d368(&eye, work->eye.x, work->eye.y, work->eye.z);
            func_ov000_0216d368(&target, work->target.x, work->target.y, work->target.z);
        }
    }
    if (arg1 == 0) { eye.z = -eye.z; target.z = -target.z; }
    camera->eye = eye;
    camera->target = target;
    Camera_SetOrbitFromPosition(camera);
    camera->unknown_240_ = eye;
    camera->unknown_24c_ = target;
    camera->unknown_258_ = func_ov000_0216f210(camera, &result);
}
