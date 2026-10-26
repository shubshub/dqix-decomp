#include "Resource/ActionDataTables.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Container020e0310;
struct Obj02046574;
struct StoreStruct;
struct Struct_020e4e38;

struct Struct_ov002_02161234 {
    char *a;
    char *b;
    int c;
};

struct Struct_ov002_02161234_2 {
    int f0;
    int f4;
    int f8;
};

extern "C" char *KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" char *MessageSystem_GetInstance();
extern "C" void func_02046380(void *messages);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574 *obj, int index, char *str);
extern "C" void *NameText_Clear(void *p);
extern "C" void *__clear(void *dst, int count);
extern "C" void NameText_InitFromPartyMember(void *obj, int combatantId);
extern "C" void func_020465c0(StoreStruct *messages, int index, int value);
extern "C" void *func_02079e2c(char *p, int key);
extern "C" void func_020e4e38(void *obj, struct Struct_020e4e38 *src);
extern "C" unsigned char GameState_GetLeaderIndex(GameState *battleStruct);
extern "C" void func_020e526c(void *reader);
extern "C" void func_020e56fc(void *reader, int file, int size);
extern "C" void *func_020e5294(void *p, int key);
extern "C" void func_020e4f18(void *src, void *dst, int n);
extern "C" void MessageSystem_FormatText(void *messages, int a, const char *format, char *output, int size, int b, int c);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int STD_GetStringLength(const char *s);

extern "C" char data_ov002_0216d2bc[];
extern "C" char data_ov002_0216d2d2[];
extern "C" char data_ov002_0216d2e4[];
extern "C" char data_ov002_0216d2ea[];

static inline int inline_ov002_02161234(int i) {
    return (i >= 0 && i <= 3) ? 1 : 0;
}

// USA: func_ov002_02161234
extern "C" ARM void func_ov002_02161234(char *self, char *dst) {
    char buf1[0x80];
    char buf2[0x80];
    char buf3[0x80];
    char var3[0x80];
    Struct_ov002_02161234_2 name1;
    Struct_ov002_02161234_2 name2;
    Struct_ov002_02161234 pa;
    Struct_ov002_02161234 pb;
    Struct_ov002_02161234_2 packed;
    Struct_ov002_02161234_2 table;
    unsigned int size;
    if (dst == 0) {
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
    __clear(var3, 0x80);
    pa.a = buf1;
    pa.b = buf2;
    pb.a = buf3;
    pb.b = var3;
    NameText_InitFromPartyMember(&name1, sel);
    NameText_InitFromPartyMember(&name2, sub);
    *(void **) (msgs + 0)    = &name1;
    *(void **) (msgs + 0x10) = &name2;
    if (inline_ov002_02161234(sub)) {
        int k = *(signed char *) (self + 0x1c20);
        if (k == 4) {
            k = 9;
        }
        func_020465c0((StoreStruct *) msgs, 9, (k + 1) * 10 + sub);
    }
    if (*(short *) (self + 0x1c26) != -1) {
        if (inline_ov002_02161234(sel)) {
            name          = (char *) GetGameResources() + 0x435c + sel * 0x30;
            GameObject *m = gs->GetPartyMemberByIndex(sel);
            if (m != 0) {
                name = *(char **) ((char *) m + 0x134);
            }
            MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 0, name);
        }
        char **p = (char **) func_02079e2c((char *) func_020797dc(), *(short *) (self + 0x1c26));
        if (*p != 0) {
            name = *p;
        }
        MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 1, name);
        func_020e4e38(&packed, (struct Struct_020e4e38 *) p);
        *(void **) (msgs + 8) = &packed;
        if (inline_ov002_02161234(sub)) {
            MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 2, self + 0x1ab0 + sub * 0x3c);
        }
        for (int i = 0; i < 2; i++) {
            func_020465c0((StoreStruct *) msgs, i, *(int *) (self + i * 4 + 0x2490));
        }
    } else {
        if (inline_ov002_02161234(sel)) {
            name          = (char *) GetGameResources() + 0x435c + sel * 0x30;
            GameObject *m = gs->GetPartyMemberByIndex(sel);
            if (m != 0) {
                name = *(char **) ((char *) m + 0x134);
            }
            MessageSystem_SetStringArgument((struct Obj02046574 *) msgs, 0, name);
            func_020465c0((StoreStruct *) msgs, 0, 1);
        } else if (*(signed char *) (self + 0x1c20) == 4) {
            func_020465c0((StoreStruct *) msgs, 0, 0);
            NameText_InitFromPartyMember(&name1, GameState_GetLeaderIndex(gs));
        }
        BackgroundLoader::AddLockGlobal();
        void *file = ExtractFileFromGP2(data_ov002_0216d2bc, data_ov002_0216d2d2, &size);
        func_020e526c(&table);
        func_020e56fc(&table, (int) file, size);
        void *ea = func_020e5294(&table, *(short *) (self + 0x1c22));
        void *eb = func_020e5294(&table, *(short *) (self + 0x1c24));
        if (ea != 0) {
            func_020e4f18(ea, &pa, 3);
            *(void **) (msgs + 0x18) = &pa;
        }
        if (eb != 0) {
            func_020e4f18(eb, &pb, 3);
            *(void **) (msgs + 0x1c) = &pb;
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
    if (flag && (key == 0x2367 || key == 0x2365 || key == 0x236f || key == 0x2372 || key == 0x238d || key == 0x125c ||
                 key == 0x125d || key == 0x125e || key == 0x232b || key == 0x797c || key == 0x2371))
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
