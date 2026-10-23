#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct SePlayer;
struct Obj020d7aa0;
struct S_a0af4;

extern "C" void func_ov002_0215b2c8(char *self);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c614(char *self);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int key, int value);
extern "C" int func_0205df38(void *obj, int key);
extern "C" void func_ov002_0215b458(char *self, int v);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
int GetField0x3acValue_020100a8(GameState *gs);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
void SePlayer_Play(struct SePlayer *obj, int a, int b);
int GetFieldC54ArrayValue021573f8(void *self, int v);
int GetCountByType02157108(void *self, int type);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *obj);
void *GetPtrField0x2a04_02010828(GameState *gameState);
int FindKeyIndex020a0af4(struct S_a0af4 *s, int key);
int CheckFlagOrThreshold_02161b48(char *self, int v);
void ResetAllocatorsAndClearFields0215b428(unsigned char *obj);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" char g_sePlayer;

#if defined(jpn)
#define RG(u, j) (j)
extern "C" void func_ov002_0215c618(char *arg0, int arg1);
#define func_ov002_0215b458 func_ov002_0215c618
#else
#define RG(u, j) (u)
#endif

#define OBJ (arg0 + RG(0x2c8 + 0xc00, 0xe20))
#define CUR (*(short *) (arg0 + RG(0x1be6, 0x1aae)))
#define SEL (*(signed char *) (arg0 + RG(0x1c20, 0x1ae8)))
#define LAST (*(signed char *) (arg0 + RG(0x1c73, 0x1b37)))

