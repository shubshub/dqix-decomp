#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"



struct Struct_0201c1c8 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206dfe8(void* p, int a, int b);

void ClearRegions0206e080(char* obj, int slot);
void ClearIndexedEntryFields0206e0d0(char* obj, int slot);
extern "C" void Scenario_SetFlag(void* obj, unsigned char* arr, int idx, int flag);

void GameState_SetStoryChapter(char* obj, int v);
void GameState_SetStoryPart(char* obj, int v);
void GameState_SetStoryStep(char* base, int val);

struct Struct_02108d70_5 {
    unsigned char unknown_0_;
    char unknown_1_[7];
    void* unknown_8_;
    char unknown_c_[4];
    int unknown_10_;
    int unknown_14_;
    char unknown_18_[8];
    int unknown_20_;
    char unknown_24_[4];
    int unknown_28_;
};
extern struct Struct_02108d70_5 data_02108d70;

// USA: func_020716a4
extern "C" ARM int func_020716a4(struct Struct_0201c1c8* arg0, int arg1) {
    int var0;
    int var1;
    int var2;
    int var3;
    int var4;
    void* var5;
    int var6;
    GameState* var7;

    var0 = ((Script::Parameter*)arg0)->ToInt();
    if (data_02108d70.unknown_14_ != var0) {
        return 1;
    }

    var1 = ((Script::Parameter*)(arg0 + 1))->ToInt();
    var2 = ((Script::Parameter*)(arg0 + 2))->ToInt();
    {
        struct Struct_0201c1c8* var8 = arg0 + 3;
        arg0 = arg0 + 4;
        var3 = ((Script::Parameter*)var8)->ToInt();
    }

    bs = GameState::GetInstance();
    GameState_SetStoryChapter((char*)bs, a);
    GameState_SetStoryPart((char*)bs, b);
    GameState_SetStoryStep((char*)bs, c);

    entry = Scenario_GetInstance();
    ClearRegions0206e080((char*)entry, *(unsigned char*)((char*)entry + 0x332));
    ClearIndexedEntryFields0206e0d0((char*)entry, *(unsigned char*)((char*)entry + 0x332));
    func_0206dfe8(entry, 0, 0x200);
    func_0206dfe8(entry, 0x38e, 0x3e8);

    for (var6 = 0; var6 < arg1 - 4; var6++) {
        var4 = ((Script::Parameter*)arg0)->ToInt();
        arg0 = arg0 + 1;
        switch (var4 >> 16) {
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
