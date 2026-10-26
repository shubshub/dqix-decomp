#include <globaldefs.h>

class Struct_ov003_0216c00c {
public:
    virtual void inline_ov003_0216c00c_12();
};
typedef void (Struct_ov003_0216c00c::*Type_01ff91ac_2)();

extern Type_01ff91ac_2 data_ov003_0218070c[12];
extern Type_01ff91ac_2 __ptmf_null;
extern int data_ov003_02180cc4;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_ov017_021d48f0(void* p);
extern "C" void LinkSession_End(void* p);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int LinkSession_GetState(int* obj);
extern "C" void WH_Reset(void);

// USA: func_ov003_021714a0
extern "C" ARM int func_ov003_021714a0(Struct_ov003_0216c00c* obj) {
    void* ptr = LinkSession_GetInstance();
    func_ov017_021d48f0(LinkMessageQueue_GetInstance());

    if (LinkSession_GetState((int*)ptr) == -1) {
        WH_Reset();
        LinkSession_End(ptr);
        return 0;
    }

    if (!(data_ov003_02180cc4 & 1)) {
        data_ov003_0218070c[11] = __ptmf_null;
        data_ov003_02180cc4 |= 1;
    }

    unsigned char idx = *(unsigned char*)obj;
    (obj->*data_ov003_0218070c[idx])();
    return 1;
}
