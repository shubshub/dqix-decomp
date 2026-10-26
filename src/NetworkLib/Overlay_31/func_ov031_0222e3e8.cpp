#include <globaldefs.h>

extern "C" void func_ov031_0222e404(void);
extern "C" void func_ov031_0222e484(void);
extern "C" void func_ov031_0222e7f8(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_0222e3e8
extern "C" ARM void func_ov031_0222e3e8(void) {
    func_ov031_0222e404();
    func_ov031_0222e484();
    func_ov031_022274c0((int)func_ov031_0222e7f8);
}
