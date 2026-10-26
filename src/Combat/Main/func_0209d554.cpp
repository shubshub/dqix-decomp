#include <globaldefs.h>

extern "C" void func_0209f364(void*, int, int, int);
extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021d6110(void*);
extern "C" void* func_0209dccc();

// USA: func_0209d554
extern "C" ARM int func_0209d554(char* arg) {
    void* mgr = func_0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(arg);
    int b = func_ov017_021d6110(arg + 8);
    int c = func_ov017_021d60f4(arg + 0x10);
    func_0209f364(mgr, a, b, c);
    return 1;
}
