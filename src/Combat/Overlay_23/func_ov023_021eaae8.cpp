#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int func_ov017_021d60f4(void* obj);

struct Obj02086aec;
extern "C" short Party_CountItem(struct Obj02086aec* obj, int key);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021eaae8
extern "C" ARM int func_ov023_021eaae8(void* obj) {
    struct Obj02086aec* p = (struct Obj02086aec*)GameState_GetParty(GameState::GetInstance());
    short key = (short)func_ov017_021d60f4(obj);
    int v = Party_CountItem(p, key);
    func_ov017_021d6134((char*)obj + 8, v);
    return 1;
}
