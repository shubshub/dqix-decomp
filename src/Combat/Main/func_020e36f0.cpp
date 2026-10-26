#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_ov017_021ced48(int, int);

// USA: func_020e36f0
extern "C" ARM void func_020e36f0(unsigned char* obj) {
    void* state = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)state)) return;
    if (LinkSession_IsHostOrSolo(state)) {
        if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
            obj[0] |= 1;
        }
        return;
    }
    func_ov017_021ced48(0, 0);
}
