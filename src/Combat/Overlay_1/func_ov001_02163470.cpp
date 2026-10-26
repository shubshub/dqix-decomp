#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov001_0215ab20(int t);
extern "C" void* func_ov001_0215a6bc(void* ctx, int a);

// USA: func_ov001_02163470
extern "C" ARM int func_ov001_02163470(void* obj) {
    int t = func_ov017_021d60f4(obj);
    void* ctx = func_ov001_0215ab20(t);
    if (ctx == NULL) {
        return 0;
    }
    int a = func_ov017_021d60f4((char*)obj + 0x8);
    func_ov001_0215a6bc(ctx, a);
    return 1;
}
