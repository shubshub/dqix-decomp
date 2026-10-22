#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_ov003_0216201c {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

struct Struct_ov003_02154af4_3 {
#if defined(jpn)
    char unknown_0_[0x1f0];
    char unknown_308_[0x20c - 0x1f0];
    Struct_ov003_0216201c *unknown_324_;
    char unknown_210_[0x28c - 0x210];
#else
    char unknown1_0_[0x308];
    char unknown_308_[0x324 - 0x308];
    Struct_ov003_0216201c *unknown_324_;
    char unknown_328_[0x464 - 0x328];
#endif
    unsigned int unknown_464_;
    char unknown_468_[0x470 - 0x468];
    short *unknown_470_;
    short unknown_474_;
    char unknown_476_[0x484 - 0x476];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    short unknown_48a_;
    char unknown_48c_[0x49f - 0x48c];
    signed char unknown_49f_;
    char unknown_4a0_[0x4a3 - 0x4a0];
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
    char unknown_4a5_[0x4a9 - 0x4a5];
    unsigned char unknown_4a9_[4];
    unsigned char unknown_4ad_;
};

extern int g_sePlayer;
extern "C" void func_020813ec(void *, int);
struct Obj0208203c;
void ResetWithSub0208203c(Obj0208203c*);
int FindMappedMemberId02080468(void *, int);
struct SePlayer;
void SePlayer_Play(SePlayer *, int, int);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(Cont0207fe44*);
int CountValidCombatantsMinusField_02160b84(void *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void func_ov003_02160c58(Scene *, short *, short *);
void SetEntryLowNibbleAndElement02080c68(void *, int, int);
extern "C" void *func_0205ec34();
extern "C" unsigned char *func_02053c6c(unsigned char *);
extern "C" int func_02011494(char*, void*);
extern "C" void func_0206df6c(void *, unsigned char *, int, int);
extern "C" int func_0206dfb0(int, unsigned char *, int);
extern "C" int func_02083b00(unsigned char *, int);
extern "C" void func_02083acc(unsigned char *, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_021ccfd0(int);

// USA: func_ov003_0216201c
extern "C" ARM void func_ov003_0216201c(Struct_ov003_02154af4_3 *arg0) {
    GameState *var0        = GameState::GetInstance();
    unsigned char *var1    = (unsigned char *)func_02010828(var0);
    unsigned char *var2  = (unsigned char *) func_0205ec34();
    unsigned char *var3 = func_02053c6c((unsigned char *) var0->GetPartyMemberByIndex(0));
    unsigned char var4  = arg0->unknown_4a4_;
    Struct_ov003_0216201c *var5     = arg0->unknown_324_;

    if (var4 == 0) {
        func_0207fe44((Struct_0207fe44*)var5);
        arg0->unknown_488_ = 0x1e;
        if (*((unsigned char *)func_02010828(GameState::GetInstance()) + 0xf7c) == 1) {
            arg0->unknown_488_ = 0x1d;
        }
        self->h48a   = FindMappedMemberId02080468(entries, self->h488);
        self->h474   = self->h48a;
        entries->sel = self->h48a;
        func_020813ec(entries, self->h488);
        ResetWithSub0208203c((Obj0208203c*)self->sub308);
        self->p470  = 0;
        self->state = self->state + 1;
        self->flags &= ~0x300;
    } else if (state == 1) {
        self->p470 = &self->h48a;
        SetEntryLowNibbleAndElement02080c68(entries, self->h488, 0);
        if (func_ov003_02160854(self) != 0) {
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->sub308);
            self->p470 = 0;
            switch (self->h48a) {
                case 0xb4:
                case 0xb7:
                    int var6 = func_ov003_02160b84(arg0);
                    var6 += var1[0xf7c];
                    if (var6 == 4) {
                        arg0->unknown_484_ = 6;
                        arg0->unknown_486_ = 2;
                    } else if (*((unsigned char *)func_02010828(GameState::GetInstance()) + 0x2000 + 0xc8c) == 0) {
                        func_0207fe44((Struct_0207fe44*)var5);
                        arg0->unknown_4a3_  = 2;
                        arg0->unknown_4a4_ = 0;
                    } else {
                        func_0207fe44((Struct_0207fe44*)var5);
                        arg0->unknown_484_  = 0x4c;
                        arg0->unknown_4a3_  = 2;
                        arg0->unknown_4a4_ = 4;
                    }
                    break;
                case 0xb8: {
                    int var7           = func_02011494((char*)GameState::GetInstance(), &arg0->unknown_4a9_);
                    arg0->unknown_4ad_       = var7;
                    unsigned char var8 = arg0->unknown_4ad_;
                    unsigned char var9;
                    unsigned char *var10 = arg0->unknown_4a9_;
                    for (var9 = 0; var9 < var8 - 1; var9++) {
                        if (*var10 == 0) {
                            *var10   = var10[1];
                            var10[1] = 0;
                        }
                        var10++;
                    }
                    short var11;
                    short var12;
                    arg0->unknown_4ad_ = arg0->unknown_4ad_ - 1;
                    func_ov003_02160c58(arg0, &var11, &var12);
                    if (*((unsigned char *)func_02010828(GameState::GetInstance()) + 0xf7c) == 1) {
                        arg0->unknown_484_ = 0x10;
                        arg0->unknown_486_ = 2;
                    } else if (var12 == 0) {
                        arg0->unknown_484_ = 0x45;
                        arg0->unknown_486_ = 2;
                    } else {
                        func_0207fe44((Struct_0207fe44*)var5);
                        arg0->unknown_484_  = 0xa;
                        arg0->unknown_4a3_  = 3;
                        arg0->unknown_4a4_ = 0;
                    }
                    break;
                }
                case 0xbe:
                case 0xbf: {
                    short var13;
                    short var14;
                    func_ov003_02160c58(arg0, &var13, &var14);
                    var14 = var14 - (var1[0xf7c] - 1);
                    if (var14 > 0) {
                        func_0207fe44((Struct_0207fe44*)var5);
                        arg0->unknown_4a3_ = 4;
                        arg0->unknown_484_ = 0x13;
                        arg0->unknown_464_ |= 2;
                        arg0->unknown_4a4_ = 0;
                    } else {
                        arg0->unknown_484_ = 0x17;
                        arg0->unknown_486_ = 2;
                    }
                    break;
                }
                case 0xb5:
                case 0xb9:
                    if (*((unsigned char *)func_02010828(GameState::GetInstance()) + 0x2000 + 0xc8c) != 0) {
                        func_0207fe44((Struct_0207fe44*)var5);
                        arg0->unknown_4a3_ = 5;
                        arg0->unknown_49f_ = 0;
                        func_0206df6c(var2, var2 + 0x8c, 0x785, 1);
                        arg0->unknown_484_  = 0x1d;
                        arg0->unknown_4a4_ = 0x64;
                    } else {
                        arg0->unknown_484_ = 0x1b;
                        arg0->unknown_486_ = 2;
                    }
                    break;
                case 0xb6:
                case 0xba:
                    func_0207fe44((Struct_0207fe44*)var5);
                    if (func_0206dfb0((int) var2, var2 + 0x8c, 0x784) != 0 && var3 != 0 &&
                        func_02083b00(var3, 0x11e) == 0)
                    {
                        arg0->unknown_484_ = 0x59;
                        if (var3 != 0) {
                            func_02083acc(var3, 0x11e);
                        }
                        func_ov017_021c9e00(0, 0, 0, 0);
                        func_ov017_021ccfd0(0);
                    } else {
                        arg0->unknown_484_ = 0x44;
                    }
                    break;
            }
            func_02080c68(var5, arg0->unknown_488_, 1);
        } else if (func_ov003_02160a68(arg0) != 0) {
            func_0207fe44((Struct_0207fe44*)var5);
            if (func_0206dfb0((int) var2, var2 + 0x8c, 0x784) != 0 && var3 != 0 &&
                func_02083b00(var3, 0x11e) == 0)
            {
                arg0->unknown_484_ = 0x59;
                if (var3 != 0) {
                    func_02083acc(var3, 0x11e);
                }
                func_ov017_021c9e00(0, 0, 0, 0);
                func_ov017_021ccfd0(0);
            } else {
                arg0->unknown_484_ = 0x44;
            }
        }
    }
}
