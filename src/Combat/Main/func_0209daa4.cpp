#include <globaldefs.h>

extern "C" void* func_0209dccc();
extern "C" int func_ov017_021d60f4(void*);

struct Struct_0209daa4;
extern "C" void func_0209fde8(struct Struct_0209daa4* p, int a, int b, int c);

// USA: func_0209daa4
extern "C" ARM int func_0209daa4(void* self) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(self);
    int b = func_ov017_021d60f4((char*)self + 0x8);
    int c = func_ov017_021d60f4((char*)self + 0x10);
    func_0209fde8((struct Struct_0209daa4*)mgr, a, b, c);
    return 1;
}
