#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02177300_4124 = 0xf98 };
enum { Enum_ov003_02177300_4144 = 0xfac };
enum { Enum_ov003_02177300_2204 = 0x818 };
#else
enum { Enum_ov003_02177300_4124 = 0x101c };
enum { Enum_ov003_02177300_4144 = 0x1030 };
enum { Enum_ov003_02177300_2204 = 0x89c };
#endif

#include "GameState/GameState.h"

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02177300
#pragma opt_common_subs off
extern "C" ARM void func_ov003_02177300(char* self) {
    GameState* battle = GameState::GetInstance();
    int field = *(int*)(self + Enum_ov003_02177300_4144);
    struct Struct_0207fdcc_2* var2 = *(struct Struct_0207fdcc_2**)(self + Enum_ov003_02177300_2204);
    int key1 = -1, key2 = -1;

    switch (field) {
    case 2:
        key1 = 0xb;
        key2 = 0x5d;
        break;
    case 3:
        key1 = 0xc;
        key2 = 0x60;
        break;
    case 4:
        key1 = 0xd;
        key2 = 0x64;
        break;
    }
    if (key1 < 0) {
        return;
    }

    func_02080c20(var2, key1);
    func_02080c68(var2, key1, 0);

    int hp;
    unsigned char i;
    for (i = 0; i < *(int*)(self + Enum_ov003_02177300_4144); i++) {
        hp = 0;
        GameObject* combatant = func_0200ff1c(battle, *(int*)(self + Enum_ov003_02177300_4124 + i * 4));
        if (combatant != 0) {
            hp = *(int*)((char*)combatant + 0x134);
        }
        func_02080f8c((struct Container02080f8c*)var2, key2, hp);

        int var8 = func_020dcc98((signed char)*(int*)(self + Enum_ov003_02177300_4124 + i * 4));
        func_02080cc0((struct Struct_02080cc0*)var2, key2, var8);

        key2 = (short)(key2 + 1);
    }

    func_020813ec(var2, key1);
}
