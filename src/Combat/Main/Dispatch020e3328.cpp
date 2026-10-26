#include <globaldefs.h>
int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
extern "C" void func_020e321c(void*, int, int);

// USA: func_020e3328
ARM void Dispatch020e3328(void* a, int b) {
    void* ctx = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)ctx)) {
        int v = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)(ctx));
        func_020e321c(a, b, v & 0xff);
    }
}
