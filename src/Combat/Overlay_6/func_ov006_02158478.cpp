#if defined(jpn)
#define R(j,u) (j)
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Graphics/Background.h"
#if defined(jpn)
#define func_ov006_02154fe4 func_ov006_02156730
#endif

struct Struct_0207fdcc_2;
struct BackgroundGraphics;
struct Struct_ov006_02155480_2;
struct Struct_020e28dc;
struct Struct_020439b0;
struct Struct_020e2834;
struct Struct_0207fd88;
struct Struct_ov006_02154614;

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
    char unk_0[0x14];
    unsigned int unk_14;
    char unknown_18_[0x44 - 0x18];
    int unknown_44_;
    char unknown_48_[4];
    int unknown_4c_;
    char unk_50[0x70 - 0x50];
};


struct Canvas {
    char unk_0[0xac];
    short x_;
    short y_;
};

extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
extern "C" int func_ov006_02158080(Struct_0207fdcc_2*, int);
extern "C" Canvas* func_02081da8(Struct_0207fdcc_2*, int);
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" int Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void func_0204b938(void*, void*, int, int, unsigned short);
extern "C" void func_ov006_02154fe4(Struct_ov006_02154614*);
extern "C" void func_ov006_02155480(Struct_ov006_02155480_2*);
extern "C" int func_ov006_021570fc(Struct_ov006_02154614*, int);
extern "C" void Background_TransferMap(void*, int);
extern "C" int func_020e28dc(Struct_020e28dc*);
extern "C" void func_020e2cc4(Struct_020439b0*, int);
extern "C" void func_020e2834(Struct_020e2834*);
extern "C" void func_0207fd88(Struct_0207fd88*);

struct Struct_ov006_02157a60 {
    int unknown_0_;
    char** texts_;
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

// USA: func_ov006_02158478
extern "C" ARM void func_ov006_02158478(Struct_ov006_02157a60* self)
{
    if (self->state_ == 0)
        return;
    unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
    memset(screen, 0, 0x800);
    if (func_ov006_02158080((Struct_0207fdcc_2*)R(*(void**)((char*)self+0xc),self->menu_), 1))
    {
        Canvas* canvas = func_02081da8((Struct_0207fdcc_2*)R(*(void**)((char*)self+0xc),self->menu_), 1);
        if (canvas == 0)
            return;
        short x;
        short y;
        void* layer = (char*)canvas + 0xc8;
        if (layer == 0)
            return;
        x = canvas->x_;
        y = canvas->y_;
        BackgroundGraphics background;
        Background_Init((BackgroundGraphics*)&background);
        background.subScreen_ = 1;
        background.bgNumber_ = 0;
        background.map_ = screen;
        Background_SetScroll((BackgroundGraphics*)&background, 0, 0);
        func_0204b938(&background, layer, x, y, 0xffff);
    }
    func_ov006_02154fe4(R(*(Struct_ov006_02154614**)((char*)self+8),self->pot_));
    if (self->unknown_432_ != 0)
    {
        func_ov006_02155480((Struct_ov006_02155480_2*)R(*(Struct_ov006_02154614**)((char*)self+8),self->pot_));
        func_ov006_021570fc(R(*(Struct_ov006_02154614**)((char*)self+8),self->pot_), 1);
        self->unknown_432_ = 0;
    }
    Background_TransferMap(R((int*)((char*)self+0x4c),self->subBackground_), 0);
    if (R(*(void**)((char*)self+0x10),self->choice_) != 0)
    {
        void* window = *(void**)((char*)R(*(void**)((char*)self+0x10),self->choice_) + 0x10);
        func_020e2cc4((Struct_020439b0*)((char*)window + 0x28), func_020e28dc((Struct_020e28dc*)R(*(void**)((char*)self+0x10),self->choice_)));
        func_020e2834((Struct_020e2834*)R(*(void**)((char*)self+0x10),self->choice_));
    }
    if (R(*(void**)((char*)self+0xc),self->menu_) != 0)
        func_0207fd88((Struct_0207fd88*)R(*(void**)((char*)self+0xc),self->menu_));
}
