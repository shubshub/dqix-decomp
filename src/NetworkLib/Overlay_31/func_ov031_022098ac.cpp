#include <globaldefs.h>

extern "C" void func_ov031_0220b8f4(void* a, int b, int c);
extern "C" void func_ov031_0220b028(void* a, int b, int c);

// USA: func_ov031_022098ac
extern "C" ARM void func_ov031_022098ac(void* base, int b, int c) {
    func_ov031_0220b8f4((char*)base + 0x2ec, b, c);
    func_ov031_0220b028((char*)base + 0x3a4, b, c);
}
