#include <globaldefs.h>

extern "C" void Vec3Ease_Clear(void* p);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

// USA: func_020a2718
extern "C" ARM void func_020a2718(char* actor) {
    Vec3Ease_Clear(actor + 0x248);
    *(int*)(actor + 0x220) = *(short*)(actor + 0x246);
    Camera_SetOrbitVector(actor, (int*)(actor + 0x220));
}
