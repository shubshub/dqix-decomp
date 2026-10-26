#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov025_021e85e8_17544 = 0x41d8 };
#else
enum { Enum_ov025_021e85e8_17544 = 0x4488 };
#endif

// USA: func_ov025_021e85e8
extern "C" ARM int func_ov025_021e85e8(unsigned char* obj) {
    unsigned char* base = (unsigned char*)GetGameResources();
    base[Enum_ov025_021e85e8_17544] = 1;
    unsigned char flag = obj[8];
    unsigned char v = 1;
    if (flag == 0) {
        v = 0;
    }
    base[Enum_ov025_021e85e8_17544] = v;
    return 1;
}
