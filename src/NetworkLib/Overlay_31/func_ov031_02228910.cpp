#include <globaldefs.h>

extern "C" signed char func_ov031_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern unsigned char data_ov031_02290c58;
extern "C" void func_ov031_02237e58(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02228960(void);

// USA: func_ov031_02228910
extern "C" ARM void func_ov031_02228910(void) {
    signed char v = func_ov031_02237e9c();
    if (v != 0) {
        if (v != 1) return;
        func_ov031_02236878(0xe);
        data_ov031_02290c58 = 1;
    } else {
        func_ov031_02236878(7);
    }
    func_ov031_02237e58();
    func_ov031_022274c0((int)func_ov031_02228960);
}
