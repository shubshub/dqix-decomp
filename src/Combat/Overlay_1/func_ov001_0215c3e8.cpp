#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" void* func_ov001_0215a5d8(void* ctx);

// USA: func_ov001_0215c3e8
extern "C" ARM int func_ov001_0215c3e8(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    void* node = func_ov001_0215ab20(idx);
    if (node == NULL) return 0;
    func_ov001_0215a5d8(node);
    return 1;
}
