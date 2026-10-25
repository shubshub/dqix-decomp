#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
struct Struct_ov003_0216201c {
    char unknown_0_[0x2a];
    short unknown_36_;
};

struct Struct_ov003_02154af4_3 {
    char unknown_0_[0x1f0];
    char unknown_308_[0x20c - 0x1f0];
    Struct_ov003_0216201c *unknown_324_;
    char unknown_210_[0x28c - 0x210];
    unsigned int unknown_464_;
    char unknown_290_[0x298 - 0x290];
#else
struct Struct_ov003_0216201c {
    char unknown_0_[0x36];
    short unknown_36_;
};

struct Struct_ov003_02154af4_3 {
    char unknown_0_[0x308];
    char unknown_308_[0x324 - 0x308];
    Struct_ov003_0216201c *unknown_324_;
    char unknown_328_[0x464 - 0x328];
    unsigned int unknown_464_;
    char unknown_468_[0x470 - 0x468];
#endif
    short *unknown_470_;
    short unknown_474_;
    char unknown_476_[0x480 - 0x476];
    short unknown_480_;
    char unknown_482_[0x484 - 0x482];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    char unknown_48a_[0x48c - 0x48a];
    short unknown_48c_;
    char unknown_48e_[0x49f - 0x48e];
    signed char unknown_49f_;
    char unknown_4a0_[0x4a3 - 0x4a0];
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
};

struct Struct_ov003_0216253c {
    signed char unknown_0_0_ : 6;
    char unknown_1_[0x13f - 1];
    unsigned char unknown_13f_0_ : 3;
};

extern int g_sePlayer;
unsigned int *GlobalFlags_GetInstance();
struct StatusOwner02081198;
void SetEntryNibbleByShortId(StatusOwner02081198*, int, int);
struct StatusOwner02081164;
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020813ec(void *, int);
extern "C" void func_ov003_02165c9c(Scene *);
struct Obj0208203c;
void ResetWithSub0208203c(Obj0208203c*);
int FindMappedMemberId02080468(void *, int);
void FlagWord_SetBits(unsigned int *, unsigned int);
extern "C" void func_ov003_02165bd8(Scene *);
void ApplyElementEffect02161438(void*);
extern "C" int func_ov003_02160854(Scene *);
int CompareThreshold_021614e8(int);
struct SePlayer;
void SePlayer_Play(SePlayer *, int, int);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(Cont0207fe44*);
Elem * GetElementAtIndex_02160bd0_02160bd0(void*, int);
extern "C" int *func_0202ae18();
extern "C" int func_0202b7d8(int *);
extern "C" int func_0202c508(int *);
extern "C" void func_ov017_02195540(unsigned char *);
extern "C" int func_ov003_02160b84(void *);
extern "C" int func_ov003_02160a68(Struct_ov003_02154af4_3 *);
extern "C" void func_ov003_021612c0(Struct_ov003_02154af4_3 *);
extern "C" int func_ov003_02161344(Struct_ov003_02154af4_3 *);
extern "C" void func_ov003_02161480(Struct_ov003_02154af4_3 *);
extern "C" int func_ov003_021669f0(Struct_ov003_02154af4_3 *);

// USA: func_ov003_0216253c
extern "C" ARM void func_ov003_0216253c(Scene *self) {
    Entries *entries    = self->entries;
    unsigned int *data  = GlobalFlags_GetInstance();
    unsigned char state = self->state;

    if (var2 == 0) {
        arg0->unknown_480_   = -1;
        arg0->unknown_49f_   = 0;
        arg0->unknown_488_   = 6;
        arg0->unknown_48c_   = -1;
        arg0->unknown_474_   = arg0->unknown_48c_;
        var0->unknown_36_ = arg0->unknown_48c_;
        func_02081198((Struct_02081198*)var0, 0x15, 1);
        func_02081164((Struct_02081164*)var0, 0x15, 1);
        func_020813ec(var0, 0x15);
        func_ov003_02165c9c(arg0);
        func_0208203c((Struct_02081f20_2*)arg0->unknown_308_);
        arg0->unknown_470_ = 0;
        arg0->unknown_464_ |= 0x780000;
        if (arg0->unknown_464_ & 1) {
            arg0->unknown_464_ |= 0x800000;
        }
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    } else if (var2 == 1) {
        arg0->unknown_484_ = 0x48;
        arg0->unknown_464_ |= 2;
        arg0->unknown_4a4_ = 4;
    } else if (var2 == 4) {
        arg0->unknown_480_   = -1;
        arg0->unknown_49f_   = 0;
        arg0->unknown_488_   = 6;
        arg0->unknown_48c_   = func_02080468(var0, arg0->unknown_488_);
        arg0->unknown_474_   = arg0->unknown_48c_;
        var0->unknown_36_ = arg0->unknown_48c_;
        func_02081198((Struct_02081198*)var0, 0x15, 1);
        func_02081164((Struct_02081164*)var0, 0x15, 1);
        func_020813ec(var0, 0x15);
        func_ov003_02165c9c(arg0);
        arg0->unknown_464_ |= 0x780000;
        if (arg0->unknown_464_ & 1) {
            arg0->unknown_464_ |= 0x800000;
        }
        ResetWithSub0208203c((Obj0208203c*)self->sub308);
        self->p470  = 0;
        self->state = self->state + 1;
        FlagWord_SetBits(data, 0x40);
        self->flags |= 0x400;
    } else if (state == 5) {
        self->p470 = &self->h48c;
        self->flags |= 1;
        func_ov003_02165bd8(self);
        if (self->flags & 0x1000000) {
            self->flags |= 0x780000;
            if (self->flags & 1) {
                self->flags |= 0x800000;
            }
        }
        int idx = self->h48c - 0x15 + self->c49f * 4;
        ApplyElementEffect02161438(self);
        if (func_ov003_02160854(self) != 0) {
            if (idx == *((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0x2000 + 0xc8c)) {
                if (CompareThreshold_021614e8((int) self) != 0) {
                    return;
                }
                SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
                ResetWithSub0208203c((Obj0208203c*)self->sub308);
                self->p470 = 0;
                CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
                self->flags |= 0x80000;
                self->h484  = 0x4d;
                self->state = 100;
                self->flags |= 0x800;
            }
            Struct_ov003_0216253c *var4 = func_ov003_02160bd0(arg0, var3);
            if (var4 == NULL) {
                return;
            }
            int var5 = var4->unknown_0_0_;
            if (var5 < 0) {
                return;
            }
            self->h480 = v;
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->sub308);
            self->p470 = 0;
            CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
            self->flags |= 0x80000;
            self->flags |= 8;
            unsigned char *g = (unsigned char *) GetGameResources();
            int *p           = func_0202ae18();
            if (CheckField0NonZero_0202b7d8(p) != 0 && func_0202c508(p) != 0) {
                ClearFlag320_02195540(g);
            }
            int a = *((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c);
            int n = CountValidCombatantsMinusField_02160b84(self);
            if (a + n == 4) {
                CallFunc0204c804OverAllElems((Cont0207fe44*)entries);
                self->flags |= 0x80000;
                self->h484  = 6;
                self->h486  = 2;
                self->c4a3  = 1;
                self->state = 0;
            } else {
                int var10 = var4->unknown_13f_0_;
                if (var10 == 2 || var10 == 4) {
                    arg0->unknown_484_  = 0x52;
                    arg0->unknown_4a4_ = 9;
                    arg0->unknown_464_ |= 2;
                    arg0->unknown_464_ |= 0x8000;
                } else if (var10 == 3) {
                    arg0->unknown_484_  = 0x53;
                    arg0->unknown_4a4_ = 9;
                    arg0->unknown_464_ |= 2;
                    arg0->unknown_464_ |= 0x8000;
                } else {
                    arg0->unknown_484_  = 0x3d;
                    arg0->unknown_4a4_ = 8;
                    arg0->unknown_464_ |= 2;
                    arg0->unknown_464_ |= 0x8000;
                }
            }
            arg0->unknown_464_ |= 0x800;
        } else {
            if (func_ov003_02160a68(arg0) == 0) {
                return;
            }
            func_0207fe44((Struct_0207fe44*)var0);
            arg0->unknown_464_ |= 0x80000;
            arg0->unknown_484_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
            arg0->unknown_464_ |= 0x800;
        }
    } else if (var2 == 6) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    } else if (var2 == 7) {
        int var11 = func_ov003_02161344(arg0);
        if (var11 != -1) {
            if (var11 == 1) {
                arg0->unknown_484_  = 7;
                arg0->unknown_4a3_  = 3;
                arg0->unknown_4a4_ = 0;
                arg0->unknown_464_ |= 0x100;
            }
        } else {
            arg0->unknown_480_  = -1;
            arg0->unknown_484_  = 4;
            arg0->unknown_4a4_ = 4;
            arg0->unknown_464_ &= ~8;
        }
    } else if (var2 == 8) {
        func_ov003_02161480(arg0);
        arg0->unknown_4a4_ = 10;
    } else if (var2 == 9) {
        func_ov003_02161480(arg0);
        arg0->unknown_4a4_ = 11;
    } else if (var2 == 10) {
        if (func_ov003_021669f0(arg0) != 0) {
            arg0->unknown_4a3_  = 7;
            arg0->unknown_4a4_ = 0;
        }
    } else if (var2 == 11) {
        if (func_ov003_021669f0(arg0) != 0) {
            arg0->unknown_4a3_  = 1;
            arg0->unknown_484_  = 2;
            arg0->unknown_4a4_ = 0;
        }
    } else if (var2 == 100) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    } else if (var2 == 101) {
        int var12 = func_ov003_02161344(arg0);
        if (var12 != -1) {
            if (var12 == 1) {
                arg0->unknown_484_  = 0x4e;
                arg0->unknown_4a3_  = 4;
                arg0->unknown_4a4_ = 0;
                arg0->unknown_464_ |= 2;
            }
        } else {
            if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0x2000 + 0xc8c) == 0) {
                self->state = 0;
            } else {
                arg0->unknown_484_  = 4;
                arg0->unknown_4a4_ = 4;
            }
        }
    }
}
