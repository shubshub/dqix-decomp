#include <globaldefs.h>
#include "Input/Input.h"

extern "C" char *MessageSystem_GetInstance(void);
extern "C" char *Zone3D_GetInstance(void);
extern "C" void func_ov003_0216fc58(void *self, int a, int b);
extern "C" void func_ov003_0216ff90(void *self);
extern "C" void func_ov003_0216fe74(void *self, int a, int b, int c);
extern "C" void func_ov003_02170960(void *self, int a, void *item);
#if defined(jpn)
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574 *, int, char *);
extern "C" void func_ov003_021701e4(void *self, int a);
#define REGION_NOTIFY(self, a, item) func_ov003_021701e4(self, a)
#else
#define REGION_NOTIFY(self, a, item) func_ov003_02170960(self, a, item)
#endif
extern "C" void func_ov003_02170898(void *self);
extern "C" void func_ov003_02170688(void *self);
extern "C" void func_02098630(void *pool, void *item, int a, int b);
extern "C" int func_020457e0(void *global);

struct Struct_ov003_0216efdc_2;
struct Struct_ov003_0216f474;
struct SePlayer;
struct Struct_02098970;
struct Struct_02098970_2;
struct Struct_02098e70;
struct Struct_02098eac;
extern "C" Struct_ov003_0216f474 *func_ov003_0216f414(Struct_ov003_0216efdc_2 *list, int id);
extern "C" void SePlayer_Play(SePlayer *obj, int a, int b);
extern "C" int func_02098970(Struct_02098970 *pool, Struct_02098970_2 *entry);
extern "C" void func_ov003_0216fb6c(char *pool);
extern "C" int func_02098e70(Struct_02098e70 *p);
extern "C" int func_02098eac(Struct_02098eac *p);

extern int g_sePlayer;

struct Struct_ov003_0216f474 {
    unsigned char pad0[0x16];
    unsigned char flags;
};

struct Global0216f474 {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
};

struct Struct_ov003_0216f474_3 {
    char unk_0[0xc];
    unsigned int unknown_c_0_ : 4;
    unsigned int kind_ : 4;
    unsigned int unknown_d_0_ : 22;
    unsigned int unknown_f_6_ : 1;
    unsigned int unknown_f_7_ : 1;
    char unk_10[0xe8 - 0x10];
};

struct Struct_ov003_0216f474_4 {
    unsigned char unk_0;
    unsigned char unk_1;
    signed char state_;
    char unk_3;
    char unk_4[2];
    signed char unk_6;
    signed char unknown_7_;
    signed char unk_8;
    signed char unknown_9_;
    signed char unk_a;
    char unknown_b_;
    short unk_c;
    short unknown_e_;
    char unk_10[0x20 - 0x10];
    unsigned short unk_20;
    char unk_22[0xd4 - 0x22];
    Struct_ov003_0216efdc_2 *unknown_d4_;
    char unk_d8[0xf4 - 0xd8];
    Struct_ov003_0216f474_3 *items_[30];
    int unknown_16c_;
};

#if defined(jpn)
enum { regionalOffset0 = 0x860 };
#else
enum { regionalOffset0 = 0x840 };
#endif

// USA: func_ov003_0216f474
extern "C" ARM void func_ov003_0216f474(Struct_ov003_0216f474_4 *self) {
    char *base;
    Global0216f474 *global;
    global    = (Global0216f474 *) MessageSystem_GetInstance();
    base      = Zone3D_GetInstance();
    int state = self->state_;
    if (state == 0) {
        if (self->unknown_d4_ != 0) {
            Struct_ov003_0216f474 *e = func_ov003_0216f414(self->unknown_d4_, 0x19);
            if (e != 0) {
                e->flags &= ~2;
            }
            e = func_ov003_0216f414(self->unknown_d4_, 0x1a);
            if (e != 0) {
                e->flags |= 2;
            }
        }
        SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
        Struct_ov003_0216f474_3 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            func_ov003_0216fc58(self, 1, 0);
        } else {
            func_ov003_0216fc58(self, 0, 0);
        }
        self->state_ = 1;
    } else if (state == 1) {
        Struct_ov003_0216f474_3 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (g_keyManager.TestKeysPressed(0x80) != 0) {
            self->unk_8 = self->unk_8 + 1;
            if (self->unk_8 > 2) {
                self->unk_8 = 0;
            }
            self->unknown_9_ = -1;
        } else if (g_keyManager.TestKeysPressed(0x40) != 0) {
            self->unk_8 = self->unk_8 - 1;
            if (self->unk_8 < 0) {
                self->unk_8 = 2;
            }
            self->unknown_9_ = -1;
        }
        int sel = -2;
        if (self->unknown_e_ <= 0x18) {
            if (self->unknown_e_ >= 0x16) {
                sel = self->unknown_e_ - 0x16;
            }
        }
        if (g_keyManager.TestKeysPressed(2) != 0) {
            self->unknown_7_ = -1;
            func_ov003_0216ff90(self);
            self->unk_1  = 2;
            self->state_ = 0;
        } else {
            if (g_keyManager.TestKeysPressed(0x401) != 0 || sel == self->unknown_9_) {
                switch (self->unk_8) {
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
                        self->unknown_7_  = -1;
                        self->unk_1  = 2;
                        self->state_ = 0;
                        break;
                }
            }
        }
        if (self->unk_c <= 0x18 && self->unk_c >= 0x16) {
            self->unk_8 = self->unk_c - 0x16;
            if (self->unknown_9_ != self->unk_8) {
                self->unknown_9_ = self->unk_8;
            }
        }
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            func_ov003_0216fe74(self, 1, self->unk_8, self->unknown_9_);
        } else {
            func_ov003_0216fe74(self, 0, self->unk_8, self->unknown_9_);
        }
    } else if (state == 2) {
        Struct_ov003_0216f474_3 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574 *) global, 0, (char *) item);
