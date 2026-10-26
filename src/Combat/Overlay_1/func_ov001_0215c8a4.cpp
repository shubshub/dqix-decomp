#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov001_0215ab20(int t);
extern "C" void func_ov001_0215a674(void* self, int a1, int a2);

// USA: func_ov001_0215c8a4
extern "C" ARM int func_ov001_0215c8a4(void* self) {
    int a0 = func_ov017_021d60f4(self);
    void* ctx = func_ov001_0215ab20(a0);
    if (ctx == NULL) {
        return 0;
    }
    int a1 = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    int a2 = func_ov017_021d60f4((char*)self + 0x10);
    func_ov001_0215a674(ctx, a1, a2);
    return 1;
}
