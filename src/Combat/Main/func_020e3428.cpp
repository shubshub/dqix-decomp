#include <globaldefs.h>
extern "C" int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_020e33b4(void*, int, int);

// USA: func_020e3428
extern "C" ARM void func_020e3428(void* a, int b) {
    void* ctx = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)ctx)) {
        int v = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)(ctx));
        func_020e33b4(a, b, v & 0xff);
    }
}
