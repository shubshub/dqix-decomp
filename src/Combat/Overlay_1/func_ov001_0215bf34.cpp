#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" void func_ov001_02159d9c(void* node);

// USA: func_ov001_0215bf34
extern "C" ARM int func_ov001_0215bf34(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    void* node = func_ov001_0215ab20(idx);
    if (node == NULL) return 0;
    func_ov001_02159d9c(node);
    return 1;
}
