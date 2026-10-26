#include <globaldefs.h>
#include "Input/Input.h"



extern "C" char *MessageSystem_GetInstance(void);
extern "C" char *Zone3D_GetInstance(void);
extern "C" void *Scenario_GetInstance(void);
extern "C" void func_ov003_02170960(void *self, int a, int b);
#if defined(jpn)
extern "C" void func_ov003_021701e4(void *self, int a);
#endif

struct Struct_ov003_0216efdc_2;
struct Struct_ov003_0216efdc_3;
extern "C" Struct_ov003_0216efdc_3 *func_ov003_0216f414(Struct_ov003_0216efdc_2 *list, int id);
extern "C" int Scenario_TestFlag(int a, unsigned char *bits, int index);
extern "C" void Scenario_SetFlag(void *a, unsigned char *bits, int index, int set);

struct Struct_ov003_0216efdc_3 {
    unsigned char pad0[0x16];
    unsigned char flags;
};

struct Global0216efdc {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Progress0216efdc {
    unsigned char pad0[0xb38];
    int chapter;
};

struct Struct_02010604_4 {
    volatile unsigned short unknown_0_0_ : 2;
    volatile unsigned short unknown_0_2_ : 14;
};

struct Struct_ov003_0216efdc {
    unsigned char unk_0;
    unsigned char unk_1;
    signed char state_;
    char unk_3;
    unsigned char unk_4;
    unsigned char unk_5;
    signed char unk_6;
    signed char unknown_7_;
    unsigned char unk_8;
    signed char unknown_9_;
    char unk_a[2];
    short unk_c;
    short unknown_e_;
    char unk_10[0x20 - 0x10];
    unsigned short unk_20;
    char unk_22[0xd4 - 0x22];
    void *unknown_d4_;
};

#if defined(jpn)
enum { regionalOffset0 = 0x1860 };
#else
enum { regionalOffset0 = 0x1840 };
#endif

// USA: func_ov003_0216efdc
extern "C" ARM void func_ov003_0216efdc(Struct_ov003_0216efdc *self) {
    Global0216efdc *global     = (Global0216efdc *) MessageSystem_GetInstance();
    Progress0216efdc *progress = (Progress0216efdc *) (Zone3D_GetInstance() + regionalOffset0);
    int chapter                = progress->chapter;
    int state                  = self->state_;
    if (state == 0) {
        volatile unsigned short *bg = (volatile unsigned short *) 0x4000008;
        bg[0]                       = (bg[0] & ~3);
        bg[1]                       = (bg[1] & ~3) | 1;
        bg[2]                       = (bg[2] & ~3) | 2;
        bg[3]                       = (bg[3] & ~3) | 3;
        if (self->unknown_d4_ != 0) {
            Struct_ov003_0216efdc_3 *e = func_ov003_0216f414((Struct_ov003_0216efdc_2 *) self->unknown_d4_, 0x19);
            if (e != 0) {
                e->flags |= 2;
            }
            e = func_ov003_0216f414((Struct_ov003_0216efdc_2 *) self->unknown_d4_, 0x1a);
            if (e != 0) {
                e->flags &= ~2;
            }
        }
        void *save = Scenario_GetInstance();
        if (Scenario_TestFlag((int) save, (unsigned char *) save + 0x8c, 0x783) != 0) {
            self->state_ = 1;
            return;
        }
        Scenario_SetFlag(save, (unsigned char *) save + 0x8c, 0x783, 1);
#if defined(jpn)
        func_ov003_021701e4(self, 0x1f);
#else
        func_ov003_02170960(self, 0x1f, 0);
#endif
        global->unknown_998_ = 1;
        self->unk_20 |= 1;
        self->state_ = 0x65;
    } else if (state == 0x65) {
        if (global->unknown_9a0_ == 0 && global->unknown_998_ == 0) {
            self->state_ = 1;
        }
    } else if (state == 1) {
        if (g_keyManager.TestKeysPressed(2) != 0 || self->unknown_e_ == 5) {
            self->unk_1  = 6;
            self->state_ = 0;
            return;
        }
        if (chapter == 0) {
            return;
        }
        if (g_keyManager.TestKeyRepeat(0x10) != 0 || self->unknown_e_ == 0x11) {
            self->unk_0++;
            if (self->unk_0 > self->unk_4) {
                self->unk_0 = 1;
            }
            int n;
            if (self->unk_0 == self->unk_4 && (n = chapter % 8) != 0) {
                self->unk_5 = n;
            } else {
                self->unk_5 = 8;
            }
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = self->unk_5 - 1;
            }
            self->unknown_7_  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else if (g_keyManager.TestKeyRepeat(0x20) != 0 || self->unknown_e_ == 0x10) {
            self->unk_0--;
            if (self->unk_0 < 1) {
                self->unk_0 = self->unk_4;
            }
            int n;
            if (self->unk_0 == self->unk_4 && (n = chapter % 8) != 0) {
                self->unk_5 = n;
            } else {
                self->unk_5 = 8;
            }
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = self->unk_5 - 1;
            }
            self->unknown_7_  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else if (g_keyManager.TestKeyRepeat(0x80) != 0) {
            self->unk_6 = self->unk_6 + 1;
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = 0;
            }
            self->unknown_7_  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else if (g_keyManager.TestKeyRepeat(0x40) != 0) {
            self->unk_6 = self->unk_6 - 1;
            if (self->unk_6 < 0) {
                self->unk_6 = self->unk_5 - 1;
                if (self->unk_6 < 0) {
                    self->unk_6 = 0;
                }
            }
            self->unknown_7_  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else {
            int sel = -2;
            if (self->unknown_e_ <= 0xd) {
                if (self->unknown_e_ >= 6) {
                    sel = self->unknown_e_ - 6;
                }
            }
            if (g_keyManager.TestKeysPressed(0x401) != 0 || sel == self->unknown_7_) {
                self->unk_8  = 0;
                self->unknown_9_  = -1;
                self->unk_1  = 5;
                self->state_ = 0;
                return;
            }
            if (self->unk_c > 0xd) {
                return;
            }
            if (self->unk_c < 6) {
                return;
            }
            if (g_touchInput.IsPressed() == 0) {
                return;
            }
            self->unk_6 = self->unk_c - 6;
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = self->unk_5 - 1;
            }
            if (self->unknown_7_ != self->unk_6) {
                self->unknown_7_  = self->unk_6;
                self->unk_1  = 2;
                self->state_ = 0;
                return;
            }
        }
    }
}
