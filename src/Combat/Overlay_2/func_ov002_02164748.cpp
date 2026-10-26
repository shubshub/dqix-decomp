#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Struct_ov002_02164748_2;
struct Struct_ov002_02164748_3;
struct Struct_ov002_02164748_4;
struct KeyMap020a095c;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" int func_ov002_02161b48(char *base, int a);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
extern "C" void func_0205dee8(struct Struct_ov002_02164748_2 *o, int v);
extern "C" unsigned char *func_02053c6c(unsigned char *p);
extern "C" int func_ov002_02157108(void *base, int id);
extern "C" GameObject *func_0200ff1c(GameState *gameState, int combatantId);
extern "C" void *GameState_GetParty(GameState *gameState);
extern "C" void func_02083834(struct Struct_ov002_02164748_3 *s, int v);
extern "C" int func_02083994(struct Struct_ov002_02164748_4 *s, int v);
extern "C" void func_020a095c(struct KeyMap020a095c *m, int key, int val);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215bba8(char *base);
extern "C" void func_ov002_0215a7b4(char *base, int a, short b, int c, int d);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" char g_sePlayer[];

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

#define FLAG(m) (**(int **) ((char *) (m) + 0x130) & 1)
#define SLOT(f, i) (*(short *) ((f) + (i) * 2 + 0x400 + 0x54))

