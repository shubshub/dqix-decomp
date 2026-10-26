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
    char unknown_48c_[0x49e - 0x48c];
    unsigned char unknown_49e_;
    char unknown_49f_[0x4a3 - 0x49f];
    unsigned char unknown_4a3_;
    unsigned char state;
};

#if defined(jpn)
#define REGION_OFF_354 0x134
#else
#define REGION_OFF_354 0x354
#endif

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
extern "C" int func_ov003_02160b50(void *);
extern "C" int func_ov003_02160a68(Scene *);
extern "C" int func_ov003_02160854(Scene *);
extern "C" void func_02080c68(void *, int, int);
extern "C" void func_ov003_02166f80(void*, int, int);

// USA: func_ov003_02163fd4
extern "C" ARM void func_ov003_02163fd4(Scene *self) {
    unsigned char state = self->state;
    Struct_ov003_0216201c *entries    = self->entries;

    if (state == 0) {
        func_0207fe44((Struct_0207fe44*)entries);
        int idx    = -1;
        self->unknown_49e_ = func_ov003_02160b50(self);
        switch (self->unknown_49e_) {
            case 0: self->unknown_488_ = 0x19; break;
            case 1:
                self->unknown_488_ = 0x1a;
                idx        = 0;
                break;
            case 2:
                self->unknown_488_ = 0x1b;
                idx        = 1;
                break;
        }
        func_020813ec(entries, idx);
        self->unknown_48a_   = func_02080468(entries, self->unknown_488_);
        self->unknown_474_   = self->unknown_48a_;
        entries->sel = self->unknown_48a_;
        func_020813ec(entries, self->unknown_488_);
        func_0208203c((Struct_02081f20_2*)self->unknown_308_);
        self->state = self->state + 1;
        self->flags &= ~0x300;
        *(unsigned char *) ((char*)GameState::GetInstance()->GetResources() + 0x4000 + REGION_OFF_354) = 0xa;
    } else if (state == 1) {
        self->unknown_470_ = &self->unknown_48a_;
        func_02080c68(entries, self->unknown_488_, 0);
        short *p = &self->unknown_484_;
        if (func_ov003_02160854(self) != 0) {
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_308_);
            self->unknown_470_ = 0;
            switch (self->unknown_48a_) {
                case 0xa6:
                    if ((int) *((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c) > 1) {
                        p[0]        = 3;
                        p[1]        = 4;
                        self->unknown_4a3_  = 0xb;
                        self->state = 0;
                    } else {
                        func_0207fe44((Struct_0207fe44*)entries);
                        p[0]        = 3;
                        self->unknown_4a3_  = 0xb;
                        self->state = 2;
                    }
                    break;
                case 0xa7:
                    if (*((unsigned char *)GameState_GetParty(GameState::GetInstance()) + 0xf7c) == 4) {
                        p[0] = 0x14;
                        p[1] = 1;
                    } else {
                        func_0207fe44((Struct_0207fe44*)entries);
                        self->unknown_4a3_  = 0xd;
                        self->state = 0xb;
                    }
                    break;
                case 0xa9:
                    func_ov003_02166f80(self, self->unknown_488_, 1);
                    if (func_ov003_02160b84(self) == 0) {
                        self->unknown_4a3_  = 0xe;
                        self->state = 0;
                    } else {
                        p[0]        = 0x1f;
                        p[1]        = 1;
                        self->state = 2;
                    }
                    break;
                case 0xaa:
                    func_ov003_02166f80(self, self->unknown_488_, 1);
                    p[0]        = 0x11;
                    self->unknown_4a3_  = 0xc;
                    self->state = 0;
                    break;
                case 0xc0:
                case 0xc2:
                    self->flags |= 0x2000;
                    func_ov003_02166f80(self, self->unknown_488_, 1);
                    p[0] = 0x31;
                    p[1] = 1;
                    break;
                case 0xc1:
                case 0xc3:
                    self->flags |= 0x2000;
                    func_ov003_02166f80(self, self->unknown_488_, 1);
                    p[0] = 0x32;
                    p[1] = 1;
                    break;
                case 0xa8:
                    self->flags |= 0x2000;
                    func_ov003_02166f80(self, self->unknown_488_, 1);
                    p[0] = 0x10;
                    p[1] = 1;
                    break;
                case 0xab:
                    self->flags |= 0x2000;
                    func_ov003_02166f80(self, self->unknown_488_, 1);
                    p[0] = 0x1e;
                    p[1] = 1;
                    break;
                case 0xbb:
                case 0xbc:
                case 0xbd:
                    func_0207fe44((Struct_0207fe44*)entries);
                    p[0] = 0x2d;
                    break;
            }
            func_02080c68(entries, self->unknown_488_, 1);
        } else if (func_ov003_02160a68(self) != 0) {
            func_0207fe44((Struct_0207fe44*)entries);
            p[0] = 0x2d;
        }
    } else if (state == 2) {
        func_ov003_02166f80(self, self->unknown_488_, 0);
        self->state = 1;
    }
}
