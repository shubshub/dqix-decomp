#include <globaldefs.h>

extern "C" void* func_0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209eaec(void*, int, int);

// USA: func_0209cfcc
extern "C" ARM int func_0209cfcc(void* obj) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(obj);
    int b = func_ov017_021d60f4((char*)obj + 8);
    func_0209eaec(mgr, a, b);
    return 1;
}
