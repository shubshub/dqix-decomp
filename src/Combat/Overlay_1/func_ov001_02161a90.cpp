#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02161a90
extern "C" ARM int func_ov001_02161a90(void* obj) {
#if defined(jpn)
    enum { Enum_ov001_02161a90_1844 = 0x524, fieldOffset = 0x158 };
#else
    enum { Enum_ov001_02161a90_1844 = 0x734, fieldOffset = 0x15c };
#endif
    int* p = *(int**)((int)GetGameResources() + 0x3000 + Enum_ov001_02161a90_1844);
    func_ov017_021d6134(obj, p[fieldOffset / 4]);
    return 1;
}
