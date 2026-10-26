#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_020da31c_3 {
    unsigned char padding[8];
    int objectIndex;
    unsigned char unknown_c_;
    unsigned char flags, kind, ticks, unknown_10_, started;
};
struct Struct_02078398_2 {
    char filename[16];
    unsigned char enabled, flags;
    short unknown_12_, objectIndex, unknown_16_, unknown_18_, unknown_1a_, field_0x1c;
    short unknown_1e_;
    int unknown_20_, unknown_24_, field_0x28;
    Vector3i position, rotation, scale;
};
struct Struct_020da31c {
    Object3D object;
    short unknown_ac_, direction, unknown_b0_, timer;
};
struct Struct_020da31c_2 {
    unsigned char padding[0xe8];
    Matrix4x3 matrix;
};
struct Struct_0205a180 {
    unsigned int field_0x0;
    Struct_020da31c_2* output;
};
extern "C" void* func_02057924();
extern "C" void func_02078484(Struct_02078398_2*);
extern "C" void func_02057fb4(void*, int, void*);
extern "C" void* func_02058658(void*, int);
extern "C" void func_0205a180(Struct_0205a180*);
extern "C" void SePlayer_PlayExtra(void*, int, int);
extern char data_020f2884[], data_020f2887[], g_sePlayer[];

// USA: func_020da31c
extern "C" ARM void func_020da31c(Struct_020da31c_3* event) {
    void* manager = func_02057924();
    GameState* game = GameState::GetInstance();
    if (!manager || !game) return;
    switch (event->kind) {
    case 1: {
        GameObject* actor = game->GetWanderingMonsterByIndex(event->objectIndex);
        if (!actor) return;
        if (!(event->flags & 8)) {
            Struct_02078398_2 effect;
            event->flags |= 8;
            func_02078484(&effect);
            int index = event->objectIndex;
            effect.objectIndex = index;
            effect.enabled = 0;
            sprintf(effect.filename, data_020f2884, data_020f2887);
            effect.position.x = 0;
            effect.position.y = 0;
            effect.position.z = 0;
            effect.scale.x = 0x1000;
            effect.scale.y = 0x1000;
            effect.scale.z = 0x1000;
            func_02057fb4(manager, 0x14, &effect);
        }
        int timer = ((Struct_020da31c*)actor)->timer;
        int distance = fix32SignedAngleDistance(actor->obj3D_.rotation_.y, ((Struct_020da31c*)actor)->direction);
        if (timer > 0x3d || distance != 0) ++event->ticks;
        if (event->ticks < 3) return;
        event->ticks = 0;
        Struct_02078398_2 effect;
        func_02078484(&effect);
        effect.position = actor->obj3D_.position_;
        effect.rotation = actor->obj3D_.rotation_;
        effect.scale.x = 200;
        effect.scale.y = 200;
        effect.scale.z = 200;
        sprintf(effect.filename, data_020f2884, data_020f2887);
        effect.flags |= 0x40;
        func_02057fb4(manager, 0x15, &effect);
        break;
    }
    case 2: {
        GameObject* actor = game->GetGameObjectByIndex(event->objectIndex);
        if (!actor) return;
        if (!(event->flags & 8)) {
            Struct_02078398_2 effect;
            event->flags |= 8;
            func_02078484(&effect);
            int index = event->objectIndex;
            effect.objectIndex = index;
            effect.enabled = 0;
            sprintf(effect.filename, data_020f2884, data_020f2887);
            effect.position.x = 0;
            effect.position.y = 0;
            effect.position.z = 0;
            effect.scale.x = 0x3000;
            effect.scale.y = 0x1000;
            effect.scale.z = 0x3000;
            func_02057fb4(manager, 0x14, &effect);
        }
        if (++event->ticks < 7) return;
        event->ticks = 0;
        Struct_02078398_2 effect;
        func_02078484(&effect);
        effect.position = actor->obj3D_.position_;
        effect.rotation = actor->obj3D_.rotation_;
        effect.scale.x = 225;
        effect.scale.y = 225;
        effect.scale.z = 225;
        sprintf(effect.filename, data_020f2884, data_020f2887);
        func_02057fb4(manager, 0x15, &effect);
        break;
    }
    case 3: {
        GameObject* actor = game->GetWanderingMonsterByIndex(event->objectIndex);
        if (!actor) return;
        Struct_02078398_2 effect;
        Struct_0205a180* record = (Struct_0205a180*)func_02058658(manager, 0xd0);
        if (record && record->output) {
            Struct_020da31c_2* output = record->output;
            Matrix4x3 result, world, offset, rotation;
            Mat4x3_WriteIdentity(&result);
            Mat4x3_WriteIdentity(&world);
            Mat4x3_ApplyTranslation(&world, &world, actor->obj3D_.position_.x,
                actor->obj3D_.position_.y, actor->obj3D_.position_.z);
            Mat4x3_WriteIdentity(&offset);
            Mat4x3_ApplyTranslation(&offset, &offset, 0, 0x3000, 0x800);
            rotation = RotationMatrixY(((Struct_020da31c*)actor)->direction);
            Mat4x3_Multiply(&offset, &rotation, &result);
            Mat4x3_Multiply(&result, &world, &result);
            output->matrix = result;
        }
        if (!(event->flags & 0x10)) {
            event->ticks = 0;
            event->unknown_10_ = 0;
            return;
        }
        ++event->ticks;
        if (event->unknown_10_ < 1 && (event->flags & 0x10)) {
            if (!event->started) {
                func_02078484(&effect);
                effect.position = actor->obj3D_.position_;
                effect.rotation = actor->obj3D_.rotation_;
                effect.unknown_18_ = 90;
                effect.scale.x = 0x199;
                effect.scale.y = 0x199;
                effect.scale.z = 0x199;
                sprintf(effect.filename, data_020f2884, data_020f2887);
                effect.flags |= 0xb8;
                func_02057fb4(manager, 0x16, &effect);
                event->started = 1;
                SePlayer_PlayExtra(g_sePlayer, 1, 0);
            } else {
                Struct_0205a180* active = (Struct_0205a180*)func_02058658(manager, 0xd0);
                if (active) {
                    func_0205a180(active);
                    SePlayer_PlayExtra(g_sePlayer, 1, 0);
                }
            }
            ++event->unknown_10_;
        } else if (event->ticks >= 85) {
            event->flags &= ~0x10;
        }
        break;
    }
    }
}
