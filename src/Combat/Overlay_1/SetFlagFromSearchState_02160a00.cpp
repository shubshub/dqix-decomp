#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void*);
extern "C" void func_ov017_021d6134(void*, int);
int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

// USA: func_ov001_02160a00
ARM int SetFlagFromSearchState_02160a00(void* ctx) {
    void* obj = LinkSession_GetInstance(ctx);
    int result;
    if (!LinkSession_IsActive((int*)obj)) {
        goto setOne;
    }
    if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)obj) != 0) {
        goto setZero;
    }
setOne:
    result = 1;
    goto call;
setZero:
    result = 0;
call:
    func_ov017_021d6134(ctx, result);
    return 1;
}
