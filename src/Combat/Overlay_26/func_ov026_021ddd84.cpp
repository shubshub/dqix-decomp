#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

struct GameState;
struct Struct_ov000_02160da0;
struct Struct_ov000_02161e30;
struct PartyState;

extern "C" void* LinkSession_GetInstance(GameState* gs);
extern "C" void* func_0207d78c();
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" void func_ov026_021dbd1c(Struct_ov000_02160da0* self, int index, unsigned char flag);

// USA: func_ov026_021ddd84
extern "C" ARM int func_ov026_021ddd84(GameResources* res, Struct_ov000_02160da0* self, Struct_ov000_02161e30* battle, PartyState* party, void* list, unsigned char* arg5, unsigned char flag) {
    LinkSession_GetInstance(GameState::GetInstance());
    func_0207d78c();
    int index = func_ov017_02195658(res);
    if (index <= -1) {
        return 0;
    }
    func_ov026_021dbd1c(self, index, flag);
    return 1;
}
