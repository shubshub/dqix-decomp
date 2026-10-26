#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
struct Struct_ov003_0216201c {
    char pad0[0x2a];
    short sel;
};

struct Scene {
    char pad0[0x1f0];
    char unknown_308_[0x20c - 0x1f0];
    Struct_ov003_0216201c *entries;
    char unknown_210_[0x28c - 0x210];
    unsigned int flags;
    char unknown_290_[0x298 - 0x290];
#else
struct Struct_ov003_0216201c {
    char pad0[0x36];
    short sel;
};

struct Scene {
    char pad0[0x308];
    char unknown_308_[0x324 - 0x308];
    Struct_ov003_0216201c *entries;
    char unknown_328_[0x464 - 0x328];
    unsigned int flags;
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
    unsigned char state;
};

struct Struct_ov003_0216253c {
    signed char v : 6;
    char pad1[0x13f - 1];
    unsigned char m : 3;
};

extern int g_sePlayer;
extern "C" unsigned int *GlobalFlags_GetInstance();
struct Struct_02081198;
extern "C" void func_02081198(Struct_02081198*, int, int);
struct Struct_02081164;
extern "C" void func_02081164(Struct_02081164*, int, int);
extern "C" void func_020813ec(void *, int);
extern "C" void func_ov003_02165c9c(Scene *);
struct Struct_02081f20_2;
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" int func_02080468(void *, int);
extern "C" void FlagWord_SetBits(unsigned int *, unsigned int);
extern "C" void func_ov003_02165bd8(Scene *);
extern "C" void func_ov003_02161438(void*);
extern "C" int func_ov003_02160854(Scene *);
extern "C" int func_ov003_021614e8(int);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer *, int, int);
struct Struct_0207fe44;
extern "C" void func_0207fe44(Struct_0207fe44*);
extern "C" Struct_ov003_0216253c * func_ov003_02160bd0(void*, int);
extern "C" int *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *);
extern "C" int LinkSession_IsHostOrSolo(int *);
extern "C" void func_ov017_02195540(unsigned char *);
extern "C" int func_ov003_02160b84(void *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
extern "C" void func_ov003_02161480(Scene *);
extern "C" int func_ov003_021669f0(Scene *);

// USA: func_ov003_0216253c
extern "C" ARM void func_ov003_0216253c(Scene *self) {
    Struct_ov003_0216201c *entries    = self->entries;
    unsigned int *data  = GlobalFlags_GetInstance();
    unsigned char state = self->state;

    if (state == 0) {
        self->unknown_480_   = -1;
        self->unknown_49f_   = 0;
        self->unknown_488_   = 6;
        self->unknown_48c_   = -1;
        self->unknown_474_   = self->unknown_48c_;
        entries->sel = self->unknown_48c_;
        func_02081198((Struct_02081198*)entries, 0x15, 1);
        func_02081164((Struct_02081164*)entries, 0x15, 1);
        func_020813ec(entries, 0x15);
        func_ov003_02165c9c(self);
        func_0208203c((Struct_02081f20_2*)self->unknown_308_);
        self->unknown_470_ = 0;
        self->flags |= 0x780000;
        if (self->flags & 1) {
            self->flags |= 0x800000;
        }
        self->state = self->state + 1;
    } else if (state == 1) {
        self->unknown_484_ = 0x48;
        self->flags |= 2;
        self->state = 4;
    } else if (state == 4) {
        self->unknown_480_   = -1;
        self->unknown_49f_   = 0;
        self->unknown_488_   = 6;
        self->unknown_48c_   = func_02080468(entries, self->unknown_488_);
        self->unknown_474_   = self->unknown_48c_;
        entries->sel = self->unknown_48c_;
        func_02081198((Struct_02081198*)entries, 0x15, 1);
        func_02081164((Struct_02081164*)entries, 0x15, 1);
        func_020813ec(entries, 0x15);
        func_ov003_02165c9c(self);
        self->flags |= 0x780000;
        if (self->flags & 1) {
            self->flags |= 0x800000;
        }
        func_0208203c((Struct_02081f20_2*)self->unknown_308_);
        self->unknown_470_  = 0;
        self->state = self->state + 1;
        FlagWord_SetBits(data, 0x40);
        self->flags |= 0x400;
    } else if (state == 5) {
        self->unknown_470_ = &self->unknown_48c_;
        self->flags |= 1;
        func_ov003_02165bd8(self);
        if (self->flags & 0x1000000) {
            self->flags |= 0x780000;
            if (self->flags & 1) {
                self->flags |= 0x800000;
            }
        }
        int idx = self->unknown_48c_ - 0x15 + self->unknown_49f_ * 4;
        func_ov003_02161438(self);
        if (func_ov003_02160854(self) != 0) {
            if (idx == *((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0x2000 + 0xc8c)) {
                if (func_ov003_021614e8((int) self) != 0) {
                    return;
                }
                SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
                func_0208203c((Struct_02081f20_2*)self->unknown_308_);
                self->unknown_470_ = 0;
                func_0207fe44((Struct_0207fe44*)entries);
                self->flags |= 0x80000;
                self->unknown_484_  = 0x4d;
                self->state = 100;
                self->flags |= 0x800;
            }
            Struct_ov003_0216253c *elem = func_ov003_02160bd0(self, idx);
            if (elem == NULL) {
                return;
            }
            int v = elem->v;
            if (v < 0) {
                return;
            }
            self->unknown_480_ = v;
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_308_);
            self->unknown_470_ = 0;
            func_0207fe44((Struct_0207fe44*)entries);
            self->flags |= 0x80000;
            self->flags |= 8;
            unsigned char *g = (unsigned char *) GetGameResources();
            int *p           = LinkSession_GetInstance();
            if (LinkSession_IsActive(p) != 0 && LinkSession_IsHostOrSolo(p) != 0) {
                func_ov017_02195540(g);
            }
            int a = *((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c);
            int n = func_ov003_02160b84(self);
            if (a + n == 4) {
                func_0207fe44((Struct_0207fe44*)entries);
                self->flags |= 0x80000;
                self->unknown_484_  = 6;
                self->unknown_486_  = 2;
                self->unknown_4a3_  = 1;
                self->state = 0;
            } else {
                int m = elem->m;
                if (m == 2 || m == 4) {
                    self->unknown_484_  = 0x52;
                    self->state = 9;
                    self->flags |= 2;
                    self->flags |= 0x8000;
                } else if (m == 3) {
                    self->unknown_484_  = 0x53;
                    self->state = 9;
                    self->flags |= 2;
                    self->flags |= 0x8000;
                } else {
                    self->unknown_484_  = 0x3d;
                    self->state = 8;
                    self->flags |= 2;
                    self->flags |= 0x8000;
                }
            }
            self->flags |= 0x800;
        } else {
            if (func_ov003_02160a68(self) == 0) {
                return;
            }
            func_0207fe44((Struct_0207fe44*)entries);
            self->flags |= 0x80000;
            self->unknown_484_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
            self->flags |= 0x800;
        }
    } else if (state == 6) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 7) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->unknown_484_  = 7;
                self->unknown_4a3_  = 3;
                self->state = 0;
                self->flags |= 0x100;
            }
        } else {
            self->unknown_480_  = -1;
            self->unknown_484_  = 4;
            self->state = 4;
            self->flags &= ~8;
        }
    } else if (state == 8) {
        func_ov003_02161480(self);
        self->state = 10;
    } else if (state == 9) {
        func_ov003_02161480(self);
        self->state = 11;
    } else if (state == 10) {
        if (func_ov003_021669f0(self) != 0) {
            self->unknown_4a3_  = 7;
            self->state = 0;
        }
    } else if (state == 11) {
        if (func_ov003_021669f0(self) != 0) {
            self->unknown_4a3_  = 1;
            self->unknown_484_  = 2;
            self->state = 0;
        }
    } else if (state == 100) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 101) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->unknown_484_  = 0x4e;
                self->unknown_4a3_  = 4;
                self->state = 0;
                self->flags |= 2;
            }
        } else {
            if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0x2000 + 0xc8c) == 0) {
                self->state = 0;
            } else {
                self->unknown_484_  = 4;
                self->state = 4;
            }
        }
    }
}
