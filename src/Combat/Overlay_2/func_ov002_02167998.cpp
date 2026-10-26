#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
#define data_ov002_0216cc98 data_ov002_0216d2b0
#define RG(u, j) (j)
#define OBJ (base + 0xe20)
#else
#define RG(u, j) (u)
#define OBJ (base + 0x2c8 + 0xc00)
#endif

class GameState;
struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Elem_0205d81c;
struct ShortArrays0204c610;
struct ShortArrays0204c654;
struct SePlayer;
struct Obj_0205da38;

struct Cursor {
    int col;
    int row;
};

struct Flags3c {
    unsigned int pad : 30;
    unsigned int toggle : 1;
    unsigned int top : 1;
};

extern "C" int GameState_GetProtagonistIndex(GameState *gs);
extern "C" void func_0205def8(struct Struct_0205def8 *s, int clear, int key);
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" void func_0204c610(struct ShortArrays0204c610 *base, int index, short *out0, short *out1, short *out2, short *out3);
extern "C" void func_0204c654(ShortArrays0204c654*, int, short, short, short, short);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" void func_0205d7a0(unsigned char *obj, int val);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38 *obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" int func_ov002_02161b48(char *self, int flag);
extern "C" unsigned char *func_02053c6c(unsigned char *c);
extern "C" void func_ov002_02161cf0(void *self);
extern "C" void func_ov002_0215f6a4(void *self);
extern "C" void func_ov002_02161a8c(void);
extern "C" void func_ov002_021619b4(int member, int a, int b);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
extern "C" void func_ov002_02156e90(void *self);

extern unsigned char data_ov002_0216cc98[];
extern char g_sePlayer[];

