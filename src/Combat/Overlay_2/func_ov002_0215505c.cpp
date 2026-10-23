#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_0201099c_14;
struct Struct_0205cfd4;
struct Struct_02020cb8;
struct Struct_020a9ea4;

struct Struct_ov002_0215505c {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 7;
};

void *Clear12Bytes020e46c4(void *p);
struct Obj021e1318;
void ClearObj_021e1318(Obj021e1318*);
void KeyTable_Reset(struct Struct020dfc40 *s);
extern "C" void func_02074af4(void *state);
void InitStruct0205cfd4(struct InitTarget0205cfd4 *t);
void Background_Init(struct List0204af64 *l);
extern "C" void func_0204c684(void *p);
extern "C" void *memset(void *dst, int value, unsigned int length);
int CopyOutRegion0x5718_02011494(char *obj, void *dst);
extern "C" char *func_0205ec34(void);
extern "C" unsigned short func_0206e384(unsigned char *arg0);
extern "C" short func_0206e3d4(int arg0, int arg1);
extern "C" void func_ov002_0215b234(char *arg0);
extern "C" void func_020a9ea4(struct Struct_020a9ea4 *arg0);
extern "C" void func_ov016_0218b5c0(int arg0, int arg1);
extern "C" void func_ov002_0215b814(char *arg0);

extern "C" unsigned char data_ov002_0216d3ac;

#define RESET(off) ((SafeAllocator *) (arg0 + (off)))->ResetAllocatorPointer()
#define S16(off) (*(short *) (arg0 + (off)))
#define S32(off) (*(int *) (arg0 + (off)))
#define U8(off) (*(unsigned char *) (arg0 + (off)))
#define S8(off) (*(signed char *) (arg0 + (off)))

