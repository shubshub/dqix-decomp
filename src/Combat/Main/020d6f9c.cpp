#include <globaldefs.h>
#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"

struct Struct205563c {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};
struct Struct_020d6f9c_5 { unsigned char pad0[0xe8]; Matrix4x3 matrix; };
struct Struct_02055660 { void* field0; void* field4; int field8; int fieldc; };

extern "C" void func_02059cc8(unsigned char* obj);
extern "C" void func_0205563c(Struct205563c* obj);
extern "C" int func_02055660(Struct_02055660* obj, int data, int model, int allocator);
extern const Vector3fix data_020ee20c;
extern const Vector3fix data_020ee200;

struct Struct_020d6f9c_6 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_020d6f9c_7 {
    char animationName[16];
    unsigned char animationFlags;
    Struct_020d6f9c_6 flags;
    short delay;
    short targetId;
    short unknown_16_;
    short duration;
    short unknown_1a_;
    short field1c;
    Vector3fix unknown_20_;
    Vector3fix position;
    Vector3fix rotation;
    Vector3fix scale;

};

union Struct_020d6f9c {
    Object3D object;
    Struct205563c unknown1_0_;
    Struct_02055660 effect;
};

struct Struct_020d6f9c_2 {
    Struct_020d6f9c payload;
    int type;
    short delay;
    short unknown_b2_;
    short unknown_b4_;
    short duration;
    int unknown_b8_;
    int unknown_bc_;
    Vector3fix unknown_c0_;
    Struct_020d6f9c_6 flags;
    unsigned char unknown_cd_[3];
    int unknown_d0_;
    int active;
};

struct Struct_020d6f9c_3 {
    int unknown_0_;
    unsigned char pad4[0x10];
    Object3D model;
    unsigned char unknown_c0_[0x128];
    int type;
    Struct_020d6f9c_3* next;
};

struct Struct_020d6f9c_4 {
    Struct_020d6f9c_2 slots[12];
    Struct_020d6f9c_3* head;
    unsigned short mask;
    unsigned short unknown_a26_;
    SafeAllocator allocator;
};

// USA: func_020d6f9c
extern "C" ARM void func_020d6f9c(void* param0, int combatantId, int arg2) {
    Struct_020d6f9c_3* node;
    Struct_020d6f9c_4* manager = (Struct_020d6f9c_4*)param0;
    if (manager->allocator.GetMaxPossibleAllocation() < 0x7e4) return;
    if (combatantId >= 0xc0) combatantId -= 0xbc;
    if (manager->mask & (1 << combatantId)) {
        if (manager->slots[combatantId].unknown_d0_ == arg2) return;
        func_02059cc8((unsigned char*)&manager->slots[combatantId]);
        manager->slots[combatantId].active = 0;
    }
    Struct_020d6f9c_7 config;
    config.animationName[0] = 0;
    config.animationFlags = 1;
    config.delay = 0;
    config.targetId = -1;
    config.unknown_16_ = -1;
    config.duration = -1;
    config.unknown_1a_ = -1;
    config.field1c = -0x1000;
    config.unknown_20_.x = 0;
    config.unknown_20_.y = 0;
    config.unknown_20_.z = 0;
    config.position.x = 0;
    config.position.y = 0;
    config.position.z = 0;
    config.rotation.x = 0;
    config.rotation.y = 0;
    config.rotation.z = 0;
    config.scale.x = 0x1000;
    config.scale.y = 0x1000;
    config.scale.z = 0x1000;
    config.flags.bit0 = 0;
    config.flags.unknown_0_1_ = 0;
    config.flags.bit2 = 1;
    config.flags.unknown_0_3_ = 0;
    config.flags.unknown_0_4_ = 0;
    config.flags.unknown_0_5_ = 0;
    config.flags.unknown_0_6_ = 0;
    config.flags.unknown_0_7_ = 0;
    config.animationFlags = 0;
    Vector3fix var3 = data_020ee20c;
    config.scale = var3;
    manager->mask |= 1 << combatantId;
    manager->unknown_a26_ |= 1 << combatantId;
    node = manager->head;
    while (node != NULL) {
        if (arg2 == node->unknown_0_) break;
        node = node->next;
    }
    if (node == NULL) return;
    if (node->type == 0) {
        Struct_020d6f9c_2* slot = &manager->slots[combatantId];
        slot->payload.object.Initialize();
        slot->payload.object.SetFlag16();
        slot->unknown_d0_ = node->unknown_0_;
        slot->type = node->type;
        node->model.ShallowCloneTo(&slot->payload.object);
        slot->payload.object.position_ = config.position;
        slot->payload.object.SetScale(&config.scale);
        int rotationY = config.rotation.y;
        int rotationX = config.rotation.x;
        slot->payload.object.rotation_.x = rotationX;
        slot->payload.object.rotation_.y = rotationY;
        slot->payload.object.rotation_.z = 0x3244;
        if (config.animationName[0] == 0) {
            slot->payload.object.SetAnimationByIndex(0, config.animationFlags);
        } else {
            slot->payload.object.SetAnimationByName(config.animationName, config.animationFlags);
        }
        slot->delay = config.delay;
        slot->unknown_b2_ = config.targetId;
        slot->unknown_b4_ = config.unknown_16_;
        slot->duration = config.duration;
        slot->unknown_b8_ = config.unknown_1a_;
        slot->unknown_bc_ = config.field1c;
        slot->unknown_c0_ = config.unknown_20_;
        slot->flags.unknown_0_1_ = config.flags.bit0 != 0;
    } else {
        manager->slots[combatantId].unknown_d0_ = node->unknown_0_;
        manager->slots[combatantId].type = node->type;
        manager->slots[combatantId].delay = config.delay;
        manager->slots[combatantId].unknown_b2_ = config.targetId;
        manager->slots[combatantId].unknown_b4_ = config.unknown_16_;
        manager->slots[combatantId].duration = config.duration;
        manager->slots[combatantId].unknown_b8_ = config.unknown_1a_;
        manager->slots[combatantId].unknown_bc_ = config.field1c;
        manager->slots[combatantId].unknown_c0_ = config.unknown_20_;
        manager->slots[combatantId].flags.unknown_0_1_ = config.flags.bit0 != 0;
        func_0205563c(&manager->slots[combatantId].payload.unknown1_0_);
        func_02055660(&manager->slots[combatantId].payload.effect, (int)&node->unknown_c0_, (int)&node->model, (int)&manager->allocator);
        Matrix4x3 matrix;
        Mat4x3_WriteIdentity(&matrix);
        Mat4x3_ApplyTranslation(&matrix, &matrix, config.position.x, config.position.y, config.position.z);
        Struct_020d6f9c_5* effect = (Struct_020d6f9c_5*)manager->slots[combatantId].payload.effect.field4;
        effect->matrix = matrix;
        Vector3fix scale = data_020ee200;
        node->model.SetScale(&scale);
    }
}
