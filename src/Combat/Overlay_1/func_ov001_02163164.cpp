#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021bbc04(int val);
extern "C" void func_ov017_021d6134(void* param, int val);

// USA: func_ov001_02163164
extern "C" ARM int func_ov001_02163164(void* param) {
#if defined(jpn)
    enum { Enum_ov001_02163164_1844 = 0x524 };
#else
    enum { Enum_ov001_02163164_1844 = 0x734 };
#endif
    void* base = GetGameResources();
    int field = *(int*)((char*)base + 0x3000 + Enum_ov001_02163164_1844);
    int cond = func_ov017_021bbc04(field);
    if (cond != 0) {
        func_ov017_021d6134(param, 1);
    } else {
        func_ov017_021d6134(param, 0);
    }
    return 1;
}
