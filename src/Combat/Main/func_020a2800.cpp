#include <globaldefs.h>
extern "C" void Camera_SetFieldOfView(struct AngleTrig0202e9a4*, int);

extern "C" void Camera_SetOrbitVector(void*, int*);

struct Struct_020a2800 {
    char pad[0x220];
    int vecX;
    int unknown_224_;
    int unknown_228_;
};

// USA: func_020a2800
extern "C" ARM void func_020a2800(struct Struct_020a2800* obj) {
    obj->unknown_224_ = 0x6000;
    obj->unknown_228_ = 0xb000;
    Camera_SetOrbitVector(obj, &obj->vecX);
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)(obj), (int)(0xf000));
}
