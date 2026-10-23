#include "GameState/GameState.h"
#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define func_020dcf7c func_020de968
extern "C" void func_020de968(int arg0, void *arg1);
extern "C" void func_020474a8(void *arg0, int arg1, const char *arg2, char *arg3);
#else
#define REGION_LAYOUT(j,u) u
#endif

struct Struct_0201099c_10;
struct Struct_0201099c_3;
struct Struct_02046574_2;
struct Struct_020465c0;
extern "C" void *func_020e2ff8(void);
extern "C" void func_020e3428(void *arg0, int arg1);
extern "C" int func_020421a0(void);
extern "C" char *func_020dedd0(struct Struct_0201099c_10 *arg0, int arg1);
extern "C" void *memset(void *arg0, int arg1, unsigned int arg2);
extern "C" void func_02046380(void *arg0);
extern "C" void *func_020e46c4(void *arg0);
extern "C" void func_02046574(struct Struct_02046574_2 *arg0, int arg1, char *arg2);
extern "C" void func_020e4bf4(void *arg0, int arg1);
extern "C" void __clear(void *arg0, int arg1);
#if !defined(jpn)
extern "C" void func_020dcf7c(int arg0, void *arg1);
#endif
void SetByteInRange_020465f0(unsigned char *base, int index, unsigned char value);
void StoreInArray0x8b0_020465c0(struct StoreStruct *base, int index, int value);
int KeyTable_Get(struct Container020e0310 *c, int key);
int AppendString02042058(char *dst, const char *src);
extern "C" void func_02046608(void *a, int b, int c, void *d, int e, int f, int g);
extern "C" void func_ov016_0218b5c0(int a, int b);

struct Struct_ov002_02159900 {
    char *unknown_0_;
    char *unknown_4_;
    int unknown_8_;
};

#define TXT(k) KeyTable_Get((struct Container020e0310 *) (base + REGION_LAYOUT(8, 0x20)), (k))
#define BD0 (*(char **) (base + REGION_LAYOUT(0x1a98, 0x1000 + 0xbd0)))

