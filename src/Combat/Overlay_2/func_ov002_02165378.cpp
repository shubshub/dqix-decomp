#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct StructA0205d5d0;
struct SePlayer;
struct Obj020d7aa0;

extern "C" int func_ov002_0215edc8(unsigned char *self);
extern "C" void func_ov002_02157174(char *self, int combatantId);
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215e900(char *self);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_ov002_0215ece4(void *base, char *dst, int c, int arg3, int arg4);
extern "C" char *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" void func_ov002_0216574c(void *elem, int on);
extern "C" int Window_SetPaneText(struct StructA0205d5d0 *, int, int, int, unsigned char);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205df38(void *list, int key);
extern "C" Obj020d7aa0 *TextQueue_GetInstance();
extern "C" void TextQueue_Reset(Obj020d7aa0 *obj);
extern "C" void SePlayer_Play(struct SePlayer *obj, int a, int b);
extern "C" int func_ov002_0216364c(void *member);
extern "C" int func_ov002_02161b48(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" char g_sePlayer;

// USA: func_ov002_02165378
#if defined(jpn)
extern "C" void func_ov002_0215fe54(void *base, char *dst, int c, int arg3, int arg4);
#define func_ov002_0215ece4 func_ov002_0215fe54
extern "C" ARM void func_ov002_02165378(char *self) {
    int state = *(int *) (self + 0x1a88);
    if (state == 0) {
        if (!func_ov002_0215edc8((unsigned char *) self)) {
            return;
        }
        *(short *) (self + 0x1aee) = -1;
        *(short *) (self + 0x1ac0) = 0;
        func_ov002_02157174(self, *(signed char *) (self + *(short *) (self + 0x1ac0) + 0x1b32));
        func_0205de24((struct Struct0205de24 *) (self + 0xe20), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215e900(self);
        *(short *) (self + 0x1ac2)         = 0;
        *(short *) (self + 0x1ac0)         = 0;
        *(unsigned char *) (self + 0x1ae8) = *(signed char *) (self + *(short *) (self + 0x1ac0) + 0x1b32);
        memset(*(void **) (self + 0x1a98), 0, 0x800);
        func_ov002_0215ece4(self, *(char **) (self + 0x1a98), *(signed char *) (self + 0x1ae8), 0, 8);
        int on = 0;
        if ((short) ((*(unsigned char *) (self + 0x2350) + 7) / 8) > 1) {
            on = 1;
        }
        char *e = func_0205d81c((struct Struct_0205d81c *) (self + 0xe20), 0x12);
        if (e != 0) {
            func_ov002_0216574c(e, on);
        }
        ((int (*)(struct StructA0205d5d0*, int, int, int))Window_SetPaneText)((struct StructA0205d5d0 *) (self + 0xe20), 0x12,
                                                             *(int *) (self + 0x1a98), 1);
        *(int *) (self + 0x1a88) += 1;
        return;
    }
    if (state != 1) {
        return;
    }
    *(unsigned int *) (self + 0x22ac) |= 4;
    short old = *(short *) (self + 0x1ac0);
    *(short *) (self + 0x1ac0) =
        Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0xe20));
    *(unsigned char *) (self + 0x1ae8) = *(signed char *) (self + *(short *) (self + 0x1ac0) + 0x1b32);
    if (old != *(short *) (self + 0x1ac0)) {
        func_ov002_02157174(self, *(signed char *) (self + 0x1ae8));
        memset(*(void **) (self + 0x1a98), 0, 0x800);
        func_ov002_0215ece4(self, *(char **) (self + 0x1a98), *(signed char *) (self + 0x1ae8), 0, 8);
        int on = 0;
        if ((short) ((*(unsigned char *) (self + 0x2350) + 7) / 8) > 1) {
            on = 1;
        }
        char *e = func_0205d81c((struct Struct_0205d81c *) (self + 0xe20), 0x12);
        if (e != 0) {
            func_ov002_0216574c(e, on);
        }
        ((int (*)(struct StructA0205d5d0*, int, int, int))Window_SetPaneText)((struct StructA0205d5d0 *) (self + 0xe20), 0x12,
                                                             *(int *) (self + 0x1a98), 1);
        return;
    }
    int t  = g_keyManager.TestKeysPressed(0x601);
    int u  = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0xe20), 0x14);
    int ok = (t | u) ? 1 : 0;
    if (ok || func_0205df38(self + 0xe20, 0x12) != 0) {
        if (*(unsigned int *) (self + 0x22ac) & 2) {
            return;
        }
        TextQueue_Reset(TextQueue_GetInstance());
        *(unsigned char *) (self + 0xed8) = *(int *) (self + 0x1a80);
        *(unsigned int *) (self + 0x22ac) &= ~4;
        SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
        *(int *) (self + 0x1a80) = 0x12;
        *(int *) (self + 0x1a88) = 0;
        if (func_ov002_0216364c(
                GameState::GetInstance()->GetPartyMemberByIndex(*(signed char *) (self + 0x1ae8))))
        {
            *(short *) (self + 0x1af0) = 0x2332;
            *(short *) (self + 0x1af2) = -1;
            *(int *) (self + 0x1a80)   = 0x29;
            *(int *) (self + 0x1a84)   = 0x11;
            return;
        }
        if (*(unsigned char *) (self + 0x2350) != 0) {
            *(int *) (self + 0x1a80) = 0x12;
            return;
        }
        *(short *) (self + 0x1af0) = 0x232e;
        *(short *) (self + 0x1af2) = -1;
        *(int *) (self + 0x1a80)   = 0x29;
        *(int *) (self + 0x1a84)   = 0x11;
        return;
    }
    if (func_ov002_02161b48(self, 1)) {
        *(short *) (self + 0x1ac0)       = -1;
        *(signed char *) (self + 0x1ae8) = -1;
        func_ov002_02156e90(self);
    }
}
#else
extern "C" ARM void func_ov002_02165378(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        if (!func_ov002_0215edc8((unsigned char *) self)) {
            return;
        }
        *(short *) (self + 0x1c26) = -1;
        *(short *) (self + 0x1bf8) = 0;
        func_ov002_02157174(self, *(signed char *) (self + *(short *) (self + 0x1bf8) + 0x1c6e));
        func_0205de24((struct Struct0205de24 *) (self + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215e900(self);
        *(short *) (self + 0x1bfa)         = 0;
        *(short *) (self + 0x1bf8)         = 0;
        *(unsigned char *) (self + 0x1c20) = *(signed char *) (self + *(short *) (self + 0x1bf8) + 0x1c6e);
        memset(*(void **) (self + 0x1bd0), 0, 0x960);
        func_ov002_0215ece4(self, *(char **) (self + 0x1bd0), *(signed char *) (self + 0x1c20), 0, 8);
        int on = 0;
        if ((short) ((*(unsigned char *) (self + 0x2520) + 7) / 8) > 1) {
            on = 1;
        }
        char *e = func_0205d81c((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 0x11);
        if (e != 0) {
            func_ov002_0216574c(e, on);
        }
        Window_SetPaneText((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x11,
                                                             *(int *) (self + 0x1bd0), 1, 0);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (state != 1) {
        return;
    }
    *(unsigned int *) (self + 0x247c) |= 4;
    short old = *(short *) (self + 0x1bf8);
    *(short *) (self + 0x1bf8) =
        Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0x2c8 + 0xc00));
    *(unsigned char *) (self + 0x1c20) = *(signed char *) (self + *(short *) (self + 0x1bf8) + 0x1c6e);
    if (old != *(short *) (self + 0x1bf8)) {
        func_ov002_02157174(self, *(signed char *) (self + 0x1c20));
        memset(*(void **) (self + 0x1bd0), 0, 0x960);
        func_ov002_0215ece4(self, *(char **) (self + 0x1bd0), *(signed char *) (self + 0x1c20), 0, 8);
        int on = 0;
        if ((short) ((*(unsigned char *) (self + 0x2520) + 7) / 8) > 1) {
            on = 1;
        }
        char *e = func_0205d81c((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 0x11);
        if (e != 0) {
            func_ov002_0216574c(e, on);
        }
        Window_SetPaneText((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x11,
                                                             *(int *) (self + 0x1bd0), 1, 0);
        return;
    }
    int t  = g_keyManager.TestKeysPressed(0x601);
    int u  = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0x2c8 + 0xc00), 0x14);
    int ok = (t | u) ? 1 : 0;
    if (ok || func_0205df38(self + 0x2c8 + 0xc00, 0x11) != 0) {
        if (*(unsigned int *) (self + 0x247c) & 2) {
            return;
        }
        TextQueue_Reset(TextQueue_GetInstance());
        *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
        *(unsigned int *) (self + 0x247c) &= ~4;
        SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
        *(int *) (self + 0x1bb8) = 0x11;
        *(int *) (self + 0x1bc0) = 0;
        if (func_ov002_0216364c(
                GameState::GetInstance()->GetPartyMemberByIndex(*(signed char *) (self + 0x1c20))))
        {
            *(short *) (self + 0x1c28) = 0x2332;
            *(short *) (self + 0x1c2a) = -1;
            *(int *) (self + 0x1bb8)   = 0x26;
            *(int *) (self + 0x1bbc)   = 0x10;
            return;
        }
        if (*(unsigned char *) (self + 0x2520) != 0) {
            *(int *) (self + 0x1bb8) = 0x11;
            return;
        }
        *(short *) (self + 0x1c28) = 0x232e;
        *(short *) (self + 0x1c2a) = -1;
        *(int *) (self + 0x1bb8)   = 0x26;
        *(int *) (self + 0x1bbc)   = 0x10;
        return;
    }
    if (func_ov002_02161b48(self, 1)) {
        *(short *) (self + 0x1bf8)       = -1;
        *(signed char *) (self + 0x1c20) = -1;
        func_ov002_02156e90(self);
    }
}
#endif