#endif
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            REGION_NOTIFY(self, 0x25, item);
            global->unknown_998_   = 1;
            Struct_ov003_0216f474_3 copy = *item;
            func_02098970((Struct_02098970 *) (base + regionalOffset0), (Struct_02098970_2 *) item);
            func_ov003_02170898(self);
            func_ov003_02170688(self);
            func_ov003_0216fb6c(base + regionalOffset0);
            func_02098630(base + regionalOffset0, &copy, 0, 0);
            func_ov003_0216fb6c(base + regionalOffset0);
            func_ov003_02170898(self);
            func_ov003_02170688(self);
            self->unknown_16c_ = 1;
            self->unk_20 |= 8;
            self->state_ = 0x64;
        } else {
            int var9 = func_02098e70((Struct_02098e70 *) (base + regionalOffset0));
            int var10 = func_02098eac((Struct_02098eac *) (base + regionalOffset0));
            if (var9 + var10 >= 6) {
                REGION_NOTIFY(self, 0x21, item);
                global->unknown_998_ = 1;
                self->state_    = 0x64;
            } else {
                REGION_NOTIFY(self, 0x23, item);
                global->unknown_998_ = 1;
                if (var10 > var9) {
                    item->kind_ = 9;
                } else {
                    item->kind_ = 0xa;
                }
                item->unknown_f_6_ = 1;
                func_ov003_02170898(self);
                func_ov003_02170688(self);
                self->unknown_16c_ = 1;
                self->unk_20 |= 8;
                self->state_ = 0x64;
            }
        }
    } else if (state == 3) {
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574 *) global, 0, (char *) self->items_[(self->unk_0 - 1) * 8 + self->unk_6]);
        func_ov003_021701e4(self, 0x26);
#else
        func_ov003_02170960(self, 0x26, self->items_[(self->unk_0 - 1) * 8 + self->unk_6]);
#endif
        global->unknown_998_ = 1;
        self->state_    = 0x65;
    } else if (state == 4) {
        if (self->unk_20 & 2) {
            self->state_ = 5;
        }
    } else if (state == 5) {
        Struct_ov003_0216f474_3 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (self->unknown_d4_ != 0) {
            Struct_ov003_0216f474 *e = func_ov003_0216f414(self->unknown_d4_, 0x19);
            if (e != 0) {
                e->flags &= ~2;
            }
            e = func_ov003_0216f414(self->unknown_d4_, 0x1a);
            if (e != 0) {
                e->flags &= ~2;
            }
            e = func_ov003_0216f414(self->unknown_d4_, 0x1b);
            if (e != 0) {
                e->flags |= 2;
            }
        }
        if ((self->unk_20 & 0x10) == 0) {
            if (self->unk_a != 0) {
                REGION_NOTIFY(self, 0x27, item);
                if (func_02098970((Struct_02098970 *) (base + regionalOffset0), (Struct_02098970_2 *) item) != 0) {
                    func_ov003_02170898(self);
                    func_ov003_02170688(self);
                }
                self->unk_20 |= 8;
                self->state_ = 0x65;
            } else {
                REGION_NOTIFY(self, 0x28, item);
                self->state_ = 0x64;
            }
        }
    } else if (state == 0x64) {
        if (global->unknown_9a0_ == 0 && global->unknown_998_ == 0) {
            if (self->unk_20 & 8) {
                self->unknown_7_ = -1;
                self->unk_20 &= ~8;
                self->unk_1  = 2;
                self->state_ = 0;
            } else {
                self->unknown_7_  = -1;
                self->unk_1  = 2;
                self->state_ = 0;
            }
        }
    } else if (state == 0x65) {
        if (global->unknown_9a0_ != 0 || global->unknown_998_ != 0) {
            return;
        }
        {
            Struct_ov003_0216f474_3 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
            if (func_020457e0(global) == 0) {
                if (func_02098970((Struct_02098970 *) (base + regionalOffset0), (Struct_02098970_2 *) item) != 0) {
                    func_ov003_02170898(self);
                    func_ov003_02170688(self);
                }
                self->unk_20 |= 8;
            }
            if (self->unk_20 & 8) {
                self->unknown_7_ = -1;
                self->unk_20 &= ~8;
                self->unk_1  = 2;
                self->state_ = 0;
            } else {
                self->unknown_7_  = -1;
                self->unk_1  = 2;
                self->state_ = 0;
            }
        }
    }
}
