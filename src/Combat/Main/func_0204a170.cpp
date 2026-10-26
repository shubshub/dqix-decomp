#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Graphics/Vector.h"
#include "GameState/GameState.h"

extern "C" void func_020a2d14(void* actor);
extern "C" void func_0204a4ac(void* self);
extern "C" void Camera_SetOrbitFromPosition(void* obj);
int fix32ReduceAngle0To2Pi(int angle);

struct Struct_0204a170;
extern "C" int func_020a3570(struct Struct_0204a170* arg0);

struct Obj02033874;
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

extern Matrix4x3 data_02107874;
extern Matrix4x3 data_021078ac;
extern Matrix4x3 data_021078e4;

struct Struct_0204a170_2 {
    char unknown_0_[0x44];
    Vector3fix unknown_44_;
    Vector3fix unknown_50_;
};

struct Struct_0204a170_3 {
    char unknown_0_[0x4];
    Vector3fix unknown_4_;
    Vector3fix unknown_10_;
    char unknown_1c_[0x21c - 0x1c];
    struct Struct_0204a170_2* unknown_21c_;
    struct Struct_0204a170_2* unknown_220_;
    char unknown_224_[0x260 - 0x224];
    int unknown_260_;
    unsigned char unknown_264_;
    unsigned char unknown_265_;
};

// USA: func_0204a170
extern "C" ARM void func_0204a170(struct Struct_0204a170_3* arg0) {
    Matrix4x3 var0;
    Matrix4x3 var1;
    Matrix4x3 var2;

    if (arg0->unknown_21c_ == NULL) return;

    if (arg0->unknown_260_ >= 0) {
        GameState* var3 = GameState::GetInstance();
        void* var4 = var3->GetGameObjectByIndex(arg0->unknown_260_);
        if (var4 != NULL) {
            *(Vector3i*)((int*)&arg0->unknown_21c_->unknown_44_) = *(Vector3i const*)((int*)((char*)var4 + 0x44));
            *(Vector3i*)((int*)&arg0->unknown_21c_->unknown_50_) = *(Vector3i const*)((int*)((char*)var4 + 0x50));
            ((Object3D*)arg0->unknown_21c_)->SetScale(&((Object3D*)var4)->GetScale());
        }
    }

    func_020a2d14(arg0);
    if (func_020a3570((struct Struct_0204a170*)arg0) != 0) return;
    func_0204a4ac(arg0);

    const Vector3fix& scale = ((Object3D*)self->f21c)->GetScale();
    ((Object3D*)self->f21c)->UpdateTrackedBones();

    var0 = data_02107874;
    var1 = data_021078ac;
    var2 = data_021078e4;

    Vector3fix var6;
    Vector3fix var7;
    Vector3fix var8;

    var6.x = var0.translation.x; var6.y = var0.translation.y; var6.z = var0.translation.z;
    var7.x = var1.translation.x; var7.y = var1.translation.y; var7.z = var1.translation.z;
    var8.x = var2.translation.x; var8.y = var2.translation.y; var8.z = var2.translation.z;

    Vector3fixMultiply(&var6, &var5, &var6);
    Vector3fixMultiply(&var7, &var5, &var7);
    Vector3fixMultiply(&var8, &var5, &var8);

    Struct_0204a170_2* var9 = arg0->unknown_21c_;
    Vector3fix_Add(&var6, &var9->unknown_44_, &var6);
    Vector3fix_Add(&var7, &var9->unknown_44_, &var7);
    Vector3fix_Add(&var8, &var9->unknown_44_, &var8);

    *(Vector3i*)((int*)&self->f10) = *(Vector3i const*)((int*)&v2);
    *(Vector3i*)((int*)&self->f04) = *(Vector3i const*)((int*)&v1);
    Camera_SetOrbitFromPosition(self);

struct Struct_0204a170_2* var10 = arg0->unknown_220_;
    if (var10 == NULL) return;

    int var11 = fix32ReduceAngle0To2Pi(fix32_Atan2(var8.x - var10->unknown_44_.x,
                                                        var8.z - var10->unknown_44_.z));
    struct Struct_0204a170_2* var12 = arg0->unknown_220_;
    *(Vector3i*)((int*)&var12->unknown_44_) = *(Vector3i const*)((int*)&var8);

    if (arg0->unknown_265_ != 0) return;

    self->f264++;
    if (self->f264 >= 3) {
        GameObject_SnapFacing((struct Obj02033874*)u,
            FIX32_MULTIPLY(t->rot.y + angle, 0x800));
        self->f264 = 0;
    } else {
        GameObject_SnapFacing((struct Obj02033874*)u, t->rot.y);
    }
}
