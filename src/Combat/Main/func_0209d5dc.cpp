#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" float func_ov017_021d6110(void*);
extern "C" void func_0209f634(void*, int, int);
extern "C" void* func_0209dccc();

// USA: func_0209d5dc
extern "C" ARM int func_0209d5dc(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    float f = func_ov017_021d6110((char*)arg + 8);
    func_0209f634(mgr, a, (int)f);
    return 1;
}
