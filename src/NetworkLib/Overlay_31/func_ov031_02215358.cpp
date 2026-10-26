#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" int func_ov031_02215528(void* a0, void* a1, void* a2);
extern "C" int func_ov031_0220764c(void* a0);
extern "C" void func_ov031_022134cc(int v);

extern int data_ov031_0224e1c0;

// USA: func_ov031_02215358
extern "C" ARM int func_ov031_02215358(void* a0) {
    void* f1 = func_ov031_022133f8(1);
    void* f4 = func_ov031_022133f8(4);
    func_ov031_02215528(f1, a0, f4);
    data_ov031_0224e1c0 = 4;
    if (func_ov031_0220764c(f4) == 0) {
        return 0xc;
    }
    func_ov031_022134cc(2);
    return 0x11;
}
