#include <globaldefs.h>

int MessageSystem_GetInstance();

// USA: func_ov001_0215e564  (semantic: ClearGlobalByte9b2_0215e564)
extern "C" ARM int func_ov001_0215e564(void) {
#if defined(jpn)
    enum { fieldOffset = 0x7e2 };
#else
    enum { fieldOffset = 0x9b2 };
#endif
    int r = MessageSystem_GetInstance();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + fieldOffset) = 0;
    return 1;
}
