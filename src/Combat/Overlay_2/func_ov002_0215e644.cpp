#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Obj02046574;
struct StoreStruct;
struct Container020e0310;
char *GetGlobalField0x1c020421a0();
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *gameState, int combatantId);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
void SetIndexedName02046574(struct Obj02046574 *obj, int index, char *str);
void StoreInArray0x8b0_020465c0(struct StoreStruct *base, int index, int value);
int KeyTable_Get(struct Container020e0310 *c, int key);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendString02042058(char *dst, const char *src);
void SetByteInRange_020465f0(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02046380(void *g);
extern "C" int func_020420e8(const char *text, int large);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_ov017_021bdbcc(GameResources *r);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
extern "C" char data_ov002_0216d2a1[];

static inline unsigned short inline_ov002_0215e644(char *arg0, int arg1) { return *(unsigned short *) (arg0 + arg1); }

// USA: func_ov002_0215e644
extern "C" ARM void func_ov002_0215e644(char *base, char *dst) {
    char num[0x10];
    char tag[0x20];
    char text[0x400];
    if (dst == NULL) return;
    char *g       = GetGlobalField0x1c020421a0();
    GameObject *m = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), *(signed char *) (base + 0x1c00 + 0x20));
    if (m == NULL) return;
    unsigned char *f = GetFieldAt0x150_02053c6c((unsigned char *) m);
    if (f == NULL) return;
    func_02046380(g);
    SetIndexedName02046574((struct Obj02046574 *) g, 0, *(char **) ((char *) m + 0x134));
    int x1 = (0x40 - func_020420e8(*(const char **) ((char *) m + 0x134), 0)) >> 1;
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 0, LdH(*(char **) ((char *) m + 0x130), 4));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 1, LdH(*(char **) ((char *) m + 0x134), 0x30));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 2, LdH(*(char **) ((char *) m + 0x130), 6));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 3, LdH(*(char **) ((char *) m + 0x134), 0x32));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 4, *(unsigned short *) (f + *(int *) (f + 0x950) * 2 + 0x16c));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 5, LdH(*(char **) ((char *) m + 0x134), 0x34));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 6, LdH(*(char **) ((char *) m + 0x134), 0x36));
    StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 7, (*(unsigned int *) f << 12) >> 22);
    int job          = *(int *) (f + 0x950);
    GameResources *v = GetGameResources();
    if (func_ov017_021bdbcc(v)) job = 0;
    char *s = (char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20),
                                                                      (short) (job + 0x834));
    int x2  = (0x40 - func_020420e8(s, 0)) >> 1;
    if (func_ov017_021bdbcc(v)) {
        SetIndexedName02046574((struct Obj02046574 *) g, 1, s);
    } else if (*(int *) ((char *) m + 0x1c4) == 0) {
        SetIndexedName02046574((struct Obj02046574 *) g, 1, s);
    }
    unsigned char var11 = *(var5 + *(int *) (var5 + 0x950) + 0x186);
    if (var11 != 0) {
        sprintf(var0, data_ov002_0216d2a1, var11);
        __clear(var1, 0x20);
        int var12 = 5;
        if (var11 == 10) var12 = 0xd;
        func_02041e70(var1, var12);
        func_02042058(var1, var0);
        func_02041e70(var1, 0xf);
        func_02046574((struct Struct_02046574_2 *) var3, 2, var1);
    }
    for (int var13 = 0; var13 < 8; var13++) {
        int var14 = 3;
        if (var13 == 4) var14 = 2;
        func_020465f0((unsigned char *) var3, var13, var14);
    }
    for (int var15 = 0; var15 < 8; var15++) {
        func_020465d8((unsigned char *) var3, var15, 1);
    }
    sprintf(text,
            (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0x7d0),
            x1, x2);
    func_02046608(g, 0xa, text, dst, 0x100, 0, 0);
}
