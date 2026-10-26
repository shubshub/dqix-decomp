#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(int a);
extern "C" void func_020daf9c(int a, int b, int c, int d);

// USA: func_ov001_02162488
extern "C" ARM int func_ov001_02162488(int a) {
    func_020daf9c(func_ov017_021d60f4(a), 0, 1, 0);
    return 1;
}
