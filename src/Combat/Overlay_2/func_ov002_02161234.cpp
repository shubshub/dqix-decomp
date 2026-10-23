#include "Resource/ActionDataTables.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_0201099c_3;
struct Struct_02046574_2;
struct Struct_020465c0;
struct Struct_020e4e38;

struct Struct_ov002_02161234 {
    char *unknown_0_;
    char *unknown_4_;
    int unknown_8_;
};

struct Struct_ov002_02161234_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

char *KeyTable_Get(struct Container020e0310 *c, int key);
char *GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void *messages);
void SetIndexedName02046574(struct Obj02046574 *obj, int index, char *str);
void *Clear12Bytes020e46c4(void *p);
extern "C" void *__clear(void *dst, int count);
void InitObjFromCombatantId020e4bf4(void *obj, int combatantId);
void StoreInArray0x8b0_020465c0(StoreStruct *messages, int index, int value);
void *SearchBothTables02079e2c(char *p, int key);
void InitObjFromPackedFields020e4e38(void *obj, struct Src020e4e38 *src);
unsigned char GetField0x397cValue_020100b0(GameState *battleStruct);
void Zero4Bytes_020e526c(void *reader);
void TryInvoke020e53bc_020e56fc(void *reader, int file, int size);
void *CallFunc020e52a0_020e5294(void *p, int key);
extern "C" void func_020e4f18(void *src, void *dst, int n);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
int AppendString02042058(char *dst, const char *src);
int StringLength_020d2ff0(const char *s);

extern "C" char data_ov002_0216d2bc[];
extern "C" char data_ov002_0216d2d2[];
extern "C" char data_ov002_0216d2e4[];
extern "C" char data_ov002_0216d2ea[];

static inline int inline_ov002_02161234(int arg0) {
    return (arg0 >= 0 && arg0 <= 3) ? 1 : 0;
}

