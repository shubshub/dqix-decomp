#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov025_021e86f0_1162 = 0x1da };
#else
enum { Enum_ov025_021e86f0_1162 = 0x48a };
#endif

// USA: func_ov025_021e86f0
extern "C" ARM int func_ov025_021e86f0(void) {
    char* p = (char*)GetGameResources() + 0x4000;
    p[Enum_ov025_021e86f0_1162] = 1;
    return 1;
}
