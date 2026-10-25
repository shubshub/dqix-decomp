#include <globaldefs.h>

#if defined(jpn)
enum { StatusFieldOffset = 0x868 };
#else
enum { StatusFieldOffset = 0x998 };
#endif

int MessageSystem_GetInstance(void);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_021652bc
#if defined(jpn)
extern "C" ARM int func_ov004_02165b4c(void* obj)
#else
ARM int CheckFieldAndEnqueue_021652bc_021652bc(void* obj)
#endif
{
    if (*(int*)((char*)MessageSystem_GetInstance() + StatusFieldOffset) == 0) {
        func_ov011_021848a0(obj, 0x65);
    }
    return 0;
}
