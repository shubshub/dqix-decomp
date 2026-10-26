#include <globaldefs.h>
#include "std_library_functions.h"

struct CameraVector_0202df68 {
    int x;
    int y;
    int z;
};

// The camera (include/Graphics/Camera.h, header field names) with the fields its padding still hides:
// the field of view and its ease (Camera_UpdateFieldOfViewEase), the orbit (Camera_SetOrbit) and the roll, turn and yaw
// animations (Camera_UpdateAnimations).
struct CameraInitView {
    unsigned int field0;                   // kind flags (Camera_GetKindFlags)
    struct CameraVector_0202df68 position;
    struct CameraVector_0202df68 target;
    struct CameraVector_0202df68 up;
    char padding28[0x30];
    int fieldOfView;                       // Camera_SetFieldOfView also stores its sine and cosine in frustum[0], [1]
    int frustum[5];                        // Camera_Update's projection: sine, cosine, aspect, near, far
    int orbitYaw;
    int orbitHeight;
    int orbitDistance;
    short roll;
    char padding7e[0x72];
    unsigned char transform[0x30];         // Matrix4x3
    struct CameraVector_0202df68 effectivePosition;
    struct CameraVector_0202df68 effectiveTarget;
    struct CameraVector_0202df68 direction;
    unsigned char inverseRotation[0x24];   // Matrix3x3
    unsigned int flags;
    unsigned char positionEase[0x28];
    unsigned char targetEase[0x28];
    unsigned char unknownEase[0x28];
    int shakeAmplitude;
    unsigned int shakeRemaining;
    short rollStep;
    unsigned short rollFrames;
    int fieldOfViewTarget;
    unsigned int fieldOfViewEaseTime;
    unsigned char bobbing;
    unsigned char padding1f9;
    unsigned short bobPhase;
    int bobOffset;
    float bobSpeed;
    int bobAmplitude;
    int minimumHeight;
    unsigned char clampHeight;
    unsigned char padding20d;
    short turnStep;
    unsigned short turnFrames;
    short yaw;
    short yawStep;
    unsigned short yawFrames;
};

extern "C" void Camera_SetOrbitFromPosition(CameraInitView* camera);
extern "C" void Camera_SetOrbit(CameraInitView* camera, int yaw, int height, int distance);
extern "C" void Mat3x3_WriteIdentity(void* matrix);
void Vec3Ease_Clear(void* ease);

struct AngleTrig0202e9a4;
void Camera_SetFieldOfView(struct AngleTrig0202e9a4* camera, int fieldOfView);

// Main, originally func_0202df68 (USA 0x0202df68, EUR 0x0202df78, JPN 0x0202dad8)
extern "C" ARM void Camera_Init(CameraInitView* camera) {
    camera->field0 = 1;
    camera->frustum[2] = 0x1555;      // 4/3 (256/192)
    camera->frustum[3] = 0x1000;      // 1.0
    camera->frustum[4] = 0x190000;    // 400.0
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)camera, 0xf000);

    camera->position.x = 0;
    camera->position.y = 0x4000;
    camera->position.z = 0x8000;
    camera->target.x = 0;
    camera->target.y = 0x800;
    camera->target.z = 0;
    camera->up.x = 0;
    camera->up.y = 0x1000;
    camera->up.z = 0;
    Camera_SetOrbitFromPosition(camera);

    Camera_SetOrbit(camera, 0, 0x6000, 0xb000);

    memset(camera->transform, 0, sizeof(camera->transform));

    camera->roll = 0;
    camera->shakeAmplitude = 0;
    camera->shakeRemaining = 0;
    camera->flags = 0;

    Mat3x3_WriteIdentity(camera->inverseRotation);
    Vec3Ease_Clear(camera->positionEase);
    Vec3Ease_Clear(camera->targetEase);
    Vec3Ease_Clear(camera->unknownEase);

    camera->fieldOfViewTarget = camera->fieldOfView;
    camera->fieldOfViewEaseTime = 0;
    camera->bobbing = 0;

    camera->bobPhase = 0;
    camera->bobOffset = 0;
    camera->bobSpeed = 1.0f;
    camera->bobAmplitude = 0x1000;
    camera->rollStep = 0;
    camera->rollFrames = 0;
    camera->clampHeight = 0;

    camera->turnStep = 0;
    camera->turnFrames = 0;
    camera->yaw = 0;
    camera->yawStep = 0;
    camera->yawFrames = 0;
}
