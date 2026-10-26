#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021b2074(void* obj, void* extra);

// USA: func_ov003_02172570
extern "C" ARM int func_ov003_02172570(unsigned char* obj, void* extra) {
#if defined(jpn)
    enum { Enum_ov003_02172570_15176 = 0x3928 };
#else
    enum { Enum_ov003_02172570_15176 = 0x3b48 };
#endif
    if (*obj != 9) {
        return 0;
    }
    char* base = (char*)GetGameResources();
    func_ov017_021b2074(*(void**)(base + Enum_ov003_02172570_15176), extra);
    return 1;
}