// USA: func_ov002_02167998
extern "C" ARM void func_ov002_02167998(char *base) {
    unsigned char *obj = (unsigned char *) OBJ;
    int col;
    short v;
    int last;
    int shown;
    GameState *gs = GameState::GetInstance();
    int phase     = *(int *) (base + RG(0x1bc0, 0x1a88));
    if (phase == 0) {
#if !defined(jpn)
        base[0x1c34] = 0;
#endif
        for (int i = 0; i < 5; i++) {
            func_0205def8((struct Struct_0205def8 *) obj, 0, data_ov002_0216cc98[i]);
        }
        base[RG(0x1c20, 0x1ae8)]               = GameState_GetProtagonistIndex(gs);
        *(short *) (base + RG(0x1c02, 0x1aca)) = 0;
        func_0205de24((struct Struct0205de24 *) obj, 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f6a4(base);
        (*(int *) (base + RG(0x1bc0, 0x1a88)))++;
        func_ov002_02161a8c();
#if !defined(jpn)
        func_ov002_021619b4(*(signed char *) (base + 0x1c20), *(int *) (base + 0x1a68), *(int *) (base + 0x1bd8));
#endif
        return;
    }
    if (phase != 1) return;
    *(int *) (base + RG(0x247c, 0x22ac)) |= 4;
    struct Elem_0205d81c *e = func_0205d81c((struct Struct_0205d81c *) obj, RG(0x18, 0x19));
    if (e != 0) {
        short idx = *(signed char *) (base + RG(0x1c73, 0x1b37));
        short a, b, c, d;
        func_0204c610((struct ShortArrays0204c610 *) e, idx, &a, &b, &c, &d);
        idx += *(signed char *) (base + RG(0x1c73, 0x1b37)) + 1;
        func_0204c654((struct ShortArrays0204c654 *) e, idx, a, b, c, d);
        idx += *(signed char *) (base + RG(0x1c73, 0x1b37)) + 1;
        func_0204c654((struct ShortArrays0204c654 *) e, idx, a, b, c, d);
    }
    int mode;
    int sel;
    short old = *(short *) (base + RG(0x1c02, 0x1aca));
    col         = old % (*(signed char *) (base + RG(0x1c73, 0x1b37)) + 1);
    Cursor *cur = (Cursor *) (obj + 0x6c);
    mode        = cur->col;
    sel         = cur->row;
    *(short *) (base + RG(0x1c02, 0x1aca)) = Window_GetSelectedIndex((struct Struct_0205c570 *) obj);
    if (old != *(short *) (base + RG(0x1c02, 0x1aca))) {
        if (col == sel && sel == *(signed char *) (base + RG(0x1c73, 0x1b37)) && g_touchInput.pressed_ == 0) {
            sel--;
            v = mode * (*(signed char *) (base + RG(0x1c73, 0x1b37)) + 1) + sel;
            func_0205d7a0(obj, v);
            *(short *) (base + RG(0x1c02, 0x1aca)) = v;
        }
        base[RG(0x1c20, 0x1ae8)] = -1;
        if (sel < *(signed char *) (base + RG(0x1c73, 0x1b37))) {
            base[RG(0x1c20, 0x1ae8)] = *(signed char *) (base + sel + RG(0x1c6e, 0x1b32));
        }
#if defined(jpn)
        func_ov002_0215b9a4(base, 0x1b, 0);
        func_ov002_0215b9a4(base, 0x1c, 0);
#else
        base[0x1c34] = 1;
#endif
    }
    last  = sel == *(signed char *) (base + RG(0x1c73, 0x1b37));
    shown = !last;
    func_0205def8((struct Struct_0205def8 *) obj, shown, RG(0x1a, 0x1b));
    func_0205def8((struct Struct_0205def8 *) obj, shown, RG(0x1b, 0x1c));
    if (old != *(short *) (base + RG(0x1c02, 0x1aca))) return;
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int confirm = (pressed | Window_IsSelectionTouched((struct Obj_0205da38 *) OBJ, 0x14)) ? 1 : 0;
    if (confirm) {
        if (sel == *(signed char *) (base + RG(0x1c73, 0x1b37))) {
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            for (int i = 0; i < 5; i++) {
                func_0205def8((struct Struct_0205def8 *) obj, 1, data_ov002_0216cc98[i]);
            }
            *(short *) (base + RG(0x1c02, 0x1aca)) = -1;
            func_ov002_02156e90(base);
            func_ov002_02156e90(base);
            func_ov002_02156e90(base);
            return;
        }
        int member       = *(signed char *) (base + RG(0x1c20, 0x1ae8));
        unsigned char *m = (unsigned char *)gs->GetPartyMemberByIndex(member);
        if (m == 0) return;
        switch (mode) {
        case 0:
            if (member == GameState_GetProtagonistIndex(gs)) return;
            func_ov002_0215b9a4(base, *(int *) (base + RG(0x1bb8, 0x1a80)) & 0xff, 1);
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + RG(0x1bb8, 0x1a80))   = RG(0x19, 0x1a);
            *(int *) (base + RG(0x1bc0, 0x1a88))   = 0;
            *(short *) (base + RG(0x1c04, 0x1acc)) = (signed char) *(int *) (func_02053c6c(m) + RG(0x94c, 0x8b4));
            break;
        case 1: {
            struct Flags3c *f = (struct Flags3c *) (*(unsigned char **) (m + 0x134) + 0x3c);
            unsigned short t = f->toggle;
            t++;
            t %= 2;
            f->toggle = t;
            func_ov002_0215b9a4(base, *(int *) (base + RG(0x1bb8, 0x1a80)) & 0xff, 0);
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            break;
        }
        case 2: {
            unsigned char *f = func_02053c6c(m);
            obj[0xb8]        = *(int *) (base + RG(0x1bb8, 0x1a80));
            *(int *) (base + RG(0x247c, 0x22ac)) &= ~4;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + RG(0x1bb8, 0x1a80))   = RG(0x1c, 0x1d);
            *(int *) (base + RG(0x1bc0, 0x1a88))   = 0;
            *(short *) (base + RG(0x1c06, 0x1ace)) = f[0x56a];
            break;
        }
        }
        return;
    }
    if (func_ov002_02161b48(base, 1)) {
        for (int i = 0; i < 5; i++) {
            func_0205def8((struct Struct_0205def8 *) obj, 1, data_ov002_0216cc98[i]);
        }
        *(short *) (base + RG(0x1c02, 0x1aca)) = -1;
        func_ov002_02156e90(base);
        func_ov002_02156e90(base);
        func_ov002_02156e90(base);
    }
}
