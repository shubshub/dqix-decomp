#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_021631a4
extern "C" ARM int func_ov001_021631a4(void* obj) {
#if defined(jpn)
    enum { Enum_ov001_021631a4_1844 = 0x524, fieldOffset = 0x80 };
#else
    enum { Enum_ov001_021631a4_1844 = 0x734, fieldOffset = 0x84 };
#endif
    char* base = (char*)GetGameResources();
    char* q = *(char**)(base + 0x3000 + Enum_ov001_021631a4_1844);
    int v = func_ov017_021d60f4(obj);
    *(short*)(q + 0x100 + fieldOffset) = (short)v;
    return 1;
}
