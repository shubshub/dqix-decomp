#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_0215c680_54 = 0x2a, Enum_ov006_0215c680_76 = 0x48, Enum_ov006_0215c680_4180 = 0x1054 };
#else
enum { Enum_ov006_0215c680_54 = 0x36, Enum_ov006_0215c680_76 = 0x4c, Enum_ov006_0215c680_4696 = 0x1258 };
#endif

struct Obj0208203c { int fields_[3]; };
struct SePlayer;
struct Obj2081;
struct Container02071ffc;
struct StructC28;
struct AlchemyPot;
struct Recipe;

struct Struct_0207fdcc_2 {
    char unknown_0_[Enum_ov006_0215c680_54];
    short unknown_36_;
};

struct Struct_ov006_0215b1a0 {
    Struct_ov006_021537d0* unknown_0_;
    int unknown_4_[2];
};

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    void* unknown_8_;
    void* unknown_c_;
    Struct_ov006_02154614* unknown_10_;
    Struct_0207fdcc_2* unknown_14_;
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
    Struct_02081f20_2 unknown_9c_;
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int unknown_ac_[0x54 / 4];
    int unknown_100_[Enum_ov006_0215c680_76 / 4];
    Struct_ov006_0215b1a0 unknown_14c_;
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

struct Struct_ov006_0215951c;
struct Struct_ov006_02159094;
struct Struct_ov006_021596f0;
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);
extern "C" short func_02080468(void*, int);
extern "C" void func_02081ea4(Struct_0207fdcc_2*, int, int);
extern "C" void func_020813ec(void*, int);
extern "C" void func_02080c68(void*, int, int);
extern "C" void func_ov006_0215951c(Struct_ov006_0215951c*);
extern "C" void func_020804fc(void*, int);
extern "C" void func_ov006_0215f4dc(Struct_ov006_02157a60*);
extern "C" void func_ov006_021573c8(void*);
extern "C" void func_ov006_021553bc(void*, short*, unsigned char*);
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" void func_ov006_02155710(void*, int, int);
extern "C" int func_ov006_021595b4(AlchemyMenu*);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu*);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu*);
void SePlayer_Play(SePlayer*, int, int);
extern "C" int func_ov006_02159218(AlchemyMenu*);
void ExpireStatusSlot02159094(Obj02159094*);
void ClearField44IfSet_02158c28(StructC28*);
extern "C" void func_ov006_0215943c(AlchemyMenu*);
int Check02159564(void*);
extern "C" void func_ov006_02159274(AlchemyMenu*, unsigned char*, short*, unsigned char*);
void UpdateEntryFlags021596f0(Struct021596f0*);
extern "C" int func_ov006_02159834(AlchemyMenu*);
extern "C" void func_ov006_02159108(AlchemyMenu*, int, int, int);
extern "C" SePlayer g_sePlayer;

static inline unsigned char inline_ov006_0215bb7c(Struct_ov006_02157a60* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_38a_; }

static inline unsigned char inline_ov003_0216e714(Struct_ov006_02157a60* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_38b_; }

extern "C" int func_ov006_021570fc(Struct_ov006_02154614*, int);
extern "C" void func_ov006_02159db0(Struct_ov006_02157a60*);
extern "C" signed char func_ov006_02159e50(Struct_ov006_02157a60*);

