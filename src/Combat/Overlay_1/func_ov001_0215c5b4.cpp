#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int t);
extern "C" void func_ov001_0215a4e8(void* self, int a1, int a2);

// USA: func_ov001_0215c5b4
extern "C" ARM int func_ov001_0215c5b4(void* self) {
    int a0 = func_ov017_021d60f4(self);
    void* ctx = func_ov001_0215ab20(a0);
    if (ctx == NULL) {
        return 0;
    }
    int a1 = func_ov017_021d60f4((char*)self + 0x8);
    int a2 = func_ov017_021d60f4((char*)self + 0x10);
    func_ov001_0215a4e8(ctx, a1, a2);
    return 1;
}
