#include "GameState/GameState.h"
#include <globaldefs.h>

struct ArrayContainsByteStruct;
struct ItemTable;
struct KeyMap020a0b3c;
struct S_a0b8c;
struct StoreStruct;
int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char *dst, int cursor);
char *MessageSystem_GetInstance();
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct *arr, int value);
int GetCountByType02157108(void *self, int type);
void StoreInArray0x8b0_020465c0(struct StoreStruct *base, int index, int value);
char *ItemTable_Find(struct ItemTable *c, int key);
void CopyTextAndUppercaseIfFlagged0206819c(const char *src, char *dst, int flag);
int Text_AppendNTag(char *dst, int n, const char *name);
int Text_Append(char *dst, const char *src);
int CountNonZeroValues020a0b8c(struct S_a0b8c *s);
int LookupValueByKey020a0b3c(KeyMap020a0b3c *map, int key);
void SetElementStateOrCreate0215b918(unsigned char *self, int a, int b, int c);
extern "C" void func_02046380(void *g);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d288[];
extern "C" char data_ov002_0216d270[];

struct Struct_ov002_0215de9c {
    char unknown_0_[0x58];
    int unknown_58_;
    char unknown_5c_[0xc];
    int unknown_68_;
};

// USA: func_ov002_0215de9c
extern "C" ARM void func_ov002_0215de9c(char *base, char *dst, int flag) {
    char nameA[0x100];
    char nameB[0x100];
    char num[0x40];
    if (dst == NULL) return;
    int cur = *(short *) (base + 0x1b00 + 0xf4) & 7;
    if (*(int *) (base + 0x1000 + 0xbb8) == 0xd) {
        if (flag) {
            Text_AppendFrameTag(dst, cur, 8, 5, 5, 5);
        }
        Text_AppendCursorTag(dst, cur);
    }
    GameState *gs = GameState::GetInstance();
    char *g       = MessageSystem_GetInstance();
    char *party   = (char *) GameState_GetParty(gs);
    int actor     = *(signed char *) (base + 0x1c00 + 0x21);
    int ok        = 0;
    unsigned char *f;
    struct F0215de9c *fld = (struct F0215de9c *) (base + 0x2c8 + 0xc00) + 1;
    fld--;
    int page  = fld->page;
    int pages = fld->pages;
    if (actor >= 0 && actor <= 3) {
        ok = 1;
    }
    if (ok) {
        GameObject *m = GetCombatantWithFlag0x100_0200ff1c(gs, actor);
        if (m == NULL) return;
        f = GetFieldAt0x150_02053c6c((unsigned char *) m);
        if (!ArrayContainsByte_02086ef0((ArrayContainsByteStruct *) party, *(signed char *) (base + 0x1c00 + 0x21))) return;
        int n     = GetCountByType02157108(base, *(signed char *) (base + 0x1c00 + 0x21));
        int extra = 0;
        if (n < 8) extra = 1;
        for (int i = 0; i < n + extra; i++) {
            func_02046380(g);
            StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 0, i);
            char *e = ItemTable_Find((struct ItemTable *) (base + 0x3ec + 0x400),
                                                                        *(short *) (f + i * 2 + 0x454));
            if (e != NULL) {
                __clear(nameA, 0x100);
                CopyTextAndUppercaseIfFlagged0206819c(*(const char **) (e + 4), nameA, 0);
                Text_AppendNTag(dst, i, nameA);
                if (i != n - 1) {
                    Text_Append(dst, *(const char **) (base + 0x1000 + 0xbdc));
                } else if (extra == 1) {
                    Text_Append(dst, *(const char **) (base + 0x1000 + 0xbdc));
                }
            } else if (i == n) {
                Text_AppendNTag(dst, i, data_ov002_0216d288);
            }
        }
    } else {
        int end;
        int i = page * 8;
        end   = i + 8;
        int c = GetCountByType02157108(base, actor);
        if (end > c) end = c;
        pages = (CountNonZeroValues020a0b8c((struct S_a0b8c *) party) + 7) / 8;
        for (; i < end; i++) {
            func_02046380(g);
            StoreInArray0x8b0_020465c0((struct StoreStruct *) g, 0, i);
            char *e = ItemTable_Find((struct ItemTable *) (base + 0x3ec + 0x400),
                                                                        *(short *) (party + i * 2 + 0xc));
            if (e == NULL) continue;
            __clear(nameB, 0x100);
            CopyTextAndUppercaseIfFlagged0206819c(*(const char **) (e + 4), nameB, 0);
            Text_AppendNTag(dst, i, nameB);
            __clear(num, 0x40);
            sprintf(num, data_ov002_0216d270,
                    LookupValueByKey020a0b3c((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
            Text_Append(dst, num);
            if (i != end - 1) {
                Text_Append(dst, *(const char **) (base + 0x1000 + 0xbdc));
            }
        }
    }
    if (var12 > 1) {
        func_ov002_0215b918((unsigned char *) arg0, 0xd, var11, var12);
    } else {
        func_ov002_0215b918((unsigned char *) arg0, 0xd, 0, 0);
    }
}
