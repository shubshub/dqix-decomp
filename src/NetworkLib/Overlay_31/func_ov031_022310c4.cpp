#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02232508(void);

// USA: func_ov031_022310c4
extern "C" ARM void func_ov031_022310c4(void) {
    if (func_ov031_0223c054(1) != 0) return;
    if (func_ov031_0223c054(0) != 0) return;
    func_ov031_02223440();
    int v = 1;
    func_ov031_0223cbbc(v, v);
    func_ov031_0223cbbc(0, 0x14);
    func_ov031_022274d0(2, 1);
    func_ov031_022274c0((int)func_ov031_02232508);
}
