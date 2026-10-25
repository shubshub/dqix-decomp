#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "Graphics/LightingManager.h"
#include "Combat/CombatantMotion.h"

struct Struct_0203de84 { unsigned int unknown_0_[3]; };
struct Struct_0203de84_2;
struct Struct_020407c4 { unsigned int unknown_0_[3]; };
struct Struct_020407c4_2;
struct Struct_02040c2c_4;
struct Struct_02040c2c_5;
struct Struct_02028460_3 { int unknown_0_; int unknown_4_; int unknown_8_; };
struct Struct_02015438;

struct Struct_02040c2c_3 {
    Object3D unknown_0_;
    unsigned short unknown_ac_;
    char unknown_ae_[0xc0 - 0xae];
    unsigned int unknown_c0_;

    unsigned int inline_02040c2c_2() { return unknown_c0_; }
};

struct Struct_02040c2c_2 {
    int unknown_0_;
    Struct_0203de84 unknown_4_;
    unsigned char unknown_10_[0x1a];
    unsigned short unknown_2a_;
    unsigned char unknown_2c_[0x30];
    unsigned int unknown_5c_;
    int unknown_60_;
    int unknown_64_;
    int unknown_68_;
    Vector3i unknown_6c_;
    Vector3i unknown_78_;
    int unknown_84_;
    unsigned int unknown_88_;

    unsigned int inline_02040c2c() { return unknown_88_; }
};

struct Struct_02040c2c {
    char unknown_0_[0x1f];
    unsigned char unknown_1f_;
    char unknown_20_[0x48 - 0x20];
    struct Vector3i unknown_48_;
};

struct Obj0203c818;
extern "C" void func_0203c818(Obj0203c818*, void*, int, int);
extern "C" void Npc_PickWanderStep(struct Obj02040c2c* self, void* vec);
extern "C" int rand(void);
extern "C" int func_0202e800(void* arg0);
extern "C" void* func_0202ed6c(void* arg0);

extern "C" int func_02046b24(struct Struct_02015438** arg0);
extern "C" void func_0204117c(struct Struct_02040c2c_5* arg0, struct Struct_02028460_3* arg1);
extern "C" void func_02041298(struct Struct_02040c2c_4* arg0, int arg1);
extern "C" void func_020406f8(struct Struct_0203de84* arg0, struct Struct_0203de84_2* arg1);
extern "C" void func_020407c4(struct Struct_020407c4* arg0, struct Struct_020407c4_2* arg1);

// USA: func_02040c2c
extern "C" ARM void func_02040c2c(struct Struct_0203dd20* arg0, void* arg1, int arg2, int arg3) {
    struct Struct_0203de84 var0;
    struct Struct_0203de84 var1;
    struct Struct_020407c4 var2;
    struct Vector3i var3;
    struct Struct_0203de84 var4;

    if (arg0->unknown_14_ != 0) {
        func_0203c818(reinterpret_cast<Struct_0203c818_2*>(arg0->unknown_14_), arg1, arg2, arg3);
        struct LightingManager* var5 = LightingManager::GetInstance();
        if (var5 != 0) {
            arg0->unknown_14_->unknown_2a_ = var5->spriteDiffuseColor_;
        }
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)GetGameResources()->fieldTaskQueue_) != 4) {
            if (!(self->flags & 1) && !(self->flags & 0x20000)) {
                if (self->settings != 0 && self->settings->mode != 0) {
                    SpriteMotion02040c2c* a = self->spriteMotion;
                    if (!(a->flags & 1) && self->idleDelay < self->spriteMotion->GetIdleTicks()) {
                        motionPosition = a->position;
                        switch (self->settings->mode) {
                        case 7:
                        case 8:
                            Npc_PickWanderStep(self, &motionPosition);
                            break;
                        case 9:
                        case 10:
                            func_0204117c((struct Struct_02040c2c_5*)arg0, (struct Struct_02028460_3*)&var0);
                            break;
                        }
                        if (arg0->unknown_0_ & 8) {
                            arg0->unknown_4_ = 0;
                        } else {
                            arg0->unknown_4_ = rand() % 2000 + 2000;
                        }
                    }
                }
            }
        }
    } else if (arg0->unknown_18_ != 0) {
        func_02041298((struct Struct_02040c2c_4*)arg0->unknown_18_, arg2);
        if (arg0->unknown_18_->unknown_0_.pModel_ != 0 && arg0->unknown_18_->unknown_0_.pModel_->rawInternalModel_ != 0) {
            if (LightingManager::GetInstance() != 0) {
                arg0->unknown_18_->unknown_0_.SetDiffuseColor(LightingManager::GetInstance()->modelDiffuseColor_);
            }
        }
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)GetGameResources()->fieldTaskQueue_) != 4) {
            if (!(self->flags & 1) && !(self->flags & 0x20000)) {
                if (self->settings != 0 && self->settings->mode != 0) {
                    ModelEffect02040c2c* b = self->modelMotion;
                    if (!(b->flags_ac & 1)) {
                        if (self->idleDelay < self->modelMotion->GetIdleTicks()) {
                            switch (self->settings->mode) {
                            case 7:
                            case 8:
                                Npc_PickWanderStep(self, &b->object.position_);
                                break;
                            case 9:
                            case 10:
                                func_0204117c((struct Struct_02040c2c_5*)arg0, (struct Struct_02028460_3*)&var7->unknown_0_.position_);
                                break;
                            }
                            if (arg0->unknown_0_ & 8) {
                                arg0->unknown_4_ = 0;
                            } else {
                                arg0->unknown_4_ = rand() % 2000 + 2000;
                            }
                        }
                    }
                }
            }
        }
    }

    if (self->attachment != 0) {
        SelectVec3FromSources020406f8(&sourcePosition, (struct Node020406f8*)self);
        attachmentPosition = sourcePosition;
        FillVec3Default020407c4(&attachmentRotation, (struct Self020407c4*)self);
        struct Vector3i* pB = (struct Vector3i*)&attachmentRotation;
        attachmentPosition.v[1] += 0x1000;
        if (self->spriteMotion != 0) {
            unsigned char* camera = (unsigned char*)GameState::GetInstance()->GetCamera();
            GetPtrField0x58_0202ed6c(camera);
            float fx = (float)GetField0x78_0202e800(camera);
            fx *= 3.0f;
            int divisor = (int)fx;
            Vector3fix_Subtract(reinterpret_cast<Vector3i*>(camera + 0x10), reinterpret_cast<Vector3i*>(&attachmentPosition), &cameraOffset);
            Vector3fixDivideScalar(&cameraOffset, divisor, &cameraOffset);
            Vector3fix_Add(reinterpret_cast<Vector3i*>(&attachmentPosition), &cameraOffset, reinterpret_cast<Vector3i*>(&attachmentPosition));
        }
        Vector3fix_Add(reinterpret_cast<Vector3i*>(&var1), &arg0->unknown_c_->unknown_48_, reinterpret_cast<Vector3i*>(&var1));
        arg0->unknown_10_->position_ = *(struct Vector3i*)&var1;
        arg0->unknown_10_->rotation_ = *var8;
        arg0->unknown_10_->AdvanceEffects();
    }
    arg0->unknown_0_ &= ~0x20000u;
}
