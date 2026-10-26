#include <globaldefs.h>

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_020e3748(unsigned char* obj, int bit);
extern "C" void func_ov017_021ced48(int, int);

// USA: func_020e3798
extern "C" ARM void func_020e3798(unsigned char* obj) {
    void* state = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)state)) return;
    obj[2] = 0;
    if (LinkSession_IsHostOrSolo(state)) {
        func_020e3748(obj, 0);
        return;
    }
    func_ov017_021ced48(2, 0);
}
