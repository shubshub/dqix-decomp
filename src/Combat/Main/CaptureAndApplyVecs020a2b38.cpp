#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

void Camera_SetOrbitVector(void* obj, int* vec);
struct GlobalObj0202e6a8;
void Camera_SetOrbitYaw(struct GlobalObj0202e6a8*, int);
extern "C" void func_020a212c(void* obj, int flag);

// USA: func_020a2b38
ARM void CaptureAndApplyVecs020a2b38(void* objRaw, int* a, int* b, int* c) {
    char* base = (char*)objRaw;
    Vector3i local1 = *(Vector3i*)(base + 0x10);
    Vector3i local0 = *(Vector3i*)(base + 0x70);
    int v = *(short*)(base + 0x21e);
    Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)objRaw, v);
    *(int*)(base + 0x220) = *(short*)(base + 0x21e);
    Camera_SetOrbitVector(objRaw, (int*)(base + 0x220));
    func_020a212c(objRaw, 0);
    *(Vector3i*)a = *(Vector3i*)(base + 0x4);
    *(Vector3i*)b = *(Vector3i*)(base + 0x10);
    *(Vector3i*)c = *(Vector3i*)(base + 0x70);
    *(Vector3i*)(base + 0x10) = local1;
    Camera_SetOrbitVector(objRaw, (int*)&local0);
}
