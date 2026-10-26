#include <globaldefs.h>

#if defined(jpn)
enum { stateFieldOffset = 0x218 };
#else
enum { stateFieldOffset = 0x2c8 };
#endif

extern "C" int MessageSystem_GetInstance(void);

// USA: func_ov004_0216768c
#if defined(jpn)
extern "C" ARM int func_ov004_02167c98(void)
#else
extern "C" ARM int func_ov004_0216768c(void)
#endif
{
    *(int*)((char*)MessageSystem_GetInstance() + stateFieldOffset) = 1;
    return 0;
}
