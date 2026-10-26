#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02161d8c
extern "C" ARM int func_ov001_02161d8c(void* obj) {
    int v = LinkSession_IsActive((int*)LinkSession_GetInstance());
    func_ov017_021d6134(obj, v);
    return 1;
}
