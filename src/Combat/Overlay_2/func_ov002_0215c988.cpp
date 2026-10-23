#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_0205c508;
struct Struct_020465c0;
struct Struct_0201099c_10;
struct Struct_020a0b8c;
struct Struct_0207cf30_3;
struct Struct_0205d81c;

extern "C" int func_02041c08(char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" int func_02041ea4(char *arg0, int arg1);
extern "C" char *func_020421a0();
extern "C" void func_0205c508(struct Struct_0205c508 *arg0, int *arg1, int *arg2);
extern "C" void *func_02053c6c(unsigned char *arg0);
extern "C" int func_ov002_02157108(void *arg0, int arg1);
extern "C" void func_02046380(void *arg0);
extern "C" void func_020465c0(Struct_020465c0 *arg0, int arg1, int arg2);
extern "C" char *func_020dedd0(struct Struct_0201099c_10 *arg0, int arg1);
extern "C" void *__clear(void *arg0, int arg1);
extern "C" void func_0206819c(const char *arg0, char *arg1, int arg2);
extern "C" int func_02041b70(char *arg0, int arg1, const char *arg2);
extern "C" int func_02042058(char *arg0, const char *arg1);
extern "C" void *func_02010828(GameState *arg0);
extern "C" int func_020a0b8c(struct Struct_020a0b8c *arg0);
extern "C" int func_020a0b3c(Struct_0207cf30_3 *arg0, int arg1);
extern "C" int sprintf(char *arg0, const char *arg1, ...);
extern "C" void func_ov002_0215b918(unsigned char *arg0, int arg1, int arg2, int arg3);
extern "C" char *func_0205d81c(struct Struct_0205d81c *arg0, int arg1);

extern "C" char data_ov002_0216d270[];
#if defined(jpn)
struct Obj02046574;
struct Container020e0310;
int StringLength_020d2ff0(const char *s);
void SetIndexedName02046574(struct Obj02046574 *obj, int index, char *str);
int KeyTable_Get(struct Container020e0310 *c, int key);
void SetByteInRange_020465f0(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_020474a8(void *messages, int a, const char *format, char *output);
extern "C" void func_02042428(char *dst, int a);
extern "C" void *memset(void *dst, int value, unsigned int length);
#endif

// USA: func_ov002_0215c988
extern "C" ARM void func_ov002_0215c988(char *arg0, char *arg1, int arg2) {
#if defined(jpn)
    char var0[0x40];
    int var1;
    int var2;
    if (arg1 == NULL) return;
    int var3 = *(short *) (arg0 + 0x1a00 + 0xb0) & 7;
    if (arg2) {
        func_02041c08(arg1, var3, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    GameState *gs = GameState::GetInstance();
    char *msgs    = GetGlobalField0x1c020421a0();
    char *obj     = self + 0xe20;
    int page      = *(int *) (obj + 0x68);
    int pages     = *(int *) (obj + 0x58);
    ComputeProductSums0205c508((struct UnkStruct0205c508 *) (obj + 0x54), &first, &last);
    int id = *(signed char *) (self + 0x1a00 + 0xe8);
    int ok = (id >= 0 && id <= 3) ? 1 : 0;
    if (ok) {
        page              = 0;
        pages             = 1;
        unsigned char *pm = (unsigned char *) GetFieldAt0x150_02053c6c((unsigned char *) GetCombatantWithFlag0x100_0200ff1c(gs, id));
        int n             = GetCountByType02157108(self, id);
        int k             = 0;
        for (int i = 0; i < n; i++) {
            func_02046380(msgs);
            StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, k);
            char *e = FindElementByKey020dedd0((struct Container020dedd0 *) (self + 0x750), *(short *) (pm + i * 2 + 0x454));
            if (e != 0) {
                int len = StringLength_020d2ff0(dst);
                SetIndexedName02046574((struct Obj02046574 *) msgs, 0, *(char **) (e + 4));
                func_020474a8(msgs, 0xa, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x480),
                              dst + len);
                if (i != n - 1) {
                    AppendString02042058(dst, *(char **) (self + 0x1000 + 0xaa4));
                }
            }
            var13++;
        }
    } else if (var9 == 4) {
        unsigned char *var17 = (unsigned char *) func_02010828(var4);
        int var18              = func_020a0b8c((struct Struct_020a0b8c *) var17);
        if (*(int *) (arg0 + 0x1000 + 0xa80) == 4) {
            var1 = 0;
            var2  = 8;
            if (var18 < 8) {
                var2 = var18;
            }
            var8 = (var18 + 7) / 8;
            var7  = 0;
        }
        if (var8 == 0) {
            var8 = 1;
        }
        int k = 0;
        for (int i = first; i < last; i++) {
            func_02046380(msgs);
            StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, k);
            char *e = FindElementByKey020dedd0((struct Container020dedd0 *) (self + 0x750), *(short *) (party + i * 2 + 0xc));
            if (e != 0) {
                int len = StringLength_020d2ff0(dst);
                SetIndexedName02046574((struct Obj02046574 *) msgs, 0, *(char **) (e + 4));
                func_020474a8(msgs, 0xa, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x480),
                              dst + len);
                memset(numBuf, 0, 0x40);
                sprintf(numBuf, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x481),
                        LookupValueByKey020a0b3c((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
                AppendString02042058(dst, numBuf);
                if (i != last - 1) {
                    AppendString02042058(dst, *(char **) (self + 0x1000 + 0xaa4));
                }
            }
            var19++;
        }
    }
    int on = 0;
    if (pages > 1) {
        StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, page + 1);
        StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 1, pages);
        SetByteInRange_020465f0((unsigned char *) msgs, 0, 2);
        SetByteInRange_020465f0((unsigned char *) msgs, 1, 2);
        SetByteAtIndex_020465d8((unsigned char *) msgs, 0, 1);
        SetByteAtIndex_020465d8((unsigned char *) msgs, 1, 0);
        func_02042428(dst, 8);
        AppendString02042058(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (self + 8), 0x47f));
        on = 1;
    }
    unsigned char *var24 = (unsigned char *) func_0205d81c((struct Struct_0205d81c *) (arg0 + 0xe20), 5);
    if (var24 != 0) {
        if (var23) {
            var24[0xc5] |= 8;
        } else {
            var24[0xc5] &= ~8;
        }
    }
