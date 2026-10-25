#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { pendingFieldOffset = 0x868 };
#else
enum { pendingFieldOffset = 0x998 };
#endif

struct FlagWord02046708;

void* GlobalFlags_GetInstance(void);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int MessageSystem_GetInstance();
extern "C" void func_02096c38(void* obj, int a0, int a1, int a2, int a3);

// USA: func_02096824
ARM void MaybeDispatchPendingAction02096824(unsigned char* obj) {
    void* p = GlobalFlags_GetInstance();
    if (TestFlags02046708((struct FlagWord02046708*)p, 0x4000)) return;
    if (!(g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0)) return;
    int g = MessageSystem_GetInstance();
    if (g != 0 && *(int*)(g + pendingFieldOffset) != 0) return;
    if (!obj[0x225]) return;
    func_02096c38(obj, obj[0x220], obj[0x221], obj[0x222], obj[0x223]);
}
