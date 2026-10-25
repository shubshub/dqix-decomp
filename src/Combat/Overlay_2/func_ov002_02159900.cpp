#include "GameState/GameState.h"
#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define func_020dcf7c func_020de968
extern "C" void func_020de968(int arg0, void *arg1);
extern "C" void func_020474a8(void *arg0, int arg1, const char *arg2, char *arg3);
#else
#define REGION_LAYOUT(j,u) u
#endif

struct ItemTable;
struct Container020e0310;
struct Obj02046574;
struct StoreStruct;
void *GetData02153637_020e2ff8(void);
void Dispatch020e3428(void *a, int b);
int MessageSystem_GetInstance(void);
char *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_02046380(void *g);
void *Clear12Bytes020e46c4(void *p);
void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
void NameText_InitFromPartyMember(void *obj, int combatantId);
extern "C" void __clear(void *buf, int n);
#if !defined(jpn)
extern "C" void func_020dcf7c(int arg0, void *arg1);
#endif
void SetByteInRange_020465f0(unsigned char *base, int index, unsigned char value);
void StoreInArray0x8b0_020465c0(struct StoreStruct *base, int index, int value);
int KeyTable_Get(struct Container020e0310 *c, int key);
int Text_Append(char *dst, const char *src);
extern "C" void MessageSystem_FormatText(void *a, int b, int c, void *d, int e, int f, int g);
extern "C" void func_ov016_0218b5c0(int a, int b);

struct Struct_ov002_02159900 {
    char *unknown_0_;
    char *unknown_4_;
    int unknown_8_;
};

#define TXT(k) KeyTable_Get((struct Container020e0310 *) (base + REGION_LAYOUT(8, 0x20)), (k))
#define BD0 (*(char **) (base + REGION_LAYOUT(0x1a98, 0x1000 + 0xbd0)))

// USA: func_ov002_02159900
extern "C" ARM void func_ov002_02159900(char *base, char *arr, int any) {
    Dispatch020e3428(GetData02153637_020e2ff8(), 1);
    GameState *gs      = GameState::GetInstance();
    char *g            = (char *) MessageSystem_GetInstance();
    unsigned char *ent = (unsigned char *) (arr + 8);
    char *e            = ItemTable_Find((struct ItemTable *) (base + REGION_LAYOUT(0x750, 0x3ec + 0x400)),
                                                                           *(short *) (base + REGION_LAYOUT(0x1aea, 0x1c00 + 0x22)));
    if (e == NULL) return;
#if defined(jpn)
    memset(*(void **) (base + 0x1a98), 0, 0x800);
    memset(*(void **) (base + 0x1a9c), 0, 0x800);
    func_02046380(g);
    char *out = *(char **) (base + 0x1a98);
    char *m   = (char *)GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (arr + 2));
    if (m != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 0, *(char **) (m + 0x134));
    }
    char names[0x40];
    __clear(names, 0x40);
    DispatchIfCountPositive020dcf7c(*(short *) (e + 0x18), names);
    MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, names);
    char *m2 = (char *)GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (arr + 4));
    if (m2 != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (m2 + 0x134));
        SetByteInRange_020465f0((unsigned char *) g, 9, 0);
        StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 9, *(short *) (m2 + 4));
    }
#else
    memset(*(void **) (base + 0x1000 + 0xbd0), 0, 0x960);
    memset(*(void **) (base + 0x1000 + 0xbd4), 0, 0x960);
    func_02046380(g);
    Clear12Bytes020e46c4(base + 8);
    Clear12Bytes020e46c4(base + 0x14);
    char *out = *(char **) (base + 0x1000 + 0xbd0);
    char *m   = (char *)GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (arr + 2));
    if (m != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 0, *(char **) (m + 0x134));
        NameText_InitFromPartyMember(base + 8, *(signed char *) (arr + 2));
        *(char **) g = base + 8;
    }
    struct Names9900 nm;
    char buf1[0x80];
    char buf2[0x80];
    Clear12Bytes020e46c4(&nm);
    __clear(buf1, 0x80);
    __clear(buf2, 0x80);
    nm.a = buf1;
    nm.b = buf2;
    DispatchIfCountPositive020dcf7c(*(short *) (e + 0x18), &nm);
    *(struct Names9900 **) (g + 0x18) = &nm;
    MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, nm.a);
    char *m2 = (char *)GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (arr + 4));
    if (m2 != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (m2 + 0x134));
        NameText_InitFromPartyMember(base + 0x14, *(signed char *) (arr + 4));
        *(char **) (g + 0x10) = base + 0x14;
        SetByteInRange_020465f0((unsigned char *) g, 9, 0);
        StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 9, *(short *) (m2 + 4));
    }
