#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"

struct Struct_ov015_0218e670
{
    char unknown_0_[0x24];
    Object3D* unknown_24_;
    char unknown_28_[0x12];
    unsigned char unknown_3a_;
};

struct Struct_ov015_0218e670_2
{
    int unknown_0_;
    Vector3i unknown_4_;
    Vector3i unknown_10_;
};

struct Struct_ov015_02194564_2
{
    Matrix4x3* unknown_0_;
    Matrix4x3* unknown_4_;
    Matrix4x3* unknown_8_;
};

extern CameraOutputs0218e670 data_ov015_02194564;
ViewerCamera0218e670* GetFieldIfFlag2_020100cc(char*);
extern "C" void G3X_ResetMtxStack();
extern "C" void Camera_SetOrbitFromPosition(ViewerCamera0218e670*);

// USA: func_ov015_0218e670
extern "C" ARM void func_ov015_0218e670(Struct_ov015_0218e670* arg0)
{
    Matrix4x3 var0;
    Matrix4x3 var1;
    Matrix4x3 var2;
    GameState* var3 = GameState::GetInstance();
    if (var3 == NULL)
        return;
    Struct_ov015_0218e670_2* var4 = func_020100cc((char*)var3);
    if (var4 == NULL)
        return;
    bool var5 = false;
    if (arg0->unknown_3a_)
    {
        if (g_keyManager.TestKeysPressed(0x100))
            var5 = true;
    }
    else
        var5 = true;
    if (!var5)
        return;
    data_ov015_02194564.eye = &eyeMatrix;
    data_ov015_02194564.target = &targetMatrix;
    data_ov015_02194564.position = &positionMatrix;
    G3X_ResetMtxStack();
    RenderConfig::SubmitToFifo();
    self->object->UpdateTrackedBones();
    data_ov015_02194564.eye = NULL;
    data_ov015_02194564.target = NULL;
    data_ov015_02194564.position = NULL;
    Vector3i eye;
    Vector3i target;
    Vector3i position;
    eye.x = eyeMatrix.translation.x;
    eye.y = eyeMatrix.translation.y;
    eye.z = eyeMatrix.translation.z;
    target.x = targetMatrix.translation.x;
    target.y = targetMatrix.translation.y;
    target.z = targetMatrix.translation.z;
    position.x = positionMatrix.translation.x;
    position.y = positionMatrix.translation.y;
    position.z = positionMatrix.translation.z;
    Vector3i scale = self->object->GetScale();
    Vector3fixMultiply(&eye, &scale, &eye);
    Vector3fixMultiply(&target, &scale, &target);
    Vector3fixMultiply(&position, &scale, &position);
    Vector3i translation = self->object->position_;
    Vector3fix_Add(&eye, &translation, &eye);
    Vector3fix_Add(&target, &translation, &target);
    Vector3fix_Add(&position, &translation, &position);
    (camera->target = target, camera->eye) = eye;
    Camera_SetOrbitFromPosition(camera);
}
