#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_02033834;
struct Vector3i;
struct List02160094* GetNodeAtIndex02160094(struct List02160094* list, int idx);
struct List021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int idx);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
int Camera_GetOrbitYaw(void* obj);
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
void StoreVec3AtField0x50_0203db34(unsigned char* obj, int x, int y, int z);
extern "C" void* __clear(void* dst, int count);

static inline fix32_t inline_02061c04_5(fix32_t arg0, fix32_t arg1) {
    return (int)(((long long)arg0 * arg1 + 0x800) >> 12);
}

struct Struct_ov025_021e514c_4 {
    Vector3fix unknown_0_;
    Vector3fix unknown_c_;
    Vector3fix unknown_18_;
    Vector3fix unknown_24_;
};

struct Struct_ov025_021e514c_5 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
};

struct Struct_ov025_021e514c {
    char unknown_0_[0xe];
    short unknown_e_;
};

struct Struct_ov025_021e514c_2 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    int unknown_c_;
    int unknown_10_;
    Vector3fix unknown_14_;
    unsigned char unknown_20_;
};

struct Struct_ov025_021e514c_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x42];
    Vector3fix unknown_44_;
    Vector3fix unknown_50_;
};

// USA: func_ov025_021e514c
extern "C" ARM int func_ov025_021e514c(struct Struct_ov025_021e514c_2* arg0, struct Struct_ov000_0215440c_2* arg1, int arg2, void* arg3) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_ov025_021e514c_5* var1 = (struct Struct_ov025_021e514c_5*)func_ov000_02160094(arg1, 0);
    struct Struct_ov025_021e514c* var2 = (struct Struct_ov025_021e514c*)func_ov000_021600f8((struct Struct_ov000_0215440c*)arg1, 0);
    int var3[8];
    int var4 = func_ov000_021820bc(arg3, (int)arg1, arg0->unknown_8_, (int)var3);
    Vector3fix var5;
    __clear(&var5, sizeof(var5));
    int var6 = 0;
    int var7 = 0;
    unsigned char var8 = 0;
    unsigned char var9 = 0;
    int* var10;
    int var11;

    if (var1) {
        int var12;
        if (var1->unknown_20_ <= 3) var12 = 1; else var12 = 0;
        var8 = var12;
    }
    if (var2) {
        int var13 = 0;
        if (var2->unknown_e_ >= 0 && var2->unknown_e_ <= 3) var13 = 1;
        var9 = var13;
    }

    switch (arg0->unknown_9_) {
    case 1:
        if (var8) var7 = 1; else var7 = 2;
        break;
    case 2:
        if (var9) var7 = 1; else var7 = 2;
        break;
    case 5:
        if (var8) var7 = 2; else var7 = 1;
        break;
    case 6:
        if (var9) var7 = 2; else var7 = 1;
        break;
    case 3: {
        void* target = bs->GetCamera();
        if (target) {
            Matrix4x3 m = RotationMatrixY(Camera_GetOrbitYaw(target));
            Mat4x3_ApplyToVector(&self->vec, &m, &result);
        }
        break;
    }
    case 4:
    case 11: {
        if (var1 == 0 || var2 == 0) return 1;
        GameObject* var16 = var0->GetGameObjectByIndex(var2->unknown_e_);
        if (!var16) return 1;
        Struct_ov025_021e514c_3* var17 = (Struct_ov025_021e514c_3*)var16;
        fix32_t var18 = var16->obj3D_.GetRadius();
        int var19 = var17->unknown_50_.y;
        if (arg0->unknown_9_ == 4) arg0->unknown_14_.z = arg0->unknown_14_.z + (var18 >> 1);
        else arg0->unknown_14_.z = arg0->unknown_14_.z - (var18 >> 1);
        if (arg0->unknown_b_ == 1) {
            fix32_t var20 = var16->obj3D_.GetHeight() >> 1;
            arg0->unknown_14_.y = var20;
            if (arg0->unknown_c_ < arg0->unknown_14_.y) arg0->unknown_14_.y = arg0->unknown_c_;
            else if (arg0->unknown_14_.y < arg0->unknown_10_) arg0->unknown_14_.y = arg0->unknown_10_;
        }
        Matrix4x3 m = RotationMatrixY(rotY);
        Vector3fix off;
        Mat4x3_ApplyToVector(&self->vec, &m, &off);
        Vector3fix pos = o->position;
        Vector3fix_Add(&off, &pos, &off);
        int angle = fix32ReduceAngle0To2Pi(rotY + 0x3244);
        for (i = 0, idp = ids; i < count; i++, idp++) {
            GameObject* t = bs->GetGameObjectByIndex(*idp);
            if (t) {
                *(Vector3i*)(&t->obj3D_.position_.x) = *(Vector3i const*)((int*)&off);
                if (((Obj021e514c*)t)->flags & 2) {
                    GameObject_SnapFacing((struct Obj02033874*)t, angle);
                } else {
                    func_0203db34((unsigned char*)var25, 0, var24, 0);
                }
            }
        }
        return 1;
    }
    case 7: {
        int var26[12];
        func_ov000_021820bc(arg3, (int)arg1, arg0->unknown_a_, (int)var26);
        GameObject* var27 = var0->GetGameObjectByIndex(var26[0]);
        if (var27) {
            *(Vector3i*)((int*)&var5) = *(Vector3i const*)(&var27->obj3D_.position_.x);
            var6 = ((Struct_ov025_021e514c_3*)var27)->unknown_50_.y;
        }
        break;
    }
    case 10: {
        GameObject* var28 = var0->GetGameObjectByIndex(var1->unknown_20_);
        if (var28) {
            *(Vector3i*)((int*)&var5) = *(Vector3i const*)(&var28->obj3D_.position_.x);
            var5.y = var5.y + (var28->obj3D_.GetHeight() >> 1);
            var6 = ((Struct_ov025_021e514c_3*)var28)->unknown_50_.y;
        }
        break;
    }
    case 8: {
        int* tgt = (int*)bs->GetCamera();
        if (!tgt) return 1;
        Case8Local021e514c L;
        *(Vector3i*)((int*)&L.b) = *(Vector3i const*)(tgt + 4);
        *(Vector3i*)((int*)&L.a) = *(Vector3i const*)(tgt + 1);
        Vector3fix_Subtract(&L.a, &L.b, &L.diff);
        unsigned char axis = self->idxB;
        if (axis != 0 && axis < 4) {
            unsigned char k = axis - 1;
            L.tmp.x = self->vec.x;
            L.tmp.y = self->vec.y;
            L.tmp.z = self->vec.z;
            fix32_t* arr = (fix32_t*)&L.tmp;
            arr[k] = FxMul(arr[k], -0x1000);
            Vector3fix_Normalize(&L.diff, &L.diff);
            Vector3fixMultiplyScalar(&L.diff, arr[k], &L.diff);
            result.x = L.a.x + L.diff.x;
            result.y = L.a.y + L.diff.y;
            result.z = L.a.z + L.diff.z;
        } else {
            var5.x = var30.unknown_24_.x + inline_02061c04_5(var30.unknown_c_.x, arg0->unknown_14_.x);
            var5.y = var30.unknown_24_.y + inline_02061c04_5(var30.unknown_c_.y, arg0->unknown_14_.y);
            var5.z = var30.unknown_24_.z + inline_02061c04_5(var30.unknown_c_.z, arg0->unknown_14_.z);
        }
        break;
    }
    case 9:
        *(Vector3i*)((int*)&var5) = *(Vector3i const*)((int*)&arg0->unknown_14_);
        if (arg0->unknown_20_) var6 = 0x3244;
        break;
    }

    if (var7 != 0) {
        var5.y = 0;
        var5.x = 0;
        switch (var7) {
        case 1:
            var6 = 0x3244;
            var5.z = 0x2800;
            break;
        case 2:
            var6 = 0;
            var5.z = -0x2800;
            break;
        }
    }
    for (i = 0, idp = ids; i < count; i++, idp++) {
        GameObject* t = bs->GetGameObjectByIndex(*idp);
        if (t) {
            *(Vector3i*)(&t->obj3D_.position_.x) = *(Vector3i const*)((int*)&result);
            if (((Obj021e514c*)t)->flags & 2) {
                GameObject_SnapFacing((struct Obj02033874*)t, yaw);
            } else {
                func_0203db34((unsigned char*)var34, 0, var6, 0);
            }
        }
    }
    return 1;
}
