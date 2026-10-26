#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0207fe44;
struct Struct_02081f20_2;
struct SePlayer;
struct Struct_ov003_02162f40_3;
struct Obj020397cc;
struct Struct_02081198;
struct Struct_02081164;
struct Struct_02086a04;

struct Struct_ov003_0216201c {
#if defined(jpn)
    char pad0[0x2a];
#else
    char pad0[0x36];
#endif
    short sel;
};

struct Struct_ov003_02162f40_4 {
#if defined(jpn)
    char pad0[0x228];
#else
    char pad0[0x400];
#endif
    unsigned int flags;
};

struct BattleInfo {
    char pad0[0xf7c];
    unsigned char unknown_f7c_;
    char unknown_f7d_[0x2c8c - 0xf7d];
    unsigned char unknown_2c8c_;
};

struct Struct_ov003_0216253c {
    signed char v : 6;
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
    unsigned char state;
};

static inline BattleInfo *inline_ov003_02162f40() {
    return (BattleInfo *) GameState_GetParty(GameState::GetInstance());
}

struct Struct_ov003_02162f40_2 {
    char pad0[0x64];
    Struct_ov003_02162f40_4 cont;
};

extern "C" void func_0207fe44(Struct_0207fe44 *);
extern "C" void func_020813ec(Struct_ov003_0216201c *, int);
extern "C" int func_02080468(void *, int);
extern "C" void func_0208203c(Struct_02081f20_2 *);
extern "C" void func_02080c68(void *, int, int);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void SePlayer_Play(SePlayer *, int, int);
extern "C" void func_ov003_0217e5dc(Struct_ov003_02162f40_3 *, unsigned char);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" Struct_ov003_0216253c *func_ov003_02160bd0(void *, int);
extern "C" void func_02081198(Struct_02081198 *, int, int);
extern "C" void func_02081164(Struct_02081164 *, int, int);
extern "C" void func_ov003_02165c9c(Scene *);
extern "C" void func_ov003_02166f80(void *, int, int);
extern "C" int func_ov003_02160b84(void *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
extern "C" void func_02086a04(Struct_02086a04 *, int);
extern "C" int func_ov003_02166a90(Scene *, int);
extern "C" void GameObject_DisableControl(Obj020397cc *, int);

extern int g_sePlayer;

// USA: func_ov003_02162f40
extern "C" ARM void func_ov003_02162f40(Scene *self) {
    unsigned char state = self->state;
    Struct_ov003_0216201c *entries    = self->entries;

    if (state == 0) {
        func_0207fe44((Struct_0207fe44 *) entries);
        func_020813ec(entries, 8);
        self->unknown_488_   = 8;
        self->unknown_490_   = func_02080468(entries, self->unknown_488_);
        self->unknown_474_   = self->unknown_490_;
        entries->sel = self->unknown_490_;
        func_020813ec(entries, self->unknown_488_);
        func_0208203c((Struct_02081f20_2 *) self->unknown_308_);
        self->state = self->state + 1;
    } else if (state == 1) {
        self->unknown_470_ = &self->unknown_490_;
        func_02080c68(entries, self->unknown_488_, 0);
        if (func_ov003_02160854(self) != 0) {
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2 *) self->unknown_308_);
            self->unknown_470_        = 0;
            unsigned char idx = self->unknown_490_ - 0x25;
            Struct_ov003_02162f40_3 *obj  = (Struct_ov003_02162f40_3 *) GetGameResources();
            func_ov003_0217e5dc(obj, idx);
            func_0207fe44((Struct_0207fe44 *) entries);
            self->unknown_4a3_  = 0x10;
            self->state = self->state + 1;
        } else {
            if (func_ov003_02160a68(self) == 0) {
                return;
            }
            func_0208203c((Struct_02081f20_2 *) self->unknown_308_);
            self->unknown_470_ = 0;
            func_0207fe44((Struct_0207fe44 *) entries);
            self->unknown_484_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
        }
    } else if (state == 2) {
        self->unknown_488_  = 6;
        self->unknown_492_  = func_02080468(entries, self->unknown_488_);
        short first = self->unknown_492_;
        self->unknown_474_  = first;
        int n       = inline_ov003_02162f40()->unknown_2c8c_ - 1;
        self->unknown_49f_  = n / 4;
        self->unknown_474_  = self->unknown_474_ + (n & 3);
        self->unknown_492_  = self->unknown_474_;
        short col   = (short) (self->unknown_492_ - first) & 3;
        short idx   = self->unknown_49f_ * 4 + col;
        self->unknown_480_  = -1;
        Struct_ov003_0216253c *elem  = func_ov003_02160bd0(self, idx);
        if (elem != NULL) {
            self->unknown_480_ = elem->v;
        }
        entries->sel = self->unknown_492_;
        func_0207fe44((Struct_0207fe44 *) entries);
        func_02081198((Struct_02081198 *) entries, 5, 1);
        func_02081164((Struct_02081164 *) entries, 5, 1);
        func_020813ec(entries, 5);
        func_ov003_02165c9c(self);
        func_ov003_02166f80(self, self->unknown_488_, 1);
        self->flags |= 0x780000;
        if (self->flags & 1) {
            ((Struct_ov003_02162f40_2 *) self)->cont.flags |= 0x800000;
        }
        self->flags |= 8;
        self->state = self->state + 1;
        func_0208203c((Struct_02081f20_2 *) self->unknown_308_);
        self->unknown_470_ = 0;
    } else if (state == 3) {
#if defined(jpn)
        int limit = 4;
        if (self->unknown_49e_ == 1) {
            limit = 3;
        }
#else
        int limit = 4;
#endif
        self->unknown_484_  = 0x16;
        self->state = 4;
        int a       = inline_ov003_02162f40()->unknown_f7c_;
        int n       = func_ov003_02160b84(self);
        if (a + n >= limit) {
            return;
        }
        self->unknown_484_  = 0x15;
        self->state = 5;
    } else if (state == 4) {
        func_0207fe44((Struct_0207fe44 *) entries);
        self->flags |= 0x80000;
        self->unknown_484_  = 2;
        self->unknown_4a3_  = 1;
        self->state = 0;
    } else if (state == 5) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 6) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                func_0207fe44((Struct_0207fe44 *) entries);
                self->flags |= 0x80000;
