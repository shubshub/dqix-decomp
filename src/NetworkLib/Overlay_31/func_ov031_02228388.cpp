#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" int func_ov031_02236878(int index);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02227ce4(void);
extern "C" void func_ov031_0222855c(void);
extern "C" void func_ov031_022283d8(void);

// USA: func_ov031_02228388
extern "C" ARM void func_ov031_02228388(void) {
    int v = func_ov031_02222e0c();
    switch (v) {
    case 0:
        func_ov031_02236878(7);
        func_ov031_022274c0((int)func_ov031_02227ce4);
        break;
    case 1:
        func_ov031_02236878(6);
        func_ov031_0222855c();
        func_ov031_022274c0((int)func_ov031_022283d8);
        break;
    }
}
