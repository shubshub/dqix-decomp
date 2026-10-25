#include "GameState/GameState.h"
#include <globaldefs.h>

struct TableA68;
struct Obj02046574;
struct StoreStruct;
struct S020466c8;
struct Container020e0310;
void *FindEntryByKey_02072a68(struct TableA68 *table, int key);
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *gameState, int combatantId);
void *MessageSystem_GetInstance();
int Text_Append(char *dst, const char *src);
int KeyTable_Get(struct Container020e0310 *c, int key);
void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
void NameText_InitFromPartyMember(void *obj, int combatantId);
void *CallFunc020e52a0_020e5294(void *p, int key);
void StoreInArray0x8b0_020465c0(struct StoreStruct *base, int index, int value);
void SetField0x38(struct S020466c8 *p, int v);
int GetField110ArrayValue021574d4(void *base, int idx);
extern "C" void *func_0209a594(void *p, int key);
extern "C" void func_02046380(void *g);
extern "C" void func_020e4864(void *src, void *dst, int a, int b, int c, int d);
extern "C" void func_0204500c(void *obj, char *buffer, int a, int b);
extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" void *__clear(void *dst, int count);

struct Struct_ov002_021685bc {
    unsigned short unknown_0_0_ : 11;
    unsigned short unknown_1_3_ : 5;
    short unknown_2_;
    unsigned int unknown_4_0_ : 5;
    unsigned int unknown_4_5_ : 7;
    unsigned int unknown_5_4_ : 8;
    unsigned int unknown_6_4_ : 5;
    unsigned int unknown_7_1_ : 7;
};

