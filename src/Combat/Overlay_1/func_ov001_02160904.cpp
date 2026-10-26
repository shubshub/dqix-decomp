#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void*);

#if defined(jpn)
    enum { baseOffset = 0x4c0 };
#else
    enum { baseOffset = 0x6d0 };
#endif
struct Struct_ov001_02160904 { char pad[0x5a4]; int unknown_5a4_; };
struct Struct_ov001_02160904_2 { char pad[baseOffset]; Struct_ov001_02160904* p; };

// USA: func_ov001_02160904
extern "C" ARM int func_ov001_02160904(void* obj) {
    int flag = func_ov017_021d60f4(obj);
    struct Struct_ov001_02160904_2* base = (struct Struct_ov001_02160904_2*)((char*)GetGameResources() + 0x3000);
    struct Struct_ov001_02160904* h = base->p;
    if (flag != 0) {
        h->unknown_5a4_ &= ~1;
    } else {
        h->unknown_5a4_ |= 1;
    }
    return 1;
}
