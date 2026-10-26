#include <globaldefs.h>

// Main, originally CheckField0NonZero020a10a8 (USA 0x020a10a8, EUR 0x020a10b8, JPN 0x020a2e20)
extern "C" ARM int Vec3Ease_IsRunning(int* obj) {
    return obj[0] != 0;
}
