#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Obj02033874;
struct Vector3i;
extern "C" struct Struct_ov000_0215440c_2* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int idx);
extern "C" struct Struct_ov000_0215440c* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int idx);
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" int Camera_GetOrbitYaw(void* obj);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
extern "C" void func_0203db34(unsigned char* obj, int x, int y, int z);
extern "C" void* __clear(void* dst, int count);

static inline fix32_t FxMul(fix32_t a, fix32_t b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Struct_ov025_021e514c_4 {
    Vector3fix tmp;
    Vector3fix diff;
    Vector3fix a;
    Vector3fix b;
};

struct Struct_ov025_021e514c_5 {
    char pad[0x20];
    unsigned short field20;
};

struct Struct_ov025_021e514c {
    char pad[0xe];
    short unknown_e_;
};

struct Struct_ov025_021e514c_2 {
    char pad0[8];
    unsigned char unknown_8_;
    unsigned char mode;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    int unknown_c_;
    int unknown_10_;
    Vector3fix vec;
    unsigned char unknown_20_;
};

struct Struct_ov025_021e514c_3 {
    unsigned short flags;
    char pad2[0x42];
    Vector3fix position;
    Vector3fix rotation;
};

// USA: func_ov025_021e514c
extern "C" ARM int func_ov025_021e514c(struct Struct_ov025_021e514c_2* self, struct Struct_ov000_0215440c_2* p1, int unused, void* p3) {
    GameState* bs = GameState::GetInstance();
    struct Struct_ov025_021e514c_5* nodeA = (struct Struct_ov025_021e514c_5*)func_ov000_02160094(p1, 0);
    struct Struct_ov025_021e514c* nodeB = (struct Struct_ov025_021e514c*)func_ov000_021600f8((struct Struct_ov000_0215440c*)p1, 0);
    int ids[8];
    int count = func_ov000_021820bc(p3, (int)p1, self->unknown_8_, (int)ids);
    Vector3fix result;
    __clear(&result, sizeof(result));
    int yaw = 0;
    int dir = 0;
    unsigned char flagA = 0;
    unsigned char var9 = 0;
    int* var10;
    int i;

    if (nodeA) {
        int a;
        if (nodeA->field20 <= 3) a = 1; else a = 0;
        flagA = a;
    }
    if (nodeB) {
        int b = 0;
        if (nodeB->unknown_e_ >= 0 && nodeB->unknown_e_ <= 3) b = 1;
        var9 = b;
    }

    switch (self->mode) {
    case 1:
        if (flagA) dir = 1; else dir = 2;
        break;
    case 2:
        if (var9) dir = 1; else dir = 2;
        break;
    case 5:
        if (flagA) dir = 2; else dir = 1;
        break;
    case 6:
        if (var9) dir = 2; else dir = 1;
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
        if (nodeA == 0 || nodeB == 0) return 1;
        GameObject* obj = bs->GetGameObjectByIndex(nodeB->unknown_e_);
        if (!obj) return 1;
        Struct_ov025_021e514c_3* o = (Struct_ov025_021e514c_3*)obj;
        fix32_t radius = obj->obj3D_.GetRadius();
        int rotY = o->rotation.y;
        if (self->mode == 4) self->vec.z = self->vec.z + (radius >> 1);
        else self->vec.z = self->vec.z - (radius >> 1);
        if (self->unknown_b_ == 1) {
            fix32_t h = obj->obj3D_.GetHeight() >> 1;
            self->vec.y = h;
            if (self->unknown_c_ < self->vec.y) self->vec.y = self->unknown_c_;
            else if (self->vec.y < self->unknown_10_) self->vec.y = self->unknown_10_;
        }
        Matrix4x3 m = RotationMatrixY(rotY);
        Vector3fix off;
        Mat4x3_ApplyToVector(&self->vec, &m, &off);
        Vector3fix pos = o->position;
        Vector3fix_Add(&off, &pos, &off);
        int angle = fix32ReduceAngle0To2Pi(rotY + 0x3244);
        for (i = 0, var10 = ids; i < count; i++, var10++) {
            GameObject* t = bs->GetGameObjectByIndex(*var10);
            if (t) {
                *(Vector3i*)(&t->obj3D_.position_.x) = *(Vector3i const*)((int*)&off);
                if (((Struct_ov025_021e514c_3*)t)->flags & 2) {
                    GameObject_SnapFacing((struct Obj02033874*)t, angle);
                } else {
                    func_0203db34((unsigned char*)t, 0, angle, 0);
                }
            }
        }
        return 1;
    }
    case 7: {
        int out[12];
        func_ov000_021820bc(p3, (int)p1, self->unknown_a_, (int)out);
        GameObject* obj = bs->GetGameObjectByIndex(out[0]);
        if (obj) {
            *(Vector3i*)((int*)&result) = *(Vector3i const*)(&obj->obj3D_.position_.x);
            yaw = ((Struct_ov025_021e514c_3*)obj)->rotation.y;
        }
        break;
    }
    case 10: {
        GameObject* obj = bs->GetGameObjectByIndex(nodeA->field20);
        if (obj) {
            *(Vector3i*)((int*)&result) = *(Vector3i const*)(&obj->obj3D_.position_.x);
            result.y = result.y + (obj->obj3D_.GetHeight() >> 1);
            yaw = ((Struct_ov025_021e514c_3*)obj)->rotation.y;
        }
        break;
    }
    case 8: {
        int* tgt = (int*)bs->GetCamera();
        if (!tgt) return 1;
        Struct_ov025_021e514c_4 L;
        *(Vector3i*)((int*)&L.b) = *(Vector3i const*)(tgt + 4);
        *(Vector3i*)((int*)&L.a) = *(Vector3i const*)(tgt + 1);
        Vector3fix_Subtract(&L.a, &L.b, &L.diff);
        unsigned char axis = self->unknown_a_;
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
            result.x = L.b.x + FxMul(L.diff.x, self->vec.x);
            result.y = L.b.y + FxMul(L.diff.y, self->vec.y);
            result.z = L.b.z + FxMul(L.diff.z, self->vec.z);
        }
        break;
    }
    case 9:
        *(Vector3i*)((int*)&result) = *(Vector3i const*)((int*)&self->vec);
        if (self->unknown_20_) yaw = 0x3244;
        break;
    }

    if (dir != 0) {
        result.y = 0;
        result.x = 0;
        switch (dir) {
        case 1:
            yaw = 0x3244;
            result.z = 0x2800;
            break;
        case 2:
            yaw = 0;
            result.z = -0x2800;
            break;
        }
    }
    for (i = 0, var10 = ids; i < count; i++, var10++) {
        GameObject* t = bs->GetGameObjectByIndex(*var10);
        if (t) {
            *(Vector3i*)(&t->obj3D_.position_.x) = *(Vector3i const*)((int*)&result);
            if (((Struct_ov025_021e514c_3*)t)->flags & 2) {
                GameObject_SnapFacing((struct Obj02033874*)t, yaw);
            } else {
                func_0203db34((unsigned char*)t, 0, yaw, 0);
            }
        }
    }
    return 1;
}
