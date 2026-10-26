#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include <globaldefs.h>

struct Struct_0205c570;
struct Struct_0205cf1c;
struct SePlayer;

#if defined(jpn)
enum { Enum_ov003_0215d150_0 = 0x18, Enum_ov003_0215d150_0_2 = -0x34, Enum_ov003_0215d150_0_3 = -0x130, Enum_ov003_0215d150_0_4 = -0x1d0, Enum_ov003_0215d150_0_5 = 0x20 };
#else
enum { Enum_ov003_0215d150_0 = 0, Enum_ov003_0215d150_0_2 = 0, Enum_ov003_0215d150_0_3 = 0, Enum_ov003_0215d150_0_4 = 0, Enum_ov003_0215d150_0_5 = 0 };
#endif

struct Ctl {
    char pad0[0x5c + Enum_ov003_0215d150_0_2];
    char *strings;
    char pad60[0x998 - 0x60 + Enum_ov003_0215d150_0_3 - Enum_ov003_0215d150_0_2];
    int unknown_998_;
    char unknown_99c_[4];
    int w9a0;
};

struct Scene {
    char pad0[0x64];
    Container020e0310 cont64;
    char pad6c[0x98 - 0x6c + Enum_ov003_0215d150_0];
    char list98[0x3b8 - 0x98];
    unsigned char state;
    char unknown_3b9_[2];
    unsigned char unknown_3bb_;
    unsigned char unknown_3bc_;
    unsigned char unknown_3bd_[4];
    signed char b3c1;
    unsigned char unknown_3c2_;
    unsigned char unknown_3c3_;
    char unknown_3c4_[0x3cc - 0x3c4];
    int w3cc;
    int unknown_3d0_;
    char unknown_3d4_[0x3ec - 0x3d4];
    unsigned char unknown_3ec_;
    unsigned char unknown_3ed_;
    char unknown_3ee_[2];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    unsigned char unknown_3f2_;
};

struct Struct_01ff91ac_29 {
    char pad0[0xb3c];
    int unknown_b3c_;
};

struct Zone {
    char pad0[0x1840 + Enum_ov003_0215d150_0_5];
    Struct_01ff91ac_29 sub;
};

static inline Struct_01ff91ac_29 *inline_ov003_0215d150(Zone *z) { return &z->sub; }
static inline int inline_ov003_0215d150_2(Struct_01ff91ac_29 *s) { return s->unknown_b3c_; }

extern "C" Ctl *MessageSystem_GetInstance();
extern "C" int *LinkSession_GetInstance();
extern "C" Zone *Zone3D_GetInstance();
extern "C" void func_02046380(void *obj);
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char *, int, unsigned char);
extern "C" int LinkSession_IsActive(int *p);
extern "C" int LinkSession_IsGuest(int *p);
extern "C" int LinkSession_IsHostOrSolo(int *p);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" const char * KeyTable_Get(Container020e0310*, int);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" void func_ov003_0215cab0(char *obj, void *flag);
extern "C" void func_ov003_0215ddc0(char *base);
extern "C" void func_ov003_0215df1c(void *self);
extern "C" void func_ov003_0215dd3c(char *obj);
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(Struct_0205d81c*, int, int);
extern "C" void func_0205cef8(void *obj);
extern "C" void func_0205cf04(void *obj);
extern "C" int Window_GetSelectedIndex(Struct_0205c570 *);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void SePlayer_Play(SePlayer *, int, int);
extern "C" void func_0205cf10(void *p);
extern "C" void func_0205cf1c(Struct_0205cf1c *);
extern "C" int func_ov003_0215dcb8(char *obj);
extern "C" ARM int func_ov003_0215dd00(char *self);

extern int g_sePlayer;

