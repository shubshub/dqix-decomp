#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_021632a8
extern "C" ARM int func_ov001_021632a8(void* obj) {
    GameResources* p = GetGameResources();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0) {
        SetFlags00(p, 0x4000);
    } else {
        ClearFlags00(p, 0x4000);
    }
    return 1;
}
