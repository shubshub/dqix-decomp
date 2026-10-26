#include <globaldefs.h>
#if defined(jpn)
enum { kRegion874 = 0x7f0 };
enum { Enum_ov003_02179cfc_4168 = 0xfc4 };
#else
enum { kRegion874 = 0x874 };
enum { Enum_ov003_02179cfc_4168 = 0x1048 };
#endif

#include "GameState/GameState.h"

struct Struct_02052df8;
struct ItemTable;
struct Element020de650;

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02052df8(struct Struct_02052df8* obj, int index);
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

struct Struct_ov003_0217fb68 { unsigned int v[9]; };
extern struct Struct_ov003_0217fb68 data_ov003_0217fb68;

struct Struct_ov003_02179cfc {
    char pad[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
};

// USA: func_ov003_02179cfc
extern "C" ARM void* func_ov003_02179cfc(char* base, int combatantId, struct Struct_ov003_02179cfc* arg2) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == NULL) return arg2;

    struct Struct_ov003_0217fb68 table = data_ov003_0217fb68;

    int val = func_02052df8((struct Struct_02052df8*)combatant, table.v[arg2->unknown_8_0_]);
    if (val == -1) return arg2;

    struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(base + kRegion874), val);
    if (elem == NULL) return arg2;

    *(unsigned short*)(base + Enum_ov003_02179cfc_4168) = val;
    return elem;
}
