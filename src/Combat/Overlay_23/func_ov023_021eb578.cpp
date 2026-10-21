#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct GameResources;
struct Struct_0201099c_3;
struct Struct_0205cf78;
struct Struct_0205cf78_2;
struct Struct_02020aec;
struct Struct_02020cb8_4;
struct Struct_02020cb8_5;
struct Struct_0204b12c;
struct Struct_02020cb8;
struct Struct_0204af38;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;
struct Struct_0204b8d0;
struct Struct_02043368_2;
struct Struct_02043368;

void SetSubBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void* func_020d6c00(void);
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);
extern "C" void func_020dc2bc(void);
extern "C" void func_020dfec0(void* arg0, void* arg1, void* arg2, unsigned int arg3);
extern "C" int func_020421a0(void);
extern "C" void func_ov023_021ec368(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov023_021ec39c(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov023_021ec3c8(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov023_021ec3f4(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov023_021ec420(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov023_021ec454(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_0204b11c(unsigned char* arg0, int arg1);
extern "C" void func_0204b5b4(void*, int);
extern "C" int func_0204b5e8(struct Struct_02020cb8_5* arg0, int arg1, int arg2);
extern "C" void func_0204b12c(struct Struct_0204b12c* arg0, SafeAllocator* arg1);
extern "C" int func_02046900(struct Struct_02020cb8_4* arg0);
extern "C" void* func_020467f0(struct Struct_02020aec* arg0, int arg1, void** arg2, int* arg3);
extern "C" void func_0204b174(void* arg0, void* arg1, SafeAllocator* arg2, int arg3);
extern "C" void func_0204bc74(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
extern "C" void func_0204b0e8(struct Struct_02020cb8_2* arg0, void* arg1);
extern "C" void func_0204c7a8(struct Struct_0204c7a8* arg0, SafeAllocator* arg1, int arg2, unsigned int arg3);
extern "C" void func_0205cf78(struct Struct_0205cf78* arg0, struct Struct_0205cf78_2* arg1, unsigned char arg2);
extern "C" int func_020e0434(struct Struct_0201099c_3* arg0, int arg1);
extern "C" void func_0204af64(struct Struct_02020cb8* arg0);
extern "C" void func_0204af38(struct Struct_0204af38* arg0, int arg1, SafeAllocator* arg2);
extern "C" void func_0204b8d0(struct Struct_0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void func_0205a444(char* arg0);
extern "C" void func_0205a198(struct Struct_02043368_2* arg0);
extern "C" void func_0205a234(struct Struct_02043368* arg0);
extern "C" void func_0205a528(void* arg0, void* arg1, int arg2, void* arg3);

extern char data_ov023_021fe108[];
#if defined(jpn)
extern char data_ov023_021fd39c[];
#endif
extern char data_ov023_021fe121[];
extern char data_ov023_021fe131[];
extern unsigned char data_ov023_021fd844[];

struct Struct_ov008_021895a8 {
    unsigned char unknown_0_[2];
};

struct Struct_ov023_021eb578 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov023_021eb578_2 {
    char unknown_0_[4];
    Struct_ov023_021eb578* unknown_4_;
    char unknown_8_[0xd8];
};

struct Struct_ov023_021eb578_3 {
    char unknown_0_[0x3c];
    char* unknown_3c_;
    char* unknown_40_;
    char unknown_44_[8];
    short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
};

struct Struct_ov023_021eb578_4 {
    SafeAllocator* unknown_0_;
    char unknown_4_[0x18];
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    char unknown_28_[0x1c];
    Struct_ov023_021eb578 unknown_44_[2];
    Struct_ov023_021eb578 unknown_84_[2];
    char unknown_c4_[0x98];
    Struct_ov023_021eb578* unknown_15c_;
    char unknown_160_[0x16];
    unsigned char unknown_176_;
    char unknown_177_[9];
    Struct_ov023_021eb578_2 unknown_180_[3];
    char* unknown_420_;
    Struct_ov023_021eb578_3* unknown_424_;
    char* unknown_428_;
    char* unknown_42c_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    char unknown_433_;
    int unknown_434_;
    unsigned short unknown_438_;
};

#define IS_SUB_SCREEN_MODE(self)     ((self)->unknown_430_ == 0 || (self)->unknown_430_ == 1 || (self)->unknown_430_ == 6 || ((self)->unknown_430_ == 7 && !((self)->unknown_438_ & 8)))
#define IS_MAIN_SCREEN_MODE(self) ((self)->unknown_430_ == 2 || ((self)->unknown_430_ == 7 && ((self)->unknown_438_ & 8)))

#define REG16(a) (*(volatile unsigned short*)(a))
#define REG32(a) (*(volatile unsigned int*)(a))

#define SET_LAYER_PRIORITIES(m0, m1, m2, m3, mPlanes, s0, s1, s2, s3, sPlanes)     do {         REG16(0x4000008) = (REG16(0x4000008) & ~3) | (m0);         REG16(0x400000a) = (REG16(0x400000a) & ~3) | (m1);         REG16(0x400000c) = (REG16(0x400000c) & ~3) | (m2);         REG16(0x400000e) = (REG16(0x400000e) & ~3) | (m3);         REG32(0x4000000) = (REG32(0x4000000) & ~0x1f00) | ((mPlanes) << 8);         REG16(0x4001008) = (REG16(0x4001008) & ~3) | (s0);         REG16(0x400100a) = (REG16(0x400100a) & ~3) | (s1);         REG16(0x400100c) = (REG16(0x400100c) & ~3) | (s2);         REG16(0x400100e) = (REG16(0x400100e) & ~3) | (s3);         REG32(0x4001000) = (REG32(0x4001000) & ~0x1f00) | ((sPlanes) << 8);     } while (0)

// USA: func_ov023_021eb578
extern "C" ARM void func_ov023_021eb578(Scene021eb578* self) {
    SafeAllocator* allocs;
    FontBankLoader* g;
    GameResources* res;
    BackgroundLoader* loader;
    unsigned char state;
    res = GameState::GetInstance()->GetResources();
    g = GetGlobal02109400_02094a00();
    loader = BackgroundLoader::GetInstance();
    state = self->state;

    if (var4 == 0) {
        if (IS_SUB_SCREEN_MODE(arg0)) {
            SetSubBrightness(var2, -16, 15);
        } else if (IS_MAIN_SCREEN_MODE(arg0)) {
            SetMainBrightness(var2, -16, 15);
        }
        func_02094b40(var1);
        func_02094b34(var1, 0x71, 0x201, 0, 0);
        arg0->unknown_432_++;
    }

    if (var4 == 1) {
        if (IsBrightnessTransitionActive(var2)) {
            return;
        }
        if (func_02094b4c(var1) == 0) {
            return;
        }
        if (arg0->unknown_438_ & 0x10) {
            func_020466e4((unsigned int*)func_020d6c00(), 1);
            func_020dc2bc();
        }
#if defined(jpn)
        arg0->unknown_434_ = var3->QueueLoadFile(data_ov023_021fd39c, NULL);
#else
        arg0->unknown_434_ = var3->QueueLoadFileInGP2(data_ov023_021fe108, data_ov023_021fe121, NULL);
#endif
        arg0->unknown_432_++;
    }

    if (var4 == 2) {
        void* var5;
        unsigned int var6;
        unsigned char var7[2];
        int var8;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        var3->GetLoadedFileByID(arg0->unknown_434_, &var5, &var6);
        var0 = arg0->unknown_0_;
        var0[2].Reset();
        func_020dfec0(arg0->unknown_4_, &var0[2], var5, var6);
        var3->RemoveTask(arg0->unknown_434_);
        arg0->unknown_434_ = -1;
#if defined(jpn)
        arg0->unknown_1c_ = *(int*)(func_020421a0() + 0x28);
#else
        arg0->unknown_1c_ = *(int*)(func_020421a0() + 0x5c);
#endif
        if (arg0->unknown_430_ == 0 || arg0->unknown_430_ == 1) {
            func_ov023_021ec368(0, 0, 0x1a, 4, 0);
            func_ov023_021ec39c(0, 0, 0x1b, 4);
            func_ov023_021ec3c8(0, 0, 0x1c, 6);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            var7[0] = 1;
            var7[1] = 0;
        } else if (arg0->unknown_430_ == 7) {
            if (!(arg0->unknown_438_ & 8)) {
                func_ov023_021ec368(0, 0, 0xe, 0, 0);
                func_ov023_021ec39c(0, 0, 0xf, 0);
                func_ov023_021ec3c8(0, 0, 7, 1);
                func_ov023_021ec3f4(0, 0, 0x1e, 2);
                var7[0] = 1;
                var7[1] = 0;
            } else {
                func_ov023_021ec420(0, 0, 0, 1, 0);
                func_ov023_021ec454(0, 0, 0x1f, 1);
                func_ov023_021ec3f4(0, 0, 0x17, 3);
                func_ov023_021ec3c8(0, 0, 0x17, 2);
                var7[0] = 0;
                var7[1] = 1;
            }
        } else if (arg0->unknown_430_ == 2) {
            func_ov023_021ec420(0, 0, 0, 1, 0);
            func_ov023_021ec454(0, 0, 0x1f, 1);
            func_ov023_021ec3f4(0, 0, 0x17, 3);
            func_ov023_021ec3c8(0, 0, 0x17, 2);
            var7[0] = 0;
            var7[1] = 1;
        } else if (arg0->unknown_430_ == 6) {
            func_ov023_021ec368(0, 0, 0xe, 0, 0);
            func_ov023_021ec39c(0, 0, 0xf, 0);
            func_ov023_021ec3c8(0, 0, 7, 1);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            var7[0] = 1;
            var7[1] = 0;
        }
        for (var8 = 0; var8 < 2; var8++) {
            Struct_ov023_021eb578* var9 = &arg0->unknown_84_[var8];
            func_0204b11c((unsigned char*)var9, 0);
            var9->unknown_1c_0_ = var7[var8];
            var9->unknown_1c_4_ = 3;
            func_0204b5b4(var9, 0);
            func_0204b5e8((struct Struct_02020cb8_5*)var9, 0, 0);
            func_0204b12c((struct Struct_0204b12c*)var9, &arg0->unknown_0_[1]);
        }
        arg0->unknown_434_ = var3->QueueLoadFile(data_ov023_021fe131, NULL);
        arg0->unknown_432_++;
    }

    if (var4 == 3) {
        void* var10;
        void* var11;
        unsigned int var12;
        int var13;
        void* var14;
        unsigned char var15[3];
        int var16;
        int var17;
        int var18;
        int var19;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        var0 = arg0->unknown_0_;
        var3->GetLoadedFileByID(arg0->unknown_434_, &var11, &var12);
        var16 = func_02046900((struct Struct_02020cb8_4*)var11);
        for (var17 = 0; var17 < var16; var17++) {
            var14 = func_020467f0((struct Struct_02020aec*)var11, var17, &var10, &var13);
            if (var14 != NULL && var17 != 1) {
                func_0204b174(&arg0->unknown_84_[0], var14, &var0[1], var13);
                func_0204b174(&arg0->unknown_84_[1], var14, &var0[1], var13);
            }
        }
        var3->RemoveTask(arg0->unknown_434_);
        arg0->unknown_434_ = -1;
        for (var18 = 0; var18 < 2; var18++) {
            Struct_ov023_021eb578* var20 = &arg0->unknown_84_[var18];
            func_0204bc74(var20, 0, 0, 0, 0x20, 0x19, 0);
            func_0204b0e8((struct Struct_02020cb8_2*)var20, 0);
        }
        arg0->unknown_420_ = (char*)var0[1].Allocate(0x2a00);
        var15[0] = 0;
        var15[1] = 0;
        var15[2] = 1;
        for (var19 = 0; var19 < 3; var19++) {
            Struct_ov023_021eb578_2* var21 = &arg0->unknown_180_[var19];
            func_0204c7a8((struct Struct_0204c7a8*)var21, &var0[1], (int)arg0->unknown_420_, 0x400);
            var21->unknown_4_ = &arg0->unknown_84_[var15[var19]];
        }
        arg0->unknown_15c_ = &arg0->unknown_84_[0];
        arg0->unknown_176_ = 2;
        func_0205cf78((struct Struct_0205cf78*)arg0->unknown_c4_, (struct Struct_0205cf78_2*)arg0->unknown_180_, 3);
        arg0->unknown_434_ = var3->QueueLoadFile((const char*)func_020e0434((struct Struct_0201099c_3*)arg0->unknown_4_, 3), NULL);
        arg0->unknown_432_++;
    }

    if (var4 == 4) {
        void* var22;
        void* var23;
        unsigned int var24;
        int var25;
        void* var26;
        unsigned char var27[2];
        signed char var28[2];
        unsigned char var29[2];
        int var30;
        int var31;
        int var32;
        int var33;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        var0 = arg0->unknown_0_;
        var0->Reset();
        var30 = 0;
        if (IS_SUB_SCREEN_MODE(arg0)) {
            var30 = 1;
        } else if (IS_MAIN_SCREEN_MODE(arg0)) {
            var30 = 0;
        }
        *(Struct_ov008_021895a8*)var27 = *(Struct_ov008_021895a8*)&data_ov023_021fd844[8];
        *(Struct_ov008_021895a8*)var28 = *(Struct_ov008_021895a8*)&data_ov023_021fd844[6];
        *(Struct_ov008_021895a8*)var29 = *(Struct_ov008_021895a8*)&data_ov023_021fd844[0];
        for (var33 = 0; var33 < 2; var33++) {
            Struct_ov023_021eb578* var34 = &arg0->unknown_44_[var33];
            func_0204af64((struct Struct_02020cb8*)var34);
            var34->unknown_1c_0_ = var30;
            var34->unknown_1c_4_ = var27[var33];
            func_0204b5b4(var34, var28[var33]);
            func_0204b5e8((struct Struct_02020cb8_5*)var34, 0, 0);
            func_0204b12c((struct Struct_0204b12c*)var34, var0);
            func_0204af38((struct Struct_0204af38*)var34, var29[var33], var0);
        }
        var3->GetLoadedFileByID(arg0->unknown_434_, &var23, &var24);
        var31 = func_02046900((struct Struct_02020cb8_4*)var23);
        for (var32 = 0; var32 < var31; var32++) {
            var26 = func_020467f0((struct Struct_02020aec*)var23, var32, &var22, &var25);
            if (var26 != NULL) {
                if (var32 < 3) {
                    func_0204b174(&arg0->unknown_44_[0], var26, var0, var25);
                } else {
                    func_0204b174(&arg0->unknown_44_[1], var26, var0, var25);
                }
            }
        }
        var3->RemoveTask(arg0->unknown_434_);
        arg0->unknown_434_ = -1;
        func_0204b8d0((struct Struct_0204b8d0*)&arg0->unknown_44_[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
        func_0204b0e8((struct Struct_02020cb8_2*)&arg0->unknown_44_[0], 0);
        func_0204bc74(&arg0->unknown_44_[1], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((struct Struct_02020cb8_2*)&arg0->unknown_44_[1], 0);
        if (arg0->unknown_430_ == 0 || arg0->unknown_430_ == 1) {
            SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
        } else if (arg0->unknown_430_ == 7) {
            if (!(arg0->unknown_438_ & 8)) {
                SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
            } else {
                SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
            }
        } else if (arg0->unknown_430_ == 2) {
            SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
        } else if (arg0->unknown_430_ == 6) {
            SET_LAYER_PRIORITIES(3, 1, 2, 0, 0x19, 3, 2, 1, 0, 0x1e);
        }
        arg0->unknown_434_ = var3->QueueLoadFile((const char*)func_020e0434((struct Struct_0201099c_3*)arg0->unknown_4_, 4), NULL);
        arg0->unknown_432_++;
    }

    if (var4 == 5) {
        void* var35;
        void* var36;
        unsigned int var37;
        int var38;
        void* var39;
        int var40;
        Struct_ov023_021eb578_3* var41;
        int var42;
        int var43;
        int var44;
        if (var3->GetTaskStatus(arg0->unknown_434_) == 0) {
            return;
        }
        var40 = arg0->unknown_44_[0].unknown_1c_0_;
        var0 = arg0->unknown_0_;
        func_0205a444((char*)arg0->unknown_424_);
        arg0->unknown_424_->unknown_50_ = var40;
        var41 = arg0->unknown_424_;
        var41->unknown_40_ = arg0->unknown_428_;
        var41->unknown_4c_ = 4;
        arg0->unknown_424_->unknown_3c_ = arg0->unknown_42c_;
        for (var44 = 0; var44 < 4; var44++) {
            func_0205a198((struct Struct_02043368_2*)(arg0->unknown_428_ + var44 * 0x28));
        }
        func_0205a234((struct Struct_02043368*)arg0->unknown_42c_);
        var3->GetLoadedFileByID(arg0->unknown_434_, &var36, &var37);
        var42 = func_02046900((struct Struct_02020cb8_4*)var36);
        var0[3].Reset();
        for (var43 = 0; var43 < var42; var43++) {
            var39 = func_020467f0((struct Struct_02020aec*)var36, var43, &var35, &var38);
            if (var39 != NULL) {
                func_0205a528(arg0->unknown_424_, var39, var38, &var0[3]);
            }
        }
        var3->RemoveTask(arg0->unknown_434_);
        arg0->unknown_434_ = -1;
        arg0->unknown_432_++;
    }

    if (var4 == 6) {
        if (arg0->unknown_44_[0].unknown_1c_0_ == 0) {
            SetMainBrightness(var2, 0, 15);
        } else {
            SetSubBrightness(var2, 0, 15);
        }
        if (arg0->unknown_20_ == 0 || arg0->unknown_24_ == 0) {
            arg0->unknown_431_ = 2;
            arg0->unknown_432_ = 0;
        } else {
            arg0->unknown_431_ = 1;
            arg0->unknown_432_ = 0;
        }
    }
}
