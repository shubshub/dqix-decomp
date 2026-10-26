#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/OverlayId.h"

extern int data_ov000_02184220;

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char unknown0[0xe24];
#else
    char unknown0[0xea8];
#endif
    int state;
    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x7920 - 0xe2c];
#else
    char unknown_eb0_[0x7730 - 0xeb0];
#endif
    short unknown_7730_;
};

// USA: func_ov000_02160da0
extern "C" ARM void func_ov000_02160da0(Struct_ov000_02160da0* battle) {
    battle->state = 0x12;
    battle->unknown_eac_ = 0;
    data_ov000_02184220 = 1;
    battle->unknown_7730_ = BackgroundLoader::GetInstance()->QueueLoadOverlay(OVERLAY_ID(24));
}
