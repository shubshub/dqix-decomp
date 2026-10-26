#include <globaldefs.h>

extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

// USA: func_ov017_0218f758
extern "C" ARM void func_ov017_0218f758(void* self) {
    for (int i = 0; i < 4; i++) {
        func_ov017_0218f5a4(self, i, 0, 0, 0);
    }
}
