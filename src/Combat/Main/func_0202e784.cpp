#include <globaldefs.h>

struct GlobalObj0202e6a8 {
    char pad0[0x70];
    int unknown_70_;
};

extern "C" void Camera_SetOrbitYaw(struct GlobalObj0202e6a8*, int);

// USA: func_0202e784
extern "C" ARM void func_0202e784(struct GlobalObj0202e6a8* obj, int val) {
    val += obj->unknown_70_;
    if ((float)val < 0.0f) val += 0x6488;
    if (val > 0x6488) val += -0x6488;
    Camera_SetOrbitYaw(obj, val);
}
