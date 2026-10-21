#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define REGIONAL_OFFSET(jp, us) jp
#define data_ov002_0216c96c data_ov002_0216cfc0
enum { Enum_ov002_0215624c_43 = 0x2e };
#else
#define REGIONAL_OFFSET(jp, us) us
enum { Enum_ov002_0215624c_43 = 0x2b };
#endif

struct Struct_ov002_02155960_2;
struct Struct_ov002_0215624c_15;
struct Struct_ov002_0215624c_17;
struct Struct_ov002_0215624c_18;
struct Struct_ov002_0215624c_19;
struct Struct_ov002_0215624c_20;
struct Struct_ov002_0215624c_21;
struct Struct_ov002_0215624c_22;
struct Struct_ov002_0215624c_23;
struct Struct_ov002_0215624c_24;
struct Struct_ov002_0215624c_25;
struct Struct_ov002_0215624c_11;
struct Struct_ov002_0215624c_26;
struct Struct_0201099c_3;

unsigned char *FindElementForFieldB0_0205d8c4(struct Struct_0205d81c *s);
int IsField0x9cEqual3_0204c7cc(unsigned char *obj);
void SetFieldAt0x30_0205bc24(void *obj, int value);
extern "C" int func_0205d0e0(void *obj, int val);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
void PushInputLogB_020a1ef0(int id);
int GetGlobalField0x1c020421a0(void);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char *obj, int value);
extern "C" void func_0204b5b4(void *obj, int val);
void AllocateAndClearBuffer0204b12c(struct AllocTarget0204b12c *obj,
                                                                                         SafeAllocator *alloc);
int DispatchViaTable0204b5e8(struct Obj0204b5e8 *obj, int a, int b);
extern "C" void ColorEffect_ConfigureAlphaBlend(int reg, int a, int b, int c, int d);
extern "C" void func_0204bc74(void *arg0, unsigned short arg1, int arg2, int arg3, int arg4, int arg5, unsigned short arg6);
extern "C" void func_0204b0e8(struct Struct_ov002_0215624c_19 *arg0, void *arg1);
extern "C" void func_0204b174(void *arg0, void *arg1, SafeAllocator *arg2, int arg3);
extern "C" void func_0204c7a8(struct Struct_ov002_0215624c_20 *arg0, SafeAllocator *arg1,
                                                                           int arg2, unsigned int arg3);
extern "C" void func_0205cf78(struct Struct_ov002_0215624c_21 *arg0,
                                                                                     struct Struct_ov002_0215624c_22 *arg1,
                                                                                     unsigned char arg2);
