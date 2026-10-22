#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_0215b7e8_54 = 0x2a, Enum_ov006_0215b7e8_76 = 0x48, Enum_ov006_0215b7e8_4180 = 0x1054 };
#else
enum { Enum_ov006_0215b7e8_54 = 0x36, Enum_ov006_0215b7e8_76 = 0x4c, Enum_ov006_0215b7e8_4696 = 0x1258 };
#endif

struct Obj0208203c;
struct SePlayer;
struct Obj2081;
struct Obj0215f348;
struct Cont0207fe44;
struct AlchemyPot;

struct Struct_ov006_0215b7e8 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
};

struct Struct_ov000_0217ab8c {
    char unknown_0_[Enum_ov006_0215b7e8_54];
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
    int unknown_100_[Enum_ov006_0215b7e8_76 / 4];
    int unknown_14c_[0xc / 4];
    int unknown_158_[0x18 / 4];
    char unknown_170_[0xc];
#if defined(jpn)
    char unknown1_170_[0xc];
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

extern "C" void func_ov006_021570fc(AlchemyPot* pot, int shown);
short FindMappedMemberId02080468(void* menu, int group);
extern "C" void func_020813ec(void* menu, int group);
void SyncEntries0215f348(Obj0215f348* self);
void SetElementFlag0x40_02081ea4(Obj2081* menu, int group, int value);
void ResetWithSub0208203c(Obj0208203c* repeat);
void SetElementFlag0x20_02080c04(Obj2081* menu, int id);
void ClearElementFlag0x20_02080c20(Obj2081* menu, int id);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
void SePlayer_Play(SePlayer* sound, int, int);
void CallFunc0204c804OverAllElems(Cont0207fe44* menu);
extern "C" LayoutElement* func_ov006_02157368(void* layout, short id);
extern "C" void func_ov006_02158de0(AlchemyMenu* self);
void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081* menu, int group);

extern "C" char g_sePlayer[];

// USA: func_ov006_0215b7e8
extern "C" ARM void func_ov006_0215b7e8(Struct_ov006_02157a60* arg0) {
    Struct_ov000_0217ab8c* var0 = arg0->unknown_14_;
    if (arg0->unknown_390_ == 0)
    {
        func_ov006_021570fc(arg0->unknown_10_, 1);
        arg0->unknown_397_ = 0;
        arg0->unknown_36e_ = 2;
        if (arg0->unknown_360_ < 0)
            arg0->unknown_360_ = func_02080468(var0, arg0->unknown_36e_);
        var0->unknown_36_ = arg0->unknown_360_;
        func_020813ec(var0, arg0->unknown_36e_);
        func_ov006_0215f348((Struct_ov006_0215b7e8_2*)arg0);
        func_02081ea4((Struct_0207fdcc_2*)var0, arg0->unknown_36e_, 0);
        func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
        arg0->unknown_44_ = 0;
        arg0->unknown_390_++;
        if (arg0->unknown_360_ == 4)
            func_02080c04((Struct_0207fdcc_2*)var0, 3);
        else
            func_02080c20((Struct_0207fdcc_2*)var0, 3);
    }
    else if (arg0->unknown_390_ == 1)
    {
        arg0->unknown_44_ = &arg0->unknown_360_;
        if (arg0->unknown_35e_ != *arg0->unknown_44_)
        {
            if (arg0->unknown_360_ == 4)
                func_02080c04((Struct_0207fdcc_2*)var0, 3);
            else
                func_02080c20((Struct_0207fdcc_2*)var0, 3);
            func_ov006_0215f348((Struct_ov006_0215b7e8_2*)arg0);
        }
        arg0->unknown_42c_ = 0;
        if (func_ov006_02158a28(arg0))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            switch (self->mainCursor_)
            {
            case 2:
                arg0->unknown_366_ = -1;
                func_0207fe44((Struct_0207fe44*)var0);
                arg0->unknown_38f_ = 9;
                arg0->unknown_390_ = 0;
                {
                    Struct_ov006_0215b7e8* var1 = func_ov006_02157368(arg0->unknown_100_, 0x50);
                    if (var1 != 0)
                        var1->unknown_16_ &= ~1;
                }
                {
                    Struct_ov006_0215b7e8* var2 = func_ov006_02157368(arg0->unknown_100_, 0x4f);
                    if (var2 != 0)
                        var2->unknown_16_ |= 1;
                }
                {
                    Struct_ov006_0215b7e8* var3 = func_ov006_02157368(arg0->unknown_100_, 0xe);
                    if (var3 != 0)
                        var3->unknown_16_ &= ~1;
                }
                {
                    Struct_ov006_0215b7e8* var4 = func_ov006_02157368(arg0->unknown_100_, 0xf);
                    if (var4 != 0)
                        var4->unknown_16_ |= 1;
                }
                {
                    Struct_ov006_0215b7e8* var5 = func_ov006_02157368(arg0->unknown_100_, 0x15);
                    if (var5 != 0)
                        var5->unknown_16_ &= ~1;
                }
                break;
            case 3:
            {
                func_ov006_02158de0(arg0);
                unsigned short* var6 = arg0->unknown_50_;
                unsigned char var7;
                int var8 = 0;
                if (var6 != 0)
                {
                    for (var7 = 0; var7 < 9; var7++)
                    {
                        if (var6[var7] != 0)
                        {
                            var8 = 1;
                            break;
                        }
                    }
                    if (var6[8] != 0)
                        var8 = 1;
                }
                if (var8)
                {
                    arg0->unknown_362_ = -1;
                    arg0->unknown_364_ = -1;
                    func_0207fe44((Struct_0207fe44*)var0);
                    arg0->unknown_38f_ = 5;
                    arg0->unknown_390_ = 0;
                    func_ov006_021570fc(arg0->unknown_10_, 1);
                    arg0->unknown_37e_ = 0x24;
                    arg0->unknown_392_ = 0;
                    arg0->unknown_394_ |= 0x20 | 0x100;
                    break;
                }
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_37e_ = 0x35;
                arg0->unknown_392_ = 0;
                func_02081ea4((Struct_0207fdcc_2*)var0, arg0->unknown_36e_, 1);
                arg0->unknown_390_ = 0;
                func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
                arg0->unknown_44_ = 0;
                return;
            }
            case 4:
                arg0->unknown_38f_ = 0xc;
                arg0->unknown_390_ = 0;
                break;
            }
            func_0207fdcc((Struct_0207fdcc_2*)var0, 3);
            func_0207fdcc((Struct_0207fdcc_2*)var0, arg0->unknown_36e_);
            return;
        }
        if (func_ov006_02158b78(arg0) || g_keyManager.TestKeysPressed(0x800))
        {
            func_0207fe44((Struct_0207fe44*)var0);
            arg0->unknown_38f_ = 0xc;
            arg0->unknown_390_ = 0;
        }
    }
}
