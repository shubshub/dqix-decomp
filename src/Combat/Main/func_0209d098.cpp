#include <globaldefs.h>

extern "C" void func_0209ee34(void*, int, int);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_0209dccc();

// USA: func_0209d098
extern "C" ARM int func_0209d098(char* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    int b = func_ov017_021d60f4(arg + 8);
    func_0209ee34(mgr, a, b);
    return 1;
}
