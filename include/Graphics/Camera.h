#pragma once

#include "NitroSDK/Matrix.h"

// The 3D camera, as far as Camera_Update reads it (the object is larger).
struct Camera {
    unsigned int field0;
    Vector3i position;              // Camera_SetPosition; Camera_EasePositionTo moves it
    Vector3i target;                // Camera_SetTarget; Camera_EaseTargetTo moves it
    Vector3i up;
    unsigned char padding28[0x34];
    int frustum[5];
    unsigned char padding70[0xc];
    short roll;
    unsigned char padding7e[0x72];
    Matrix4x3 transform;
    Vector3i effectivePosition;
    Vector3i effectiveTarget;
    Vector3i direction;
    Matrix3x3 inverseRotation;
    unsigned int flags;
    // Three 0x28-byte vector eases (Vec3Ease_IsRunning); Camera_IsEasing tests all three.
    unsigned char positionEase[0x28]; // Camera_EasePositionTo
    unsigned char targetEase[0x28];   // Camera_EaseTargetTo
    unsigned char unknownEase[0x28];
    int shakeAmplitude;
    unsigned int shakeRemaining;
    unsigned char padding1ec[0xc];
    unsigned char bobbing;
    unsigned char padding1f9;
    unsigned short bobPhase;
    int bobOffset;
    float bobSpeed;
    int bobAmplitude;
    int minimumHeight;
    unsigned char clampHeight;
    unsigned char padding20d[5];
    short yaw;
};