// USA: func_ov002_02164748
extern "C" ARM void func_ov002_02164748(char *base) {
    int state = *(int *) (base + RG(0x1000 + 0xbc0, 0x1a88));
    if (state == 0) {
        *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc)) = func_ov002_02157108(base, *(signed char *) (base + RG(0x1c00 + 0x21, 0x1ae9))) & 7;
        func_0205de24((struct Struct0205de24 *) (base + RG(0x2c8 + 0xc00, 0xe20)), 0, 3);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0x2c8 + 0xc00, 0xe20)), RG(9, 0xa), 1);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0x2c8 + 0xc00, 0xe20)), RG(0xd, 0xe), 0);
        func_ov002_02161cf0(base);
        *(int *) (base + RG(0x1000 + 0xbc8, 0x1a90)) = 1;
        func_ov002_0215bba8(base);
        *(int *) (base + RG(0x1000 + 0xbc0, 0x1a88)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + RG(0x2000 + 0x47c, 0x22ac)) |= 4;
        short old = *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc));
        *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc)) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + RG(0x2c8 + 0xc00, 0xe20)));
        if (old != *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc))) return;
        int var2 = g_keyManager.TestKeysPressed(0x601);
        int tb = Window_IsSelectionTouched((struct Obj_0205da38*)(base + RG(0x2c8 + 0xc00, 0xe20)), 0x14);
        if ((var2 | tb) ? 1 : 0) {
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            GameState *gs = GameState::GetInstance();
            GameObject *a = func_0200ff1c(gs, *(signed char *) (base + RG(0x1c00 + 0x21, 0x1ae9)));
            if (a == NULL) return;
            unsigned char *fa = func_02053c6c((unsigned char *) a);
            GameObject *b     = func_0200ff1c(gs, *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)));
            if (b == NULL && *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)) != 4) return;
            int done                          = 0;
            short v                           = SLOT(fa, *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc)));
            *(short *) (base + RG(0x1c00 + 0x24, 0x1aec)) = v;
            if (v <= 0) {
                func_ov002_0215a7b4(base, *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)), *(short *) (base + RG(0x1c00 + 0x22, 0x1aea)),
                                    *(short *) (base + RG(0x1b00 + 0xe8, 0x1ab0)), 0);
                func_02083834((struct Struct_ov002_02164748_3 *) fa,
                                                                 *(short *) (base + RG(0x1c00 + 0x22, 0x1aea)));
                int t = *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8));
                if (t == 4) {
                    if (FLAG(a))
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x236b;
                    else
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x236a;
                } else if (t == *(signed char *) (base + RG(0x1c00 + 0x21, 0x1ae9))) {
                    if (FLAG(b))
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x2364;
                    else
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x2363;
                } else {
                    if ((**(int **) ((char *) b + 0x130) & 1) && FLAG(a))
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x2360;
                    else if (!(**(int **) ((char *) b + 0x130) & 1U) && FLAG(a))
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x235f;
                    else if ((**(int **) ((char *) b + 0x130) & 1L) && !FLAG(a))
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x235e;
                    else
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x235b;
                    done = 1;
                }
            } else if (v > 0) {
                done = 1;
                if (*(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)) == 4) {
                    void *party = GameState_GetParty(gs);
                    func_ov002_0215a7b4(base, *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)), *(short *) (base + RG(0x1c00 + 0x22, 0x1aea)),
                                        *(short *) (base + RG(0x1b00 + 0xe8, 0x1ab0)), 0);
                    func_020a095c((struct KeyMap020a095c *) party,
                                                                      *(short *) (base + RG(0x1c00 + 0x24, 0x1aec)), done);
                    SLOT(fa, *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc))) = *(short *) (base + RG(0x1c00 + 0x22, 0x1aea));
                    if (FLAG(a))
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x236d;
                    else
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x236c;
                } else {
                    GameObject *b2 = func_0200ff1c(gs, *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)));
                    if (b2 == NULL) return;
                    unsigned char *fb                           = func_02053c6c((unsigned char *) b2);
                    SLOT(fb, *(short *) (base + RG(0x1b00 + 0xe8, 0x1ab0))) = *(short *) (base + RG(0x1c00 + 0x24, 0x1aec));
                    SLOT(fa, *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc))) = *(short *) (base + RG(0x1c00 + 0x22, 0x1aea));
                    if (*(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)) == *(signed char *) (base + RG(0x1c00 + 0x21, 0x1ae9))) {
                        if (FLAG(b2))
                            *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x2364;
                        else
                            *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x2363;
                    } else if (FLAG(b2) && FLAG(a)) {
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x235d;
                    } else {
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0)) = 0x235c;
                    }
                }
            }
            if (done) {
                int same = 0;
                int var15  = *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8));
                if (var15 != *(signed char *) (base + RG(0x1c00 + 0x21, 0x1ae9)) &&
                    *(short *) (base + RG(0x1c00 + 0x22, 0x1aea)) == *(short *) (base + RG(0x1c00 + 0x24, 0x1aec)))
                    same = 1;
                if (*(short *) (base + RG(0x1c00 + 0x22, 0x1aea)) == 0x570a && var15 != 4) {
                    short cnt = func_02083994(
                        (struct Struct_ov002_02164748_4 *) func_02053c6c((unsigned char *) b), 0x570a);
                    if (cnt == 0 || (cnt == 1 && same)) {
                        *(unsigned char *) (*(char **) ((char *) b + 0x130) + 8) = 0;
                        func_ov017_021c9e00(b->obj3D_.actorIndex_, 0, 0, 1);
                    }
                }
                if (*(short *) (base + RG(0x1c00 + 0x24, 0x1aec)) == 0x570a) {
                    short cnt = func_02083994((struct Struct_ov002_02164748_4 *) fa, 0x570a);
                    if (cnt == 0 || (cnt == 1 && same)) {
                        *(unsigned char *) (*(char **) ((char *) a + 0x130) + 8) = 0;
                        func_ov017_021c9e00(a->obj3D_.actorIndex_, 0, 0, 1);
                    }
                }
            }
            *(unsigned int *) (base + RG(0x2000 + 0x47c, 0x22ac)) &= ~4;
            func_ov002_0215b9a4(base, *(int *) (base + RG(0x1000 + 0xbb8, 0x1a80)) & 0xff, 1);
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1af2))          = -1;
            *(int *) (base + RG(0x1000 + 0xbb8, 0x1a80))           = RG(0x26, 0x29);
            *(int *) (base + RG(0x1000 + 0xbbc, 0x1a84))           = 5;
            *(int *) (base + RG(0x1000 + 0xbc0, 0x1a88))           = 0;
            *(unsigned char *) (base + RG(0x2000 + 0x478, 0x22a8)) = 1;
        } else if (func_ov002_02161b48(base, 1)) {
            *(short *) (base + RG(0x1b00 + 0xf4, 0x1abc)) = -1;
            *(int *) (base + RG(0x1000 + 0xbb8, 0x1a80))  = RG(9, 0xa);
            func_ov002_02161cf0(base);
            Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0x2c8 + 0xc00, 0xe20)), RG(9, 0xa), 0);
            func_0205dee8((struct Struct_ov002_02164748_2 *) (base + RG(0x2c8 + 0xc00, 0xe20)), RG(9, 0xa));
            *(int *) (base + RG(0x1000 + 0xbc8, 0x1a90)) = 1;
            *(int *) (base + RG(0x1000 + 0xbcc, 0x1a94)) = 1;
            func_ov002_0215b9a4(base, *(int *) (base + RG(0x1000 + 0xbb8, 0x1a80)) & 0xff, 0);
        }
    }
}
