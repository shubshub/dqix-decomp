#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct Struct_ov003_0217ce3c { char pad[0x6]; signed char step; char pad2; unsigned short field8; };

// USA: func_ov003_0217dc94
extern "C" ARM void func_ov003_0217dc94(Struct_ov003_0217ce3c* obj) {
    if ((obj->field8 & 1) == 0) return;
    if (obj->step == 0) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b34(g, 0x1f5, 0x66, 0, 0);
        obj->step = 1;
    } else if (obj->step == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            obj->field8 = obj->field8 & ~1;
            obj->step = -1;
        }
    }
}
