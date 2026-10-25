#include <globaldefs.h>

extern "C" {
void *_ZN9GameState11GetInstanceEv(void);
int func_02080468(void *, int);
void func_0208203c(void *);
int func_ov003_021550dc(void *);
void _Z13SePlayer_PlayP8SePlayerii(void *, int, int);
int _Z29GameState_GetProtagonistIndexP9GameState(void *);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void *, int);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void *);
void *_Z18GameState_GetPartyP9GameState(void *);
int func_ov003_02155208(void *);
void func_ov003_02155580(void *, int);
int func_ov003_02155618(void *);
int func_ov003_02155fc0(void *, int);
void func_ov003_02158334(void *);
}

extern char g_sePlayer[];

struct Struct_ov003_02156d40 {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

struct Struct_ov003_02156d40_2 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
};

struct Struct_ov003_02156d40_3 {
    char unknown_0_[8];
    void *unknown_8_;
    char unknown_c_[0xc];
    void *unknown_18_;
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
    short unknown_1ec_;
    char unknown_1ee_[4];
    unsigned char unknown_1f2_[5];
    char unknown_1f7_;
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_;
    char unknown_1fa_;
    unsigned char unknown_1fb_;
    unsigned int unknown_1fc_;
};

// USA: func_ov003_02156d40
extern "C" ARM void func_ov003_02156d40(struct Ctrl02156d40 *self) {
    void *gs              = _ZN9GameState11GetInstanceEv();
    struct Q02156d40 *q   = (struct Q02156d40 *) _Z18GameState_GetPartyP9GameState(gs);
    struct Obj02156d40 *p = (struct Obj02156d40 *) self->f18;
    if (self->state == 0) {
        func_ov003_02155580(self, 0);
        self->state = self->state + 1;
        return;
    }
    if (self->state == 1) {
        int r = func_ov003_02155618(self);
        if (r != -1) {
            if (r == 1) {
                if (self->f1fb == 0) {
                    self->f1f7  = _Z29GameState_GetProtagonistIndexP9GameState(gs);
                    self->state = 0;
                    if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, self->f1f7)) {
                        self->cmd  = 8;
                        self->mode = 7;
                        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
                        return;
                    }
                    arg0->unknown_1fc_ = arg0->unknown_1fc_ | 2;
                    arg0->unknown_1ec_   = 9;
                    arg0->unknown_1f8_  = 3;
                    arg0->unknown_1f9_ = 0;
                } else {
                    arg0->unknown_1f7_  = arg0->unknown_1f2_[0];
                    arg0->unknown_1ec_   = 6;
                    arg0->unknown_1f8_  = 2;
                    arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
                }
            }
        } else {
            arg0->unknown_1ec_  = 3;
            arg0->unknown_1f8_ = 7;
        }
        return;
    }
    if (arg0->unknown_1f9_ == 2) {
        arg0->unknown_1e6_ = 3;
        switch (var1->unknown_f7c_) {
            case 3: arg0->unknown_1e6_ = 4; break;
            case 4: arg0->unknown_1e6_ = 5; break;
        }
        if (arg0->unknown_1e2_ < 0) {
            arg0->unknown_1e2_ = func_02080468(var2, arg0->unknown_1e6_);
            arg0->unknown_1e8_ = arg0->unknown_1e2_;
        }
        var2->unknown_36_ = arg0->unknown_1e2_;
        func_ov003_02158334(arg0);
        func_0208203c(arg0->unknown_80_);
        arg0->unknown_8_   = 0;
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        return;
    }
    if (arg0->unknown_1f9_ != 3) {
        return;
    }
    self->f08 = &self->f1e2;
    if (func_ov003_021550dc(self) != 0) {
        _Z13SePlayer_PlayP8SePlayerii(g_sePlayer, 1, 0);
        _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
        self->f08  = 0;
        short d    = (short) (self->f1e2 - _Z26FindMappedMemberId02080468Pvi(p, self->f1e6));
        self->f1f7 = self->f1f2[d];
        if (func_ov003_02155fc0(self, self->f1f7) != 0) {
            self->cmd  = 0x31;
            self->mode = 7;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
            return;
        }
        if (func_ov003_02155f88(arg0, arg0->unknown_1f7_)) {
            arg0->unknown_1ec_  = 8;
            arg0->unknown_1f8_ = 7;
            func_0207fe44(var2);
            return;
        }
        arg0->unknown_1fc_ = arg0->unknown_1fc_ | 2;
        arg0->unknown_1ec_   = 9;
        arg0->unknown_1f8_  = 3;
        arg0->unknown_1f9_ = 0;
        func_0207fe44(var2);
        return;
    }
    if (func_ov003_02155208(arg0) == 0) {
        return;
    }
    arg0->unknown_8_  = 0;
    arg0->unknown_1ec_  = 7;
    arg0->unknown_1f8_ = 7;
    func_0207fe44(var2);
}
