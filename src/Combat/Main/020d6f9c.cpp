#include <globaldefs.h>
#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"

struct Struct_0205563c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
};
struct Struct_020d6f9c_5 { unsigned char unknown_0_[0xe8]; Matrix4x3 unknown_e8_; };
struct Struct_02055660 { void* unknown_0_; void* unknown_4_; int unknown_8_; int unknown_c_; };

extern "C" void func_02059cc8(unsigned char* arg0);
extern "C" void func_0205563c(Struct_0205563c* arg0);
extern "C" int func_02055660(Struct_02055660* arg0, int arg1, int arg2, int arg3);
extern const Vector3fix data_020ee20c;
extern const Vector3fix data_020ee200;

struct Struct_020d6f9c_6 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_020d6f9c_7 {
    char unknown_0_[16];
    unsigned char unknown_10_;
    Struct_020d6f9c_6 unknown_11_;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    Vector3fix unknown_20_;
    Vector3fix unknown_2c_;
    Vector3fix unknown_38_;
    Vector3fix unknown_44_;

};

union Struct_020d6f9c {
    Object3D unknown_0_;
    Struct_0205563c unknown1_0_;
    Struct_02055660 unknown2_0_;
};

struct Struct_020d6f9c_2 {
    Struct_020d6f9c unknown_0_;
    int unknown_ac_;
    short unknown_b0_;
    short unknown_b2_;
    short unknown_b4_;
    short unknown_b6_;
    int unknown_b8_;
    int unknown_bc_;
    Vector3fix unknown_c0_;
    Struct_020d6f9c_6 unknown_cc_;
    unsigned char unknown_cd_[3];
    int unknown_d0_;
    int unknown_d4_;
};

struct Struct_020d6f9c_3 {
    int unknown_0_;
    unsigned char unknown_4_[0x10];
    Object3D unknown_14_;
    unsigned char unknown_c0_[0x128];
    int unknown_1e8_;
    Struct_020d6f9c_3* unknown_1ec_;
};

struct Struct_020d6f9c_4 {
    Struct_020d6f9c_2 unknown_0_[12];
    Struct_020d6f9c_3* unknown_a20_;
    unsigned short unknown_a24_;
    unsigned short unknown_a26_;
    SafeAllocator unknown_a28_;
};

// USA: func_020d6f9c
extern "C" ARM void func_020d6f9c(void* arg0, int arg1, int arg2) {
    Struct_020d6f9c_3* var0;
    Struct_020d6f9c_4* var1 = (Struct_020d6f9c_4*)arg0;
    if (var1->unknown_a28_.GetMaxPossibleAllocation() < 0x7e4) return;
    if (arg1 >= 0xc0) arg1 -= 0xbc;
    if (var1->unknown_a24_ & (1 << arg1)) {
        if (var1->unknown_0_[arg1].unknown_d0_ == arg2) return;
        func_02059cc8((unsigned char*)&var1->unknown_0_[arg1]);
        var1->unknown_0_[arg1].unknown_d4_ = 0;
    }
    Struct_020d6f9c_7 var2;
    var2.unknown_0_[0] = 0;
    var2.unknown_10_ = 1;
    var2.unknown_12_ = 0;
    var2.unknown_14_ = -1;
    var2.unknown_16_ = -1;
    var2.unknown_18_ = -1;
    var2.unknown_1a_ = -1;
    var2.unknown_1c_ = -0x1000;
    var2.unknown_20_.x = 0;
    var2.unknown_20_.y = 0;
    var2.unknown_20_.z = 0;
    var2.unknown_2c_.x = 0;
    var2.unknown_2c_.y = 0;
    var2.unknown_2c_.z = 0;
    var2.unknown_38_.x = 0;
    var2.unknown_38_.y = 0;
    var2.unknown_38_.z = 0;
    var2.unknown_44_.x = 0x1000;
    var2.unknown_44_.y = 0x1000;
    var2.unknown_44_.z = 0x1000;
    var2.unknown_11_.unknown_0_0_ = 0;
    var2.unknown_11_.unknown_0_1_ = 0;
    var2.unknown_11_.unknown_0_2_ = 1;
    var2.unknown_11_.unknown_0_3_ = 0;
    var2.unknown_11_.unknown_0_4_ = 0;
    var2.unknown_11_.unknown_0_5_ = 0;
    var2.unknown_11_.unknown_0_6_ = 0;
    var2.unknown_11_.unknown_0_7_ = 0;
    var2.unknown_10_ = 0;
    Vector3fix var3 = data_020ee20c;
    var2.unknown_44_ = var3;
    var1->unknown_a24_ |= 1 << arg1;
    var1->unknown_a26_ |= 1 << arg1;
    var0 = var1->unknown_a20_;
    while (var0 != NULL) {
        if (arg2 == var0->unknown_0_) break;
        var0 = var0->unknown_1ec_;
    }
    if (node == NULL) return;
    if (node->type == 0) {
        ReactionSlot020d6f9c* slot = &manager->slots[combatantId];
        slot->payload.object.Initialize();
        slot->payload.object.SetFlag16();
        slot->reason = node->reason;
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
        var4->unknown_b0_ = var2.unknown_12_;
        var4->unknown_b2_ = var2.unknown_14_;
        var4->unknown_b4_ = var2.unknown_16_;
        var4->unknown_b6_ = var2.unknown_18_;
        var4->unknown_b8_ = var2.unknown_1a_;
        var4->unknown_bc_ = var2.unknown_1c_;
        var4->unknown_c0_ = var2.unknown_20_;
        var4->unknown_cc_.unknown_0_1_ = var2.unknown_11_.unknown_0_0_ != 0;
    } else {
        var1->unknown_0_[arg1].unknown_d0_ = var0->unknown_0_;
        var1->unknown_0_[arg1].unknown_ac_ = var0->unknown_1e8_;
        var1->unknown_0_[arg1].unknown_b0_ = var2.unknown_12_;
        var1->unknown_0_[arg1].unknown_b2_ = var2.unknown_14_;
        var1->unknown_0_[arg1].unknown_b4_ = var2.unknown_16_;
        var1->unknown_0_[arg1].unknown_b6_ = var2.unknown_18_;
        var1->unknown_0_[arg1].unknown_b8_ = var2.unknown_1a_;
        var1->unknown_0_[arg1].unknown_bc_ = var2.unknown_1c_;
        var1->unknown_0_[arg1].unknown_c0_ = var2.unknown_20_;
        var1->unknown_0_[arg1].unknown_cc_.unknown_0_1_ = var2.unknown_11_.unknown_0_0_ != 0;
        func_0205563c(&var1->unknown_0_[arg1].unknown_0_.unknown1_0_);
        func_02055660(&var1->unknown_0_[arg1].unknown_0_.unknown2_0_, (int)&var0->unknown_c0_, (int)&var0->unknown_14_, (int)&var1->unknown_a28_);
        Matrix4x3 var7;
        Mat4x3_WriteIdentity(&var7);
        Mat4x3_ApplyTranslation(&var7, &var7, var2.unknown_2c_.x, var2.unknown_2c_.y, var2.unknown_2c_.z);
        Struct_020d6f9c_5* var8 = (Struct_020d6f9c_5*)var1->unknown_0_[arg1].unknown_0_.unknown2_0_.unknown_4_;
        var8->unknown_e8_ = var7;
        Vector3fix var9 = data_020ee200;
        var0->unknown_14_.SetScale(&var9);
    }
}
