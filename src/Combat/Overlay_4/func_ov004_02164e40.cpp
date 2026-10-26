#include <globaldefs.h>
#if defined(jpn)
extern char data_ov004_02170e42;
extern char data_ov004_02170598;
extern "C" void* func_02011aa0(char*, unsigned int);
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);

struct Struct_ov004_021549e4_2 {
    char pad[0x28];
    unsigned short field28;
};
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);

struct Struct_02046574 { char c[0x40]; };
struct Obj02046574 {
    char pad[0x4ac];
    struct Struct_02046574 names[16];
};
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void func_020464e8(char* base, int index, char* src);

extern unsigned char* data_ov004_02171010;

// USA: func_ov004_02164e40
extern "C" ARM int func_ov004_02164e40(void* obj) {
    void* g = (void*)MessageSystem_GetInstance();
    func_02046380(g);

    GameState* battle = GameState::GetInstance();
    GameState_GetProtagonistIndex(battle);
    GameObject* combatant = battle->GetLeader();

    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;

    unsigned int idx = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)node);

#if defined(jpn)
    char prefix[32];
    char suffix[32];
    char mapKind[32];
    char level[32];
    VectorizedMemset(prefix, 0, 32);
    VectorizedMemset(suffix, 0, 32);
    VectorizedMemset(mapKind, 0, 32);
    VectorizedMemset(level, 0, 32);

    unsigned int off = idx * 0x1e4;
    unsigned char* base = data_ov004_02171010;
    unsigned char* var11 = base + 0xad5;
    var11 = var11 + off;
    unsigned char kind = *var11;
    if (kind == 1) {
        char* row = (char*)base + 0xb20 + off;
        strcpy(prefix, row + 0x3b);
        char* var14 = (char*)data_ov004_02171010 + 0xb20;
        var14 = var14 + off;
        strcpy(suffix, var14 + 0x5b);
        strcpy(mapKind, &data_ov004_02170e42);
        char* var15 = (char*)data_ov004_02171010 + 0xb20;
        var15 = var15 + off;
        strcpy(level, var15 + 0x9b);
    } else if (kind == 2) {
        char* row = (char*)base + 0xb20 + off;
        strcpy(prefix, row + 0x90);
        char* var17 = (char*)data_ov004_02171010 + 0xb20;
        var17 = var17 + off;
        strcpy(suffix, var17 + 0xb0);
        strcpy(mapKind, &data_ov004_02170598);
        char* var18 = (char*)data_ov004_02171010 + 0xb20;
        var18 = var18 + off;
        strcpy(level, var18 + 0xd0);
    }
    if (combatant) {
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)combatant->baseStats_);
    }
    MessageSystem_SetStringArgument((Obj02046574*)g, 1, prefix);
    MessageSystem_SetStringArgument((Obj02046574*)g, 2, suffix);
    MessageSystem_SetStringArgument((Obj02046574*)g, 3, mapKind);
    MessageSystem_SetStringArgument((Obj02046574*)g, 4, level);
    MessageSystem_SetStringArgument((Obj02046574*)g, 5, (char*)func_02011aa0((char*)battle, 0));
    MessageSystem_SetStringArgument((Obj02046574*)g, 6, (char*)func_02011aa0((char*)battle, 1));
    MessageSystem_SetStringArgument((Obj02046574*)g, 7, (char*)func_02011aa0((char*)battle, 2));
    MessageSystem_SetStringArgument((Obj02046574*)g, 8, (char*)func_02011aa0((char*)battle, 3));
#else
    char buf[0x40];
    VectorizedMemset(buf, 0, 0x40);

    unsigned char* base = data_ov004_02171010;
    unsigned int off = idx * 0x1c4;
    unsigned char* var22 = base + 0xad5;
    var22 = var22 + off;
    unsigned char kind = *var22;
    if (kind == 1) {
        char* row = (char*)base + 0xb20;
        row = row + off;
        strcpy(buf, row + 0x63);
    } else if (kind == 2) {
        char* row = (char*)base + 0xb20;
        row = row + off;
        strcpy(buf, row + 0xf8);
    }

    if (combatant) {
        char* name = (char*)combatant->baseStats_;
        MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, name);
    }
    func_020464e8((char*)g, 0, buf);
#endif
    return 0;
}
