#include <globaldefs.h>
#include "Resource/ResourceMutex.h"

struct FlagWord02046708;
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
void* GlobalFlags_GetInstance(void);

extern "C" void func_020dbae0(void* obj);

// USA: func_020dbc0c  (semantic: RunIfFlag100ClearRestoreState)
extern "C" ARM void func_020dbc0c(void* obj) {
    bool old = SetResourceMutexOperational(false);
    if (!FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x100)) {
        func_020dbae0(obj);
    }
    SetResourceMutexOperational(old);
}
