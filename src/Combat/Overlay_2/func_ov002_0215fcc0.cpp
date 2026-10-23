#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_020465c0;
struct Struct_0201099c_3;
struct Struct_ov002_0215fcc0 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov002_0216ca30 {
    int unknown_0_[5];
};
int KeyTable_Get(struct Container020e0310 *c, int key);
int AppendYTag_02041a5c(char *dst, int y);
int AppendXTag_02041a28(char *dst, int x);
int AppendWidthTag_02041acc(char *dst, int w);
int AppendString02042058(char *dst, const char *src);
int AppendFormatted02041fac(char *buf, int a, int b);
const char *CallFunc020e0434With02153694_020e51cc(int key);
char *GetGlobalField0x1c020421a0();
void StoreInArray0x8b0_020465c0(struct StoreStruct *base, int index, int value);
void SetByteInRange_020465f0(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02046380(void *g);
extern "C" int func_020420e8(const char *text, int large);
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
    int w            = func_020420e8(name, 0);
    __clear(line, 0x200);
    char *f = *(char **) ((char *) m + 0x150);
    int val;
    int lv = *(unsigned char *) (f + *(int *) (f + 0x950) + 0x186);
    val    = *(unsigned short *) (f + *(int *) (f + 0x950) * 2 + 0x16c);
    if (lv != 0) {
        const char *title =
            (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), (short) (lv + 0x8fc));
        AppendYTag_02041a5c(line, 4);
        AppendString02042058(line, name);
        AppendWidthTag_02041acc(line, 0x10);
        AppendString02042058(line, title);
        AppendWidthTag_02041acc(line, 4);
        AppendString02042058(line, CallFunc020e0434With02153694_020e51cc(0x3f3));
        __clear(numA, 0x10);
        sprintf(numA, data_ov002_0216d285, val);
        AppendString02042058(line, numA);
    } else {
        func_02041a5c(var0, 4);
        func_02042058(var0, var8);
        func_02041acc(var0, 0x12);
        func_02042058(var0, func_020e51cc(0x3f3));
        __clear(var3, 0x10);
        sprintf(var3, data_ov002_0216d285, var11);
        func_02042058(var0, var3);
    }
    __clear(var1, 0x100);
    sprintf(var1, data_ov002_0216d2ae, func_020e51cc(0x3f3), var11);
    int var14 = var9 + 0x12 + func_020420e8(var1, 0);
    if (var12 != 0) var14 += 9;
    int var15                             = (0x80 - var14) >> 1;
    *(short *) (arg0 + 0x2400 + 0x5c) = var9 + var15 + 1;
    func_02041a28(arg1, var15);
    func_02042058(arg1, var0);
    func_02041fac(arg1, (int) data_ov002_0216d2b3, 0x10);
    unsigned char *var16 = (unsigned char *) func_020421a0();
    func_02046380(var16);
    struct Struct_ov002_0216ca30 var17 = data_ov002_0216ca30;
    int var18[7]         = {
        (*(struct Struct_ov002_0215fcc0 **) ((char *) var4 + 0x130))->unknown_4_,
        var4->baseStats_->primaryStats.maxHP,
        (*(struct Struct_ov002_0215fcc0 **) ((char *) var4 + 0x130))->unknown_6_,
        var4->baseStats_->primaryStats.maxMP,
        var4->baseStats_->primaryStats.attack,
        var4->baseStats_->primaryStats.defense,
        var4->baseStats_->primaryStats.agility,
    };
    for (int var19 = 0; var19 < 7; var19++) {
        func_020465d8(var16, var19, 1);
        func_020465f0(var16, var19, 3);
        func_020465c0((struct Struct_020465c0 *) var16, var19, var18[var19]);
    }
    for (int i = 0; i < 5; i++) {
        AppendString02042058(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), k1++));
        AppendXTag_02041a28(dst, xs.v[i]);
        AppendString02042058(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), k2++));
        if (i != 4) {
            AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
        }
    }
}
