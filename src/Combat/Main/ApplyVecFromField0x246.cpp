#include <globaldefs.h>

void Vec3Ease_Clear(void* p);
void Camera_SetOrbitVector(void* obj, int* vec);

// USA: func_020a2718
ARM void ApplyVecFromField0x246_020a2718(char* actor) {
    Vec3Ease_Clear(actor + 0x248);
    *(int*)(actor + 0x220) = *(short*)(actor + 0x246);
    Camera_SetOrbitVector(actor, (int*)(actor + 0x220));
}
