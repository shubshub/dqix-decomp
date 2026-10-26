#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

struct Struct_0204a4ac_3;

struct Struct_0204a4ac {
    char pad0[0x8];
    struct Struct_0204a4ac_3* text;
};

struct Struct_02107870 {
    unsigned short key;
    char pad2[0x36];
};

struct Struct_0204a4ac_2 {
    char pad0[0x21c];
    struct Struct_0204a4ac* owner;
    char pad1[0x4];
    char nameA[0x10];
    char nameB[0x10];
    char unknown_244_[0x10];
    int keyA;
    int unknown_258_;
    int unknown_25c_;
};

extern struct Struct_02107870 data_02107870[3];
extern struct Struct_02107870 data_021078a8;
extern struct Struct_02107870 data_021078e0;

// USA: func_0204a4ac
extern "C" ARM void func_0204a4ac(struct Struct_0204a4ac_2* self) {
    struct Struct_0204a4ac_3* text;

    if (self->owner == NULL || (text = self->owner->text) == NULL) return;

    if (self->unknown_258_ >= 0) ((Object3D*)self->owner)->UntrackBoneByIndex(self->keyA);
    if (self->unknown_258_ >= 0) ((Object3D*)self->owner)->UntrackBoneByIndex(self->unknown_258_);
    if (self->unknown_25c_ >= 0) ((Object3D*)self->owner)->UntrackBoneByIndex(self->unknown_25c_);

    if (self->keyA == -1) self->keyA = ((Model3D*)text)->GetBoneIndex(self->nameA);
    if (self->unknown_258_ == -1) self->unknown_258_ = ((Model3D*)text)->GetBoneIndex(self->nameB);
    if (self->unknown_25c_ == -1) self->unknown_25c_ = ((Model3D*)text)->GetBoneIndex(self->unknown_244_);

    if (self->unknown_258_ >= 0) {
        data_02107870[0].key = self->keyA;
        ((Object3D*)self->owner)->TrackBone((Object3D::TrackedBoneMatrix*)&data_02107870[0]);
    }
    if (self->unknown_258_ >= 0) {
        data_02107870[1].key = self->unknown_258_;
        ((Object3D*)self->owner)->TrackBone((Object3D::TrackedBoneMatrix*)&data_021078a8);
    }
    if (self->unknown_25c_ >= 0) {
        data_02107870[2].key = self->unknown_25c_;
        ((Object3D*)self->owner)->TrackBone((Object3D::TrackedBoneMatrix*)&data_021078e0);
    }
}