#else
    char var25[0x100];
    char var26[0x100];
    char var27[0x40];
    int var28;
    int var29;
    if (arg1 == NULL) return;
    int var30 = *(short *) (arg0 + 0x1be8) & 7;
    if (arg2) {
        func_02041c08(arg1, var30, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var30);
    GameState *var31 = GameState::GetInstance();
    char *var32    = func_020421a0();
    char *var33     = arg0 + 0x2c8 + 0xc00;
    int var34      = *(int *) (var33 + 0x68);
    int var35     = *(int *) (var33 + 0x58);
    func_0205c508((struct Struct_0205c508 *) (var33 + 0x54), &var28, &var29);
    int var36 = *(signed char *) (arg0 + 0x1c20);
    int var37 = (var36 >= 0 && var36 <= 3) ? 1 : 0;
    if (var37) {
        var34              = 0;
        var35             = 1;
        unsigned char *var38 = (unsigned char *) func_02053c6c((unsigned char *) func_0200ff1c(var31, var36));
        int var39             = func_ov002_02157108(arg0, var36);
        int var40             = 0;
        for (int var41 = 0; var41 < var39; var41++) {
            func_02046380(var32);
            func_020465c0((Struct_020465c0 *) var32, 0, var40);
            char *var42 = func_020dedd0((struct Struct_0201099c_10 *) (arg0 + 0x3ec + 0x400),
                                                                        *(short *) (var38 + var41 * 2 + 0x454));
            if (var42 != 0) {
                __clear(var25, 0x100);
                func_0206819c(*(char **) (var42 + 4), var25, 0);
                func_02041b70(arg1, var40, var25);
                if (var41 != var39 - 1) {
                    func_02042058(arg1, *(char **) (arg0 + 0x1bdc));
                }
            }
            var40++;
        }
    } else if (var36 == 4) {
        unsigned char *var43 = (unsigned char *) func_02010828(var31);
        int var44              = func_020a0b8c((struct Struct_020a0b8c *) var43);
        if (*(int *) (arg0 + 0x1bb8) == 4) {
            var28 = 0;
            var29  = 8;
            if (var44 < 8) {
                var29 = var44;
            }
            var35 = (var44 + 7) / 8;
            var34  = 0;
        }
        if (var35 == 0) {
            var35 = 1;
        }
        int var45 = 0;
        for (int var46 = var28; var46 < var29; var46++) {
            func_02046380(var32);
            func_020465c0((Struct_020465c0 *) var32, 0, var45);
            char *var47 = func_020dedd0((struct Struct_0201099c_10 *) (arg0 + 0x3ec + 0x400),
                                                                        *(short *) (var43 + var46 * 2 + 0xc));
            if (var47 != 0) {
                __clear(var26, 0x100);
                func_0206819c(*(char **) (var47 + 4), var26, 0);
                func_02041b70(arg1, var45, var26);
                __clear(var27, 0x40);
                sprintf(var27, data_ov002_0216d270,
                        func_020a0b3c((Struct_0207cf30_3 *) var43, *(short *) (var47 + 0x18)));
                func_02042058(arg1, var27);
                if (var46 != var29 - 1) {
                    func_02042058(arg1, *(char **) (arg0 + 0x1bdc));
                }
            }
            var45++;
        }
    }
    int var48 = 0;
    if (var35 > 1) {
        func_ov002_0215b918((unsigned char *) arg0, 5, var34, var35);
        var48 = 1;
    } else {
        func_ov002_0215b918((unsigned char *) arg0, 5, var48, var48);
    }
    unsigned char *var49 =
        (unsigned char *) func_0205d81c((struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), 5);
    if (var49 != 0) {
        if (var48) {
            var49[0xc5] |= 8;
        } else {
            var49[0xc5] &= ~8;
        }
    }
#endif
}
