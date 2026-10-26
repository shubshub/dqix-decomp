#include "GameState/GameState.h"
#include <globaldefs.h>

struct StoreStruct;
struct Container020e0310;
struct Struct_ov002_0215fcc0 {
    int hdr;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov002_0216ca30 {
    int v[5];
};
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int func_02041a5c(char *dst, int y);
extern "C" int func_02041a28(char *dst, int x);
extern "C" int func_02041acc(char *dst, int w);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int func_02041fac(char *buf, int a, int b);
extern "C" const char *StandardStrings_Get(int key);
extern "C" char *MessageSystem_GetInstance();
extern "C" void func_020465c0(struct StoreStruct *base, int index, int value);
extern "C" void func_020465f0(unsigned char *messages, int index, unsigned char digits);
extern "C" void func_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02046380(void *g);
extern "C" int Font_GetTextWidth(const char *text, int large);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d285[];
extern "C" char data_ov002_0216d2ae[];
extern "C" char data_ov002_0216d2b3[];
extern "C" struct Struct_ov002_0216ca30 data_ov002_0216ca30;

// USA: func_ov002_0215fcc0
extern "C" ARM void func_ov002_0215fcc0(char *base, char *dst) {
    char line[0x200];
    char tmp[0x100];
    char numA[0x10];
    char numB[0x10];
    GameObject *m;
    if (dst == NULL) return;
    GameState *gs = GameState::GetInstance();
    short k1      = 0x10fe;
    short k2      = 0x1112;
    m             = gs->GetPartyMemberByIndex(*(signed char *) (base + 0x1c00 + 0x20));
    if (m == NULL) return;
    const char *name = *(const char **) ((char *) m + 0x134);
    int w            = Font_GetTextWidth(name, 0);
    __clear(line, 0x200);
    char *f = *(char **) ((char *) m + 0x150);
    int val;
    int lv = *(unsigned char *) (f + *(int *) (f + 0x950) + 0x186);
    val    = *(unsigned short *) (f + *(int *) (f + 0x950) * 2 + 0x16c);
    if (lv != 0) {
        const char *title =
            (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), (short) (lv + 0x8fc));
        func_02041a5c(line, 4);
        Text_Append(line, name);
        func_02041acc(line, 0x10);
        Text_Append(line, title);
        func_02041acc(line, 4);
        Text_Append(line, StandardStrings_Get(0x3f3));
        __clear(numA, 0x10);
        sprintf(numA, data_ov002_0216d285, val);
        Text_Append(line, numA);
    } else {
        func_02041a5c(line, 4);
        Text_Append(line, name);
        func_02041acc(line, 0x12);
        Text_Append(line, StandardStrings_Get(0x3f3));
        __clear(numB, 0x10);
        sprintf(numB, data_ov002_0216d285, val);
        Text_Append(line, numB);
    }
    __clear(tmp, 0x100);
    sprintf(tmp, data_ov002_0216d2ae, StandardStrings_Get(0x3f3), val);
    int tw = w + 0x12 + Font_GetTextWidth(tmp, 0);
    if (lv != 0) tw += 9;
    int x                             = (0x80 - tw) >> 1;
    *(short *) (base + 0x2400 + 0x5c) = w + x + 1;
    func_02041a28(dst, x);
    Text_Append(dst, line);
    func_02041fac(dst, (int) data_ov002_0216d2b3, 0x10);
    unsigned char *g = (unsigned char *) MessageSystem_GetInstance();
    func_02046380(g);
    struct Struct_ov002_0216ca30 xs = data_ov002_0216ca30;
    int stats[7]         = {
        (*(struct Struct_ov002_0215fcc0 **) ((char *) m + 0x130))->unknown_4_,
        m->baseStats_->primaryStats.maxHP,
        (*(struct Struct_ov002_0215fcc0 **) ((char *) m + 0x130))->unknown_6_,
        m->baseStats_->primaryStats.maxMP,
        m->baseStats_->primaryStats.attack,
        m->baseStats_->primaryStats.defense,
        m->baseStats_->primaryStats.agility,
    };
    for (int i = 0; i < 7; i++) {
        func_020465d8(g, i, 1);
        func_020465f0(g, i, 3);
        func_020465c0((struct StoreStruct *) g, i, stats[i]);
    }
    for (int i = 0; i < 5; i++) {
        Text_Append(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), k1++));
        func_02041a28(dst, xs.v[i]);
        Text_Append(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), k2++));
        if (i != 4) {
            Text_Append(dst, *(const char **) (base + 0x1000 + 0xbdc));
        }
    }
}
