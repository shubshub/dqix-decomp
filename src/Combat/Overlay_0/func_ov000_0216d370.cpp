#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Matrix.h"

struct Flags0202ecfc;
void Camera_DisableTransform(struct Flags0202ecfc* p);
void Camera_SetRoll(unsigned char* obj, unsigned short val);
struct AngleTrig0202e9a4;
void Camera_SetFieldOfView(struct AngleTrig0202e9a4* obj, int angle);
void Camera_StopTurn(unsigned char* obj);
struct HalfwordTriple0202e98c;
void Camera_ResetYaw(struct HalfwordTriple0202e98c* p);
void* Camera_StopPositionEase(char* obj);
void* Camera_StopTargetEase(void* obj);
void* Camera_StopOrbitEase(void* obj);

// USA: func_ov000_0216d370
extern "C" ARM void func_ov000_0216d370(char* arg0, int arg1, int arg2, int arg3) {
    *(unsigned char*)(arg0 + 0x220) = 0;
    if (*(int*)(arg0 + 0x224) >= 0) {
        Vector3i var0 = *(Vector3i*)(arg0 + 0x12c);
        Vector3i var1 = *(Vector3i*)(arg0 + 0x120);
        *(Vector3i*)(arg0 + 0x10) = var0;
        *(Vector3i*)(arg0 + 0x4) = var1;
    }

    *(int*)(obj + 0x224) = -1;
    *(int*)(obj + 0x238) = 0;
    *(int*)(obj + 0x23c) = 0;
    Camera_DisableTransform((struct Flags0202ecfc*)obj);
    *(unsigned char*)(obj + 0x260) = 0;

    if (flagA) {
        Camera_SetRoll((unsigned char*)obj, 0);
    }

    if (flagB) {
        Camera_SetFieldOfView((struct AngleTrig0202e9a4*)obj, 0xf000);
    }

    if (flagC) {
        Camera_StopTurn((unsigned char*)obj);
        Camera_ResetYaw((struct HalfwordTriple0202e98c*)obj);
    }

    memset(obj + 0x264, 0, 0x14);
    Camera_StopPositionEase(obj);
    Camera_StopTargetEase(obj);
    Camera_StopOrbitEase(obj);
}
