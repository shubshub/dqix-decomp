#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Graphics/Vector.h"
#include "GameState/GameState.h"

extern "C" void func_020a2d14(void* actor);
extern "C" void func_0204a4ac(void* self);
extern "C" void Camera_SetOrbitFromPosition(void* obj);
int fix32ReduceAngle0To2Pi(int angle);

struct Struct_0204a170;
extern "C" int func_020a3570(struct Struct_0204a170* p);

struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

extern Matrix4x3 data_02107874;
extern Matrix4x3 data_021078ac;
extern Matrix4x3 data_021078e4;

struct Struct_0204a170_2 {
    char pad0[0x44];
    Vector3fix pos;
    Vector3fix rot;
};

struct Struct_0204a170_3 {
    char pad0[0x4];
    Vector3fix f04;
    Vector3fix f10;
    char pad1[0x21c - 0x1c];
    struct Struct_0204a170_2* f21c;
    struct Struct_0204a170_2* unknown_220_;
    char pad2[0x260 - 0x224];
    int f260;
    unsigned char unknown_264_;
    unsigned char unknown_265_;
};

// USA: func_0204a170
extern "C" ARM void func_0204a170(struct Struct_0204a170_3* self) {
    Matrix4x3 var0;
    Matrix4x3 m2;
    Matrix4x3 var2;

    if (self->f21c == NULL) return;

    if (self->f260 >= 0) {
        GameState* bs = GameState::GetInstance();
        void* target = bs->GetGameObjectByIndex(self->f260);
        if (target != NULL) {
            *(Vector3i*)((int*)&self->f21c->pos) = *(Vector3i const*)((int*)((char*)target + 0x44));
            *(Vector3i*)((int*)&self->f21c->rot) = *(Vector3i const*)((int*)((char*)target + 0x50));
            ((Object3D*)self->f21c)->SetScale(&((Object3D*)target)->GetScale());
        }
    }

    func_020a2d14(self);
    if (func_020a3570((struct Struct_0204a170*)self) != 0) return;
    func_0204a4ac(self);

    const Vector3fix& scale = ((Object3D*)self->f21c)->GetScale();
    ((Object3D*)self->f21c)->UpdateTrackedBones();

    var0 = data_02107874;
    m2 = data_021078ac;
    var2 = data_021078e4;

    Vector3fix v1;
    Vector3fix v2;
    Vector3fix v3;

    v1.x = var0.translation.x; v1.y = var0.translation.y; v1.z = var0.translation.z;
    v2.x = m2.translation.x; v2.y = m2.translation.y; v2.z = m2.translation.z;
    v3.x = var2.translation.x; v3.y = var2.translation.y; v3.z = var2.translation.z;

    Vector3fixMultiply(&v1, &scale, &v1);
    Vector3fixMultiply(&v2, &scale, &v2);
    Vector3fixMultiply(&v3, &scale, &v3);

    Struct_0204a170_2* o = self->f21c;
    Vector3fix_Add(&v1, &o->pos, &v1);
    Vector3fix_Add(&v2, &o->pos, &v2);
    Vector3fix_Add(&v3, &o->pos, &v3);

    *(Vector3i*)((int*)&self->f10) = *(Vector3i const*)((int*)&v2);
    *(Vector3i*)((int*)&self->f04) = *(Vector3i const*)((int*)&v1);
    Camera_SetOrbitFromPosition(self);

struct Struct_0204a170_2* t = self->unknown_220_;
    if (t == NULL) return;

    int angle = fix32ReduceAngle0To2Pi(fix32_Atan2(v3.x - t->pos.x,
                                                        v3.z - t->pos.z));
    struct Struct_0204a170_2* u = self->unknown_220_;
    *(Vector3i*)((int*)&u->pos) = *(Vector3i const*)((int*)&v3);

    if (self->unknown_265_ != 0) return;

    self->unknown_264_++;
    if (self->unknown_264_ >= 3) {
        GameObject_SnapFacing((struct Obj02033874*)u,
            FIX32_MULTIPLY(t->rot.y + angle, 0x800));
        self->unknown_264_ = 0;
    } else {
        GameObject_SnapFacing((struct Obj02033874*)u, t->rot.y);
    }
}
