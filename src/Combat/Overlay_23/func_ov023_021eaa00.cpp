#include <globaldefs.h>
#include "GameState/GameState.h"

void* GameState_GetParty(GameState* battleStruct);

struct Obj02086aec;
short Party_CountItem(struct Obj02086aec* obj, int key);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021eaa00
extern "C" ARM int func_ov023_021eaa00(void* obj) {
    struct Obj02086aec* p = (struct Obj02086aec*)GameState_GetParty(GameState::GetInstance());
    int sum = 0;
    sum = sum + Party_CountItem(p, 0x5619);
    sum = sum + Party_CountItem(p, 0x561d);
    sum = sum + Party_CountItem(p, 0x561e);
    sum = sum + Party_CountItem(p, 0x561f);
    sum = sum + Party_CountItem(p, 0x5620);
    sum = sum + Party_CountItem(p, 0x5621);
    sum = sum + Party_CountItem(p, 0x5622);
    sum = sum + Party_CountItem(p, 0x5623);
    sum = sum + Party_CountItem(p, 0x5624);
    sum = sum + Party_CountItem(p, 0x5625);
    func_ov017_021d6134(obj, sum);
    return 1;
}
