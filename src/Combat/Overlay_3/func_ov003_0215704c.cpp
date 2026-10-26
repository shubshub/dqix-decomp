#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" {
extern "C" int func_02080468(void *, int);
extern "C" void func_ov003_0215385c(void *);
void func_ov003_02158480(void *);
extern "C" void func_0208203c(void *);
extern "C" void func_ov003_021538f4(void *, int);
extern "C" int func_ov003_02156034(void *);
int _Z31IsSubBrightnessTransitionActiveP13GameResources(void *);
int func_ov003_021550dc(void *);
extern "C" void SePlayer_Play(void *, int, int);
extern "C" void func_0207fe44(void *);
extern "C" int func_ov003_02155f40(void *, int);
int func_ov003_02155208(void *);
extern "C" void func_ov003_02153874(void *);
void func_ov003_02155580(void *, int);
int func_ov003_02155618(void *);
extern "C" void *func_02053c6c(void *);
extern "C" void *func_ov003_02155e14(void *, int);
void ItemTable_LoadIds(void *, void *, void *, unsigned int, void *, int);
void _ZN13SafeAllocator5ResetEv(void *);
extern "C" void func_ov003_0215873c(void *);
extern "C" void *MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(void *);
extern "C" void func_ov003_02158a50(void *);
extern "C" void func_0209c830(void *, int);
void func_ov003_0215582c(void *);
extern "C" int FieldTaskQueue_GetCurrentKind(void *);
int _ZNK8Object3D19HasAnimationStoppedEv(void *);
int LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int);
void func_ov017_021c3fb4(int, int);
void func_ov017_021c4418(int, int);
void func_ov017_021cf078(int, int, int);
void func_ov017_021ccc34(int);
void func_ov017_021cc730(int, int, int, int);
void PartyMember_RecalculateStats(void *, int);
void func_ov003_02155740(void *);
extern "C" void *func_02094d6c(void);
int func_ov003_02158754(void *);
}

#if defined(jpn)
#define JPN_OFS(j, u) (j)
#else
#define JPN_OFS(j, u) (u)
#endif

extern char g_sePlayer[];
extern char g_bgmPlayer[];
extern const char *g_itemDataArchive;
extern const char *g_itemDataFile;

struct Struct_ov003_0215704c {
    char pad0[0x36];
    short unknown_36_;
    char unknown_38_[0x59 - 0x38];
    signed char unknown_59_;
    char unknown_5a_[0x5d - 0x5a];
    unsigned char unknown_5d_;
};

struct Struct_ov003_0215704c_2 {
    char pad0[0x130];
    unsigned char *f130;
};

struct Struct_ov003_0215704c_3 {
    unsigned int pad : 17;
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int rest : 13;
    char pad4[0xc];
};

struct Struct_ov003_0215704c_4 {
    unsigned char count;
    char pad1[3];
    struct Struct_ov003_0215704c_3 recs[1];
};

struct Struct_ov003_0215704c_5 {
    void *alloc;
    struct Struct_ov003_0215704c *f04;
    void *f08;
    char unknown_c_[0x18 - 0xc];
    void *f18;
    char unknown_1c_[0x80 - 0x1c];
#if defined(jpn)
    char unknown_80_[0x174 - 0x80];
#else
    char unknown_80_[0x178 - 0x80];
#endif
    char sub178[0x1d0 - 0x178];
    int task;
    int unknown_1d4_;
    char unknown_1d8_[4];
    int unknown_1dc_;
    char unknown_1e0_[4];
    short unknown_1e4_;
    short unknown_1e6_;
    short unknown_1e8_;
    char unknown_1ea_[2];
    short cmd;
    short unknown_1ee_;
    char unknown_1f0_[7];
    signed char f1f7;
    unsigned char mode;
    unsigned char state;
    char unknown_1fa_[2];
    unsigned int flags;
    char unknown_200_[0x280 - 0x200];
    char unknown_280_[0x32c - 0x280];
    int unknown_32c_;
    char unknown_330_[8];
    unsigned char unknown_338_;
};

