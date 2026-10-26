#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int flag);
extern "C" unsigned int func_ov031_02227558(void);
extern "C" void func_ov031_022274d0(int a, int b);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02228024(void);
extern "C" void func_ov031_02232508(void);

// USA: func_ov031_02227fb0
extern "C" ARM void func_ov031_02227fb0(void) {
    if (func_ov031_0223c054(1)) return;
    if (func_ov031_0223c054(0)) return;
    unsigned int var0 = func_ov031_02227558();
    switch (var0) {
    case 0:
        func_ov031_022274d0(0, 1);
        func_ov031_022274c0((int)func_ov031_02228024);
        break;
    case 1:
        func_ov031_022274d0(1, 1);
        func_ov031_022274c0((int)func_ov031_02232508);
        break;
    }
}
