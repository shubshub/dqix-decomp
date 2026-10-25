#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_0215dee8_54 = 0x2a, Enum_ov006_0215dee8_76 = 0x48, Enum_ov006_0215dee8_4696 = 0x1054 };
#else
enum { Enum_ov006_0215dee8_54 = 0x36, Enum_ov006_0215dee8_76 = 0x4c, Enum_ov006_0215dee8_4696 = 0x1258 };
#endif

struct Obj0208203c;
struct SePlayer;
struct Obj2081;
struct ClearFlag40_02157184Struct;
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
    char unknown_0_[Enum_ov006_0215dee8_4696];
    unsigned short unknown_1258_;
};

struct Struct_ov000_0217ab8c {
    char unknown_0_[Enum_ov006_0215dee8_54];
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
    int unknown_100_[Enum_ov006_0215dee8_76 / 4];
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

void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081* menu, int group);
extern "C" void func_ov006_0215fa1c(AlchemyMenu* self, int total);
extern "C" void func_ov006_0215fb7c(AlchemyMenu* self);
extern "C" void func_ov006_0215fcf0(AlchemyMenu* self);
extern "C" void func_ov006_0215f7e8(AlchemyMenu* self);
void ResetWithSub0208203c(Obj0208203c* repeat);
Recipe* FindNodeOrMark_02158d8c(void* self, short index);
extern "C" RecipeRecord* func_ov006_02153c6c(void* ingredients, short id);
extern "C" void func_ov006_02153b9c(void* ingredients, short id, unsigned char* amounts);
extern "C" void func_ov006_021555b0(AlchemyPot* pot, Recipe* recipe, RecipeRecord* record, unsigned char* amounts);
extern "C" unsigned char func_ov006_02159bb0(AlchemyMenu* self);
extern "C" void func_ov006_02159c64(AlchemyMenu* self);
extern "C" void func_ov006_021570fc(AlchemyPot* pot, int shown);
void SePlayer_Play(SePlayer* sound, int, int);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
extern "C" int func_ov006_021537d0(void* ingredients, short id);
void SetElementFlag0x40_02081ea4(Obj2081* menu, int group, int value);
void ClearFlag40_02157184(ClearFlag40_02157184Struct* pot);
void ClearField44IfSet_02158c28(StructC28* self);
extern "C" void func_ov006_02159db0(AlchemyMenu* self);
extern "C" signed char func_ov006_02159e50(AlchemyMenu* self);
struct Obj0215a33c;
void Func_0215a33c(Obj0215a33c*, int);
extern "C" unsigned char func_ov006_0215a384(AlchemyMenu* self, int great);
extern "C" void func_ov006_0215fe34(AlchemyMenu* self, void* result);
extern "C" unsigned char func_ov006_0215fecc(AlchemyMenu* self);
int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" int func_020dd4c4(signed char member, void* results);
extern "C" int func_ov006_02153a78(void* ingredients, int times);
void SetEntryLowNibbleAndElement02080c68(void* menu, int id, int value);
extern "C" void func_ov006_0215f9e8(AlchemyMenu* self);
extern "C" unsigned char func_ov006_021599c0(AlchemyMenu* self);
extern "C" void func_ov006_0215a5dc(AlchemyMenu* self);
int CheckFlagOrByte55_02158c70();

extern "C" char g_sePlayer[];

