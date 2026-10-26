#include <globaldefs.h>
#include "Resource/Brightness.h"

// USA: func_ov025_021e8314
extern "C" ARM int func_ov025_021e8314(unsigned char* param) {
    GameResources* obj = GetGameResources();
    if (param[8]) {
        ClearFlags04(obj, 0x400);
    } else {
        SetFlags04(obj, 0x400);
    }
    return 1;
}
