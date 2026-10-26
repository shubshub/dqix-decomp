#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_021564cc_336 = 0x144, Enum_ov000_021564cc_2384 = 0x8b8 };
#else
enum { Enum_ov000_021564cc_336 = 0x150, Enum_ov000_021564cc_2384 = 0x950 };
#endif
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern unsigned char data_ov000_02182ac5[];

struct Struct_ov000_021564cc {
    char pad[Enum_ov000_021564cc_2384];
    int idx;
};

// USA: func_ov000_021564cc
extern "C" ARM int func_ov000_021564cc(struct Random* arg0, int id) {
    GameState* bs = GameState::GetInstance();
    int inRange = (id >= 0 && id <= 3);
    if (!inRange) return 0;
    GameObject* combatant = func_0200ff1c(bs, id);
    if (combatant == NULL) return 0;
    unsigned char* field150 = *(unsigned char**)((char*)combatant + Enum_ov000_021564cc_336);
    if (!func_02083b00(field150, 0xd0)) return 0;
    struct Struct_ov000_021564cc* var4 = *(struct Struct_ov000_021564cc**)((char*)combatant + Enum_ov000_021564cc_336);
    int idx = var4->idx;
    int var6 = data_ov000_02182ac5[idx];
    int pick = NextRandomMax(arg0, var6);
    return (pick == 1);
}
