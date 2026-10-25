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

struct Struct_0207fdcc_2;
struct Struct_020e28dc;
struct Struct_020e263c_2;
struct Struct_020e28f0;
struct Struct_ov006_02154614;

struct Struct_ov006_021580b8 {
    char unknown_0_[0x28];
};

struct Struct_ov006_02156e54_2 {
    int unknown_0_[0x70 / 4];
};

struct Struct_ov006_02158478;

Canvas* FindElementByByte0xc4_02081da8(Obj2081*, int);
int WindowPane_IsOpen(unsigned char*);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void GetLookAndTurnOffsets020809c4(void*, int, int, short*, short*);
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
void SetEntryPositionFromObject(WinObj020e28f0*, short, short);
extern "C" void SpriteContext_DrawEntries(void*);

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    void* unknown_8_;
    void* unknown_c_;
    Struct_ov006_02154614* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
    void* unknown_20_;
    Struct_ov006_021580b8* unknown_24_;
    void* unknown_28_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* unknown_44_;
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
    int unknown_54_[0x20 / 4];
    int unknown_74_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int unknown_ac_[0x54 / 4];
    int unknown_100_[0x4c / 4];
    int unknown_14c_[0xc / 4];
    int unknown_158_[0x18 / 4];
    char unknown_170_[0xc];
    int unknown_17c_[4][0x74 / 4];
#if defined(jpn)
    char unknown_344_[8];
#endif
    int unknown_34c_;
    int unknown_350_;
    int unknown_354_;
    int unknown_358_;
    short unknown_35c_;
    short unknown_35e_;
    short unknown_360_;
    short unknown_362_;
    short unknown_364_;
    short unknown_366_;
    short unknown_368_;
    short unknown_36a_;
    short unknown_36c_;
    short unknown_36e_;
    short unknown_370_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short unknown_37e_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char unknown_388_;
    unsigned char unknown_389_;
    unsigned char unknown_38a_;
    unsigned char unknown_38b_;
    unsigned char unknown_38c_[3];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short unknown_394_;
    unsigned char unknown_396_;
    unsigned char unknown_397_;
    unsigned char unknown_398_[3];
    int unknown_39c_;
    int unknown_3a0_;
    int unknown_3a4_;
    unsigned int unknown_3a8_;
    int unknown_3ac_;
    int unknown_3b0_;
    int unknown_3b4_;
    Struct_ov006_02156e54_2 unknown_3b8_;
    int unknown_428_;
    signed char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char unknown_42e_;
    unsigned char unknown_42f_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    unsigned char unknown_433_;
    unsigned char unknown_434_;
};

// USA: func_ov006_021585c4
extern "C" ARM void func_ov006_021585c4(Struct_ov006_02157a60* arg0)
{
    if (arg0->unknown_38f_ == 0 || arg0->unknown_44_ == 0)
        return;
    if (arg0->unknown_36e_ < 0)
        return;
    Struct_ov006_02158478* var0 = func_02081da8((Struct_0207fdcc_2*)arg0->unknown_14_, arg0->unknown_36e_);
    if (var0 == 0)
        return;
    if (!WindowPane_IsOpen((unsigned char*)canvas) || self->choice_ == 0)
        return;
    if (func_020e28dc((Struct_020e28dc*)arg0->unknown_18_))
        return;
    short x;
    short y;
    GetLookAndTurnOffsets020809c4(self->menu_, self->group_, *self->cursor_, &x, &y);
    UpdateEntryStateAndPosition((Ctx020e263c*)self->choice_, self->ticks_);
    x -= 0x10;
    y -= 3;
    SetEntryPositionFromObject((WinObj020e28f0*)self->choice_, x, y);
    SpriteContext_DrawEntries(self->renderer_);
}
