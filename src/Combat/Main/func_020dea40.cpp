#include <globaldefs.h>

extern "C" int func_020dea64(void* a, void* b, void* c, int d, void* e, int flag);

// USA: func_020dea40
extern "C" ARM int func_020dea40(void* a, void* b, void* c, int d, int e) {
    return func_020dea64(a, b, c, d, &e, 1);
}
