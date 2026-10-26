#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern "C" void func_ov031_022281e0(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_0222818c
extern "C" ARM void func_ov031_0222818c(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x14, 8);
    func_ov031_0223cb68(1, 1);
    func_ov031_0223cb68(0, 0x14);
    func_ov031_022274c0((int)func_ov031_022281e0);
}
