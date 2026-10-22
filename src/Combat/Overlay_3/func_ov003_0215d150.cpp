#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include <globaldefs.h>

struct Struct_0205c570;
struct Struct0205cf1c;
struct SePlayer;

#if defined(jpn)
enum { Enum_ov003_0215d150_0 = 0x18, Enum_ov003_0215d150_0_2 = -0x34, Enum_ov003_0215d150_0_3 = -0x130, Enum_ov003_0215d150_0_4 = -0x1d0, Enum_ov003_0215d150_0_5 = 0x20 };
#else
enum { Enum_ov003_0215d150_0 = 0, Enum_ov003_0215d150_0_2 = 0, Enum_ov003_0215d150_0_3 = 0, Enum_ov003_0215d150_0_4 = 0, Enum_ov003_0215d150_0_5 = 0 };
#endif

struct Struct_ov003_0215d150_2 {
    char unknown_0_[0x5c + Enum_ov003_0215d150_0_2];
    char *unknown_5c_;
    char unknown_60_[0x998 - 0x60 + Enum_ov003_0215d150_0_3 - Enum_ov003_0215d150_0_2];
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Struct_ov003_02154af4_3 {
    char unknown_0_[0x64];
    Struct_0201099c_3 unknown_64_;
    char unknown_6c_[0x98 - 0x6c + Enum_ov003_0215d150_0];
    char unknown_98_[0x3b8 - 0x98];
    unsigned char unknown_3b8_;
    char unknown_3b9_[2];
    unsigned char unknown_3bb_;
    unsigned char unknown_3bc_;
    unsigned char unknown_3bd_[4];
    signed char unknown_3c1_;
    unsigned char unknown_3c2_;
    unsigned char unknown_3c3_;
    char unknown_3c4_[0x3cc - 0x3c4];
    int unknown_3cc_;
    int unknown_3d0_;
    char unknown_3d4_[0x3ec - 0x3d4];
    unsigned char unknown_3ec_;
    unsigned char unknown_3ed_;
    char unknown_3ee_[2];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    unsigned char unknown_3f2_;
};

struct Struct_01ff91ac_29 {
    char unknown_0_[0xb3c];
    int unknown_b3c_;
};

struct Struct_ov003_0215d150 {
    char unknown_0_[0x1840 + Enum_ov003_0215d150_0_5];
    Struct_01ff91ac_29 unknown_1840_;
};

static inline Struct_01ff91ac_29 *inline_ov003_0215d150(Struct_ov003_0215d150 *arg0) { return &arg0->unknown_1840_; }
static inline int inline_ov003_0215d150_2(Struct_01ff91ac_29 *arg0) { return arg0->unknown_b3c_; }

extern "C" Struct_ov003_0215d150_2 *func_020421a0();
extern "C" int *func_0202ae18();
extern "C" Struct_ov003_0215d150 *func_02012fe4();
extern "C" void func_02046380(void *arg0);
struct Struct_020465c0;
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char *, int, unsigned char);
extern "C" int func_0202b7d8(int *arg0);
extern "C" int func_0202c540(int *arg0);
extern "C" int func_0202c508(int *arg0);
struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
extern "C" const char * func_020e0434(Struct_0201099c_3*, int);
extern "C" int func_02042058(char *arg0, const char *arg1);
extern "C" void func_ov003_0215cab0(char *arg0, void *arg1);
extern "C" void func_ov003_0215ddc0(char *arg0);
extern "C" void func_ov003_0215df1c(void *arg0);
extern "C" void func_ov003_0215dd3c(char *arg0);
struct Struct_0205d81c;
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);
void SetChannelAFlag0205cef8(void *obj);
void SetChannelBFlag0205cf04(void *obj);
int GetActiveScaledSum0205d794(Struct_0205c570 *);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
void SePlayer_Play(SePlayer *, int, int);
void ClearChannelAFlag0205cf10(void *p);
void ClearFlagByte0205cf1c(Struct0205cf1c *);
extern "C" int func_ov003_0215dcb8(char *obj);
ARM int IsFlagStateOrField98Eq2_0215dd00(char *self);

extern int g_sePlayer;

