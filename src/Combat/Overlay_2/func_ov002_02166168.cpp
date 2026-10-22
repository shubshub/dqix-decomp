#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct SePlayer;
struct Obj020d7aa0;

extern "C" void func_02012fe4(void);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215f3a0(void *base);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int key, int value);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
int IsElementFlagBit40Set_0216197c(int key, struct Struct_0205d81c *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);
void SePlayer_Play(struct SePlayer *obj, int a, int b);
void InitNodeAndInsertAt_021c1798_021c1798(GameResources *res, unsigned char v);
void SetPendingFlagAndSync_0215a878(char *self);
int GetField0x3acValue_020100a8(GameState *gs);
extern "C" void func_ov017_021bff8c(int a, int b);
int CheckFlagOrThreshold_02161b48(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" char g_sePlayer;

#define OBJ (arg0 + 0x2c8 + 0xc00)

// USA: func_ov002_02166168
#if defined(jpn)
#undef OBJ
#define OBJ (self + 0xe20)
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    func_02012fe4();
    int var2 = *(int *) (arg0 + 0x1a88);
    if (var2 == 0) {
        *(short *) (arg0 + 0x1ac6) = 0;
        func_0205de24((struct Struct_0205de24_2 *) OBJ, 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f3a0(arg0);
        *(int *) (arg0 + 0x1a88) += 1;
    } else if (var2 == 1) {
        *(unsigned int *) (arg0 + 0x22ac) |= 4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x2c);
        func_0205deb4((struct Struct_0205d81c *) OBJ, 0x16, 0);
        short var3                  = *(short *) (arg0 + 0x1ac6);
        *(short *) (arg0 + 0x1ac6) = func_0205d794((struct Struct_0205c570 *) OBJ);
        char *var4                    = func_0205d81c((struct Struct_0205d81c *) OBJ, 0x17);
        if (var4 != 0) {
            *(short *) (var4 + 0xc2) = 0;
        }
        func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1a80) & 0xff, 0);
        if (var3 != *(short *) (arg0 + 0x1ac6)) {
            func_ov002_0215b9a4(arg0, 0x17, 0);
        }
        int var5  = g_keyManager.TestKeysPressed(0x601);
        int var6  = func_0205da38((struct Struct_0205da38*)OBJ, 0x14);
        int var7 = (var5 | var6) ? 1 : 0;
        if (var7) {
            unsigned int var8 = *(unsigned int *) (arg0 + 0x22ac);
            if (var8 & 2) {
                return;
            }
            func_020d7aa0(func_020d7a50());
            short var9 = 0;
            short var10[9];
            func_ov002_02156080(arg0, var10, &var9);
            func_ov002_02161920(arg0);
            switch (var10[*(short *) (arg0 + 0x1ac6)]) {
                case 0:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(unsigned char *) (self + 0xed8) = *(int *) (self + 0x1a80);
                    *(unsigned int *) (self + 0x22ac) &= ~4;
                    *(int *) (self + 0x1a80) = 0x18;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 1:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1a80) = 0x19;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 2:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(unsigned char *) (self + 0xed8) = *(int *) (self + 0x1a80);
                    *(unsigned int *) (self + 0x22ac) &= ~4;
                    *(int *) (self + 0x1a80) = 0x20;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 3:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1a80) = 0x24;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 4:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    InitNodeAndInsertAt_021c1798_021c1798(res, 1);
                    SetPendingFlagAndSync_0215a878(self);
                    *(int *) (self + 0x1a80) = 0x2e;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 5:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1a80) = 0x26;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 7:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1a80) = 0x27;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                case 8: {
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    int id = (signed char) GetField0x3acValue_020100a8(gs);
                    for (int i = 0; i < *(int *) (self + 0x1b14); i++) {
                        char *c = (char *) GetCombatantWithFlag0x100_0200ff1c(gs, *(int *) (self + i * 4 + 0x1b18));
                        if (c != 0 && !(**(int **) (c + 0x130) & 1)) {
                            id = (signed char) ((int *) (self + 0x1b18))[i];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) var1, var11);
                    *(int *) (arg0 + 0x1a80) = 0x2e;
                    *(int *) (arg0 + 0x1a88) = 0;
                    break;
                }
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1ac6) = -1;
            func_ov002_02156e90(arg0);
        }
    }
}
#else
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    func_02012fe4();
    int var16 = *(int *) (arg0 + 0x1bc0);
    if (var16 == 0) {
        *(short *) (arg0 + 0x1bfe) = 0;
        func_0205de24((struct Struct_0205de24_2 *) OBJ, 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f3a0(arg0);
        *(int *) (arg0 + 0x1bc0) += 1;
    } else if (var16 == 1) {
        *(unsigned int *) (arg0 + 0x247c) |= 4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x29);
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 1);
        func_0205deb4((struct Struct_0205d81c *) OBJ, 0x15, 0);
        short var17                  = *(short *) (arg0 + 0x1bfe);
        *(short *) (arg0 + 0x1bfe) = func_0205d794((struct Struct_0205c570 *) OBJ);
        char *var18                    = func_0205d81c((struct Struct_0205d81c *) OBJ, 0x16);
        if (var18 != 0) {
            *(short *) (var18 + 0xc2) = 0;
        }
        if (func_ov002_0216197c(*(int *) (arg0 + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1bb8) & 0xff, 0);
        }
        if (var17 != *(short *) (arg0 + 0x1bfe)) {
            func_ov002_0215b9a4(arg0, 0x16, 0);
        }
        int var19  = g_keyManager.TestKeysPressed(0x601);
        int var20  = func_0205da38((struct Struct_0205da38*)OBJ, 0x14);
        int var21 = (var19 | var20) ? 1 : 0;
        if (var21) {
            unsigned int var22 = *(unsigned int *) (arg0 + 0x247c);
            if (var22 & 2) {
                return;
            }
            if (!(var22 & 0x20)) {
                return;
            }
            func_020d7aa0(func_020d7a50());
            short var23 = 0;
            short var24[9];
            func_ov002_02156080(arg0, var24, &var23);
            func_ov002_02161920(arg0);
            switch (var24[*(short *) (arg0 + 0x1bfe)]) {
                case 0:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(unsigned int *) (self + 0x247c) &= ~4;
                    *(int *) (self + 0x1bb8) = 0x17;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 1:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x18;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 2:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(unsigned int *) (self + 0x247c) &= ~4;
                    *(int *) (self + 0x1bb8) = 0x1f;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 3:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x21;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 4:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    InitNodeAndInsertAt_021c1798_021c1798(res, 1);
                    SetPendingFlagAndSync_0215a878(self);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 5:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x23;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 7:
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x24;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 8: {
                    SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
                    int id = (signed char) GetField0x3acValue_020100a8(gs);
                    for (int i = 0; i < *(int *) (self + 0x1c50); i++) {
                        char *c = (char *) GetCombatantWithFlag0x100_0200ff1c(gs, *(int *) (self + i * 4 + 0x1c54));
                        if (c != 0 && !(**(int **) (c + 0x130) & 1)) {
                            id = (signed char) ((int *) (self + 0x1c54))[i];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) var15, var25);
                    *(int *) (arg0 + 0x1bb8) = 0x2b;
                    *(int *) (arg0 + 0x1bc0) = 0;
                    break;
                }
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + 0x1bfe) = -1;
            func_ov002_02156e90(arg0);
        }
    }
}
#endif
