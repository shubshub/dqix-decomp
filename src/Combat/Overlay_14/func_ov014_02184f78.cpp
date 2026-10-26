#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
    const char* unknown_4_;
    const char* name_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unk_14[6];
    short unknown_1a_;
    char unk_1c[4];
};

struct MonsterRecord {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};

struct Struct_ov014_021845ec {
    char unk_0[0x20];
};

struct Struct_ov014_02184dcc {
    char unk_0[0x1c];
    Struct_ov014_021845ec unknown_1c_;
    char unk_3c[0x48 - 0x3c];
    Struct_ov014_02184f78* unknown_48_;
    Struct_ov014_02184f78* unknown_4c_;
    MonsterRecord* unknown_50_;
    MonsterRecord* unknown_54_;
    void* layout_;
    void* texts_;
    char* unknown_60_[2];
    char* description_;
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    unsigned char state_;
    unsigned char unknown_7d_;
    unsigned char unknown_7e_;
    unsigned char unknown_7f_;
    unsigned char page_;
    unsigned char flags_;
    unsigned char unknown_82_0_ : 1;
    unsigned char unknown_82_1_ : 1;
    unsigned char unknown_82_2_ : 1;
    unsigned char unknown_82_3_ : 1;
    unsigned char unknown_82_4_ : 4;
    short unknown_84_;
    short unknown_86_[5];
    unsigned char unknown_90_[3];
    unsigned char unknown_93_;
    unsigned char unknown_94_;
};

extern "C" bool func_ov014_02188d10(Struct_ov014_021845ec* s);

// USA: func_ov014_02184f78
extern "C" ARM void func_ov014_02184f78(Struct_ov014_02184dcc* self, Struct_ov014_02184f78* monster, MonsterRecord* record, bool arg3) {
    if (self->state_ == 0)
        return;
    if (monster == NULL || record == NULL) {
        self->unknown_48_ = monster;
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->unknown_6c_ >= 0) {
        loader->RemoveTask(self->unknown_6c_);
        self->unknown_6c_ = -1;
    }
    for (int i = 0; i < 5; i++) {
        short var2 = self->unknown_86_[i];
        if (var2 >= 0) {
            BackgroundLoader::GetInstance()->RemoveTask(var2);
            self->unknown_86_[i] = -1;
        }
    }
    func_ov014_02188d10(&self->unknown_1c_);
    self->unknown_7f_ = 0;
    self->page_ = 0;
    self->unknown_48_ = monster;
    self->unknown_50_ = record;
    self->unknown_60_[0][0] = '\0';
    self->unknown_60_[1][0] = '\0';
    self->description_[0] = '\0';
    self->flags_ |= 1;
    self->flags_ &= ~8;
    self->unknown_82_2_ = arg3;
    if (!self->unknown_48_->unknown_13_1_) {
        self->flags_ &= ~1;
        self->flags_ |= 0x10;
        self->flags_ &= ~4;
        self->unknown_93_ = false;
        return;
    }

    self->flags_ &= ~0x10;
    if (self->unknown_70_ >= 0) {
        loader->RemoveTask(self->unknown_70_);
        self->unknown_70_ = -1;
    }
    self->unknown_7e_ = 0;
    self->unknown_93_ = true;
}
