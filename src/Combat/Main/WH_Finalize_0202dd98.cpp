#include <globaldefs.h>
#if defined(jpn)
#define data_021023c0 data_02102100
#endif

struct BattleDispatchState { char pad0[0x10]; int state_; char pad14[0x34 - 0x14]; int mode_; };
struct BattleEffectContext { char data_[0x820]; };
extern BattleDispatchState data_021015a0;
extern BattleEffectContext data_021023c0, data_02102be0;
int AdvanceStateIfState2_0202d0b4();
void WH_Reset();
int ForwardClearBattleSubEffectAt0x800020d68d0(void*);
void SetField0x48UnlessState9Or10_0202c848(int);
int SetState3AndDispatch_0202d54c();
int ClearBattleSubEffectAt0x800_020d5f88(void*);
int SetState3AndDispatch_0202cca4();

static inline int inline_0202dd98() { return data_021015a0.unknown_10_; }

// Main, originally func_0202dd98 (USA 0x0202dd98, EUR 0x0202dda8, JPN 0x0202d908)
extern "C" ARM void WH_Finalize() {
    if (data_021015a0.state_ == 1) return;
    if (data_021015a0.state_ == 2) {
        if (!AdvanceStateIfState2_0202d0b4()) WH_Reset();
        return;
    }
    if (data_021015a0.state_ != 6 && data_021015a0.state_ != 5 && data_021015a0.state_ != 4) {
        data_021015a0.state_ = 3;
        WH_Reset();
        return;
    }
    data_021015a0.unknown_10_ = 3;
    switch (data_021015a0.unknown_34_) {
    case 3: {
        int var0;
        int var1 = inline_0202dd98();
        if (var1 != 6) var0 = 0;
        else {
            data_021015a0.unknown_10_ = var1;
            int var2 = func_020d68d0(&data_021023c0);
            if (var2) { func_0202c848(var2); var0 = 0; }
            else if (!func_0202d54c()) var0 = 0;
            else var0 = 1;
        }
        if (!result) WH_Reset();
        break;
    }
    case 5:
        if (ClearBattleSubEffectAt0x800_020d5f88(&data_02102be0)) { WH_Reset(); break; }
    case 1:
        if (!SetState3AndDispatch_0202d54c()) WH_Reset();
        break;
    case 2: {
        int result;
        int status = ForwardClearBattleSubEffectAt0x800020d68d0(&data_021023c0);
        if (status) { SetField0x48UnlessState9Or10_0202c848(status); result = 0; }
        else if (SetState3AndDispatch_0202cca4()) result = 1;
        else { WH_Reset(); result = 0; }
        if (!result) WH_Reset();
        break;
    }
    case 4:
        if (ClearBattleSubEffectAt0x800_020d5f88(&data_02102be0)) { WH_Reset(); break; }
    case 0:
        if (!SetState3AndDispatch_0202cca4()) WH_Reset();
        break;
    }
}
