#include <globaldefs.h>
#include "Input/Input.h"



char *MessageSystem_GetInstance(void);
extern "C" char *Zone3D_GetInstance(void);
extern "C" void *Scenario_GetInstance(void);
extern "C" void func_ov003_02170960(void *self, int a, int b);
#if defined(jpn)
extern "C" void func_ov003_021701e4(void *arg0, int arg1);
#endif

struct Obj_0216f414;
struct Entry0216efdc;
Entry0216efdc *FindEntryByShortId_0216f414(Obj_0216f414 *list, int id);
int Scenario_TestFlag(int a, unsigned char *bits, int index);
extern "C" void Scenario_SetFlag(void *a, unsigned char *bits, int index, int set);

struct Struct_ov003_0216efdc_3 {
    unsigned char unknown_0_[0x16];
    unsigned char unknown_16_;
};

struct Struct_ov003_0216efdc_4 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Struct_ov003_0216efdc_5 {
    unsigned char unknown_0_[0xb38];
    int unknown_b38_;
};

struct Struct_02010604_4 {
    volatile unsigned short unknown_0_0_ : 2;
    volatile unsigned short unknown_0_2_ : 14;
};

struct Struct_ov003_0216efdc {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    signed char unknown_2_;
    char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    signed char unknown_6_;
    signed char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_9_;
    char unknown_a_[2];
    short unknown_c_;
    short unknown_e_;
    char unknown_10_[0x20 - 0x10];
    unsigned short unknown_20_;
    char unknown_22_[0xd4 - 0x22];
    void *unknown_d4_;
};

#if defined(jpn)
enum { Enum_ov003_0216efdc_6208 = 0x1860 };
#else
enum { Enum_ov003_0216efdc_6208 = 0x1840 };
#endif

// USA: func_ov003_0216efdc
extern "C" ARM void func_ov003_0216efdc(Menu0216efdc *self) {
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
        if (self->unk_d4 != 0) {
            Entry0216efdc *e = FindEntryByShortId_0216f414((Obj_0216f414 *) self->unk_d4, 0x19);
            if (e != 0) {
                e->flags |= 2;
            }
            var5 = func_ov003_0216f414((Struct_ov003_0216efdc_2 *) arg0->unknown_d4_, 0x1a);
            if (var5 != 0) {
                var5->unknown_16_ &= ~2;
            }
        }
        void *save = Scenario_GetInstance();
        if (Scenario_TestFlag((int) save, (unsigned char *) save + 0x8c, 0x783) != 0) {
            self->state_ = 1;
            return;
        }
        Scenario_SetFlag(save, (unsigned char *) save + 0x8c, 0x783, 1);
#if defined(jpn)
        func_ov003_021701e4(arg0, 0x1f);
#else
        func_ov003_02170960(arg0, 0x1f, 0);
#endif
        var0->unknown_998_ = 1;
        arg0->unknown_20_ |= 1;
        arg0->unknown_2_ = 0x65;
    } else if (var3 == 0x65) {
        if (var0->unknown_9a0_ == 0 && var0->unknown_998_ == 0) {
            arg0->unknown_2_ = 1;
        }
    } else if (var3 == 1) {
        if (g_keyManager.TestKeysPressed(2) != 0 || arg0->unknown_e_ == 5) {
            arg0->unknown_1_  = 6;
            arg0->unknown_2_ = 0;
            return;
        }
        if (var2 == 0) {
            return;
        }
        if (g_keyManager.TestKeyRepeat(0x10) != 0 || arg0->unknown_e_ == 0x11) {
            arg0->unknown_0_++;
            if (arg0->unknown_0_ > arg0->unknown_4_) {
                arg0->unknown_0_ = 1;
            }
            int var7;
            if (arg0->unknown_0_ == arg0->unknown_4_ && (var7 = var2 % 8) != 0) {
                arg0->unknown_5_ = var7;
            } else {
                arg0->unknown_5_ = 8;
            }
            if (arg0->unknown_6_ > arg0->unknown_5_ - 1) {
                arg0->unknown_6_ = arg0->unknown_5_ - 1;
            }
            arg0->unknown_7_  = -1;
            arg0->unknown_1_  = 2;
            arg0->unknown_2_ = 0;
        } else if (g_keyManager.TestKeyRepeat(0x20) != 0 || arg0->unknown_e_ == 0x10) {
            arg0->unknown_0_--;
            if (arg0->unknown_0_ < 1) {
                arg0->unknown_0_ = arg0->unknown_4_;
            }
            int var8;
            if (arg0->unknown_0_ == arg0->unknown_4_ && (var8 = var2 % 8) != 0) {
                arg0->unknown_5_ = var8;
            } else {
                arg0->unknown_5_ = 8;
            }
            if (arg0->unknown_6_ > arg0->unknown_5_ - 1) {
                arg0->unknown_6_ = arg0->unknown_5_ - 1;
            }
            arg0->unknown_7_  = -1;
            arg0->unknown_1_  = 2;
            arg0->unknown_2_ = 0;
        } else if (g_keyManager.TestKeyRepeat(0x80) != 0) {
            arg0->unknown_6_ = arg0->unknown_6_ + 1;
            if (arg0->unknown_6_ > arg0->unknown_5_ - 1) {
                arg0->unknown_6_ = 0;
            }
            arg0->unknown_7_  = -1;
            arg0->unknown_1_  = 2;
            arg0->unknown_2_ = 0;
        } else if (g_keyManager.TestKeyRepeat(0x40) != 0) {
            arg0->unknown_6_ = arg0->unknown_6_ - 1;
            if (arg0->unknown_6_ < 0) {
                arg0->unknown_6_ = arg0->unknown_5_ - 1;
                if (arg0->unknown_6_ < 0) {
                    arg0->unknown_6_ = 0;
                }
            }
            arg0->unknown_7_  = -1;
            arg0->unknown_1_  = 2;
            arg0->unknown_2_ = 0;
        } else {
            int var9 = -2;
            if (arg0->unknown_e_ <= 0xd) {
                if (arg0->unknown_e_ >= 6) {
                    var9 = arg0->unknown_e_ - 6;
                }
            }
            if (g_keyManager.TestKeysPressed(0x401) != 0 || var9 == arg0->unknown_7_) {
                arg0->unknown_8_  = 0;
                arg0->unknown_9_  = -1;
                arg0->unknown_1_  = 5;
                arg0->unknown_2_ = 0;
                return;
            }
            if (arg0->unknown_c_ > 0xd) {
                return;
            }
            if (arg0->unknown_c_ < 6) {
                return;
            }
            if (g_touchInput.IsPressed() == 0) {
                return;
            }
            arg0->unknown_6_ = arg0->unknown_c_ - 6;
            if (arg0->unknown_6_ > arg0->unknown_5_ - 1) {
                arg0->unknown_6_ = arg0->unknown_5_ - 1;
            }
            if (arg0->unknown_7_ != arg0->unknown_6_) {
                arg0->unknown_7_  = arg0->unknown_6_;
                arg0->unknown_1_  = 2;
                arg0->unknown_2_ = 0;
                return;
            }
        }
    }
}
