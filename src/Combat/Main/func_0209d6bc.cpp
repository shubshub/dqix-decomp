#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209f968(void*, int, int, int);
extern "C" void* func_0209dccc();

// USA: func_0209d6bc
extern "C" ARM int func_0209d6bc(void* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    int b = func_ov017_021d60f4((char*)arg + 8);
    int c = func_ov017_021d60f4((char*)arg + 0x10);
    func_0209f968(mgr, a, b, c);
    return 1;
}
