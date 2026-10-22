#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Matrix.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Struct_0205dee8;
struct Struct_020a83b0;
struct Struct_02048350_2;
struct Struct_ov002_02165b44 {
    char *unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
};
struct TailList020469b4;
struct TailNode020469b4;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow, unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int a, int b);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
void ClearMatchingEntry_02156ff0(unsigned char *self, int v);
int GetField0x397cValue_020100b0(GameState *gs);
GameObject *GetCombatantChecked_0200ff94(GameState *gs, int id);
int TestBitInByteArray_0206dfb0(int unused, unsigned char *arr, int index);
char *FindEntryByByteId020a83b0(struct List020a83b0 *l, int id);
char *SearchBothTables02079e2c(char *t, int id);
void ConsumeCounter02048350(struct Obj02048350 *o, int n);
int CheckField0NonZero_0202b7d8(int *p);
void *GetField0x3f8Address_0200fd0c(GameState *state);
extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);
extern "C" void *func_0200fcfc(void *arg0, const void *arg1);
extern "C" void func_ov017_021acd30(char *arg0, unsigned char arg1, unsigned char arg2, unsigned char arg3);
extern "C" void func_ov017_0219e310(unsigned char *arg0, int arg1);
extern "C" void func_020469b4(struct Struct_0201bdac_2 *arg0, struct Struct_0201bdac *arg1);
extern "C" void func_ov002_02161cf0(char *arg0);
extern "C" void func_ov002_0215f170(char *arg0);
extern "C" void func_ov002_02161b98(char *arg0);
extern "C" void func_ov002_0215a7b4(char *arg0, int arg1, short arg2, int arg3, int arg4);
extern "C" void func_ov002_0215b9a4(char *arg0, unsigned char arg1, int arg2);
extern "C" char *func_0205ec34(void);
extern "C" char *func_02012fe4(void);
extern "C" int *func_0202ae18(void);
extern "C" int func_0202c508(int *p);
extern "C" void func_ov023_021dca88(char *obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
extern "C" char g_sePlayer[];

// USA: func_ov002_02165b44
extern "C" ARM void func_ov002_02165b44(char *arg0) {
#if defined(jpn)
    int var0 = *(int *) (arg0 + 0x1a88);
    if (var0 == 0) {
        *(short *) (arg0 + 0x1ac4) = 0;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xe20), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f170(arg0);
        *(int *) (arg0 + 0x1a88) += 1;
    } else if (var0 == 1) {
        *(unsigned int *) (arg0 + 0x22ac) |= 4;
        func_ov002_02161b98(arg0);
        *(short *) (arg0 + 0x1ac4) = func_0205d794((struct Struct_0205c570 *) (arg0 + 0xe20));
        int var1                            = g_keyManager.TestKeysPressed(0x601);
        int var2 = func_0205da38((struct Struct_0205da38*)(arg0 + 0xe20), 0x14);
        if ((var1 | var2) ? 1 : 0) {
            GameState *var3 = GameState::GetInstance();
            int var4        = *(signed char *) (arg0 + 0x1ae8);
            if (var4 == 4) var4 = func_020100b0(var3);
            GameObject *var5 = func_0200ff94(var3, var4);
            if (var5 == NULL) return;
            *(unsigned char *) (arg0 + 0xed8) = *(int *) (arg0 + 0x1a80);
            *(unsigned int *) (arg0 + 0x22ac) &= ~4;
            if (**(int **) ((char *) var5 + 0x130) & 1) {
                *(short *) (arg0 + 0x1af0) = -1;
                *(short *) (arg0 + 0x1af2) = -1;
                *(int *) (arg0 + 0x1a80)  = 0x12;
                return;
            }
            *(int *) (base + 0x1a88) = 0;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            int save    = (int) func_0205ec34();
            char *world = func_02012fe4();
            int kind    = 0;
            if (!TestBitInByteArray_0206dfb0(save, (unsigned char *) ((char *) save + 0x8c), 0x113a)) {
                char *p = *(char **) (world + 8);
                if (p != NULL) kind = (unsigned int) (*(unsigned char *) (p + 0xe) << 30) >> 30;
            }
            *(short *) (arg0 + 0x1af0) = 0x232d;
            if (var8 == 2) {
                char *var10 = func_020a83b0(*(struct Struct_020a83b0 **) (arg0 + 0x22a4),
                                                    *(short *) (arg0 + 0x1ac4));
                if (var10 != NULL) {
                    int *var11                          = func_0202ae18();
                    *(short *) (arg0 + 0x1af2) = -1;
                    *(int *) (arg0 + 0x1a80)  = 0x29;
                    *(int *) (arg0 + 0x1a84)  = 0x2e;
                    if (*(short *) (arg0 + 0x1aea) == 0x5603) {
                        *(short *) (arg0 + 0x1af0)          = 0x7972;
                        *(short *) (arg0 + 0x1af2)          = -1;
                        *(short *) (arg0 + 0x22b8)          = -1;
                        *(unsigned char *) (arg0 + 0x22ba) = 0;
                        if (*(unsigned int *) (arg0 + 0x22ac) & 1) func_ov023_021dca88(arg0 + 0x38);
                        func_ov002_0215a7b4(arg0, *(signed char *) (arg0 + 0x1ae8), *(short *) (arg0 + 0x1aea),
                                            *(short *) (arg0 + 0x1ab0), 0);
                    } else {
                        SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                        char *t = SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), 0xca);
                        ConsumeCounter02048350(
                            (struct Obj02048350 *) GetCombatantChecked_0200ff94(gs, *(signed char *) (base + 0x1ae8)),
                            ((struct TE5b44 *) t)->lo8);
                        if (CheckField0NonZero_0202b7d8(rec)) func_ov017_021c9e00(*(signed char *) (base + 0x1ae8), 0, 0, 1);
                    }
                    unsigned char *var13 = (unsigned char *) func_0200fd0c(var3);
                    VectorizedMemset(var13, 0, 0x70);
                    var13[4]                       = 1;
                    var13[8]                       = 1;
                    var13[9]                       = 1;
                    *(signed char *) (var13 + 0xb) = -1;
                    *(int *) (var13 + 0x20)        = -1;
                    *(int *) (var13 + 0x24)        = -1;
                    *(int *) (var13 + 0x28)        = -1;
                    *(int *) (var13 + 0x2c)        = -1;
                    *(short *) (var13 + 0x1e)      = -1;
                    var13[0xc]                     = 0;
                    *(short *) (var13 + 0x6c)      = -1;
                    var13[2]                       = 0;
                    var13[4]                       = 0;
                    var13[5]                       = 1;
                    *(unsigned short *) var13      = *(unsigned short *) (var10 + 8);
                    *(Vector3i *) (var13 + 0x10)   = *(Vector3i *) (var10 + 0xc);
                    *(short *) (var13 + 0x1c)      = *(short *) (var10 + 0xa);
                    var13[7]                       = 1;
                    var13[0x63]                    = 0;
                    func_0200fcfc(var3, var13);
                    if (func_0202c508(var11) && func_0206dfb0(var6, (unsigned char *) ((char *) var6 + 0x8c), 0x2b)) {
                        *(unsigned short *) (var7 + 0x27c6) = *(unsigned short *) (var10 + 0x1a);
                        *(unsigned short *) (var7 + 0x27c4) = *(unsigned short *) (var10 + 0x1c);
                        Vector3i *var14                               = (Vector3i *) (var7 + 0x27b4);
                        Vector3i var15                                  = *var14;
                        var15.x                                         = *(int *) (var10 + 0x20);
                        var15.z                                         = *(int *) (var10 + 0x24);
                        *var14                                        = var15;
                        func_ov017_021d1a18(*(short *) (var10 + 0x1a), *(short *) (var10 + 0x1c), 0, 0);
                    }
                    char *var16 = (char *) GetGameResources();
                    func_ov017_021acd30(var16, 0, 0, 0);
                    struct Struct_0201bdac_2 *var17;
                    unsigned char *var18 = *(unsigned char **) (var16 + 0x34fc);
                    var17                  = *(struct Struct_0201bdac_2 **) (var16 + 0x34ec);
                    func_ov017_0219e310(var18, 0);
                    func_020469b4(var17, (struct Struct_0201bdac *) var18);
                    return;
                }
                var8 = 0;
            } else if (var8 == 1) {
                *(short *) (arg0 + 0x1af2) = -1;
                *(int *) (arg0 + 0x1a80)  = 0x29;
                *(int *) (arg0 + 0x1a84)  = 0x2e;
                if (*(short *) (arg0 + 0x1aea) == 0x5603) {
                    *(short *) (arg0 + 0x1af0)          = 0x7972;
                    *(short *) (arg0 + 0x1af2)          = -1;
                    *(short *) (arg0 + 0x22b8)          = -1;
                    *(unsigned char *) (arg0 + 0x22ba) = 0;
                    if (*(unsigned int *) (arg0 + 0x22ac) & 1) func_ov023_021dca88(arg0 + 0x38);
                } else {
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                }
                func_ov017_021acd30((char *) GetGameResources(), 0, 0, 1);
                return;
            }
            if (var8 == 0) {
                if (*(short *) (arg0 + 0x1aea) == 0x5603) {
                    *(short *) (arg0 + 0x1ac4)          = -1;
                    *(short *) (arg0 + 0x1af0)          = 0x7936;
                    *(short *) (arg0 + 0x1af2)          = -1;
                    *(short *) (arg0 + 0x22b8)          = 0x7919;
                    *(unsigned char *) (arg0 + 0x22ba) = 1;
                    *(int *) (arg0 + 0x1a80)           = 0x29;
                    *(int *) (arg0 + 0x1a84)           = 5;
                } else {
                    *(short *) (base + 0x22b8)          = 0x2338;
                    *(unsigned char *) (base + 0x22ba) = 1;
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                    *(int *) (base + 0x1a80) = 0x29;
                    *(int *) (base + 0x1a84) = 0x12;
                }
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1ac4) = -1;
            if (*(short *) (arg0 + 0x1aea) == 0x5603) {
                *(short *) (arg0 + 0x1aea) = -1;
                func_ov002_02156ff0((unsigned char *) arg0, 5);
            } else {
                *(short *) (arg0 + 0x1aee) = -1;
                func_ov002_02156ff0((unsigned char *) arg0, 0x14);
                *(int *) (arg0 + 0x1a80) = 0x12;
                func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0xe20), 0x12);
                func_0205deb4((struct Struct_0205d81c *) (arg0 + 0xe20), 0x12, 0);
                func_ov002_02161cf0(arg0);
                func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1a80) & 0xff, 0);
                *(int *) (arg0 + 0x1a88) = 1;
            }
        }
    }
