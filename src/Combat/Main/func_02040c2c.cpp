#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "Graphics/LightingManager.h"
#include "Combat/CombatantMotion.h"

struct Struct_0203de84 { unsigned int v[3]; };
struct Node020406f8;
struct Struct_020407c4 { unsigned int v[3]; };
struct Struct_020407c4_2;
struct Struct_02040c2c_4;
struct Struct_02040c2c_5;
struct Struct_02028460_3 { int x; int y; int z; };
struct HeadNode02046b24;

struct Struct_02040c2c_3 {
    Object3D object;
    unsigned short unknown_ac_;
    char unknown_ae_[0xc0 - 0xae];
    unsigned int idleTicks;

    unsigned int inline_02040c2c_2() { return idleTicks; }
};

struct Struct_02040c2c_2 {
    int unknown0;
    Struct_0203de84 position;
    unsigned char unknown10[0x1a];
    unsigned short diffuseColor;
    unsigned char unknown_2c_[0x30];
    unsigned int flags;
    int angle;
    int targetAngle;
    int angularSpeed;
    Vector3i previousPosition;
    Vector3i targetPosition;
    int unknown84;
    unsigned int idleTicks;

    unsigned int inline_02040c2c() { return idleTicks; }
};

struct Struct_02040c2c {
    char unknown_0_[0x1f];
    unsigned char mode;
    char unknown_20_[0x48 - 0x20];
    struct Vector3i v48;
};

struct Obj0203c818;
extern "C" void NpcWalker_Update(Obj0203c818*, void*, int, int);
extern "C" void Npc_PickWanderStep(struct Obj02040c2c* self, void* vec);
extern "C" int rand(void);
extern "C" int Camera_GetOrbitDistance(void* p);
extern "C" void* Camera_GetPerspective(void* p);

extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** head);
extern "C" void func_0204117c(struct Struct_02040c2c_5* obj, struct Struct_02028460_3* arg1);
extern "C" void func_02041298(struct Struct_02040c2c_4* obj, int value);
extern "C" void func_020406f8(struct Struct_0203de84* out, struct Node020406f8* node);
extern "C" void func_020407c4(struct Struct_020407c4* out, struct Struct_020407c4_2* self);

// USA: func_02040c2c
extern "C" ARM void func_02040c2c(struct Obj02040c2c* self, void* context, int elapsedTicks, int movementTicks) {
    struct Struct_0203de84 motionPosition;
    struct Struct_0203de84 var1;
    struct Struct_020407c4 var2;
    struct Vector3i var3;
    struct Struct_0203de84 sourcePosition;

    if (self->spriteMotion != 0) {
        NpcWalker_Update(reinterpret_cast<Obj0203c818*>(self->spriteMotion), context, elapsedTicks, movementTicks);
        struct LightingManager* var5 = LightingManager::GetInstance();
        if (var5 != 0) {
            self->spriteMotion->diffuseColor = var5->spriteDiffuseColor_;
        }
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)GetGameResources()->fieldTaskQueue_) != 4) {
            if (!(self->flags & 1) && !(self->flags & 0x20000)) {
                if (self->settings != 0 && self->settings->mode != 0) {
                    Struct_02040c2c_2* a = self->spriteMotion;
                    if (!(a->flags & 1) && self->unknown_4_ < self->spriteMotion->inline_02040c2c()) {
                        motionPosition = a->position;
                        switch (self->settings->mode) {
                        case 7:
                        case 8:
                            Npc_PickWanderStep(self, &motionPosition);
                            break;
                        case 9:
                        case 10:
                            func_0204117c((struct Struct_02040c2c_5*)self, (struct Struct_02028460_3*)&motionPosition);
                            break;
                        }
                        if (self->flags & 8) {
                            self->unknown_4_ = 0;
                        } else {
                            self->unknown_4_ = rand() % 2000 + 2000;
                        }
                    }
                }
            }
        }
    } else if (self->unknown_18_ != 0) {
        func_02041298((struct Struct_02040c2c_4*)self->unknown_18_, elapsedTicks);
        if (self->unknown_18_->object.pModel_ != 0 && self->unknown_18_->object.pModel_->rawInternalModel_ != 0) {
            if (LightingManager::GetInstance() != 0) {
                self->unknown_18_->object.SetDiffuseColor(LightingManager::GetInstance()->modelDiffuseColor_);
            }
        }
        if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)GetGameResources()->fieldTaskQueue_) != 4) {
            if (!(self->flags & 1) && !(self->flags & 0x20000)) {
                if (self->settings != 0 && self->settings->mode != 0) {
                    Struct_02040c2c_3* b = self->unknown_18_;
                    if (!(b->unknown_ac_ & 1)) {
                        if (self->unknown_4_ < self->unknown_18_->inline_02040c2c_2()) {
                            switch (self->settings->mode) {
                            case 7:
                            case 8:
                                Npc_PickWanderStep(self, &b->object.position_);
                                break;
                            case 9:
                            case 10:
                                func_0204117c((struct Struct_02040c2c_5*)self, (struct Struct_02028460_3*)&b->object.position_);
                                break;
                            }
                            if (self->flags & 8) {
                                self->unknown_4_ = 0;
                            } else {
                                self->unknown_4_ = rand() % 2000 + 2000;
                            }
                        }
                    }
                }
            }
        }
    }

    if (self->unknown_10_ != 0) {
        func_020406f8(&sourcePosition, (struct Node020406f8*)self);
        var1 = sourcePosition;
        func_020407c4(&var2, (struct Struct_020407c4_2*)self);
        struct Vector3i* pB = (struct Vector3i*)&var2;
        var1.v[1] += 0x1000;
        if (self->spriteMotion != 0) {
            unsigned char* camera = (unsigned char*)GameState::GetInstance()->GetCamera();
            Camera_GetPerspective(camera);
            float fx = (float)Camera_GetOrbitDistance(camera);
            fx *= 3.0f;
            int var11 = (int)fx;
            Vector3fix_Subtract(reinterpret_cast<Vector3i*>(camera + 0x10), reinterpret_cast<Vector3i*>(&var1), &var3);
            Vector3fixDivideScalar(&var3, var11, &var3);
            Vector3fix_Add(reinterpret_cast<Vector3i*>(&var1), &var3, reinterpret_cast<Vector3i*>(&var1));
        }
        Vector3fix_Add(reinterpret_cast<Vector3i*>(&var1), &self->settings->v48, reinterpret_cast<Vector3i*>(&var1));
        self->unknown_10_->position_ = *(struct Vector3i*)&var1;
        self->unknown_10_->rotation_ = *pB;
        self->unknown_10_->AdvanceEffects();
    }
    self->flags &= ~0x20000u;
}
