#include <globaldefs.h>

extern "C" void* func_ov017_0219219c(char* base, int idx);

// USA: func_ov017_02191aac
extern "C" ARM void func_ov017_02191aac(void* obj, int mode, int idx, int mask) {
    void* p = func_ov017_0219219c((char*)obj, idx);
    if (!p) return;
    p = func_ov017_0219219c((char*)obj, idx);
    if (p) *(unsigned char*)p |= 1;
    if (mode == 1) {
        p = func_ov017_0219219c((char*)obj, idx);
        if (p) *(unsigned char*)p |= mask;
        return;
    }
    if (mode != 0) return;
    p = func_ov017_0219219c((char*)obj, idx);
    if (p) *(unsigned char*)p &= ~mask;
}
