#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int);
extern "C" void* func_ov001_0215a510(void* ctx, int a);

// USA: func_ov001_0215c820
extern "C" ARM int func_ov001_0215c820(void* obj) {
    int x = func_ov017_021d60f4(obj);
    void* ctx = func_ov001_0215ab20(x);
    if (ctx == NULL) return 0;
    int y = func_ov017_021d60f4((char*)obj + 8);
    func_ov001_0215a510(ctx, y);
    return 1;
}
