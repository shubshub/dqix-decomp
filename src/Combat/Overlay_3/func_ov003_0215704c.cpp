#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" {
int func_02080468(void *, int);
void func_ov003_0215385c(void *);
void func_ov003_02158480(void *);
void _Z20ResetWithSub0208203cP11Obj0208203c(void *);
void _Z31ResetIfFlagAndCategory_021538f4Pvi(void *, int);
int _Z29GetArrayEntryByIndex_02156034Pv(void *);
int _Z31IsSubBrightnessTransitionActiveP13GameResources(void *);
int func_ov003_021550dc(void *);
void _Z13SePlayer_PlayP8SePlayerii(void *, int, int);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void *);
int _Z26MatchesArrayEntry_02155f40Pvi(void *, int);
int func_ov003_02155208(void *);
void func_ov003_02153874(void *);
void func_ov003_02155580(void *, int);
int func_ov003_02155618(void *);
void *_Z34GetCombatantWithFlag0x100_0200ff1cP9GameStatei(void *, int);
void *_Z24GetFieldAt0x150_02053c6cPh(void *);
void *_Z29OffsetByIndexTimes16_02155e14ii(void *, int);
void ItemTable_LoadIds(void *, void *, void *, unsigned int, void *, int);
void _ZN13SafeAllocator5ResetEv(void *);
void func_ov003_0215873c(void *);
void *func_020421a0(void);
void func_02043204(void *);
void func_ov003_02158a50(void *);
void func_0209c830(void *, int);
void func_ov003_0215582c(void *);
int func_02046b24(void *);
int _ZNK8Object3D19HasAnimationStoppedEv(void *);
int func_0202ae18(void);
int func_0202b7d8(int);
void func_ov017_021c3fb4(int, int);
void func_ov017_021c4418(int, int);
void func_ov017_021cf078(int, int, int);
void func_ov017_021ccc34(int);
void func_ov017_021cc730(int, int, int, int);
void func_02083e28(void *, int);
void func_ov003_02155740(void *);
void *func_02094d6c(void);
int func_ov003_02158754(void *);
}

#if defined(jpn)
#define JPN_OFS(j, u) (j)
#else
#define JPN_OFS(j, u) (u)
#endif

extern char g_sePlayer[];
extern char data_02109bf4[];
extern const char *g_itemDataArchive;
extern const char *g_itemDataFile;

struct Struct_ov003_0215704c {
    char unknown_0_[0x36];
    short unknown_36_;
    char unknown_38_[0x59 - 0x38];
    signed char unknown_59_;
    char unknown_5a_[0x5d - 0x5a];
    unsigned char unknown_5d_;
};

struct Struct_ov003_0215704c_2 {
    char unknown_0_[0x130];
    unsigned char *unknown_130_;
};

struct Struct_ov003_0215704c_3 {
    unsigned int unknown_0_0_ : 17;
    unsigned int unknown_2_1_ : 1;
    unsigned int unknown_2_2_ : 1;
    unsigned int unknown_2_3_ : 13;
    char unknown_4_[0xc];
};

struct Struct_ov003_0215704c_4 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    struct Struct_ov003_0215704c_3 unknown_4_[1];
};

struct Struct_ov003_0215704c_5 {
    void *unknown_0_;
    struct Struct_ov003_0215704c *unknown_4_;
    void *unknown_8_;
    char unknown_c_[0x18 - 0xc];
    void *unknown_18_;
    char unknown_1c_[0x80 - 0x1c];
#if defined(jpn)
    char unknown_80_[0x174 - 0x80];
#else
    char unknown_80_[0x178 - 0x80];
#endif
    char unknown_178_[0x1d0 - 0x178];
    int unknown_1d0_;
    int unknown_1d4_;
    char unknown_1d8_[4];
    int unknown_1dc_;
    char unknown_1e0_[4];
    short unknown_1e4_;
    short unknown_1e6_;
    short unknown_1e8_;
    char unknown_1ea_[2];
    short unknown_1ec_;
    short unknown_1ee_;
    char unknown_1f0_[7];
    signed char unknown_1f7_;
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_;
    char unknown_1fa_[2];
    unsigned int unknown_1fc_;
    char unknown_200_[0x280 - 0x200];
    char unknown_280_[0x32c - 0x280];
    int unknown_32c_;
    char unknown_330_[8];
    unsigned char unknown_338_;
};

