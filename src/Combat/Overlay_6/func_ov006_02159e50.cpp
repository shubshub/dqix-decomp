#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_02159e50_20 = 0xc, Enum_ov006_02159e50_720 = 0x2d8 };
#else
enum { Enum_ov006_02159e50_20 = 0x14, Enum_ov006_02159e50_720 = 0x2d0 };
#endif

struct Struct_0207fdcc_2;
struct Struct_02081f20_2;
struct SePlayer;
struct Struct_020e25e8;

struct Struct_ov006_02157a60 {
    char unk_0[Enum_ov006_02159e50_20];
    Struct_0207fdcc_2* menu_;
    Struct_020e25e8* choice_;
    char unk_1c[0x28];
    short* cursor_;
    char unknown_48_[0x54];
    char unknown_9c_[Enum_ov006_02159e50_720];
    short unknown_36c_;
    short unknown_36e_;
    char unknown_370_[0xbc];
    signed char unknown_42c_;
};

extern "C" unsigned char func_ov006_02158a28(Struct_ov006_02157a60* self);
extern "C" unsigned char func_ov006_02158b78(Struct_ov006_02157a60* self);
extern "C" unsigned char SePlayer_Play(SePlayer* sound, int effect, int unk);
extern "C" void func_0207fdcc(Struct_0207fdcc_2* menu, int group);
extern "C" void func_0208203c(Struct_02081f20_2* repeat);
extern "C" void func_020e25e8(Struct_020e25e8* choice);

extern "C" char g_sePlayer[];

// USA: func_ov006_02159e50
extern "C" ARM signed char func_ov006_02159e50(Struct_ov006_02157a60* self) {
    signed char result = 0;
    self->unknown_42c_ = 0;
    self->cursor_ = &self->unknown_36c_;
    if (func_ov006_02158a28(self) || g_keyManager.TestKeysPressed(0x200)) {
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
        result = -1;
        if (self->unknown_36c_ == 0x22)
            result = 1;
    } else if (func_ov006_02158b78(self)) {
        result = -1;
    }
    if (result != 0) {
        func_0207fdcc(self->menu_, self->unknown_36e_);
        func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
        self->cursor_ = 0;
    }
    if (self->choice_ != 0 && result != 0)
        func_020e25e8(self->choice_);
    return result;
}