// USA: func_ov003_0215d150
extern "C" ARM void func_ov003_0215d150(Struct_ov003_02154af4_3 *arg0) {
    GameState *var0 = GameState::GetInstance();
    Struct_ov003_0215d150_2 *var1       = func_020421a0();
    int *var2       = func_0202ae18();
    Struct_ov003_0215d150 *var3      = func_02012fe4();

    if (var1->unknown_9a0_ == 3) {
        *(unsigned char *) ((char *) var1 + 0x1000 + 0x9ae + Enum_ov003_0215d150_0_4) = 0;
    }

    unsigned char var4 = arg0->unknown_3b8_;
    int var5;

    if (var4 == 0) {
        func_02046380(var1);
        func_020465c0((Struct_020465c0*)var1, 0, arg0->unknown_3c3_);
        func_020465f0((unsigned char *) var1, 0, 0);
        func_020465c0((Struct_020465c0*)var1, 1, arg0->unknown_3cc_);
        func_020465f0((unsigned char *) var1, 1, 0);

        int var6;
        var6 = (arg0->unknown_3d0_ == 0) ? 1 : 0;
        if (func_0202b7d8(var2) != 0) {
            if (func_0202c540(var2) != 0) {
                var6 = 2;
            }
        }
        var1->unknown_998_ = 1;

        char *var7 = var1->unknown_5c_;
        if (arg0->unknown_3f0_ != 0) {
            func_02046574((Struct_02046574_2*)var1, 0, (char*)(*(void **) ((char *) var0->GetPartyMemberByIndex(0) + 0x134)));

            int var8 = 0;
            if (func_0202c508(var2) != 0) {
                var8 = (*(short *) ((char *) var0->GetUnknownGameObject() + 4) == 0) ? 1 : 0;
            }

            if (var8 != 0) {
                func_02042058(var7, func_020e0434(&arg0->unknown_64_, (short)0x64));
            }

            if (inline_ov003_0215d150_2(inline_ov003_0215d150(var3)) == 6) {
                var5 = 0x67;
            } else if (arg0->unknown_3d0_ != 0) {
                var5 = 0x65;
            } else {
                var5 = 0x68;
            }
            func_02042058(var7, func_020e0434(&arg0->unknown_64_, (short)var5));

            if (var8 == 0) {
                func_02042058(var7, func_020e0434(&arg0->unknown_64_, (short)0x6f));
            } else {
                int var9;
                var9 = (arg0->unknown_3d0_ != 0) ? 0x66 : 0x69;
                func_02042058(var7, func_020e0434(&arg0->unknown_64_, (short)var9));
            }
        } else {
            int var10 = var6 + 0x3e8;
            func_02042058(var7, func_020e0434(&arg0->unknown_64_, (short)var10));
        }

        func_ov003_0215cab0((char *) arg0, var7);
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }

    if (var4 == 1) {
        if (var1->unknown_9a0_ != 3) {
            return;
        }
        arg0->unknown_3ec_ = 1;
        arg0->unknown_3ed_ = 0;
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var4 == 2) {
        if (arg0->unknown_3ec_ != 0) {
            return;
        }
        if (arg0->unknown_3f2_ == 0) {
            func_ov003_0215ddc0((char *) arg0);
        }
        func_ov003_0215df1c(arg0);
        func_0205deb4((Struct_0205d81c*)arg0->unknown_98_, 0, 0);
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var4 == 3) {
        arg0->unknown_3c1_ = 0;
        func_ov003_0215dd3c((char *) arg0);
        func_0205cef8(arg0->unknown_98_);
        func_0205cf04(arg0->unknown_98_);
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (state == 4) {
        self->b3c2 = 1;
        self->b3c1 = GetActiveScaledSum0205d794((Struct_0205c570 *) self->list98);
        if (func_ov003_0215dcb8((char *) self) != 0) {
            self->b3c2 = 0;
            ResetEntryList0205d6a0((Entry_0205d6a0*)self->list98, 0);
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ClearChannelAFlag0205cf10(self->list98);
            ClearFlagByte0205cf1c((Struct0205cf1c *) self->list98);
            switch (self->tab3bd[self->b3c1]) {
            case 0: self->b3bc = 2; break;
            case 1: self->b3bc = 3; break;
            case 2: self->b3bc = 4; break;
            }
            arg0->unknown_3b8_ = 0;
        } else {
            if (func_ov003_0215dd00((char *) arg0) != 0) {
                arg0->unknown_3c2_ = 0;
                func_0205d6a0((Struct_0205d6a0*)arg0->unknown_98_, 0);
                func_0205cf10(arg0->unknown_98_);
                func_0205cf1c((Struct_0205cf1c *) arg0->unknown_98_);
                arg0->unknown_3bc_ = 4;
                arg0->unknown_3b8_ = 0;
            }
        }
    }
}
