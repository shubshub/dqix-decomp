#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/Animation.h"

struct Struct_0205563c { int unknown_0_[7]; };
struct Struct_02057fd8_4 {
    unsigned char unknown_0_[8];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_[0x2c];
    unsigned char unknown_39_, unknown_3a_, unknown_3b_;
    unsigned char unknown_3c_[0xac];
    Matrix4x3 unknown_e8_;
};
struct Struct_02055660 { void* unknown_0_; Struct_02057fd8_4* unknown_4_; int unknown_8_, unknown_c_; };
struct Struct_02057fd8_5 {
    unsigned char unknown_0_0_ : 1, unknown_0_1_ : 1, unknown_0_2_ : 1, unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1, unknown_0_5_ : 1, unknown_0_6_ : 1, unknown_0_7_ : 1;
};
struct Struct_02057fd8_6 {
    char unknown_0_[16];
    unsigned char unknown_10_;
    Struct_02057fd8_5 unknown_11_;
    short unknown_12_, unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_;
    short unknown_1e_;
    Vector3i unknown_20_, unknown_2c_, unknown_38_, unknown_44_;
};
union Struct_02057fd8_7 { Object3D unknown1_0_; Struct_0205563c unknown2_0_; Struct_02055660 unknown_0_; };
struct Struct_02057fd8 {
    Struct_02057fd8_7 unknown_0_;
    int unknown_ac_;
    short unknown_b0_, unknown_b2_, unknown_b4_, unknown_b6_;
    int unknown_b8_, unknown_bc_;
    Vector3i unknown_c0_;
    Struct_02057fd8_5 unknown_cc_;
    unsigned char unknown_cd_[3];
    int unknown_d0_;
};
struct Struct_02057fd8_2 {
    int unknown_0_, unknown_4_;
    unsigned char unknown_8_[0xc];
    Object3D unknown_14_;
    unsigned char unknown_c0_[0x128];
    int unknown_1e8_;
};
struct Struct_02057fd8_3 { unsigned char unknown_0_[8]; Struct_02057fd8 unknown_8_[16]; };
extern "C" void func_0205563c(Struct_0205563c*);
extern "C" int func_02055660(Struct_02055660*, int, int, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
ModelRenderContext* GetModel3DContext(Model3D*);
extern "C" void func_020e2fdc(RenderCommandHandler*);
extern const char data_020e7d90[];
extern const Vector3i data_020e7d84;

#define COPY_REACTION_FLAGS_02057FD8() \
    arg0->unknown_8_[var2].unknown_cc_.unknown_0_1_ = arg2->unknown_11_.unknown_0_0_ != 0; \
    arg0->unknown_8_[var2].unknown_cc_.unknown_0_2_ = arg2->unknown_11_.unknown_0_2_ != 0; \
    arg0->unknown_8_[var2].unknown_cc_.unknown_0_3_ = arg2->unknown_11_.unknown_0_1_ != 0; \
    arg0->unknown_8_[var2].unknown_cc_.unknown_0_4_ = arg2->unknown_11_.unknown_0_6_ != 0; \
    arg0->unknown_8_[var2].unknown_cc_.unknown_0_5_ = arg2->unknown_11_.unknown_0_7_ != 0

// USA: func_02057fd8
extern "C" ARM int func_02057fd8(Struct_02057fd8_3* arg0, Struct_02057fd8_2* arg1, Struct_02057fd8_6* arg2) {
    GameState* var0 = GameState::GetInstance();
    if (!arg1) return -1;
    if (!arg2) return -1;
    int var1 = -1;
    int var2;
    for (var2 = 0; var2 < 16; ++var2) {
        if (!var0->GetGameObjectByIndex(var2 + 0xd0)) {
            var1 = var2 + 0xd0;
            break;
        }
    }
    if (id == -1) return -1;
    manager->slots[index].type = node->type;
    if (node->type == 0) {
        Object3D* object = &manager->slots[index].payload.object;
        object->Initialize();
        manager->slots[index].reason = node->reason;
        node->model.ShallowCloneTo(object);
        object->position_ = config->position;
        object->rotation_ = config->rotation;
        object->SetScale(config->scale.x, config->scale.y, config->scale.z);
        if (config->animationName[0] == 0) object->SetAnimationByIndex(0, config->animationFlags);
        else object->SetAnimationByName(config->animationName, config->animationFlags);
        manager->slots[index].delay = config->delay;
        manager->slots[index].targetId = config->targetId;
        manager->slots[index].field16 = config->field16;
        manager->slots[index].duration = config->duration;
        manager->slots[index].field1a = config->field1a;
        manager->slots[index].field1c = config->field1c;
        manager->slots[index].velocity = config->velocity;
        COPY_REACTION_FLAGS_02057FD8();
        func_0200fd38(var0, var1, reinterpret_cast<GameObject*>(var3));
        if (var3->pModel_) {
            ModelRenderContext* var4 = GetModel3DContext(var3->pModel_);
            NSBXXNameList* var5 = var4->internalModel_ ? &var4->internalModel_->boneList_ : 0;
            int var6 = var5 ? NSBXXNameList_SearchIndex(var5, data_020e7d90) : -1;
            if (var6 >= 0) {
                SetModelRenderContextRenderCommandHook(var4, func_020e2fdc, 0, 7, 1);
            }
        }
    } else {
        arg0->unknown_8_[var2].unknown_d0_ = arg1->unknown_0_;
        arg0->unknown_8_[var2].unknown_b0_ = arg2->unknown_12_;
        arg0->unknown_8_[var2].unknown_b2_ = arg2->unknown_14_;
        arg0->unknown_8_[var2].unknown_b4_ = arg2->unknown_16_;
        arg0->unknown_8_[var2].unknown_b6_ = arg2->unknown_18_;
        arg0->unknown_8_[var2].unknown_b8_ = arg2->unknown_1a_;
        arg0->unknown_8_[var2].unknown_bc_ = arg2->unknown_1c_;
        arg0->unknown_8_[var2].unknown_c0_ = arg2->unknown_20_;
        COPY_REACTION_FLAGS_02057FD8();
        func_0200fd38(var0, var1, reinterpret_cast<GameObject*>(&arg1->unknown_14_));
        func_0205563c(&arg0->unknown_8_[var2].unknown_0_.unknown2_0_);
        func_02055660(&arg0->unknown_8_[var2].unknown_0_.unknown_0_, reinterpret_cast<int>(arg1->unknown_c0_), reinterpret_cast<int>(&arg1->unknown_14_), arg1->unknown_4_);
        Matrix4x3 var7 __attribute__((aligned(4)));
        Mat4x3_WriteIdentity(&var7);
        Mat4x3_ApplyTranslation(&var7, &var7, arg2->unknown_2c_.x, arg2->unknown_2c_.y, arg2->unknown_2c_.z);
        Struct_02057fd8_4* var8 = arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_;
        var8->unknown_e8_ = var7;
        Vector3i var9 = data_020e7d84;
        arg1->unknown_14_.SetScale(&var9);
        if (arg2->unknown_11_.unknown_0_3_ && arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_) arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_->unknown_c_ = 0;
        if (arg2->unknown_11_.unknown_0_4_ && arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_) arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_->unknown_8_ = arg2->unknown_18_;
        if (arg2->unknown_11_.unknown_0_5_ && arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_) arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_->unknown_39_ = 1;
        if (arg2->unknown_11_.unknown_0_6_ && arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_) arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_->unknown_3a_ = 1;
        if (arg2->unknown_11_.unknown_0_7_ && arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_) arg0->unknown_8_[var2].unknown_0_.unknown_0_.unknown_4_->unknown_3b_ = 1;
    }
    return var1;
}
