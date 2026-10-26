#include <globaldefs.h>

extern "C" void* func_0209dccc();
extern "C" int func_0209fdf8();
extern "C" int func_ov017_021d6134(void*, int);

// USA: func_0209daf8
extern "C" ARM int func_0209daf8(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int v = func_0209fdf8();
    func_ov017_021d6134(arg, v);
    return 1;
}