// USA: func_ov002_0215505c
extern "C" ARM void func_ov002_0215505c(char *arg0) {
#if defined(jpn)
    unsigned char var0[4];
    RESET(0x7f0);
    RESET(0x7dc);
    RESET(0x7b4);
    RESET(0x7c8);
    RESET(0x7a0);
    RESET(0x78c);
    RESET(0x774);
    func_ov023_021e1318((Struct_ov002_0215505c_2*)(arg0 + 0x768));
    RESET(0x804);
    KeyTable_Reset((struct Struct020dfc40 *) (self + 0x8));
    U8(0x30) = 0;
    U8(0x31) = 0;
    func_02074af4(arg0 + 0x20);
    S32(0x34)                            = (*(volatile unsigned int *) 0x4000000 & 0x1f00) >> 8;
    *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    for (int var1 = 0; var1 < 5; var1++) {
        *(int *) (arg0 + var1 * 4 + 0x1a6c) = -1;
    }
    InitStruct0205cfd4((struct InitTarget0205cfd4 *) (self + 0xe20));
    for (int i = 0; i < 3; i++) {
        Background_Init((struct List0204af64 *) (self + 0xedc + i * 0x20));
    }
    for (int var3 = 0; var3 < 12; var3++) {
        func_0204c684(arg0 + 0xf3c + var3 * 0xe0);
    }
    S32(0x19bc) = 0;
    S32(0x19c0) = 0;
    for (int var4 = 0; var4 < 4; var4++) {
        memset(arg0 + 0x19c8 + var4 * 0x10, 0, 4);
        memset(arg0 + 0x1a08 + var4 * 0x18, 0, 4);
    }
    S32(0x1a68) = 0;
    S32(0x1a80) = 0;
    S32(0x1a84) = 0x2e;
    S32(0x1a88) = 0;
    S32(0x1a8c) = -1;
    S32(0x228c) = -1;
    S32(0x1a90) = 0;
    S32(0x1a94) = 0;
    S32(0x1a98) = 0;
    S32(0x1a9c) = 0;
    S32(0x1aa0) = 0;
    S32(0x1aa4) = 0;
    for (int var5 = 0; var5 < 2; var5++) {
        *(int *) (arg0 + var5 * 4 + 0x22c0) = 0;
    }
    S16(0x1aa8)         = 0;
    S16(0x1aaa)         = -1;
    S16(0x1aac)         = -1;
    S16(0x1aae)         = -1;
    S16(0x1ab0)         = -1;
    S16(0x1ab2)         = -1;
    S16(0x1ab4)         = -1;
    S16(0x1ab6)         = -1;
    S16(0x1ab8)         = -1;
    S16(0x1aba)         = -1;
    S16(0x1abc)         = -1;
    S16(0x1abe)         = -1;
    S16(0x1ac0)         = -1;
    S16(0x1ac2)         = -1;
    S16(0x1ac4)         = -1;
    S16(0x1ac6)         = -1;
    S16(0x1ac8)         = 1;
    S16(0x1aca)         = -1;
    S16(0x1acc)         = -1;
    S16(0x1ace)         = -1;
    S16(0x1ad0)         = -1;
    U8(0x2288)          = 0;
    U8(0x2289)          = 0;
    S16(0x1ad2)         = 0;
    S16(0x1ad4)         = 0;
    S16(0x1ad6)         = 0;
    S16(0x1ad8)         = 0;
    S16(0x1ada)         = 0;
    S16(0x1adc)         = 0;
    S16(0x1ade)         = 0;
    S16(0x1ae0)         = 0;
    S32(0x1ae4)         = 0;
    U8(0x1b70)          = 0;
    U8(0x1b71)          = 0;
    U8(0x1b74)          = 0;
    U8(0x1b72)          = 0;
    U8(0x1b73)          = 0;
    U8(0x1b75)          = 0;
    U8(0x1b86)          = 0;
    U8(0x1b89)          = 0;
    S32(0x2280)         = 0;
    S32(0x2284)         = 0;
    U8(0x228a)          = 0;
    S32(0x2290)         = 0;
    S32(0x2294)         = 0;
    S32(0x2298)         = 0;
    S32(0x229c)         = 0;
    U8(0x22a0)          = 0;
    U8(0x22a1)          = 0;
    U8(0x22a2)          = 0;
    S8(0x1ae8)          = -1;
    S8(0x1ae9)          = -1;
    S16(0x1aea)         = -1;
    S16(0x1aec)         = -1;
    S16(0x1aee)         = -1;
    S16(0x1af2)         = -1;
    S16(0x1af0)         = S16(0x1af2);
    U8(0x1af6)          = 0;
    U8(0x1af7)          = 0;
    U8(0x1af8)          = 0;
    U8(0x1af9)          = 0;
    U8(0x1afa)          = 0;
    data_ov002_0216d3ac = 0;
    U8(0x1afb)          = 0;
    for (int var6 = 0; var6 < 5; var6++) {
        *(int *) (arg0 + var6 * 4 + 0x1b00) = -1;
    }
    for (int var7 = 0; var7 < 5; var7++) {
        *(int *) (arg0 + var7 * 4 + 0x1b18) = -1;
    }
    for (int var8 = 0; var8 < 5; var8++) {
        *(unsigned char *) (arg0 + var8 + 0x1b2c) = 0;
    }
    U8(0x1b31)                              = 0;
    U8(0x1b47)                              = 0;
    U8(0x1b48)                              = 0;
    ((Struct_ov002_0215505c *) (arg0 + 0x1b49))->unknown_0_0_ = 0;
    U8(0x1b3c)                              = 0;
    S32(0x1b38)                             = 0;
    U8(0x1b3d)                              = 2;
    U8(0x1b3e)                              = 0;
    U8(0x1b3f)                              = 0;
    S8(0x1b37)                              = 0;
    GameState *var9                           = GameState::GetInstance();
    S32(0x1afc)                             = func_02011494((char *) var9, var0);
    for (int var10 = 0; var10 < S32(0x1afc); var10++) {
        *(int *) (arg0 + var10 * 4 + 0x1b00) = var0[var10];
        GameObject *var11                    = var9->GetPartyMemberByIndex(var0[var10]);
        if (var11 != 0 && *(int *) ((char *) var11 + 0x1b8) == 0) {
            *(unsigned char *) (arg0 + S8(0x1b37) + 0x1b32) = var0[var10];
            S8(0x1b37)++;
        }
    }
    S32(0x1b14) = func_02011494((char *) var9, var0);
    for (int var12 = 0; var12 < S32(0x1b14); var12++) {
        *(int *) (arg0 + var12 * 4 + 0x1b18) = var0[var12];
    }
    *(int *) (arg0 + S32(0x1b14) * 4 + 0x1b18) = 4;
    S32(0x1b14) += 1;
    U8(0x1b87)        = 0;
    U8(0x22a8)        = 0;
    U8(0x22aa)        = 0;
    char *var13           = func_0205ec34();
    unsigned int var14 = (func_0206e384((unsigned char *) var13) << 16) | 0xffff;
    S32(0x22b0)       = 0;
    for (int var15 = 0; var15 < 0x20; var15++) {
        if (var14 & 1) {
            short var16 = func_0206e3d4((int) var13, (short) (var15 + 1));
            *(unsigned int *) (arg0 + 0x22b0) |= 1 << (var16 - 1);
        }
        var14 >>= 1;
    }
    U8(0x22b4) = 0;
    memset(arg0 + 0x1b40, -1, 7);
    U8(0x22ab)  = 0;
    S32(0x22ac) = 0;
    U8(0x22b5)  = 0;
    U8(0x22b6)  = 0;
    U8(0x22b7)  = 0;
    S16(0x22b8) = -1;
    U8(0x22ba)  = 0;
    U8(0x22bc)  = 0;
    U8(0x22bd)  = 0;
    U8(0x2351)  = 0;
    U8(0x2352)  = 0;
    U8(0x2353)  = 0;
    memset(arg0 + 0x2354, 0, 0xc);
    S32(0x2360) = 0;
    func_ov002_0215b234(arg0);
    RESET(0x774);
    RESET(0x78c);
    RESET(0x7a0);
    RESET(0x7b4);
    RESET(0x7c8);
    RESET(0x7dc);
    RESET(0x7f0);
    func_020a9ea4((struct Struct_020a9ea4 *) (arg0 + 0x22c8));
    for (unsigned char var17 = 0; var17 < 0x20; var17++) {
        *(int *) (arg0 + var17 * 4 + 0x22d0) = 0;
    }
    U8(0x2350)  = 0;
    S16(0x2370) = 0;
    S16(0x2372) = 0;
    S32(0x2374) = 0;
    func_ov016_0218b5c0(1, -1);
    U8(0x22be) = 0;
    U8(0x22bf) = 0;
    func_ov002_0215b814(arg0);
#else
    unsigned char var18[4];
    func_020e46c4(arg0 + 8);
    func_020e46c4(arg0 + 0x14);
    RESET(0x88c);
    RESET(0x878);
    RESET(0x850);
    RESET(0x864);
    RESET(0x83c);
    RESET(0x828);
    RESET(0x810);
    func_ov023_021e1318((Struct_ov002_0215505c_2*)(arg0 + 0x804));
    RESET(0x8a0);
    KeyTable_Reset((struct Struct020dfc40 *) (self + 0x20));
    U8(0x48) = 0;
    U8(0x49) = 0;
    func_02074af4(arg0 + 0x38);
    S32(0x4c)                            = (*(volatile unsigned int *) 0x4000000 & 0x1f00) >> 8;
    *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
    for (int var19 = 0; var19 < 5; var19++) {
        *(int *) (arg0 + var19 * 4 + 0x1ba4) = -1;
    }
    InitStruct0205cfd4((struct InitTarget0205cfd4 *) (self + 0x2c8 + 0xc00));
    for (int i = 0; i < 3; i++) {
        Background_Init((struct List0204af64 *) (self + 0x384 + 0xc00 + i * 0x20));
    }
    for (int var21 = 0; var21 < 12; var21++) {
        func_0204c684(arg0 + 0x3e4 + 0xc00 + var21 * 0xe0);
    }
    S32(0x1a64) = 0;
    S32(0x1a68) = 0;
    for (int var22 = 0; var22 < 4; var22++) {
        memset(arg0 + 0xa70 + 0x1000 + var22 * 0x10, 0, 4);
        memset(arg0 + 0xab0 + 0x1000 + var22 * 0x3c, 0, 4);
    }
    S32(0x1ba0) = 0;
    S32(0x1bb8) = 0;
    S32(0x1bbc) = 0x2b;
    S32(0x1bc0) = 0;
    S32(0x1bc4) = -1;
    S32(0x2458) = -1;
    S32(0x1bc8) = 0;
    S32(0x1bcc) = 0;
    S32(0x1bd0) = 0;
    S32(0x1bd4) = 0;
    S32(0x1bd8) = 0;
    S32(0x1bdc) = 0;
    for (int var23 = 0; var23 < 2; var23++) {
        *(int *) (arg0 + var23 * 4 + 0x2490) = 0;
    }
    S16(0x1be0)         = 0;
    S16(0x1be2)         = -1;
    S16(0x1be4)         = -1;
    S16(0x1be6)         = -1;
    S16(0x1be8)         = -1;
    S16(0x1bea)         = -1;
    S16(0x1bec)         = -1;
    S16(0x1bee)         = -1;
    S16(0x1bf0)         = -1;
    S16(0x1bf2)         = -1;
    S16(0x1bf4)         = -1;
    S16(0x1bf6)         = -1;
    S16(0x1bf8)         = -1;
    S16(0x1bfa)         = -1;
    S16(0x1bfc)         = -1;
    S16(0x1bfe)         = -1;
    S16(0x1c00)         = 1;
    S16(0x1c02)         = -1;
    S16(0x1c04)         = -1;
    S16(0x1c06)         = -1;
    S16(0x1c08)         = -1;
    U8(0x2454)          = 0;
    U8(0x2455)          = 0;
    S16(0x1c0a)         = 0;
    S16(0x1c0c)         = 0;
    S16(0x1c0e)         = 0;
    S16(0x1c10)         = 0;
    S16(0x1c12)         = 0;
    S16(0x1c14)         = 0;
    S16(0x1c16)         = 0;
    S16(0x1c18)         = 0;
    S32(0x1c1c)         = 0;
    U8(0x1cac)          = 0;
    U8(0x1cad)          = 0;
    U8(0x1cb0)          = 0;
    U8(0x1cae)          = 0;
    U8(0x1caf)          = 0;
    U8(0x1cb1)          = 0;
    U8(0x1cc2)          = 0;
    U8(0x1cc5)          = 0;
    S32(0x2448)         = 0;
    S32(0x244c)         = 0;
    S32(0x2450)         = 0;
    U8(0x2456)          = 0;
    S16(0x245c)         = 0;
    S32(0x2460)         = 0;
    S32(0x2464)         = 0;
    S32(0x2468)         = 0;
    S32(0x246c)         = 0;
    U8(0x2470)          = 0;
    U8(0x2471)          = 0;
    U8(0x2472)          = 0;
    S8(0x1c20)          = -1;
    S8(0x1c21)          = -1;
    S16(0x1c22)         = -1;
    S16(0x1c24)         = -1;
    S16(0x1c26)         = -1;
    S16(0x1c2a)         = -1;
    S16(0x1c28)         = S16(0x1c2a);
    U8(0x1c2e)          = 0;
    U8(0x1c2f)          = 0;
    U8(0x1c30)          = 0;
    U8(0x1c31)          = 0;
    U8(0x1c32)          = 0;
    data_ov002_0216d3ac = 0;
    U8(0x1c33)          = 0;
    U8(0x1c34)          = 0;
    for (int var24 = 0; var24 < 5; var24++) {
        *(int *) (arg0 + var24 * 4 + 0x1c3c) = -1;
    }
    for (int var25 = 0; var25 < 5; var25++) {
        *(int *) (arg0 + var25 * 4 + 0x1c54) = -1;
    }
    for (int var26 = 0; var26 < 5; var26++) {
        *(unsigned char *) (arg0 + var26 + 0x1c68) = 0;
    }
    U8(0x1c6d)                              = 0;
    U8(0x1c83)                              = 0;
    U8(0x1c84)                              = 0;
    ((Struct_ov002_0215505c *) (arg0 + 0x1c85))->unknown_0_0_ = 0;
    U8(0x1c78)                              = 0;
    S32(0x1c74)                             = 0;
    U8(0x1c79)                              = 2;
    U8(0x1c7a)                              = 0;
    U8(0x1c7b)                              = 0;
    S8(0x1c73)                              = 0;
    GameState *var27                           = GameState::GetInstance();
    S32(0x1c38)                             = func_02011494((char *) var27, var18);
    for (int var28 = 0; var28 < S32(0x1c38); var28++) {
        *(int *) (arg0 + var28 * 4 + 0x1c3c) = var18[var28];
        GameObject *var29                    = var27->GetPartyMemberByIndex(var18[var28]);
        if (var29 != 0 && *(int *) ((char *) var29 + 0x1c4) == 0) {
            *(unsigned char *) (arg0 + S8(0x1c73) + 0x1c6e) = var18[var28];
            S8(0x1c73)++;
        }
    }
    S32(0x1c50) = func_02011494((char *) var27, var18);
    for (int var30 = 0; var30 < S32(0x1c50); var30++) {
        *(int *) (arg0 + var30 * 4 + 0x1c54) = var18[var30];
    }
    *(int *) (arg0 + S32(0x1c50) * 4 + 0x1c54) = 4;
    S32(0x1c50) += 1;
    U8(0x1cc3)        = 0;
    U8(0x2478)        = 0;
    U8(0x247a)        = 0;
    char *var31           = func_0205ec34();
    unsigned int var32 = (func_0206e384((unsigned char *) var31) << 16) | 0xffff;
    S32(0x2480)       = 0;
    for (int var33 = 0; var33 < 0x20; var33++) {
        if (var32 & 1) {
            short var34 = func_0206e3d4((int) var31, (short) (var33 + 1));
            *(unsigned int *) (arg0 + 0x2480) |= 1 << (var34 - 1);
        }
        var32 >>= 1;
    }
    U8(0x2484) = 0;
    memset(arg0 + 0x7c + 0x1c00, -1, 7);
    U8(0x247b)  = 0;
    S32(0x247c) = 0;
    U8(0x2485)  = 0;
    U8(0x2486)  = 0;
    U8(0x2487)  = 0;
    S16(0x2488) = -1;
    U8(0x248a)  = 0;
    U8(0x248c)  = 0;
    U8(0x248d)  = 0;
    U8(0x2521)  = 0;
    U8(0x2522)  = 0;
    U8(0x2523)  = 0;
    memset(arg0 + 0x124 + 0x2400, 0, 0xc);
    S32(0x2530) = 0;
    S32(0x2534) = 0;
    S32(0x2538) = 0;
    func_ov002_0215b234(arg0);
    RESET(0x810);
    RESET(0x828);
    RESET(0x83c);
    RESET(0x850);
    RESET(0x864);
    RESET(0x878);
    RESET(0x88c);
    func_020a9ea4((struct Struct_020a9ea4 *) (arg0 + 0x98 + 0x2400));
    for (unsigned char var35 = 0; var35 < 0x20; var35++) {
        *(int *) (arg0 + var35 * 4 + 0x24a0) = 0;
    }
    U8(0x2520)  = 0;
    S16(0x2548) = 0;
    S16(0x254a) = 0;
    S32(0x254c) = 0;
    func_ov016_0218b5c0(1, -1);
    U8(0x248e) = 0;
    U8(0x248f) = 0;
    func_ov002_0215b814(arg0);
#endif
}
