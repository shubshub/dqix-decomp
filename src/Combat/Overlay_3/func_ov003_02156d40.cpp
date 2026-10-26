#include <globaldefs.h>

extern "C" {
void *_ZN9GameState11GetInstanceEv(void);
extern "C" int func_02080468(void *, int);
extern "C" void func_0208203c(void *);
int func_ov003_021550dc(void *);
extern "C" void SePlayer_Play(void *, int, int);
extern "C" int GameState_GetProtagonistIndex(void *);
extern "C" int func_ov003_02155f88(void *, int);
extern "C" void func_0207fe44(void *);
extern "C" void *GameState_GetParty(void *);
int func_ov003_02155208(void *);
void func_ov003_02155580(void *, int);
int func_ov003_02155618(void *);
int func_ov003_02155fc0(void *, int);
void func_ov003_02158334(void *);
}

extern char g_sePlayer[];

struct Struct_ov003_02156d40 {
#if defined(jpn)
    char pad0[0x2a];
#else
    char pad0[0x36];
#endif
    short unknown_36_;
};

struct Q02156d40 {
    char pad0[0xf7c];
    unsigned char f7c;
};

struct Struct_ov003_02156d40_3 {
    char unknown_0_[8];
    void *f08;
    char unknown_c_[0xc];
    void *f18;
    char unknown_1c_[0x80 - 0x1c];
    char unknown_80_[0x80];
#if defined(jpn)
    char unknown_100_[0x1de - 0x100];
#else
    char unknown1_100_[0x1e2 - 0x100];
#endif
    short unknown_1e2_;
    char unknown_1e4_[2];
    short unknown_1e6_;
    short unknown_1e8_;
    char unknown_1ea_[2];
    short cmd;
    char unknown_1ee_[4];
    unsigned char unknown_1f2_[5];
    char f1f7;
    unsigned char mode;
    unsigned char state;
    char unknown_1fa_;
    unsigned char unknown_1fb_;
    unsigned int flags;
};

// USA: func_ov003_02156d40
extern "C" ARM void func_ov003_02156d40(struct Struct_ov003_02156d40_3 *self) {
    void *gs              = _ZN9GameState11GetInstanceEv();
    struct Q02156d40 *q   = (struct Q02156d40 *) GameState_GetParty(gs);
    struct Struct_ov003_02156d40 *p = (struct Struct_ov003_02156d40 *) self->f18;
    if (self->state == 0) {
        func_ov003_02155580(self, 0);
        self->state = self->state + 1;
        return;
    }
    if (self->state == 1) {
        int r = func_ov003_02155618(self);
        if (r != -1) {
            if (r == 1) {
                if (self->unknown_1fb_ == 0) {
                    self->f1f7  = GameState_GetProtagonistIndex(gs);
                    self->state = 0;
                    if (func_ov003_02155f88(self, self->f1f7)) {
                        self->cmd  = 8;
                        self->mode = 7;
                        func_0207fe44(p);
                        return;
                    }
                    self->flags = self->flags | 2;
                    self->cmd   = 9;
                    self->mode  = 3;
                    self->state = 0;
                } else {
                    self->f1f7  = self->unknown_1f2_[0];
                    self->cmd   = 6;
                    self->mode  = 2;
                    self->state = self->state + 1;
                }
            }
        } else {
            self->cmd  = 3;
            self->mode = 7;
        }
        return;
    }
    if (self->state == 2) {
        self->unknown_1e6_ = 3;
        switch (q->f7c) {
            case 3: self->unknown_1e6_ = 4; break;
            case 4: self->unknown_1e6_ = 5; break;
        }
        if (self->unknown_1e2_ < 0) {
            self->unknown_1e2_ = func_02080468(p, self->unknown_1e6_);
            self->unknown_1e8_ = self->unknown_1e2_;
        }
        p->unknown_36_ = self->unknown_1e2_;
        func_ov003_02158334(self);
        func_0208203c(self->unknown_80_);
        self->f08   = 0;
        self->state = self->state + 1;
        return;
    }
    if (self->state != 3) {
        return;
    }
    self->f08 = &self->unknown_1e2_;
    if (func_ov003_021550dc(self) != 0) {
        SePlayer_Play(g_sePlayer, 1, 0);
        func_0208203c(self->unknown_80_);
        self->f08  = 0;
        short d    = (short) (self->unknown_1e2_ - func_02080468(p, self->unknown_1e6_));
        self->f1f7 = self->unknown_1f2_[d];
        if (func_ov003_02155fc0(self, self->f1f7) != 0) {
            self->cmd  = 0x31;
            self->mode = 7;
            func_0207fe44(p);
            return;
        }
        if (func_ov003_02155f88(self, self->f1f7)) {
            self->cmd  = 8;
            self->mode = 7;
            func_0207fe44(p);
            return;
        }
        self->flags = self->flags | 2;
        self->cmd   = 9;
        self->mode  = 3;
        self->state = 0;
        func_0207fe44(p);
        return;
    }
    if (func_ov003_02155208(self) == 0) {
        return;
    }
    self->f08  = 0;
    self->cmd  = 7;
    self->mode = 7;
    func_0207fe44(p);
}
