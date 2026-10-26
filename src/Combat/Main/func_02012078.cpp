#include <globaldefs.h>

// USA: func_02012078
extern "C" ARM int func_02012078(void* obj) {
#if defined(jpn)
    enum { regionalOffset0 = 0x6000, regionalOffset1 = 0xfb8 };
#else
    enum { regionalOffset0 = 0x7000, regionalOffset1 = 0x1f8 };
#endif
    return *(int*)((unsigned char*)obj + regionalOffset0 + regionalOffset1);
}
