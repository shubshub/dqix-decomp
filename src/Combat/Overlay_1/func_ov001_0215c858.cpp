#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int);
extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov001_0215a654(void* ctx, int a);

// USA: func_ov001_0215c858
extern "C" ARM int func_ov001_0215c858(void* self) {
    int x = func_ov017_021d60f4(self);
    void* ctx = func_ov001_0215ab20(x);
    if (ctx == NULL) return 0;
    int val = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    func_ov001_0215a654(ctx, val);
    return 1;
}
