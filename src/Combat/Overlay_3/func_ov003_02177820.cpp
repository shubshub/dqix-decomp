#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02177820_4144 = 0xfac };
enum { Enum_ov003_02177820_4124 = 0xf98 };
enum { kRegion89c = 0x818 };
#else
enum { Enum_ov003_02177820_4144 = 0x1030 };
enum { Enum_ov003_02177820_4124 = 0x101c };
enum { kRegion89c = 0x89c };
#endif

#include "GameState/GameState.h"

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_02080bac(void* obj, int id);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
extern "C" void func_020813ec(void* obj, int key);
extern "C" void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov003_02177820
#pragma opt_common_subs off
extern "C" ARM void func_ov003_02177820(char* self) {
    struct Struct_0207fdcc_2* var0 = *(struct Struct_0207fdcc_2**)(self + kRegion89c);
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);

    int field = *(int*)(self + Enum_ov003_02177820_4144);
    int a = 0x11, b = 0x79;
    switch (field) {
    case 2: a = 0x12; b = 0x7c; break;
    case 3: a = 0x13; b = 0x80; break;
    case 4: a = 0x14; b = 0x85; break;
    }

    func_02080c20(var0, a);
    func_02080c68(var0, a, 0);
    func_02080bac(var0, a);

    int hp;
    unsigned char i;
    for (i = 0; i < *(int*)(self + Enum_ov003_02177820_4144); i++) {
        hp = 0;
        GameObject* combatant = battle->GetPartyMemberByIndex(*(int*)(self + Enum_ov003_02177820_4124 + i * 4));
        if (combatant != 0) {
            hp = *(int*)((char*)combatant + 0x134);
        }
        func_02080f8c((struct Container02080f8c*)var0, b, hp);

        int var8 = func_020dcc98((signed char)*(int*)(self + Enum_ov003_02177820_4124 + i * 4));
        func_02080cc0((struct Struct_02080cc0*)var0, b, var8);

        b = (short)(b + 1);
    }

    func_020813ec(var0, a);
}
