#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* arg);

// USA: func_ov001_0215b074
extern "C" ARM int func_ov001_0215b074(int arg0, char* arg1, int arg2) {
    int var0;
    int var1;
    int var2 = func_ov017_021d60f4(arg1);
    var0 = -16;
    if (arg2 >= 2) {
        var0 = func_ov017_021d60f4(arg1 + 8);
    }
    GameResources* res = GameState::GetInstance()->GetResources();
    if (res == NULL) return 0;
    setFlag = 0;
    if (mode == 0) {
        SetBrightness(res, 0, duration);
    } else if (mode == 1) {
        SetBrightness(res, brightness, duration);
    } else if (mode == 2) {
        SetSubBrightness(res, 0, duration);
    } else if (mode == 3) {
        SetSubBrightness(res, brightness, duration);
    } else if (mode == 4) {
        SetMainBrightness(res, 0, duration);
    } else if (mode == 5) {
        SetMainBrightness(res, brightness, duration);
    } else if (mode == 6) {
        SetAndLockBrightness(res, 0, duration);
    } else if (mode == 7) {
        SetAndLockBrightness(res, brightness, duration);
    } else if (mode == 8) {
        SetAndLockSubBrightness(res, 0, duration);
    } else if (mode == 9) {
        SetAndLockSubBrightness(res, brightness, duration);
    } else if (mode == 10) {
        SetAndLockMainBrightness(res, 0, duration);
    } else if (mode == 11) {
        SetAndLockMainBrightness(res, brightness, duration);
    } else if (mode == 12) {
        UnlockAndSetBrightness(res, 0, duration);
    } else if (mode == 13) {
        UnlockAndSetBrightness(res, brightness, duration);
    } else if (mode == 14) {
        UnlockAndSetSubBrightness(res, 0, duration);
    } else if (mode == 15) {
        UnlockAndSetSubBrightness(res, brightness, duration);
    } else if (mode == 16) {
        UnlockAndSetMainBrightness(res, 0, duration);
    } else if (mode == 17) {
        UnlockAndSetMainBrightness(res, brightness, duration);
    }
    int var4 = (arg0 % 2 == 1);
    if (arg0 % 6 < 4 && var4) {
        var1 = 1;
    }
    char* var5 = (char*)GetGameResources()->unknown_ptr_array_371c[6];
    if (var1) {
        if (*(unsigned short*)(var5 + 0xa) <= 3) {
            #if defined(jpn)
            var5[0xfe] = 1;
#else
            var5[0x102] = 1;
#endif
        }
    }
    return 1;
}
