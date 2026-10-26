#include <globaldefs.h>

extern "C" void func_ov000_0218177c(void* a, int b, int c, int d, int e);

// USA: func_ov000_02181a5c
extern "C" ARM void func_ov000_02181a5c(void* a, int b, int e) {
    func_ov000_0218177c(a, b, 1, 1, e);
}
