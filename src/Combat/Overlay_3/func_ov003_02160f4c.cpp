#include "GameState/GameState.h"

struct Struct_020465c0;
struct Struct_02046574_2;
struct Struct_0201099c_3;
struct Struct_020444bc;

struct Struct_ov003_02160f4c {
    unsigned char unknown_0_0_ : 1;
};

void *GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void *messages);
void *GetPtrField0x2a04_02010828(GameState *gameState);
void StoreInArray0x8b0_020465c0(StoreStruct *base, int index, int value);
extern "C" void *__clear(void *destination, int count);
void SetIndexedName02046574(Obj02046574 *obj, int index, char *str);
void *KeyTable_Get(Container020e0310 *c, int key);
void InitObjFromCombatantId020e4bf4(void *obj, int combatantId);
extern "C" void *func_ov003_02160bf8(void *obj, int key);
extern "C" void func_02042764(void *src, void *dst, int flag);
extern "C" void func_020e4b34(void *, const char *, void *, unsigned int, unsigned char, unsigned char, unsigned char,
                              unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
#if !defined(jpn)
extern "C" void func_0204500c(void *arg0, void *arg1, int arg2, int arg3);
#endif
extern "C" void func_020444bc(Struct_020444bc *arg0);
extern "C" void func_02043204(char *arg0);
extern "C" void func_02043124(char *arg0);
extern "C" void func_ov003_02166f80(void *arg0, int arg1, int arg2);

// USA: func_ov003_02160f4c
#if defined(jpn)
extern "C" void func_0204500c(void *arg0, void *arg1, int arg2);
extern "C" ARM void func_ov003_02160f4c(unsigned char *arg0) {
    unsigned char *var0 = (unsigned char *) func_020421a0();

    if (arg0[0x2cd] == 0) {
        func_02046380(var0);
        if (*(unsigned int *) (arg0 + 0x28c) & 4) {
            unsigned char *var1 = arg0 + *(short *) (arg0 + 0x200 + 0xc0) * 0x1b;
            if ((signed char) var1[1] != 0) {
                func_02046574((Struct_02046574_2 *) var0, 0, (char *) (var1 + 1));
            } else {
                SetIndexedName02046574(
                    (Obj02046574 *) ctl, 0,
                    (char *) KeyTable_Get((Container020e0310 *) (self + 0x1c4), 0x7530));
            }
            *(unsigned int *) (arg0 + 0x28c) &= ~4u;
        }
        if (*(unsigned int *) (arg0 + 0x28c) & 0x10) {
            char *var2 = (char *) func_0200ff1c(GameState::GetInstance(), *(short *) (arg0 + 0x200 + 0xaa));
            if (var2 != 0) {
                func_02046574((Struct_02046574_2 *) var0, 0, *(char **) (var2 + 0x134));
            }
            *(unsigned int *) (arg0 + 0x28c) &= ~0x10u;
            if (*(short *) (arg0 + 0x200 + 0xac) == 0x54) {
                *(unsigned int *) (arg0 + 0x28c) |= 0x10;
            }
        } else if ((*(unsigned int *) (arg0 + 0x28c) & 0x28) || *(short *) (arg0 + 0x200 + 0xac) == 0xe) {
            unsigned char *var3 = (unsigned char *) func_ov003_02160bf8(arg0, *(short *) (arg0 + 0x200 + 0xa8));
            if (var3 != 0) {
                func_02046574((Struct_02046574_2 *) var0, 0, (char *) (var3 + 0x140));
            }
            *(unsigned int *) (arg0 + 0x28c) &= ~0x28u;
        }
        short v            = *(short *) (self + 0x200 + 0xac);
        unsigned char flag = 1;
        if (v == 8 || v == 0x3d) flag = 0;
        void *key = KeyTable_Get((Container020e0310 *) (self + 0x1c4), v);
        if (key == 0) {
            *(short *) (self + 0x200 + 0xac) = *(short *) (self + 0x200 + 0xae);
            *(short *) (self + 0x200 + 0xae) = -1;
            key = KeyTable_Get((Container020e0310 *) (self + 0x1c4),
                                                                 *(short *) (self + 0x200 + 0xac));
        }
        func_0204500c(var0, var6, 0);
        *(int *) (var0 + 0x868) = 1;
        *(int *) (var0 + 0x86c) = 2;
        var0[0x1000 + 0x7fb]    = var5;
        arg0[0x2cd]++;
        if (*(unsigned int *) (arg0 + 0x28c) & 0x4000) {
            arg0[0x2ce] = 0;
        }
        if (*(unsigned int *) (arg0 + 0x28c) & 0x4000000) {
            var0[0x1000 + 0x7fb] = 0;
            *(unsigned int *) (arg0 + 0x28c) &= ~0x4000000u;
        }
        if (*(unsigned int *) (arg0 + 0x28c) & 0x8000000) {
            var0[0x1000 + 0x7ff] |= 0x20;
            *(unsigned int *) (arg0 + 0x28c) &= ~0x8000000u;
        }
    } else if (arg0[0x2cd] == 1) {
        if (*(int *) (var0 + 0x870) == 2 && (*(unsigned int *) (arg0 + 0x28c) & 0x4000) && ++arg0[0x2ce] > 0x3c) {
            func_020444bc((Struct_020444bc *) var0);
        }
        if (*(int *) (var0 + 0x868) == 0) {
            *(short *) (arg0 + 0x200 + 0xac) = *(short *) (arg0 + 0x200 + 0xae);
            *(short *) (arg0 + 0x200 + 0xae) = -1;
            arg0[0x2cb]                      = 0x10;
            arg0[0x2cd]                      = 0;
        } else if (*(int *) (var0 + 0x870) == 3) {
            *(short *) (arg0 + 0x200 + 0xac) = *(short *) (arg0 + 0x200 + 0xae);
            *(short *) (arg0 + 0x200 + 0xae) = -1;
            if (*(short *) (arg0 + 0x200 + 0xac) < 0) {
                if (*(unsigned int *) (arg0 + 0x28c) & 2) {
                    func_02043204((char *) var0);
                    func_02043124((char *) var0);
                    *(unsigned int *) (arg0 + 0x28c) &= ~2u;
                }
                if (*(unsigned int *) (arg0 + 0x28c) & 0x2000) {
                    *(unsigned int *) (arg0 + 0x28c) &= ~0x2000u;
                    func_ov003_02166f80(arg0, *(short *) (arg0 + 0x200 + 0xb0), 0);
                }
            }
            arg0[0x2cd] = 0;
        }
    }
}
#else
extern "C" ARM void func_ov003_02160f4c(unsigned char *arg0) {
    unsigned char *var7 = (unsigned char *) func_020421a0();
    char var8[0x30];
    char var9[0xc];

    if (arg0[0x4a5] == 0) {
        func_02046380(var7);
        GameState *var10    = GameState::GetInstance();
        unsigned char *var11 = (unsigned char *) func_02010828(var10);
        func_020465c0((Struct_020465c0 *) var7, 0, var11[0xf7c] - 1);
        __clear(var8, 0x30);
        if (*(unsigned int *) (arg0 + 0x464) & 4) {
            unsigned char *var12 = arg0 + *(short *) (arg0 + 0x400 + 0x98) * 0x37;
            if ((signed char) var12[1] != 0) {
                func_02046574((Struct_02046574_2 *) var7, 0, (char *) (var12 + 1));
            } else {
                SetIndexedName02046574(
                    (Obj02046574 *) ctl, 0,
                    (char *) KeyTable_Get((Container020e0310 *) (self + 0x2dc), 0x7530));
            }
            *(unsigned int *) (arg0 + 0x464) &= ~4u;
        }
        if (*(unsigned int *) (arg0 + 0x464) & 0x10) {
            func_020e4bf4(var9, *(short *) (arg0 + 0x400 + 0x82));
            *(void **) (var7 + 0x10) = var9;
            *(unsigned int *) (arg0 + 0x464) &= ~0x10u;
            if (*(short *) (arg0 + 0x400 + 0x84) == 0x54 || *(short *) (arg0 + 0x400 + 0x84) == 0x55) {
                *(unsigned int *) (arg0 + 0x464) |= 0x10;
            }
        } else if ((*(unsigned int *) (arg0 + 0x464) & 0x28) || *(short *) (arg0 + 0x400 + 0x84) == 0xe) {
            unsigned char *var13 = (unsigned char *) func_ov003_02160bf8(arg0, *(short *) (arg0 + 0x400 + 0x80));
            if (var13 != 0) {
                func_02042764(var13 + 0x140, var8, 1);
                func_020e4b34(var9, var8, 0, 0, 0, 0, 0, ((Struct_ov003_02160f4c *) (var13 + 0x174))->unknown_0_0_, 0, 1, 0, 1);
                *(void **) (var7 + 0x10) = var9;
            }
            *(unsigned int *) (arg0 + 0x464) &= ~0x28u;
        }
        short v            = *(short *) (self + 0x400 + 0x84);
        unsigned char flag = 1;
        if (v == 8 || v == 0x3d) flag = 0;
        void *key = KeyTable_Get((Container020e0310 *) (self + 0x2dc), v);
        if (key == 0) {
            *(short *) (self + 0x400 + 0x84) = *(short *) (self + 0x400 + 0x86);
            *(short *) (self + 0x400 + 0x86) = -1;
            key = KeyTable_Get((Container020e0310 *) (self + 0x2dc),
                                                                 *(short *) (self + 0x400 + 0x84));
        }
        func_0204500c(var7, var16, 0, 0xe3);
        *(int *) (var7 + 0x998) = 1;
        *(int *) (var7 + 0x99c) = 2;
        var7[0x1000 + 0x9ca]    = var15;
        arg0[0x4a5]++;
        if (*(unsigned int *) (arg0 + 0x464) & 0x4000) {
            arg0[0x4a6] = 0;
        }
        if (*(unsigned int *) (arg0 + 0x464) & 0x4000000) {
            var7[0x1000 + 0x9ca] = 0;
            *(unsigned int *) (arg0 + 0x464) &= ~0x4000000u;
        }
        if (*(unsigned int *) (arg0 + 0x464) & 0x8000000) {
            var7[0x1000 + 0x9d3] = 1;
            *(unsigned int *) (arg0 + 0x464) &= ~0x8000000u;
        }
    } else if (arg0[0x4a5] == 1) {
        if (*(int *) (var7 + 0x9a0) == 2 && (*(unsigned int *) (arg0 + 0x464) & 0x4000) && ++arg0[0x4a6] > 0x3c) {
            func_020444bc((Struct_020444bc *) var7);
        }
        if (*(int *) (var7 + 0x998) == 0) {
            *(short *) (arg0 + 0x400 + 0x84) = *(short *) (arg0 + 0x400 + 0x86);
            *(short *) (arg0 + 0x400 + 0x86) = -1;
            arg0[0x4a3]                      = 0x10;
            arg0[0x4a5]                      = 0;
        } else if (*(int *) (var7 + 0x9a0) == 3) {
            *(short *) (arg0 + 0x400 + 0x84) = *(short *) (arg0 + 0x400 + 0x86);
            *(short *) (arg0 + 0x400 + 0x86) = -1;
            if (*(short *) (arg0 + 0x400 + 0x84) < 0) {
                if (*(unsigned int *) (arg0 + 0x464) & 2) {
                    func_02043204((char *) var7);
                    func_02043124((char *) var7);
                    *(unsigned int *) (arg0 + 0x464) &= ~2u;
                }
                if (*(unsigned int *) (arg0 + 0x464) & 0x2000) {
                    *(unsigned int *) (arg0 + 0x464) &= ~0x2000u;
                    func_ov003_02166f80(arg0, *(short *) (arg0 + 0x400 + 0x88), 0);
                }
            }
            arg0[0x4a5] = 0;
        }
    }
}
#endif
