#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern "C" void func_ov031_022286b8(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_02228664
extern "C" ARM void func_ov031_02228664(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x15, 8);
    func_ov031_0223cb68(1, 1);
    func_ov031_0223cb68(0, 0x15);
    func_ov031_022274c0((int)func_ov031_022286b8);
}
