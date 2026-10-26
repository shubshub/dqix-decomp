#include <globaldefs.h>

#if defined(jpn)
#define COUNTER_0216c628 0xb38
#else
#define COUNTER_0216c628 0xc74
#endif

// USA: func_ov002_0216c628
extern "C" ARM int func_ov002_0216c628(unsigned char* obj, int amount) {
    int v = *(int*)(obj + 0x1000 + COUNTER_0216c628);
    if (v > amount) {
        *(int*)(obj + 0x1000 + COUNTER_0216c628) = v - amount;
        goto ret1;
    }
    *(int*)(obj + 0x1000 + COUNTER_0216c628) = 0;
    return 0;
ret1:
    return 1;
}
