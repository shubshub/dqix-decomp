#include <globaldefs.h>

extern "C" void func_ov000_0218177c(void* a, int b, int c, int d, int e);

// USA: func_ov000_02181aa4
extern "C" ARM void func_ov000_02181aa4(void* a, int b, int e) {
    func_ov000_0218177c(a, b, 0, 0, e);
}
