#include <globaldefs.h>
#include "Input/Input.h"

extern "C" char *func_020421a0(void);
extern "C" char *func_02012fe4(void);
extern "C" void func_ov003_0216fc58(void *arg0, int arg1, int arg2);
extern "C" void func_ov003_0216ff90(void *arg0);
extern "C" void func_ov003_0216fe74(void *arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov003_02170960(void *arg0, int arg1, void *arg2);
#if defined(jpn)
struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2 *, int, char *);
extern "C" void func_ov003_021701e4(void *arg0, int arg1);
#define REGION_NOTIFY(self, a, item) func_ov003_021701e4(self, a)
#else
#define REGION_NOTIFY(self, a, item) func_ov003_02170960(self, a, item)
#endif
extern "C" void func_ov003_02170898(void *arg0);
extern "C" void func_ov003_02170688(void *arg0);
extern "C" void func_02098630(void *arg0, void *arg1, int arg2, int arg3);
extern "C" int func_020457e0(void *arg0);

struct Obj_0216f414;
struct Entry0216f474;
struct SePlayer;
struct Pool02098970;
struct Entry02098970;
struct NibbleElem02098e70;
struct NibbleElem02098eac;
Entry0216f474 *FindEntryByShortId_0216f414(Obj_0216f414 *list, int id);
void SePlayer_Play(SePlayer *obj, int a, int b);
int ReleaseEntryIfInPool(Pool02098970 *pool, Entry02098970 *entry);
void ResetFieldsB68AndB74_0216fb6c(char *pool);
int CountNibble0xcEquals9(NibbleElem02098e70 *p);
int CountNibble0xcEqualsA(NibbleElem02098eac *p);

extern int g_sePlayer;

struct Struct_ov003_0216f474 {
    unsigned char unknown_0_[0x16];
    unsigned char unknown_16_;
};

struct Struct_ov003_0216f474_2 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Struct_ov003_0216f474_3 {
    char unknown_0_[0xc];
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 22;
    unsigned int unknown_f_6_ : 1;
    unsigned int unknown_f_7_ : 1;
    char unknown_10_[0xe8 - 0x10];
};

struct Struct_ov003_0216f474_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    signed char unknown_2_;
    char unknown_3_;
    char unknown_4_[2];
    signed char unknown_6_;
    signed char unknown_7_;
    signed char unknown_8_;
    signed char unknown_9_;
    signed char unknown_a_;
    char unknown_b_;
    short unknown_c_;
    short unknown_e_;
    char unknown_10_[0x20 - 0x10];
    unsigned short unknown_20_;
    char unknown_22_[0xd4 - 0x22];
    Struct_ov003_0216efdc_2 *unknown_d4_;
    char unknown_d8_[0xf4 - 0xd8];
    Struct_ov003_0216f474_3 *unknown_f4_[30];
    int unknown_16c_;
};

#if defined(jpn)
enum { Enum_ov003_0216f474_2112 = 0x860 };
#else
enum { Enum_ov003_0216f474_2112 = 0x840 };
#endif

