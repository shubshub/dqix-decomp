#include "GameState/GameState.h"
#include <globaldefs.h>

struct ArrayContainsByteStruct;
struct ItemTable;
struct KeyMap020a0b3c;
struct Struct_020a0b8c;
struct StoreStruct;
extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" char *MessageSystem_GetInstance();
extern "C" unsigned char *func_02053c6c(unsigned char *p);
extern "C" int func_02086ef0(ArrayContainsByteStruct *arr, int value);
extern "C" int func_ov002_02157108(void *self, int type);
extern "C" void func_020465c0(struct StoreStruct *base, int index, int value);
extern "C" char *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void func_0206819c(const char *src, char *dst, int flag);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int func_020a0b8c(struct Struct_020a0b8c *s);
extern "C" int func_020a0b3c(KeyMap020a0b3c *map, int key);
extern "C" void func_ov002_0215b918(unsigned char *self, int a, int b, int c);
extern "C" void func_02046380(void *g);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d288[];
extern "C" char data_ov002_0216d270[];

struct Struct_ov002_0215de9c {
    char pad[0x58];
    int pages;
    char pad2[0xc];
    int page;
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
    struct Struct_ov002_0215de9c *fld = (struct Struct_ov002_0215de9c *) (base + 0x2c8 + 0xc00) + 1;
    fld--;
    int page  = fld->page;
    int pages = fld->pages;
    if (actor >= 0 && actor <= 3) {
        ok = 1;
    }
    if (ok) {
        GameObject *m = func_0200ff1c(gs, actor);
        if (m == NULL) return;
        f = func_02053c6c((unsigned char *) m);
        if (!func_02086ef0((ArrayContainsByteStruct *) party, *(signed char *) (base + 0x1c00 + 0x21))) return;
        int n     = func_ov002_02157108(base, *(signed char *) (base + 0x1c00 + 0x21));
        int extra = 0;
        if (n < 8) extra = 1;
        for (int i = 0; i < n + extra; i++) {
            func_02046380(g);
            func_020465c0((struct StoreStruct *) g, 0, i);
            char *e = ItemTable_Find((struct ItemTable *) (base + 0x3ec + 0x400),
                                                                        *(short *) (f + i * 2 + 0x454));
            if (e != NULL) {
                __clear(nameA, 0x100);
                func_0206819c(*(const char **) (e + 4), nameA, 0);
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
        int c = func_ov002_02157108(base, actor);
        if (end > c) end = c;
        pages = (func_020a0b8c((struct Struct_020a0b8c *) party) + 7) / 8;
        for (; i < end; i++) {
            func_02046380(g);
            func_020465c0((struct StoreStruct *) g, 0, i);
            char *e = ItemTable_Find((struct ItemTable *) (base + 0x3ec + 0x400),
                                                                        *(short *) (party + i * 2 + 0xc));
            if (e == NULL) continue;
            __clear(nameB, 0x100);
            func_0206819c(*(const char **) (e + 4), nameB, 0);
            Text_AppendNTag(dst, i, nameB);
            __clear(num, 0x40);
            sprintf(num, data_ov002_0216d270,
                    func_020a0b3c((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
            Text_Append(dst, num);
            if (i != end - 1) {
                Text_Append(dst, *(const char **) (base + 0x1000 + 0xbdc));
            }
        }
    }
    if (pages > 1) {
        func_ov002_0215b918((unsigned char *) base, 0xd, page, pages);
    } else {
        func_ov002_0215b918((unsigned char *) base, 0xd, 0, 0);
    }
}