// USA: func_ov002_021685bc
extern "C" ARM void func_ov002_021685bc(unsigned char *base) {
    while (*(base + 0x2000 + 0x454) < *(base + 0x2000 + 0x455)) {
        struct Ev021685bc *e = (struct Ev021685bc *) func_0209a594(
            base + 0x3c + 0x2400, (*(unsigned short **) (base + 0x2000 + 0x450))[*(base + 0x2000 + 0x454)]);
        char *s = NULL;
        if (e != NULL) {
            s = (char *) FindEntryByKey_02072a68(*(struct TableA68 **) (base + 0x2000 + 0x448), e->type);
        }
        if (s != NULL) {
            GameState *gs = GameState::GetInstance();
            int id        = GetField110ArrayValue021574d4(base, *(short *) (base + 0x1c00 + 8));
            GameObject *c = GetCombatantWithFlag0x100_0200ff1c(gs, id);
            if (c != NULL) {
                char obj[0xc];
                char tmp[0x80];
                unsigned char *g = (unsigned char *) MessageSystem_GetInstance();
                memset(*(char **) (base + 0x1000 + 0xbd0), 0, 0x960);
                Text_Append(*(char **) (base + 0x1000 + 0xbd0), s);
                Text_Append(*(char **) (base + 0x1000 + 0xbd0),
                                     (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), 7));
                func_02046380(g);
                MessageSystem_SetStringArgument((struct Obj02046574 *) g, 0, *(char **) ((char *) c + 0x134));
                NameText_InitFromPartyMember(obj, id);
                *(void **) g = obj;
                if (e->type == 1) {
                    void **r            = (void **) CallFunc020e52a0_020e5294(*(void **) (base + 0x2000 + 0x44c), e->item);
                    *(void ***) (g + 8) = r;
                    __clear(tmp, 0x80);
                    func_020e4864(*r, tmp, 1, 0, 0, 0);
                    MessageSystem_SetStringArgument((struct Obj02046574 *) g, 1, tmp);
                } else {
                    MessageSystem_SetStringArgument(
                        (struct Obj02046574 *) g, 1,
                        (char *) FindEntryByKey_02072a68(*(struct TableA68 **) (base + 0x2000 + 0x448), (short) (e->a + 0x64)));
                }
                int slot = 2;
                if (e->type == 4 || e->type == 0x10) slot = 1;
                MessageSystem_SetStringArgument(
                    (struct Obj02046574 *) g, slot,
                    (char *) FindEntryByKey_02072a68(*(struct TableA68 **) (base + 0x2000 + 0x448), (short) (e->k + 0xc8)));
                StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 0, e->b);
                SetField0x38((struct S020466c8 *) g, (*(int **) base)[4]);
                func_0204500c(g, *(char **) (base + 0x1000 + 0xbd0), 0, 0xe3);
                *(g + 0x1000 + 0x9b2) = 0;
                *(int *) (g + 0x998)  = 1;
                (*(base + 0x2000 + 0x454))++;
                (*(int *) (base + 0x1000 + 0xbc0))++;
                return;
            }
        }
        (*(arg0 + 0x2000 + 0x288))++;
    }
    (*(int *) (arg0 + 0x1000 + 0xa88))++;
}
#else
extern "C" ARM void func_ov002_021685bc(unsigned char *arg0) {
    while (*(arg0 + 0x2000 + 0x454) < *(arg0 + 0x2000 + 0x455)) {
        struct Struct_ov002_021685bc *var0 = (struct Struct_ov002_021685bc *) func_0209a594(
            arg0 + 0x3c + 0x2400, (*(unsigned short **) (arg0 + 0x2000 + 0x450))[*(arg0 + 0x2000 + 0x454)]);
        char *var1 = NULL;
        if (var0 != NULL) {
            var1 = (char *) func_02072a68(*(struct Struct_02072a68_2 **) (arg0 + 0x2000 + 0x448), var0->unknown_6_4_);
        }
        if (var1 != NULL) {
            GameState *var2 = GameState::GetInstance();
            int var3        = func_ov002_021574d4(arg0, *(short *) (arg0 + 0x1c00 + 8));
            GameObject *var4 = func_0200ff1c(var2, var3);
            if (var4 != NULL) {
                char var5[0xc];
                char var6[0x80];
                unsigned char *var7 = (unsigned char *) func_020421a0();
                memset(*(char **) (arg0 + 0x1000 + 0xbd0), 0, 0x960);
                func_02042058(*(char **) (arg0 + 0x1000 + 0xbd0), var1);
                func_02042058(*(char **) (arg0 + 0x1000 + 0xbd0),
                                     (const char *) func_020e0434((struct Struct_0201099c_3 *) (arg0 + 0x20), 7));
                func_02046380(var7);
                func_02046574((struct Struct_02046574_2 *) var7, 0, *(char **) ((char *) var4 + 0x134));
                func_020e4bf4(var5, var3);
                *(void **) var7 = var5;
                if (var0->unknown_6_4_ == 1) {
                    void **var8            = (void **) func_020e5294(*(void **) (arg0 + 0x2000 + 0x44c), var0->unknown_2_);
                    *(void ***) (var7 + 8) = var8;
                    __clear(var6, 0x80);
                    func_020e4864(*var8, var6, 1, 0, 0, 0);
                    func_02046574((struct Struct_02046574_2 *) var7, 1, var6);
                } else {
                    func_02046574(
                        (struct Struct_02046574_2 *) var7, 1,
                        (char *) func_02072a68(*(struct Struct_02072a68_2 **) (arg0 + 0x2000 + 0x448), (short) (var0->unknown_4_0_ + 0x64)));
                }
                int var9 = 2;
                if (var0->unknown_6_4_ == 4 || var0->unknown_6_4_ == 0x10) var9 = 1;
                func_02046574(
                    (struct Struct_02046574_2 *) var7, var9,
                    (char *) func_02072a68(*(struct Struct_02072a68_2 **) (arg0 + 0x2000 + 0x448), (short) (var0->unknown_1_3_ + 0xc8)));
                func_020465c0((struct Struct_020465c0 *) var7, 0, var0->unknown_5_4_);
                func_020466c8((struct Struct_020466c8 *) var7, (*(int **) arg0)[4]);
                func_0204500c(var7, *(char **) (arg0 + 0x1000 + 0xbd0), 0, 0xe3);
                *(var7 + 0x1000 + 0x9b2) = 0;
                *(int *) (var7 + 0x998)  = 1;
                (*(arg0 + 0x2000 + 0x454))++;
                (*(int *) (arg0 + 0x1000 + 0xbc0))++;
                return;
            }
        }
        (*(arg0 + 0x2000 + 0x454))++;
    }
    (*(int *) (arg0 + 0x1000 + 0xbc0))++;
}
#endif