#endif
    int var14              = 0x7918;
    int var15              = 0x7919;
    unsigned char var16 = 0;
    switch ((*(unsigned int *) (var3 + 8) << 1) >> 27) {
        case 2:
            var14 = 0x7922;
            var15 = 0x7923;
            break;
        case 3:
            if (var2[0] == 3) {
                var14 = 0x792c;
                var15 = 0x7941;
            } else {
                var14 = 0x7936;
            }
            break;
        case 4:
            if (var2[0] == 3) {
                var14 = 0x792c;
                var15 = 0x794b;
            } else {
                var14 = 0x7936;
            }
            break;
        case 5:
            if (any) {
                done = 1;
                Text_Append(BD0, (const char *) TXT(0x792c));
                if (ent[0] == 3) {
                    Text_Append(BD0, (const char *) TXT(8));
                    Text_Append(BD0, (const char *) TXT(0x7941));
                }
                if (*(unsigned char *) (arr + 0x20) == 3) {
                    Text_Append(BD0, (const char *) TXT(8));
                    Text_Append(BD0, (const char *) TXT(0x794b));
                }
            } else {
                var14 = 0x7936;
            }
            break;
        case 6:
            if (var2[0] == 3) {
                *(signed char *) (arg0 + REGION_LAYOUT(0x1ae8, 0x1000 + 0xc20))   = *(signed char *) (arg1 + 2);
                *(short *) (arg0 + REGION_LAYOUT(0x1af0, 0x1c00 + 0x28))          = 0x792c;
                *(short *) (arg0 + REGION_LAYOUT(0x1af2, 0x1c00 + 0x2a))          = var16 - 1;
                *(short *) (arg0 + REGION_LAYOUT(0x22b8, 0x2400 + 0x88))          = 0x7955;
                *(unsigned char *) (arg0 + REGION_LAYOUT(0x22ba, 0x2000 + 0x48a)) = 1;
                return;
            }
            var14 = 0x7936;
            break;
        case 7:
            if (arg2) {
                var16 = 1;
#if defined(jpn)
                func_020474a8(g, 0xc, (const char *) TXT(0x792c), out + 0x700);
                Text_Append(BD0, out + 0x700);
#else
                MessageSystem_FormatText(g, 0xc, TXT(0x792c), out + 0x860, 0xe3, 0, 1);
                Text_Append(BD0, out + 0x860);
#endif
                int var17;
                for (var17 = 0; var17 < *(unsigned char *) (arg1 + 3); var17++) {
                    if (var2[var17 * 6] == 3) {
                        var15 = 0x7941;
                    } else {
                        var15 = 0x233a;
                    }
                    if (var15 >= 0) {
                        int var18 = *(signed char *) (arg1 + var17 + 4);
                        char *var19 = (char *)func_0200ff1c(var0, var18);
                        if (var19 != NULL) {
                            func_02046380(var1);
#if defined(jpn)
                            MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (c + 0x134));
                            StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 9, cid);
                            func_020474a8(g, 0xc, (const char *) TXT(b), out + 0x700);
                            Text_Append(BD0, (const char *) TXT(8));
                            Text_Append(BD0, out + 0x700);
#else
                            MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (c + 0x134));
                            NameText_InitFromPartyMember(base + 0x14, cid);
                            *(char **) (g + 0x10) = base + 0x14;
                            StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 9, cid);
                            MessageSystem_FormatText(g, 0xc, TXT(b), out + 0x860, 0xe3, 0, 1);
                            Text_Append(BD0, (const char *) TXT(8));
                            Text_Append(BD0, out + 0x860);
#endif
                        }
                    }
                }
            } else {
                func_ov016_0218b5c0(1, -1);
                var14 = 0x7936;
                var15 = 0x7919;
            }
            break;
        case 8:
            if (var2[0] != 3) {
                var14 = 0x7936;
                break;
            }
            func_020465f0((unsigned char *) var1, var16, var16);
            func_020465c0((struct Struct_020465c0 *) var1, 0, *(short *) (var2 + 2));
            var14 = 0x792c;
            var15 = 0x795f;
            break;
        case 9:
            var14 = 0x7968;
            if (var2[0] == 3) var15 = 0x7969;
            break;
        case 12:
            var14 = 0x7986;
            var15 = 0x7987;
            break;
        case 13:
            if (var2[0] == 3) {
                func_020465f0((unsigned char *) var1, var16, var16);
                func_020465c0((struct Struct_020465c0 *) var1, 0, *(short *) (var2 + 2));
                int var20 = -1;
                switch (*(short *) (var3 + 0x18)) {
                    case 0x561d: var20 = 0x7991; break;
                    case 0x561e: var20 = 0x7992; break;
                    case 0x561f: var20 = 0x7993; break;
                    case 0x5620: var20 = 0x7994; break;
                    case 0x5621: var20 = 0x7995; break;
                    case 0x5622: var20 = 0x7996; break;
                    case 0x5623: var20 = 0x7998; break;
                    case 0x5624: var20 = 0x7999; break;
                    case 0x5619: var20 = 0x7997; break;
                }
                MessageSystem_SetStringArgument((struct Obj02046574 *) g, 5, (char *) TXT(k));
                a = 0x792c;
                b = 0x7990;
            } else {
                var14 = 0x7936;
            }
            break;
        case 14:
            if (var2[0] != 3) {
                var14 = 0x7936;
                break;
            }
            func_020465f0((unsigned char *) var1, var16, var16);
            func_020465c0((struct Struct_020465c0 *) var1, 0, *(short *) (var2 + 2));
            var14 = 0x792c;
            var15 = 0x799b;
            break;
        case 15:
            var14 = 0x79a4;
            var15 = 0x79a5;
            break;
        case 16:
            var14 = 0x79ae;
            var15 = 0x79af;
            break;
        case 17:
            var14 = 0x79b8;
            var15 = 0x79b9;
            break;
        case 18:
            var14 = 0x79c2;
            var15 = 0x79c3;
            break;
        case 19:
            var14 = 0x79cc;
            var15 = 0x79cd;
            break;
        case 20:
            var14 = 0x79d6;
            var15 = 0x79d7;
            break;
        case 21:
            var14 = 0x79e0;
            var15 = 0x79e1;
            break;
    }
    if (!done) {
        Text_Append(BD0, (const char *) TXT(a));
        Text_Append(BD0, (const char *) TXT(8));
        Text_Append(BD0, (const char *) TXT(b));
    }
#if defined(jpn)
    func_020474a8(var1, 0xc, *(const char **) (arg0 + 0x1a98), *(char **) (arg0 + 0x1a9c));
    *(unsigned char *) (arg0 + 0x1af9) = 1;
    *(short *) (arg0 + 0x22b8)          = -1;
    *(unsigned char *) (arg0 + 0x22ba) = 0;
#else
    MessageSystem_FormatText(g, 0xc, *(int *) (base + 0x1000 + 0xbd0), *(void **) (base + 0x1000 + 0xbd4), 0xe3, 0, 1);
    *(unsigned char *) (base + 0x1000 + 0xc31) = 1;
    *(short *) (base + 0x2400 + 0x88)          = -1;
    *(unsigned char *) (base + 0x2000 + 0x48a) = 0;
#endif
}