#else
    int var19 = *(int *) (arg0 + 0x1000 + 0xbc0);
    if (var19 == 0) {
        *(short *) (arg0 + 0x1b00 + 0xfc) = 0;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f170(arg0);
        *(int *) (arg0 + 0x1000 + 0xbc0) += 1;
    } else if (var19 == 1) {
        *(unsigned int *) (arg0 + 0x2000 + 0x47c) |= 4;
        func_ov002_02161b98(arg0);
        *(short *) (arg0 + 0x1b00 + 0xfc) = func_0205d794((struct Struct_0205c570 *) (arg0 + 0x2c8 + 0xc00));
        int var20                            = g_keyManager.TestKeysPressed(0x601);
        int var21 = func_0205da38((struct Struct_0205da38*)(arg0 + 0x2c8 + 0xc00), 0x14);
        if ((var20 | var21) ? 1 : 0) {
            GameState *var22 = GameState::GetInstance();
            int var23        = *(signed char *) (arg0 + 0x1c00 + 0x20);
            if (var23 == 4) var23 = func_020100b0(var22);
            GameObject *var24 = func_0200ff94(var22, var23);
            if (var24 == NULL) return;
            *(unsigned char *) (arg0 + 0xf80) = *(int *) (arg0 + 0x1000 + 0xbb8);
            *(unsigned int *) (arg0 + 0x2000 + 0x47c) &= ~4;
            if (**(int **) ((char *) var24 + 0x130) & 1) {
                *(short *) (arg0 + 0x1c00 + 0x28) = -1;
                *(short *) (arg0 + 0x1c00 + 0x2a) = -1;
                *(int *) (arg0 + 0x1000 + 0xbb8)  = 0x11;
                return;
            }
            *(int *) (base + 0x1000 + 0xbc0) = 0;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            int save    = (int) func_0205ec34();
            char *world = func_02012fe4();
            int kind    = 0;
            if (!TestBitInByteArray_0206dfb0(save, (unsigned char *) ((char *) save + 0x8c), 0x113a)) {
                char *p = *(char **) (world + 8);
                if (p != NULL) kind = (unsigned int) (*(unsigned char *) (p + 0xe) << 30) >> 30;
            }
            *(short *) (arg0 + 0x1c00 + 0x28) = 0x232d;
            if (var27 == 2) {
                char *var29 = func_020a83b0(*(struct Struct_020a83b0 **) (arg0 + 0x2000 + 0x474),
                                                    *(short *) (arg0 + 0x1b00 + 0xfc));
                if (var29 != NULL) {
                    int *var30                          = func_0202ae18();
                    *(short *) (arg0 + 0x1c00 + 0x2a) = -1;
                    *(int *) (arg0 + 0x1000 + 0xbb8)  = 0x26;
                    *(int *) (arg0 + 0x1000 + 0xbbc)  = 0x2b;
                    if (*(short *) (arg0 + 0x1c00 + 0x22) == 0x5603) {
                        *(short *) (arg0 + 0x1c00 + 0x28)          = 0x7972;
                        *(short *) (arg0 + 0x1c00 + 0x2a)          = -1;
                        *(short *) (arg0 + 0x2400 + 0x88)          = -1;
                        *(unsigned char *) (arg0 + 0x2000 + 0x48a) = 0;
                        if (*(unsigned int *) (arg0 + 0x2000 + 0x47c) & 1) func_ov023_021dca88(arg0 + 0x50);
                        func_ov002_0215a7b4(arg0, *(signed char *) (arg0 + 0x1c00 + 0x20), *(short *) (arg0 + 0x1c00 + 0x22),
                                            *(short *) (arg0 + 0x1b00 + 0xe8), 0);
                    } else {
                        SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                        char *t = SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), 0xca);
                        ConsumeCounter02048350(
                            (struct Obj02048350 *) GetCombatantChecked_0200ff94(gs, *(signed char *) (base + 0x1c00 + 0x20)),
                            ((struct TE5b44 *) t)->lo8);
                        if (CheckField0NonZero_0202b7d8(rec)) func_ov017_021c9e00(*(signed char *) (base + 0x1c00 + 0x20), 0, 0, 1);
                    }
                    unsigned char *var32 = (unsigned char *) func_0200fd0c(var22);
                    VectorizedMemset(var32, 0, 0x70);
                    var32[4]                       = 1;
                    var32[8]                       = 1;
                    var32[9]                       = 1;
                    *(signed char *) (var32 + 0xb) = -1;
                    *(int *) (var32 + 0x20)        = -1;
                    *(int *) (var32 + 0x24)        = -1;
                    *(int *) (var32 + 0x28)        = -1;
                    *(int *) (var32 + 0x2c)        = -1;
                    *(short *) (var32 + 0x1e)      = -1;
                    var32[0xc]                     = 0;
                    *(short *) (var32 + 0x6c)      = -1;
                    var32[2]                       = 0;
                    var32[4]                       = 0;
                    var32[5]                       = 1;
                    *(unsigned short *) var32      = *(unsigned short *) (var29 + 8);
                    *(Vector3i *) (var32 + 0x10)   = *(Vector3i *) (var29 + 0xc);
                    *(short *) (var32 + 0x1c)      = *(short *) (var29 + 0xa);
                    var32[7]                       = 1;
                    var32[0x63]                    = 0;
                    func_0200fcfc(var22, var32);
                    if (func_0202c508(var30) && func_0206dfb0(var25, (unsigned char *) ((char *) var25 + 0x8c), 0x2b)) {
                        *(unsigned short *) (var26 + 0x2700 + 0x86) = *(unsigned short *) (var29 + 0x1a);
                        *(unsigned short *) (var26 + 0x2700 + 0x84) = *(unsigned short *) (var29 + 0x1c);
                        Vector3i *var33                               = (Vector3i *) (var26 + 0x374 + 0x2400);
                        Vector3i var34                                  = *var33;
                        var34.x                                         = *(int *) (var29 + 0x20);
                        var34.z                                         = *(int *) (var29 + 0x24);
                        *var33                                        = var34;
                        func_ov017_021d1a18(*(short *) (var29 + 0x1a), *(short *) (var29 + 0x1c), 0, 0);
                    }
                    char *var35 = (char *) GetGameResources();
                    func_ov017_021acd30(var35, 0, 0, 0);
                    struct Struct_0201bdac_2 *var36;
                    unsigned char *var37 = *(unsigned char **) (var35 + 0x3000 + 0x70c);
                    var36                  = *(struct Struct_0201bdac_2 **) (var35 + 0x3000 + 0x6fc);
                    func_ov017_0219e310(var37, 0);
                    func_020469b4(var36, (struct Struct_0201bdac *) var37);
                    return;
                }
                var27 = 0;
            } else if (var27 == 1) {
                *(short *) (arg0 + 0x1c00 + 0x2a) = -1;
                *(int *) (arg0 + 0x1000 + 0xbb8)  = 0x26;
                *(int *) (arg0 + 0x1000 + 0xbbc)  = 0x2b;
                if (*(short *) (arg0 + 0x1c00 + 0x22) == 0x5603) {
                    *(short *) (arg0 + 0x1c00 + 0x28)          = 0x7972;
                    *(short *) (arg0 + 0x1c00 + 0x2a)          = -1;
                    *(short *) (arg0 + 0x2400 + 0x88)          = -1;
                    *(unsigned char *) (arg0 + 0x2000 + 0x48a) = 0;
                    if (*(unsigned int *) (arg0 + 0x2000 + 0x47c) & 1) func_ov023_021dca88(arg0 + 0x50);
                } else {
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                }
                func_ov017_021acd30((char *) GetGameResources(), 0, 0, 1);
                return;
            }
            if (var27 == 0) {
                if (*(short *) (arg0 + 0x1c00 + 0x22) == 0x5603) {
                    *(short *) (arg0 + 0x1b00 + 0xfc)          = -1;
                    *(short *) (arg0 + 0x1c00 + 0x28)          = 0x7936;
                    *(short *) (arg0 + 0x1c00 + 0x2a)          = -1;
                    *(short *) (arg0 + 0x2400 + 0x88)          = 0x7919;
                    *(unsigned char *) (arg0 + 0x2000 + 0x48a) = 1;
                    *(int *) (arg0 + 0x1000 + 0xbb8)           = 0x26;
                    *(int *) (arg0 + 0x1000 + 0xbbc)           = 5;
                } else {
                    *(short *) (base + 0x2400 + 0x88)          = 0x2338;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                    *(int *) (base + 0x1000 + 0xbb8) = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc) = 0x11;
                }
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1b00 + 0xfc) = -1;
            if (*(short *) (arg0 + 0x1c00 + 0x22) == 0x5603) {
                *(short *) (arg0 + 0x1c00 + 0x22) = -1;
                func_ov002_02156ff0((unsigned char *) arg0, 5);
            } else {
                *(short *) (arg0 + 0x1c00 + 0x26) = -1;
                func_ov002_02156ff0((unsigned char *) arg0, 0x13);
                *(int *) (arg0 + 0x1000 + 0xbb8) = 0x11;
                func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0x2c8 + 0xc00), 0x11);
                func_0205deb4((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 0x11, 0);
                func_ov002_02161cf0(arg0);
                func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1000 + 0xbb8) & 0xff, 0);
                *(int *) (arg0 + 0x1000 + 0xbc0) = 1;
            }
        }
    }
#endif
}
