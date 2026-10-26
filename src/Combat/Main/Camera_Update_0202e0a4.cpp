#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "Graphics/Camera.h"

extern "C" void Camera_UpdateAnimations(Camera*);
extern "C" void Camera_UpdateFieldOfViewEase(Camera*);
extern const Vector3i data_020e73c0;
extern const short data_020e9450[];

static inline void inline_0202e0a4(Vector3i& position, Vector3i& target, short yaw) {
    Vector3i var0;
    Vector3fix_Subtract(&target, &position, &var0);
    Matrix4x3 var1;
    var1 = RotationMatrixY(yaw);
    Mat4x3_ApplyToVector(&var0, &var1, &var0);
    Vector3fix_Add(&position, &var0, &target);
}

// Main, originally func_0202e0a4 (USA 0x0202e0a4, EUR 0x0202e0b4, JPN 0x0202dc14)
extern "C" ARM void Camera_Update(Camera* camera) {
    Camera_UpdateAnimations(camera);
    Camera_UpdateFieldOfViewEase(camera);
    camera->effectivePosition = camera->position;
    camera->effectiveTarget = camera->target;
    if (camera->flags & 1) {
        Mat4x3_ApplyToVector(&camera->effectivePosition, &camera->transform, &camera->effectivePosition);
        Mat4x3_ApplyToVector(&camera->effectiveTarget, &camera->transform, &camera->effectiveTarget);
    }
    Mat4x4_MaybeWriteFrustum(camera->frustum[0], camera->frustum[1], camera->frustum[2], camera->frustum[3], camera->frustum[4], 0x1000, &data_0210a010.projectionMatrix);
    data_0210a010.flags &= ~0x50;
    if (camera->roll == 0) {
        camera->up.x = 0;
        camera->up.y = 0x1000;
        camera->up.z = 0;
    } else {
        Vector3i up = data_020e73c0;
        Matrix4x3 rotation;
        rotation = RotationMatrixZ(camera->roll);
        Mat4x3_ApplyToVector(&up, &rotation, &up);
        Vector3i difference;
        Vector3fix_Subtract(&camera->effectiveTarget, &camera->effectivePosition, &difference);
        difference.y = 0;
        Vector3fix_Normalize(&difference, &difference);
        rotation = RotationMatrixY(fix32ReduceAngle0To2Pi(fix32_Atan2(difference.x, difference.z)));
        Mat4x3_ApplyToVector(&up, &rotation, &camera->up);
    }
    Vector3i position = camera->effectivePosition;
    Vector3i target = camera->effectiveTarget;
    if (camera->shakeRemaining && !(camera->flags & 4)) {
        if (camera->shakeRemaining <= 33) {
            camera->shakeRemaining = 0;
            camera->shakeAmplitude = 0;
        } else {
            camera->shakeRemaining -= 33;
            int amplitude = camera->shakeAmplitude;
            camera->shakeAmplitude = amplitude - (33 * amplitude) / camera->shakeRemaining;
        }
    }
    if (camera->shakeAmplitude > 0) {
        const Matrix4x3& view = data_0210a010.viewMatrix;
        Vector3i first = { view.rows[0].x, view.rows[0].y, view.rows[0].z };
        Vector3i second = { view.rows[1].x, view.rows[1].y, view.rows[1].z };
        switch (rand() % 4) {
        case 0:
            Vector3fixMultiplyScalar(&first, camera->shakeAmplitude, &first);
            Vector3fixMultiplyScalar(&second, camera->shakeAmplitude, &second);
            break;
        case 1:
            Vector3fixMultiplyScalar(&first, -camera->shakeAmplitude, &first);
            Vector3fixMultiplyScalar(&second, camera->shakeAmplitude, &second);
            break;
        case 2:
            Vector3fixMultiplyScalar(&first, camera->shakeAmplitude, &first);
            Vector3fixMultiplyScalar(&second, -camera->shakeAmplitude, &second);
            break;
        case 3:
            Vector3fixMultiplyScalar(&first, -camera->shakeAmplitude, &first);
            Vector3fixMultiplyScalar(&second, -camera->shakeAmplitude, &second);
            break;
        }
        Vector3fix_Add(&position, &first, &position);
        Vector3fix_Add(&position, &second, &position);
        Vector3fix_Add(&target, &first, &target);
        Vector3fix_Add(&target, &second, &target);
    }
    if (camera->bobbing) {
        unsigned int tick = GameState::GetInstance()->GetTickCount();
        camera->bobPhase += (int)(camera->bobSpeed * (float)(tick * 182));
        camera->bobOffset = data_020e9450[(camera->bobPhase >> 4) * 2 + 1] >> 3;
        camera->bobOffset = FIX32_MULTIPLY(camera->bobOffset, camera->bobAmplitude);
        position.y += camera->bobOffset;
        target.y += camera->bobOffset;
    }
    if (camera->clampHeight && position.y < camera->minimumHeight) {
        position.y = camera->minimumHeight;
    }
    short yaw = camera->yaw;
    if (yaw) {
        inline_0202e0a4(position, target, yaw);
    }
    data_0210a010.eyeVector = position;
    data_0210a010.upVector = camera->up;
    data_0210a010.targetVector = target;
    Mat4x3_WriteViewMatrix(&position, &camera->up, &target, &data_0210a010.viewMatrix);
    data_0210a010.flags &= ~0xe8;
    Vector3fix_Subtract(&camera->effectiveTarget, &camera->effectivePosition, &camera->direction);
    Vector3fix_Normalize(&camera->direction, &camera->direction);
    const Matrix4x3* inverse = RenderConfig::GetInverseViewMatrix();
    camera->inverseRotation.entries[0] = inverse->entries[0];
    camera->inverseRotation.entries[1] = inverse->entries[1];
    camera->inverseRotation.entries[2] = inverse->entries[2];
    camera->inverseRotation.entries[3] = inverse->entries[3];
    camera->inverseRotation.entries[4] = inverse->entries[4];
    camera->inverseRotation.entries[5] = inverse->entries[5];
    camera->inverseRotation.entries[6] = inverse->entries[6];
    camera->inverseRotation.entries[7] = inverse->entries[7];
    camera->inverseRotation.entries[8] = inverse->entries[8];
}
