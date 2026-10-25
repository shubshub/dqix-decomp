#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* Zone3D_GetInstance(void);

struct Struct_0201f170 {
    short unknown_0_;
    unsigned char unknown_2_;
    char unknown_3_[0x8 - 0x3];
    struct Struct_0201f170* unknown_8_;
};

struct Struct_0201ec00 {
    struct Struct_0201f170* unknown_0_;
    int unknown_4_;
};

struct Struct_0201f2cc_2 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0x20 - 0x4];
};

struct Struct_0201f2cc {
    struct Struct_0201ec00 unknown_0_;
    char unknown_8_[0xc - 0x8];
    struct Struct_0201f2cc_2* unknown_c_;
    int unknown_10_;
};

extern "C" struct Struct_0201f2cc_2* func_0201f2cc(struct Struct_0201f2cc* arg0, int arg1);
extern "C" struct Struct_0201f170* func_0201f170(struct Struct_0201ec00* arg0, int arg1);

struct Struct_ov001_021601f8_3 {
    char unknown_0_[0x54];
    NSBXXInternalModel* unknown_54_;
};

struct Struct_ov001_021601f8_4 {
    char unknown_0_[0x8];
    struct Struct_ov001_021601f8_3* unknown_8_;
};

struct Struct_ov001_021601f8_5 {
    short unknown_0_;
    unsigned short unknown_2_;
    union {
        struct Struct_ov001_021601f8_3* unknown_4_;
        struct Struct_ov001_021601f8_4* unknown1_4_;
    };
};

struct Struct_ov001_021601f8 {
    unsigned short unknown_0_;
    char unknown_2_[0x24 - 0x2];
    struct Struct_ov001_021601f8_5* unknown_24_;
    char unknown_28_[0x2c - 0x28];
    struct Struct_ov001_021601f8* unknown_2c_;
    struct Struct_ov001_021601f8* unknown_30_;
};

struct Struct_ov001_021601f8_2 {
    char unknown_0_[0x98];
    int unknown_98_;
};

// USA: func_ov001_021601f8
extern "C" ARM void func_ov001_021601f8(struct SceneNode_021601f8* node, struct Manager_1f2cc* manager) {
    Zone3D_GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    struct RenderObj_021601f8* obj = node->obj;
    int timeOfDay = ((struct LightingView_021601f8*)lighting)->timeOfDay;
    struct Element_1f2cc* element = FindElementByHalfwordKey_0201f2cc(manager, node->key);
    struct Entry_1f170* entry = FindEntryBySignedId_0201f170(&manager->entryList, element->entryId);
    struct Entry_1f170* variant = entry->next;
    while (variant != NULL) {
        if (variant->id == timeOfDay) {
            entry = variant;
            break;
        }
        var5 = var5->unknown_8_;
    }

    if (var1 != NULL) {
        if (var1->unknown_0_ == 0 && var1->unknown_4_ != NULL && var1->unknown_4_->unknown_54_ != NULL && !(var1->unknown_2_ & 1)) {
            if (var4 != NULL && !(var4->unknown_2_ & 0x20)) {
                var0->ModelTransformTintBrightnessContrast(var1->unknown_4_->unknown_54_);
                var1->unknown_2_ |= 1;
            }
        } else if (var1->unknown_0_ == 2 && var1->unknown1_4_ != NULL && var1->unknown1_4_->unknown_8_ != NULL && var1->unknown1_4_->unknown_8_->unknown_54_ != NULL &&
                   !(var1->unknown_2_ & 1)) {
            if (var4 != NULL && !(var4->unknown_2_ & 0x20)) {
                var0->ModelTransformTintBrightnessContrast(var1->unknown1_4_->unknown_8_->unknown_54_);
                var1->unknown_2_ |= 1;
            }
        }
    }

    if (arg0->unknown_2c_ != NULL) {
        func_ov001_021601f8(arg0->unknown_2c_, arg1);
    }
    if (arg0->unknown_30_ != NULL) {
        func_ov001_021601f8(arg0->unknown_30_, arg1);
    }
}
