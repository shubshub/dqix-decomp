#include <globaldefs.h>
#include "Input/Input.h"

char *GetGlobalField0x1c020421a0(void);
extern "C" char *func_02012fe4(void);
extern "C" void func_ov003_0216fc58(void *self, int a, int b);
extern "C" void func_ov003_0216ff90(void *self);
extern "C" void func_ov003_0216fe74(void *self, int a, int b, int c);
extern "C" void func_ov003_02170960(void *self, int a, void *item);
#if defined(jpn)
struct Obj02046574;
void SetIndexedName02046574(Obj02046574 *, int, char *);
extern "C" void func_ov003_021701e4(void *self, int a);
#define REGION_NOTIFY(self, a, item) func_ov003_021701e4(self, a)
#else
#define REGION_NOTIFY(self, a, item) func_ov003_02170960(self, a, item)
#endif
extern "C" void func_ov003_02170898(void *self);
extern "C" void func_ov003_02170688(void *self);
extern "C" void func_02098630(void *pool, void *item, int a, int b);
extern "C" int func_020457e0(void *global);

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

struct Entry0216f474 {
    unsigned char pad0[0x16];
    unsigned char flags;
};

struct Global0216f474 {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
    int unk_998;
    char unk_99c[4];
    int unk_9a0;
};

struct Item0216f474 {
    char unk_0[0xc];
    unsigned int low_ : 4;
    unsigned int kind_ : 4;
    unsigned int mid_ : 22;
    unsigned int flag_ : 1;
    unsigned int top_ : 1;
    char unk_10[0xe8 - 0x10];
};

struct Menu0216f474 {
    unsigned char unk_0;
    unsigned char unk_1;
    signed char state_;
    char unk_3;
    char unk_4[2];
    signed char unk_6;
    signed char unk_7;
    signed char unk_8;
    signed char unk_9;
    signed char unk_a;
    char unk_b;
    short unk_c;
    short unk_e;
    char unk_10[0x20 - 0x10];
    unsigned short unk_20;
    char unk_22[0xd4 - 0x22];
    Obj_0216f414 *unk_d4;
    char unk_d8[0xf4 - 0xd8];
    Item0216f474 *items_[30];
    int unk_16c;
};

#if defined(jpn)
enum { regionalOffset0 = 0x860 };
#else
enum { regionalOffset0 = 0x840 };
#endif

