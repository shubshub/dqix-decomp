#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov001_0215ab20(int t);
extern "C" void* func_ov001_0215a6dc(void* ctx, int a);

// USA: func_ov001_021634a8
extern "C" ARM int func_ov001_021634a8(void* obj) {
    int t = func_ov017_021d60f4(obj);
    void* ctx = func_ov001_0215ab20(t);
    if (ctx == NULL) {
        return 0;
    }
    int a = func_ov017_021d60f4((char*)obj + 0x8);
    func_ov001_0215a6dc(ctx, a);
    return 1;
}
