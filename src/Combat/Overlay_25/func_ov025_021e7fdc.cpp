#include <globaldefs.h>
#include "Resource/Brightness.h"

// USA: func_ov025_021e7fdc
extern "C" ARM int func_ov025_021e7fdc(unsigned char* param) {
    unsigned char flag = param[8];
    GameResources* obj = GetGameResources();
    if (flag) {
        ClearFlags04(obj, 0x100000);
    } else {
        SetFlags04(obj, 0x100000);
    }
    return 1;
}
