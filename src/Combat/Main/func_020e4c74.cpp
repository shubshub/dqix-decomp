#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_020e4c74 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" void func_020e4b34(void* obj, struct BaseCombatStats* arg1, struct BaseCombatStats* arg2,
    int p4, int p5, int p6, int p7, int p8, int p9, int p10, int arg10, int arg11);

// USA: func_020e4c74
extern "C" ARM void func_020e4c74(void* obj, GameObject* combatant) {
    memset(obj, 0, 0xc);
    if (combatant != NULL) {
        struct Struct_020e4c74* sub = *(struct Struct_020e4c74**)((char*)combatant + 0x150);
        func_020e4b34(obj, combatant->baseStats_, combatant->baseStats_, 0, 0, 0, 0, sub->bit0, 0, 1, 0, 1);
    }
}
