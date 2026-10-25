#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Cont0207fe44;
struct Obj0208203c;
struct SePlayer;
struct Obj0217e5dc;
struct Obj020397cc;
struct StatusOwner02081198;
struct StatusOwner02081164;
struct FindEntryContainer02086a04;

struct Struct_ov003_0216201c {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

struct Struct_ov003_02162f40_4 {
#if defined(jpn)
    char unknown_0_[0x228];
#else
    char unknown1_0_[0x400];
#endif
    unsigned int unknown_400_;
};

struct Struct_ov003_02162f40 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
    char unknown_f7d_[0x2c8c - 0xf7d];
    unsigned char unknown_2c8c_;
};

struct Struct_ov003_0216253c {
    signed char unknown_0_0_ : 6;
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
    char unknown_476_[0x480 - 0x476];
    short unknown_480_;
    char unknown_482_[0x484 - 0x482];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    char unknown_48a_[0x490 - 0x48a];
    short unknown_490_;
    short unknown_492_;
    char unknown_494_[0x49e - 0x494];
    unsigned char unknown_49e_;
    signed char unknown_49f_;
    char unknown_4a0_[0x4a3 - 0x4a0];
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
};

static inline BattleInfo *GetBattleInfo() {
    return (BattleInfo *) GameState_GetParty(GameState::GetInstance());
}

struct Struct_ov003_02162f40_2 {
    char unknown_0_[0x64];
    Struct_ov003_02162f40_4 unknown_64_;
};

