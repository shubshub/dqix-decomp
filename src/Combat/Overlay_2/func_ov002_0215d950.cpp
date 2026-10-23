#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c508;
struct Struct_020465c0;
struct Struct_0201099c_10;
struct Struct_0207cf30_3;

extern "C" void *func_020421a0();
extern "C" int func_02041c08(char *arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" int func_02041ea4(char *arg0, int arg1);
extern "C" int func_02041b70(char *arg0, int arg1, const char *arg2);
extern "C" int func_02042058(char *arg0, const char *arg1);
extern "C" void func_0205c508(struct Struct_0205c508 *arg0, int *arg1, int *arg2);
extern "C" void func_02046380(void *arg0);
extern "C" void func_020465c0(Struct_020465c0 *arg0, int arg1, int arg2);
extern "C" char *func_020dedd0(Struct_0201099c_10 *arg0, int arg1);
extern "C" void func_0206819c(const char *arg0, char *arg1, int arg2);
extern "C" int func_020a0b3c(Struct_0207cf30_3 *arg0, int arg1);
extern "C" void func_ov002_0215b918(unsigned char *arg0, int arg1, int arg2, int arg3);
extern "C" void __clear(void *arg0, int arg1);
extern "C" int sprintf(char *arg0, const char *arg1, ...);
extern char data_ov002_0216d270[];
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

// USA: func_ov002_0215d950
extern "C" ARM void func_ov002_0215d950(char *arg0, char *arg1, int arg2) {
#if defined(jpn)
    char line[0x40];
    int out1, out2;
    char *tbl;
    void *msg;
    int n;
    int i;
    int count;
    if (dst == 0) return;
    int cursor = *(short *) (p + 0x1a00 + 0xb0) & 7;
    if (flag2) AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(dst, cursor);
    tbl       = (char *) GetPtrField0x2a04_02010828(GameState::GetInstance()) + 0xe04;
    msg       = GetGlobalField0x1c020421a0();
    char *fld = p + 0xe20;
    int sel   = *(int *) (fld + 0x68);
    count     = *(int *) (fld + 0x58);
    ComputeProductSums0205c508((struct UnkStruct0205c508 *) (fld + 0x54), &out1, &out2);
    n = 0;
    for (i = out1; i < out2; i++) {
        func_02046380(msg);
        StoreInArray0x8b0_020465c0((StoreStruct *) msg, 0, n);
        char *e = FindElementByKey020dedd0((Container020dedd0 *) (p + 0x750), *(short *) (tbl + i * 2 + 0xc));
        if (e != 0) {
            int len = StringLength_020d2ff0(dst);
            SetIndexedName02046574((struct Obj02046574 *) msg, 0, *(char **) (e + 4));
            func_020474a8(msg, 0xa, (const char *) KeyTable_Get((struct Container020e0310 *) (p + 8), 0x480),
                          dst + len);
            memset(line, 0, sizeof(line));
            sprintf(line, (const char *) KeyTable_Get((struct Container020e0310 *) (p + 8), 0x481),
                    LookupValueByKey020a0b3c((KeyMap020a0b3c *) tbl, *(short *) (e + 0x18)));
            AppendString02042058(dst, line);
            if (i != out2 - 1) AppendString02042058(dst, *(char **) (p + 0x1000 + 0xaa4));
        }
        var5++;
    }
    if (count > 1) {
        StoreInArray0x8b0_020465c0((StoreStruct *) msg, 0, sel + 1);
        StoreInArray0x8b0_020465c0((StoreStruct *) msg, 1, count);
        SetByteInRange_020465f0((unsigned char *) msg, 0, 2);
        SetByteInRange_020465f0((unsigned char *) msg, 1, 2);
        SetByteAtIndex_020465d8((unsigned char *) msg, 0, 1);
        SetByteAtIndex_020465d8((unsigned char *) msg, 1, 0);
        func_02042428(dst, 8);
        AppendString02042058(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (p + 8), 0x47f));
    }
#else
    char var13[0x100];
    char var14[0x40];
    int var15, var16;
    char *var17;
    int var18;
    int var19;
    int var20;
    if (arg1 == 0) return;
    int var21 = *(short *) (arg0 + 0x1be8) & 7;
    if (arg2) func_02041c08(arg1, var21, 8, 5, 5, 5);
    func_02041ea4(arg1, var21);
    var17       = (char *) func_02010828(GameState::GetInstance()) + 0xe04;
    void *var22 = func_020421a0();
    char *var23 = arg0 + 0x2c8 + 0xc00;
    int var24   = *(int *) (var23 + 0x68);
    var20     = *(int *) (var23 + 0x58);
    func_0205c508((struct Struct_0205c508 *) (var23 + 0x54), &var15, &var16);
    var18 = 0;
    for (var19 = var15; var19 < var16; var19++) {
        func_02046380(var22);
        func_020465c0((Struct_020465c0 *) var22, 0, var18);
        char *var25 = func_020dedd0((Struct_0201099c_10 *) (arg0 + 0x3ec + 0x400),
                                                                    *(short *) (var17 + var19 * 2 + 0xc));
        if (var25 != 0) {
            __clear(var13, sizeof(var13));
            func_0206819c(*(const char **) (var25 + 4), var13, 0);
            func_02041b70(arg1, var18, var13);
            __clear(var14, sizeof(var14));
            sprintf(var14, data_ov002_0216d270,
                    func_020a0b3c((Struct_0207cf30_3 *) var17, *(short *) (var25 + 0x18)));
            func_02042058(arg1, var14);
            if (var19 != var16 - 1) func_02042058(arg1, *(char **) (arg0 + 0x1000 + 0xbdc));
        }
        var18++;
    }
    if (var20 > 1) func_ov002_0215b918((unsigned char *) arg0, 10, var24, var20);
#endif
}
