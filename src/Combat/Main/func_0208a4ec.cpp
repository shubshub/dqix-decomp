#include <globaldefs.h>

extern "C" int func_0208a370(void* a, int selector, int b, int* out, int d);

// USA: func_0208a4ec
extern "C" ARM int func_0208a4ec(void* a, int b, int* out, int d) {
    return func_0208a370(a, 2, b, out, d);
}
