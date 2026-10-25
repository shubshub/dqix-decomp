#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_02017c58(void*);

// USA: func_ov001_02163dc8
ARM int SetFlagInIndirectField_02163dc8(void) {
#if defined(jpn)
    enum { fieldOffset = 0x93c };
#else
    enum { fieldOffset = 0xb5c };
#endif
    func_02017c58(Zone3D_GetInstance());
    char* p = *(char**)(((char*)GetGameResources() + 0x3000) + fieldOffset);
    p[8] = 1;
    return 1;
}
