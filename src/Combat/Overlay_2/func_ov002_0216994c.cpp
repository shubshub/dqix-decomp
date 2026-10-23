#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#define RG(u, j) (j)
#define OBJ (arg0 + 0xe20)
#define APPLY(s, k, t) func_0205d5d0(s, k, t, 1)
#else
#define RG(u, j) (u)
#define OBJ (arg0 + 0x2c8 + 0xc00)
#define APPLY(s, k, t) func_0205d5d0(s, k, t, 1, 0)
#endif

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct SePlayer;
struct StructA0205d5d0;

extern "C" int func_ov002_0215a9f0(void *arg0);
extern "C" char *func_0205ec34();
short FindShortIndex0206e3e8(int unused, int key);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
void InitBattleTag021609d4(char *self);
extern "C" void func_ov002_02161b98(char *self);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" void func_ov002_0215bba8(char *self);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
int NextIndexOrZero_0215a9b4(void *self, short idx);
int GetShortFromTable0206e3d4(int a, int b);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void SePlayer_Play(struct SePlayer *obj, int a, int b);
void SetFieldByIndexedOffsetC7c_0215a9cc(void *self, int idx);
char *GetGlobalField0x1c020421a0();
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_ov002_021607cc(void *obj, void *ptr, int flag);
int TryApplyElemFields0205d5d0(struct StructA0205d5d0 *, int, int, int, unsigned char);
extern "C" void func_ov002_02156e90(void *obj);
int CheckFlagOrThreshold_02161b48(char *self, int v);

extern "C" char g_sePlayer;

struct Struct_ov002_0216994c {
    char unknown_0_[0x68];
    int unknown_68_;
};

// USA: func_ov002_0216994c
extern "C" ARM void func_ov002_0216994c(char *arg0) {
    int var0 = *(int *) (arg0 + RG(0x1bc0, 0x1a88));
    if (var0 == 0) {
        *(unsigned int *) (arg0 + RG(0x247c, 0x22ac)) &= ~4;
        int var1                    = func_ov002_0215a9f0(arg0);
        *(short *) (arg0 + RG(0x1c0c, 0x1ad4)) = func_0206e3e8((int) func_0205ec34(), var1) - 1;
        if (*(short *) (arg0 + RG(0x1c0c, 0x1ad4)) < 0) {
            *(short *) (arg0 + RG(0x1c0c, 0x1ad4)) = 0;
        }
        func_0205de24((struct Struct_ov002_0215624c_11 *) OBJ, 0, 3);
        func_ov002_02161cf0(arg0);
        func_ov002_021609d4(arg0);
        *(int *) (arg0 + RG(0x1bc0, 0x1a88)) += 1;
        return;
    }
    if (var0 != 1) {
        return;
    }
    *(unsigned int *) (self + 0x247c) |= 4;
    func_ov002_02161b98(self);
    *(short *) (self + 0x1c0c) =
        Window_GetSelectedIndex((struct Struct_0205c570 *) (self + 0x2c8 + 0xc00));
    struct Fld0216994c *l = (struct Fld0216994c *) (self + 0x2c8 + 0xc00) + 1;
    l--;
    int f = l->f68;
    if (*(unsigned char *) (self + 0x2484) != f) {
        func_ov002_0215bba8(self);
    }
    int a  = g_keyManager.TestKeysPressed(0x601);
    int b  = Window_IsSelectionTouched((struct Obj_0205da38*)(self + 0x2c8 + 0xc00), 0x14);
    int ok = (a | b) ? 1 : 0;
    if (ok) {
        int next = NextIndexOrZero_0215a9b4(self, *(short *) (self + 0x1c0c));
        int idx  = GetShortFromTable0206e3d4((int) func_0205ec34(), next);
        int one  = 1;
        int en   = one;
        if (idx >= 0 && *(short *) (self + 0x1c0c) != 0x1f) {
            en = 0;
            if (*(unsigned int *) (self + 0x2480) & (one << (idx - 1))) {
                en = one;
            }
        }
        if (!var10) {
            return;
        }
        *(unsigned int *) (arg0 + RG(0x247c, 0x22ac)) &= ~4;
        unsigned char *var11 = (unsigned char *) func_0205d81c(
            (struct Struct_ov002_02155960_2 *) OBJ, RG(0x21, 0x24));
        if (var11 == 0) {
            return;
        }
        SePlayer_Play((struct SePlayer *) &g_sePlayer, 1, 0);
        SetFieldByIndexedOffsetC7c_0215a9cc(self, idx);
        void *buf = *(void **) (GetGlobalField0x1c020421a0() + 0x5c);
        memset(buf, 0, 0x960);
        func_ov002_021607cc(self, buf, (elem[0xc5] & 2) ? 1 : 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x21,
                                                             (int) buf, 1, 0);
        func_ov002_02156e90(self);
        return;
    }
    if (func_ov002_02161b48(arg0, 1)) {
        *(unsigned int *) (arg0 + RG(0x247c, 0x22ac)) &= ~4;
        *(short *) (arg0 + RG(0x1c0c, 0x1ad4)) = 0;
        func_ov002_02156e90(arg0);
    }
}
