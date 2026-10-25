#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "Graphics/Camera.h"

extern "C" void func_0202ef14(Camera*);
extern "C" void func_0202f0e0(Camera*);
extern const Vector3i data_020e73c0;
extern const short data_020e9450[];

static inline void inline_0202e0a4(Vector3i& arg0, Vector3i& arg1, short arg2) {
    Vector3i var0;
    Vector3fix_Subtract(&arg1, &arg0, &var0);
    Matrix4x3 var1;
    var1 = RotationMatrixY(arg2);
    Mat4x3_ApplyToVector(&var0, &var1, &var0);
    Vector3fix_Add(&arg0, &var0, &arg1);
}

// Main, originally func_0202e0a4 (USA 0x0202e0a4, EUR 0x0202e0b4, JPN 0x0202dc14)
extern "C" ARM void Camera_Update(Camera* camera) {
    func_0202ef14(camera);
    func_0202f0e0(camera);
    camera->effectivePosition = camera->position;
    camera->effectiveTarget = camera->target;
    if (camera->flags & 1) {
        Mat4x3_ApplyToVector(&camera->effectivePosition, &camera->transform, &camera->effectivePosition);
        Mat4x3_ApplyToVector(&camera->effectiveTarget, &camera->transform, &camera->effectiveTarget);
    }
    Mat4x4_MaybeWriteFrustum(arg0->unknown_5c_[0], arg0->unknown_5c_[1], arg0->unknown_5c_[2], arg0->unknown_5c_[3], arg0->unknown_5c_[4], 0x1000, &data_0210a010.projectionMatrix);
    data_0210a010.flags &= ~0x50;
    if (arg0->unknown_7c_ == 0) {
        arg0->unknown_1c_.x = 0;
        arg0->unknown_1c_.y = 0x1000;
        arg0->unknown_1c_.z = 0;
    } else {
        Vector3i var0 = data_020e73c0;
        Matrix4x3 var1;
        var1 = RotationMatrixZ(arg0->unknown_7c_);
        Mat4x3_ApplyToVector(&var0, &var1, &var0);
        Vector3i var2;
        Vector3fix_Subtract(&arg0->unknown_12c_, &arg0->unknown_120_, &var2);
        var2.y = 0;
        Vector3fix_Normalize(&var2, &var2);
        var1 = RotationMatrixY(fix32ReduceAngle0To2Pi(fix32_Atan2(var2.x, var2.z)));
        Mat4x3_ApplyToVector(&var0, &var1, &arg0->unknown_1c_);
    }
    Vector3i var3 = arg0->unknown_120_;
    Vector3i var4 = arg0->unknown_12c_;
    if (arg0->unknown_1e8_ && !(arg0->unknown_168_ & 4)) {
        if (arg0->unknown_1e8_ <= 33) {
            arg0->unknown_1e8_ = 0;
            arg0->unknown_1e4_ = 0;
        } else {
            arg0->unknown_1e8_ -= 33;
            int var5 = arg0->unknown_1e4_;
            arg0->unknown_1e4_ = var5 - (33 * var5) / arg0->unknown_1e8_;
        }
    }
    if (arg0->unknown_1e4_ > 0) {
        const Matrix4x3& var6 = data_0210a010.viewMatrix;
        Vector3i var7 = { var6.rows[0].x, var6.rows[0].y, var6.rows[0].z };
        Vector3i var8 = { var6.rows[1].x, var6.rows[1].y, var6.rows[1].z };
        switch (rand() % 4) {
        case 0:
            Vector3fixMultiplyScalar(&var7, arg0->unknown_1e4_, &var7);
            Vector3fixMultiplyScalar(&var8, arg0->unknown_1e4_, &var8);
            break;
        case 1:
            Vector3fixMultiplyScalar(&var7, -arg0->unknown_1e4_, &var7);
            Vector3fixMultiplyScalar(&var8, arg0->unknown_1e4_, &var8);
            break;
        case 2:
            Vector3fixMultiplyScalar(&var7, arg0->unknown_1e4_, &var7);
            Vector3fixMultiplyScalar(&var8, -arg0->unknown_1e4_, &var8);
            break;
        case 3:
            Vector3fixMultiplyScalar(&var7, -arg0->unknown_1e4_, &var7);
            Vector3fixMultiplyScalar(&var8, -arg0->unknown_1e4_, &var8);
            break;
        }
        Vector3fix_Add(&var3, &var7, &var3);
        Vector3fix_Add(&var3, &var8, &var3);
        Vector3fix_Add(&var4, &var7, &var4);
        Vector3fix_Add(&var4, &var8, &var4);
    }
    if (arg0->unknown_1f8_) {
        unsigned int var9 = GameState::GetInstance()->GetTickCount();
        arg0->unknown_1fa_ += (int)(arg0->unknown_200_ * (float)(var9 * 182));
        arg0->unknown_1fc_ = data_020e9450[(arg0->unknown_1fa_ >> 4) * 2 + 1] >> 3;
        arg0->unknown_1fc_ = FIX32_MULTIPLY(arg0->unknown_1fc_, arg0->unknown_204_);
        var3.y += arg0->unknown_1fc_;
        var4.y += arg0->unknown_1fc_;
    }
    if (arg0->unknown_20c_ && var3.y < arg0->unknown_208_) {
        var3.y = arg0->unknown_208_;
    }
    short var10 = arg0->unknown_212_;
    if (var10) {
        inline_0202e0a4(var3, var4, var10);
    }
    data_0210a010.eyeVector = var3;
    data_0210a010.upVector = arg0->unknown_1c_;
    data_0210a010.targetVector = var4;
    Mat4x3_WriteViewMatrix(&var3, &arg0->unknown_1c_, &var4, &data_0210a010.viewMatrix);
    data_0210a010.flags &= ~0xe8;
    Vector3fix_Subtract(&arg0->unknown_12c_, &arg0->unknown_120_, &arg0->unknown_138_);
    Vector3fix_Normalize(&arg0->unknown_138_, &arg0->unknown_138_);
    const Matrix4x3* var11 = RenderConfig::GetInverseViewMatrix();
    arg0->unknown_144_.entries[0] = var11->entries[0];
    arg0->unknown_144_.entries[1] = var11->entries[1];
    arg0->unknown_144_.entries[2] = var11->entries[2];
    arg0->unknown_144_.entries[3] = var11->entries[3];
    arg0->unknown_144_.entries[4] = var11->entries[4];
    arg0->unknown_144_.entries[5] = var11->entries[5];
    arg0->unknown_144_.entries[6] = var11->entries[6];
    arg0->unknown_144_.entries[7] = var11->entries[7];
    arg0->unknown_144_.entries[8] = var11->entries[8];
}
