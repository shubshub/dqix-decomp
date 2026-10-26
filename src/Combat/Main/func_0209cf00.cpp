#include <globaldefs.h>

extern "C" void func_0209e7a4(void* mgr, int a, int b);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_0209dccc();

// USA: func_0209cf00
extern "C" ARM int func_0209cf00(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    func_0209e7a4(mgr, func_ov017_021d60f4(arg), func_ov017_021d60f4((char*)arg + 8));
    return 1;
}
