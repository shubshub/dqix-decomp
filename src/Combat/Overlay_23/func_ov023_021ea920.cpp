#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea920
extern "C" ARM int func_ov023_021ea920(void* obj) {
    void* p = LinkSession_GetInstance();
    if (LinkSession_IsGuest(p) != 0) {
        func_ov017_021d6134(obj, 1);
    } else {
        func_ov017_021d6134(obj, 0);
    }
    return 1;
}