extern "C" void *memset(void *arg0, int arg1, unsigned int arg2);
extern "C" void *memcpy(void *arg0, const void *arg1, unsigned int arg2);
extern "C" void *func_020421b0(int arg0);
void CleanInvalidateCacheRange(const void *where, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void LoadToMainBG3CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void func_0205a198(struct Struct_ov002_0215624c_23 *arg0);
extern "C" void func_0205a234(struct Struct_ov002_0215624c_24 *arg0);
extern "C" void func_0205a444(char *arg0);
extern "C" void *func_020467f0(struct Struct_ov002_0215624c_25 *arg0, int arg1, void **arg2, int *arg3);
extern "C" void func_0205a528(void *arg0, void *arg1, int arg2, void *arg3);
extern "C" void func_0205de24(struct Struct_ov002_0215624c_11 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);
extern "C" int func_02046900(struct Struct_ov002_0215624c_26 *arg0);
extern "C" void func_020dfec0(void *arg0, void *arg1, void *arg2, unsigned int arg3);
extern "C" int func_020e0434(struct Struct_0201099c_3 *arg0, int arg1);
extern "C" void func_020dc7e8(int arg0, int arg1);
extern "C" void func_ov002_0215bf34(char *arg0);
extern "C" void func_ov002_0215c028(char *arg0);
extern "C" void func_ov002_0215bba8(char *arg0);
extern "C" void func_ov002_02161cf0(char *arg0);
extern "C" void func_ov002_0215c0f8(char *arg0);
extern "C" void func_ov002_0215a938(char *arg0);

struct Struct_ov002_0215624c_12 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov002_0215624c_13 {
    int unknown_0_;
    short unknown_4_;
    char unknown_6_[0x1a];
};

struct Struct_ov002_0215624c_14 {
    unsigned char unknown_0_[3];
};

struct Struct_ov002_0216c96c {
    unsigned char unknown_0_[4];
#if defined(jpn)
    struct Struct_ov002_0215624c_14 unknown_7_;
    struct Struct_ov002_0215624c_14 unknown_4_;
#else
    struct Struct_ov002_0215624c_14 unknown_4_;
    struct Struct_ov002_0215624c_14 unknown_7_;
#endif
};

struct Struct_ov002_0215624c_16 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

extern struct Struct_ov002_0216c96c data_ov002_0216c96c;
#if defined(jpn)
extern char data_ov002_0216d50c[];
extern char data_ov002_0216d520[];
#endif
extern char data_ov002_0216ced4[];
extern char data_ov002_0216cee8[];
extern char data_ov002_0216cef8[];
extern char data_ov002_0216cf11[];

#define S16(off) (*(short *) (arg0 + (off)))
#define S32(off) (*(int *) (arg0 + (off)))
#define U8(off) (*(unsigned char *) (arg0 + (off)))
#define REG16(a) (*(volatile unsigned short *) (a))
#define REG32(a) (*(volatile unsigned int *) (a))

// USA: func_ov002_0215624c
extern "C" ARM void func_ov002_0215624c(char *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();

    if (g_keyManager.TestKeysPressed(0x601)) {
        U8(REGIONAL_OFFSET(0x1af7, 0x1c2f)) = 1;
    }
    if (g_keyManager.TestKeysPressed(0x802)) {
        U8(REGIONAL_OFFSET(0x1af7, 0x1c2f))  = 0;
        S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = Enum_ov002_0215624c_43;
        if (S32(REGIONAL_OFFSET(0x1a8c, 0x1bc4)) >= 0) {
            var0->RemoveTask(S32(REGIONAL_OFFSET(0x1a8c, 0x1bc4)));
            S32(REGIONAL_OFFSET(0x1a8c, 0x1bc4)) = -1;
        }
        for (int var1 = 0; var1 < 5; var1++) {
            var0->RemoveTask(((int *) (arg0 + REGIONAL_OFFSET(0x1a6c, 0x1ba4)))[var1]);
            *(int *) (arg0 + var1 * 4 + REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = -1;
        }
        return;
    }

    unsigned char *var2 = func_0205d8c4((struct Struct_ov002_02155960_2 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)));
    if (var2 != 0 && func_0204c7cc(var2) && !(var2[0xc5] & 2)) {
        func_0205bc24(&((struct Struct_ov002_0215624c_12 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)))->unknown_4_, -1);
    }
    S32(REGIONAL_OFFSET(0x1a90, 0x1bc8)) = func_0205d0e0(arg0 + REGIONAL_OFFSET(0xe20, 0xec8), S32(REGIONAL_OFFSET(0x1a68, 0x1ba0)));
    short var3   = S16(REGIONAL_OFFSET(0x1aa8, 0x1be0));
    S16(REGIONAL_OFFSET(0x1aa8, 0x1be0)) = func_0205d794((struct Struct_ov002_0215624c_15 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)));
    if (S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) >= 1 && var3 != S16(REGIONAL_OFFSET(0x1aa8, 0x1be0))) {
        S32(REGIONAL_OFFSET(0x1a90, 0x1bc8)) = 1;
        int var4   = S32(REGIONAL_OFFSET(0x1a80, 0x1bb8));
        S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 1;
        func_ov002_0215bba8(arg0);
        S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = var4;
    }

    if (S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) == 0) {
        PushInputLogB_020a1ef0(1);
        char *w     = (char *) GameState::GetInstance()->GetResources();
        S32(REGIONAL_OFFSET(0x1a98, 0x1bd0)) = *(int *) ((char *) GetGlobalField0x1c020421a0() + REGIONAL_OFFSET(0x28, 0x5c));
        ((SafeAllocator *) (self + REGIONAL_OFFSET(0x78c, 0x828)))->Reset();

        struct Struct_ov002_0215624c_14 var6  = data_ov002_0216c96c.unknown_4_;
        struct Struct_ov002_0215624c_14 var7 = data_ov002_0216c96c.unknown_7_;
        struct Struct_ov002_0215624c_16 *var8;
        for (int var9 = 0; var9 < 3; var9++) {
            var8 = (struct Struct_ov002_0215624c_16 *) (arg0 + REGIONAL_OFFSET(0xedc, 0xf84) + var9 * 0x20);
            func_0204b11c((unsigned char *) var8, 0);
            var8->unknown_1c_0_ = 0;
            var8->unknown_1c_4_ = var6.unknown_0_[var9];
            func_0204b5b4(var8, var7.unknown_0_[var9]);
            func_0204b12c((struct Struct_ov002_0215624c_17 *) var8,
                                                                                     (SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x78c, 0x828)));
            func_0204b5e8((struct Struct_ov002_0215624c_18 *) var8, 0, 0);
        }

        REG16(0x0400000a) = (REG16(0x0400000a) & 0x43) | 0x1d00;
        REG16(0x0400000c) = (REG16(0x0400000c) & 0x43) | 0x1e00;
        REG16(0x0400000e) = (REG16(0x0400000e) & 0x43) | 0x1f08;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);

        char *var10;
        for (int var11 = 0; var11 < 3; var11++) {
            var10 = arg0 + REGIONAL_OFFSET(0xedc, 0xf84) + var11 * 0x20;
            func_0204bc74(var10, 0, 0, 0, 0x20, 0x19, 0);
            func_0204b0e8((struct Struct_ov002_0215624c_19 *) var10, 0);
        }

        void *var12 = *(void **) (var5 + 0x2c);
        func_0204b174(arg0 + REGIONAL_OFFSET(0xefc, 0xfa4), var12, (SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x78c, 0x828)), 0);
        func_0204b174(arg0 + REGIONAL_OFFSET(0xf1c, 0xfc4), var12, (SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x78c, 0x828)), 0);

        for (int var13 = 0; var13 < 3; var13++) {
            struct Struct_ov002_0215624c_13 *var14 = (struct Struct_ov002_0215624c_13 *) (arg0 + REGIONAL_OFFSET(0xedc, 0xf84)) + var13;
            var14->unknown_0_               = 0x60;
            var14->unknown_4_              = 3;
        }

        S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)) = (int) ((SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x78c, 0x828)))->Allocate(0x4400);
        for (int var15 = 0; var15 < 12; var15++) {
            char *var16 = arg0 + REGIONAL_OFFSET(0xf3c, 0xfe4) + var15 * 0xe0;
            func_0204c7a8((struct Struct_ov002_0215624c_20 *) var16,
                                                                       (SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x78c, 0x828)), S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0x400);
            *(char **) (var16 + 4) = arg0 + REGIONAL_OFFSET(0xefc, 0xfa4);
        }
        *(char **) (arg0 + REGIONAL_OFFSET(0xeb8, 0xf60)) = arg0 + REGIONAL_OFFSET(0xedc, 0xf84);
        U8(REGIONAL_OFFSET(0xed2, 0xf7a))                 = 3;
        func_0205cf78((struct Struct_ov002_0215624c_21 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)),
                                                                             (struct Struct_ov002_0215624c_22 *) (arg0 + REGIONAL_OFFSET(0xf3c, 0xfe4)), 12);

        memset((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0, 0x60);
        memset((char *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)) + 0x20, 0x11111111, 0x20);
        memcpy((char *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)) + 0x40, func_020421b0(REGIONAL_OFFSET(0x1f, 0x15)), 0x20);
        CleanInvalidateCacheRange((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0x60);
        LoadToMainBG1CharacterData((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0, 0x60);
        LoadToMainBG3CharacterData((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), 0, 0x60);

        for (unsigned char var17 = 0; var17 < REGIONAL_OFFSET(0x2c, 0x2b); var17++) {
            func_0205a198((struct Struct_ov002_0215624c_23 *) (S32(REGIONAL_OFFSET(0x19bc, 0x1a64)) + var17 * 0x28));
        }
        func_0205a234((struct Struct_ov002_0215624c_24 *) S32(REGIONAL_OFFSET(0x19c4, 0x1a6c)));
        func_0205a444((char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)));
        *(unsigned char *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x50) = 0;
        {
            char *var18               = (char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68));
            *(int *) (var18 + 0x40)   = S32(REGIONAL_OFFSET(0x19bc, 0x1a64));
            *(short *) (var18 + 0x4c) = REGIONAL_OFFSET(0x2c, 0x2b);
        }
        *(int *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x3c) = S32(REGIONAL_OFFSET(0x19c4, 0x1a6c));
        memcpy((void *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), *(void **) (var5 + 0x30), *(unsigned int *) (var5 + 0x34));

        ((SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x7dc, 0x878)))->Reset();
        for (int var19 = 0; var19 < 4; var19++) {
            int var20;
            void *var21;
            void *var22 = func_020467f0((struct Struct_ov002_0215624c_25 *) S32(REGIONAL_OFFSET(0x1aa0, 0x1bd8)), var19, &var21, &var20);
            func_0205a528((void *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)), var22, var20, arg0 + REGIONAL_OFFSET(0x7dc, 0x878));
        }

        S16(REGIONAL_OFFSET(0x1aa8, 0x1be0)) = 0;
        func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + REGIONAL_OFFSET(0xe20, 0xec8)), 0, 2);

        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) == 0 && U8(REGIONAL_OFFSET(0x2364, 0x253c)) == 0) {
            func_ov002_0215bf34(arg0);
            func_ov002_0215c028(arg0);
            int var23   = S32(REGIONAL_OFFSET(0x1a80, 0x1bb8));
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 1;
            func_ov002_02161cf0(arg0);
            func_ov002_0215c0f8(arg0);
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = var23;
        }

        S32(REGIONAL_OFFSET(0x22ac, 0x247c)) |= 4;
        REG16(0x04000008) = (REG16(0x04000008) & ~3) | 3;
        REG16(0x0400000a) = (REG16(0x0400000a) & ~3) | 2;
        REG16(0x0400000c) = (REG16(0x0400000c) & ~3) | 1;
        REG16(0x0400000e) = (REG16(0x0400000e) & ~3);
        REG32(0x04000000) = (REG32(0x04000000) & ~0x1f00) | 0x1f00;
        func_0205d0e0(arg0 + REGIONAL_OFFSET(0xe20, 0xec8), S32(REGIONAL_OFFSET(0x1a68, 0x1ba0)));
        func_0205d0e0(arg0 + REGIONAL_OFFSET(0xe20, 0xec8), S32(REGIONAL_OFFSET(0x1a68, 0x1ba0)));

        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) != 0) {
            char *var24                 = (char *) GameState::GetInstance();
#if defined(jpn)
            *(short *) (var24 + 0x6f9c) = 0;
            *(short *) (var24 + 0x6f9e) = -1;
            *(short *) (var24 + 0x6fa0) = -1;
#else
            *(short *) (var24 + 0x71dc) = 0;
            *(short *) (var24 + 0x7f58) = 0;
            *(short *) (var24 + 0x71de) = -1;
            *(short *) (var24 + 0x71e0) = -1;
#endif
        }

