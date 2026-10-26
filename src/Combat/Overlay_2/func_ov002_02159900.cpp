#include "GameState/GameState.h"
#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define func_020dcf7c func_020de968
extern "C" void func_020de968(int count, void *buf);
extern "C" void func_020474a8(void *g, int kind, const char *text, char *out);
#else
#define REGION_LAYOUT(j,u) u
#endif

struct ItemTable;
struct Container020e0310;
struct Obj02046574;
struct StoreStruct;
extern "C" void *func_020e2ff8(void);
extern "C" void func_020e3428(void *a, int b);
extern "C" int MessageSystem_GetInstance(void);
extern "C" char *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_02046380(void *g);
extern "C" void *NameText_Clear(void *p);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
extern "C" void NameText_InitFromPartyMember(void *obj, int combatantId);
extern "C" void __clear(void *buf, int n);
#if !defined(jpn)
extern "C" void func_020dcf7c(int count, void *buf);
#endif
extern "C" void func_020465f0(unsigned char *base, int index, unsigned char value);
extern "C" void func_020465c0(struct StoreStruct *base, int index, int value);
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" void MessageSystem_FormatText(void *a, int b, int c, void *d, int e, int f, int g);
extern "C" void func_ov016_0218b5c0(int a, int b);

struct Struct_ov002_02159900 {
    char *a;
    char *b;
    int c;
};

#define TXT(k) KeyTable_Get((struct Container020e0310 *) (base + REGION_LAYOUT(8, 0x20)), (k))
#define BD0 (*(char **) (base + REGION_LAYOUT(0x1a98, 0x1000 + 0xbd0)))

// USA: func_ov002_02159900
extern "C" ARM void func_ov002_02159900(char *base, char *arr, int any) {
    func_020e3428(func_020e2ff8(), 1);
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
    char *m   = (char *)func_0200ff1c(gs, *(signed char *) (arr + 2));
    if (m != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 0, *(char **) (m + 0x134));
    }
    char names[0x40];
    __clear(names, 0x40);
    func_020dcf7c(*(short *) (e + 0x18), names);
    MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, names);
    char *m2 = (char *)func_0200ff1c(gs, *(signed char *) (arr + 4));
    if (m2 != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (m2 + 0x134));
        func_020465f0((unsigned char *) g, 9, 0);
        func_020465c0((struct StoreStruct *) g, 9, *(short *) (m2 + 4));
    }
#else
    memset(*(void **) (base + 0x1000 + 0xbd0), 0, 0x960);
    memset(*(void **) (base + 0x1000 + 0xbd4), 0, 0x960);
    func_02046380(g);
    NameText_Clear(base + 8);
    NameText_Clear(base + 0x14);
    char *out = *(char **) (base + 0x1000 + 0xbd0);
    char *m   = (char *)func_0200ff1c(gs, *(signed char *) (arr + 2));
    if (m != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 0, *(char **) (m + 0x134));
        NameText_InitFromPartyMember(base + 8, *(signed char *) (arr + 2));
        *(char **) g = base + 8;
    }
    struct Struct_ov002_02159900 nm;
    char buf1[0x80];
    char buf2[0x80];
    NameText_Clear(&nm);
    __clear(buf1, 0x80);
    __clear(buf2, 0x80);
    nm.a = buf1;
    nm.b = buf2;
    func_020dcf7c(*(short *) (e + 0x18), &nm);
    *(struct Struct_ov002_02159900 **) (g + 0x18) = &nm;
    MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, nm.a);
    char *m2 = (char *)func_0200ff1c(gs, *(signed char *) (arr + 4));
    if (m2 != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (m2 + 0x134));
        NameText_InitFromPartyMember(base + 0x14, *(signed char *) (arr + 4));
        *(char **) (g + 0x10) = base + 0x14;
        func_020465f0((unsigned char *) g, 9, 0);
        func_020465c0((struct StoreStruct *) g, 9, *(short *) (m2 + 4));
    }
