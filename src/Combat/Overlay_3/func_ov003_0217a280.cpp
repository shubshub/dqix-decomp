#include <globaldefs.h>

struct Struct_0207fdcc_2 {
#if defined(jpn)
    char unk_0[0x2a];
#else
    char unk_0[0x36];
#endif
    short selected;
};
extern "C" int func_020811d0(struct Struct_0207fdcc_2* obj, int key);
extern "C" short func_02080468(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);

struct Struct_ov003_0217a280 {
#if defined(jpn)
    char unk_0[0x808];
#else
    char unk_0[0x88c];
#endif
    char repeat[0x89c - 0x88c];
    struct Struct_0207fdcc_2* menu;
    char unknown_8a0_[0xff8 - 0x8a0];
    short* cursor;
    short unknown_ffc_;
    short key;
    char unknown_1000_[4];
    short unknown_1004_;
    char unknown_1006_[6];
    short unknown_100c_;
    char unknown_100e_[4];
    short unknown_1012_;
    char unknown_1014_[0x1036 - 0x1014];
    short nextState;
    char unknown_1038_[6];
    unsigned char mode;
    unsigned char step;
    char unknown_1040_[6];
    unsigned short flags;
};

// USA: func_ov003_0217a280
extern "C" ARM void func_ov003_0217a280(struct Struct_ov003_0217a280* self) {
    struct Struct_0207fdcc_2* menu = self->menu;
    if (self->step == 0) {
        self->key = 2;
        if (func_020811d0(menu, self->key) == 0) {
            if (self->unknown_1004_ < 0) {
                self->unknown_1004_ = func_02080468(menu, self->key);
            }
            menu->selected = self->unknown_1004_;
            func_020813ec(menu, self->key);
            func_02080c68(menu, self->key, 1);
            self->unknown_ffc_ = self->key;
        }
        self->key = 0x10;
        if (self->unknown_100c_ < 0) {
            self->unknown_100c_ = func_02080468(menu, self->key);
        }
        menu->selected = self->unknown_100c_;
        func_020813ec(menu, self->key);
        func_0208203c((struct Struct_02081f20_2*)self->repeat);
        self->cursor = 0;
        self->step++;
    } else if (self->step == 1) {
        self->cursor = &self->unknown_100c_;
        if (func_ov003_021765b4(self)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)self->repeat);
            self->cursor = 0;
            switch (self->unknown_100c_) {
            case 0x76:
                self->unknown_ffc_ = self->key;
                self->nextState = 0xb;
                self->mode = 4;
                self->step = 0;
                self->flags |= 0x20;
                break;
            case 0x77:
                self->unknown_ffc_ = self->key;
                self->nextState = 0xc;
                self->mode = 7;
                self->step = 0;
                self->unknown_1012_ = -1;
                self->flags |= 0x20;
                break;
            }
        } else if (func_ov003_021766e8(self)) {
            func_0208203c((struct Struct_02081f20_2*)self->repeat);
            self->cursor = 0;
            self->nextState = 0xa;
            self->mode = 1;
            self->step = 0;
            func_0207fdcc(menu, self->key);
        }
    }
}
