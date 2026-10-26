#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct SePlayer;
struct Obj020d7aa0;

extern "C" void Zone3D_GetInstance(void);
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215f3a0(void *base);
extern "C" void func_0205def8(struct Struct_0205def8 *s, int clear, int key);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" char *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" int func_ov002_0216197c(int key, struct Struct_0205d81c *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" Obj020d7aa0 *TextQueue_GetInstance();
extern "C" void TextQueue_Reset(Obj020d7aa0 *obj);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);
extern "C" void SePlayer_Play(struct SePlayer *obj, int a, int b);
extern "C" void func_ov017_021c1798(GameResources *res, unsigned char v);
extern "C" void func_ov002_0215a878(char *self);
extern "C" int GameState_GetProtagonistIndex(GameState *gs);
extern "C" void func_ov017_021bff8c(int a, int b);
extern "C" int func_ov002_02161b48(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" char g_sePlayer;

#define OBJ (self + 0x2c8 + 0xc00)

// USA: func_ov002_02166168
#if defined(jpn)
#undef OBJ
#define OBJ (self + 0xe20)
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    Zone3D_GetInstance();
    int state = *(int *) (self + 0x1a88);
    if (state == 0) {
        *(short *) (self + 0x1ac6) = 0;
        func_0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215f3a0(self);
        *(int *) (self + 0x1a88) += 1;
    } else if (state == 1) {
        *(unsigned int *) (self + 0x22ac) |= 4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x2c);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x16, 0);
        short old                  = *(short *) (self + 0x1ac6);
        *(short *) (self + 0x1ac6) = Window_GetSelectedIndex((struct Struct_0205c570 *) OBJ);
        char *e                    = func_0205d81c((struct Struct_0205d81c *) OBJ, 0x17);
        if (e != 0) {
            *(short *) (e + 0xc2) = 0;
        }
        func_ov002_0215b9a4(self, *(int *) (self + 0x1a80) & 0xff, 0);
        if (old != *(short *) (self + 0x1ac6)) {
            func_ov002_0215b9a4(self, 0x17, 0);
        }
        int t  = g_keyManager.TestKeysPressed(0x601);
        int u  = Window_IsSelectionTouched((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            unsigned int f = *(unsigned int *) (self + 0x22ac);
            if (f & 2) {
                return;
            }
            TextQueue_Reset(TextQueue_GetInstance());
            short count = 0;
            short list[9];
            func_ov002_02156080(self, list, &count);
            func_ov002_02161920(self);
            switch (list[*(short *) (self + 0x1ac6)]) {
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
                    func_ov017_021c1798(res, 1);
                    func_ov002_0215a878(self);
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
                    int id = (signed char) GameState_GetProtagonistIndex(gs);
                    for (int i = 0; i < *(int *) (self + 0x1b14); i++) {
                        char *c = (char *) func_0200ff1c(gs, *(int *) (self + i * 4 + 0x1b18));
                        if (c != 0 && !(**(int **) (c + 0x130) & 1)) {
                            id = (signed char) ((int *) (self + 0x1b18))[i];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) res, id);
                    *(int *) (self + 0x1a80) = 0x2e;
                    *(int *) (self + 0x1a88) = 0;
                    break;
                }
            }
        } else if (func_ov002_02161b48(self, 1)) {
            *(short *) (self + 0x1ac6) = -1;
            func_ov002_02156e90(self);
        }
    }
}
#else
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    Zone3D_GetInstance();
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(short *) (self + 0x1bfe) = 0;
        func_0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215f3a0(self);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (self + 0x247c) |= 4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x29);
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 1);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x15, 0);
        short old                  = *(short *) (self + 0x1bfe);
        *(short *) (self + 0x1bfe) = Window_GetSelectedIndex((struct Struct_0205c570 *) OBJ);
        char *e                    = func_0205d81c((struct Struct_0205d81c *) OBJ, 0x16);
        if (e != 0) {
            *(short *) (e + 0xc2) = 0;
        }
        if (func_ov002_0216197c(*(int *) (self + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        }
        if (old != *(short *) (self + 0x1bfe)) {
            func_ov002_0215b9a4(self, 0x16, 0);
        }
        int t  = g_keyManager.TestKeysPressed(0x601);
        int u  = Window_IsSelectionTouched((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            unsigned int f = *(unsigned int *) (self + 0x247c);
            if (f & 2) {
                return;
            }
            if (!(f & 0x20)) {
                return;
            }
            TextQueue_Reset(TextQueue_GetInstance());
            short count = 0;
            short list[9];
            func_ov002_02156080(self, list, &count);
            func_ov002_02161920(self);
            switch (list[*(short *) (self + 0x1bfe)]) {
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
                    func_ov017_021c1798(res, 1);
                    func_ov002_0215a878(self);
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
                    int id = (signed char) GameState_GetProtagonistIndex(gs);
                    for (int i = 0; i < *(int *) (self + 0x1c50); i++) {
                        char *c = (char *) func_0200ff1c(gs, *(int *) (self + i * 4 + 0x1c54));
                        if (c != 0 && !(**(int **) (c + 0x130) & 1)) {
                            id = (signed char) ((int *) (self + 0x1c54))[i];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) res, id);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                }
            }
        } else if (func_ov002_02161b48(self, 1)) {
            *(short *) (self + 0x1bfe) = -1;
            func_ov002_02156e90(self);
        }
    }
}
#endif
