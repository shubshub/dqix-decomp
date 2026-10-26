#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int);
extern "C" void* func_ov001_0215a4c8(void* ctx, int a);

// USA: func_ov001_0215c57c
extern "C" ARM int func_ov001_0215c57c(void* obj) {
    int x = func_ov017_021d60f4(obj);
    void* ctx = func_ov001_0215ab20(x);
    if (ctx == NULL) return 0;
    int y = func_ov017_021d60f4((char*)obj + 8);
    func_ov001_0215a4c8(ctx, y);
    return 1;
}
