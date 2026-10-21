#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov003_021539a0_2;

struct Struct_ov003_021539a0_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov003_021539a0_4 {
    char unknown_0_[8];
    struct Struct_ov003_021539a0_3 unknown_8_[3];
};

struct Struct_ov003_021539a0_5 {
    short unknown_0_;
    char unknown_2_[0x14];
    unsigned char unknown_16_;
    char unknown_17_;
};

struct Struct_ov003_021539a0_6 {
    int unknown_0_;
    void* unknown_4_;
    struct Struct_ov003_021539a0_5* unknown_8_;
    char unknown_c_[6];
    short unknown_12_;
    unsigned short unknown_14_;
    char unknown_16_[0x4a - 0x16];
    short unknown_4a_;
};

struct Struct_ov003_021539a0_7 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov003_021539a0_8 {
    char unknown_0_[8];
    void* unknown_8_;
    char unknown_c_[0x9c];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[8];
    short unknown_b4_;
    short unknown_b6_;
    short unknown_b8_;
    short unknown_ba_;
    char unknown_bc_[0x24];
};

struct Struct_ov003_021539a0 {
    int unknown_0_;
    void* unknown_4_;
    struct Struct_ov003_021539a0_4* unknown_8_;
    struct Struct_ov003_021539a0_6* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    char unknown_18_[0x38];
    int unknown_50_;
    int unknown_54_;
    char unknown_58_;
    signed char unknown_59_;
    char unknown_5a_[2];
    unsigned char unknown_5c_;
    unsigned char unknown_5d_;
};

struct SafeAllocator;
extern "C" void __clear(void*, int);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" void* func_0208247c(void*);
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" int func_02082490(void*, void*, unsigned int, int, int);
struct Struct_02020aec;
extern "C" char* func_020467f0(Struct_02020aec*, int, void**, int*);
extern "C" void func_0204b11c(unsigned char*, int);
extern "C" void func_0204b5b4(void*, int);
struct Struct_02020cb8_5;
extern "C" void func_0204b5e8(Struct_02020cb8_5*, int, int);
extern "C" void func_0204c684(void*);
struct Struct_0204b988;
extern "C" void func_0204b988(Struct_0204b988*, unsigned int, int, int, unsigned short);
struct Struct_02020cb8_2;
extern "C" void func_0204b0e8(Struct_02020cb8_2*, void*);
struct Struct_0201099c_3;
extern "C" char* func_020e0434(Struct_0201099c_3*, int);
extern "C" void* func_020421a0();
extern "C" void func_02046608(void*, int, char*, char*, int, int, int);
extern "C" void func_ov023_021e23d0(void*, int, int, unsigned char, unsigned char);
extern "C" int func_02085fb4(unsigned char*);
extern "C" int func_02086020(unsigned char*);
extern "C" int func_0208608c(unsigned char*);
extern "C" int func_020860f8(unsigned char*);
extern "C" int func_02086164(unsigned char*);
extern "C" int func_020861d0(unsigned char*);
extern "C" int func_0208623c(unsigned char*);
extern "C" int func_020862a8(unsigned char*);
extern "C" int func_02086314(unsigned char*);
extern "C" void func_ov023_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_ov023_021e257c(void*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToSubBG0CharacterData(int, int, unsigned int);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);

extern char data_ov003_0217fca0[];
extern char data_ov003_0217fcb5[];
extern char data_ov003_0217fcc7[];
extern char data_ov003_0217fcd5[];
extern char data_ov003_0217fcde[];
extern short data_ov003_0217f288[];

#if defined(jpn)
#define data_ov003_0217fca0 data_ov003_0217e520
#define data_ov003_0217f288 data_ov003_0217df8c
extern char data_ov003_0217e520[];
extern short data_ov003_0217df8c[];
#endif

#define CAP999(x) ((x) > 999 ? 999 : (x))

