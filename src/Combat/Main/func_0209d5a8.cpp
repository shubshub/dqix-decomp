#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209f498(void*, int);
extern "C" void* func_0209dccc();

// USA: func_0209d5a8
extern "C" ARM int func_0209d5a8(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    func_0209f498(mgr, func_ov017_021d60f4(arg));
    return 1;
}
