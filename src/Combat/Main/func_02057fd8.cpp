#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/Animation.h"

struct Struct205563c { int words[7]; };
struct Struct_02057fd8_4 {
    unsigned char unknown_0_[8];
    int duration;
    unsigned char enabled;
    unsigned char unknown_d_[0x2c];
    unsigned char unknown_39_, unknown_3a_, unknown_3b_;
    unsigned char unknown_3c_[0xac];
    Matrix4x3 matrix;
};
struct Struct_02055660 { void* field0; Struct_02057fd8_4* effect; int field8, fieldc; };
struct Struct_02057fd8_5 {
    unsigned char bit0 : 1, unknown_0_1_ : 1, bit2 : 1, unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1, unknown_0_5_ : 1, unknown_0_6_ : 1, unknown_0_7_ : 1;
};
struct Struct_02057fd8_6 {
    char animationName[16];
    unsigned char animationFlags;
    Struct_02057fd8_5 flags;
    short delay, targetId, unknown_16_, duration, unknown_1a_, field1c;
    short unknown_1e_;
    Vector3i unknown_20_, position, rotation, scale;
};
union Struct_02057fd8_7 { Object3D object; Struct205563c header; Struct_02055660 effect; };
struct Struct_02057fd8 {
    Struct_02057fd8_7 payload;
    int type;
    short delay, targetId, unknown_b4_, duration;
    int unknown_b8_, field1c;
    Vector3i unknown_c0_;
    Struct_02057fd8_5 flags;
    unsigned char unknown_cd_[3];
    int unknown_d0_;
};
struct Struct_02057fd8_2 {
    int unknown_0_, allocator;
    unsigned char unknown_8_[0xc];
    Object3D model;
    unsigned char unknown_c0_[0x128];
    int type;
};
struct Struct_02057fd8_3 { unsigned char unknown_0_[8]; Struct_02057fd8 slots[16]; };
extern "C" void func_0205563c(Struct205563c*);
extern "C" int func_02055660(Struct_02055660*, int, int, int);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
ModelRenderContext* GetModel3DContext(Model3D*);
extern "C" void func_020e2fdc(RenderCommandHandler*);
extern const char data_020e7d90[];
extern const Vector3i data_020e7d84;

#define COPY_REACTION_FLAGS_02057FD8() \
    manager->slots[index].flags.unknown_0_1_ = config->flags.bit0 != 0; \
    manager->slots[index].flags.bit2 = config->flags.bit2 != 0; \
    manager->slots[index].flags.unknown_0_3_ = config->flags.unknown_0_1_ != 0; \
    manager->slots[index].flags.unknown_0_4_ = config->flags.unknown_0_6_ != 0; \
    manager->slots[index].flags.unknown_0_5_ = config->flags.unknown_0_7_ != 0

// USA: func_02057fd8
extern "C" ARM int func_02057fd8(Struct_02057fd8_3* manager, Struct_02057fd8_2* node, Struct_02057fd8_6* config) {
    GameState* game = GameState::GetInstance();
    if (!node) return -1;
    if (!config) return -1;
    int id = -1;
    int index;
    for (index = 0; index < 16; ++index) {
        if (!game->GetGameObjectByIndex(index + 0xd0)) {
            id = index + 0xd0;
            break;
        }
    }
    if (id == -1) return -1;
    manager->slots[index].type = node->type;
    if (node->type == 0) {
        Object3D* object = &manager->slots[index].payload.object;
        object->Initialize();
        manager->slots[index].unknown_d0_ = node->unknown_0_;
        node->model.ShallowCloneTo(object);
        object->position_ = config->position;
        object->rotation_ = config->rotation;
        object->SetScale(config->scale.x, config->scale.y, config->scale.z);
        if (config->animationName[0] == 0) object->SetAnimationByIndex(0, config->animationFlags);
        else object->SetAnimationByName(config->animationName, config->animationFlags);
        manager->slots[index].delay = config->delay;
        manager->slots[index].targetId = config->targetId;
        manager->slots[index].unknown_b4_ = config->unknown_16_;
        manager->slots[index].duration = config->duration;
        manager->slots[index].unknown_b8_ = config->unknown_1a_;
        manager->slots[index].field1c = config->field1c;
        manager->slots[index].unknown_c0_ = config->unknown_20_;
        COPY_REACTION_FLAGS_02057FD8();
        func_0200fd38(game, id, reinterpret_cast<GameObject*>(object));
        if (object->pModel_) {
            ModelRenderContext* context = GetModel3DContext(object->pModel_);
            NSBXXNameList* names = context->internalModel_ ? &context->internalModel_->boneList_ : 0;
            int bone = names ? NSBXXNameList_SearchIndex(names, data_020e7d90) : -1;
            if (bone >= 0) {
                SetModelRenderContextRenderCommandHook(context, func_020e2fdc, 0, 7, 1);
            }
        }
    } else {
        manager->slots[index].unknown_d0_ = node->unknown_0_;
        manager->slots[index].delay = config->delay;
        manager->slots[index].targetId = config->targetId;
        manager->slots[index].unknown_b4_ = config->unknown_16_;
        manager->slots[index].duration = config->duration;
        manager->slots[index].unknown_b8_ = config->unknown_1a_;
        manager->slots[index].field1c = config->field1c;
        manager->slots[index].unknown_c0_ = config->unknown_20_;
        COPY_REACTION_FLAGS_02057FD8();
        func_0200fd38(game, id, reinterpret_cast<GameObject*>(&node->model));
        func_0205563c(&manager->slots[index].payload.header);
        func_02055660(&manager->slots[index].payload.effect, reinterpret_cast<int>(node->unknown_c0_), reinterpret_cast<int>(&node->model), node->allocator);
        Matrix4x3 matrix __attribute__((aligned(4)));
        Mat4x3_WriteIdentity(&matrix);
        Mat4x3_ApplyTranslation(&matrix, &matrix, config->position.x, config->position.y, config->position.z);
        Struct_02057fd8_4* effect = manager->slots[index].payload.effect.effect;
        effect->matrix = matrix;
        Vector3i scale = data_020e7d84;
        node->model.SetScale(&scale);
        if (config->flags.unknown_0_3_ && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->enabled = 0;
        if (config->flags.unknown_0_4_ && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->duration = config->duration;
        if (config->flags.unknown_0_5_ && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->unknown_39_ = 1;
        if (config->flags.unknown_0_6_ && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->unknown_3a_ = 1;
        if (config->flags.unknown_0_7_ && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->unknown_3b_ = 1;
    }
    return id;
}
