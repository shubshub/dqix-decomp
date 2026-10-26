#include <globaldefs.h>

extern "C" void func_ov031_0220b8f4(void*, void*, int);
extern "C" void func_ov031_0220b18c(void*, void*, int);
extern char data_ov031_022498e5;

// USA: func_ov031_0220ba14
extern "C" ARM void func_ov031_0220ba14(void* a, void* b) {
    func_ov031_0220b8f4(a, &data_ov031_022498e5, 0x2c);
    func_ov031_0220b18c(b, a, 0x14);
}
