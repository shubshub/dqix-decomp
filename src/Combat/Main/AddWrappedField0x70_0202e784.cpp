#include <globaldefs.h>

struct GlobalObj0202e6a8 {
    char pad0[0x70];
    int field70;
};

void Camera_SetOrbitYaw(struct GlobalObj0202e6a8*, int);

// USA: func_0202e784
ARM void AddWrappedField0x70_0202e784(struct GlobalObj0202e6a8* obj, int val) {
    val += obj->field70;
    if ((float)val < 0.0f) val += 0x6488;
    if (val > 0x6488) val += -0x6488;
    Camera_SetOrbitYaw(obj, val);
}