// USA: func_ov003_0215704c
extern "C" ARM void func_ov003_0215704c(struct Struct_ov003_0215704c_5 *arg0) {
    void *var0              = GameState::GetInstance();
    int var1             = arg0->unknown_1f9_;
    void *var2               = arg0->unknown_18_;
    struct Struct_ov003_0215704c *var3 = arg0->unknown_4_;

    if (var1 == 0) {
        var3->unknown_59_ = arg0->unknown_1f7_;
        func_ov003_0215385c(var3);
        arg0->unknown_1e6_ = 6;
        if (arg0->unknown_1e4_ < 0) {
            arg0->unknown_1e4_ = func_02080468(var2, arg0->unknown_1e6_);
            arg0->unknown_1e8_ = arg0->unknown_1e4_;
        }
#if defined(jpn)
        ((short *) var2)[0x2a / 2] = arg0->unknown_1e4_;
#else
        ((short *) var2)[0x36 / 2] = arg0->unknown_1e4_;
#endif
        func_ov003_02158480(arg0);
        func_0208203c(arg0->unknown_80_);
        arg0->unknown_8_   = 0;
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 1) {
        arg0->unknown_8_ = &arg0->unknown_1e4_;
        int var4    = 1;
        func_ov003_021538f4(var3, func_ov003_02156034(arg0));
        if (var3->unknown_5d_ & 1) {
            var4 = 0;
        }
        void *res = GameState::GetInstance()->GetResources();
        if (IsBrightnessWithinValidRange((GameResources*)res, true) == 0) {
            ok = 0;
        }
        if (_Z31IsSubBrightnessTransitionActiveP13GameResources(var5) != 0) {
            var4 = 0;
        }
        if (func_ov003_021550dc(self) != 0 && ok != 0) {
            _Z13SePlayer_PlayP8SePlayerii(g_sePlayer, 1, 0);
            _Z20ResetWithSub0208203cP11Obj0208203c(self->sub80);
            self->f08   = 0;
            self->cmd   = 0xa;
            self->state = self->state + 1;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
            if (_Z26MatchesArrayEntry_02155f40Pvi(self, self->f1f7)) {
                self->flags = self->flags | 2;
                self->cmd   = 0x30;
                self->cmd2  = 9;
                self->state = 0;
                return;
            }
        } else if (func_ov003_02155208(arg0) != 0 && var4 != 0) {
            arg0->unknown_8_  = 0;
            arg0->unknown_1ec_  = 7;
            arg0->unknown_1f8_ = 7;
            func_0207fe44(var2);
            var3->unknown_59_ = -1;
            func_ov003_02153874(var3);
        }
    } else if (var1 == 2) {
        func_ov003_02155580(arg0, 0);
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 3) {
        int var6 = func_ov003_02155618(arg0);
        if (var6 != -1) {
            if (var6 == 1) {
                arg0->unknown_1ec_             = 0xc;
                struct Struct_ov003_0215704c_2 *var7 = (struct Struct_ov003_0215704c_2 *) func_0200ff1c((GameState *)var0, arg0->unknown_1f7_);
                if (var7 != 0) {
                    var7->unknown_130_[8] = 0;
                }
                arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
            }
        } else {
            arg0->unknown_1fc_ = arg0->unknown_1fc_ | 2;
            arg0->unknown_1ec_   = 0xb;
            arg0->unknown_1f9_ = 0;
        }
    } else if (var1 == 4) {
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
                char *f = (char *) _Z24GetFieldAt0x150_02053c6cPh(pm);
                if (f != 0) {
                    void *slot =
                        _Z29OffsetByIndexTimes16_02155e14ii(f + 0xa4 + 0x400, _Z29GetArrayEntryByIndex_02156034Pv(self));
                    ItemTable_LoadIds(self->sub178, (char *) self->alloc + 0x78, file, size, slot, 8);
                }
            }
            var8->RemoveTask(arg0->unknown_1d0_);
            arg0->unknown_1d0_ = -1;
            func_ov003_0215873c(arg0);
            arg0->unknown_1f9_ = 0x32;
            arg0->unknown_338_  = 1;
        }
    } else if (var1 == 6) {
        arg0->unknown_1d4_ = 0;
        func_02043204(func_020421a0());
        func_ov003_02158a50(arg0);
        func_0209c830(data_02109bf4, 0x34);
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 7) {
        arg0->unknown_1d4_ = arg0->unknown_1d4_ + arg0->unknown_1dc_;
        if (arg0->unknown_1d4_ > 0x8c) {
            func_ov003_0215582c(arg0);
            arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
        }
    } else if (var1 == 8) {
        char *var14 = (char *) GetGameResources();
        if (func_02046b24(*(void **) (var14 + 0x3000 + JPN_OFS(0x4f0, 0x700))) == 0x13) {
            return;
        }
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 9) {
        if (_ZNK8Object3D19HasAnimationStoppedEv(arg0->unknown_280_) == 0) {
            return;
        }
        arg0->unknown_32c_ = 0;
        if (func_0202b7d8(func_0202ae18()) != 0) {
            func_ov017_021c3fb4(arg0->unknown_1f7_, 0);
            func_ov017_021c4418(arg0->unknown_1f7_, -1);
            func_ov017_021cf078(arg0->unknown_1f7_, (unsigned char) func_ov003_02156034(arg0), 0);
            func_ov017_021ccc34(arg0->unknown_1f7_);
            func_ov017_021cc730(arg0->unknown_1f7_, 1, 0, 0);
        }
        void *var15 = func_0200ff1c((GameState *)var0, arg0->unknown_1f7_);
        if (var15 != 0) {
            func_02083e28(*(void **) ((char *) var15 + JPN_OFS(0x144, 0x150)), 0);
        }
        func_ov003_02155740(arg0);
        struct Struct_ov003_0215704c_4 *var16 = (struct Struct_ov003_0215704c_4 *) func_02094d6c();
        struct Struct_ov003_0215704c_3 *var17 = var16->unknown_4_;
        unsigned char var18      = var16->unknown_0_;
        int var19;
        for (var19 = 0; var19 < var18; var19++, var17++) {
            if (var17->unknown_2_1_) {
                var17->unknown_2_2_ = 1;
            }
        }
        arg0->unknown_338_  = 0;
        arg0->unknown_1ec_   = 0xd;
        arg0->unknown_1f9_ = arg0->unknown_1f9_ + 1;
    } else if (var1 == 0xa) {
        arg0->unknown_1f8_ = 7;
    }
    if (arg0->unknown_1f9_ == 0x32) {
        if (func_ov003_02158754(arg0) != 0) {
            arg0->unknown_1f9_ = 6;
        }
    }
}