#if defined(jpn)
        S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = var0->QueueLoadFile(data_ov002_0216d50c, 0);
        S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)) = var0->QueueLoadFile(data_ov002_0216d520, 0);
#else
        S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = var0->QueueLoadFileInGP2(data_ov002_0216ced4, data_ov002_0216cee8, 0);
        S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)) = var0->QueueLoadFileInGP2(data_ov002_0216cef8, data_ov002_0216cf11, 0);
#endif
        S32(REGIONAL_OFFSET(0x1a88, 0x1bc0))++;
    } else if (S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) == 1) {
        unsigned char var25 = 0;
        for (int var26 = 0; var26 < 2; var26++) {
            if (var0->GetTaskStatus(*(int *) (arg0 + var26 * 4 + REGIONAL_OFFSET(0x1a6c, 0x1ba4)))) {
                var25++;
            }
        }
        if (var25 != 2) {
            return;
        }

        if (var0->GetTaskStatus(S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)))) {
            void *var27;
            void *var28;
            unsigned int var29;
            int var30;
            var0->GetLoadedFileByID(S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)), &var28, &var29);
            int var31 = func_02046900((struct Struct_ov002_0215624c_26 *) var28);
            for (unsigned char var32 = 0; var32 < REGIONAL_OFFSET(0x2c, 0x2b); var32++) {
                func_0205a198((struct Struct_ov002_0215624c_23 *) (S32(REGIONAL_OFFSET(0x19bc, 0x1a64)) + var32 * 0x28));
            }
            func_0205a234((struct Struct_ov002_0215624c_24 *) S32(REGIONAL_OFFSET(0x19c4, 0x1a6c)));
            func_0205a444((char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)));
            *(unsigned char *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x50) = 0;
            {
                char *var33               = (char *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68));
                *(int *) (var33 + 0x40)   = S32(REGIONAL_OFFSET(0x19bc, 0x1a64));
                *(short *) (var33 + 0x4c) = REGIONAL_OFFSET(0x2c, 0x2b);
            }
            *(int *) (S32(REGIONAL_OFFSET(0x19c0, 0x1a68)) + 0x3c) = S32(REGIONAL_OFFSET(0x19c4, 0x1a6c));
            ((SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x7dc, 0x878)))->Reset();
            for (int var34 = 0; var34 < var31; var34++) {
                void *var35 = func_020467f0((struct Struct_ov002_0215624c_25 *) var28, var34, &var27, &var30);
                func_0205a528((void *) S32(REGIONAL_OFFSET(0x19c0, 0x1a68)), var35, var30, arg0 + REGIONAL_OFFSET(0x7dc, 0x878));
            }
            var0->RemoveTask(S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)));
            S32(REGIONAL_OFFSET(0x1a6c, 0x1ba4)) = -1;
        }

        if (var0->GetTaskStatus(S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)))) {
            void *var36;
            unsigned int var37;
            var0->GetLoadedFileByID(S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)), &var36, &var37);
            ((SafeAllocator *) (arg0 + REGIONAL_OFFSET(0x7a0, 0x83c)))->Reset();
            func_020dfec0(arg0 + REGIONAL_OFFSET(0x8, 0x20), arg0 + REGIONAL_OFFSET(0x7a0, 0x83c), var36, var37);
            S32(REGIONAL_OFFSET(0x1aa4, 0x1bdc)) = func_020e0434((struct Struct_0201099c_3 *) (arg0 + REGIONAL_OFFSET(0x8, 0x20)), 0);
            var0->RemoveTask(S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)));
            S32(REGIONAL_OFFSET(0x1a70, 0x1ba8)) = -1;
        }

        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) != 0) {
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 4;
            S32(REGIONAL_OFFSET(0x1a84, 0x1bbc)) = Enum_ov002_0215624c_43;
            S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) = 0;
        } else {
            S32(REGIONAL_OFFSET(0x1a80, 0x1bb8)) = 1;
            S32(REGIONAL_OFFSET(0x1a84, 0x1bbc)) = Enum_ov002_0215624c_43;
            S32(REGIONAL_OFFSET(0x1a88, 0x1bc0)) = 1;
        }
        S32(REGIONAL_OFFSET(0x22ac, 0x247c)) |= 2;
        U8(REGIONAL_OFFSET(0x22aa, 0x247a)) = 0;
        if (U8(REGIONAL_OFFSET(0x22b5, 0x2485)) == 0) {
            func_ov002_0215a938(arg0);
        }
        func_020dc7e8(1, -1);
        func_020dc7e8(8, -1);
    }
}
