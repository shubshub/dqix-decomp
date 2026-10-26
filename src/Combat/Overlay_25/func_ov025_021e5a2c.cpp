#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e5a2c_24576 = 0x7000, Enum_ov025_021e5a2c_4053 = 0x1c5 };
#else
enum { Enum_ov025_021e5a2c_24576 = 0x6000, Enum_ov025_021e5a2c_4053 = 0xfd5 };
#endif

#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

struct Struct_ov025_021e5a2c {
    char unknown0[Enum_ov025_021e5a2c_24576 + Enum_ov025_021e5a2c_4053];
    unsigned char unknown_6fd5_;
};
struct CameraState {
    int unknown0;
    Vector3i vector;
};
struct Struct_ov025_021e5a2c_2 {
    char unknown0[8];
    Vector3i vector;
};
extern "C" Struct_ov025_021e5a2c* func_ov000_02160130(void);

// USA: func_ov025_021e5a2c
extern "C" ARM int func_ov025_021e5a2c(Struct_ov025_021e5a2c_2* command) {
    GameState* bs = GameState::GetInstance();
    CameraState* f = (CameraState*)bs->GetCamera();
    if (f != 0) {
        f->vector = command->vector;
    }
    Struct_ov025_021e5a2c* w = func_ov000_02160130();
    if (w) {
        w->unknown_6fd5_ = 1;
    }
    return 1;
}
