#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_02160010 data_ov006_02161364
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_021580b8 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[6];
    unsigned char unknown_22_;
    char unknown_23_[2];
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    char unknown_27_;
};

struct Struct_ov006_02156e54_2 {
    int unknown_0_[0x70 / 4];
};

struct Struct_ov006_02154614 {
    char unknown_0_[R(0x1054, 0x1258)];
    unsigned short unknown_1258_;
};

void ComputeShortPair_021e2bdc(void*, int, short*, short*);
extern "C" void SpriteContext_DrawSprite(void*, Sprite*);

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

// USA: func_ov006_0215868c
extern "C" ARM void func_ov006_0215868c(Struct_ov006_02157a60* arg0)
{
    if (!(arg0->unknown_394_ & 0x10))
        return;
    short x;
    short y;
    ComputeShortPair_021e2bdc(self->layout_, 0x78, &x, &y);
    Sprite* sprite = &self->sprites_[10];
    sprite->x_ = x << 12;
    sprite->y_ = y << 12;
    sprite->unk_22 = 0xc;
    sprite->unk_25 = 9;
    sprite->unk_26 = 2;
    if (self->chosenCounts_[0] > 1 || self->chosenCounts_[1] >= 1)
        sprite->unk_25 = 8;
    SpriteContext_DrawSprite(self->renderer_, sprite);
    ComputeShortPair_021e2bdc(self->layout_, 0x10, &x, &y);
    sprite = &self->sprites_[9];
    sprite->x_ = x << 12;
    sprite->y_ = y << 12;
    sprite->unk_22 = 0xe;
    sprite->unk_26 = 2;
    SpriteContext_DrawSprite(self->renderer_, sprite);
    ComputeShortPair_021e2bdc(self->layout_, 0x25, &x, &y);
    sprite = &self->sprites_[15];
    if (!(self->pot_->windowFlags_ & 0x800))
        sprite = &self->sprites_[16];
    sprite->x_ = x << 12;
    sprite->y_ = y << 12;
    sprite->unk_22 = 0x10;
    sprite->unk_26 = 2;
    SpriteContext_DrawSprite(self->renderer_, sprite);
}
