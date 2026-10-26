#include <globaldefs.h>

extern "C" signed char func_ov031_02237e9c(void);
extern unsigned char data_ov031_02290ce4;
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237e58(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02234e40(void);

// USA: func_ov031_02234de4
extern "C" ARM void func_ov031_02234de4(void) {
    int v = func_ov031_02237e9c();
    if (v != 0) {
        if (v != 1) return;
        data_ov031_02290ce4 = 3;
        func_ov031_02236878(6);
    } else {
        data_ov031_02290ce4 = 1;
        func_ov031_02236878(7);
    }
    func_ov031_02237e58();
    func_ov031_022274c0((int)func_ov031_02234e40);
}
