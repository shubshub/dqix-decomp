#if defined(jpn)
#define R(j,u) (j)
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_ov006_02154fe4 func_ov006_02156730
#endif

struct Struct_0207fdcc_2;
struct Struct_02020cb8;
struct Struct_02020cb8_5;
struct Struct_ov006_02155480_2;
struct Struct_020e28dc;
struct Struct_020439b0;
struct Struct_020e2834;
struct Struct_0207fd88;
struct Struct_ov006_02154614;

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
    char unknown_0_[0x14];
    unsigned int unknown_14_;
    char unknown_18_[0x44 - 0x18];
    int unknown_44_;
    char unknown_48_[4];
    int unknown_4c_;
    char unknown_50_[0x70 - 0x50];
};

struct Struct_ov003_021594c4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
int CheckElementFlag_02158080_02158080(Obj2081*, int);
Canvas* FindElementByByte0xc4_02081da8(Obj2081*, int);
void Background_Init(List0204af64*);
int Background_SetScroll(Obj0204b5e8*, int, int);
void CallFunc0204b620IfField0x14_0204b938(void*, void*, int, int, unsigned short);
extern "C" void func_ov006_02154fe4(AlchemyPot*);
void ResetDisplayState02155480(Obj02155480*);
extern "C" int func_ov006_021570fc(AlchemyPot*, int);
extern "C" void Background_TransferMap(void*, int);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void SetEntryEnabled020e2cc4(Entry020e2cc4*, int);
void SetYesNoButtonPalette020e2834(SelfState020e2834*);
void CallFunc0204b088OverList0x2c(Cont0207fd88*);

struct Struct_ov006_02157a60 {
    int unknown_0_;
    char** unknown_4_;
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

// USA: func_ov006_02158478
extern "C" ARM void func_ov006_02158478(Struct_ov006_02157a60* arg0)
{
    if (arg0->unknown_38f_ == 0)
        return;
    unsigned short* var0 = (unsigned short*)GetSubBG0ScreenBase();
    memset(var0, 0, 0x800);
    if (func_ov006_02158080((Struct_0207fdcc_2*)R(*(void**)((char*)arg0+0xc),arg0->unknown_14_), 1))
    {
        Struct_ov006_02158478* var1 = func_02081da8((Struct_0207fdcc_2*)R(*(void**)((char*)arg0+0xc),arg0->unknown_14_), 1);
        if (var1 == 0)
            return;
        short var2;
        short var3;
        void* var4 = (char*)var1 + 0xc8;
        if (var4 == 0)
            return;
        x = canvas->x_;
        y = canvas->y_;
        BackgroundGraphics background;
        Background_Init((List0204af64*)&background);
        background.unk_1c_0_ = 1;
        background.unk_1c_4_ = 0;
        *(unsigned short**)&background.unk_0[0x14] = screen;
        Background_SetScroll((Obj0204b5e8*)&background, 0, 0);
        CallFunc0204b620IfField0x14_0204b938(&background, layer, x, y, 0xffff);
    }
    func_ov006_02154fe4(R(*(Struct_ov006_02154614**)((char*)arg0+8),arg0->unknown_10_));
    if (arg0->unknown_432_ != 0)
    {
        func_ov006_02155480((Struct_ov006_02155480_2*)R(*(Struct_ov006_02154614**)((char*)arg0+8),arg0->unknown_10_));
        func_ov006_021570fc(R(*(Struct_ov006_02154614**)((char*)arg0+8),arg0->unknown_10_), 1);
        arg0->unknown_432_ = 0;
    }
    Background_TransferMap(R((int*)((char*)self+0x4c),self->subBackground_), 0);
    if (R(*(void**)((char*)self+0x10),self->choice_) != 0)
    {
        void* var6 = *(void**)((char*)R(*(void**)((char*)arg0+0x10),arg0->unknown_18_) + 0x10);
        func_020e2cc4((Struct_020439b0*)((char*)var6 + 0x28), func_020e28dc((Struct_020e28dc*)R(*(void**)((char*)arg0+0x10),arg0->unknown_18_)));
        func_020e2834((Struct_020e2834*)R(*(void**)((char*)arg0+0x10),arg0->unknown_18_));
    }
    if (R(*(void**)((char*)arg0+0xc),arg0->unknown_14_) != 0)
        func_0207fd88((Struct_0207fd88*)R(*(void**)((char*)arg0+0xc),arg0->unknown_14_));
}
