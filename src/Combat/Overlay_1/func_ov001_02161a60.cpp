#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov028_021d8c20(int);
extern "C" void func_020a1f4c(int flag);

// USA: func_ov001_02161a60
extern "C" ARM int func_ov001_02161a60(void) {
#if defined(jpn)
    enum { Enum_ov001_02161a60_1844 = 0x524, fieldOffset = 0x15c };
#else
    enum { Enum_ov001_02161a60_1844 = 0x734, fieldOffset = 0x160 };
#endif
    char* p = *(char**)((char*)GetGameResources() + 0x3000 + Enum_ov001_02161a60_1844);
    int v = *(int*)(p + fieldOffset);
    func_ov028_021d8c20(v);
    *(int*)(p + fieldOffset) = 0;
    func_020a1f4c(1);
    return 1;
}
