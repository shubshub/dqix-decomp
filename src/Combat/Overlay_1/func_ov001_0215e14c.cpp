#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a2b38(void* objRaw, int* a, int* b, int* c);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov001_02158f64(void* ctx, EventVec3 v1, EventVec3 v2, int d, int one, unsigned char arg5);

struct Struct_ov001_02165880_37 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_37 data_ov001_02165880;

// USA: func_ov001_0215e14c
extern "C" ARM int func_ov001_0215e14c(void* obj) {
    int flagResult = GameState_GetFollowCamera((char*)GameState::GetInstance());
    if (flagResult == 0) {
        return 0;
    }
    EventVec3 a, b, c;
    func_020a2b38((void*)flagResult, (int*)&a, (int*)&b, (int*)&c);
    int d = func_ov017_021d60f4(obj);
    func_ov001_02158f64(data_ov001_02165880.field24, a, b, d, 0, 0);
    return 1;
}
