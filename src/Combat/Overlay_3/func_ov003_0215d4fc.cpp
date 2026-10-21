#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_0215d4fc_0 = 0x18, Enum_ov003_0215d4fc_0_2 = -0x130, Enum_ov003_0215d4fc_1808 = 0x500 };
#else
enum { Enum_ov003_0215d4fc_0 = 0, Enum_ov003_0215d4fc_0_2 = 0, Enum_ov003_0215d4fc_1808 = 0x710 };
#endif

struct Struct_ov003_02154af4_3 {
    char unknown_0_[0x64];
    char unknown_64_[0x98 - 0x64 + Enum_ov003_0215d4fc_0];
    char unknown_98_[0x3b8 - 0x98];
    unsigned char unknown_3b8_;
    char unknown_3b9_[2];
    unsigned char unknown_3bb_;
    unsigned char unknown_3bc_;
    char unknown_3bd_[0x3c4 - 0x3bd];
    unsigned char unknown_3c4_[4];
    char unknown_3c8_[4];
    unsigned int unknown_3cc_;
    char unknown_3d0_[0x3d8 - 0x3d0];
    float unknown_3d8_;
    char unknown_3dc_[4];
    float unknown_3e0_;
    char unknown_3e4_[4];
    int unknown_3e8_;
    unsigned char unknown_3ec_;
    unsigned char unknown_3ed_;
    char unknown_3ee_[2];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    char unknown_3f2_;
    unsigned char unknown_3f3_;
    unsigned char unknown_3f4_;
    unsigned char unknown_3f5_;
    char unknown_3f6_[2];
    int unknown_3f8_;
};

struct Struct_ov003_0215d150_2 {
    char unknown_0_[0x998 + Enum_ov003_0215d4fc_0_2];
    int unknown_998_;
};

struct Struct_ov003_0215d4fc {
    char unknown_0_[0x12c];
    int unknown_12c_;
};

extern int data_02109bf4;
extern int data_02108760;

extern "C" int *func_0202ae18();
Ctl *GetGlobalField0x1c020421a0();
void *GetGlobalPtr021075f4_0203cf4c();
unsigned char *GetData02153637_020e2ff8();
extern "C" int func_0202c508(int *);
extern "C" void func_02043204(char*);
struct Struct_0201099c_3;
extern "C" void * func_020e0434(Struct_0201099c_3*, int);
extern "C" void func_ov003_0215cab0(Struct_ov003_02154af4_3 *, void *);
extern "C" void *func_0203df78(void *, int);
struct Struct_0205d6a0;
extern "C" void func_0205d6a0(Struct_0205d6a0*, int);
struct Struct_02109bf4_4;
extern "C" void func_0209c678(Struct_02109bf4_4*, int);
struct GameResources;
void SetBrightness(GameResources*, int, int);
extern "C" void func_0205e944(void *, int);
int IsBrightnessTransitionActive(GameResources*);
struct Struct_02109bf4_3;
extern "C" void func_0209c20c(Struct_02109bf4_3*);
extern "C" void func_0209c6d8(void*, int);
extern "C" void func_020e3368(unsigned char *, unsigned char);
struct Struct_0208ab34;
extern "C" int func_020e34bc(Struct_0208ab34*, int);
extern "C" char *func_0200ff94(GameState *, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_020e3428(void *, int);
struct Struct_0208ab34_2;
extern "C" void func_020e3468(Struct_0208ab34_2*, int);
extern "C" void func_ov017_021a2fa0(void *);
extern "C" void func_02012fe4();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021921fc(void *, int, int);
extern "C" int func_0209ca2c(void *);
extern "C" void func_0209c7fc(void *);
struct Struct_0203e2c4_2;
extern "C" void func_02040b2c(Struct_0203e2c4_2*, int);
struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2*, int, char*);

