#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02163200
extern "C" ARM int func_ov001_02163200(void* obj) {
#if defined(jpn)
    enum { Enum_ov001_02163200_14132 = 0x3524, fieldOffset = 0x103 };
#else
    enum { Enum_ov001_02163200_14132 = 0x3734, fieldOffset = 0x107 };
#endif
    char* p = (char*)GetGameResources();
    unsigned char v = *(unsigned char*)(*(char**)(p + Enum_ov001_02163200_14132) + fieldOffset);
    func_ov017_021d6134(obj, v);
    return 1;
}
