#include <globaldefs.h>

struct Struct_ov014_02184f78;

struct MonsterRecord {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};

struct Struct_ov014_02184dcc {
    char unk_0[0x48];
    Struct_ov014_02184f78* unknown_48_;
    Struct_ov014_02184f78* unknown_4c_;
    MonsterRecord* unknown_50_;
    char unk_54[0x80 - 0x54];
    unsigned char page_;
    unsigned char flags_;
    char unknown_82_[0x90 - 0x82];
    unsigned char unknown_90_[3];
    unsigned char unknown_93_;
};

extern "C" void func_ov014_02184f78(Struct_ov014_02184dcc* self, Struct_ov014_02184f78* monster, MonsterRecord* record, bool arg3);

// USA: func_ov014_02184dcc
extern "C" ARM void func_ov014_02184dcc(Struct_ov014_02184dcc* self) {
    if (self->flags_ & 1)
        return;
    if (self->flags_ & 8)
        return;
    if (self->unknown_50_ == NULL || !self->unknown_50_->unknown_1_2_)
        return;
    unsigned char page = self->page_;
    func_ov014_02184f78(self, self->unknown_48_, self->unknown_50_, false);
    self->page_ = page + 1;
    self->page_ %= 2;
    self->unknown_90_[2] = true;
    self->flags_ |= 8;
}
