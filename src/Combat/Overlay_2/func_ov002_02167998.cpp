#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
#define data_ov002_0216cc98 data_ov002_0216d2b0
#define RG(u, j) (j)
#define OBJ (arg0 + 0xe20)
#else
#define RG(u, j) (u)
#define OBJ (arg0 + 0x2c8 + 0xc00)
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

struct Struct_ov002_02167998_3 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov002_02167998_4 {
    unsigned int unknown_0_0_ : 30;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
};

int GetField0x3acValue_020100a8(GameState *gs);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void GetFourShortsAtIndex(struct ShortArrays0204c610 *base, int index, short *out0, short *out1, short *out2, short *out3);
void SetFourShortsAtIndex(ShortArrays0204c654*, int, short, short, short, short);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
extern "C" void func_0205d7a0(unsigned char *obj, int val);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38 *obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *c);
extern "C" void func_ov002_02161cf0(void *self);
extern "C" void func_ov002_0215f6a4(void *self);
extern "C" void func_ov002_02161a8c(void);
extern "C" void func_ov002_021619b4(int arg0, int arg1, int arg2);
extern "C" void func_ov002_0215b9a4(void *arg0, int arg1, int arg2);
extern "C" void func_ov002_02156e90(void *arg0);

extern unsigned char data_ov002_0216cc98[];
extern char g_sePlayer[];

