#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0202b000_1342 = 0x753e - 0x6fc0 };
#else
enum { Enum_0202b000_1342 = 0x74fe - 0x6fc0 };
#endif
#include "GameState/GameState.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_0202b000 { unsigned char values[6]; };
struct BattleObject0202b000 {
    int active;
    unsigned short slot;
    char unknown_6_[0x102c - 6];
    Struct_0202b000 selection;
};
extern "C" void LinkSession_Reset(BattleObject0202b000*);
extern "C" void VCountIrq_PushDisable();
extern "C" int func_020d4dd4();
extern "C" int func_0202d9e0();
extern "C" int func_020d472c(void*);
extern "C" void func_0202d688(int);
extern "C" int LinkSession_WaitForIdle(BattleObject0202b000*, int);
extern "C" void WH_Reset();
extern "C" int func_020d5974(void*, int, int);
extern "C" void VCountIrq_PopDisable();
extern "C" void func_0202ae30(void*);

// USA: func_0202b000
extern "C" ARM unsigned char func_0202b000(BattleObject0202b000* obj) {
    LinkSession_Reset(obj);
    VCountIrq_PushDisable();
    obj->slot = func_020d4dd4();
    int var0 = 0;
    while (!func_0202d9e0()) {
        var0++;
        if (var0 > 5000) break;
        SleepCurrentContext(1);
    }
    func_020d472c((void*)func_0202ae30);
    func_0202d688(0x785);
    obj->active = 1;
    int result = LinkSession_WaitForIdle(obj, 1);
    if (result) {
        WH_Reset();
        LinkSession_WaitForIdle(obj, 1);
    }
    func_020d5974(0, 255, 235);
    GameState* state = GameState::GetInstance();
    Struct_0202b000 selection = *(Struct_0202b000*)&state->unk_6fc0[Enum_0202b000_1342];
    obj->selection = selection;
    VCountIrq_PopDisable();
    return result;
}
