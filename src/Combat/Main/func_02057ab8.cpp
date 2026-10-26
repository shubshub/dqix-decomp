#include <globaldefs.h>

#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "World/Object3D.h"

struct Model3D;
void* GetModel3DContext(Model3D*);
Matrix4x3 RotationMatrixY(int angle);
void Vector3fixMultiply(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
extern "C" void func_02059f54(void* elem, int idx);

struct Struct_02057ab8 {
    char pad0[0xc4];
    Vector3fix unknown_c4_;
    Vector3fix unknown_d0_;
    Vector3fix unknown_dc_;
    Matrix4x3 unknown_e8_;
};

struct Struct_02057ab8_2 {
    char pad0[4];
    struct Struct_02057ab8* other;
    char pad1[0x44 - 0x8];
    Vector3fix pos;
    Vector3fix dir;
    char pad2[0xac - 0x5c];
    int unknown_ac_;
    short unknown_b0_;
    short unknown_b2_;
    short unknown_b4_;
    char pad3[0xd4 - 0xb6];
};

struct Struct_02057ab8_3 {
    char hdr[8];
    struct Struct_02057ab8_2 elems[16];
};

extern "C" ARM void func_02057ab8(struct Struct_02057ab8_3* c, int id);

// USA: func_02057ab8
extern "C" ARM void func_02057ab8(struct Struct_02057ab8_3* c, int id) {
    GameState* gs = GameState::GetInstance();
    int i;
    if (id < 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        struct Struct_02057ab8_2* e = &c->elems[i];
        if (id != e->unknown_b2_) continue;
        if (e->unknown_b0_ > 0) continue;
        void* obj = gs->GetGameObjectByIndex(e->unknown_b2_);
        if (obj == 0) {
            e->unknown_b2_ = -1;
            continue;
        }
        void* var4 = *(void**)((char*)obj + 8);
        if (var4 == 0) {
            e->unknown_b2_ = -1;
            continue;
        }
        ModelRenderContext* ctx = (ModelRenderContext*)GetModel3DContext((Model3D*)var4);
        if (ctx == 0) {
            e->unknown_b2_ = -1;
            continue;
        }

        Matrix4x3 m;
        Mat4x3_WriteIdentity(&m);
        Vector3fix pos = *(Vector3fix*)((char*)obj + 0x44);
        Vector3fix dir = *(Vector3fix*)((char*)obj + 0x50);
        Vector3fix scale = ((Object3D*)obj)->GetScale();
        int flag = 0;
        if (e->unknown_b4_ > -1) {
            if (GetModelBonePositionAndDirectionMatrices(ctx, (Matrix4x3*)flag, (Matrix3x3*)flag, (unsigned int)e->unknown_b4_)) {
                const Matrix4x3* var11 = RenderConfig::GetInverseViewMatrix();
                GetCurrentPositionAndDirectionMatrices(&m, (Matrix3x3*)flag);
                Mat4x3_Multiply(&m, var11, &m);
                flag = 1;
            }
        }
        if (e->unknown_ac_ == 0) {
            Vector3fix var12 = e->pos;
            Vector3fix var13 = e->dir;
            Vector3fix ss = ((Object3D*)e)->GetScale();
            Matrix4x3 var15;
            Vector3fix tv;
            var15 = RotationMatrixY(dir.y);
            Mat4x3_ApplyToVector(&var12, &var15, &tv);
            Vector3fix_Add(&pos, &tv, &pos);
            Vector3fixMultiply(&scale, &ss, &scale);
            e->pos = pos;
            e->dir = dir;
            ((Object3D*)e)->SetScale(&scale);
            func_02059f54(e, i + 0xd0);
            func_02057ab8(c, i + 0xd0);
            e->pos = var12;
            e->dir = var13;
            ((Object3D*)e)->SetScale(&ss);
        } else if (e->unknown_ac_ == 1) {
            struct Struct_02057ab8* o = e->other;
            if (o != 0) {
                if (flag == 0) {
                    o->unknown_c4_ = pos;
                    o->unknown_d0_ = dir;
                    o->unknown_dc_ = scale;
                } else {
                    pos.x = m.translation.x;
                    pos.y = m.translation.y;
                    pos.z = m.translation.z;
                    Mat4x3_ApplyScale(&m, &m, 0xf627, 0xf627, 0xf627);
                    m.translation.x = pos.x;
                    m.translation.y = pos.y;
                    m.translation.z = pos.z;
                    o->unknown_e8_ = m;
                }
            }
            func_02059f54(e, i + 0xd0);
            func_02057ab8(c, i + 0xd0);
        }
    }
}
