#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
extern "C" void func_0205de24(Struct_0205de24_2*, unsigned char, unsigned char);
extern "C" void func_ov002_02161cf0(char *arg0);
extern "C" void func_ov002_0215dae0(unsigned char *arg0);
struct Struct_0205c570;
extern "C" int func_0205d794(Struct_0205c570*);
extern "C" int func_ov002_021573f8(void *arg0, int arg1);
struct Struct_0205d81c;
extern "C" void func_0205deb4(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215b9a4(char *arg0, unsigned char arg1, int arg2);
struct Struct_0205def8;
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
void * FindElementByC40205d81c(Struct_0205d81c*, int);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
extern "C" void func_ov002_02156e90(char *base);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);

extern int g_sePlayer;

// USA: func_ov002_021644a8
#if defined(jpn)
extern "C" ARM void func_ov002_021644a8(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    if (var0 == 0) {
        *(short *) (arg0 + 0x1ab8) = 0;
        func_0205de24((Struct_0205de24_2*)(arg0 + 0xe20), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215dae0((unsigned char *) arg0);
        (*(int *) (arg0 + 0x1a88))++;
    } else if (var0 == 1) {
        *(int *) (arg0 + 0x22ac) |= 4;
        short var1 = *(short *) (arg0 + 0x1ab8);
        *(short *) (arg0 + 0x1ab8) = func_0205d794((Struct_0205c570*)(arg0 + 0xe20));
        *(char *) (arg0 + 0x1ae8) = func_ov002_021573f8(arg0, *(short *) (arg0 + 0x1ab8));
        signed char var2 = *(signed char *) (arg0 + 0x1ae8);
        *(char *) (arg0 + 0x1ae9) = var2;
        func_0205deb4((Struct_0205d81c*)(arg0 + 0xe20), 0xe, 1);
        if (*(short *) (arg0 + 0x1ab8) != 0) {
            func_ov002_0215b9a4(arg0, 0xe, 0);
            func_0205def8((Struct_0205def8*)(arg0 + 0xe20), 1, 0xe);
            unsigned char *var3 = (unsigned char *) func_0205d81c((Struct_0205d81c*)(arg0 + 0xe20), 0xc);
            unsigned char *var4 = (unsigned char *) func_0205d81c((Struct_0205d81c*)(arg0 + 0xe20), 0xe);
            if (var3 != 0 && var4 != 0) {
                short var5 = *(short *) (var3 + 0xac);
                short var6 = *(short *) (var3 + 0xa8);
                *(short *) (var4 + 0xac) = var5 + var6;
                *(short *) (var4 + 0xae) = 1;
            }
        } else {
            func_0205def8((Struct_0205def8*)(arg0 + 0xe20), 0, 0xe);
        }
        if (var1 != *(short *) (arg0 + 0x1ab8)) {
            return;
        }
        int t = g_keyManager.TestKeysPressed(0x601);
        int u = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xe20), 0x14);
        int hit = (t | u) != 0;
        if (hit != 0) {
            *(char *) (self + 0x1afa) = 0;
            *(char *) (self + 0xed8) = *(int *) (self + 0x1a80);
            *(int *) (self + 0x22ac) &= ~4;
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + 0xe20), 0xc, 1);
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
            *(short *) (self + 0x1ada) = 0;
            *(short *) (self + 0x1af0) = 0x238d;
            *(short *) (self + 0x1af2) = -1;
            *(int *) (self + 0x1a80) = 0x29;
            *(int *) (self + 0x1a84) = 0xc;
            *(int *) (self + 0x1a88) = 0;
            *(char *) (self + 0x1af6) = 1;
        } else {
            if (func_ov002_02161b48(arg0, 1) == 0) {
                return;
            }
            func_ov002_02156e90(arg0);
            *(short *) (arg0 + 0x1ab8) = -1;
            *(char *) (arg0 + 0x1ae8) = -1;
            *(char *) (arg0 + 0x1ae9) = -1;
            func_0205dee8((Struct_0205dee8*)(arg0 + 0xe20), (*(int *) (arg0 + 0x1a80) = 4));
            func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1a80), 0);
            func_ov002_02161cf0(arg0);
        }
    }
}
#else
extern "C" ARM void func_ov002_021644a8(char *arg0) {
    int var10 = *(int *) (arg0 + 0x1bc0);
    if (var10 == 0) {
        *(short *) (arg0 + 0x1bf0) = 0;
        func_0205de24((Struct_0205de24_2*)(arg0 + 0xec8), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215dae0((unsigned char *) arg0);
        (*(int *) (arg0 + 0x1bc0))++;
    } else if (var10 == 1) {
        *(int *) (arg0 + 0x247c) |= 4;
        short var11 = *(short *) (arg0 + 0x1bf0);
        *(short *) (arg0 + 0x1bf0) = func_0205d794((Struct_0205c570*)(arg0 + 0xec8));
        *(char *) (arg0 + 0x1c20) = func_ov002_021573f8(arg0, *(short *) (arg0 + 0x1bf0));
        signed char var12 = *(signed char *) (arg0 + 0x1c20);
        *(char *) (arg0 + 0x1c21) = var12;
        func_0205deb4((Struct_0205d81c*)(arg0 + 0xec8), 0xd, 1);
        if (*(short *) (arg0 + 0x1bf0) != 0) {
            func_ov002_0215b9a4(arg0, 0xd, 0);
            func_0205def8((Struct_0205def8*)(arg0 + 0xec8), 1, 0xd);
            unsigned char *var13 = (unsigned char *) func_0205d81c((Struct_0205d81c*)(arg0 + 0xec8), 0xb);
            unsigned char *var14 = (unsigned char *) func_0205d81c((Struct_0205d81c*)(arg0 + 0xec8), 0xd);
            if (var13 != 0 && var14 != 0) {
                short var15 = *(short *) (var13 + 0xac);
                short var16 = *(short *) (var13 + 0xa8);
                *(short *) (var14 + 0xac) = var15 + var16;
                *(short *) (var14 + 0xae) = 1;
            }
        } else {
            func_0205def8((Struct_0205def8*)(arg0 + 0xec8), 0, 0xd);
        }
        if (var11 != *(short *) (arg0 + 0x1bf0)) {
            return;
        }
        int t = g_keyManager.TestKeysPressed(0x601);
        int u = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xec8), 0x14);
        int hit = (t | u) != 0;
        if (hit != 0) {
            *(char *) (self + 0x1c32) = 0;
            *(char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(int *) (self + 0x247c) &= ~4;
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + 0xec8), 0xb, 1);
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
            *(short *) (self + 0x1c12) = 0;
            *(short *) (self + 0x1c28) = 0x238d;
            *(short *) (self + 0x1c2a) = -1;
            *(int *) (self + 0x1bb8) = 0x26;
            *(int *) (self + 0x1bbc) = 0xb;
            *(int *) (self + 0x1bc0) = 0;
            *(char *) (self + 0x1c2e) = 1;
        } else {
            if (func_ov002_02161b48(arg0, 1) == 0) {
                return;
            }
            func_ov002_02156e90(arg0);
            *(short *) (arg0 + 0x1bf0) = -1;
            *(char *) (arg0 + 0x1c20) = -1;
            *(char *) (arg0 + 0x1c21) = -1;
            func_0205dee8((Struct_0205dee8*)(arg0 + 0x2c8 + 0xc00), (*(int *) (arg0 + 0x1bb8) = 4));
            func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1bb8), 0);
            func_ov002_02161cf0(arg0);
        }
    }
}
#endif
