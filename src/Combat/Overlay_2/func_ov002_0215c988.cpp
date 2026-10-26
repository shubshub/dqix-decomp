#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_0205c508;
struct StoreStruct;
struct ItemTable;
struct Struct_020a0b8c;
struct KeyMap020a0b3c;
struct Struct_0205d81c;

extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" char *MessageSystem_GetInstance();
extern "C" void func_0205c508(struct Struct_0205c508 *s, int *out1, int *out2);
extern "C" void *func_02053c6c(unsigned char *member);
extern "C" int func_ov002_02157108(void *self, int type);
extern "C" void func_02046380(void *messages);
extern "C" void func_020465c0(StoreStruct *messages, int index, int value);
extern "C" char *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void *__clear(void *destination, int count);
extern "C" void func_0206819c(const char *src, char *dst, int flag);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" void *GameState_GetParty(GameState *gameState);
extern "C" int func_020a0b8c(struct Struct_020a0b8c *s);
extern "C" int func_020a0b3c(KeyMap020a0b3c *map, int key);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void func_ov002_0215b918(unsigned char *self, int a, int b, int c);
extern "C" char *func_0205d81c(struct Struct_0205d81c *s, int key);

extern "C" char data_ov002_0216d270[];
#if defined(jpn)
struct Obj02046574;
struct Container020e0310;
extern "C" int STD_GetStringLength(const char *s);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" void func_020465f0(unsigned char *messages, int index, unsigned char digits);
extern "C" void func_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_020474a8(void *messages, int a, const char *format, char *output);
extern "C" void func_02042428(char *dst, int a);
extern "C" void *memset(void *dst, int value, unsigned int length);
#endif

// USA: func_ov002_0215c988
extern "C" ARM void func_ov002_0215c988(char *self, char *dst, int flag) {
#if defined(jpn)
    char numBuf[0x40];
    int first;
    int last;
    if (dst == NULL) return;
    int cursor = *(short *) (self + 0x1a00 + 0xb0) & 7;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    GameState *gs = GameState::GetInstance();
    char *msgs    = MessageSystem_GetInstance();
    char *obj     = self + 0xe20;
    int page      = *(int *) (obj + 0x68);
    int pages     = *(int *) (obj + 0x58);
    func_0205c508((struct Struct_0205c508 *) (obj + 0x54), &first, &last);
    int id = *(signed char *) (self + 0x1a00 + 0xe8);
    int ok = (id >= 0 && id <= 3) ? 1 : 0;
    if (ok) {
        page              = 0;
        pages             = 1;
        unsigned char *pm = (unsigned char *) func_02053c6c((unsigned char *) func_0200ff1c(gs, id));
        int n             = func_ov002_02157108(self, id);
        int k             = 0;
        for (int i = 0; i < n; i++) {
            func_02046380(msgs);
            func_020465c0((StoreStruct *) msgs, 0, k);
            char *e = ItemTable_Find((struct ItemTable *) (self + 0x750), *(short *) (pm + i * 2 + 0x454));
            if (e != 0) {
                int len = STD_GetStringLength(dst);
                MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 0, *(char **) (e + 4));
                func_020474a8(msgs, 0xa, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x480),
                              dst + len);
                if (i != n - 1) {
                    Text_Append(dst, *(char **) (self + 0x1000 + 0xaa4));
                }
            }
            k++;
        }
    } else if (id == 4) {
        unsigned char *party = (unsigned char *) GameState_GetParty(gs);
        int cnt              = func_020a0b8c((struct Struct_020a0b8c *) party);
        if (*(int *) (self + 0x1000 + 0xa80) == 4) {
            first = 0;
            last  = 8;
            if (cnt < 8) {
                last = cnt;
            }
            pages = (cnt + 7) / 8;
            page  = 0;
        }
        if (pages == 0) {
            pages = 1;
        }
        int k = 0;
        for (int i = first; i < last; i++) {
            func_02046380(msgs);
            func_020465c0((StoreStruct *) msgs, 0, k);
            char *e = ItemTable_Find((struct ItemTable *) (self + 0x750), *(short *) (party + i * 2 + 0xc));
            if (e != 0) {
                int len = STD_GetStringLength(dst);
                MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 0, *(char **) (e + 4));
                func_020474a8(msgs, 0xa, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x480),
                              dst + len);
                memset(numBuf, 0, 0x40);
                sprintf(numBuf, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x481),
                        func_020a0b3c((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
                Text_Append(dst, numBuf);
                if (i != last - 1) {
                    Text_Append(dst, *(char **) (self + 0x1000 + 0xaa4));
                }
            }
            k++;
        }
    }
    int on = 0;
    if (pages > 1) {
        func_020465c0((StoreStruct *) msgs, 0, page + 1);
        func_020465c0((StoreStruct *) msgs, 1, pages);
        func_020465f0((unsigned char *) msgs, 0, 2);
        func_020465f0((unsigned char *) msgs, 1, 2);
        func_020465d8((unsigned char *) msgs, 0, 1);
        func_020465d8((unsigned char *) msgs, 1, 0);
        func_02042428(dst, 8);
        Text_Append(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x47f));
        on = 1;
    }
    unsigned char *el = (unsigned char *) func_0205d81c((struct Struct_0205d81c *) (self + 0xe20), 5);
    if (el != 0) {
        if (on) {
            el[0xc5] |= 8;
        } else {
            el[0xc5] &= ~8;
        }
    }
