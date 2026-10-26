#include <globaldefs.h>
#include "Graphics/LightingManager.h"

struct Struct_ov025_021e74f4_2 {
    char unknown0[8];
    fix16_t targetBrightness;
    unsigned short duration;
};
struct Struct_ov025_021e74f4 {
#if defined(jpn)
    char unknown0[0x71c4];
#else
    char unknown0[0x6fd4];
#endif
    unsigned char unknown_6fd4_;
};
extern "C" Struct_ov025_021e74f4* func_ov000_02160130();

// USA: func_ov025_021e74f4
extern "C" ARM int func_ov025_021e74f4(Struct_ov025_021e74f4_2* command) {
    LightingManager::GetInstance()->BeginFade(command->targetBrightness, command->duration);
    func_ov000_02160130()->unknown_6fd4_ = 1;
    return 1;
}
