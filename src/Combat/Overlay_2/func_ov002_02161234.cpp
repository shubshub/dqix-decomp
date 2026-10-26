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
char *MessageSystem_GetInstance();
extern "C" void func_02046380(void *messages);
void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
void *NameText_Clear(void *p);
extern "C" void *__clear(void *dst, int count);
void NameText_InitFromPartyMember(void *obj, int combatantId);
void StoreInArray0x8b0_020465c0(StoreStruct *messages, int index, int value);
void *SearchBothTables02079e2c(char *p, int key);
void InitObjFromPackedFields020e4e38(void *obj, struct Src020e4e38 *src);
unsigned char GameState_GetLeaderIndex(GameState *battleStruct);
void Zero4Bytes_020e526c(void *reader);
void TryInvoke020e53bc_020e56fc(void *reader, int file, int size);
void *CallFunc020e52a0_020e5294(void *p, int key);
extern "C" void func_020e4f18(void *src, void *dst, int n);
extern "C" void MessageSystem_FormatText(void *messages, int a, const char *format, char *output, int size, int b, int c);
int Text_Append(char *dst, const char *src);
int STD_GetStringLength(const char *s);

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
    char *msgs    = MessageSystem_GetInstance();
    GetGameResources();
    func_02046380(msgs);
    char *name;
    short sel;
    short key = *(short *) (self + 0x1c28);
    int sub;
    GameObject *u = gs->GetLeader();
    if (u != 0) {
        MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 4, *(char **) ((char *) u + 0x134));
    }
    sel = *(signed char *) (self + 0x1c20);
    sub = *(signed char *) (self + 0x1c21);
    NameText_Clear(&pa);
    NameText_Clear(&pb);
    __clear(buf1, 0x80);
    __clear(buf2, 0x80);
    __clear(buf3, 0x80);
    __clear(buf4, 0x80);
    pa.a = buf1;
    pa.b = buf2;
    pb.a = buf3;
    pb.b = buf4;
    NameText_InitFromPartyMember(&name1, sel);
    NameText_InitFromPartyMember(&name2, sub);
    *(void **) (msgs + 0)    = &name1;
    *(void **) (msgs + 0x10) = &name2;
    if (InParty02161234(sub)) {
        int k = *(signed char *) (self + 0x1c20);
        if (k == 4) {
            k = 9;
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
            MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 0, name);
        }
        char **var20 = (char **) func_02079e2c((char *) func_020797dc(), *(short *) (arg0 + 0x1c26));
        if (*var20 != 0) {
            var13 = *var20;
        }
        MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 1, name);
        InitObjFromPackedFields020e4e38(&packed, (struct Src020e4e38 *) p);
        *(void **) (msgs + 8) = &packed;
        if (InParty02161234(sub)) {
            MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 2, self + 0x1ab0 + sub * 0x3c);
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
            MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 0, name);
            StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, 1);
        } else if (*(signed char *) (self + 0x1c20) == 4) {
            StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, 0);
            NameText_InitFromPartyMember(&name1, GameState_GetLeaderIndex(gs));
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
        if (sub == 4) {
            NameText_InitFromPartyMember(&name2, GameState_GetLeaderIndex(gs));
        }
        BackgroundLoader::RemoveLockGlobal();
    }
    MessageSystem_FormatText(msgs, 0xc, KeyTable_Get((struct Container020e0310 *) (self + 0x20), *(short *) (self + 0x1c28)),
                  dst, 0xe3, 0, 1);
    Text_Append(dst, *(char **) (self + 0x1bdc));
    int len   = STD_GetStringLength(dst);
    char *fmt = KeyTable_Get((struct Container020e0310 *) (self + 0x20), *(short *) (self + 0x1c2a));
    if (fmt != 0) {
        MessageSystem_FormatText(msgs, 0xc, fmt, dst + len, 0xe3, 0, 1);
    }
    *(short *) (self + 0x1c18) = STD_GetStringLength(dst);
    int flag                   = 1;
    if (*(int *) (self + 0x1bbc) == 0x11 && key == 0x232b) {
        flag = 0;
    }
    if (*(int *) (self + 0x1bbc) == 0x17) {
        Text_Append(dst, data_ov002_0216d2e4);
        return;
    }
    if (var28 && (var15 == 0x2367 || var15 == 0x2365 || var15 == 0x236f || var15 == 0x2372 || var15 == 0x238d || var15 == 0x125c ||
                 var15 == 0x125d || var15 == 0x125e || var15 == 0x232b || var15 == 0x797c || var15 == 0x2371))
    {
        if (*(short *) (self + 0x1c26) == 0xd5 && key == 0x232b) {
            Text_Append(dst, data_ov002_0216d2ea);
        } else {
            Text_Append(dst, data_ov002_0216d2e4);
        }
    } else {
        Text_Append(dst, data_ov002_0216d2ea);
    }
}
