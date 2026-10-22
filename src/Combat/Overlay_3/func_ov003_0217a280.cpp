#include <globaldefs.h>

struct Struct_0207fdcc_2 {
#if defined(jpn)
    char unknown1_0_[0x2a];
#else
    char unknown_0_[0x36];
#endif
    short unknown_36_;
};
extern "C" int func_020811d0(struct Struct_0207fdcc_2* arg0, int arg1);
extern "C" short func_02080468(void* arg0, int arg1);
extern "C" void func_020813ec(void* arg0, int arg1);
extern "C" void func_02080c68(void* arg0, int arg1, int arg2);
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* arg0, int arg1);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* arg0);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

extern "C" int func_ov003_021765b4(void* arg0);
extern "C" int func_ov003_021766e8(void* arg0);

struct Struct_ov003_0217a280 {
#if defined(jpn)
    char unknown_0_[0x808];
#else
    char unknown1_0_[0x88c];
#endif
    char unknown_88c_[0x89c - 0x88c];
    struct Struct_0207fdcc_2* unknown_89c_;
    char unknown_8a0_[0xff8 - 0x8a0];
    short* unknown_ff8_;
    short unknown_ffc_;
    short unknown_ffe_;
    char unknown_1000_[4];
    short unknown_1004_;
    char unknown_1006_[6];
    short unknown_100c_;
    char unknown_100e_[4];
    short unknown_1012_;
    char unknown_1014_[0x1036 - 0x1014];
    short unknown_1036_;
    char unknown_1038_[6];
    unsigned char unknown_103e_;
    unsigned char unknown_103f_;
    char unknown_1040_[6];
    unsigned short unknown_1046_;
};

// USA: func_ov003_0217a280
extern "C" ARM void func_ov003_0217a280(struct Struct_ov003_0217a280* arg0) {
    struct Struct_0207fdcc_2* var0 = arg0->unknown_89c_;
    if (arg0->unknown_103f_ == 0) {
        arg0->unknown_ffe_ = 2;
        if (func_020811d0(var0, arg0->unknown_ffe_) == 0) {
            if (arg0->unknown_1004_ < 0) {
                arg0->unknown_1004_ = func_02080468(var0, arg0->unknown_ffe_);
            }
            var0->unknown_36_ = arg0->unknown_1004_;
            func_020813ec(var0, arg0->unknown_ffe_);
            func_02080c68(var0, arg0->unknown_ffe_, 1);
            arg0->unknown_ffc_ = arg0->unknown_ffe_;
        }
        arg0->unknown_ffe_ = 0x10;
        if (arg0->unknown_100c_ < 0) {
            arg0->unknown_100c_ = func_02080468(var0, arg0->unknown_ffe_);
        }
        menu->selected = self->member100c;
        func_020813ec(menu, self->key);
        ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
        self->cursor = 0;
        self->step++;
    } else if (self->step == 1) {
        self->cursor = &self->member100c;
        if (func_ov003_021765b4(self)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)self->repeat);
            self->cursor = 0;
            switch (self->member100c) {
            case 0x76:
                arg0->unknown_ffc_ = arg0->unknown_ffe_;
                arg0->unknown_1036_ = 0xb;
                arg0->unknown_103e_ = 4;
                arg0->unknown_103f_ = 0;
                arg0->unknown_1046_ |= 0x20;
                break;
            case 0x77:
                arg0->unknown_ffc_ = arg0->unknown_ffe_;
                arg0->unknown_1036_ = 0xc;
                arg0->unknown_103e_ = 7;
                arg0->unknown_103f_ = 0;
                arg0->unknown_1012_ = -1;
                arg0->unknown_1046_ |= 0x20;
                break;
            }
        } else if (func_ov003_021766e8(arg0)) {
            func_0208203c((struct Struct_02081f20_2*)arg0->unknown_88c_);
            arg0->unknown_ff8_ = 0;
            arg0->unknown_1036_ = 0xa;
            arg0->unknown_103e_ = 1;
            arg0->unknown_103f_ = 0;
            func_0207fdcc(var0, arg0->unknown_ffe_);
        }
    }
}