#if defined(jpn)
                int limit = 4;
                if (self->unknown_49e_ == 1) {
                    limit = 3;
                }
#else
                int limit = 4;
#endif
                int a = inline_ov003_02162f40()->unknown_f7c_;
                int n = func_ov003_02160b84(self);
                if (a + n < limit) {
                    self->flags |= 0xa;
                    self->unknown_484_  = 8;
                    self->state = 10;
                } else {
                    self->unknown_484_  = 5;
                    self->unknown_486_  = 2;
                    self->unknown_4a3_  = 1;
                    self->state = 0;
                }
            }
        } else {
            func_0207fe44((Struct_0207fe44 *) entries);
            self->flags |= 0x80000;
            self->flags |= 8;
            self->unknown_484_  = 0x5a;
            self->unknown_486_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
        }
    } else if (state == 7) {
        self->unknown_4a3_  = 7;
        self->state = 0;
        func_02086a04((Struct_02086a04 *) inline_ov003_02162f40(), (signed char) self->unknown_480_);
    } else if (state == 10) {
        if (func_ov003_02166a90(self, self->unknown_480_) == 0) {
            return;
        }
        GameObject *hero = GameState::GetInstance()->GetProtagonist();
        if (hero != NULL) {
            GameObject_DisableControl((Obj020397cc *) hero, 1);
        }
        self->state = 7;
    } else if (state == 100) {
        func_ov003_021612c0(self);
        self->state = 101;
    } else if (state == 101) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->unknown_484_  = 0x13;
                self->flags |= 2;
                self->state = 0;
            }
        } else {
            self->unknown_484_  = 0x12;
            self->unknown_486_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
        }
    }
}
