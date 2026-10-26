#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02163128
extern "C" ARM int func_ov001_02163128(void* obj) {
    GameResources* p = GetGameResources();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0) {
        ClearFlags04(p, 0x800);
    } else {
        SetFlags04(p, 0x800);
    }
    return 1;
}
