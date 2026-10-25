#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205d81c;
struct StructA0205d5d0;
struct SePlayer;
struct Obj020d7aa0;

int HasPositiveContainerAndField_0215edc8(unsigned char *self);
extern "C" void func_ov002_02157174(char *self, int combatantId);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215e900(char *self);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_ov002_0215ece4(void *base, char *dst, int c, int productB, int clampedSum);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void SetOrClearByteC5Bit8_0216574c(void *elem, int on);
int Window_SetPaneText(struct StructA0205d5d0 *, int, int, int, unsigned char);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205df38(void *list, int key);
Obj020d7aa0 *TextQueue_GetInstance();
void TextQueue_Reset(Obj020d7aa0 *obj);
void SePlayer_Play(struct SePlayer *obj, int a, int b);
int IsFlagAt130Bit0Set_0216364c(void *member);
int CheckFlagOrThreshold_02161b48(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" char g_sePlayer;

// USA: func_ov002_02165378
#if defined(jpn)
int Window_SetPaneText(struct StructA0205d5d0 *, int, int, int);
extern "C" void func_ov002_0215fe54(void *base, char *dst, int c, int productB, int clampedSum);
#define func_ov002_0215ece4 func_ov002_0215fe54
extern "C" ARM void func_ov002_02165378(char *arg0) {
    int var0 = *(int *) (arg0 + 0x1a88);
    if (var0 == 0) {
        if (!func_ov002_0215edc8((unsigned char *) arg0)) {
            return;
        }
        *(short *) (arg0 + 0x1aee) = -1;
        *(short *) (arg0 + 0x1ac0) = 0;
        func_ov002_02157174(arg0, *(signed char *) (arg0 + *(short *) (arg0 + 0x1ac0) + 0x1b32));
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0xe20), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215e900(arg0);
        *(short *) (arg0 + 0x1ac2)         = 0;
        *(short *) (arg0 + 0x1ac0)         = 0;
        *(unsigned char *) (arg0 + 0x1ae8) = *(signed char *) (arg0 + *(short *) (arg0 + 0x1ac0) + 0x1b32);
        memset(*(void **) (arg0 + 0x1a98), 0, 0x800);
        func_ov002_0215ece4(arg0, *(char **) (arg0 + 0x1a98), *(signed char *) (arg0 + 0x1ae8), 0, 8);
        int var1 = 0;
        if ((short) ((*(unsigned char *) (arg0 + 0x2350) + 7) / 8) > 1) {
            var1 = 1;
        }
        char *var2 = func_0205d81c((struct Struct_0205d81c *) (arg0 + 0xe20), 0x12);
        if (var2 != 0) {
            func_ov002_0216574c(var2, var1);
        }
        Window_SetPaneText((struct StructA0205d5d0 *) (self + 0xe20), 0x12,
                                                             *(int *) (self + 0x1a98), 1);
        *(int *) (self + 0x1a88) += 1;
        return;
    }
    if (var0 != 1) {
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
        char *var5 = func_0205d81c((struct Struct_0205d81c *) (arg0 + 0xe20), 0x12);
        if (var5 != 0) {
            func_ov002_0216574c(var5, var4);
        }
        Window_SetPaneText((struct StructA0205d5d0 *) (self + 0xe20), 0x12,
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
        if (IsFlagAt130Bit0Set_0216364c(
                GameState::GetInstance()->GetPartyMemberByIndex(*(signed char *) (self + 0x1ae8))))
        {
            *(short *) (arg0 + 0x1af0) = 0x2332;
            *(short *) (arg0 + 0x1af2) = -1;
            *(int *) (arg0 + 0x1a80)   = 0x29;
            *(int *) (arg0 + 0x1a84)   = 0x11;
            return;
        }
        if (*(unsigned char *) (arg0 + 0x2350) != 0) {
            *(int *) (arg0 + 0x1a80) = 0x12;
            return;
        }
        *(short *) (arg0 + 0x1af0) = 0x232e;
        *(short *) (arg0 + 0x1af2) = -1;
        *(int *) (arg0 + 0x1a80)   = 0x29;
        *(int *) (arg0 + 0x1a84)   = 0x11;
        return;
    }
    if (func_ov002_02161b48(arg0, 1)) {
        *(short *) (arg0 + 0x1ac0)       = -1;
        *(signed char *) (arg0 + 0x1ae8) = -1;
        func_ov002_02156e90(arg0);
    }
}
#else
extern "C" ARM void func_ov002_02165378(char *arg0) {
    int var9 = *(int *) (arg0 + 0x1bc0);
    if (var9 == 0) {
        if (!func_ov002_0215edc8((unsigned char *) arg0)) {
            return;
        }
        *(short *) (arg0 + 0x1c26) = -1;
        *(short *) (arg0 + 0x1bf8) = 0;
        func_ov002_02157174(arg0, *(signed char *) (arg0 + *(short *) (arg0 + 0x1bf8) + 0x1c6e));
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215e900(arg0);
        *(short *) (arg0 + 0x1bfa)         = 0;
        *(short *) (arg0 + 0x1bf8)         = 0;
        *(unsigned char *) (arg0 + 0x1c20) = *(signed char *) (arg0 + *(short *) (arg0 + 0x1bf8) + 0x1c6e);
        memset(*(void **) (arg0 + 0x1bd0), 0, 0x960);
        func_ov002_0215ece4(arg0, *(char **) (arg0 + 0x1bd0), *(signed char *) (arg0 + 0x1c20), 0, 8);
        int var10 = 0;
        if ((short) ((*(unsigned char *) (arg0 + 0x2520) + 7) / 8) > 1) {
            var10 = 1;
        }
        char *var11 = func_0205d81c((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 0x11);
        if (var11 != 0) {
            func_ov002_0216574c(var11, var10);
        }
        Window_SetPaneText((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x11,
                                                             *(int *) (self + 0x1bd0), 1, 0);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (var9 != 1) {
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
        char *var14 = func_0205d81c((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 0x11);
        if (var14 != 0) {
            func_ov002_0216574c(var14, var13);
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
        if (IsFlagAt130Bit0Set_0216364c(
                GameState::GetInstance()->GetPartyMemberByIndex(*(signed char *) (self + 0x1c20))))
        {
            *(short *) (arg0 + 0x1c28) = 0x2332;
            *(short *) (arg0 + 0x1c2a) = -1;
            *(int *) (arg0 + 0x1bb8)   = 0x26;
            *(int *) (arg0 + 0x1bbc)   = 0x10;
            return;
        }
        if (*(unsigned char *) (arg0 + 0x2520) != 0) {
            *(int *) (arg0 + 0x1bb8) = 0x11;
            return;
        }
        *(short *) (arg0 + 0x1c28) = 0x232e;
        *(short *) (arg0 + 0x1c2a) = -1;
        *(int *) (arg0 + 0x1bb8)   = 0x26;
        *(int *) (arg0 + 0x1bbc)   = 0x10;
        return;
    }
    if (func_ov002_02161b48(arg0, 1)) {
        *(short *) (arg0 + 0x1bf8)       = -1;
        *(signed char *) (arg0 + 0x1c20) = -1;
        func_ov002_02156e90(arg0);
    }
}
#endif
