#include <globaldefs.h>

extern "C" int func_020c895c(int a, int b, void* c);

// USA: func_0200ab10
extern "C" ARM int func_0200ab10(void* p) {
    return func_020c895c(0, -1, p);
}
