#include "GameState/GameState.h"
#include <globaldefs.h>

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
    char unknown_476_[0x480 - 0x476];
    short unknown_480_;
    char unknown_482_[0x484 - 0x482];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    char unknown_48a_[0x494 - 0x48a];
    short unknown_494_;
    char unknown_496_[0x49f - 0x496];
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

#if defined(jpn)
#define REGION_OFF_464 0x28c
#else
#define REGION_OFF_464 0x64 + 0x400
#endif

extern int g_sePlayer;
struct StatusOwner02081198;
void SetEntryNibbleByShortId(StatusOwner02081198*, int, int);
struct StatusOwner02081164;
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020813ec(void *, int);
struct Obj0208203c;
void ResetWithSub0208203c(Obj0208203c*);
int FindMappedMemberId02080468(void *, int);
struct SePlayer;
void SePlayer_Play(SePlayer *, int, int);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(Cont0207fe44*);
Elem * GetElementAtIndex_02160bd0_02160bd0(void*, int);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
void SetOrClearFlag40_02166f80(void*, int, int);
extern "C" void func_ov003_02166220(Scene *);
extern "C" void func_ov003_02166184(Scene *);
extern "C" void func_ov003_021668fc(Scene *);

// USA: func_ov003_02163484
extern "C" ARM void func_ov003_02163484(Struct_ov003_02154af4_3 *arg0) {
    unsigned char var0 = arg0->unknown_4a4_;
    Struct_ov003_0216201c *var1    = arg0->unknown_324_;

    if (var0 == 0) {
        arg0->unknown_480_ = -1;
        arg0->unknown_488_ = 6;
        arg0->unknown_474_ = -1;
        if (arg0->unknown_494_ < 0) {
            arg0->unknown_494_ = func_02080468(var1, arg0->unknown_488_);
        }
        var1->unknown_36_ = arg0->unknown_494_;
        func_02081198((Struct_02081198*)var1, 0x18, 1);
        func_02081164((Struct_02081164*)var1, 0x18, 1);
        func_020813ec(var1, 0x18);
        func_ov003_02166f80(arg0, arg0->unknown_488_, 0);
        func_ov003_02166220(arg0);
        func_0208203c((Struct_02081f20_2*)arg0->unknown_308_);
        arg0->unknown_470_ = 0;
        arg0->unknown_464_ |= 0x780000;
        if (arg0->unknown_464_ & 1) {
            *(unsigned int *) ((int) arg0 + REGION_OFF_464) |= 0x800000;
        }
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    } else if (var0 == 1) {
        arg0->unknown_470_ = &arg0->unknown_494_;
        arg0->unknown_464_ |= 1;
        func_ov003_02166184(arg0);
        if (arg0->unknown_464_ & 0x1000000) {
            arg0->unknown_464_ |= 0x780000;
            if (arg0->unknown_464_ & 1) {
                *(unsigned int *) ((int) arg0 + REGION_OFF_464) |= 0x800000;
            }
        }
        if (func_ov003_02160854(arg0) != 0) {
            int var2 = arg0->unknown_494_ - func_02080468(var1, arg0->unknown_488_);
            var2 += arg0->unknown_49f_ * 4;
            Struct_ov003_0216253c *var3 = func_ov003_02160bd0(arg0, var2);
            if (var3 == 0) {
                return;
            }
            if (var3->unknown_0_0_ < 0) {
                return;
            }
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->sub308);
            self->p470 = 0;
            int m      = elem->m;
            if (m == 3) {
                SetOrClearFlag40_02166f80(self, self->h488, 1);
                self->h484  = 0x58;
                self->state = 0;
            } else if (m == 2 || m == 1 || m == 4) {
                SetOrClearFlag40_02166f80(self, self->h488, 1);
                self->h484  = 0x57;
                self->state = 0;
            } else {
                arg0->unknown_480_ = var3->unknown_0_0_;
                func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                arg0->unknown_484_  = 0x19;
                arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
                arg0->unknown_464_ |= 0x20;
            }
        } else if (func_ov003_02160a68(arg0) != 0) {
            func_0208203c((Struct_02081f20_2*)arg0->unknown_308_);
            arg0->unknown_470_ = 0;
            func_0207fe44((Struct_0207fe44*)var1);
            arg0->unknown_464_ |= 0x80000;
            arg0->unknown_484_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
        }
    } else if (var0 == 2) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
    } else if (var0 == 3) {
        int var5 = func_ov003_02161344(arg0);
        if (var5 != -1) {
            if (var5 == 1) {
                arg0->unknown_484_  = 0x1a;
                arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
                arg0->unknown_464_ |= 0x20;
            }
        } else {
            func_0207fe44((Struct_0207fe44*)var1);
            arg0->unknown_484_  = 0x1c;
            arg0->unknown_486_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
            arg0->unknown_464_ |= 0x80000;
            arg0->unknown_4a4_ = 0;
        }
    } else if (var0 == 4) {
        func_0207fe44((Struct_0207fe44*)var1);
        arg0->unknown_464_ |= 0x80000;
        arg0->unknown_484_  = 2;
        arg0->unknown_4a3_  = 1;
        arg0->unknown_4a4_ = 0;
        func_ov003_021668fc(arg0);
    } else if (var0 == 5) {
        func_0207fe44((Struct_0207fe44*)var1);
        arg0->unknown_464_ |= 0x80000;
        arg0->unknown_484_  = 2;
        arg0->unknown_4a3_  = 1;
        arg0->unknown_4a4_ = 0;
    } else if (var0 == 100) {
        func_ov003_021612c0(arg0);
        arg0->unknown_4a4_ = 0x65;
    } else if (var0 == 101) {
        int var6 = func_ov003_02161344(arg0);
        if (var6 != -1) {
            if (var6 == 1) {
                arg0->unknown_484_  = 0x18;
                arg0->unknown_4a4_ = 0;
            }
        } else {
            arg0->unknown_484_  = 0x1c;
            arg0->unknown_486_  = 2;
            arg0->unknown_4a3_  = 1;
            arg0->unknown_4a4_ = 0;
        }
    }
}
