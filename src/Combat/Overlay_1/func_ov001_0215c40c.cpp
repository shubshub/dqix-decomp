#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" void* func_ov001_0215a3c0(void* ctx);

// USA: func_ov001_0215c40c
extern "C" ARM int func_ov001_0215c40c(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    void* node = func_ov001_0215ab20(idx);
    if (node == NULL) return 0;
    func_ov001_0215a3c0(node);
    return 1;
}
