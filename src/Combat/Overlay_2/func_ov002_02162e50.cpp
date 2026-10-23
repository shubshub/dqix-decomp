#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Obj0205dee8;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int a, int b);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
void *GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int *p, unsigned int mask);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
extern "C" int GetInventoryItemByID(char *self, int idx, int member);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02161b98(char *self);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov002_0215b458(char *self, int a);
extern "C" int func_0205df38(void *list, int key);
extern "C" void func_ov023_021dc9e8(char *obj, SafeAllocator *alloc, int item, char *list, int n);
extern "C" void func_ov023_021dc134(char *obj, int item, int flag);
extern "C" void func_ov023_021dbfd0(char *obj, SafeAllocator *alloc);
extern "C" void func_ov023_021dcae0(char *obj, int item);
extern "C" void func_ov023_021dca88(char *obj);
extern "C" char g_sePlayer[];

static inline int inline_02000c9c_6(int arg0) {
    return (arg0 >= 0 && arg0 <= 3) ? 1 : 0;
}

// USA: func_ov002_02162e50
#if defined(jpn)
extern "C" void func_ov002_0215c618(char *arg0, int arg1);
#define func_ov002_0215b458 func_ov002_0215c618
extern "C" ARM void func_ov002_02162e50(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    char *var1 = arg0 + 0x38;
    if (var0 == 0) {
        *(short *) (arg0 + 0x1ac2) = -1;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xe20), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215b9a4(arg0, 5, 0);
        *(int *) (arg0 + 0x1a88) += 1;
        func_0205deb4((struct Struct_0205d81c *) (arg0 + 0xe20), 4, 1);
        func_0205deb4((struct Struct_0205d81c *) (arg0 + 0xe20), 5, 0);
        func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0xe20), 5);
        int var2 = GetInventoryItemByID(arg0, *(short *) (arg0 + 0x1ab0), *(signed char *) (arg0 + 0x1ae8));
        func_020466e4((unsigned int *) func_020d6c00(), 1);
        if (*(unsigned int *) (arg0 + 0x22ac) & 1) {
            ((SafeAllocator *) (arg0 + 0x7c8))->Reset();
            func_ov023_021dc9e8(var1, (SafeAllocator *) (arg0 + 0x7c8), var2, arg0 + 0x750, 0x50);
        } else {
            ((SafeAllocator *) (arg0 + 0x7c8))->Reset();
            func_ov023_021dc134(var1, var2, 0);
            struct Struct_ov002_02162e50 {
                char unknown_0_[0x6f0];
                unsigned short unknown_6f0_;
            };
            ((Struct_ov002_02162e50 *) (var1))->unknown_6f0_ |= 0x50;
            func_ov023_021dbfd0(var1, (SafeAllocator *) (arg0 + 0x7c8));
            *(char **) (var1 + 0x48) = arg0 + 0x750;
            *(unsigned int *) (arg0 + 0x22ac) |= 1;
        }
    } else if (state == 1) {
        *(unsigned int *) (base + 0x22ac) |= 4;
        func_ov002_02161b98(base);
        int prev = *(short *) (base + 0x1ab0);
        *(short *) (base + 0x1ab0) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0xe20));
        if (g_keyManager.TestKeysPressed(4) || func_0205df38(base + 0xe20, 0x2b)) {
            if (*(short *) (base + 0x1aae) == *(signed char *) (base + 0x1b37)) {
                func_ov002_0215b458(base, 1);
                *(short *) (base + 0x1aea) =
                    GetInventoryItemByID(base, *(short *) (base + 0x1ab0), *(signed char *) (base + 0x1ae8));
                func_ov023_021dcae0(sub, *(short *) (base + 0x1aea));
                return;
            }
        }
        *(short *) (base + 0x1aea) =
            GetInventoryItemByID(base, *(short *) (base + 0x1ab0), *(signed char *) (base + 0x1ae8));
        func_ov023_021dcae0(sub, *(short *) (base + 0x1aea));
        if (prev != *(short *) (base + 0x1ab0)) return;
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0xe20), 0x14);
        if ((a | b) ? 1 : 0) {
            *(unsigned char *) (base + 0xed8) = *(int *) (base + 0x1a80);
            *(unsigned int *) (base + 0x22ac) &= ~4;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            if (*(unsigned char *) (base + 0x22b5))
                *(int *) (base + 0x1a80) = 0x2a;
            else
                *(int *) (arg0 + 0x1a80) = 7;
            int var6                           = 0;
            *(int *) (arg0 + 0x1a88) = var6;
            int var7                        = *(signed char *) (arg0 + 0x1ae8);
            if (var7 >= 0 && var7 <= 3) var6 = 1;
            if (var6) return;
            GameObject *var8 = GameState::GetInstance()->GetProtagonist();
            if (var8 == NULL) return;
            *(short *) (func_02053c6c((unsigned char *) var8) + 0x800 + 0xc0) = *(short *) (arg0 + 0x1aea);
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1aea) = -1;
            *(short *) (arg0 + 0x1ab0) = -1;
            *(int *) (arg0 + 0x1a80)  = 4;
            *(int *) (arg0 + 0x1a88)  = 1;
            func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0xe20), 4);
            func_0205deb4((struct Struct_0205d81c *) (arg0 + 0xe20), 4, 0);
            func_ov002_02161cf0(arg0);
            func_ov023_021dca88(var1);
        }
    }
}
#else
extern "C" ARM void func_ov002_02162e50(char *arg0) {
    int var9 = *(int *) (arg0 + 0x1000 + 0xbc0);
    if (var9 == 0) {
        *(short *) (arg0 + 0x1b00 + 0xfa) = -1;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215b9a4(arg0, 5, 0);
        *(int *) (arg0 + 0x1000 + 0xbc0) += 1;
        func_0205deb4((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 4, 1);
        func_0205deb4((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 5, 0);
        func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0x2c8 + 0xc00), 5);
        int var10 = GetInventoryItemByID(arg0, *(short *) (arg0 + 0x1b00 + 0xe8), *(signed char *) (arg0 + 0x1c00 + 0x20));
        func_020466e4((unsigned int *) func_020d6c00(), 1);
        if (*(unsigned int *) (arg0 + 0x2000 + 0x47c) & 1) {
            ((SafeAllocator *) (arg0 + 0x64 + 0x800))->Reset();
            func_ov023_021dc9e8(arg0 + 0x50, (SafeAllocator *) (arg0 + 0x64 + 0x800), var10, arg0 + 0x3ec + 0x400, 0x50);
        } else {
            ((SafeAllocator *) (arg0 + 0x64 + 0x800))->Reset();
            func_ov023_021dc134(arg0 + 0x50, var10, 0);
            struct Struct_ov002_02162e50 {
                char unknown_0_[0x774];
                unsigned short unknown_774_;
            };
            ((Struct_ov002_02162e50 *) (arg0 + 0x50))->unknown_774_ |= 0x50;
            func_ov023_021dbfd0(arg0 + 0x50, (SafeAllocator *) (arg0 + 0x64 + 0x800));
            *(char **) (arg0 + 0x98) = arg0 + 0x3ec + 0x400;
            *(unsigned int *) (arg0 + 0x2000 + 0x47c) |= 1;
        }
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        func_ov002_02161b98(base);
        int prev = *(short *) (base + 0x1b00 + 0xe8);
        *(short *) (base + 0x1b00 + 0xe8) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (g_keyManager.TestKeysPressed(4) || func_0205df38(base + 0x2c8 + 0xc00, 0x28)) {
            if (*(short *) (base + 0x1b00 + 0xe6) == *(signed char *) (base + 0x1c00 + 0x73)) {
                func_ov002_0215b458(base, 1);
                *(short *) (base + 0x1c00 + 0x22) =
                    GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
                func_ov023_021dcae0(base + 0x50, *(short *) (base + 0x1c00 + 0x22));
                return;
            }
        }
        *(short *) (base + 0x1c00 + 0x22) =
            GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
        func_ov023_021dcae0(base + 0x50, *(short *) (base + 0x1c00 + 0x22));
        if (prev != *(short *) (base + 0x1b00 + 0xe8)) return;
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
        if ((a | b) ? 1 : 0) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            if (*(unsigned char *) (base + 0x2000 + 0x485))
                *(int *) (base + 0x1000 + 0xbb8) = 0x27;
            else
                *(int *) (arg0 + 0x1000 + 0xbb8) = 6;
            int var14                           = 0;
            *(int *) (arg0 + 0x1000 + 0xbc0) = var14;
            int var15                        = *(signed char *) (arg0 + 0x1c00 + 0x20);
            if (var15 >= 0 && var15 <= 3) var14 = 1;
            if (var14) return;
            GameObject *var16 = GameState::GetInstance()->GetProtagonist();
            if (var16 == NULL) return;
            *(short *) (func_02053c6c((unsigned char *) var16) + 0x900 + 0x58) = *(short *) (arg0 + 0x1c00 + 0x22);
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1c00 + 0x22) = -1;
            *(short *) (arg0 + 0x1b00 + 0xe8) = -1;
            *(int *) (arg0 + 0x1000 + 0xbb8)  = 4;
            *(int *) (arg0 + 0x1000 + 0xbc0)  = 1;
            func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0x2c8 + 0xc00), 4);
            func_0205deb4((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 4, 0);
            func_ov002_02161cf0(arg0);
            func_ov023_021dca88(arg0 + 0x50);
        }
    }
}
#endif
