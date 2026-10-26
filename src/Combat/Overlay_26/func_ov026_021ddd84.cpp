#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

struct GameState;
struct Struct_ov000_02160da0;
struct Struct_ov000_02161e30;
struct Struct_ov000_0217e870_2;

extern "C" void* LinkSession_GetInstance(GameState* gs);
void* GetData02108ea8_0207d78c();
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" void func_ov026_021dbd1c(BattleWork* self, int index, unsigned char flag);

// USA: func_ov026_021ddd84
extern "C" ARM int func_ov026_021ddd84(GameResources* res, BattleWork* self, BattleState* battle, PartyState* party, void* list, unsigned char* turnFlag, unsigned char flag) {
    LinkSession_GetInstance(GameState::GetInstance());
    GetData02108ea8_0207d78c();
    int index = func_ov017_02195658(res);
    if (index <= -1) {
        return 0;
    }
    func_ov026_021dbd1c(arg1, var0, arg6);
    return 1;
}
