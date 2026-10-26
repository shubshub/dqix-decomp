#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0202b000_1342 = 0x753e - 0x6fc0 };
#else
enum { Enum_0202b000_1342 = 0x74fe - 0x6fc0 };
#endif
#include "GameState/GameState.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_0202b000 { unsigned char unknown_0_[6]; };
struct Struct_0202b000_2 {
    int unknown_0_;
    unsigned short unknown_4_;
    char unknown_6_[0x102c - 6];
    Struct_0202b000 unknown_102c_;
};
extern "C" void LinkSession_Reset(BattleObject0202b000*);
void VCountIrq_PushDisable();
int IncrementSlotIndex020d4dd4();
int InitBattleWorkAndPoll0202d9e0();
int SetBattleContextField0xc8IfIdle_020d472c(void*);
void SetField0x8Of02101640_0202d688(int);
extern "C" int LinkSession_WaitForIdle(BattleObject0202b000*, int);
void WH_Reset();
int DispatchSizedRequest020d5974(void*, int, int);
extern "C" void VCountIrq_PopDisable();
void SetGlobalStateIfField4Is16_0202ae30(void*);

// USA: func_0202b000
extern "C" ARM unsigned char func_0202b000(BattleObject0202b000* obj) {
    LinkSession_Reset(obj);
    VCountIrq_PushDisable();
    obj->slot = IncrementSlotIndex020d4dd4();
    int attempts = 0;
    while (!InitBattleWorkAndPoll0202d9e0()) {
        attempts++;
        if (attempts > 5000) break;
        SleepCurrentContext(1);
    }
    SetBattleContextField0xc8IfIdle_020d472c((void*)SetGlobalStateIfField4Is16_0202ae30);
    SetField0x8Of02101640_0202d688(0x785);
    obj->active = 1;
    int result = LinkSession_WaitForIdle(obj, 1);
    if (result) {
        WH_Reset();
        LinkSession_WaitForIdle(obj, 1);
    }
    DispatchSizedRequest020d5974(0, 255, 235);
    GameState* state = GameState::GetInstance();
    BattleSelection0202b000 selection = *(BattleSelection0202b000*)&state->unk_6fc0[kSelectionIndex];
    obj->selection = selection;
    VCountIrq_PopDisable();
    return result;
}
