#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209f774(void*, int);
extern "C" void* func_0209dccc();

// USA: func_0209d624
extern "C" ARM int func_0209d624(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    func_0209f774(mgr, func_ov017_021d60f4(arg));
    return 1;
}