void CallFunc0204c804OverAllElems(Cont0207fe44 *);
extern "C" void func_020813ec(Entries *, int);
int FindMappedMemberId02080468(void *, int);
void ResetWithSub0208203c(Obj0208203c *);
void SetEntryLowNibbleAndElement02080c68(void *, int, int);
extern "C" int func_ov003_02160854(Scene *);
void SePlayer_Play(SePlayer *, int, int);
extern "C" void _Z16InitObj_0217e5dcP11Obj0217e5dca(Obj0217e5dc *, unsigned char);
extern "C" int func_ov003_02160a68(Scene *);
Elem *GetElementAtIndex_02160bd0_02160bd0(void *, int);
void SetEntryNibbleByShortId(StatusOwner02081198 *, int, int);
void SetEntryFlag0x2ByShortId(StatusOwner02081164 *, int, int);
extern "C" void func_ov003_02165c9c(Scene *);
void SetOrClearFlag40_02166f80(void *, int, int);
int CountValidCombatantsMinusField_02160b84(void *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
void RemoveOrShiftMarkedEntry02086a04(FindEntryContainer02086a04 *, int);
extern "C" int func_ov003_02166a90(Scene *, int);
void GameObject_DisableControl(Obj020397cc *, int);

extern int g_sePlayer;

// USA: func_ov003_02162f40
extern "C" ARM void func_ov003_02162f40(Struct_ov003_02154af4_3 *arg0) {
    unsigned char var0 = arg0->unknown_4a4_;
    Struct_ov003_0216201c *var1    = arg0->unknown_324_;

    if (state == 0) {
        CallFunc0204c804OverAllElems((Cont0207fe44 *) entries);
        func_020813ec(entries, 8);
        self->h488   = 8;
        self->h490   = FindMappedMemberId02080468(entries, self->h488);
        self->h474   = self->h490;
        entries->sel = self->h490;
        func_020813ec(entries, self->h488);
        ResetWithSub0208203c((Obj0208203c *) self->sub308);
        self->state = self->state + 1;
    } else if (state == 1) {
        self->p470 = &self->h490;
        SetEntryLowNibbleAndElement02080c68(entries, self->h488, 0);
        if (func_ov003_02160854(self) != 0) {
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c *) self->sub308);
            self->p470        = 0;
            unsigned char idx = self->h490 - 0x25;
            Obj0217e5dc *obj  = (Obj0217e5dc *) GetGameResources();
            _Z16InitObj_0217e5dcP11Obj0217e5dca(obj, idx);
            CallFunc0204c804OverAllElems((Cont0207fe44 *) entries);
            self->c4a3  = 0x10;
            self->state = self->state + 1;
        } else {
            if (func_ov003_02160a68(arg0) == 0) {
                return;
            }
            func_0208203c((Struct_02081f20_2 *) arg0->unknown_308_);
            arg0->unknown_470_ = 0;
            func_0207fe44((Struct_0207fe44 *) var1);
            arg0->unknown_484_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
        }
    } else if (var0 == 2) {
        arg0->unknown_488_  = 6;
        arg0->unknown_492_  = func_02080468(var1, arg0->unknown_488_);
        short var4 = arg0->unknown_492_;
        arg0->unknown_474_  = var4;
        int var5       = inline_ov003_02162f40()->unknown_2c8c_ - 1;
        arg0->unknown_49f_  = var5 / 4;
        arg0->unknown_474_  = arg0->unknown_474_ + (var5 & 3);
        arg0->unknown_492_  = arg0->unknown_474_;
        short var6   = (short) (arg0->unknown_492_ - var4) & 3;
        short var7   = arg0->unknown_49f_ * 4 + var6;
        arg0->unknown_480_  = -1;
        Struct_ov003_0216253c *var8  = func_ov003_02160bd0(arg0, var7);
        if (var8 != NULL) {
            arg0->unknown_480_ = var8->unknown_0_0_;
        }
        var1->unknown_36_ = arg0->unknown_492_;
        func_0207fe44((Struct_0207fe44 *) var1);
        func_02081198((Struct_02081198 *) var1, 5, 1);
        func_02081164((Struct_02081164 *) var1, 5, 1);
        func_020813ec(var1, 5);
        func_ov003_02165c9c(arg0);
        func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
        arg0->unknown_464_ |= 0x780000;
        if (arg0->unknown_464_ & 1) {
            ((Struct_ov003_02162f40_2 *) arg0)->unknown_64_.unknown_400_ |= 0x800000;
        }
        arg0->unknown_464_ |= 8;
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        func_0208203c((Struct_02081f20_2 *) arg0->unknown_308_);
        arg0->unknown_470_ = 0;
    } else if (var0 == 3) {
#if defined(jpn)
        int var9 = 4;
        if (arg0->unknown_49e_ == 1) {
            var9 = 3;
        }
#else
        int var9 = 4;
#endif
        arg0->unknown_484_  = 0x16;
        arg0->unknown_4a4_ = 4;
        int var10       = inline_ov003_02162f40()->unknown_f7c_;
        int var11       = func_ov003_02160b84(arg0);
        if (var10 + var11 >= var9) {
            return;
        }
        arg0->unknown_484_  = 0x15;
        arg0->unknown_4a4_ = 5;
    } else if (var0 == 4) {
        func_0207fe44((Struct_0207fe44 *) var1);
        arg0->unknown_464_ |= 0x80000;
        arg0->unknown_484_  = 2;
        arg0->unknown_4a3_  = 1;
        arg0->unknown_4a4_ = 0;
    } else if (var0 == 5) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    } else if (var0 == 6) {
        int var12 = func_ov003_02161344(arg0);
        if (var12 != -1) {
            if (var12 == 1) {
                func_0207fe44((Struct_0207fe44 *) var1);
                arg0->unknown_464_ |= 0x80000;
#if defined(jpn)
                int var13 = 4;
                if (arg0->unknown_49e_ == 1) {
                    var13 = 3;
                }
#else
                int var13 = 4;
#endif
                int var14 = inline_ov003_02162f40()->unknown_f7c_;
                int var15 = func_ov003_02160b84(arg0);
                if (var14 + var15 < var13) {
                    arg0->unknown_464_ |= 0xa;
                    arg0->unknown_484_  = 8;
                    arg0->unknown_4a4_ = 10;
                } else {
                    arg0->unknown_484_  = 5;
                    arg0->unknown_486_  = 2;
                    arg0->unknown_4a3_  = 1;
                    arg0->unknown_4a4_ = 0;
                }
            }
        } else {
            func_0207fe44((Struct_0207fe44 *) var1);
            arg0->unknown_464_ |= 0x80000;
            arg0->unknown_464_ |= 8;
            arg0->unknown_484_  = 0x5a;
            arg0->unknown_486_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
        }
    } else if (var0 == 7) {
        arg0->unknown_4a3_  = 7;
        arg0->unknown_4a4_ = 0;
        func_02086a04((Struct_02086a04 *) inline_ov003_02162f40(), (signed char) arg0->unknown_480_);
    } else if (var0 == 10) {
        if (func_ov003_02166a90(arg0, arg0->unknown_480_) == 0) {
            return;
        }
        GameObject *hero = GameState::GetInstance()->GetProtagonist();
        if (hero != NULL) {
            GameObject_DisableControl((Obj020397cc *) hero, 1);
        }
        arg0->unknown_4a4_ = 7;
    } else if (var0 == 100) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_ = 101;
    } else if (var0 == 101) {
        int var17 = func_ov003_02161344(arg0);
        if (var17 != -1) {
            if (var17 == 1) {
                arg0->unknown_484_  = 0x13;
                arg0->unknown_464_ |= 2;
                arg0->unknown_4a4_ = 0;
            }
        } else {
            arg0->unknown_484_  = 0x12;
            arg0->unknown_486_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
        }
    }
}
