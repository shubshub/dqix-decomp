#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_ov006_021580b8 func_ov006_02159668
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Struct_0207fdcc_2;
struct Struct_ov006_02158054;
struct BackgroundGraphics;
struct Struct0200fb08;
struct Struct_0207fcb8;
struct Struct_0207fd00;
struct Struct_0207fd44_2;
struct Container0205a3d0;
struct Container0205a330;
struct Struct_020e28dc;
struct Struct_020e2794_2;
struct Struct_02075db0;
struct Struct_ov006_02154614;
struct Struct_ov006_02157a60;

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

struct SpriteAnimation {
    char unk_0[4];
    short x_;
    short y_;
    char unk_8[0xd];
    unsigned char flags_;
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

extern "C" int func_ov006_02158080(Struct_0207fdcc_2*, int);
extern "C" void func_ov006_02158054(void*, Struct_ov006_02158054*, int, int, unsigned char, unsigned char);
extern "C" void func_ov006_02154a60(Struct_ov006_02154614*);
extern "C" void Background_ClearMap(BackgroundGraphics*, void*);
extern "C" void* Background_GetScreen(BackgroundGraphics*, unsigned int);
extern "C" void func_0204b938(void*, void*, int, int, unsigned short);
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void func_0207fcb8(Struct_0207fcb8*);
extern "C" void func_0207fd00(Struct_0207fd00*);
extern "C" void func_0207fe80(void*, int, int, int);
extern "C" void Background_FlushMap(void*, int);
extern "C" void func_0207fd44(Struct_0207fd44_2*);
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
extern "C" SpriteAnimation* SpriteEntryList_Find(Container0205a3d0*, int);
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" void SpriteContext_DrawEntries(void*);
extern "C" int func_020e28dc(Struct_020e28dc*);
extern "C" void func_020e2794(Struct_020e2794_2*, void*);
extern "C" void func_ov006_021585c4(Struct_ov006_02157a60*);
extern "C" void func_ov006_0215868c(Struct_ov006_02157a60*);
extern "C" void func_ov006_021587d0(Struct_ov006_02157a60*);
extern "C" void func_ov006_02158914(Struct_ov006_02157a60*);
extern "C" void func_020807c4(void*, int, short*, short*);
extern "C" void SpriteContext_DrawSprite(void*, Sprite*);
extern "C" void* OamManager_GetInstance();
extern "C" unsigned int OamManager_GetSubOamBuffer(void*);
extern "C" void func_02076988(int*, int, int);
extern "C" void func_02075db0(Struct_02075db0*, int, int);

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
    int layout_[LOW_REGION(0x48,0x4c) / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[LOW_REGION(0x18,0xc)];
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

// USA: func_ov006_021580b8
extern "C" ARM void func_ov006_021580b8(Struct_ov006_02157a60* self)
{
    if (self->state_ != 0)
    {
        if (func_ov006_02158080((Struct_0207fdcc_2*)self->menu_, 0))
            func_ov006_02158054(self->renderer_, (Struct_ov006_02158054*)&self->sprites_[26], 2, 0x61, 0x64, 1);
        if (func_ov006_02158080((Struct_0207fdcc_2*)self->menu_, 1))
        {
            func_ov006_02158054(self->renderer_, (Struct_ov006_02158054*)&self->sprites_[27], 2, 0x74, 0x66, 1);
            if (self->unknown_42c_ > 0x1f)
                func_ov006_02158054(self->renderer_, (Struct_ov006_02158054*)&self->sprites_[28], 0x78, 0xb6, 0x63, 1);
        }
        else
        {
            self->unknown_42c_ = 0;
        }
        func_ov006_02154a60(self->pot_);
        Background_ClearMap((BackgroundGraphics*)self->subBackground_, 0);
        void* layer = Background_GetScreen((BackgroundGraphics*)self->subBackground_, self->background_);
        if (layer != 0)
            func_0204b938(self->subBackground_, layer, 0, 0, 0xffff);
#if !defined(jpn)
        if (self->background_ == 1)
        {
            unsigned int kind = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
            unsigned char tiles = 1;
            switch (kind)
            {
            case 2:
                tiles = 3;
                break;
            case 4:
                tiles = 4;
                break;
            case 3:
                tiles = 5;
                break;
            case 5:
                tiles = 6;
                break;
            }
            if (tiles > 1)
                Background_DrawScreen((BackgroundGraphics*)self->subBackground_, tiles, 0, 0, 0x16, 2, 9, 2, 0xffff);
        }
#endif
        void* menu = self->menu_;
        func_0207fcb8((Struct_0207fcb8*)menu);
        func_0207fd00((Struct_0207fd00*)menu);
        func_0207fe80(menu, 2, 1, 1);
        Background_FlushMap(self->subBackground_, 0);
        func_0207fd44((Struct_0207fd44_2*)menu);
        if (self->flags_ & 0x200)
        {
            self->unknown_42c_ = 0;
            SpriteEntryList_PlayAnimation((Container0205a3d0*)self->animations_, 1);
            SpriteAnimation* animation = SpriteEntryList_Find((Container0205a3d0*)self->animations_, 0);
            if (animation != 0)
                animation->flags_ &= ~8;
            animation = SpriteEntryList_Find((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
                animation->flags_ |= 8;
            SpriteEntryList_AdvanceAnimations((Container0205a330*)self->animations_, self->ticks_);
            animation = SpriteEntryList_Find((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
            {
                animation->x_ = 0xd7;
                animation->y_ = 0x96;
            }
            SpriteContext_DrawEntries(self->renderer_);
        }
        else
        {
            SpriteAnimation* animation = SpriteEntryList_Find((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
                animation->flags_ &= ~8;
        }
        if (self->message_ < 0)
        {
            if (self->choice_ != 0 && func_020e28dc((Struct_020e28dc*)self->choice_))
                func_020e2794((Struct_020e2794_2*)self->choice_, self->renderer_);
            else
                func_ov006_021585c4(self);
        }
        func_ov006_0215868c(self);
        func_ov006_021587d0(self);
        func_ov006_02158914(self);
        self->unknown_431_ = 0;
        self->unknown_430_ = 0;
    }
    if (self->unknown_3b4_ != 0)
    {
        unsigned char state = self->state_;
        if (state != 8 && state != 11)
            return;
        short x;
        short y;
        func_020807c4(self->menu_, 0x12, &x, &y);
        Sprite* sprite = &self->sprites_[17];
        if (sprite != 0)
        {
            sprite->x_ = (x + 4) << 12;
            sprite->y_ = (y + 4) << 12;
            sprite->unk_22 = 0x32;
            sprite->unknown_26_ = 1;
            SpriteContext_DrawSprite(self->renderer_, sprite);
        }
        unsigned int vram = OamManager_GetSubOamBuffer(OamManager_GetInstance());
        self->unknown_3b8_.unknown_4c_ = 0;
        self->unknown_3b8_.unk_14 = vram + 0x1b8;
        self->unknown_3b8_.unknown_44_ = 0x37;
        func_02076988((int*)&self->unknown_3b8_, 0x1000, 0x1000);
        func_02075db0((Struct_02075db0*)&self->unknown_3b8_, x + 8, y + 8);
    }
}