// USA: func_ov003_0216f474
extern "C" ARM void func_ov003_0216f474(Struct_ov003_0216f474_4 *arg0) {
    char *var0;
    Struct_ov003_0216f474_2 *var1;
    var1    = (Struct_ov003_0216f474_2 *) func_020421a0();
    var0      = func_02012fe4();
    int var2 = arg0->unknown_2_;
    if (var2 == 0) {
        if (arg0->unknown_d4_ != 0) {
            Struct_ov003_0216f474 *var3 = func_ov003_0216f414(arg0->unknown_d4_, 0x19);
            if (var3 != 0) {
                var3->unknown_16_ &= ~2;
            }
            var3 = func_ov003_0216f414(arg0->unknown_d4_, 0x1a);
            if (var3 != 0) {
                var3->unknown_16_ |= 2;
            }
        }
        SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
        Item0216f474 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            func_ov003_0216fc58(self, 1, 0);
        } else {
            func_ov003_0216fc58(arg0, 0, 0);
        }
        arg0->unknown_2_ = 1;
    } else if (var2 == 1) {
        Struct_ov003_0216f474_3 *var5 = arg0->unknown_f4_[(arg0->unknown_0_ - 1) * 8 + arg0->unknown_6_];
        if (g_keyManager.TestKeysPressed(0x80) != 0) {
            arg0->unknown_8_ = arg0->unknown_8_ + 1;
            if (arg0->unknown_8_ > 2) {
                arg0->unknown_8_ = 0;
            }
            arg0->unknown_9_ = -1;
        } else if (g_keyManager.TestKeysPressed(0x40) != 0) {
            arg0->unknown_8_ = arg0->unknown_8_ - 1;
            if (arg0->unknown_8_ < 0) {
                arg0->unknown_8_ = 2;
            }
            arg0->unknown_9_ = -1;
        }
        int var6 = -2;
        if (arg0->unknown_e_ <= 0x18) {
            if (arg0->unknown_e_ >= 0x16) {
                var6 = arg0->unknown_e_ - 0x16;
            }
        }
        if (g_keyManager.TestKeysPressed(2) != 0) {
            arg0->unknown_7_ = -1;
            func_ov003_0216ff90(arg0);
            arg0->unknown_1_  = 2;
            arg0->unknown_2_ = 0;
        } else {
            if (g_keyManager.TestKeysPressed(0x401) != 0 || var6 == arg0->unknown_9_) {
                switch (arg0->unknown_8_) {
                    case 0:
                        SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
                        func_ov003_0216ff90(self);
                        self->state_ = 2;
                        break;
                    case 1:
                        SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
                        func_ov003_0216ff90(self);
                        self->state_ = 3;
                        break;
                    case 2:
                        SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
                        func_ov003_0216ff90(self);
                        self->unk_7  = -1;
                        self->unk_1  = 2;
                        self->state_ = 0;
                        break;
                }
            }
        }
        if (arg0->unknown_c_ <= 0x18 && arg0->unknown_c_ >= 0x16) {
            arg0->unknown_8_ = arg0->unknown_c_ - 0x16;
            if (arg0->unknown_9_ != arg0->unknown_8_) {
                arg0->unknown_9_ = arg0->unknown_8_;
            }
        }
        if (var5->unknown_c_4_ == 9 || var5->unknown_c_4_ == 0xa) {
            func_ov003_0216fe74(arg0, 1, arg0->unknown_8_, arg0->unknown_9_);
        } else {
            func_ov003_0216fe74(arg0, 0, arg0->unknown_8_, arg0->unknown_9_);
        }
    } else if (var2 == 2) {
        Struct_ov003_0216f474_3 *var7 = arg0->unknown_f4_[(arg0->unknown_0_ - 1) * 8 + arg0->unknown_6_];
#if defined(jpn)
        func_02046574((Struct_02046574_2 *) var1, 0, (char *) var7);
#endif
        if (var7->unknown_c_4_ == 9 || var7->unknown_c_4_ == 0xa) {
            REGION_NOTIFY(arg0, 0x25, var7);
            var1->unknown_998_   = 1;
            Struct_ov003_0216f474_3 var8 = *var7;
            func_02098970((Struct_02098970 *) (var0 + Enum_ov003_0216f474_2112), (Struct_02098970_2 *) var7);
            func_ov003_02170898(arg0);
            func_ov003_02170688(arg0);
            func_ov003_0216fb6c(var0 + Enum_ov003_0216f474_2112);
            func_02098630(var0 + Enum_ov003_0216f474_2112, &var8, 0, 0);
            func_ov003_0216fb6c(var0 + Enum_ov003_0216f474_2112);
            func_ov003_02170898(arg0);
            func_ov003_02170688(arg0);
            arg0->unknown_16c_ = 1;
            arg0->unknown_20_ |= 8;
            arg0->unknown_2_ = 0x64;
        } else {
            int var9 = func_02098e70((Struct_02098e70 *) (var0 + Enum_ov003_0216f474_2112));
            int var10 = func_02098eac((Struct_02098eac *) (var0 + Enum_ov003_0216f474_2112));
            if (var9 + var10 >= 6) {
                REGION_NOTIFY(arg0, 0x21, var7);
                var1->unknown_998_ = 1;
                arg0->unknown_2_    = 0x64;
            } else {
                REGION_NOTIFY(arg0, 0x23, var7);
                var1->unknown_998_ = 1;
                if (var10 > var9) {
                    var7->unknown_c_4_ = 9;
                } else {
                    var7->unknown_c_4_ = 0xa;
                }
                var7->unknown_f_6_ = 1;
                func_ov003_02170898(arg0);
                func_ov003_02170688(arg0);
                arg0->unknown_16c_ = 1;
                arg0->unknown_20_ |= 8;
                arg0->unknown_2_ = 0x64;
            }
        }
    } else if (var2 == 3) {
#if defined(jpn)
        func_02046574((Struct_02046574_2 *) var1, 0, (char *) arg0->unknown_f4_[(arg0->unknown_0_ - 1) * 8 + arg0->unknown_6_]);
        func_ov003_021701e4(arg0, 0x26);
#else
        func_ov003_02170960(arg0, 0x26, arg0->unknown_f4_[(arg0->unknown_0_ - 1) * 8 + arg0->unknown_6_]);
#endif
        var1->unknown_998_ = 1;
        arg0->unknown_2_    = 0x65;
    } else if (var2 == 4) {
        if (arg0->unknown_20_ & 2) {
            arg0->unknown_2_ = 5;
        }
    } else if (var2 == 5) {
        Struct_ov003_0216f474_3 *var11 = arg0->unknown_f4_[(arg0->unknown_0_ - 1) * 8 + arg0->unknown_6_];
        if (arg0->unknown_d4_ != 0) {
            Struct_ov003_0216f474 *var12 = func_ov003_0216f414(arg0->unknown_d4_, 0x19);
            if (var12 != 0) {
                var12->unknown_16_ &= ~2;
            }
            var12 = func_ov003_0216f414(arg0->unknown_d4_, 0x1a);
            if (var12 != 0) {
                var12->unknown_16_ &= ~2;
            }
            var12 = func_ov003_0216f414(arg0->unknown_d4_, 0x1b);
            if (var12 != 0) {
                var12->unknown_16_ |= 2;
            }
        }
        if ((arg0->unknown_20_ & 0x10) == 0) {
            if (arg0->unknown_a_ != 0) {
                REGION_NOTIFY(arg0, 0x27, var11);
                if (func_02098970((Struct_02098970 *) (var0 + Enum_ov003_0216f474_2112), (Struct_02098970_2 *) var11) != 0) {
                    func_ov003_02170898(arg0);
                    func_ov003_02170688(arg0);
                }
                arg0->unknown_20_ |= 8;
                arg0->unknown_2_ = 0x65;
            } else {
                REGION_NOTIFY(arg0, 0x28, var11);
                arg0->unknown_2_ = 0x64;
            }
        }
    } else if (var2 == 0x64) {
        if (var1->unknown_9a0_ == 0 && var1->unknown_998_ == 0) {
            if (arg0->unknown_20_ & 8) {
                arg0->unknown_7_ = -1;
                arg0->unknown_20_ &= ~8;
                arg0->unknown_1_  = 2;
                arg0->unknown_2_ = 0;
            } else {
                arg0->unknown_7_  = -1;
                arg0->unknown_1_  = 2;
                arg0->unknown_2_ = 0;
            }
        }
    } else if (var2 == 0x65) {
        if (var1->unknown_9a0_ != 0 || var1->unknown_998_ != 0) {
            return;
        }
        {
            Struct_ov003_0216f474_3 *var13 = arg0->unknown_f4_[(arg0->unknown_0_ - 1) * 8 + arg0->unknown_6_];
            if (func_020457e0(var1) == 0) {
                if (func_02098970((Struct_02098970 *) (var0 + Enum_ov003_0216f474_2112), (Struct_02098970_2 *) var13) != 0) {
                    func_ov003_02170898(arg0);
                    func_ov003_02170688(arg0);
                }
                arg0->unknown_20_ |= 8;
            }
            if (arg0->unknown_20_ & 8) {
                arg0->unknown_7_ = -1;
                arg0->unknown_20_ &= ~8;
                arg0->unknown_1_  = 2;
                arg0->unknown_2_ = 0;
            } else {
                arg0->unknown_7_  = -1;
                arg0->unknown_1_  = 2;
                arg0->unknown_2_ = 0;
            }
        }
    }
}
