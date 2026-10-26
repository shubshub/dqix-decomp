#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_ov006_021580b8 func_ov006_02159668
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Obj2081;
struct SetFieldsAndCall02158054Struct;
struct BackgroundGraphics;
struct Struct0200fb08;
struct Obj0207fcb8;
struct Obj0207fd00;
struct Cont0207fd44;
struct Container0205a3d0;
struct Container0205a330;
struct Outer020e28dc;
struct Struct020e2794;
struct Struct02075db0;
struct AlchemyPot;
struct AlchemyMenu;

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

struct Struct_ov006_021580b8_2 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[0xd];
    unsigned char unknown_15_;
};

struct Struct_ov006_02156e54_2 {
    char unknown_0_[0x14];
    unsigned int unknown_14_;
    char unknown_18_[0x44 - 0x18];
    int unknown_44_;
    char unknown_48_[4];
    int unknown_4c_;
    char unknown_50_[0x70 - 0x50];
};

int CheckElementFlag_02158080_02158080(Obj2081*, int);
void SetFieldsAndCall02158054(void*, SetFieldsAndCall02158054Struct*, int, int, unsigned char, unsigned char);
extern "C" void func_ov006_02154a60(AlchemyPot*);
void Background_ClearMap(BackgroundGraphics*, void*);
void* Background_GetScreen(BackgroundGraphics*, unsigned int);
void CallFunc0204b620IfField0x14_0204b938(void*, void*, int, int, unsigned short);
int GameState_GetLanguage(Struct0200fb08*);
void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
void ClearAllBuffers0207fcb8(Obj0207fcb8*);
void CallFunc0204c8f0OverEntries0207fd00(Obj0207fd00*);
extern "C" void func_0207fe80(void*, int, int, int);
extern "C" void Background_FlushMap(void*, int);
void CallFunc0204b04cOverList0x2c(Cont0207fd44*);
void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
SpriteAnimation* SpriteEntryList_Find(Container0205a3d0*, int);
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" void SpriteContext_DrawEntries(void*);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void UpdateEntryIfActive020e2794(Struct020e2794*, void*);
extern "C" void func_ov006_021585c4(AlchemyMenu*);
extern "C" void func_ov006_0215868c(AlchemyMenu*);
extern "C" void func_ov006_021587d0(AlchemyMenu*);
extern "C" void func_ov006_02158914(AlchemyMenu*);
void GetSublistEntryScaledXY_020807c4(void*, int, short*, short*);
extern "C" void SpriteContext_DrawSprite(void*, Sprite*);
extern "C" void* OamManager_GetInstance();
extern "C" unsigned int OamManager_GetSubOamBuffer(void*);
void SetFieldsAt0x28And0x2c02076988(int*, int, int);
void ForwardTableValue02075db0(Struct02075db0*, int, int);

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
    int unknown_100_[LOW_REGION(0x48,0x4c) / 4];
    int unknown_14c_[0xc / 4];
    int unknown_158_[0x18 / 4];
    char unknown_170_[LOW_REGION(0x18,0xc)];
    int unknown_17c_[4][0x74 / 4];
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

// USA: func_ov006_021580b8
extern "C" ARM void func_ov006_021580b8(Struct_ov006_02157a60* arg0)
{
    if (arg0->unknown_38f_ != 0)
    {
        if (func_ov006_02158080((Struct_0207fdcc_2*)arg0->unknown_14_, 0))
            func_ov006_02158054(arg0->unknown_ac_, (Struct_ov006_02158054*)&arg0->unknown_24_[26], 2, 0x61, 0x64, 1);
        if (func_ov006_02158080((Struct_0207fdcc_2*)arg0->unknown_14_, 1))
        {
            func_ov006_02158054(arg0->unknown_ac_, (Struct_ov006_02158054*)&arg0->unknown_24_[27], 2, 0x74, 0x66, 1);
            if (arg0->unknown_42c_ > 0x1f)
                func_ov006_02158054(arg0->unknown_ac_, (Struct_ov006_02158054*)&arg0->unknown_24_[28], 0x78, 0xb6, 0x63, 1);
        }
        else
        {
            arg0->unknown_42c_ = 0;
        }
        func_ov006_02154a60(self->pot_);
        Background_ClearMap((BackgroundGraphics*)self->subBackground_, 0);
        void* layer = Background_GetScreen((BackgroundGraphics*)self->subBackground_, self->background_);
        if (layer != 0)
            CallFunc0204b620IfField0x14_0204b938(self->subBackground_, layer, 0, 0, 0xffff);
#if !defined(jpn)
        if (arg0->unknown_397_ == 1)
        {
            unsigned int kind = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
            unsigned char tiles = 1;
            switch (kind)
            {
            case 2:
                var2 = 3;
                break;
            case 4:
                var2 = 4;
                break;
            case 3:
                var2 = 5;
                break;
            case 5:
                var2 = 6;
                break;
            }
            if (tiles > 1)
                Background_DrawScreen((BackgroundGraphics*)self->subBackground_, tiles, 0, 0, 0x16, 2, 9, 2, 0xffff);
        }
#endif
        void* menu = self->menu_;
        ClearAllBuffers0207fcb8((Obj0207fcb8*)menu);
        CallFunc0204c8f0OverEntries0207fd00((Obj0207fd00*)menu);
        func_0207fe80(menu, 2, 1, 1);
        Background_FlushMap(self->subBackground_, 0);
        CallFunc0204b04cOverList0x2c((Cont0207fd44*)menu);
        if (self->flags_ & 0x200)
        {
            self->arrowTimer_ = 0;
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
                var4->unknown_4_ = 0xd7;
                var4->unknown_6_ = 0x96;
            }
            SpriteContext_DrawEntries(self->renderer_);
        }
        else
        {
            SpriteAnimation* animation = SpriteEntryList_Find((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
                animation->flags_ &= ~8;
        }
        if (arg0->unknown_37e_ < 0)
        {
            if (arg0->unknown_18_ != 0 && func_020e28dc((Struct_020e28dc*)arg0->unknown_18_))
                func_020e2794((Struct_020e2794_2*)arg0->unknown_18_, arg0->unknown_ac_);
            else
                func_ov006_021585c4(arg0);
        }
        func_ov006_0215868c(arg0);
        func_ov006_021587d0(arg0);
        func_ov006_02158914(arg0);
        arg0->unknown_431_ = 0;
        arg0->unknown_430_ = 0;
    }
    if (arg0->unknown_3b4_ != 0)
    {
        unsigned char var6 = arg0->unknown_38f_;
        if (var6 != 8 && var6 != 11)
            return;
        short var7;
        short var8;
        func_020807c4(arg0->unknown_14_, 0x12, &var7, &var8);
        Struct_ov006_021580b8* var9 = &arg0->unknown_24_[17];
        if (var9 != 0)
        {
            sprite->x_ = (x + 4) << 12;
            sprite->y_ = (y + 4) << 12;
            sprite->unk_22 = 0x32;
            sprite->unk_26 = 1;
            SpriteContext_DrawSprite(self->renderer_, sprite);
        }
        unsigned int vram = OamManager_GetSubOamBuffer(OamManager_GetInstance());
        self->resultSprite_.unk_4c = 0;
        self->resultSprite_.unk_14 = vram + 0x1b8;
        self->resultSprite_.unk_44 = 0x37;
        SetFieldsAt0x28And0x2c02076988((int*)&self->resultSprite_, 0x1000, 0x1000);
        ForwardTableValue02075db0((Struct02075db0*)&self->resultSprite_, x + 8, y + 8);
    }
}
