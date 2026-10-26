#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_0215f3d8 func_ov006_021607f8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_020e28dc;
struct Struct_0207fdcc_2;

struct Sprite {
    char unk_0[0x28];
};

struct Struct_ov006_02156e54_2 {
    int unk_0[0x70 / 4];
};

struct Struct_ov006_02154614;

extern "C" int func_020e28dc(Struct_020e28dc*);
extern "C" int func_020e2984(struct Struct_020e28dc* window);
extern "C" int func_02080d54(Struct_0207fdcc_2*, int, int, int);

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
    unsigned char** unknown1_4c_;
    unsigned short* sizes_;
#if defined(jpn)
    char unknown_4c_[8];
#endif
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

// USA: func_ov006_02158b78
extern "C" ARM unsigned char func_ov006_02158b78(Struct_ov006_02157a60* self)
{
    unsigned char cancelled = 0;
    if (g_keyManager.TestKeysPressed(2))
        cancelled = 1;
    if (self->choice_ != 0 && func_020e28dc((Struct_020e28dc*)self->choice_))
    {
        if (func_020e2984((struct Struct_020e28dc*)self->choice_))
            cancelled = 1;
    }
    else if (g_touchInput.pressed_)
    {
        int x;
        int y;
        g_touchInput.GetTouchPoint(&x, &y);
        if (!func_02080d54((Struct_0207fdcc_2*)self->menu_, self->unknown_36e_, (short)x, (short)y))
            cancelled = 1;
    }
    return cancelled;
}
