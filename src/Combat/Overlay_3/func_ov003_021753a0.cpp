#include <globaldefs.h>
#if defined(jpn)
enum { kNodeOffset = 0x7f0 };
enum { Enum_ov003_021753a0_4096 = 0xf00 };
enum { Enum_ov003_021753a0_58 = 0xb6 };
#else
enum { kNodeOffset = 0x874 };
enum { Enum_ov003_021753a0_4096 = 0x1000 };
enum { Enum_ov003_021753a0_58 = 0x3a };
#endif
#include "Combat/Main/MessageSlotTable.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

extern "C" GameObject* func_0200ff94(GameState* battleStruct, int combatantId);

extern "C" int func_020dd4c4(void* id, void* node);
extern "C" void func_020dd7ac(void* buf);
extern "C" void func_020dd8b4(int buf, int id, int node, int flag);

extern unsigned char data_ov003_0217fac8[];

struct Struct_ov003_021753a0 {
    char pad[0xc];
    unsigned int lo : 7;
    unsigned int kind : 4;
    unsigned int hi : 21;
};

// USA: func_ov003_021753a0
#pragma opt_common_subs off
extern "C" ARM int func_ov003_021753a0(char* obj, int id, int arg2, int arg3) {
    int result = 1;
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = func_0200ff94(battle, id);
    if (combatant == 0) return result;

    int key = *(short*)(obj + Enum_ov003_021753a0_4096 + Enum_ov003_021753a0_58);
    struct Element020de650* node = ItemTable_Find((struct ItemTable*)(obj + kNodeOffset), key);
    if (node == 0) return result;

    func_020dd4c4((void*)id, node);

    Struct_020dd7ac buf;
    func_020dd7ac(&buf);
    func_020dd8b4((int)&buf, id, (int)node, 0);

    int kind = ((struct Struct_ov003_021753a0*)node)->kind;
    unsigned char var7 = data_ov003_0217fac8[kind];
    func_020dd9b4(&buf, var7, (void*)arg2, (void*)arg3);

    switch (var7) {
    case 3:
    case 4:
        result = 0;
        break;
    }
    return result;
}
