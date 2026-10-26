#include <globaldefs.h>

struct Struct_0204a170;
struct GlobalObj0202e6a8;
struct Obj0202e71c;

extern "C" void func_020a2d14(void* obj);
extern "C" int func_020a3570(struct Struct_0204a170* p);
extern "C" void func_ov000_0216f3d4(void* obj);
extern "C" void func_ov000_0216ea38(void* obj);
extern "C" void func_ov000_0216f0d0(void* obj);
extern "C" int Camera_GetOrbitYaw(void* obj);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void Camera_SetOrbitYaw(struct GlobalObj0202e6a8* obj, int value);
extern "C" int Camera_GetOrbitDistance(void* obj);
extern "C" void Camera_SetOrbitDistance(struct Obj0202e71c* obj, int p);
extern "C" void func_ov000_0216f2b8(void* obj);

struct Struct_ov000_0216d464 {
    unsigned char pad[0x238];
    int unknown_238_;
    int unknown_23c_;
};

// USA: func_ov000_0216d464
extern "C" ARM void func_ov000_0216d464(struct Struct_ov000_0216d464* obj) {
    func_020a2d14(obj);
    if (func_020a3570((struct Struct_0204a170*)obj) != 0) {
        func_ov000_0216f3d4(obj);
        return;
    }
    func_ov000_0216ea38(obj);
    func_ov000_0216f0d0(obj);
    if (obj->unknown_238_ != 0) {
        int a = Camera_GetOrbitYaw(obj);
        int angle = fix32ReduceAngle0To2Pi(a + obj->unknown_238_);
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)obj, angle);
    }
    if (obj->unknown_23c_ != 0) {
        int cur78 = Camera_GetOrbitDistance(obj);
        int var3 = obj->unknown_23c_;
        int limit = (var3 < cur78) ? (cur78 + var3) : 0;
        if (limit < 0x3000) {
            limit = 0x3000;
        }
        Camera_SetOrbitDistance((struct Obj0202e71c*)obj, limit);
    }
    func_ov000_0216f2b8(obj);
    func_ov000_0216f3d4(obj);
}
