#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

// USA: func_020e3748
extern "C" ARM void func_020e3748(unsigned char* obj, int bit) {
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        obj[1] &= ~(1 << bit);
    }
}