// USA: func_ov002_02167998
extern "C" ARM void func_ov002_02167998(char *arg0) {
    unsigned char *var0 = (unsigned char *) OBJ;
    int var1;
    short var2;
    int var3;
    int var4;
    GameState *var5 = GameState::GetInstance();
    int var6     = *(int *) (arg0 + RG(0x1bc0, 0x1a88));
    if (var6 == 0) {
#if !defined(jpn)
        arg0[0x1c34] = 0;
#endif
        for (int var7 = 0; var7 < 5; var7++) {
            func_0205def8((struct Struct_ov002_02155960_3 *) var0, 0, data_ov002_0216cc98[var7]);
        }
        arg0[RG(0x1c20, 0x1ae8)]               = func_020100a8(var5);
        *(short *) (arg0 + RG(0x1c02, 0x1aca)) = 0;
        func_0205de24((struct Struct_ov002_0215624c_11 *) var0, 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f6a4(arg0);
        (*(int *) (arg0 + RG(0x1bc0, 0x1a88)))++;
        func_ov002_02161a8c();
#if !defined(jpn)
        func_ov002_021619b4(*(signed char *) (arg0 + 0x1c20), *(int *) (arg0 + 0x1a68), *(int *) (arg0 + 0x1bd8));
#endif
        return;
    }
    if (var6 != 1) return;
    *(int *) (arg0 + RG(0x247c, 0x22ac)) |= 4;
    struct Struct_ov002_02155960_4 *var8 = func_0205d81c((struct Struct_ov002_02155960_2 *) var0, RG(0x18, 0x19));
    if (var8 != 0) {
        short var9 = *(signed char *) (arg0 + RG(0x1c73, 0x1b37));
        short var10, var11, var12, var13;
        func_0204c610((struct Struct_ov002_02167998 *) var8, var9, &var10, &var11, &var12, &var13);
        var9 += *(signed char *) (arg0 + RG(0x1c73, 0x1b37)) + 1;
        func_0204c654((struct Struct_ov002_02167998_2 *) var8, var9, var10, var11, var12, var13);
        var9 += *(signed char *) (arg0 + RG(0x1c73, 0x1b37)) + 1;
        func_0204c654((struct Struct_ov002_02167998_2 *) var8, var9, var10, var11, var12, var13);
    }
    int var14;
    int var15;
    short var16 = *(short *) (arg0 + RG(0x1c02, 0x1aca));
    var1         = var16 % (*(signed char *) (arg0 + RG(0x1c73, 0x1b37)) + 1);
    Struct_ov002_02167998_3 *var17 = (Struct_ov002_02167998_3 *) (var0 + 0x6c);
    var14        = var17->unknown_0_;
    var15         = var17->unknown_4_;
    *(short *) (arg0 + RG(0x1c02, 0x1aca)) = func_0205d794((struct Struct_ov002_0215624c_15 *) var0);
    if (var16 != *(short *) (arg0 + RG(0x1c02, 0x1aca))) {
        if (var1 == var15 && var15 == *(signed char *) (arg0 + RG(0x1c73, 0x1b37)) && g_touchInput.pressed_ == 0) {
            var15--;
            var2 = var14 * (*(signed char *) (arg0 + RG(0x1c73, 0x1b37)) + 1) + var15;
            func_0205d7a0(var0, var2);
            *(short *) (arg0 + RG(0x1c02, 0x1aca)) = var2;
        }
        arg0[RG(0x1c20, 0x1ae8)] = -1;
        if (var15 < *(signed char *) (arg0 + RG(0x1c73, 0x1b37))) {
            arg0[RG(0x1c20, 0x1ae8)] = *(signed char *) (arg0 + var15 + RG(0x1c6e, 0x1b32));
        }
#if defined(jpn)
        func_ov002_0215b9a4(arg0, 0x1b, 0);
        func_ov002_0215b9a4(arg0, 0x1c, 0);
#else
        arg0[0x1c34] = 1;
#endif
    }
    last  = sel == *(signed char *) (base + 0x1c73);
    shown = !last;
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) obj, shown, 0x1a);
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) obj, shown, 0x1b);
    if (old != *(short *) (base + 0x1c02)) return;
    int pressed = g_keyManager.TestKeysPressed(0x601);
    int confirm = (pressed | IsActiveElementFlag2Set0205da38((struct Obj_0205da38 *) (base + 0x2c8 + 0xc00), 0x14)) ? 1 : 0;
    if (confirm) {
        if (sel == *(signed char *) (base + 0x1c73)) {
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            for (int i = 0; i < 5; i++) {
                SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) obj, 1, data_ov002_0216cc98[i]);
            }
            *(short *) (arg0 + RG(0x1c02, 0x1aca)) = -1;
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            return;
        }
        int var21       = *(signed char *) (arg0 + RG(0x1c20, 0x1ae8));
        unsigned char *var22 = (unsigned char *)var5->GetPartyMemberByIndex(var21);
        if (var22 == 0) return;
        switch (var14) {
        case 0:
            if (member == GetField0x3acValue_020100a8(gs)) return;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1bb8) & 0xff, 1);
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + 0x1bb8)   = 0x19;
            *(int *) (base + 0x1bc0)   = 0;
            *(short *) (base + 0x1c04) = (signed char) *(int *) (GetFieldAt0x150_02053c6c(m) + 0x94c);
            break;
        case 1: {
            struct Flags3c *f = (struct Flags3c *) (*(unsigned char **) (m + 0x134) + 0x3c);
            unsigned short t = f->toggle;
            t++;
            t %= 2;
            f->toggle = t;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1bb8) & 0xff, 0);
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            break;
        }
        case 2: {
            unsigned char *f = GetFieldAt0x150_02053c6c(m);
            obj[0xb8]        = *(int *) (base + 0x1bb8);
            *(int *) (base + 0x247c) &= ~4;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + 0x1bb8)   = 0x1c;
            *(int *) (base + 0x1bc0)   = 0;
            *(short *) (base + 0x1c06) = f[0x56a];
            break;
        }
        }
        return;
    }
    if (func_ov002_02161b48(arg0, 1)) {
        for (int var26 = 0; var26 < 5; var26++) {
            func_0205def8((struct Struct_ov002_02155960_3 *) var0, 1, data_ov002_0216cc98[var26]);
        }
        *(short *) (arg0 + RG(0x1c02, 0x1aca)) = -1;
        func_ov002_02156e90(arg0);
        func_ov002_02156e90(arg0);
        func_ov002_02156e90(arg0);
    }
}
