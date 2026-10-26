#include <globaldefs.h>
void Camera_SetFieldOfView(struct AngleTrig0202e9a4*, int);

void Camera_SetOrbitVector(void*, int*);

struct Struct020A2800 {
    char pad[0x220];
    int vecX;
    int vecY;
    int vecZ;
};

// USA: func_020a2800
ARM void ConfigureVec3AndApply020a2800(struct Struct020A2800* obj) {
    obj->vecY = 0x6000;
    obj->vecZ = 0xb000;
    Camera_SetOrbitVector(obj, &obj->vecX);
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)(obj), (int)(0xf000));
}