// USA: func_ov003_0215704c
extern "C" ARM void func_ov003_0215704c(struct Struct_ov003_0215704c_5 *self) {
    void *gs              = GameState::GetInstance();
    int state             = self->state;
    void *p               = self->f18;
    struct Struct_ov003_0215704c *o = self->f04;

    if (state == 0) {
        o->unknown_59_ = self->f1f7;
        func_ov003_0215385c(o);
        self->unknown_1e6_ = 6;
        if (self->unknown_1e4_ < 0) {
            self->unknown_1e4_ = func_02080468(p, self->unknown_1e6_);
            self->unknown_1e8_ = self->unknown_1e4_;
        }
#if defined(jpn)
        ((short *) p)[0x2a / 2] = self->unknown_1e4_;
#else
        ((short *) p)[0x36 / 2] = self->unknown_1e4_;
#endif
        func_ov003_02158480(self);
        func_0208203c(self->unknown_80_);
        self->f08   = 0;
        self->state = self->state + 1;
    } else if (state == 1) {
        self->f08 = &self->unknown_1e4_;
        int ok    = 1;
        func_ov003_021538f4(o, func_ov003_02156034(self));
        if (o->unknown_5d_ & 1) {
            ok = 0;
        }
        void *res = GameState::GetInstance()->GetResources();
        if (IsScreenNotFullyFaded((GameResources*)res, true) == 0) {
            ok = 0;
        }
        if (_Z31IsSubBrightnessTransitionActiveP13GameResources(res) != 0) {
            ok = 0;
        }
        if (func_ov003_021550dc(self) != 0 && ok != 0) {
            SePlayer_Play(g_sePlayer, 1, 0);
            func_0208203c(self->unknown_80_);
            self->f08   = 0;
            self->cmd   = 0xa;
            self->state = self->state + 1;
            func_0207fe44(p);
            if (func_ov003_02155f40(self, self->f1f7)) {
                self->flags = self->flags | 2;
                self->cmd   = 0x30;
                self->unknown_1ee_  = 9;
                self->state = 0;
                return;
            }
        } else if (func_ov003_02155208(self) != 0 && ok != 0) {
            self->f08  = 0;
            self->cmd  = 7;
            self->mode = 7;
            func_0207fe44(p);
            o->unknown_59_ = -1;
            func_ov003_02153874(o);
        }
    } else if (state == 2) {
        func_ov003_02155580(self, 0);
        self->state = self->state + 1;
    } else if (state == 3) {
        int r = func_ov003_02155618(self);
        if (r != -1) {
            if (r == 1) {
                self->cmd             = 0xc;
                struct Struct_ov003_0215704c_2 *c = (struct Struct_ov003_0215704c_2 *) func_0200ff1c((GameState *)gs, self->f1f7);
                if (c != 0) {
                    c->f130[8] = 0;
                }
                self->state = self->state + 1;
            }
        } else {
            self->flags = self->flags | 2;
            self->cmd   = 0xb;
            self->state = 0;
        }
    } else if (state == 4) {
#if defined(jpn)
        self->task  = BackgroundLoader::GetInstance()->QueueLoadGP1(g_itemDataArchive, 0);
#else
        self->task  = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, 0);
#endif
        self->state = self->state + 1;
    } else if (state == 5) {
        BackgroundLoader *loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->task)) {
            void *file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            _ZN13SafeAllocator5ResetEv((char *) self->alloc + 0x78);
            void *pm = GameState::GetInstance()->GetPartyMemberByIndex(self->f1f7);
            if (pm != 0) {
                char *f = (char *) func_02053c6c(pm);
                if (f != 0) {
                    void *slot =
                        func_ov003_02155e14(f + 0xa4 + 0x400, func_ov003_02156034(self));
                    ItemTable_LoadIds(self->sub178, (char *) self->alloc + 0x78, file, size, slot, 8);
                }
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            func_ov003_0215873c(self);
            self->state = 0x32;
            self->unknown_338_  = 1;
        }
    } else if (state == 6) {
        self->unknown_1d4_ = 0;
        MessageSystem_Reset(MessageSystem_GetInstance());
        func_ov003_02158a50(self);
        func_0209c830(g_bgmPlayer, 0x34);
        self->state = self->state + 1;
    } else if (state == 7) {
        self->unknown_1d4_ = self->unknown_1d4_ + self->unknown_1dc_;
        if (self->unknown_1d4_ > 0x8c) {
            func_ov003_0215582c(self);
            self->state = self->state + 1;
        }
    } else if (state == 8) {
        char *x = (char *) GetGameResources();
        if (FieldTaskQueue_GetCurrentKind(*(void **) (x + 0x3000 + JPN_OFS(0x4f0, 0x700))) == 0x13) {
            return;
        }
        self->state = self->state + 1;
    } else if (state == 9) {
        if (_ZNK8Object3D19HasAnimationStoppedEv(self->unknown_280_) == 0) {
            return;
        }
        self->unknown_32c_ = 0;
        if (LinkSession_IsActive(LinkSession_GetInstance()) != 0) {
            func_ov017_021c3fb4(self->f1f7, 0);
            func_ov017_021c4418(self->f1f7, -1);
            func_ov017_021cf078(self->f1f7, (unsigned char) func_ov003_02156034(self), 0);
            func_ov017_021ccc34(self->f1f7);
            func_ov017_021cc730(self->f1f7, 1, 0, 0);
        }
        void *c2 = func_0200ff1c((GameState *)gs, self->f1f7);
        if (c2 != 0) {
            PartyMember_RecalculateStats(*(void **) ((char *) c2 + JPN_OFS(0x144, 0x150)), 0);
        }
        func_ov003_02155740(self);
        struct Struct_ov003_0215704c_4 *g = (struct Struct_ov003_0215704c_4 *) func_02094d6c();
        struct Struct_ov003_0215704c_3 *rp = g->recs;
        unsigned char cnt      = g->count;
        int i;
        for (i = 0; i < cnt; i++, rp++) {
            if (rp->a) {
                rp->b = 1;
            }
        }
        self->unknown_338_  = 0;
        self->cmd   = 0xd;
        self->state = self->state + 1;
    } else if (state == 0xa) {
        self->mode = 7;
    }
    if (self->state == 0x32) {
        if (func_ov003_02158754(self) != 0) {
            self->state = 6;
        }
    }
}