// USA: func_ov006_0215dee8
extern "C" ARM void func_ov006_0215dee8(Struct_ov006_02157a60* arg0) {
    if (arg0->unknown_390_ == 0)
    {
        arg0->unknown_397_ = 1;
        func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0);
        func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 1);
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
        int var0 = arg0->unknown_350_;
        int var1 = 0;
        if (var0 & 0x10)
        {
            var1 = 1;
            arg0->unknown_388_++;
        }
        else if (var0 & 0x20)
        {
            var1 = 1;
            arg0->unknown_388_--;
        }
        if (arg0->unknown_388_ == 0xff)
            arg0->unknown_388_ = arg0->unknown_389_ - 1;
        if (arg0->unknown_389_ <= arg0->unknown_388_)
            arg0->unknown_388_ = 0;
        Struct_ov006_021537d0* var2 = func_ov006_02158d8c(arg0, arg0->unknown_36a_ - 0x29);
        Struct_ov006_021555b0* var3 = 0;
        if (var2 != 0)
        {
            var3 = func_ov006_02153c6c(arg0->unknown_74_, var2->unknown_0_);
            func_ov006_02153b9c(arg0->unknown_74_, var2->unknown_0_, arg0->unknown_398_);
        }
        func_ov006_021555b0(arg0->unknown_10_, var2, var3, arg0->unknown_398_);
        if (var1)
        {
            func_ov006_0215f7e8(arg0);
            return;
        }
        unsigned char var4 = func_ov006_02159bb0(arg0);
        if (var4 == 1)
        {
            func_ov006_02159c64(arg0);
            return;
        }
        if (var4 == 4)
        {
            if (var2 != 0 && var3 != 0)
            {
                AlchemyPot* pot = self->pot_;
                int shown = (pot->windowFlags_ & 0x800) ? 1 : 0;
                func_ov006_021570fc(pot, shown == 0 ? 1 : 0);
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                return;
            }
            return;
        }
        if (func_ov006_02158a28(arg0) || var4 == 2)
        {
            if (var2 != 0 && var3 != 0)
            {
                if (!var3->unknown_2_1_)
                    return;
                self->recipe_ = recipe;
                self->menu_->cursor_ = *self->cursor_;
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                ResetWithSub0208203c((Obj0208203c*)self->repeat_);
                self->cursor_ = 0;
                if (func_ov006_021537d0(self->ingredients_, recipe->id_))
                {
                    func_02081ea4((Struct_0207fdcc_2*)arg0->unknown_14_, 9, 1);
                    arg0->unknown_37e_ = 3;
                    arg0->unknown_392_ = 0;
                    arg0->unknown_394_ |= 0x20;
                    arg0->unknown_38b_ = 1;
                    arg0->unknown_387_ = 1;
                    arg0->unknown_390_++;
                    return;
                }
                func_02081ea4((Struct_0207fdcc_2*)arg0->unknown_14_, 9, 1);
                arg0->unknown_37e_ = 2;
                arg0->unknown_392_ = 0;
                arg0->unknown_394_ |= 0x20;
                arg0->unknown_390_ = 0x64;
                return;
            }
        }
        else if (func_ov006_02158b78(arg0) || var4 == 3)
        {
            if (button == 3)
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)self->menu_, self->group_);
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)self->menu_, 0xe);
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)self->menu_, 0xf);
            self->state_ = 9;
            self->step_ = 0;
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            ClearFlag40_02157184((ClearFlag40_02157184Struct*)self->pot_);
            self->background_ = 2;
            if (self->bookCursor_ == 0x25 || self->bookCursor_ == 0x26)
                self->step_ = 2;
            self->flags_ &= ~0x80;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)arg0);
    }
    else if (arg0->unknown_390_ == 2)
    {
        func_ov006_02159db0(arg0);
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 3)
    {
        signed char var7 = func_ov006_02159e50(arg0);
        if (var7 != -1)
        {
            if (var7 != 1)
                return;
            func_ov006_0215a33c((Struct_ov006_0215a33c*)arg0, 0);
            arg0->unknown_390_++;
            return;
        }
        arg0->unknown_390_ = 0;
    }
    else if (arg0->unknown_390_ == 4)
    {
        arg0->unknown_42c_ = 0;
        if (arg0->unknown_428_ == -1)
        {
            unsigned char var8 = func_ov006_0215a384(arg0, 0);
            if (var8 == 0)
                return;
            func_ov006_0215fe34(arg0, arg0->unknown_17c_);
            return;
        }
        else
        {
            unsigned char var9 = func_ov006_0215fecc(arg0);
            if (var9 == 0)
                return;
            self->showResult_ = 0;
            if (!(func_020dd4c4(GameState_GetProtagonistIndex(GameState::GetInstance()), self->results_) & 4))
            {
                arg0->unknown_390_ = 7;
                return;
            }
            arg0->unknown_37e_ = arg0->unknown_396_ + 4;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
        }
    }
    else if (arg0->unknown_390_ == 5)
    {
        func_ov006_02159db0(arg0);
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 6)
    {
        signed char var10 = func_ov006_02159e50(arg0);
        if (var10 != -1)
        {
            if (var10 == 1)
                arg0->unknown_390_++;
            return;
        }
        arg0->unknown_390_ = 0;
    }
    else if (arg0->unknown_390_ == 7)
    {
        if (func_ov006_02153a78(arg0->unknown_74_, 2))
        {
            arg0->unknown_37e_ = 6;
            arg0->unknown_392_ = 0;
            arg0->unknown_390_++;
            return;
        }
        arg0->unknown_37e_ = 8;
        arg0->unknown_392_ = 0;
        arg0->unknown_38f_ = 0xb;
        func_ov006_02157184((Struct_ov006_02157184*)arg0->unknown_10_);
        arg0->unknown_390_ = 0;
    }
    else if (arg0->unknown_390_ == 8)
    {
        func_02080c68(arg0->unknown_14_, 9, 1);
        func_ov006_0215f9e8(arg0);
        arg0->unknown_394_ |= 8;
        arg0->unknown_393_ = 0;
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 9)
    {
        arg0->unknown_42c_ = 0;
        unsigned char var11 = func_ov006_021599c0(arg0);
        if (var11 == 1)
            return;
        if (g_keyManager.TestKeysPressed(1) || var11 == 2)
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            self->times_ = self->count_;
            CallFunc0204c804OnMatchingKey_0207fdcc((Obj2081*)self->menu_, 0xa);
            self->state_ = 0xb;
            ClearFlag40_02157184((ClearFlag40_02157184Struct*)self->pot_);
            self->step_ = 0;
            self->message_ = 7;
            self->messageStep_ = 0;
            self->flags_ &= ~8;
            return;
        }
        unsigned char var12 = func_ov006_02158b78(arg0);
        if (var12 == 0 && var11 != 3)
            return;
        func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_14_, 0xa);
        arg0->unknown_390_ = 0;
        arg0->unknown_394_ &= ~8;
        arg0->unknown_38b_ = 1;
        func_ov006_0215a5dc(arg0);
    }
    else if (arg0->unknown_390_ == 0x64)
    {
        int var13 = func_ov006_02158c70();
        if (var13 == 0)
            return;
        arg0->unknown_37e_ = 1;
        arg0->unknown_392_ = 0;
        arg0->unknown_394_ |= 0x20;
        arg0->unknown_390_++;
    }
    else if (arg0->unknown_390_ == 0x65)
    {
        int var14 = func_ov006_02158c70();
        if (var14 != 0)
        {
            var14 = 0;
            arg0->unknown_390_ = 0;
        }
    }
}
