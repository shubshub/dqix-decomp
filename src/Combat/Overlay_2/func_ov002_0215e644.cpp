#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Obj02046574;
struct StoreStruct;
struct Container020e0310;
extern "C" char *MessageSystem_GetInstance();
extern "C" GameObject *func_0200ff1c(GameState *gameState, int combatantId);
extern "C" unsigned char *func_02053c6c(unsigned char *p);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
extern "C" void func_020465c0(struct StoreStruct *base, int index, int value);
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_AppendPaletteTag(char *dst, int palette);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" void func_020465f0(unsigned char *messages, int index, unsigned char digits);
extern "C" void func_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02046380(void *g);
extern "C" int Font_GetTextWidth(const char *text, int large);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_ov017_021bdbcc(GameResources *r);
extern "C" void MessageSystem_FormatText(void *messages, int a, const char *format, char *output, int size, int b, int c);
extern "C" char data_ov002_0216d2a1[];

static inline unsigned short inline_ov002_0215e644(char *p, int off) { return *(unsigned short *) (p + off); }

// USA: func_ov002_0215e644
extern "C" ARM void func_ov002_0215e644(char *base, char *dst) {
    char num[0x10];
    char tag[0x20];
    char text[0x400];
    if (dst == NULL) return;
    char *g       = MessageSystem_GetInstance();
    GameObject *m = func_0200ff1c(GameState::GetInstance(), *(signed char *) (base + 0x1c00 + 0x20));
    if (m == NULL) return;
    unsigned char *f = func_02053c6c((unsigned char *) m);
    if (f == NULL) return;
    func_02046380(g);
    MessageSystem_SetStringArgument((struct Obj02046574 *) g, 0, *(char **) ((char *) m + 0x134));
    int x1 = (0x40 - Font_GetTextWidth(*(const char **) ((char *) m + 0x134), 0)) >> 1;
    func_020465c0((struct StoreStruct *) g, 0, inline_ov002_0215e644(*(char **) ((char *) m + 0x130), 4));
    func_020465c0((struct StoreStruct *) g, 1, inline_ov002_0215e644(*(char **) ((char *) m + 0x134), 0x30));
    func_020465c0((struct StoreStruct *) g, 2, inline_ov002_0215e644(*(char **) ((char *) m + 0x130), 6));
    func_020465c0((struct StoreStruct *) g, 3, inline_ov002_0215e644(*(char **) ((char *) m + 0x134), 0x32));
    func_020465c0((struct StoreStruct *) g, 4, *(unsigned short *) (f + *(int *) (f + 0x950) * 2 + 0x16c));
    func_020465c0((struct StoreStruct *) g, 5, inline_ov002_0215e644(*(char **) ((char *) m + 0x134), 0x34));
    func_020465c0((struct StoreStruct *) g, 6, inline_ov002_0215e644(*(char **) ((char *) m + 0x134), 0x36));
    func_020465c0((struct StoreStruct *) g, 7, (*(unsigned int *) f << 12) >> 22);
    int var7          = *(int *) (f + 0x950);
    GameResources *v = GetGameResources();
    if (func_ov017_021bdbcc(v)) var7 = 0;
    char *s = (char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20),
                                                                      (short) (var7 + 0x834));
    int x2  = (0x40 - Font_GetTextWidth(s, 0)) >> 1;
    if (func_ov017_021bdbcc(v)) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, s);
    } else if (*(int *) ((char *) m + 0x1c4) == 0) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, s);
    }
    unsigned char lv = *(f + *(int *) (f + 0x950) + 0x186);
    if (lv != 0) {
        sprintf(num, data_ov002_0216d2a1, lv);
        __clear(tag, 0x20);
        int pal = 5;
        if (lv == 10) pal = 0xd;
        Text_AppendPaletteTag(tag, pal);
        Text_Append(tag, num);
        Text_AppendPaletteTag(tag, 0xf);
        MessageSystem_SetStringArgument((struct Obj02046574 *) g, 2, tag);
    }
    for (int i = 0; i < 8; i++) {
        int var14 = 3;
        if (i == 4) var14 = 2;
        func_020465f0((unsigned char *) g, i, var14);
    }
    for (int i = 0; i < 8; i++) {
        func_020465d8((unsigned char *) g, i, 1);
    }
    sprintf(text,
            (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0x7d0),
            x1, x2);
    MessageSystem_FormatText(g, 0xa, text, dst, 0x100, 0, 0);
}