#else
    char nameBuf[0x100];
    char nameBuf2[0x100];
    char numBuf[0x40];
    int first;
    int last;
    if (dst == NULL) return;
    int cursor = *(short *) (self + 0x1be8) & 7;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    GameState *gs = GameState::GetInstance();
    char *msgs    = MessageSystem_GetInstance();
    char *obj     = self + 0x2c8 + 0xc00;
    int page      = *(int *) (obj + 0x68);
    int pages     = *(int *) (obj + 0x58);
    func_0205c508((struct Struct_0205c508 *) (obj + 0x54), &first, &last);
    int id = *(signed char *) (self + 0x1c20);
    int ok = (id >= 0 && id <= 3) ? 1 : 0;
    if (ok) {
        page              = 0;
        pages             = 1;
        unsigned char *pm = (unsigned char *) func_02053c6c((unsigned char *) func_0200ff1c(gs, id));
        int n             = func_ov002_02157108(self, id);
        int k             = 0;
        for (int i = 0; i < n; i++) {
            func_02046380(msgs);
            func_020465c0((StoreStruct *) msgs, 0, k);
            char *e = ItemTable_Find((struct ItemTable *) (self + 0x3ec + 0x400),
                                                                        *(short *) (pm + i * 2 + 0x454));
            if (e != 0) {
                __clear(nameBuf, 0x100);
                func_0206819c(*(char **) (e + 4), nameBuf, 0);
                Text_AppendNTag(dst, k, nameBuf);
                if (i != n - 1) {
                    Text_Append(dst, *(char **) (self + 0x1bdc));
                }
            }
            k++;
        }
    } else if (id == 4) {
        unsigned char *party = (unsigned char *) GameState_GetParty(gs);
        int cnt              = func_020a0b8c((struct Struct_020a0b8c *) party);
        if (*(int *) (self + 0x1bb8) == 4) {
            first = 0;
            last  = 8;
            if (cnt < 8) {
                last = cnt;
            }
            pages = (cnt + 7) / 8;
            page  = 0;
        }
        if (pages == 0) {
            pages = 1;
        }
        int k = 0;
        for (int i = first; i < last; i++) {
            func_02046380(msgs);
            func_020465c0((StoreStruct *) msgs, 0, k);
            char *e = ItemTable_Find((struct ItemTable *) (self + 0x3ec + 0x400),
                                                                        *(short *) (party + i * 2 + 0xc));
            if (e != 0) {
                __clear(nameBuf2, 0x100);
                func_0206819c(*(char **) (e + 4), nameBuf2, 0);
                Text_AppendNTag(dst, k, nameBuf2);
                __clear(numBuf, 0x40);
                sprintf(numBuf, data_ov002_0216d270,
                        func_020a0b3c((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
                Text_Append(dst, numBuf);
                if (i != last - 1) {
                    Text_Append(dst, *(char **) (self + 0x1bdc));
                }
            }
            k++;
        }
    }
    int on = 0;
    if (pages > 1) {
        func_ov002_0215b918((unsigned char *) self, 5, page, pages);
        on = 1;
    } else {
        func_ov002_0215b918((unsigned char *) self, 5, on, on);
    }
    unsigned char *el =
        (unsigned char *) func_0205d81c((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 5);
    if (el != 0) {
        if (on) {
            el[0xc5] |= 8;
        } else {
            el[0xc5] &= ~8;
        }
    }
#endif
}
