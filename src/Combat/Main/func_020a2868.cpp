#include <globaldefs.h>
extern "C" void Camera_SetFieldOfView(struct AngleTrig0202e9a4*, int);

extern "C" void Camera_SetOrbitVector(void*, int*);

struct Struct_020a2868 {
    unsigned char pad[0x220];
    int vec[3];
};

// USA: func_020a2868
extern "C" ARM void func_020a2868(struct Struct_020a2868* obj) {
    obj->vec[1] = 0xc666;
    obj->vec[2] = 0xe666;
    Camera_SetOrbitVector(obj, obj->vec);
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)(obj), (int)(0x19000));
}