// USA: func_ov006_0215c680
extern "C" ARM void func_ov006_0215c680(Struct_ov006_02157a60* arg0) {
    Struct_0207fdcc_2* var0 = arg0->unknown_14_;
    if (arg0->unknown_390_ == 0) {
        func_0207fdcc(var0, 0);
        func_0207fdcc(var0, 1);
        arg0->unknown_36e_ = 0x10;
        if (arg0->unknown_362_ < 0)
            arg0->unknown_362_ = func_02080468(var0, arg0->unknown_36e_);
        func_02081ea4(var0, arg0->unknown_36e_, 0);
        func_020813ec(var0, arg0->unknown_36e_);
        func_02080c68(var0, arg0->unknown_36e_, 0);
        arg0->unknown_370_ = -1;
        arg0->unknown_38b_ = 0;
        func_ov006_0215951c((Struct_ov006_0215951c*)arg0);
        func_02081ea4(var0, 0x11, 0);
        func_020804fc(var0, 0x11);
        func_ov006_0215f4dc(arg0);
        arg0->unknown_394_ |= 0x10;
        arg0->unknown_394_ |= 0x20;
        func_02080c68(var0, 0x11, 1);
        func_ov006_021573c8(arg0->unknown_100_);
        func_ov006_021553bc(arg0->unknown_10_, arg0->unknown_378_, arg0->unknown_38c_);
        func_0208203c(&arg0->unknown_9c_);
        arg0->unknown_44_ = 0;
        Struct_ov006_02154614* var1 = arg0->unknown_10_;
        func_ov006_02155710(var1, -1, 0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 1) {
        if (func_ov006_021595b4(arg0))
            return;
        arg0->unknown_44_ = &arg0->unknown_362_;
        if (arg0->unknown_35e_ != *arg0->unknown_44_) {
            func_ov006_0215951c((Struct_ov006_0215951c*)arg0);
            func_ov006_0215f4dc(arg0);
        }
        if (func_ov006_02158a28(self)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c(&self->repeat_);
            self->cursor_ = 0;
            if (func_ov006_02159218(self)) {
                SetEntryLowNibbleAndElement02080c68(menu, self->group_, 1);
                SetElementFlag0x40_02081ea4(menu, self->group_, 1);
                SetEntryLowNibbleAndElement02080c68(menu, 0x11, 0);
                self->step_++;
            }
        } else {
            if (func_ov006_02158b78(arg0)) {
                func_0208203c(&arg0->unknown_9c_);
                arg0->unknown_44_ = 0;
                arg0->unknown_38f_ = 6;
                arg0->unknown_390_ = 0;
                func_ov006_02159094((Struct_ov006_02159094*)arg0);
                func_ov006_021553bc(arg0->unknown_10_, arg0->unknown_378_, arg0->unknown_38c_);
                func_ov006_0215f4dc(arg0);
            }
            func_ov006_02158c28((Struct_ov006_02158c28*)arg0);
        }
    } else if (arg0->unknown_390_ == 2) {
        func_ov006_0215943c(arg0);
        func_ov006_021553bc(arg0->unknown_10_, arg0->unknown_378_, arg0->unknown_38c_);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 3) {
        if (func_ov006_02159564(arg0))
            return;
        if (func_ov006_02158a28(self) && self->previousCursor_ == *self->cursor_) {
            unsigned char category;
            unsigned char count;
            count = 0;
            category = 0;
            short item = 0;
            func_ov006_02159274(self, &category, &item, &count);
            if (count) {
                SePlayer_Play(&g_sePlayer, 1, 0);
                ResetWithSub0208203c(&self->repeat_);
                self->cursor_ = 0;
                SetElementFlag0x40_02081ea4(self->menu_, 0x11, 1);
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
        } else if (func_ov006_02158b78(arg0)) {
            func_0208203c(&arg0->unknown_9c_);
            arg0->unknown_44_ = 0;
            arg0->unknown_364_ = -1;
            arg0->unknown_390_ = 0;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)arg0);
    } else if (arg0->unknown_390_ == 4) {
        func_ov006_021596f0((Struct_ov006_021596f0*)arg0);
        arg0->unknown_393_ = 0;
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 5) {
        arg0->unknown_42c_ = 0;
        int var5 = func_ov006_02159834(arg0);
        if (var5 == 1)
            return;
        if (g_keyManager.TestKeysPressed(1) || result == 2) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c(&self->repeat_);
            self->cursor_ = 0;
            self->flags_ &= ~8;
            CallFunc0204c804OnMatchingKey_0207fdcc(menu, 6);
            func_ov006_02159108(self, self->category_, self->item_, self->count_);
            func_ov006_021553bc(self->pot_, self->chosenItems_, self->chosenCounts_);
            self->step_++;
            self->flags_ |= 0x20;
            self->message_ = 0xa;
            self->messageStep_ = 0;
        } else if (func_ov006_02158b78(self) || result == 3) {
            ResetWithSub0208203c(&self->repeat_);
            self->cursor_ = 0;
            self->flags_ &= ~8;
            CallFunc0204c804OnMatchingKey_0207fdcc(menu, 6);
            self->step_ = 0;
            self->message_ = 0x24;
            self->messageStep_ = 0;
            self->flags_ |= 0x120;
        }
    } else if (arg0->unknown_390_ == 6) {
        func_ov006_021570fc(arg0->unknown_10_, 1);
        func_ov006_02159db0(arg0);
        arg0->unknown_390_++;
    } else if (arg0->unknown_390_ == 7) {
        int var6 = func_ov006_02159e50(arg0);
        if (var6 != -1) {
            if (var6 == 1) {
                arg0->unknown_38f_ = 8;
                arg0->unknown_3b4_ = 0;
                arg0->unknown_390_ = 0;
            }
        } else {
            while (arg0->unknown_378_[0] > 0)
                func_ov006_02159094((Struct_ov006_02159094*)arg0);
            func_ov006_021553bc(arg0->unknown_10_, arg0->unknown_378_, arg0->unknown_38c_);
            arg0->unknown_38f_ = 5;
            arg0->unknown_390_ = 0;
            arg0->unknown_394_ |= 0x20;
            arg0->unknown_37e_ = 0x24;
            arg0->unknown_392_ = 0;
            arg0->unknown_394_ |= 0x100;
        }
    }
}
