#include <globaldefs.h>

extern "C" void func_0206ea8c(void* a, void* b, int c, int d);

// USA: func_0206eb20
extern "C" ARM void func_0206eb20(void* a, void* b, int c, int limit) {
    for (; c < limit; c++) {
        func_0206ea8c(a, b, (short)c, 0);
    }
}
