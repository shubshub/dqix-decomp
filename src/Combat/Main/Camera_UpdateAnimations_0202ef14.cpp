#include <globaldefs.h>

struct DispatchObj020a0dec {
    int selector;
};

extern "C" int Vec3Ease_IsRunning(int*);
extern "C" void Vec3Ease_Step(struct DispatchObj020a0dec*);
extern "C" void Camera_TurnTarget(void*, int);
int fix32ReduceAngle0To2Pi(int);

// The camera (include/Graphics/Camera.h) with the animation fields its padding still hides:
// a roll animation (+0x1ec, +0x1ee), a turn of the target around the position (+0x20e, +0x210) and a
// yaw animation (+0x214, +0x216), each a step applied once a frame while its frame count runs down.
struct CameraAnimationView {
    char padding0[0x7c];
    short roll;
    char padding7e[0x168 - 0x7e];
    unsigned int flags;
    struct DispatchObj020a0dec positionEase;
    char padding170[0x194 - 0x170];
    struct DispatchObj020a0dec targetEase;
    char padding198[0x1bc - 0x198];
    struct DispatchObj020a0dec orbitEase;
    char padding1c0[0x1ec - 0x1c0];
    short rollStep;
    unsigned short rollFrames;
    char padding1f0[0x20e - 0x1f0];
    short turnStep;
    unsigned short turnFrames;
    short yaw;
    short yawStep;
    unsigned short yawFrames;
};

// What each ease applies its vector with: position, target, orbit (the members of data_020e73cc / _e73e4).
typedef void (CameraAnimationView::*CameraEaseApplier)(void*);

struct CameraEaseAppliers {
    CameraEaseApplier apply[3];
};

// Camera::flags bit 2 clear: the target ease sets the target alone (Camera_SetTargetVector).
extern const CameraEaseAppliers data_020e73cc;
// Bit 2 set: it moves the target and keeps the orbit (Camera_SetTargetKeepOrbit).
extern const CameraEaseAppliers data_020e73e4;

// Main, originally func_0202ef14 (USA 0x0202ef14, EUR 0x0202ef24, JPN 0x0202ea84)
extern "C" ARM void Camera_UpdateAnimations(struct CameraAnimationView* camera) {
    unsigned int flags = camera->flags;
    struct DispatchObj020a0dec* eases[3];
    eases[0] = &camera->positionEase;
    eases[1] = &camera->targetEase;
    eases[2] = &camera->orbitEase;

    int i;
    if (flags & 2) {
        struct CameraEaseAppliers appliers = data_020e73e4;
        for (i = 0; i < 3; i++) {
            if (Vec3Ease_IsRunning((int*)eases[i])) {
                Vec3Ease_Step(eases[i]);
                void* easedVector = (void*)((char*)eases[i] + 4);
                (camera->*appliers.apply[i])(easedVector);
            }
        }
    } else {
        struct CameraEaseAppliers appliers = data_020e73cc;
        for (i = 0; i < 3; i++) {
            if (Vec3Ease_IsRunning((int*)eases[i])) {
                Vec3Ease_Step(eases[i]);
                void* easedVector = (void*)((char*)eases[i] + 4);
                (camera->*appliers.apply[i])(easedVector);
            }
        }
    }

    if (camera->rollFrames != 0) {
        camera->rollFrames -= 1;
        camera->roll = camera->roll + camera->rollStep;
    }

    if (camera->turnFrames != 0) {
        camera->turnFrames -= 1;
        Camera_TurnTarget(camera, camera->turnStep);
    }

    if (camera->yawFrames != 0) {
        camera->yawFrames -= 1;
        camera->yaw = fix32ReduceAngle0To2Pi(camera->yaw + camera->yawStep);
    }
}
