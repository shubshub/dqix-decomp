#include <globaldefs.h>
void Camera_SetFieldOfView(struct AngleTrig0202e9a4*, int);

void Camera_SetOrbitVector(void*, int*);

// USA: func_020a2830
ARM void InitVec3ParamsVariant8b33_020a2830(void* obj) {
    *(int*)((char*)obj + 0x224) = 0x8b33;
    *(int*)((char*)obj + 0x228) = 0xe666;
    Camera_SetOrbitVector(obj, (int*)((char*)obj + 0x220));
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)(obj), (int)(0x19000));
}
