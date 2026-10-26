#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned short func_ov004_0215eb20(void* obj, int bit);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);

struct Struct_ov004_021707f0 {
    signed char entry;
    signed char count;
    char unknown2[0x12];
    int combatant;
    char unknown18[0xc];
};

signed char data_ov004_021707e8[6];
Struct_ov004_021707f0 data_ov004_021707f0;
extern unsigned char data_ov004_02170820[];
extern int data_ov004_02170854[];

// USA: func_ov004_0215ef14
extern "C" ARM void func_ov004_0215ef14() {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), data_ov004_021707f0.combatant);
    int order = 0;
    for (int i = 1; i < 13; i++) {
        if (func_ov004_0215eb20(combatant, data_ov004_02170854[i])) {
            data_ov004_021707f0.count++;
            data_ov004_02170820[data_ov004_02170854[i] - 1] = order;
            data_ov004_021707e8[5]++;
            order++;
        }
    }
}
