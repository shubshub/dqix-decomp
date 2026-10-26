#include "GameState/GameState.h"
#include <globaldefs.h>



struct Struct_ov003_0216201c {
#if defined(jpn)
    char pad0[0x2a];
#else
    char pad0[0x36];
#endif
    short sel;
};

struct Scene {
#if defined(jpn)
    char pad0[0x1f0];
    char unknown_308_[0x20c - 0x1f0];
    Struct_ov003_0216201c *entries;
    char unknown_210_[0x28c - 0x210];
#else
    char pad0[0x308];
    char unknown_308_[0x324 - 0x308];
    Struct_ov003_0216201c *entries;
    char unknown_328_[0x464 - 0x328];
#endif
    unsigned int flags;
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
    unsigned char state;
    char unknown_4a5_[0x4a9 - 0x4a5];
    unsigned char list[4];
    unsigned char cnt;
};

extern int g_sePlayer;
extern "C" void func_020813ec(void *, int);
struct Struct_02081f20_2;
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" int func_02080468(void *, int);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer *, int, int);
struct Struct_0207fe44;
extern "C" void func_0207fe44(Struct_0207fe44*);
extern "C" int func_ov003_02160b84(void *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void func_ov003_02160c58(Scene *, short *, short *);
extern "C" void func_02080c68(void *, int, int);
extern "C" void *Scenario_GetInstance();
extern "C" unsigned char *func_02053c6c(unsigned char *);
extern "C" int GameState_GetOwnPartyOrder(char*, void*);
extern "C" void Scenario_SetFlag(void *, unsigned char *, int, int);
extern "C" int Scenario_TestFlag(int, unsigned char *, int);
extern "C" int func_02083b00(unsigned char *, int);
extern "C" void func_02083acc(unsigned char *, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_021ccfd0(int);

// USA: func_ov003_0216201c
extern "C" ARM void func_ov003_0216201c(Scene *self) {
    GameState *gs        = GameState::GetInstance();
    unsigned char *gp    = (unsigned char *)GameState_GetParty(gs);
    unsigned char *bits  = (unsigned char *) Scenario_GetInstance();
    unsigned char *field = func_02053c6c((unsigned char *) gs->GetPartyMemberByIndex(0));
    unsigned char state  = self->state;
    Struct_ov003_0216201c *entries     = self->entries;

    if (state == 0) {
        func_0207fe44((Struct_0207fe44*)entries);
        self->unknown_488_ = 0x1e;
        if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c) == 1) {
            self->unknown_488_ = 0x1d;
        }
        self->unknown_48a_   = func_02080468(entries, self->unknown_488_);
        self->unknown_474_   = self->unknown_48a_;
        entries->sel = self->unknown_48a_;
        func_020813ec(entries, self->unknown_488_);
        func_0208203c((Struct_02081f20_2*)self->unknown_308_);
        self->unknown_470_  = 0;
        self->state = self->state + 1;
        self->flags &= ~0x300;
    } else if (state == 1) {
        self->unknown_470_ = &self->unknown_48a_;
        func_02080c68(entries, self->unknown_488_, 0);
        if (func_ov003_02160854(self) != 0) {
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_308_);
            self->unknown_470_ = 0;
            switch (self->unknown_48a_) {
                case 0xb4:
                case 0xb7:
                    int var6 = func_ov003_02160b84(self);
                    var6 += gp[0xf7c];
                    if (var6 == 4) {
                        self->unknown_484_ = 6;
                        self->unknown_486_ = 2;
                    } else if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0x2000 + 0xc8c) == 0) {
                        func_0207fe44((Struct_0207fe44*)entries);
                        self->unknown_4a3_  = 2;
                        self->state = 0;
                    } else {
                        func_0207fe44((Struct_0207fe44*)entries);
                        self->unknown_484_  = 0x4c;
                        self->unknown_4a3_  = 2;
                        self->state = 4;
                    }
                    break;
                case 0xb8: {
                    int n           = GameState_GetOwnPartyOrder((char*)GameState::GetInstance(), &self->list);
                    self->cnt       = n;
                    unsigned char m = self->cnt;
                    unsigned char i;
                    unsigned char *p = self->list;
                    for (i = 0; i < m - 1; i++) {
                        if (*p == 0) {
                            *p   = p[1];
                            p[1] = 0;
                        }
                        p++;
                    }
                    short a;
                    short b;
                    self->cnt = self->cnt - 1;
                    func_ov003_02160c58(self, &a, &b);
                    if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c) == 1) {
                        self->unknown_484_ = 0x10;
                        self->unknown_486_ = 2;
                    } else if (b == 0) {
                        self->unknown_484_ = 0x45;
                        self->unknown_486_ = 2;
                    } else {
                        func_0207fe44((Struct_0207fe44*)entries);
                        self->unknown_484_  = 0xa;
                        self->unknown_4a3_  = 3;
                        self->state = 0;
                    }
                    break;
                }
                case 0xbe:
                case 0xbf: {
                    short a;
                    short b;
                    func_ov003_02160c58(self, &a, &b);
                    b = b - (gp[0xf7c] - 1);
                    if (b > 0) {
                        func_0207fe44((Struct_0207fe44*)entries);
                        self->unknown_4a3_ = 4;
                        self->unknown_484_ = 0x13;
                        self->flags |= 2;
                        self->state = 0;
                    } else {
                        self->unknown_484_ = 0x17;
                        self->unknown_486_ = 2;
                    }
                    break;
                }
                case 0xb5:
                case 0xb9:
                    if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0x2000 + 0xc8c) != 0) {
                        func_0207fe44((Struct_0207fe44*)entries);
                        self->unknown_4a3_ = 5;
                        self->unknown_49f_ = 0;
                        Scenario_SetFlag(bits, bits + 0x8c, 0x785, 1);
                        self->unknown_484_  = 0x1d;
                        self->state = 0x64;
                    } else {
                        self->unknown_484_ = 0x1b;
                        self->unknown_486_ = 2;
                    }
                    break;
                case 0xb6:
                case 0xba:
                    func_0207fe44((Struct_0207fe44*)entries);
                    if (Scenario_TestFlag((int) bits, bits + 0x8c, 0x784) != 0 && field != 0 &&
                        func_02083b00(field, 0x11e) == 0)
                    {
                        self->unknown_484_ = 0x59;
                        if (field != 0) {
                            func_02083acc(field, 0x11e);
                        }
                        func_ov017_021c9e00(0, 0, 0, 0);
                        func_ov017_021ccfd0(0);
                    } else {
                        self->unknown_484_ = 0x44;
                    }
                    break;
            }
            func_02080c68(entries, self->unknown_488_, 1);
        } else if (func_ov003_02160a68(self) != 0) {
            func_0207fe44((Struct_0207fe44*)entries);
            if (Scenario_TestFlag((int) bits, bits + 0x8c, 0x784) != 0 && field != 0 &&
                func_02083b00(field, 0x11e) == 0)
            {
                self->unknown_484_ = 0x59;
                if (field != 0) {
                    func_02083acc(field, 0x11e);
                }
                func_ov017_021c9e00(0, 0, 0, 0);
                func_ov017_021ccfd0(0);
            } else {
                self->unknown_484_ = 0x44;
            }
        }
    }
}
