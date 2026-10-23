#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
extern "C" void func_0205de24(Struct_0205de24_2*, unsigned char, unsigned char);
extern "C" void func_ov002_02161cf0(char *arg0);
extern "C" void func_ov002_0215dae0(unsigned char *arg0);
struct Struct_0205c570;
int Window_GetSelectedIndex(Struct_0205c570*);
int GetFieldC54ArrayValue021573f8(void *self, int v);
struct Struct_0205d81c;
extern "C" void func_0205deb4(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215b9a4(char *arg0, unsigned char arg1, int arg2);
struct Struct_0205def8;
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
void * FindElementByC40205d81c(Struct_0205d81c*, int);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
extern "C" void func_ov002_02156e90(char *base);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);

extern int g_sePlayer;

// USA: func_ov002_021644a8
#if defined(jpn)
extern "C" ARM void func_ov002_021644a8(char *self) {
    int phase = *(int *) (self + 0x1a88);
    if (phase == 0) {
        *(short *) (self + 0x1ab8) = 0;
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)(self + 0xe20), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215dae0((unsigned char *) self);
        (*(int *) (self + 0x1a88))++;
    } else if (phase == 1) {
        *(int *) (self + 0x22ac) |= 4;
        short saved = *(short *) (self + 0x1ab8);
        *(short *) (self + 0x1ab8) = Window_GetSelectedIndex((Struct_0205c570*)(self + 0xe20));
        *(char *) (self + 0x1ae8) = GetFieldC54ArrayValue021573f8(self, *(short *) (self + 0x1ab8));
        signed char cur = *(signed char *) (self + 0x1ae8);
        *(char *) (self + 0x1ae9) = cur;
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + 0xe20), 0xe, 1);
        if (*(short *) (self + 0x1ab8) != 0) {
            func_ov002_0215b9a4(self, 0xe, 0);
            SetElementFlag0x20ByKey0205def8((Struct_0205def8*)(self + 0xe20), 1, 0xe);
            unsigned char *ea = (unsigned char *) FindElementByC40205d81c((Struct_0205d81c*)(self + 0xe20), 0xc);
            unsigned char *eb = (unsigned char *) FindElementByC40205d81c((Struct_0205d81c*)(self + 0xe20), 0xe);
            if (ea != 0 && eb != 0) {
                short ac = *(short *) (ea + 0xac);
                short a8 = *(short *) (ea + 0xa8);
                *(short *) (eb + 0xac) = ac + a8;
                *(short *) (eb + 0xae) = 1;
            }
        } else {
            func_0205def8((Struct_0205def8*)(arg0 + 0xe20), 0, 0xe);
        }
        if (var1 != *(short *) (arg0 + 0x1ab8)) {
            return;
        }
        int t = g_keyManager.TestKeysPressed(0x601);
        int u = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0xe20), 0x14);
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
extern "C" ARM void func_ov002_021644a8(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        *(short *) (self + 0x1bf0) = 0;
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)(self + 0xec8), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215dae0((unsigned char *) self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        short saved = *(short *) (self + 0x1bf0);
        *(short *) (self + 0x1bf0) = Window_GetSelectedIndex((Struct_0205c570*)(self + 0xec8));
        *(char *) (self + 0x1c20) = GetFieldC54ArrayValue021573f8(self, *(short *) (self + 0x1bf0));
        signed char cur = *(signed char *) (self + 0x1c20);
        *(char *) (self + 0x1c21) = cur;
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + 0xec8), 0xd, 1);
        if (*(short *) (self + 0x1bf0) != 0) {
            func_ov002_0215b9a4(self, 0xd, 0);
            SetElementFlag0x20ByKey0205def8((Struct_0205def8*)(self + 0xec8), 1, 0xd);
            unsigned char *ea = (unsigned char *) FindElementByC40205d81c((Struct_0205d81c*)(self + 0xec8), 0xb);
            unsigned char *eb = (unsigned char *) FindElementByC40205d81c((Struct_0205d81c*)(self + 0xec8), 0xd);
            if (ea != 0 && eb != 0) {
                short ac = *(short *) (ea + 0xac);
                short a8 = *(short *) (ea + 0xa8);
                *(short *) (eb + 0xac) = ac + a8;
                *(short *) (eb + 0xae) = 1;
            }
        } else {
            func_0205def8((Struct_0205def8*)(arg0 + 0xec8), 0, 0xd);
        }
        if (var11 != *(short *) (arg0 + 0x1bf0)) {
            return;
        }
        int t = g_keyManager.TestKeysPressed(0x601);
        int u = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0xec8), 0x14);
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
