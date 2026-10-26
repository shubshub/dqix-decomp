#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02161a1c
extern "C" ARM int func_ov001_02161a1c(void* ctx) {
#if defined(jpn)
    enum { Enum_ov001_02161a1c_1844 = 0x524, objectOffset = 0x15c, flagOffset = 0x160 };
#else
    enum { Enum_ov001_02161a1c_1844 = 0x734, objectOffset = 0x160, flagOffset = 0x164 };
#endif
    char* p = (char*)GetGameResources() + 0x3000;
    char* q = *(char**)(p + Enum_ov001_02161a1c_1844);
    int v = *(int*)(q + objectOffset);
    if (v == 0) {
        func_ov017_021d6134(ctx, 1);
    } else {
        func_ov017_021d6134(ctx, *(unsigned char*)(q + flagOffset));
    }
    return 1;
}
