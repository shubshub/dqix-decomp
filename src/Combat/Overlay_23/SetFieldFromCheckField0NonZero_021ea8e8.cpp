#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea8e8  (semantic: SetFieldFromCheckField0NonZero_021ea8e8)
extern "C" ARM int func_ov023_021ea8e8(void* obj) {
    if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
        func_ov017_021d6134(obj, 1);
    } else {
        func_ov017_021d6134(obj, 0);
    }
    return 1;
}
