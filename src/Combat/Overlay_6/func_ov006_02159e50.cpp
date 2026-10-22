#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_02159e50_20 = 0xc, Enum_ov006_02159e50_720 = 0x2d8 };
#else
enum { Enum_ov006_02159e50_20 = 0x14, Enum_ov006_02159e50_720 = 0x2d0 };
#endif

struct Obj2081;
struct Obj0208203c;
struct SePlayer;
struct Obj020e25e8;

struct Struct_ov006_02157a60 {
    char unknown_0_[Enum_ov006_02159e50_20];
    Struct_0207fdcc_2* unknown_14_;
    Struct_020e25e8* unknown_18_;
    char unknown_1c_[0x28];
    short* unknown_44_;
    char unknown_48_[0x54];
    char unknown_9c_[Enum_ov006_02159e50_720];
    short unknown_36c_;
    short unknown_36e_;
    char unknown_370_[0xbc];
    signed char unknown_42c_;
};

extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
unsigned char SePlayer_Play(SePlayer* sound, int effect, int unk);
void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081* menu, int group);
void ResetWithSub0208203c(Obj0208203c* repeat);
void ResetSelectionState020e25e8(Obj020e25e8* choice);

extern "C" char g_sePlayer[];

// USA: func_ov006_02159e50
extern "C" ARM signed char func_ov006_02159e50(AlchemyMenu* self) {
    signed char result = 0;
    self->arrowTimer_ = 0;
    self->cursor_ = &self->choiceCursor_;
    if (func_ov006_02158a28(self) || g_keyManager.TestKeysPressed(0x200)) {
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
        result = -1;
        if (self->choiceCursor_ == 0x22)
            result = 1;
    } else if (func_ov006_02158b78(self)) {
        result = -1;
    }
    if (var0 != 0) {
        func_0207fdcc(arg0->unknown_14_, arg0->unknown_36e_);
        func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
        arg0->unknown_44_ = 0;
    }
    if (arg0->unknown_18_ != 0 && var0 != 0)
        func_020e25e8(arg0->unknown_18_);
    return var0;
}