// USA: func_ov002_02159900
extern "C" ARM void func_ov002_02159900(char *arg0, char *arg1, int arg2) {
    func_020e3428(func_020e2ff8(), 1);
    GameState *var0      = GameState::GetInstance();
    char *var1            = (char *) func_020421a0();
    unsigned char *var2 = (unsigned char *) (arg1 + 8);
    char *var3            = func_020dedd0((struct Struct_0201099c_10 *) (arg0 + REGION_LAYOUT(0x750, 0x3ec + 0x400)),
                                                                           *(short *) (arg0 + REGION_LAYOUT(0x1aea, 0x1c00 + 0x22)));
    if (var3 == NULL) return;
#if defined(jpn)
    memset(*(void **) (arg0 + 0x1a98), 0, 0x800);
    memset(*(void **) (arg0 + 0x1a9c), 0, 0x800);
    func_02046380(var1);
    char *var4 = *(char **) (arg0 + 0x1a98);
    char *var5   = (char *)func_0200ff1c(var0, *(signed char *) (arg1 + 2));
    if (var5 != NULL) {
        func_02046574((struct Struct_02046574_2 *) var1, 0, *(char **) (var5 + 0x134));
    }
    char var6[0x40];
    __clear(var6, 0x40);
    func_020dcf7c(*(short *) (var3 + 0x18), var6);
    func_02046574((struct Struct_02046574_2 *) var1, 1, var6);
    char *var7 = (char *)func_0200ff1c(var0, *(signed char *) (arg1 + 4));
    if (var7 != NULL) {
        func_02046574((struct Struct_02046574_2 *) var1, 2, *(char **) (var7 + 0x134));
        func_020465f0((unsigned char *) var1, 9, 0);
        func_020465c0((struct Struct_020465c0 *) var1, 9, *(short *) (var7 + 4));
    }
#else
    memset(*(void **) (arg0 + 0x1000 + 0xbd0), 0, 0x960);
    memset(*(void **) (arg0 + 0x1000 + 0xbd4), 0, 0x960);
    func_02046380(var1);
    func_020e46c4(arg0 + 8);
    func_020e46c4(arg0 + 0x14);
    char *var8 = *(char **) (arg0 + 0x1000 + 0xbd0);
    char *var9   = (char *)func_0200ff1c(var0, *(signed char *) (arg1 + 2));
    if (var9 != NULL) {
        func_02046574((struct Struct_02046574_2 *) var1, 0, *(char **) (var9 + 0x134));
        func_020e4bf4(arg0 + 8, *(signed char *) (arg1 + 2));
        *(char **) var1 = arg0 + 8;
    }
    struct Struct_ov002_02159900 var10;
    char var11[0x80];
    char var12[0x80];
    func_020e46c4(&var10);
    __clear(var11, 0x80);
    __clear(var12, 0x80);
    var10.unknown_0_ = var11;
    var10.unknown_4_ = var12;
    func_020dcf7c(*(short *) (var3 + 0x18), &var10);
    *(struct Struct_ov002_02159900 **) (var1 + 0x18) = &var10;
    func_02046574((struct Struct_02046574_2 *) var1, 1, var10.unknown_0_);
    char *var13 = (char *)func_0200ff1c(var0, *(signed char *) (arg1 + 4));
    if (var13 != NULL) {
        func_02046574((struct Struct_02046574_2 *) var1, 2, *(char **) (var13 + 0x134));
        func_020e4bf4(arg0 + 0x14, *(signed char *) (arg1 + 4));
        *(char **) (var1 + 0x10) = arg0 + 0x14;
        func_020465f0((unsigned char *) var1, 9, 0);
        func_020465c0((struct Struct_020465c0 *) var1, 9, *(short *) (var13 + 4));
    }
#endif
    int var14              = 0x7918;
    int var15              = 0x7919;
    unsigned char var16 = 0;
    switch ((*(unsigned int *) (var3 + 8) << 1) >> 27) {
        case 2:
            var14 = 0x7922;
            var15 = 0x7923;
            break;
        case 3:
            if (var2[0] == 3) {
                var14 = 0x792c;
                var15 = 0x7941;
            } else {
                var14 = 0x7936;
            }
            break;
        case 4:
            if (var2[0] == 3) {
                var14 = 0x792c;
                var15 = 0x794b;
            } else {
                var14 = 0x7936;
            }
            break;
        case 5:
            if (arg2) {
                var16 = 1;
                func_02042058(BD0, (const char *) TXT(0x792c));
                if (var2[0] == 3) {
                    func_02042058(BD0, (const char *) TXT(8));
                    func_02042058(BD0, (const char *) TXT(0x7941));
                }
                if (*(unsigned char *) (arg1 + 0x20) == 3) {
                    func_02042058(BD0, (const char *) TXT(8));
                    func_02042058(BD0, (const char *) TXT(0x794b));
                }
            } else {
                var14 = 0x7936;
            }
            break;
        case 6:
            if (var2[0] == 3) {
                *(signed char *) (arg0 + REGION_LAYOUT(0x1ae8, 0x1000 + 0xc20))   = *(signed char *) (arg1 + 2);
                *(short *) (arg0 + REGION_LAYOUT(0x1af0, 0x1c00 + 0x28))          = 0x792c;
                *(short *) (arg0 + REGION_LAYOUT(0x1af2, 0x1c00 + 0x2a))          = var16 - 1;
                *(short *) (arg0 + REGION_LAYOUT(0x22b8, 0x2400 + 0x88))          = 0x7955;
                *(unsigned char *) (arg0 + REGION_LAYOUT(0x22ba, 0x2000 + 0x48a)) = 1;
                return;
            }
            var14 = 0x7936;
            break;
        case 7:
            if (arg2) {
                var16 = 1;
#if defined(jpn)
                func_020474a8(var1, 0xc, (const char *) TXT(0x792c), var4 + 0x700);
                func_02042058(BD0, var4 + 0x700);
#else
                func_02046608(var1, 0xc, TXT(0x792c), var8 + 0x860, 0xe3, 0, 1);
                func_02042058(BD0, var8 + 0x860);
#endif
                int var17;
                for (var17 = 0; var17 < *(unsigned char *) (arg1 + 3); var17++) {
                    if (var2[var17 * 6] == 3) {
                        var15 = 0x7941;
                    } else {
                        var15 = 0x233a;
                    }
                    if (var15 >= 0) {
                        int var18 = *(signed char *) (arg1 + var17 + 4);
                        char *var19 = (char *)func_0200ff1c(var0, var18);
                        if (var19 != NULL) {
                            func_02046380(var1);
#if defined(jpn)
                            func_02046574((struct Struct_02046574_2 *) var1, 2, *(char **) (var19 + 0x134));
                            func_020465c0((struct Struct_020465c0 *) var1, 9, var18);
                            func_020474a8(var1, 0xc, (const char *) TXT(var15), var4 + 0x700);
                            func_02042058(BD0, (const char *) TXT(8));
                            func_02042058(BD0, var4 + 0x700);
#else
                            func_02046574((struct Struct_02046574_2 *) var1, 2, *(char **) (var19 + 0x134));
                            func_020e4bf4(arg0 + 0x14, var18);
                            *(char **) (var1 + 0x10) = arg0 + 0x14;
                            func_020465c0((struct Struct_020465c0 *) var1, 9, var18);
                            func_02046608(var1, 0xc, TXT(var15), var8 + 0x860, 0xe3, 0, 1);
                            func_02042058(BD0, (const char *) TXT(8));
                            func_02042058(BD0, var8 + 0x860);
#endif
                        }
                    }
                }
            } else {
                func_ov016_0218b5c0(1, -1);
                var14 = 0x7936;
                var15 = 0x7919;
            }
            break;
        case 8:
            if (var2[0] != 3) {
                var14 = 0x7936;
                break;
            }
            func_020465f0((unsigned char *) var1, var16, var16);
            func_020465c0((struct Struct_020465c0 *) var1, 0, *(short *) (var2 + 2));
            var14 = 0x792c;
            var15 = 0x795f;
            break;
        case 9:
            var14 = 0x7968;
            if (var2[0] == 3) var15 = 0x7969;
            break;
        case 12:
            var14 = 0x7986;
            var15 = 0x7987;
            break;
        case 13:
            if (var2[0] == 3) {
                func_020465f0((unsigned char *) var1, var16, var16);
                func_020465c0((struct Struct_020465c0 *) var1, 0, *(short *) (var2 + 2));
                int var20 = -1;
                switch (*(short *) (var3 + 0x18)) {
                    case 0x561d: var20 = 0x7991; break;
                    case 0x561e: var20 = 0x7992; break;
                    case 0x561f: var20 = 0x7993; break;
                    case 0x5620: var20 = 0x7994; break;
                    case 0x5621: var20 = 0x7995; break;
                    case 0x5622: var20 = 0x7996; break;
                    case 0x5623: var20 = 0x7998; break;
                    case 0x5624: var20 = 0x7999; break;
                    case 0x5619: var20 = 0x7997; break;
                }
                func_02046574((struct Struct_02046574_2 *) var1, 5, (char *) TXT(var20));
                var14 = 0x792c;
                var15 = 0x7990;
            } else {
                var14 = 0x7936;
            }
            break;
        case 14:
            if (var2[0] != 3) {
                var14 = 0x7936;
                break;
            }
            func_020465f0((unsigned char *) var1, var16, var16);
            func_020465c0((struct Struct_020465c0 *) var1, 0, *(short *) (var2 + 2));
            var14 = 0x792c;
            var15 = 0x799b;
            break;
        case 15:
            var14 = 0x79a4;
            var15 = 0x79a5;
            break;
        case 16:
            var14 = 0x79ae;
            var15 = 0x79af;
            break;
        case 17:
            var14 = 0x79b8;
            var15 = 0x79b9;
            break;
        case 18:
            var14 = 0x79c2;
            var15 = 0x79c3;
            break;
        case 19:
            var14 = 0x79cc;
            var15 = 0x79cd;
            break;
        case 20:
            var14 = 0x79d6;
            var15 = 0x79d7;
            break;
        case 21:
            var14 = 0x79e0;
            var15 = 0x79e1;
            break;
    }
    if (!var16) {
        func_02042058(BD0, (const char *) TXT(var14));
        func_02042058(BD0, (const char *) TXT(8));
        func_02042058(BD0, (const char *) TXT(var15));
    }
#if defined(jpn)
    func_020474a8(var1, 0xc, *(const char **) (arg0 + 0x1a98), *(char **) (arg0 + 0x1a9c));
    *(unsigned char *) (arg0 + 0x1af9) = 1;
    *(short *) (arg0 + 0x22b8)          = -1;
    *(unsigned char *) (arg0 + 0x22ba) = 0;
#else
    func_02046608(var1, 0xc, *(int *) (arg0 + 0x1000 + 0xbd0), *(void **) (arg0 + 0x1000 + 0xbd4), 0xe3, 0, 1);
    *(unsigned char *) (arg0 + 0x1000 + 0xc31) = 1;
    *(short *) (arg0 + 0x2400 + 0x88)          = -1;
    *(unsigned char *) (arg0 + 0x2000 + 0x48a) = 0;
#endif
}
