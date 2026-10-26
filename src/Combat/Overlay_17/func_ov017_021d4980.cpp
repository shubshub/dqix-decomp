#include <globaldefs.h>

extern "C" void func_0200159c(int);

struct Struct_ov017_021d4980 { int f0, f1, f2, f3; };

// USA: func_ov017_021d4980
extern "C" ARM void func_ov017_021d4980(Struct_ov017_021d4980 s) {
    int cond = *(volatile int*)&s.f0;
    int unused = *(volatile int*)&s.f1;
    (void)unused;
    if (cond != 0) {
        func_0200159c(-1);
    }
}
