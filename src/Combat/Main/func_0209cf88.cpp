#include <globaldefs.h>

extern "C" void* func_0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209e9f4(void*, int, int);

// USA: func_0209cf88
extern "C" ARM int func_0209cf88(void* obj) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(obj);
    int b = func_ov017_021d60f4((char*)obj + 8);
    func_0209e9f4(mgr, a, b);
    return 1;
}