// USA: func_ov003_0215d4fc
extern "C" ARM void func_ov003_0215d4fc(Scene *self) {
    GameState *gs    = GameState::GetInstance();
    void *res        = (void*)gs->GetResources();
    Ctl *ctl         = GetGlobalField0x1c020421a0();
    int *a           = func_0202ae18();
    void *b          = GetGlobalPtr021075f4_0203cf4c();
    GameObject *c    = gs->GetUnknownGameObject();
    unsigned char *d = GetData02153637_020e2ff8();
    unsigned char state;
    int i;
    int sb;
    sb = 0;
    if (func_0202c508(a) != 0) {
        if (*(short *) ((char *) gs->GetUnknownGameObject() + 4) == 0) {
            sb = 1;
        }
    }
    var7 = arg0->unknown_3b8_;

    if (var7 == 0) {
        if (arg0->unknown_3f3_ != 0) {
            func_02043204((char*)var2);
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
            return;
        }
        int var10 = 0x3f2;
        if (arg0->unknown_3cc_ > *(unsigned int *) ((unsigned char *)func_02010828(var0) + 0xf6c)) {
            var10 = 0x3fc;
            if (arg0->unknown_3f0_ != 0) {
                if (var9 != 0) {
                    var10        = 0x6c;
                    arg0->unknown_3f1_ = 1;
                } else {
                    var10 = 0x72;
                }
            }
            func_ov003_0215cab0(arg0, func_020e0434((Struct_0201099c_3*)arg0->unknown_64_, var10));
            arg0->unknown_3b8_ = 8;
            return;
        }
        if (arg0->unknown_3f0_ != 0) {
            var10 = 0x6a;
        }
        func_ov003_0215cab0(arg0, func_020e0434((Struct_0201099c_3*)arg0->unknown_64_, var10));
        arg0->unknown_3bb_ = 2;
        void *var11 = func_0203df78(var4, (*(Struct_ov003_0215d4fc **) ((char *) GetGameResources() + 0x3000 + Enum_ov003_0215d4fc_1808))->unknown_12c_);
        if (var11 != 0) {
            arg0->unknown_3f8_ = func_02040a20((Struct_0203dce4*)var11);
        }
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var7 == 1) {
        if (var2->unknown_998_ != 0) {
            return;
        }
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_98_, 0);
        func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0x10);
        SetBrightness((GameResources*)var1, -16, 0x3c);
        func_0205e944(&data_02108760, 0);
        arg0->unknown_3f5_  = 1;
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var7 == 2) {
        if (IsBrightnessTransitionActive((GameResources*)var1) != 0) {
            return;
        }
        func_0209c20c((Struct_02109bf4_3*)&data_02109bf4);
        func_0209c6d8(&data_02109bf4, 0x37);
        arg0->unknown_3e8_  = 0xb4;
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var7 == 3) {
        func_020e3368(var6, 1);
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var7 == 4) {
        int var12 = func_020e34bc((Struct_0208ab34*)var6, 1);
        if (var12 == 1 || arg0->unknown_3f4_ != 0) {
            unsigned char *var13              = (unsigned char *)func_02010828(var0);
            *(unsigned int *) (var13 + 0xf6c) = *(unsigned int *) (var13 + 0xf6c) - arg0->unknown_3cc_;
            for (var8 = 0; var8 < 4; var8++) {
                if (arg0->unknown_3c4_[var8] != 0xff) {
                    char *var14                                          = func_0200ff94(var0, arg0->unknown_3c4_[var8]);
                    *(unsigned short *) (*(char **) (var14 + 0x130) + 4) = *(unsigned short *) (*(char **) (var14 + 0x134) + 0x30);
                    *(unsigned short *) (*(char **) (var14 + 0x130) + 6) = *(unsigned short *) (*(char **) (var14 + 0x134) + 0x32);
                    func_ov017_021c9e00(arg0->unknown_3c4_[var8], 0, 0, 1);
                }
            }
            if (func_0202c508(var3) != 0) {
                switch (arg0->unknown_3bc_) {
                    case 2: var0->SetDayTimer(arg0->unknown_3d8_); break;
                    case 3: var0->SetDayTimer(arg0->unknown_3e0_); break;
                }
            }
            func_020e3428(var6, 1);
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
        } else if ((unsigned int) (var12 - 3) <= 2) {
            func_020e3468((Struct_0208ab34_2*)var6, 1);
            arg0->unknown_3b8_ = 3;
        }
    }
    if (var7 == 5) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            func_ov017_021a2fa0((void *) GetGameResources());
            func_02012fe4();
            func_ov017_0219bd1c(1, 0, 0, 0);
            func_ov017_021921fc((char *) var5 + 0x44, *(short *) ((char *) var5 + 0xae), 1);
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
        }
    }
    if (var7 == 6) {
        if (func_0209ca2c(&data_02109bf4) != 0) {
            return;
        }
        func_0209c7fc(&data_02109bf4);
        SetBrightness((GameResources*)var1, 0, 0x3c);
        func_0205e944(&data_02108760, 0x7f);
        arg0->unknown_3ec_ = 1;
        arg0->unknown_3ed_ = 0;
        void *var15 = func_0203df78(var4, (*(Struct_ov003_0215d4fc **) ((char *) GetGameResources() + 0x3000 + Enum_ov003_0215d4fc_1808))->unknown_12c_);
        if (var15 != 0) {
            func_02040b2c((Struct_0203e2c4_2*)var15, arg0->unknown_3f8_);
        }
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    } else if (arg0->unknown_3b8_ == 7) {
        if (arg0->unknown_3ec_ != 0) {
            return;
        }
        if (IsBrightnessTransitionActive((GameResources*)var1) != 0) {
            return;
        }
        arg0->unknown_3f5_ = 0;
        if (arg0->unknown_3f4_ != 0) {
            return;
        }
        if (arg0->unknown_3f3_ != 0) {
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
            return;
        }
        var2->unknown_998_ = 1;
        func_02046574((Struct_02046574_2*)var2, 0, (char*)(*(void **) ((char *) var0->GetUnknownGameObject() + 0x134)));
        int var16 = 0x3f3;
        if (arg0->unknown_3f0_ != 0) {
            if (var9 == 0) {
                var16 = 0x71;
            } else if (arg0->unknown_3bc_ == 2) {
                var16 = 0x6b;
            } else {
                var16 = 0x6d;
            }
        }
        func_ov003_0215cab0(arg0, func_020e0434((Struct_0201099c_3*)arg0->unknown_64_, var16));
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (arg0->unknown_3b8_ == 8 && var2->unknown_998_ == 0) {
        arg0->unknown_3bc_  = 5;
        arg0->unknown_3b8_ = 0;
    }
}
