#include <globaldefs.h>

extern "C" int func_0208a370(void* a, int selector, int b, int* out, int d);

// USA: func_0208a4ac
extern "C" ARM int func_0208a4ac(void* a, int b, int* out, int d) {
    return func_0208a370(a, 0, b, out, d);
}
