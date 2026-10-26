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
    unsigned char state;
};

struct Struct_ov003_0216253c {
    signed char v : 6;
    char pad1[0x13f - 1];
    unsigned char m : 3;
};

#if defined(jpn)
#define REGION_OFF_464 0x28c
#else
#define REGION_OFF_464 0x64 + 0x400
#endif

extern int g_sePlayer;
struct Struct_02081198;
extern "C" void func_02081198(Struct_02081198*, int, int);
struct Struct_02081164;
extern "C" void func_02081164(Struct_02081164*, int, int);
extern "C" void func_020813ec(void *, int);
struct Struct_02081f20_2;
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" int func_02080468(void *, int);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer *, int, int);
struct Struct_0207fe44;
extern "C" void func_0207fe44(Struct_0207fe44*);
extern "C" Struct_ov003_0216253c * func_ov003_02160bd0(void*, int);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void func_ov003_021612c0(Scene *);
extern "C" int func_ov003_02161344(Scene *);
extern "C" void func_ov003_02166f80(void*, int, int);
extern "C" void func_ov003_02166220(Scene *);
extern "C" void func_ov003_02166184(Scene *);
extern "C" void func_ov003_021668fc(Scene *);

// USA: func_ov003_02163484
extern "C" ARM void func_ov003_02163484(Scene *self) {
    unsigned char state = self->state;
    Struct_ov003_0216201c *entries    = self->entries;

    if (state == 0) {
        self->unknown_480_ = -1;
        self->unknown_488_ = 6;
        self->unknown_474_ = -1;
        if (self->unknown_494_ < 0) {
            self->unknown_494_ = func_02080468(entries, self->unknown_488_);
        }
        entries->sel = self->unknown_494_;
        func_02081198((Struct_02081198*)entries, 0x18, 1);
        func_02081164((Struct_02081164*)entries, 0x18, 1);
        func_020813ec(entries, 0x18);
        func_ov003_02166f80(self, self->unknown_488_, 0);
        func_ov003_02166220(self);
        func_0208203c((Struct_02081f20_2*)self->unknown_308_);
        self->unknown_470_ = 0;
        self->flags |= 0x780000;
        if (self->flags & 1) {
            *(unsigned int *) ((int) self + REGION_OFF_464) |= 0x800000;
        }
        self->state = self->state + 1;
    } else if (state == 1) {
        self->unknown_470_ = &self->unknown_494_;
        self->flags |= 1;
        func_ov003_02166184(self);
        if (self->flags & 0x1000000) {
            self->flags |= 0x780000;
            if (self->flags & 1) {
                *(unsigned int *) ((int) self + REGION_OFF_464) |= 0x800000;
            }
        }
        if (func_ov003_02160854(self) != 0) {
            int idx = self->unknown_494_ - func_02080468(entries, self->unknown_488_);
            idx += self->unknown_49f_ * 4;
            Struct_ov003_0216253c *elem = func_ov003_02160bd0(self, idx);
            if (elem == 0) {
                return;
            }
            if (elem->v < 0) {
                return;
            }
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_308_);
            self->unknown_470_ = 0;
            int m      = elem->m;
            if (m == 3) {
                func_ov003_02166f80(self, self->unknown_488_, 1);
                self->unknown_484_  = 0x58;
                self->state = 0;
            } else if (m == 2 || m == 1 || m == 4) {
                func_ov003_02166f80(self, self->unknown_488_, 1);
                self->unknown_484_  = 0x57;
                self->state = 0;
            } else {
                self->unknown_480_ = elem->v;
                func_ov003_02166f80(self, self->unknown_488_, 1);
                self->unknown_484_  = 0x19;
                self->state = self->state + 1;
                self->flags |= 0x20;
            }
        } else if (func_ov003_02160a68(self) != 0) {
            func_0208203c((Struct_02081f20_2*)self->unknown_308_);
            self->unknown_470_ = 0;
            func_0207fe44((Struct_0207fe44*)entries);
            self->flags |= 0x80000;
            self->unknown_484_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
        }
    } else if (state == 2) {
        func_ov003_021612c0(self);
        self->state = self->state + 1;
    } else if (state == 3) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->unknown_484_  = 0x1a;
                self->state = self->state + 1;
                self->flags |= 0x20;
            }
        } else {
            func_0207fe44((Struct_0207fe44*)entries);
            self->unknown_484_  = 0x1c;
            self->unknown_486_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
            self->flags |= 0x80000;
            self->state = 0;
        }
    } else if (state == 4) {
        func_0207fe44((Struct_0207fe44*)entries);
        self->flags |= 0x80000;
        self->unknown_484_  = 2;
        self->unknown_4a3_  = 1;
        self->state = 0;
        func_ov003_021668fc(self);
    } else if (state == 5) {
        func_0207fe44((Struct_0207fe44*)entries);
        self->flags |= 0x80000;
        self->unknown_484_  = 2;
        self->unknown_4a3_  = 1;
        self->state = 0;
    } else if (state == 100) {
        func_ov003_021612c0(self);
        self->state = 0x65;
    } else if (state == 101) {
        int r = func_ov003_02161344(self);
        if (r != -1) {
            if (r == 1) {
                self->unknown_484_  = 0x18;
                self->state = 0;
            }
        } else {
            self->unknown_484_  = 0x1c;
            self->unknown_486_  = 2;
            self->unknown_4a3_  = 1;
            self->state = 0;
        }
    }
}
