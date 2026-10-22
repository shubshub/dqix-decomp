#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215b57c_4696 = 0x1054, Enum_ov006_0215b57c_54 = 0x2a };
#else
enum { Enum_ov006_0215b57c_4696 = 0x1258, Enum_ov006_0215b57c_54 = 0x36 };
#endif

struct Obj0208203c;
struct ClearFlag40_02157184Struct;
struct SePlayer;
struct Obj2081;
struct StructC28;

struct Struct_ov006_021537d0 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0x18];
    Struct_ov006_021537d0* unknown_1c_;
};

struct Struct_ov006_021555b0 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
    char unknown_0_[Enum_ov006_0215b57c_4696];
    unsigned short unknown_1258_;
};

struct Struct_ov000_0217ab8c {
    char unknown_0_[Enum_ov006_0215b57c_54];
    short unknown_36_;
};

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    void* unknown_8_;
    void* unknown_c_;
    Struct_ov006_02154614* unknown_10_;
    Struct_ov000_0217ab8c* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
    void* unknown_20_;
    void* unknown_24_;
    void* unknown_28_;
    Struct_ov006_021537d0* unknown_2c_;
    Struct_ov006_021537d0* unknown_30_;
    Struct_ov006_021537d0* unknown_34_;
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
#if defined(jpn)
    char unknown_174_[8];
#endif
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
    int unknown_3b8_[0x70 / 4];
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

extern "C" void func_ov006_0215fa1c(AlchemyMenu* self, int total);
extern "C" void func_ov006_0215fb7c(AlchemyMenu* self);
extern "C" void func_ov006_0215fcf0(AlchemyMenu* self);
extern "C" void func_ov006_0215f7e8(AlchemyMenu* self);
void ResetWithSub0208203c(Obj0208203c* repeat);
Recipe* FindNodeOrMark_02158d8c(void* self, short index);
extern "C" RecipeRecord* func_ov006_02153c6c(void* ingredients, short id);
extern "C" void func_ov006_02153b9c(void* ingredients, short id, unsigned char* amounts);
void ClearFlag40_02157184(ClearFlag40_02157184Struct* pot);
extern "C" void func_ov006_021555b0(AlchemyPot* pot, Recipe* recipe, RecipeRecord* record, unsigned char* amounts);
extern "C" unsigned char func_ov006_02159bb0(AlchemyMenu* self);
extern "C" void func_ov006_02159c64(AlchemyMenu* self);
extern "C" void func_ov006_021570fc(AlchemyPot* pot, int shown);
void SePlayer_Play(SePlayer* sound, int, int);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081* menu, int group);
void ClearField44IfSet_02158c28(StructC28* self);

extern "C" char g_sePlayer[];

// USA: func_ov006_0215b57c
extern "C" ARM void func_ov006_0215b57c(Struct_ov006_02157a60* arg0) {
    Struct_ov006_02154614* var0 = arg0->unknown_10_;
    if (arg0->unknown_390_ == 0)
    {
        arg0->unknown_397_ = 1;
        func_ov006_0215fa1c(arg0, 0);
        func_ov006_0215fb7c(arg0);
        func_ov006_0215fcf0(arg0);
        arg0->unknown_36e_ = 9;
        if (arg0->unknown_36a_ < 0)
            arg0->unknown_36a_ = 0x29;
        arg0->unknown_14_->unknown_36_ = arg0->unknown_36a_;
        func_ov006_0215f7e8(arg0);
        func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
        arg0->unknown_44_ = 0;
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 1)
    {
        arg0->unknown_44_ = &arg0->unknown_36a_;
        int var1 = arg0->unknown_350_;
        int var2 = 0;
        if (var1 & 0x10)
        {
            var2 = 1;
            arg0->unknown_388_++;
        }
        else if (var1 & 0x20)
        {
            var2 = 1;
            arg0->unknown_388_--;
        }
        if (arg0->unknown_388_ == 0xff)
            arg0->unknown_388_ = arg0->unknown_389_ - 1;
        if (arg0->unknown_389_ <= arg0->unknown_388_)
            arg0->unknown_388_ = 0;
        Struct_ov006_021537d0* var3 = func_ov006_02158d8c(arg0, arg0->unknown_36a_ - 0x29);
        Struct_ov006_021555b0* var4 = 0;
        if (var3 != 0)
        {
            var4 = func_ov006_02153c6c(arg0->unknown_74_, var3->unknown_0_);
            func_ov006_02153b9c(arg0->unknown_74_, var3->unknown_0_, arg0->unknown_398_);
        }
        else
        {
            func_ov006_02157184((Struct_ov006_02157184*)var0);
        }
        func_ov006_021555b0(var0, var3, var4, arg0->unknown_398_);
        if (var2)
        {
            func_ov006_0215f7e8(arg0);
            return;
        }
        unsigned char var5 = func_ov006_02159bb0(arg0);
        if (var5 == 1)
        {
            func_ov006_02159c64(arg0);
            return;
        }
        if (var5 == 4)
        {
            if (var3 != 0 && var4 != 0)
            {
                func_ov006_021570fc(pot, (pot->windowFlags_ & 0x800) ? 0 : 1);
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            }
            return;
        }
        if (!func_ov006_02158a28(arg0) && func_ov006_02158b78(arg0))
        {
            arg0->unknown_394_ &= ~0x80;
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, arg0->unknown_36e_);
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0xe);
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0xf);
            arg0->unknown_38f_ = 2;
            arg0->unknown_390_ = 0;
            arg0->unknown_397_ = 2;
            func_ov006_02157184((Struct_ov006_02157184*)var0);
            if (arg0->unknown_366_ == 0x25 || arg0->unknown_366_ == 0x26)
                arg0->unknown_390_ = 2;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)arg0);
    }
}
