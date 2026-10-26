#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_0207fdcc_2 {
    char unk_0[R(0x2a, 0x36)];
    short cursor_;
};

struct Struct_02081f20_2;
struct Struct_ov006_021591ec;

struct Struct_ov006_02157a60 {
    char unk_0[R(0xc, 0x14)];
    Struct_0207fdcc_2* menu_;
    char unknown_18_[0x2c];
    short* cursor_;
    char unknown_48_[0x54];
    char unknown_9c_[0x64];
    char layout_[R(0x26c, 0x264)];
    short unknown_364_;
    char unknown_366_[0x8];
    short unknown_36e_;
    short item_;
    char unknown_372_[0x19];
    unsigned char count_;
    char unknown_38c_[0x8];
    unsigned short flags_;
};

extern "C" void func_02080c20(Struct_0207fdcc_2* menu, int flag);
extern "C" void func_ov006_021573c8(void* layout);
extern "C" unsigned short func_ov006_021591ec(Struct_ov006_021591ec* self);
extern "C" short func_02080468(void* menu, int group);
extern "C" void func_ov006_0215f4dc(Struct_ov006_02157a60* self);
extern "C" void func_ov006_0215f740(Struct_ov006_02157a60* self);
extern "C" void func_0208203c(Struct_02081f20_2* repeat);
extern "C" void func_02081ea4(Struct_0207fdcc_2* menu, int group, int flag);

// USA: func_ov006_0215943c
extern "C" ARM void func_ov006_0215943c(Struct_ov006_02157a60* self) {
    func_02080c20(self->menu_, 0);
    self->flags_ |= 0x10;
    self->item_ = -1;
    self->count_ = 0;
    func_ov006_021573c8(self->layout_);
    unsigned short size = func_ov006_021591ec((Struct_ov006_021591ec*)self);
    self->flags_ &= ~4;
    if (size > 8)
        self->flags_ |= 4;
    self->unknown_36e_ = 0x11;
    self->unknown_364_ = -1;
    if (self->unknown_364_ < 0)
        self->unknown_364_ = func_02080468(self->menu_, self->unknown_36e_);
    self->menu_->cursor_ = self->unknown_364_;
    func_ov006_0215f4dc(self);
    func_ov006_0215f740(self);
    func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
    self->cursor_ = 0;
    func_02081ea4(self->menu_, self->unknown_36e_, 0);
}
