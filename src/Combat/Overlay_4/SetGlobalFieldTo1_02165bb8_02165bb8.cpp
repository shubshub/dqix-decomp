#include <globaldefs.h>

int MessageSystem_GetInstance(void);

// USA: func_ov004_02165bb8
ARM int SetGlobalFieldTo1_02165bb8_02165bb8(void) {
#if defined(jpn)
    enum { regionalFieldOffset = 0x218 };
#else
    enum { regionalFieldOffset = 0x2c8 };
#endif
    *(int*)((char*)MessageSystem_GetInstance() + regionalFieldOffset) = 1;
    return 0;
}
