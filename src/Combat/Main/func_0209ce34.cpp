#include <globaldefs.h>

extern "C" void func_0209e4bc(void* mgr, int a, int b);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_0209dccc();

// USA: func_0209ce34
extern "C" ARM int func_0209ce34(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    func_0209e4bc(mgr, func_ov017_021d60f4(arg), func_ov017_021d60f4((char*)arg + 8));
    return 1;
}
