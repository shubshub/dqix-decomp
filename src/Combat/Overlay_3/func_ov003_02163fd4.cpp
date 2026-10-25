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
    char unknown_476_[0x484 - 0x476];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    short unknown_48a_;
    char unknown_48c_[0x49e - 0x48c];
    unsigned char unknown_49e_;
    char unknown_49f_[0x4a3 - 0x49f];
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
};

#if defined(jpn)
#define REGION_OFF_354 0x134
#else
#define REGION_OFF_354 0x354
#endif

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
int CheckField0AndBattleState_02160b50(void *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
void SetEntryLowNibbleAndElement02080c68(void *, int, int);
void SetOrClearFlag40_02166f80(void*, int, int);

// USA: func_ov003_02163fd4
extern "C" ARM void func_ov003_02163fd4(Struct_ov003_02154af4_3 *arg0) {
    unsigned char var0 = arg0->unknown_4a4_;
    Struct_ov003_0216201c *var1    = arg0->unknown_324_;

    if (var0 == 0) {
        func_0207fe44((Struct_0207fe44*)var1);
        int var2    = -1;
        arg0->unknown_49e_ = func_ov003_02160b50(arg0);
        switch (arg0->unknown_49e_) {
            case 0: arg0->unknown_488_ = 0x19; break;
            case 1:
                arg0->unknown_488_ = 0x1a;
                var2        = 0;
                break;
            case 2:
                arg0->unknown_488_ = 0x1b;
                var2        = 1;
                break;
        }
        func_020813ec(entries, idx);
        self->h48a   = FindMappedMemberId02080468(entries, self->h488);
        self->h474   = self->h48a;
        entries->sel = self->h48a;
        func_020813ec(entries, self->h488);
        ResetWithSub0208203c((Obj0208203c*)self->sub308);
        self->state = self->state + 1;
        self->flags &= ~0x300;
        *(unsigned char *) ((char*)GameState::GetInstance()->GetResources() + 0x4000 + REGION_OFF_354) = 0xa;
    } else if (state == 1) {
        self->p470 = &self->h48a;
        SetEntryLowNibbleAndElement02080c68(entries, self->h488, 0);
        short *p = &self->h484;
        if (func_ov003_02160854(self) != 0) {
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->sub308);
            self->p470 = 0;
            switch (self->h48a) {
                case 0xa6:
                    if ((int) *((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c) > 1) {
                        p[0]        = 3;
                        p[1]        = 4;
                        self->c4a3  = 0xb;
                        self->state = 0;
                    } else {
                        func_0207fe44((Struct_0207fe44*)var1);
                        var3[0]        = 3;
                        arg0->unknown_4a3_  = 0xb;
                        arg0->unknown_4a4_ = 2;
                    }
                    break;
                case 0xa7:
                    if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c) == 4) {
                        p[0] = 0x14;
                        p[1] = 1;
                    } else {
                        func_0207fe44((Struct_0207fe44*)var1);
                        arg0->unknown_4a3_  = 0xd;
                        arg0->unknown_4a4_ = 0xb;
                    }
                    break;
                case 0xa9:
                    func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                    if (func_ov003_02160b84(arg0) == 0) {
                        arg0->unknown_4a3_  = 0xe;
                        arg0->unknown_4a4_ = 0;
                    } else {
                        var3[0]        = 0x1f;
                        var3[1]        = 1;
                        arg0->unknown_4a4_ = 2;
                    }
                    break;
                case 0xaa:
                    func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                    var3[0]        = 0x11;
                    arg0->unknown_4a3_  = 0xc;
                    arg0->unknown_4a4_ = 0;
                    break;
                case 0xc0:
                case 0xc2:
                    arg0->unknown_464_ |= 0x2000;
                    func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                    var3[0] = 0x31;
                    var3[1] = 1;
                    break;
                case 0xc1:
                case 0xc3:
                    arg0->unknown_464_ |= 0x2000;
                    func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                    var3[0] = 0x32;
                    var3[1] = 1;
                    break;
                case 0xa8:
                    arg0->unknown_464_ |= 0x2000;
                    func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                    var3[0] = 0x10;
                    var3[1] = 1;
                    break;
                case 0xab:
                    arg0->unknown_464_ |= 0x2000;
                    func_ov003_02166f80(arg0, arg0->unknown_488_, 1);
                    var3[0] = 0x1e;
                    var3[1] = 1;
                    break;
                case 0xbb:
                case 0xbc:
                case 0xbd:
                    func_0207fe44((Struct_0207fe44*)var1);
                    var3[0] = 0x2d;
                    break;
            }
            func_02080c68(var1, arg0->unknown_488_, 1);
        } else if (func_ov003_02160a68(arg0) != 0) {
            func_0207fe44((Struct_0207fe44*)var1);
            var3[0] = 0x2d;
        }
    } else if (var0 == 2) {
        func_ov003_02166f80(arg0, arg0->unknown_488_, 0);
        arg0->unknown_4a4_ = 1;
    }
}
