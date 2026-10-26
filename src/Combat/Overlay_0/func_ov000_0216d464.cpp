#include <globaldefs.h>

struct Struct_0204a170;
struct Struct_0202e6a8;
struct Struct_0202e71c;

extern "C" void func_020a2d14(void* obj);
int GetField0x218(struct S020a3570* p);
extern "C" void func_ov000_0216f3d4(void* obj);
extern "C" void func_ov000_0216ea38(void* obj);
extern "C" void func_ov000_0216f0d0(void* obj);
int Camera_GetOrbitYaw(void* obj);
int fix32ReduceAngle0To2Pi(int angle);
void Camera_SetOrbitYaw(struct GlobalObj0202e6a8* obj, int value);
int Camera_GetOrbitDistance(void* obj);
void Camera_SetOrbitDistance(struct Obj0202e71c* obj, int p);
extern "C" void func_ov000_0216f2b8(void* obj);

struct Struct_ov000_0216d464 {
    unsigned char unknown_0_[0x238];
    int unknown_238_;
    int unknown_23c_;
};

// USA: func_ov000_0216d464
extern "C" ARM void func_ov000_0216d464(struct Struct_ov000_0216d464* arg0) {
    func_020a2d14(arg0);
    if (func_020a3570((struct Struct_0204a170*)arg0) != 0) {
        func_ov000_0216f3d4(arg0);
        return;
    }
    func_ov000_0216ea38(obj);
    func_ov000_0216f0d0(obj);
    if (obj->f238 != 0) {
        int a = Camera_GetOrbitYaw(obj);
        int angle = fix32ReduceAngle0To2Pi(a + obj->f238);
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)obj, angle);
    }
    if (obj->f23c != 0) {
        int cur78 = Camera_GetOrbitDistance(obj);
        int f23c = obj->f23c;
        int limit = (f23c < cur78) ? (cur78 + f23c) : 0;
        if (limit < 0x3000) {
            limit = 0x3000;
        }
        Camera_SetOrbitDistance((struct Obj0202e71c*)obj, limit);
    }
    func_ov000_0216f2b8(arg0);
    func_ov000_0216f3d4(arg0);
}
