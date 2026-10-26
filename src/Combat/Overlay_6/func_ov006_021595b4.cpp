#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0207fdcc_2;
struct SePlayer;

struct Struct_ov006_02154614 {
    char unk_0[R(0x1054, 0x1258)];
    unsigned short unknown_1258_;
};

struct Struct_ov006_02157a60 {
    char unk_0[R(8, 0x10)];
    Struct_ov006_02154614* pot_;
    Struct_0207fdcc_2* menu_;
    char unknown_18_[0x2c];
    short* cursor_;
    char unknown_48_[0xb8];
    char layout_[R(0x286, 0x27e)];
    short message_;
    char unknown_380_[0xc];
    unsigned char unknown_38c_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short flags_;
};

extern "C" short func_ov023_021e29d0(void* layout);
extern "C" void func_ov006_0215f4dc(Struct_ov006_02157a60* self);
extern "C" void func_02081ea4(Struct_0207fdcc_2* menu, int group, int flag);
extern "C" void func_ov006_021570fc(Struct_ov006_02154614* arg0, int show);
extern "C" unsigned char SePlayer_Play(SePlayer* sound, int effect, int unk);

extern "C" char g_sePlayer[];

// USA: func_ov006_021595b4
extern "C" ARM int func_ov006_021595b4(Struct_ov006_02157a60* self) {
    short element = func_ov023_021e29d0(self->layout_);
    int names = element == 0x78 ? 1 : 0;
    int window = element == 0x25 ? 1 : 0;
    if (self->unknown_38c_[0] > 1 || self->unknown_38c_[1] >= 1) {
        names = (names | g_keyManager.TestKeysPressed(0x400)) ? 1 : 0;
        if (names) {
            self->cursor_ = 0;
            self->state_ = 7;
            self->step_ = 6;
            func_ov006_0215f4dc(self);
            func_02081ea4(self->menu_, 0x10, 1);
            self->flags_ &= ~0x10;
            self->flags_ |= 0x20;
            self->message_ = 0xa;
            self->unknown_392_ = 0;
            return 1;
        }
    }
    if (names)
        return 1;
    if (self->flags_ & 0x10) {
        if (g_keyManager.TestKeysPressed(0x300) || window) {
            Struct_ov006_02154614* var3 = self->pot_;
            func_ov006_021570fc(var3, (var3->unknown_1258_ & 0x800) ? 0 : 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            return 1;
        }
    }
    return 0;
}
