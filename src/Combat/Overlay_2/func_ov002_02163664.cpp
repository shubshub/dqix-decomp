#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Obj0205dee8;
struct Container020dedd0;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int a, int b);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
int BuildFlaggedCombatantSlotList_02154f4c(unsigned char *obj);
int CountFlag0x800MatchesEqualsTarget020dcc20(int targetCount, int flag);
int CheckAnyByteMatches020dcbbc(unsigned char *arr, int count, int b, int c, int d);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
void ClearMatchingEntry_02156ff0(unsigned char *self, int v);
int CheckAndClearEntryStatus_0215b7d0(char* base);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" void func_ov002_0215b814(char *base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215ce94(char *base);
extern "C" void func_ov002_02156e90(char *base);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" int func_ov002_0215b720(char *self, int id);
extern "C" void func_ov002_02157d40(char *base);
extern "C" void func_ov002_02157634(char *base);
extern "C" char g_sePlayer[];

// USA: func_ov002_02163664
#if defined(jpn)
extern "C" ARM void func_ov002_02163664(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    if (var0 == 0) {
        *(short *) (arg0 + 0x1ab4) = func_ov002_02154f4c((unsigned char *) arg0);
        GameObject *var1 = GameState::GetInstance()->GetProtagonist();
        if (var1 != NULL) {
            short var2 = *(short *) (func_02053c6c((unsigned char *) var1) + 0x800 + 0xc6);
            for (int var3 = 0; var3 < *(unsigned char *) (arg0 + 0x1000 + 0xb31); var3++) {
                if (var2 == *(unsigned char *) (arg0 + var3 + 0x1000 + 0xb2c)) {
                    *(short *) (arg0 + 0x1ab4) = var3;
                    break;
                }
            }
        }
        if (*(short *) (base + 0x1aee) != -1) *(short *) (base + 0x1ab4) = 0;
        func_ov002_0215b814(base);
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0xe20), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_0215ce94(base);
        *(int *) (base + 0x1a88) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x22ac) |= 4;
        short old = *(short *) (base + 0x1ab4);
        *(short *) (base + 0x1ab4) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0xe20));
        if (old != *(short *) (base + 0x1ab4)) *(int *) (base + 0x1a94) = 1;
        int n              = *(unsigned char *) (base + 0x1b31);
        unsigned char *lst = (unsigned char *) (base + 0x32c + 0x1800);
        unsigned char mode = *(unsigned char *) (base + 0x1b48);
        if (mode == 7) {
            n   = *(unsigned char *) (base + 0x1b37);
            lst = (unsigned char *) (base + 0x32 + 0x1b00);
        }
        if (var7 != 7 && !func_020dcc20(var5, 0)) {
            *(short *) (arg0 + 0x1ab4) = -1;
            func_ov002_02156e90(arg0);
            return;
        }
        int var8 = 0;
        if (*(short *) (arg0 + 0x1aee) == 0xd1) var8 = 1;
        if (*(unsigned char *) (arg0 + 0x1b88) != 0 || func_020dcbbc(var6, var5, 1, 1, var8)) {
            *(int *) (arg0 + 0x1a94) = 1;
            func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1a80) & 0xff, 0);
        }
        if (old != *(short *) (base + 0x1ab4)) return;
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0xe20), 0x14);
        if ((a | b) ? 1 : 0) {
            if (!func_020dc920(lst[*(short *) (base + 0x1ab4)], 1, 1, special)) return;
            func_ov002_0215b814(base);
            *(unsigned char *) (base + 0xed8)          = *(int *) (base + 0x1a80);
            *(unsigned char *) (base + 0x1ae9) = lst[*(short *) (base + 0x1ab4)];
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(unsigned int *) (base + 0x22ac) &= ~4;
            func_ov002_0215b9a4(base, 0x11, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0xe20), 0x11, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0xe20), 0x14, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0xe20), 8, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0xe20), 9, 1);
            if (*(short *) (base + 0x1aee) != -1) {
                if (func_ov002_0215b720(base, *(short *) (base + 0x1aee))) {
                    *(int *) (base + 0x1a88) = 2;
                    return;
                }
                func_ov002_02157d40(arg0);
                return;
            }
            char *var11 = func_020dedd0((struct Struct_0201099c_10 *) (arg0 + 0x750),
                                                                        *(short *) (arg0 + 0x1aea));
            if (var11 != NULL && func_ov002_0215b720(arg0, *(short *) (var11 + 0x14))) {
                *(int *) (arg0 + 0x1a88) = 2;
                return;
            }
            GameObject *var12 = GameState::GetInstance()->GetProtagonist();
            if (var12 != NULL) {
                short var13                                                        = *(signed char *) (arg0 + 0x1ae9);
                *(short *) (func_02053c6c((unsigned char *) var12) + 0x800 + 0xc6) = var13;
            }
            func_ov002_02157634(arg0);
        } else if (func_ov002_02161b48(arg0, 1)) {
            if (*(short *) (arg0 + 0x1aee) != -1) {
                *(int *) (arg0 + 0x1a80) = 0x12;
                func_ov002_02156ff0((unsigned char *) arg0, 0x14);
                func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0xe20), 0x12);
                func_0205deb4((struct Struct_0205d81c *) (arg0 + 0xe20), 0x12, 0);
                *(int *) (arg0 + 0x1a88) = 1;
                *(int *) (arg0 + 0x1a80) = 0x12;
                func_ov002_02161cf0(arg0);
            } else {
                func_ov002_02156e90(arg0);
            }
            *(short *) (arg0 + 0x1ab4) = -1;
        }
    } else if (var0 == 2) {
        int var14 = func_ov002_0215b7d0(arg0);
        if (var14 > 0) {
            *(unsigned char *) (arg0 + 0xed8) = *(int *) (arg0 + 0x1a80);
            if (*(short *) (arg0 + 0x1aee) != -1) {
                func_ov002_02157d40(arg0);
                return;
            }
            GameObject *var15 = GameState::GetInstance()->GetProtagonist();
            if (var15 != NULL) {
                short var16                                                        = *(signed char *) (arg0 + 0x1ae9);
                *(short *) (func_02053c6c((unsigned char *) var15) + 0x800 + 0xc6) = var16;
            }
            func_ov002_02157634(arg0);
        } else if (var14 < 0) {
            if (*(short *) (arg0 + 0x1aee) != -1) {
                *(short *) (arg0 + 0x1af0) = 0x232d;
                *(short *) (arg0 + 0x22b8) = 0x232b;
                *(int *) (arg0 + 0x1a84)  = 0x12;
            } else {
                *(short *) (arg0 + 0x1af0) = 0x7918;
                *(short *) (arg0 + 0x22b8) = 0x7919;
                *(int *) (arg0 + 0x1a84)  = 5;
            }
            *(short *) (arg0 + 0x1af2)          = -1;
            *(unsigned char *) (arg0 + 0x22ba) = 1;
            *(int *) (arg0 + 0x1a80)           = 0x29;
            *(int *) (arg0 + 0x1a88)           = 0;
        }
    }
}
#else
extern "C" ARM void func_ov002_02163664(char *arg0) {
    int var17 = *(int *) (arg0 + 0x1000 + 0xbc0);
    if (var17 == 0) {
        *(short *) (arg0 + 0x1b00 + 0xec) = func_ov002_02154f4c((unsigned char *) arg0);
        int var18                             = *(unsigned char *) (arg0 + 0x1000 + 0xc6d);
        unsigned char *var19                = (unsigned char *) (arg0 + 0x68 + 0x1c00);
        if (*(short *) (arg0 + 0x1c00 + 0x26) < 0 && *(unsigned char *) (arg0 + 0x1000 + 0xc84) == 7) {
            var18   = *(unsigned char *) (arg0 + 0x1000 + 0xc73);
            var19 = (unsigned char *) (arg0 + 0x6e + 0x1c00);
        }
        GameObject *var20 = GameState::GetInstance()->GetProtagonist();
        if (var20 != NULL) {
            int var21 = 0;
            short var22   = *(short *) (func_02053c6c((unsigned char *) var20) + 0x900 + 0x5e);
            for (int var23 = 0; var23 < var18; var23++) {
                if (var22 == var19[var23]) {
                    *(short *) (arg0 + 0x1b00 + 0xec) = var23;
                    var21                             = 1;
                    break;
                }
            }
            if (!var21) *(short *) (arg0 + 0x1b00 + 0xec) = 0;
        }
        if (*(short *) (base + 0x1c00 + 0x26) != -1) *(short *) (base + 0x1b00 + 0xec) = 0;
        func_ov002_0215b814(base);
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_0215ce94(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xec);
        *(short *) (base + 0x1b00 + 0xec) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (old != *(short *) (base + 0x1b00 + 0xec)) *(int *) (base + 0x1000 + 0xbcc) = 1;
        int n              = *(unsigned char *) (base + 0x1000 + 0xc6d);
        unsigned char *lst = (unsigned char *) (base + 0x68 + 0x1c00);
        unsigned char mode = *(unsigned char *) (base + 0x1000 + 0xc84);
        if (mode == 7) {
            n   = *(unsigned char *) (base + 0x1000 + 0xc73);
            lst = (unsigned char *) (base + 0x6e + 0x1c00);
        }
        if (var27 != 7 && !func_020dcc20(var25, 0)) {
            *(short *) (arg0 + 0x1b00 + 0xec) = -1;
            func_ov002_02156e90(arg0);
            return;
        }
        int var28 = 0;
        if (*(short *) (arg0 + 0x1c00 + 0x26) == 0xd1) var28 = 1;
        if (*(unsigned char *) (arg0 + 0x1000 + 0xcc4) != 0 || func_020dcbbc(var26, var25, 1, 1, var28)) {
            *(int *) (arg0 + 0x1000 + 0xbcc) = 1;
            func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1000 + 0xbb8) & 0xff, 0);
        }
        if (old != *(short *) (base + 0x1b00 + 0xec)) return;
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
        if ((a | b) ? 1 : 0) {
            if (!func_020dc920(lst[*(short *) (base + 0x1b00 + 0xec)], 1, 1, special)) return;
            func_ov002_0215b814(base);
            *(unsigned char *) (base + 0xf80)          = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned char *) (base + 0x1000 + 0xc21) = lst[*(short *) (base + 0x1b00 + 0xec)];
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_0215b9a4(base, 0x10, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x10, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x13, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 7, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 8, 1);
            if (*(short *) (base + 0x1c00 + 0x26) != -1) {
                if (func_ov002_0215b720(base, *(short *) (base + 0x1c00 + 0x26))) {
                    *(int *) (base + 0x1000 + 0xbc0) = 2;
                    return;
                }
                func_ov002_02157d40(arg0);
                return;
            }
            char *var31 = func_020dedd0((struct Struct_0201099c_10 *) (arg0 + 0x3ec + 0x400),
                                                                        *(short *) (arg0 + 0x1c00 + 0x22));
            if (var31 != NULL && func_ov002_0215b720(arg0, *(short *) (var31 + 0x14))) {
                *(int *) (arg0 + 0x1000 + 0xbc0) = 2;
                return;
            }
            GameObject *var32 = GameState::GetInstance()->GetProtagonist();
            if (var32 != NULL) {
                short var33                                                        = *(signed char *) (arg0 + 0x1c00 + 0x21);
                *(short *) (func_02053c6c((unsigned char *) var32) + 0x900 + 0x5e) = var33;
            }
            func_ov002_02157634(arg0);
        } else if (func_ov002_02161b48(arg0, 1)) {
            if (*(short *) (arg0 + 0x1c00 + 0x26) != -1) {
                *(int *) (arg0 + 0x1000 + 0xbb8) = 0x11;
                func_ov002_02156ff0((unsigned char *) arg0, 0x13);
                func_0205dee8((struct Struct_0205dee8 *) (arg0 + 0x2c8 + 0xc00), 0x11);
                func_0205deb4((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 0x11, 0);
                *(int *) (arg0 + 0x1000 + 0xbc0) = 1;
                *(int *) (arg0 + 0x1000 + 0xbb8) = 0x11;
                func_ov002_02161cf0(arg0);
            } else {
                func_ov002_02156e90(arg0);
            }
            *(short *) (arg0 + 0x1b00 + 0xec) = -1;
        }
    } else if (var17 == 2) {
        int var34 = func_ov002_0215b7d0(arg0);
        if (var34 > 0) {
            *(unsigned char *) (arg0 + 0xf80) = *(int *) (arg0 + 0x1000 + 0xbb8);
            if (*(short *) (arg0 + 0x1c00 + 0x26) != -1) {
                func_ov002_02157d40(arg0);
                return;
            }
            GameObject *var35 = GameState::GetInstance()->GetProtagonist();
            if (var35 != NULL) {
                short var36                                                        = *(signed char *) (arg0 + 0x1c00 + 0x21);
                *(short *) (func_02053c6c((unsigned char *) var35) + 0x900 + 0x5e) = var36;
            }
            func_ov002_02157634(arg0);
        } else if (var34 < 0) {
            if (*(short *) (arg0 + 0x1c00 + 0x26) != -1) {
                *(short *) (arg0 + 0x1c00 + 0x28) = 0x232d;
                *(short *) (arg0 + 0x2400 + 0x88) = 0x232b;
                *(int *) (arg0 + 0x1000 + 0xbbc)  = 0x11;
            } else {
                *(short *) (arg0 + 0x1c00 + 0x28) = 0x7918;
                *(short *) (arg0 + 0x2400 + 0x88) = 0x7919;
                *(int *) (arg0 + 0x1000 + 0xbbc)  = 5;
            }
            *(short *) (arg0 + 0x1c00 + 0x2a)          = -1;
            *(unsigned char *) (arg0 + 0x2000 + 0x48a) = 1;
            *(int *) (arg0 + 0x1000 + 0xbb8)           = 0x26;
            *(int *) (arg0 + 0x1000 + 0xbc0)           = 0;
        }
    }
}
#endif
