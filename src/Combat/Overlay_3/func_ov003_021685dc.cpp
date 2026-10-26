#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { Enum_ov003_021685dc_1444 = 0x5a0 };
#else
enum { Enum_ov003_021685dc_1444 = 0x5a4 };
#endif

struct Struct_ov003_021685dc { char pad[Enum_ov003_021685dc_1444]; unsigned char state; unsigned char step; };

// USA: func_ov003_021685dc
extern "C" ARM void func_ov003_021685dc(Struct_ov003_021685dc* obj) {
    if (obj->state == 0) return;
    if (obj->step == 0) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b34(g, 0x1f5, 0x66, 0, 0);
        obj->step = obj->step + 1;
    } else if (obj->step == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            obj->state = 0;
            obj->step = 0;
        }
    }
}