// USA: func_ov003_0216f474
extern "C" ARM void func_ov003_0216f474(Menu0216f474 *self) {
    char *base;
    Global0216f474 *global;
    global    = (Global0216f474 *) GetGlobalField0x1c020421a0();
    base      = func_02012fe4();
    int state = self->state_;
    if (state == 0) {
        if (self->unk_d4 != 0) {
            Entry0216f474 *e = FindEntryByShortId_0216f414(self->unk_d4, 0x19);
            if (e != 0) {
                e->flags &= ~2;
            }
            e = FindEntryByShortId_0216f414(self->unk_d4, 0x1a);
            if (e != 0) {
                e->flags |= 2;
            }
        }
        SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
        Item0216f474 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            func_ov003_0216fc58(self, 1, 0);
        } else {
            func_ov003_0216fc58(self, 0, 0);
        }
        self->state_ = 1;
    } else if (state == 1) {
        Item0216f474 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (g_keyManager.TestKeysPressed(0x80) != 0) {
            self->unk_8 = self->unk_8 + 1;
            if (self->unk_8 > 2) {
                self->unk_8 = 0;
            }
            self->unk_9 = -1;
        } else if (g_keyManager.TestKeysPressed(0x40) != 0) {
            self->unk_8 = self->unk_8 - 1;
            if (self->unk_8 < 0) {
                self->unk_8 = 2;
            }
            self->unk_9 = -1;
        }
        int sel = -2;
        if (self->unk_e <= 0x18) {
            if (self->unk_e >= 0x16) {
                sel = self->unk_e - 0x16;
            }
        }
        if (g_keyManager.TestKeysPressed(2) != 0) {
            self->unk_7 = -1;
            func_ov003_0216ff90(self);
            self->unk_1  = 2;
            self->state_ = 0;
        } else {
            if (g_keyManager.TestKeysPressed(0x401) != 0 || sel == self->unk_9) {
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
                        self->unk_7  = -1;
                        self->unk_1  = 2;
                        self->state_ = 0;
                        break;
                }
            }
        }
        if (self->unk_c <= 0x18 && self->unk_c >= 0x16) {
            self->unk_8 = self->unk_c - 0x16;
            if (self->unk_9 != self->unk_8) {
                self->unk_9 = self->unk_8;
            }
        }
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            func_ov003_0216fe74(self, 1, self->unk_8, self->unk_9);
        } else {
            func_ov003_0216fe74(self, 0, self->unk_8, self->unk_9);
        }
    } else if (state == 2) {
        Item0216f474 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
#if defined(jpn)
        SetIndexedName02046574((Obj02046574 *) global, 0, (char *) item);
#endif
        if (item->kind_ == 9 || item->kind_ == 0xa) {
            REGION_NOTIFY(self, 0x25, item);
            global->unk_998   = 1;
            Item0216f474 copy = *item;
            ReleaseEntryIfInPool((Pool02098970 *) (base + regionalOffset0), (Entry02098970 *) item);
            func_ov003_02170898(self);
            func_ov003_02170688(self);
            ResetFieldsB68AndB74_0216fb6c(base + regionalOffset0);
            func_02098630(base + regionalOffset0, &copy, 0, 0);
            ResetFieldsB68AndB74_0216fb6c(base + regionalOffset0);
            func_ov003_02170898(self);
            func_ov003_02170688(self);
            self->unk_16c = 1;
            self->unk_20 |= 8;
            self->state_ = 0x64;
        } else {
            int n9 = CountNibble0xcEquals9((NibbleElem02098e70 *) (base + regionalOffset0));
            int nA = CountNibble0xcEqualsA((NibbleElem02098eac *) (base + regionalOffset0));
            if (n9 + nA >= 6) {
                REGION_NOTIFY(self, 0x21, item);
                global->unk_998 = 1;
                self->state_    = 0x64;
            } else {
                REGION_NOTIFY(self, 0x23, item);
                global->unk_998 = 1;
                if (nA > n9) {
                    item->kind_ = 9;
                } else {
                    item->kind_ = 0xa;
                }
                item->flag_ = 1;
                func_ov003_02170898(self);
                func_ov003_02170688(self);
                self->unk_16c = 1;
                self->unk_20 |= 8;
                self->state_ = 0x64;
            }
        }
    } else if (state == 3) {
#if defined(jpn)
        SetIndexedName02046574((Obj02046574 *) global, 0, (char *) self->items_[(self->unk_0 - 1) * 8 + self->unk_6]);
        func_ov003_021701e4(self, 0x26);
#else
        func_ov003_02170960(self, 0x26, self->items_[(self->unk_0 - 1) * 8 + self->unk_6]);
#endif
        global->unk_998 = 1;
        self->state_    = 0x65;
    } else if (state == 4) {
        if (self->unk_20 & 2) {
            self->state_ = 5;
        }
    } else if (state == 5) {
        Item0216f474 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
        if (self->unk_d4 != 0) {
            Entry0216f474 *e = FindEntryByShortId_0216f414(self->unk_d4, 0x19);
            if (e != 0) {
                e->flags &= ~2;
            }
            e = FindEntryByShortId_0216f414(self->unk_d4, 0x1a);
            if (e != 0) {
                e->flags &= ~2;
            }
            e = FindEntryByShortId_0216f414(self->unk_d4, 0x1b);
            if (e != 0) {
                e->flags |= 2;
            }
        }
        if ((self->unk_20 & 0x10) == 0) {
            if (self->unk_a != 0) {
                REGION_NOTIFY(self, 0x27, item);
                if (ReleaseEntryIfInPool((Pool02098970 *) (base + regionalOffset0), (Entry02098970 *) item) != 0) {
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
        if (global->unk_9a0 == 0 && global->unk_998 == 0) {
            if (self->unk_20 & 8) {
                self->unk_7 = -1;
                self->unk_20 &= ~8;
                self->unk_1  = 2;
                self->state_ = 0;
            } else {
                self->unk_7  = -1;
                self->unk_1  = 2;
                self->state_ = 0;
            }
        }
    } else if (state == 0x65) {
        if (global->unk_9a0 != 0 || global->unk_998 != 0) {
            return;
        }
        {
            Item0216f474 *item = self->items_[(self->unk_0 - 1) * 8 + self->unk_6];
            if (func_020457e0(global) == 0) {
                if (ReleaseEntryIfInPool((Pool02098970 *) (base + regionalOffset0), (Entry02098970 *) item) != 0) {
                    func_ov003_02170898(self);
                    func_ov003_02170688(self);
                }
                self->unk_20 |= 8;
            }
            if (self->unk_20 & 8) {
                self->unk_7 = -1;
                self->unk_20 &= ~8;
                self->unk_1  = 2;
                self->state_ = 0;
            } else {
                self->unk_7  = -1;
                self->unk_1  = 2;
                self->state_ = 0;
            }
        }
    }
}
