#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"

struct Struct_ov015_0218e670
{
    char field_0x0[0x24];
    Object3D* object;
    char field_0x28[0x12];
    unsigned char unknown_3a_;
};

struct ViewerCamera0218e670
{
    int field_0x0;
    Vector3i eye;
    Vector3i target;
};

struct Struct_ov015_02194564_2
{
    Matrix4x3* target;
    Matrix4x3* position;
    Matrix4x3* eye;
};

extern Struct_ov015_02194564_2 data_ov015_02194564;
extern "C" ViewerCamera0218e670* func_020100cc(char*);
extern "C" void G3X_ResetMtxStack();
extern "C" void Camera_SetOrbitFromPosition(ViewerCamera0218e670*);

// USA: func_ov015_0218e670
extern "C" ARM void func_ov015_0218e670(Struct_ov015_0218e670* self)
{
    Matrix4x3 var0;
    Matrix4x3 var1;
    Matrix4x3 var2;
    GameState* game = GameState::GetInstance();
    if (game == NULL)
        return;
    ViewerCamera0218e670* camera = func_020100cc((char*)game);
    if (camera == NULL)
        return;
    bool update = false;
    if (self->unknown_3a_)
    {
        if (g_keyManager.TestKeysPressed(0x100))
            update = true;
    }
    else
        update = true;
    if (!update)
        return;
    data_ov015_02194564.eye = &var0;
    data_ov015_02194564.target = &var1;
    data_ov015_02194564.position = &var2;
    G3X_ResetMtxStack();
    RenderConfig::SubmitToFifo();
    self->object->UpdateTrackedBones();
    data_ov015_02194564.eye = NULL;
    data_ov015_02194564.target = NULL;
    data_ov015_02194564.position = NULL;
    Vector3i eye;
    Vector3i target;
    Vector3i position;
    eye.x = var0.translation.x;
    eye.y = var0.translation.y;
    eye.z = var0.translation.z;
    target.x = var1.translation.x;
    target.y = var1.translation.y;
    target.z = var1.translation.z;
    position.x = var2.translation.x;
    position.y = var2.translation.y;
    position.z = var2.translation.z;
    Vector3i scale = self->object->GetScale();
    Vector3fixMultiply(&eye, &scale, &eye);
    Vector3fixMultiply(&target, &scale, &target);
    Vector3fixMultiply(&position, &scale, &position);
    Vector3i var10 = self->object->position_;
    Vector3fix_Add(&eye, &var10, &eye);
    Vector3fix_Add(&target, &var10, &target);
    Vector3fix_Add(&position, &var10, &position);
    (camera->target = target, camera->eye) = eye;
    Camera_SetOrbitFromPosition(camera);
}
