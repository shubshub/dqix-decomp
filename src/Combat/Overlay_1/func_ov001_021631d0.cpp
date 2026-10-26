#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov001_021631d0
extern "C" ARM int func_ov001_021631d0(void* ctx) {
#if defined(jpn)
    enum { Enum_ov001_021631d0_1844 = 0x524, fieldOffset = 0x101 };
#else
    enum { Enum_ov001_021631d0_1844 = 0x734, fieldOffset = 0x105 };
#endif
    unsigned char* self = (unsigned char*)GetGameResources();
    unsigned char* work = *(unsigned char**)(self + 0x3000 + Enum_ov001_021631d0_1844);
    unsigned char v = work[fieldOffset];
    work[fieldOffset] = 0;
    func_ov017_021d6134(ctx, v);
    return 1;
}
