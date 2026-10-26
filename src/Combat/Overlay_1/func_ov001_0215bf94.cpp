#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" void func_ov001_02159ea8(void* node, int val);

// USA: func_ov001_0215bf94
extern "C" ARM int func_ov001_0215bf94(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    int val = func_ov017_021d60f4((char*)ctx + 0x8);
    void* node = func_ov001_0215ab20(idx);
    if (node == NULL) return 0;
    func_ov001_02159ea8(node, val);
    return 1;
}