// USA: func_ov003_0215d150
extern "C" ARM void func_ov003_0215d150(Scene *self) {
    GameState *gs = GameState::GetInstance();
    Ctl *g       = MessageSystem_GetInstance();
    int *a       = LinkSession_GetInstance();
    Zone *b      = Zone3D_GetInstance();

    if (g->w9a0 == 3) {
        *(unsigned char *) ((char *) g + 0x1000 + 0x9ae + Enum_ov003_0215d150_0_4) = 0;
    }

    unsigned char state = self->state;
    int k1;

    if (state == 0) {
        func_02046380(g);
        func_020465c0((StoreStruct*)g, 0, self->unknown_3c3_);
        func_020465f0((unsigned char *) g, 0, 0);
        func_020465c0((StoreStruct*)g, 1, self->w3cc);
        func_020465f0((unsigned char *) g, 1, 0);

        int sb;
        sb = (self->unknown_3d0_ == 0) ? 1 : 0;
        if (LinkSession_IsActive(a) != 0) {
            if (LinkSession_IsGuest(a) != 0) {
                sb = 2;
            }
        }
        g->unknown_998_ = 1;

        char *buf = g->strings;
        if (self->unknown_3f0_ != 0) {
            MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)(*(void **) ((char *) gs->GetPartyMemberByIndex(0) + 0x134)));

            int flag = 0;
            if (LinkSession_IsHostOrSolo(a) != 0) {
                flag = (*(short *) ((char *) gs->GetLeader() + 4) == 0) ? 1 : 0;
            }

            if (flag != 0) {
                Text_Append(buf, KeyTable_Get(&self->cont64, (short)0x64));
            }

            if (inline_ov003_0215d150_2(inline_ov003_0215d150(b)) == 6) {
                k1 = 0x67;
            } else if (self->unknown_3d0_ != 0) {
                k1 = 0x65;
            } else {
                k1 = 0x68;
            }
            Text_Append(buf, KeyTable_Get(&self->cont64, (short)k1));

            if (flag == 0) {
                Text_Append(buf, KeyTable_Get(&self->cont64, (short)0x6f));
            } else {
                int k2;
                k2 = (self->unknown_3d0_ != 0) ? 0x66 : 0x69;
                Text_Append(buf, KeyTable_Get(&self->cont64, (short)k2));
            }
        } else {
            int k0 = sb + 0x3e8;
            Text_Append(buf, KeyTable_Get(&self->cont64, (short)k0));
        }

        func_ov003_0215cab0((char *) self, buf);
        self->state = self->state + 1;
    }

    if (state == 1) {
        if (g->w9a0 != 3) {
            return;
        }
        self->unknown_3ec_ = 1;
        self->unknown_3ed_ = 0;
        self->state = self->state + 1;
    }
    if (state == 2) {
        if (self->unknown_3ec_ != 0) {
            return;
        }
        if (self->unknown_3f2_ == 0) {
            func_ov003_0215ddc0((char *) self);
        }
        func_ov003_0215df1c(self);
        Window_SetPanePalette((Struct_0205d81c*)self->list98, 0, 0);
        self->state = self->state + 1;
    }
    if (state == 3) {
        self->b3c1 = 0;
        func_ov003_0215dd3c((char *) self);
        func_0205cef8(self->list98);
        func_0205cf04(self->list98);
        self->state = self->state + 1;
    }
    if (state == 4) {
        self->unknown_3c2_ = 1;
        self->b3c1 = Window_GetSelectedIndex((Struct_0205c570 *) self->list98);
        if (func_ov003_0215dcb8((char *) self) != 0) {
            self->unknown_3c2_ = 0;
            Window_ClosePane((Entry_0205d6a0*)self->list98, 0);
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            func_0205cf10(self->list98);
            func_0205cf1c((Struct_0205cf1c *) self->list98);
            switch (self->unknown_3bd_[self->b3c1]) {
            case 0: self->unknown_3bc_ = 2; break;
            case 1: self->unknown_3bc_ = 3; break;
            case 2: self->unknown_3bc_ = 4; break;
            }
            self->state = 0;
        } else {
            if (func_ov003_0215dd00((char *) self) != 0) {
                self->unknown_3c2_ = 0;
                Window_ClosePane((Entry_0205d6a0*)self->list98, 0);
                func_0205cf10(self->list98);
                func_0205cf1c((Struct_0205cf1c *) self->list98);
                self->unknown_3bc_ = 4;
                self->state = 0;
            }
        }
    }
}