// USA: func_ov002_02161234
extern "C" ARM void func_ov002_02161234(char *arg0, char *arg1) {
    char var0[0x80];
    char var1[0x80];
    char var2[0x80];
    char var3[0x80];
    Struct_ov002_02161234_2 var4;
    Struct_ov002_02161234_2 var5;
    Struct_ov002_02161234 var6;
    Struct_ov002_02161234 var7;
    Struct_ov002_02161234_2 var8;
    Struct_ov002_02161234_2 var9;
    unsigned int var10;
    if (arg1 == 0) {
        return;
    }
    KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x270e);
    GameState *gs = GameState::GetInstance();
    char *msgs    = GetGlobalField0x1c020421a0();
    GetGameResources();
    func_02046380(var12);
    char *var13;
    short var14;
    short var15 = *(short *) (arg0 + 0x1c28);
    int var16;
    GameObject *var17 = var11->GetUnknownGameObject();
    if (var17 != 0) {
        func_02046574((struct Struct_02046574_2 *) var12, 4, *(char **) ((char *) var17 + 0x134));
    }
    var14 = *(signed char *) (arg0 + 0x1c20);
    var16 = *(signed char *) (arg0 + 0x1c21);
    func_020e46c4(&var6);
    func_020e46c4(&var7);
    __clear(var0, 0x80);
    __clear(var1, 0x80);
    __clear(var2, 0x80);
    __clear(var3, 0x80);
    var6.unknown_0_ = var0;
    var6.unknown_4_ = var1;
    var7.unknown_0_ = var2;
    var7.unknown_4_ = var3;
    func_020e4bf4(&var4, var14);
    func_020e4bf4(&var5, var16);
    *(void **) (var12 + 0)    = &var4;
    *(void **) (var12 + 0x10) = &var5;
    if (inline_ov002_02161234(var16)) {
        int var18 = *(signed char *) (arg0 + 0x1c20);
        if (var18 == 4) {
            var18 = 9;
        }
        func_020465c0((Struct_020465c0 *) var12, 9, (var18 + 1) * 10 + var16);
    }
    if (*(short *) (arg0 + 0x1c26) != -1) {
        if (inline_ov002_02161234(var14)) {
            var13          = (char *) GetGameResources() + 0x435c + var14 * 0x30;
            GameObject *var19 = var11->GetPartyMemberByIndex(var14);
            if (var19 != 0) {
                var13 = *(char **) ((char *) var19 + 0x134);
            }
            func_02046574((struct Struct_02046574_2 *) var12, 0, var13);
        }
        char **var20 = (char **) func_02079e2c((char *) func_020797dc(), *(short *) (arg0 + 0x1c26));
        if (*var20 != 0) {
            var13 = *var20;
        }
        func_02046574((struct Struct_02046574_2 *) var12, 1, var13);
        func_020e4e38(&var8, (struct Struct_020e4e38 *) var20);
        *(void **) (var12 + 8) = &var8;
        if (inline_ov002_02161234(var16)) {
            func_02046574((struct Struct_02046574_2 *) var12, 2, arg0 + 0x1ab0 + var16 * 0x3c);
        }
        for (int var21 = 0; var21 < 2; var21++) {
            func_020465c0((Struct_020465c0 *) var12, var21, *(int *) (arg0 + var21 * 4 + 0x2490));
        }
    } else {
        if (inline_ov002_02161234(var14)) {
            var13          = (char *) GetGameResources() + 0x435c + var14 * 0x30;
            GameObject *var22 = var11->GetPartyMemberByIndex(var14);
            if (var22 != 0) {
                var13 = *(char **) ((char *) var22 + 0x134);
            }
            func_02046574((struct Struct_02046574_2 *) var12, 0, var13);
            func_020465c0((Struct_020465c0 *) var12, 0, 1);
        } else if (*(signed char *) (arg0 + 0x1c20) == 4) {
            func_020465c0((Struct_020465c0 *) var12, 0, 0);
            func_020e4bf4(&var4, func_020100b0(var11));
        }
        BackgroundLoader::AddLockGlobal();
        void *var23 = ExtractFileFromGP2(data_ov002_0216d2bc, data_ov002_0216d2d2, &var10);
        func_020e526c(&var9);
        func_020e56fc(&var9, (int) var23, var10);
        void *var24 = func_020e5294(&var9, *(short *) (arg0 + 0x1c22));
        void *var25 = func_020e5294(&var9, *(short *) (arg0 + 0x1c24));
        if (var24 != 0) {
            func_020e4f18(var24, &var6, 3);
            *(void **) (var12 + 0x18) = &var6;
        }
        if (var25 != 0) {
            func_020e4f18(var25, &var7, 3);
            *(void **) (var12 + 0x1c) = &var7;
        }
        if (var16 == 4) {
            func_020e4bf4(&var5, func_020100b0(var11));
        }
        BackgroundLoader::RemoveLockGlobal();
    }
    func_02046608(msgs, 0xc, KeyTable_Get((struct Container020e0310 *) (self + 0x20), *(short *) (self + 0x1c28)),
                  dst, 0xe3, 0, 1);
    AppendString02042058(dst, *(char **) (self + 0x1bdc));
    int len   = StringLength_020d2ff0(dst);
    char *fmt = KeyTable_Get((struct Container020e0310 *) (self + 0x20), *(short *) (self + 0x1c2a));
    if (fmt != 0) {
        func_02046608(msgs, 0xc, fmt, dst + len, 0xe3, 0, 1);
    }
    *(short *) (arg0 + 0x1c18) = func_020d2ff0(arg1);
    int var28                   = 1;
    if (*(int *) (arg0 + 0x1bbc) == 0x11 && var15 == 0x232b) {
        var28 = 0;
    }
    if (*(int *) (arg0 + 0x1bbc) == 0x17) {
        func_02042058(arg1, data_ov002_0216d2e4);
        return;
    }
    if (var28 && (var15 == 0x2367 || var15 == 0x2365 || var15 == 0x236f || var15 == 0x2372 || var15 == 0x238d || var15 == 0x125c ||
                 var15 == 0x125d || var15 == 0x125e || var15 == 0x232b || var15 == 0x797c || var15 == 0x2371))
    {
        if (*(short *) (arg0 + 0x1c26) == 0xd5 && var15 == 0x232b) {
            func_02042058(arg1, data_ov002_0216d2ea);
        } else {
            func_02042058(arg1, data_ov002_0216d2e4);
        }
    } else {
        func_02042058(arg1, data_ov002_0216d2ea);
    }
}
