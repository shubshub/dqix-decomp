#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"



struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206dfe8(void* p, int a, int b);

extern "C" void func_0206e080(char* obj, int slot);
extern "C" void func_0206e0d0(char* obj, int slot);
extern "C" void Scenario_SetFlag(void* obj, unsigned char* arr, int idx, int flag);

extern "C" void GameState_SetStoryChapter(char* obj, int v);
extern "C" void GameState_SetStoryPart(char* obj, int v);
extern "C" void GameState_SetStoryStep(char* base, int val);

struct Struct_02108d70_5 {
    unsigned char unknown_0_;
    char pad1[7];
    void* entries;
    char pad2[4];
    int limit;
    int field14;
    char pad18[8];
    int unknown_20_;
    char pad20[4];
    int count;
};
extern struct Struct_02108d70_5 data_02108d70;

// USA: func_020716a4
extern "C" ARM int func_020716a4(struct Variant02030b0c* args, int count) {
    int v0;
    int a;
    int b;
    int c;
    int v;
    void* entry;
    int i;
    GameState* bs;

    v0 = ((Script::Parameter*)args)->ToInt();
    if (data_02108d70.field14 != v0) {
        return 1;
    }

    a = ((Script::Parameter*)(args + 1))->ToInt();
    b = ((Script::Parameter*)(args + 2))->ToInt();
    {
        struct Variant02030b0c* last = args + 3;
        args = args + 4;
        c = ((Script::Parameter*)last)->ToInt();
    }

    bs = GameState::GetInstance();
    GameState_SetStoryChapter((char*)bs, a);
    GameState_SetStoryPart((char*)bs, b);
    GameState_SetStoryStep((char*)bs, c);

    entry = Scenario_GetInstance();
    func_0206e080((char*)entry, *(unsigned char*)((char*)entry + 0x332));
    func_0206e0d0((char*)entry, *(unsigned char*)((char*)entry + 0x332));
    func_0206dfe8(entry, 0, 0x200);
    func_0206dfe8(entry, 0x38e, 0x3e8);

    for (i = 0; i < count - 4; i++) {
        v = ((Script::Parameter*)args)->ToInt();
        args = args + 1;
        switch (v >> 16) {
        case 2:
            Scenario_SetFlag(entry, (unsigned char*)entry + *(unsigned char*)((char*)entry + 0x332) * 0x1c + 3, (unsigned short)v, 1);
            break;
        case 1:
            Scenario_SetFlag(entry, (unsigned char*)entry + *(unsigned char*)((char*)entry + 0x332) * 0x1c + 0x10, (unsigned short)v, 1);
            break;
        case 0:
            Scenario_SetFlag(entry, (unsigned char*)entry + 0x8c, (unsigned short)v, 1);
            break;
        }
    }

    return 1;
}
