#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();

// USA: func_ov001_0215e514
extern "C" ARM int func_ov001_0215e514(void) {
#if defined(jpn)
    enum { fieldOffset = 0x789 };
#else
    enum { fieldOffset = 0x95b };
#endif
    int r = MessageSystem_GetInstance();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + fieldOffset) |= 0x40;
    return 1;
}
