#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d612c(void* obj);
extern char data_ov001_02165745;

// USA: func_ov001_021613d0
extern "C" ARM int func_ov001_021613d0(void* obj) {
#if defined(jpn)
    enum { Enum_ov001_021613d0_1844 = 0x524, fieldOffset = 0xd4 };
#else
    enum { Enum_ov001_021613d0_1844 = 0x734, fieldOffset = 0xd8 };
#endif
    char* base = (char*)GetGameResources();
    char* p = *(char**)(base + 0x3000 + Enum_ov001_021613d0_1844);
    int v = func_ov017_021d612c(obj);
    sprintf(p + fieldOffset, &data_ov001_02165745, v);
    return 1;
}
