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
extern "C" void func_0202eab8(ViewerCamera0218e670*);

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
    arg0->unknown_24_->MaybeUpdateBonePositions();
    data_ov015_02194564.unknown_8_ = NULL;
    data_ov015_02194564.unknown_0_ = NULL;
    data_ov015_02194564.unknown_4_ = NULL;
    Vector3i var6;
    Vector3i var7;
    Vector3i var8;
    var6.x = var0.translation.x;
    var6.y = var0.translation.y;
    var6.z = var0.translation.z;
    var7.x = var1.translation.x;
    var7.y = var1.translation.y;
    var7.z = var1.translation.z;
    var8.x = var2.translation.x;
    var8.y = var2.translation.y;
    var8.z = var2.translation.z;
    Vector3i var9 = arg0->unknown_24_->GetScale();
    Vector3fixMultiply(&var6, &var9, &var6);
    Vector3fixMultiply(&var7, &var9, &var7);
    Vector3fixMultiply(&var8, &var9, &var8);
    Vector3i var10 = arg0->unknown_24_->position_;
    Vector3fix_Add(&var6, &var10, &var6);
    Vector3fix_Add(&var7, &var10, &var7);
    Vector3fix_Add(&var8, &var10, &var8);
    (var4->unknown_10_ = var7, var4->unknown_4_) = var6;
    func_0202eab8(var4);
}
