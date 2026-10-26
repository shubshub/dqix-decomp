#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct SePlayer;
struct Struct_0205dee8;
struct Struct_ov002_02165764 {
    int f0;
    unsigned int id : 12;
    unsigned int rest : 20;
};

extern "C" void func_0205def8(struct Struct_0205def8 *s, int clear, int key);
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215eadc(void *obj, int val);
extern "C" void func_0205dee8(struct Struct_0205dee8 *obj, int val);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
extern "C" void func_ov002_02161b98(char *self);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int func_ov002_0216197c(int key, struct Struct_0205d81c *s);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" char *func_0200ff94(GameState *gs, int id);
extern "C" void SePlayer_Play(struct SePlayer *obj, int a, int b);
extern "C" int func_ov002_0215b720(char *self, int id);
extern "C" void func_ov002_02157d40(char *self);
extern "C" int func_ov002_02161b48(char *self, int v);
extern "C" void func_ov002_02156ff0(unsigned char *self, int v);
extern "C" int func_ov002_0215b7d0(char* base);

extern "C" char g_sePlayer;

#define OBJ (self + 0x2c8 + 0xc00)

// USA: func_ov002_02165764
#if defined(jpn)
#undef OBJ
#define OBJ (self + 0xe20)

extern "C" ARM void func_ov002_02165764(char *self) {
    int state = *(int *) (self + 0x1a88);
    if (state == 0) {
        *(short *) (self + 0x1ac2) = 0;
        func_0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215eadc(self, 0);
        func_0205dee8((struct Struct_0205dee8 *) OBJ, 0x12);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x12, 0);
        *(int *) (self + 0x1a88) += 1;
        return;
    }
    if (state == 1) {
        *(unsigned int *) (self + 0x22ac) |= 4;
        short old = *(short *) (self + 0x1ac2);
        func_ov002_02161b98(self);
        *(short *) (self + 0x1ac2) = Window_GetSelectedIndex((struct Struct_0205c570 *) OBJ);
        if (old != *(short *) (self + 0x1ac2)) {
            *(int *) (self + 0x1a94) = 1;
        }
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x13, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x14, 0);
        func_ov002_0215b9a4(self, *(int *) (self + 0x1a80) & 0xff, 0);
        int t  = g_keyManager.TestKeysPressed(0x601);
        int u  = Window_IsSelectionTouched((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            *(unsigned char *) (self + 0x1b48) = 3;
            char *c = func_0200ff94(GameState::GetInstance(), *(signed char *) (self + 0x1ae8));
            if (c == 0) {
                return;
            }
            if (**(int **) (c + 0x130) & 1) {
                *(short *) (self + 0x1af0) = -1;
                *(short *) (self + 0x1af2) = -1;
                *(int *) (self + 0x1a80)   = 0x12;
                return;
            }
            SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
            *(short *) (self + 0x1aee) = -1;
            short v                    = *(short *) (self + 0x1ac2);
            if (v >= 0 && v < 0x20) {
                *(short *) (self + 0x1aee) = (*(Struct_ov002_02165764 **) (self + v * 4 + 0x22d0))->id;
            }
            if (func_ov002_0215b720(self, *(short *) (self + 0x1aee))) {
                *(int *) (self + 0x1a88) = 2;
                return;
            }
            *(unsigned char *) (self + 0xed8) = *(int *) (self + 0x1a80);
            *(unsigned int *) (self + 0x22ac) &= ~4;
            *(int *) (self + 0x1a88) = 0;
            func_ov002_02157d40(self);
            return;
        }
        if (func_ov002_02161b48(self, 1)) {
            *(short *) (self + 0x1ac2) = -1;
            *(short *) (self + 0x1aee) = -1;
            *(int *) (self + 0x1a80)   = 0x11;
            func_ov002_02156ff0((unsigned char *) self, 0x12);
            Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x12, 1);
            func_0205dee8((struct Struct_0205dee8 *) OBJ, 0x11);
            Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x11, 0);
            *(int *) (self + 0x1a88) = 1;
            *(int *) (self + 0x1a80) = 0x11;
            func_ov002_0215b9a4(self, *(int *) (self + 0x1a80) & 0xff, 0);
            func_ov002_02161cf0(self);
        }
        return;
    }
    if (state != 2) {
        return;
    }
    int r = func_ov002_0215b7d0(self);
    if (r > 0) {
        *(unsigned char *) (self + 0xed8) = *(int *) (self + 0x1a80);
        *(unsigned int *) (self + 0x22ac) &= ~4;
        *(int *) (self + 0x1a88) = 0;
        func_ov002_02157d40(self);
        return;
    }
    if (r < 0) {
        *(short *) (self + 0x1af0)         = 0x232d;
        *(short *) (self + 0x1af2)         = -1;
        *(short *) (self + 0x22b8)         = 0x232b;
        *(unsigned char *) (self + 0x22ba) = 1;
        *(int *) (self + 0x1a80)           = 0x29;
        *(int *) (self + 0x1a84)           = 0x12;
        *(int *) (self + 0x1a88)           = 0;
    }
}
#else
extern "C" ARM void func_ov002_02165764(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        func_0205def8((struct Struct_0205def8 *) OBJ, 0, 0x29);
        *(short *) (self + 0x1bfa) = 0;
        func_0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215eadc(self, 0);
        func_0205dee8((struct Struct_0205dee8 *) OBJ, 0x11);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x11, 0);
        func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (state == 1) {
        *(unsigned int *) (self + 0x247c) |= 4;
        short old = *(short *) (self + 0x1bfa);
        func_ov002_02161b98(self);
        *(short *) (self + 0x1bfa) = Window_GetSelectedIndex((struct Struct_0205c570 *) OBJ);
        if (old != *(short *) (self + 0x1bfa)) {
            *(int *) (self + 0x1bcc) = 1;
        }
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x12, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x13, 0);
        if (func_ov002_0216197c(*(int *) (self + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        }
        int t  = g_keyManager.TestKeysPressed(0x601);
        int u  = Window_IsSelectionTouched((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            *(unsigned char *) (self + 0x1c84) = 3;
            char *c = func_0200ff94(GameState::GetInstance(), *(signed char *) (self + 0x1c20));
            if (c == 0) {
                return;
            }
            if (**(int **) (c + 0x130) & 1) {
                *(short *) (self + 0x1c28) = -1;
                *(short *) (self + 0x1c2a) = -1;
                *(int *) (self + 0x1bb8)   = 0x11;
                return;
            }
            SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
            *(short *) (self + 0x1c26) = -1;
            short v                    = *(short *) (self + 0x1bfa);
            if (v >= 0 && v < 0x20) {
                *(short *) (self + 0x1c26) = (*(Struct_ov002_02165764 **) (self + v * 4 + 0x24a0))->id;
            }
            if (func_ov002_0215b720(self, *(short *) (self + 0x1c26))) {
                *(int *) (self + 0x1bc0) = 2;
                return;
            }
            *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(unsigned int *) (self + 0x247c) &= ~4;
            *(int *) (self + 0x1bc0) = 0;
            func_ov002_02157d40(self);
            return;
        }
        if (func_ov002_02161b48(self, 1)) {
            *(short *) (self + 0x1bfa) = -1;
            *(short *) (self + 0x1c26) = -1;
            *(int *) (self + 0x1bb8)   = 0x10;
            func_ov002_02156ff0((unsigned char *) self, 0x11);
            Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x11, 1);
            func_0205dee8((struct Struct_0205dee8 *) OBJ, 0x10);
            Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x10, 0);
            *(int *) (self + 0x1bc0) = 1;
            *(int *) (self + 0x1bb8) = 0x10;
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
            func_ov002_02161cf0(self);
            func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x29);
        }
        return;
    }
    if (state != 2) {
        return;
    }
    int r = func_ov002_0215b7d0(self);
    if (r > 0) {
        *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
        *(unsigned int *) (self + 0x247c) &= ~4;
        *(int *) (self + 0x1bc0) = 0;
        func_ov002_02157d40(self);
        return;
    }
    if (r < 0) {
        *(short *) (self + 0x1c28)         = 0x232d;
        *(short *) (self + 0x1c2a)         = -1;
        *(short *) (self + 0x2488)         = 0x232b;
        *(unsigned char *) (self + 0x248a) = 1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x11;
        *(int *) (self + 0x1bc0)           = 0;
    }
}
#endif