// USA: func_ov002_02162964
extern "C" ARM void func_ov002_02162964(char *arg0) {
    int var0 = *(int *) (arg0 + RG(0x1bc0, 0x1a88));
    if (var0 == 0) {
        unsigned int var1 = *(unsigned int *) (arg0 + RG(0x247c, 0x22ac));
        if (var1 & 2) {
            return;
        }
#if !defined(jpn)
        if (!(var1 & 0x20)) {
            return;
        }
#endif
        *(unsigned char *) (arg0 + RG(0x248d, 0x22bd)) = 0;
#if !defined(jpn)
        func_ov002_0215b2c8(arg0);
#endif
        CUR = 0;
        SEL = *(int *) (self + CUR * 4 + RG(0x1c3c, 0x1b00));
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215c614(self);
        *(int *) (self + RG(0x1bc0, 0x1a88)) += 1;
    } else if (state == 1) {
        *(short *) (self + RG(0x1bf0, 0x1ab8)) = -1;
        *(unsigned int *) (self + RG(0x247c, 0x22ac)) |= 4;
        short old = CUR;
        CUR       = Window_GetSelectedIndex((struct Struct_0205c570 *) OBJ);
        func_ov002_0215b9a4(self, *(int *) (self + RG(0x1bb8, 0x1a80)) & 0xff, 0);
        signed char prev = SEL;
        SEL              = *(signed char *) (self + CUR + RG(0x1c6e, 0x1b32));
        if (CUR == LAST) {
            SEL = 4;
        }
        if (CUR == LAST + 1) {
            SEL = -1;
        }
        if (var3 != SEL) {
            func_ov002_0215b9a4(arg0, 5, 0);
            func_0205def8((struct Struct_0205def8 *) OBJ, SEL >= 0 ? 1 : 0, 5);
        }
        func_0205deb4((struct Struct_0205d81c *) OBJ, 5, 1);
        if (g_keyManager.TestKeysHeld(0x40)) {
            return;
        }
        if (g_keyManager.TestKeysHeld(0x80)) {
            return;
        }
        if ((g_keyManager.TestKeysPressed(4) || func_0205df38(OBJ, RG(0x28, 0x2b))) && CUR == LAST) {
            func_ov002_0215b458(arg0, 0);
            return;
        }
        int var4 = 0;
        if (func_0205df38(OBJ, 5) && CUR != LAST + 1) {
            var4 = 1;
        }
        if (var2 != CUR) {
            return;
        }
        int t  = g_keyManager.TestKeysPressed(0x601);
        int u  = Window_IsSelectionTouched((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok || pick) {
            *(unsigned char *) (self + RG(0x1c21, 0x1ae9)) = GetField0x3acValue_020100a8(GameState::GetInstance());
            TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
            *(unsigned char *) (self + RG(0xf80, 0xed8)) = *(int *) (self + RG(0x1bb8, 0x1a80));
            *(unsigned int *) (self + RG(0x247c, 0x22ac)) &= ~4;
            SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
            if (CUR == LAST + 1) {
                if (LAST != 1) {
                    *(int *) (arg0 + RG(0x1bb8, 0x1a80)) = RG(0xb, 0xc);
                } else {
                    *(unsigned char *) (arg0 + RG(0x1c32, 0x1afa)) = 0;
                    func_0205deb4((struct Struct_0205d81c *) OBJ, 4, 1);
                    *(short *) (arg0 + RG(0x1bf0, 0x1ab8)) = *(unsigned char *) (arg0 + RG(0x2521, 0x2351)) = 1;
                    SEL                                = func_ov002_021573f8(arg0, 1);
                    *(short *) (arg0 + RG(0x1c12, 0x1ada))         = 0;
                    *(short *) (arg0 + RG(0x1c28, 0x1af0))         = 0x238d;
                    *(short *) (arg0 + RG(0x1c2a, 0x1af2))         = -1;
                    *(int *) (arg0 + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
                    *(int *) (arg0 + RG(0x1bbc, 0x1a84))           = 4;
                    *(unsigned char *) (arg0 + RG(0x1c2e, 0x1af6)) = 1;
                }
                *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0;
                return;
            }
            *(int *) (arg0 + RG(0x1bb8, 0x1a80)) = 5;
            *(int *) (arg0 + RG(0x1bc0, 0x1a88)) = 0;
            if (!func_ov002_02157108(arg0, SEL)) {
                *(short *) (arg0 + RG(0x1c28, 0x1af0)) = 0x2369;
                *(short *) (arg0 + RG(0x1c2a, 0x1af2)) = -1;
                int var8                     = 0;
                if (SEL >= 0 && SEL <= 3) {
                    var8 = 1;
                }
                if (var8) {
                    *(short *) (arg0 + RG(0x1c28, 0x1af0)) = 0x235a;
                }
                *(int *) (arg0 + RG(0x1bb8, 0x1a80))           = RG(0x26, 0x29);
                *(int *) (arg0 + RG(0x1bbc, 0x1a84))           = 5;
                *(unsigned char *) (arg0 + RG(0x2478, 0x22a8)) = 1;
                *(unsigned char *) (arg0 + RG(0x1c31, 0x1af9)) = 0;
            }
            *(short *) (arg0 + RG(0x1be8, 0x1ab0)) = 0;
            if (CUR != LAST) {
                return;
            }
            GameState *var9    = GameState::GetInstance();
            GameObject *var10 = var9->GetProtagonist();
            if (!var10) {
                return;
            }
            unsigned char *var11 = func_02053c6c((unsigned char *) var10);
            *(short *) (arg0 + RG(0x1be8, 0x1ab0)) =
                func_020a0af4((struct Struct_020a095c *) func_02010828(var9), *(short *) (var11 + RG(0x958, 0x8c0)));
            if (*(short *) (arg0 + RG(0x1be8, 0x1ab0)) == -1) {
                *(short *) (arg0 + RG(0x1be8, 0x1ab0)) = 0;
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
#if !defined(jpn)
            func_ov002_0215b428((unsigned char *) arg0);
#endif
            SEL                                = -1;
            CUR                                = -1;
            *(unsigned char *) (arg0 + RG(0x2521, 0x2351)) = 0;
            func_ov002_02156e90(arg0);
        }
    }
}
