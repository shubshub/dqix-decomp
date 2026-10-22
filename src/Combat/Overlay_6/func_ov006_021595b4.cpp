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
#include "Input/Input.h"

struct Obj2081;
struct SePlayer;

struct Struct_ov006_02154614 {
    char unknown_0_[R(0x1054, 0x1258)];
    unsigned short unknown_1258_;
};

struct Struct_ov006_02157a60 {
    char unknown_0_[R(8, 0x10)];
    Struct_ov006_02154614* unknown_10_;
    Struct_0207fdcc_2* unknown_14_;
    char unknown_18_[0x2c];
    short* unknown_44_;
    char unknown_48_[0xb8];
    char unknown_100_[R(0x286, 0x27e)];
    short unknown_37e_;
    char unknown_380_[0xc];
    unsigned char unknown_38c_[3];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short unknown_394_;
};

extern "C" short func_ov023_021e29d0(void* layout);
extern "C" void func_ov006_0215f4dc(AlchemyMenu* self);
void SetElementFlag0x40_02081ea4(Obj2081* menu, int group, int flag);
extern "C" void func_ov006_021570fc(AlchemyPot* pot, int show);
unsigned char SePlayer_Play(SePlayer* sound, int effect, int unk);

extern "C" char g_sePlayer[];

// USA: func_ov006_021595b4
extern "C" ARM int func_ov006_021595b4(Struct_ov006_02157a60* arg0) {
    short var0 = func_ov023_021e29d0(arg0->unknown_100_);
    int var1 = var0 == 0x78 ? 1 : 0;
    int var2 = var0 == 0x25 ? 1 : 0;
    if (arg0->unknown_38c_[0] > 1 || arg0->unknown_38c_[1] >= 1) {
        var1 = (var1 | g_keyManager.TestKeysPressed(0x400)) ? 1 : 0;
        if (var1) {
            arg0->unknown_44_ = 0;
            arg0->unknown_38f_ = 7;
            arg0->unknown_390_ = 6;
            func_ov006_0215f4dc(arg0);
            func_02081ea4(arg0->unknown_14_, 0x10, 1);
            arg0->unknown_394_ &= ~0x10;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0xa;
            arg0->unknown_392_ = 0;
            return 1;
        }
    }
    if (var1)
        return 1;
    if (self->flags_ & 0x10) {
        if (g_keyManager.TestKeysPressed(0x300) || window) {
            AlchemyPot* pot = self->pot_;
            func_ov006_021570fc(pot, (pot->windowFlags_ & 0x800) ? 0 : 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            return 1;
        }
    }
    return 0;
}