// USA: func_ov003_021539a0
#if defined(jpn)
extern "C" ARM void func_ov003_021539a0(struct Struct_ov003_021539a0* arg0) {
    if (arg0->unknown_59_ < 0) return;
    if (!(arg0->unknown_5d_ & 1)) return;
    struct Struct_ov003_021539a0_2* var0 = (Struct_ov003_021539a0_2*)BackgroundLoader::GetInstance();
    if (arg0->unknown_5c_ == 0) {
        char var1[0x18];
        __clear(var1, 0x18);
        sprintf(var1, data_ov003_0217fca0, arg0->unknown_14_);
        arg0->unknown_50_ = ((BackgroundLoader*)var0)->QueueLoadFile(var1, (SafeAllocator*)0);
        arg0->unknown_54_ = ((BackgroundLoader*)var0)->QueueLoadFile(data_ov003_0217fcb5, (SafeAllocator*)0);
        arg0->unknown_5c_++;
    } else if (arg0->unknown_5c_ == 1) {
        if (((BackgroundLoader*)var0)->GetTaskStatus(arg0->unknown_50_) == 0) return;
        if (((BackgroundLoader*)var0)->GetTaskStatus(arg0->unknown_54_) == 0) return;
        struct Struct_ov003_021539a0_8 var2;
        struct Struct_ov003_021539a0_7 var3;
        int var4[9];
        void* var5;
        unsigned int var6;
        void* var7;
        int var8;
        ((BackgroundLoader*)var0)->GetLoadedFileByID(arg0->unknown_50_, &var5, &var6);
        void* var9 = GameState::GetInstance();
        unsigned char* var10 = (unsigned char*)((GameState*)var9)->GetPartyMemberByIndex(arg0->unknown_59_);
        func_0208247c(arg0->unknown_8_);
        unsigned char* var11 = 0;
        unsigned char* var12;
        if (var10 != 0 && var5 != 0) {
            var11 = func_02053c6c(var10);
            func_02082490(arg0->unknown_8_, var5, var6, *(unsigned short*)(var11 + 0x100 + arg0->unknown_14_ * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)var0)->RemoveTask(arg0->unknown_50_);
        arg0->unknown_50_ = -1;
        ((BackgroundLoader*)var0)->GetLoadedFileByID(arg0->unknown_54_, &var5, &var6);
        var10 = (unsigned char*)func_020467f0((Struct_02020aec*)var5, 0, &var7, &var8);
        if (var10 != 0) {
            var3.unknown_1c_0_ = 1;
            var3.unknown_1c_4_ = 0;
            func_0204b11c((unsigned char*)&var3, 0);
            func_0204b5b4(&var3, 0);
            func_0204b5e8((Struct_02020cb8_5*)&var3, 0, 0);
            var12 = var10 + 0x10;
            func_0204c684(&var2);
            var2.unknown_a8_ = 0x20;
            var2.unknown_aa_ = 0x18;
            var2.unknown_b4_ = 0xc;
            var2.unknown_8_ = var12;
            var2.unknown_b6_ = 0x10;
            struct Struct_ov003_021539a0_6* var13;
            struct Struct_ov003_021539a0_4* var14;
            int var15;
            void* var16;
            var16 = arg0->unknown_4_;
            var15 = arg0->unknown_14_;
            var14 = arg0->unknown_8_;
            var13 = arg0->unknown_c_;
            if (var11 != 0) {
                struct Struct_ov003_021539a0_5* var17;
                unsigned short var18;
                unsigned short var19;
                struct Struct_ov003_021539a0_5* var20;
                var20 = var13->unknown_8_;
                if (var20 == NULL) {
                    var17 = 0;
                } else {
                    var19 = var13->unknown_14_;
                    if (var19 == 0) {
                        var17 = 0;
                    } else {
                        for (var18 = 0; var18 < var19; var18++) {
                            short var21 = var20[var18].unknown_0_;
                            if (var21 == 1) {
                                var17 = &var20[var18];
                                goto found;
                            }
                        }
                        var17 = 0;
                    }
                }
            found:
                if (var17) {
                    var17->unknown_16_ &= ~1;
                }
                func_0204b988((Struct_0204b988*)arg0->unknown_18_, (unsigned char)(var15 + 1) & 0xff, 3, 2, 0xffff);
                func_0204b0e8((Struct_02020cb8_2*)arg0->unknown_18_, 0);
                unsigned char var22 = var15 - 1;
                var2.unknown_b8_ = 0xa;
                var2.unknown_ba_ = 0x10;
                unsigned char var23 = var22 + var22 * 2;
                func_ov023_021e23d0(var13, 7, (int)func_020e0434((Struct_0201099c_3*)var16, var23), 0xc, 0xf);
                func_ov023_021e23d0(var13, 8, (int)func_020e0434((Struct_0201099c_3*)var16, (short)(var23 + 1)), 0xc, 0xf);
                func_ov023_021e23d0(var13, 9, (int)func_020e0434((Struct_0201099c_3*)var16, (short)(var23 + 2)), 0xc, 0xf);
                int var24 = (var15 & 0xff) * 0xc;
                unsigned char* var25 = var11 + 0x7b8;
                struct Struct_ov003_021539a0_3* var26 = (struct Struct_ov003_021539a0_3*)(var25 + var24);
                var4[0] = CAP999(func_02085fb4(var11) + var14->unknown_8_[0].unknown_0_0_ + var26[0].unknown_0_0_);
                var4[1] = CAP999(func_02086020(var11) + var14->unknown_8_[0].unknown_1_2_ + var26[0].unknown_1_2_);
                var4[2] = CAP999(func_0208608c(var11) + var14->unknown_8_[0].unknown_2_4_ + var26[0].unknown_2_4_);
                var4[3] = CAP999(func_020860f8(var11) + var14->unknown_8_[1].unknown_0_0_ + var26[1].unknown_0_0_);
                var4[4] = CAP999(func_02086164(var11) + var14->unknown_8_[1].unknown_1_2_ + var26[1].unknown_1_2_);
                var4[5] = CAP999(func_020861d0(var11) + var14->unknown_8_[1].unknown_2_4_ + var26[1].unknown_2_4_);
                var4[6] = CAP999(func_0208623c(var11) + var14->unknown_8_[2].unknown_0_0_ + var26[2].unknown_0_0_);
                var4[7] = CAP999(func_020862a8(var11) + var14->unknown_8_[2].unknown_1_2_ + var26[2].unknown_1_2_);
                var4[8] = CAP999(func_02086314(var11) + var14->unknown_8_[2].unknown_2_4_ + var26[2].unknown_2_4_);
                for (unsigned char var27 = 0; data_ov003_0217f288[var27] >= 0; var27++) {
                    func_ov023_021e24b0(var13, data_ov003_0217f288[var27], var4[var27], 8, 0xf, 1, 3, 0, 0);
                }
                var13->unknown_4_ = &var2;
                var13->unknown_12_ = 1;
                func_ov023_021e257c(var13);
            }
            CleanInvalidateCacheRange(var12, 0x6000);
            LoadToSubBG0CharacterData((int)var12, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task54);
        self->task54 = -1;
        self->f10 = self->idx;
        void* axis = (void*)((GameState*)gs)->GetResources();
        if ((self->flags & 2) || !IsBrightnessWithinValidRange((GameResources*)axis, true)) {
            self->flags &= ~2;
            self->state++;
        } else {
            arg0->unknown_5d_ &= ~1;
            arg0->unknown_5c_ = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)((void*)GameState::GetInstance()->GetResources()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
#else
extern "C" ARM void func_ov003_021539a0(struct Struct_ov003_021539a0* arg0) {
    if (arg0->unknown_59_ < 0) return;
    if (!(arg0->unknown_5d_ & 1)) return;
    struct Struct_ov003_021539a0_2* var29 = (Struct_ov003_021539a0_2*)BackgroundLoader::GetInstance();
    if (arg0->unknown_5c_ == 0) {
        char var30[0x18];
        __clear(var30, 0x18);
        sprintf(var30, data_ov003_0217fca0, arg0->unknown_14_);
        arg0->unknown_50_ = ((BackgroundLoader*)var29)->QueueLoadFile(var30, (SafeAllocator*)0);
        arg0->unknown_54_ = ((BackgroundLoader*)var29)->QueueLoadFileInGP2(data_ov003_0217fcb5, data_ov003_0217fcc7, (SafeAllocator*)0);
        arg0->unknown_5c_++;
    } else if (arg0->unknown_5c_ == 1) {
        if (((BackgroundLoader*)var29)->GetTaskStatus(arg0->unknown_50_) == 0) return;
        if (((BackgroundLoader*)var29)->GetTaskStatus(arg0->unknown_54_) == 0) return;
        struct Struct_ov003_021539a0_8 var31;
        char var32[0x400];
        char var33[0x400];
        struct Struct_ov003_021539a0_7 var34;
        int var35[9];
        void* var36;
        unsigned int var37;
        void* var38;
        int var39;
        ((BackgroundLoader*)var29)->GetLoadedFileByID(arg0->unknown_50_, &var36, &var37);
        void* var40 = GameState::GetInstance();
        unsigned char* var41 = (unsigned char*)((GameState*)var40)->GetPartyMemberByIndex(arg0->unknown_59_);
        func_0208247c(arg0->unknown_8_);
        unsigned char* var42 = 0;
        unsigned char* var43;
        if (var41 != 0 && var36 != 0) {
            var42 = func_02053c6c(var41);
            func_02082490(arg0->unknown_8_, var36, var37, *(unsigned short*)(var42 + 0x100 + arg0->unknown_14_ * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)var29)->RemoveTask(arg0->unknown_50_);
        arg0->unknown_50_ = -1;
        ((BackgroundLoader*)var29)->GetLoadedFileByID(arg0->unknown_54_, &var36, &var37);
        var41 = (unsigned char*)func_020467f0((Struct_02020aec*)var36, 0, &var38, &var39);
        if (var41 != 0) {
            var34.unknown_1c_0_ = 1;
            var34.unknown_1c_4_ = 0;
            func_0204b11c((unsigned char*)&var34, 0);
            func_0204b5b4(&var34, 0);
            func_0204b5e8((Struct_02020cb8_5*)&var34, 0, 0);
            var43 = var41 + 0x10;
            func_0204c684(&var31);
            var31.unknown_a8_ = 0x20;
            var31.unknown_aa_ = 0x18;
            var31.unknown_b4_ = 0xc;
            var31.unknown_8_ = var43;
            var31.unknown_b6_ = 0x10;
            struct Struct_ov003_021539a0_6* var44;
            struct Struct_ov003_021539a0_4* var45;
            int var46;
            void* var47;
            var47 = arg0->unknown_4_;
            var46 = arg0->unknown_14_;
            var45 = arg0->unknown_8_;
            var44 = arg0->unknown_c_;
            if (var42 != 0) {
                struct Struct_ov003_021539a0_5* var48;
                unsigned short var49;
                unsigned short var50;
                struct Struct_ov003_021539a0_5* var51;
                var51 = var44->unknown_8_;
                if (var51 == NULL) {
                    var48 = 0;
                } else {
                    var50 = var44->unknown_14_;
                    if (var50 == 0) {
                        var48 = 0;
                    } else {
                        for (var49 = 0; var49 < var50; var49++) {
                            short var52 = var51[var49].unknown_0_;
                            if (var52 == 1) {
                                var48 = &var51[var49];
                                goto found;
                            }
                        }
                        var48 = 0;
                    }
                }
            found:
                if (var48) {
                    var48->unknown_16_ &= ~1;
                }
                func_0204b988((Struct_0204b988*)arg0->unknown_18_, (unsigned char)(var46 + 1) & 0xff, 3, 2, 0xffff);
                func_0204b0e8((Struct_02020cb8_2*)arg0->unknown_18_, 0);
                unsigned char var53 = var46 - 1;
                var31.unknown_b8_ = 0xa;
                var31.unknown_ba_ = 0x10;
                var44->unknown_4a_ = 0x10;
                __clear(var32, 0x400);
                unsigned char var54 = var53 + var53 * 2;
                char* var55 = func_020e0434((Struct_0201099c_3*)var47, (short)(var54 + 2));
                char* var56 = func_020e0434((Struct_0201099c_3*)var47, (short)(var54 + 1));
                char* var57 = func_020e0434((Struct_0201099c_3*)var47, (short)var54);
                sprintf(var33, data_ov003_0217fcd5, var57, var56, var55);
                func_02046608(func_020421a0(), 0xc, var33, var32, 0xdc, 0, 1);
                func_ov023_021e23d0(var44, 7, (int)var32, 0xc, 0xf);
                func_ov023_021e23d0(var44, 8, (int)data_ov003_0217fcde, 0xc, 0xf);
                func_ov023_021e23d0(var44, 9, (int)data_ov003_0217fcde, 0xc, 0xf);
                func_ov023_021e23d0(var44, 0x14, (int)data_ov003_0217fcde, 0xc, 0xf);
                int var58 = (var46 & 0xff) * 0xc;
                unsigned char* var59 = var42 + 0x850;
                struct Struct_ov003_021539a0_3* var60 = (struct Struct_ov003_021539a0_3*)(var59 + var58);
                var35[0] = CAP999(func_02085fb4(var42) + var45->unknown_8_[0].unknown_0_0_ + var60[0].unknown_0_0_);
                var35[1] = CAP999(func_02086020(var42) + var45->unknown_8_[0].unknown_1_2_ + var60[0].unknown_1_2_);
                var35[2] = CAP999(func_0208608c(var42) + var45->unknown_8_[0].unknown_2_4_ + var60[0].unknown_2_4_);
                var35[3] = CAP999(func_020860f8(var42) + var45->unknown_8_[1].unknown_0_0_ + var60[1].unknown_0_0_);
                var35[4] = CAP999(func_02086164(var42) + var45->unknown_8_[1].unknown_1_2_ + var60[1].unknown_1_2_);
                var35[5] = CAP999(func_020861d0(var42) + var45->unknown_8_[1].unknown_2_4_ + var60[1].unknown_2_4_);
                var35[6] = CAP999(func_0208623c(var42) + var45->unknown_8_[2].unknown_0_0_ + var60[2].unknown_0_0_);
                var35[7] = CAP999(func_020862a8(var42) + var45->unknown_8_[2].unknown_1_2_ + var60[2].unknown_1_2_);
                var35[8] = CAP999(func_02086314(var42) + var45->unknown_8_[2].unknown_2_4_ + var60[2].unknown_2_4_);
                for (unsigned char var61 = 0; data_ov003_0217f288[var61] >= 0; var61++) {
                    func_ov023_021e24b0(var44, data_ov003_0217f288[var61], var35[var61], 8, 0xf, 1, 3, 0, 0);
                }
                var44->unknown_4_ = &var31;
                var44->unknown_12_ = 1;
                func_ov023_021e257c(var44);
            }
            CleanInvalidateCacheRange(var43, 0x6000);
            LoadToSubBG0CharacterData((int)var43, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task54);
        self->task54 = -1;
        self->f10 = self->idx;
        void* axis = (void*)((GameState*)gs)->GetResources();
        if ((self->flags & 2) || !IsBrightnessWithinValidRange((GameResources*)axis, true)) {
            self->flags &= ~2;
            self->state++;
        } else {
            arg0->unknown_5d_ &= ~1;
            arg0->unknown_5c_ = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)((void*)GameState::GetInstance()->GetResources()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
#endif