#endif
    int a              = 0x7918;
    int b              = 0x7919;
    unsigned char done = 0;
    switch ((*(unsigned int *) (e + 8) << 1) >> 27) {
        case 2:
            a = 0x7922;
            b = 0x7923;
            break;
        case 3:
            if (ent[0] == 3) {
                a = 0x792c;
                b = 0x7941;
            } else {
                a = 0x7936;
            }
            break;
        case 4:
            if (ent[0] == 3) {
                a = 0x792c;
                b = 0x794b;
            } else {
                a = 0x7936;
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
                a = 0x7936;
            }
            break;
        case 6:
            if (ent[0] == 3) {
                *(signed char *) (base + REGION_LAYOUT(0x1ae8, 0x1000 + 0xc20))   = *(signed char *) (arr + 2);
                *(short *) (base + REGION_LAYOUT(0x1af0, 0x1c00 + 0x28))          = 0x792c;
                *(short *) (base + REGION_LAYOUT(0x1af2, 0x1c00 + 0x2a))          = done - 1;
                *(short *) (base + REGION_LAYOUT(0x22b8, 0x2400 + 0x88))          = 0x7955;
                *(unsigned char *) (base + REGION_LAYOUT(0x22ba, 0x2000 + 0x48a)) = 1;
                return;
            }
            a = 0x7936;
            break;
        case 7:
            if (any) {
                done = 1;
#if defined(jpn)
                func_020474a8(g, 0xc, (const char *) TXT(0x792c), out + 0x700);
                Text_Append(BD0, out + 0x700);
#else
                MessageSystem_FormatText(g, 0xc, TXT(0x792c), out + 0x860, 0xe3, 0, 1);
                Text_Append(BD0, out + 0x860);
#endif
                int i;
                for (i = 0; i < *(unsigned char *) (arr + 3); i++) {
                    if (ent[i * 6] == 3) {
                        b = 0x7941;
                    } else {
                        b = 0x233a;
                    }
                    if (b >= 0) {
                        int cid = *(signed char *) (arr + i + 4);
                        char *c = (char *)func_0200ff1c(gs, cid);
                        if (c != NULL) {
                            func_02046380(g);
#if defined(jpn)
                            MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (c + 0x134));
                            func_020465c0((struct StoreStruct *) g, 9, cid);
                            func_020474a8(g, 0xc, (const char *) TXT(b), out + 0x700);
                            Text_Append(BD0, (const char *) TXT(8));
                            Text_Append(BD0, out + 0x700);
#else
                            MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, *(char **) (c + 0x134));
                            NameText_InitFromPartyMember(base + 0x14, cid);
                            *(char **) (g + 0x10) = base + 0x14;
                            func_020465c0((struct StoreStruct *) g, 9, cid);
                            MessageSystem_FormatText(g, 0xc, TXT(b), out + 0x860, 0xe3, 0, 1);
                            Text_Append(BD0, (const char *) TXT(8));
                            Text_Append(BD0, out + 0x860);
#endif
                        }
                    }
                }
            } else {
                func_ov016_0218b5c0(1, -1);
                a = 0x7936;
                b = 0x7919;
            }
            break;
        case 8:
            if (ent[0] != 3) {
                a = 0x7936;
                break;
            }
            func_020465f0((unsigned char *) g, done, done);
            func_020465c0((struct StoreStruct *) g, 0, *(short *) (ent + 2));
            a = 0x792c;
            b = 0x795f;
            break;
        case 9:
            a = 0x7968;
            if (ent[0] == 3) b = 0x7969;
            break;
        case 12:
            a = 0x7986;
            b = 0x7987;
            break;
        case 13:
            if (ent[0] == 3) {
                func_020465f0((unsigned char *) g, done, done);
                func_020465c0((struct StoreStruct *) g, 0, *(short *) (ent + 2));
                int k = -1;
                switch (*(short *) (e + 0x18)) {
                    case 0x561d: k = 0x7991; break;
                    case 0x561e: k = 0x7992; break;
                    case 0x561f: k = 0x7993; break;
                    case 0x5620: k = 0x7994; break;
                    case 0x5621: k = 0x7995; break;
                    case 0x5622: k = 0x7996; break;
                    case 0x5623: k = 0x7998; break;
                    case 0x5624: k = 0x7999; break;
                    case 0x5619: k = 0x7997; break;
                }
                MessageSystem_SetStringArgument((struct Obj02046574 *) g, 5, (char *) TXT(k));
                a = 0x792c;
                b = 0x7990;
            } else {
                a = 0x7936;
            }
            break;
        case 14:
            if (ent[0] != 3) {
                a = 0x7936;
                break;
            }
            func_020465f0((unsigned char *) g, done, done);
            func_020465c0((struct StoreStruct *) g, 0, *(short *) (ent + 2));
            a = 0x792c;
            b = 0x799b;
            break;
        case 15:
            a = 0x79a4;
            b = 0x79a5;
            break;
        case 16:
            a = 0x79ae;
            b = 0x79af;
            break;
        case 17:
            a = 0x79b8;
            b = 0x79b9;
            break;
        case 18:
            a = 0x79c2;
            b = 0x79c3;
            break;
        case 19:
            a = 0x79cc;
            b = 0x79cd;
            break;
        case 20:
            a = 0x79d6;
            b = 0x79d7;
            break;
        case 21:
            a = 0x79e0;
            b = 0x79e1;
            break;
    }
    if (!done) {
        Text_Append(BD0, (const char *) TXT(a));
        Text_Append(BD0, (const char *) TXT(8));
        Text_Append(BD0, (const char *) TXT(b));
    }
#if defined(jpn)
    func_020474a8(g, 0xc, *(const char **) (base + 0x1a98), *(char **) (base + 0x1a9c));
    *(unsigned char *) (base + 0x1af9) = 1;
    *(short *) (base + 0x22b8)          = -1;
    *(unsigned char *) (base + 0x22ba) = 0;
#else
    MessageSystem_FormatText(g, 0xc, *(int *) (base + 0x1000 + 0xbd0), *(void **) (base + 0x1000 + 0xbd4), 0xe3, 0, 1);
    *(unsigned char *) (base + 0x1000 + 0xc31) = 1;
    *(short *) (base + 0x2400 + 0x88)          = -1;
    *(unsigned char *) (base + 0x2000 + 0x48a) = 0;
#endif
}
