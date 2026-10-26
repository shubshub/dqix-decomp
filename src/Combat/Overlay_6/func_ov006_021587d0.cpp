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

struct Sprite {
    char unk_0[0x14];
    int x_;
    int y_;
    char unk_1c[6];
    unsigned char unk_22;
    char unknown_23_[2];
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    char unknown_27_;
};

struct Struct_ov006_02156e54_2 {
    int unk_0[0x70 / 4];
};

struct Struct_ov006_02154614;

extern "C" {
void* memcpy(void*, const void*, unsigned int);
extern const short data_ov006_0215fff4[];
extern const short data_ov006_0215ffe2[];
extern const unsigned char data_ov006_0215ffc0[];
}

extern "C" void func_ov023_021e2bdc(void*, int, short*, short*);
extern "C" void SpriteContext_DrawSprite(void*, Sprite*);

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** texts_;
#endif
    void* canvasBuffer_;
    void* allocators_;
    Struct_ov006_02154614* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    Sprite* sprites_;
    void* animations_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* cursor_;
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    int subBackground_[0x20 / 4];
    int ingredients_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int renderer_[0x54 / 4];
    int layout_[0x4c / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
    int results_[4][0x74 / 4];
#if defined(jpn)
    char unknown_344_[8];
#endif
    int ticks_;
    int menuResult_;
    int task_;
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
    short item_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short message_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    unsigned char unknown_38c_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short flags_;
    unsigned char female_;
    unsigned char background_;
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

// USA: func_ov006_021587d0
extern "C" ARM void func_ov006_021587d0(Struct_ov006_02157a60* self)
{
    if (!(self->flags_ & 8))
        return;
    short ids[5];
    memcpy(ids, data_ov006_0215fff4, sizeof(ids));
    if (self->state_ == 10)
    {
        ids[0] = 0x1f;
        ids[1] = 0x20;
        ids[2] = 0x21;
        ids[3] = 0x22;
    }
    for (unsigned char i = 0; ids[i] >= 0; i++)
    {
        short x;
        short y;
        func_ov023_021e2bdc(self->layout_, ids[i], &x, &y);
        short index = data_ov006_0215ffe2[i];
        Sprite* sprite = &self->sprites_[index];
        if (index == 0xb && self->unknown_430_ != 0)
        {
            x++;
            y++;
        }
        if (index == 0xc && self->unknown_431_ != 0)
        {
            x++;
            y++;
        }
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = data_ov006_0215ffc0[i];
        SpriteContext_DrawSprite(self->renderer_, sprite);
    }
}
