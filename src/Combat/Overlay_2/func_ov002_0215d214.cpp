#include "GameState/GameState.h"
#include <globaldefs.h>

struct ItemTable;
struct Container020e0310;
struct StoreStruct;
struct Struct0200fb08;

struct Struct_ov002_0215d214 {
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
};

struct Struct_ov002_0215d214_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
    unsigned int unknown_4_0_ : 10;
    unsigned int unknown_5_2_ : 10;
    unsigned int unknown_6_4_ : 10;
    unsigned int unknown_7_6_ : 2;
    unsigned int unknown_8_0_ : 10;
    unsigned int unknown_9_2_ : 22;
};

struct Struct_ov002_0215d214_3 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 2;
    unsigned int unknown_b_2_ : 6;
};

void *GetFieldAt0x150_02053c6c(unsigned char *member);
char *ItemTable_Find(struct ItemTable *c, int key);
char *MessageSystem_GetInstance();
extern "C" void func_02046380(void *messages);
void NameText_InitFromPartyMember(void *obj, int combatantId);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
int GameState_GetLanguage(Struct0200fb08 *s);
char *KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" char *strstr(const char *str, const char *substr);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
void StoreInArray0x8b0_020465c0(StoreStruct *messages, int index, int value);
extern "C" void MessageSystem_FormatText(void *messages, int a, const char *format, char *output, int size, int b, int c);

extern "C" unsigned char data_ov002_0216cac4[];
extern "C" unsigned char data_ov002_0216cac5[];
extern "C" char data_ov002_0216d280[];
extern "C" char data_ov002_0216d285[];

// USA: func_ov002_0215d214
extern "C" ARM void func_ov002_0215d214(char *arg0, char *arg1, int arg2) {
    char var0[4];
    Struct_ov002_0215d214_3 var1;
    char var2[0x200];
    if (arg1 == NULL) return;
    GameState *var3              = GameState::GetInstance();
    *(short *) (arg0 + 0x1c26) = -1;
    unsigned char *var4         = (unsigned char *) (arg0 + 0x68 + 0x1c00);
    short var5                    = *(short *) (arg0 + 0x1bfa);
    if (var5 >= 0 && var5 < 0x20) {
        *(short *) (arg0 + 0x1c26) = (*(Struct_ov002_0215d214 **) (arg0 + var5 * 4 + 0x24a0))->unknown_4_0_;
    }
    if (*(short *) (arg0 + 0x1c26) < 0) {
        if (*(unsigned char *) (arg0 + 0x1c84) == 7) {
            var4 = (unsigned char *) (arg0 + 0x6e + 0x1c00);
        }
    }
    int cid = ids[*(short *) (self + 0x1bec)];
    char *c = (char *) GetCombatantWithFlag0x100_0200ff1c(gs, cid);
    if (c == 0) return;
    Stats_0215d214 *pm = (Stats_0215d214 *) GetFieldAt0x150_02053c6c((unsigned char *) c);
    if (pm == 0) return;
    char *e = 0;
    if (*(short *) (self + 0x1c26) < 0) {
        e = ItemTable_Find((struct ItemTable *) (self + 0x3ec + 0x400),
                                                              *(short *) (self + 0x1c22));
        if (e == 0) return;
    }
    char *msgs = MessageSystem_GetInstance();
    func_02046380(msgs);
    NameText_InitFromPartyMember(&nameObj, cid);
    *(void **) msgs = &nameObj;
    int key;
    char *s130 = *(char **) (c + 0x130);
    char *s134 = *(char **) (c + 0x134);
    int val    = *(unsigned short *) (s130 + 4);
    int max    = *(unsigned short *) (s134 + 0x30);
    key        = 0x4ba;
    int show   = 1;
    if (e != 0) {
        switch (*(short *) (e + 0x18)) {
            case 0x55ff:
            case 0x5600:
            case 0x5601: var16 = 0;
            case 0x561e:
                var15 = *(unsigned short *) (var13 + 0x32);
                var14 = *(unsigned short *) (var12 + 6);
                var11 = 0x4bb;
                break;
            case 0x561f:
                var14 = var8->unknown_0_0_;
                var11 = 0x1103;
                break;
            case 0x5622:
                var14 = var8->unknown_2_4_;
                var11 = 0x1104;
                break;
            case 0x5621:
                var14 = var8->unknown_1_2_;
                var11 = 0x1105;
                break;
            case 0x5619:
                var14 = var8->unknown_5_2_;
                var11 = 0x1106;
                break;
            case 0x5620:
                var14 = var8->unknown_4_0_;
                var11 = 0x1107;
                break;
            case 0x5623:
                var14 = var8->unknown_8_0_;
                var11 = 0x1108;
                break;
            case 0x5624:
                var14 = var8->unknown_6_4_;
                var11 = 0x1109;
                break;
            case 0x5625:
                var14 = *(unsigned short *) ((char *) var8 + 0x564);
                var11 = 0x110a;
                break;
            case 0x561d: break;
            default: var16 = 0; break;
        }
    } else if (*(short *) (arg0 + 0x1c26) >= 0) {
        var16 = 0;
    }
    int var17    = func_ov002_02159774(arg0, var6, 1, 1, 1);
    int var18  = 0xf;
    int var19 = 0;
    if (!var16) {
        int var20 = -1;
        int var21    = **(int **) (var7 + 0x130);
        if (var21 & 1) {
            var20 = 2;
            var11   = 0x110d;
            var18   = 9;
        } else if (var21 & 2) {
            var20 = 0;
            var11   = 0x110b;
            var18   = 0xc;
        } else if (var21 & 4) {
            var11   = 0x110c;
            var18   = var17;
            var20 = 1;
        }
        if (which >= 0) {
            int x = GameState_GetLanguage((Struct0200fb08 *) GameState::GetInstance());
            for (int j = 0; j < 5; j++) {
                if (x == data_ov002_0216cac4[j * 7]) {
                    mark = (data_ov002_0216cac5 + j * 7 + nameObj.kind)[which * 2];
                    break;
                }
            }
        }
    }
    if (var17 == 3) {
        var18 = 3;
    }
    sprintf(buf, KeyTable_Get((struct Container020e0310 *) (self + 0x20), key), arg, n);
    if (mark != 0) {
        char *p = strstr(buf, data_ov002_0216d280);
        if (p != 0) {
            sprintf(tmp, data_ov002_0216d285, mark);
            memcpy(p + 4, tmp, 2);
        }
    }
    StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, val);
    StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 1, max);
    MessageSystem_FormatText(msgs, 10, buf, dst, 0x100, 0, 0);
}
