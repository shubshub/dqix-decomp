#include <globaldefs.h>
#include "GameState/Overlay17DayCycle.h"

#pragma define_section initcode ".init" RX

// USA: func_ov017_021d6ed0
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6ed0(void) {
    data_ov017_021d837c.unknown_14_ = data_ov017_021d75b8.unknown_10_ +
        (data_ov017_021d75b8.unknown_14_ +
        (data_ov017_021d75b8.unknown_8_ + data_ov017_021d75b8.unknown_c_));
    float var0 = data_ov017_021d837c.nightStart + data_ov017_021d75b8.unknown_8_;
    float var1 = data_ov017_021d75b8.unknown_c_;
    data_ov017_021d837c.morningStart = var0;
    var0 += var1;
    float var2 = data_ov017_021d75b8.unknown_14_;
    data_ov017_021d837c.dayStart = var0;
    var0 += var2;
    data_ov017_021d837c.eveningStart = var0;
}
