#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_0215bb7c_2786 = 0x962 };
#else
enum { Enum_ov006_0215bb7c_2786 = 0xae2 };
#endif

struct Obj0208203c;
struct SePlayer;
struct Obj2081;
struct Obj0215951c;
struct Cont0207fe44;
struct StructC28;
struct Struct021596f0;

struct Struct_ov006_02154614 {
    char unknown_0_[Enum_ov006_0215bb7c_2786];
    unsigned short unknown_ae2_;
};

struct Struct_ov000_0217ab8c;

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

void ClearElementFlag0x20_02080c20(Obj2081* menu, int id);
void SetEntryLowNibbleAndElement02080c68(void* menu, int group, int value);
void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081* menu, int group);
short FindMappedMemberId02080468(void* menu, int group);
void SetElementFlag0x40_02081ea4(Obj2081* menu, int group, int value);
extern "C" void func_020813ec(void* menu, int group);
void CalcField389_0215951c(Obj0215951c* self);
void ClearSublistEntriesFlag4_020804fc(void* menu, int group);
extern "C" void func_ov006_0215f4dc(AlchemyMenu* self);
void ClearFlagsForIds_021573c8(void* layout);
extern "C" void func_ov006_021553bc(AlchemyPot* pot, short* items, unsigned char* amounts);
void ResetWithSub0208203c(Obj0208203c* repeat);
extern "C" void func_ov006_02155710(AlchemyPot* pot, short paramB, unsigned char paramC);
extern "C" int func_ov006_021595b4(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
void SePlayer_Play(SePlayer* sound, int, int);
extern "C" int func_ov006_02159218(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
void CallFunc0204c804OverAllElems(Cont0207fe44* menu);
void ClearField44IfSet_02158c28(StructC28* self);
extern "C" void func_ov006_0215943c(AlchemyMenu* self);
int Check02159564(void* self);
extern "C" void func_ov006_02159274(AlchemyMenu* self, unsigned char* category, short* item, unsigned char* count);
void UpdateEntryFlags021596f0(Struct021596f0* self);
extern "C" int func_ov006_02159834(AlchemyMenu* self);
extern "C" void func_ov006_02159108(AlchemyMenu* self, unsigned char category, short item, unsigned char count);

extern "C" char g_sePlayer[];

static inline unsigned char inline_ov006_0215bb7c(Struct_ov006_02157a60* arg0) { return arg0->unknown_38a_; }

static inline unsigned char inline_ov003_0216e714(Struct_ov006_02157a60* arg0) { return arg0->unknown_38b_; }

// USA: func_ov006_0215bb7c
extern "C" ARM void func_ov006_0215bb7c(Struct_ov006_02157a60* arg0) {
    Struct_ov000_0217ab8c* var0 = arg0->unknown_14_;
    if (arg0->unknown_390_ == 0)
    {
        func_02080c20((Struct_0207fdcc_2*)var0, 0x10);
        func_02080c20((Struct_0207fdcc_2*)var0, 0x11);
        func_02080c68(var0, 0x11, 1);
        arg0->unknown_10_->unknown_ae2_ &= ~0x10;
        func_0207fdcc((Struct_0207fdcc_2*)var0, 0);
        func_0207fdcc((Struct_0207fdcc_2*)var0, 1);
        arg0->unknown_36e_ = 0x10;
        if (arg0->unknown_362_ < 0)
            arg0->unknown_362_ = func_02080468(var0, arg0->unknown_36e_);
        func_02081ea4((Struct_0207fdcc_2*)var0, arg0->unknown_36e_, 0);
        func_020813ec(var0, arg0->unknown_36e_);
        func_02080c68(var0, arg0->unknown_36e_, 0);
        unsigned char var1;
        arg0->unknown_370_ = -1;
        arg0->unknown_38b_ = 0;
        for (var1 = 0; var1 < 3; var1++)
        {
            arg0->unknown_378_[var1] = -1;
            arg0->unknown_38c_[var1] = 0;
        }
        func_ov006_0215951c((Struct_ov006_0215951c*)arg0);
        func_02081ea4((Struct_0207fdcc_2*)var0, 0x11, 0);
        func_020804fc(var0, 0x11);
        func_ov006_0215f4dc(arg0);
        arg0->unknown_394_ |= 0x10;
        func_ov006_021573c8(arg0->unknown_100_);
        func_ov006_021553bc(arg0->unknown_10_, arg0->unknown_378_, arg0->unknown_38c_);
        func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
        arg0->unknown_44_ = 0;
        func_ov006_02155710(arg0->unknown_10_, -1, 0);
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 1)
    {
        if (func_ov006_021595b4(arg0))
            return;
        arg0->unknown_44_ = &arg0->unknown_362_;
        if (arg0->unknown_35e_ != *arg0->unknown_44_)
        {
            func_ov006_0215951c((Struct_ov006_0215951c*)arg0);
            func_ov006_0215f4dc(arg0);
        }
        if (func_ov006_02158a28(arg0))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            if (!func_ov006_02159218(self))
                return;
            func_02080c68(var0, arg0->unknown_36e_, 1);
            func_02081ea4((Struct_0207fdcc_2*)var0, arg0->unknown_36e_, 1);
            func_02080c68(var0, 0x11, 0);
            arg0->unknown_390_++;
        }
        else if (func_ov006_02158b78(arg0))
        {
            arg0->unknown_432_ = 1;
            func_0207fe44((Struct_0207fe44*)var0);
            func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
            arg0->unknown_44_ = 0;
            arg0->unknown_364_ = -1;
            arg0->unknown_38f_ = 4;
            arg0->unknown_390_ = 0;
            arg0->unknown_394_ &= ~0x10;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0;
            arg0->unknown_392_ = 0;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)arg0);
    }
    else if (arg0->unknown_390_ == 2)
    {
        unsigned char var2;
        for (var2 = 0; var2 < 3; var2++)
        {
            arg0->unknown_378_[var2] = -1;
            arg0->unknown_38c_[var2] = 0;
        }
        func_ov006_0215943c(arg0);
        func_ov006_021553bc(arg0->unknown_10_, arg0->unknown_378_, arg0->unknown_38c_);
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 3)
    {
        if (func_ov006_02159564(arg0))
            return;
        if (func_ov006_02158a28(arg0) && arg0->unknown_35e_ == *arg0->unknown_44_)
        {
            unsigned char var3 = 0;
            unsigned char var4 = 0;
            short var5 = 0;
            func_ov006_02159274(arg0, &var3, &var5, &var4);
            if (var4)
            {
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                ResetWithSub0208203c((Obj0208203c*)self->repeat_);
                self->cursor_ = 0;
                SetElementFlag0x40_02081ea4((Obj2081*)self->menu_, 0x11, 1);
                self->category_ = category;
                self->item_ = item;
                self->count_ = 1;
                self->step_++;
                self->flags_ &= ~0x10;
                self->flags_ |= 0x20;
                self->message_ = 9;
                self->messageStep_ = 0;
                return;
            }
        }
        else if (func_ov006_02158b78(arg0))
        {
            func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
            arg0->unknown_44_ = 0;
            arg0->unknown_364_ = -1;
            arg0->unknown_390_ = 0;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)arg0);
    }
    else if (arg0->unknown_390_ == 4)
    {
        func_ov006_021596f0((Struct_ov006_021596f0*)arg0);
        arg0->unknown_393_ = 0;
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 5)
    {
        arg0->unknown_42c_ = 0;
        int var6 = func_ov006_02159834(arg0);
        if (var6 == 1)
            return;
        if (g_keyManager.TestKeysPressed(1) || var6 == 2)
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            self->flags_ &= ~8;
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)menu, 6);
            unsigned char category = GetCategory(self);
            unsigned char count = GetCount(self);
            func_ov006_02159108(self, category, self->item_, count);
            func_ov006_021553bc(self->pot_, self->chosenItems_, self->chosenCounts_);
            self->state_ = 6;
            self->step_ = 0;
#if !defined(jpn)
            arg0->unknown_387_ = arg0->unknown_38b_;
#endif
            arg0->unknown_37e_ = 0x39;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20 | 0x100;
        }
        else if (func_ov006_02158b78(arg0) || var6 == 3)
        {
            func_0208203c((Struct_02081f20_2*)arg0->unknown_9c_);
            arg0->unknown_44_ = 0;
            arg0->unknown_394_ &= ~8;
            func_0207fdcc((Struct_0207fdcc_2*)var0, 6);
            arg0->unknown_390_ = 0;
            arg0->unknown_37e_ = 0x24;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x20 | 0x100;
        }
    }
}
