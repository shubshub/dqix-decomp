#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int t);
extern "C" void* func_ov001_0215a42c(void* ctx, int a);

// USA: func_ov001_0215c4fc
extern "C" ARM int func_ov001_0215c4fc(void* self, int mode) {
    int a0 = func_ov017_021d60f4(self);
    void* ctx = func_ov001_0215ab20(a0);
    if (ctx == NULL) {
        return 0;
    }
    int a1 = 0;
    if (mode >= 2) {
        a1 = func_ov017_021d60f4((char*)self + 0x8);
    }
    func_ov001_0215a42c(ctx, a1);
    return 1;
}
