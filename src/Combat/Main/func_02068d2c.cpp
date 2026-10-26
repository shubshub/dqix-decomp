#include <globaldefs.h>

extern "C" int func_02067f9c(int* p, int v);

// USA: func_02068d2c
extern "C" ARM int func_02068d2c(int a, void* obj) {
    int* p = *(int**)((char*)obj + 0x10);
    if (p != NULL) {
        return func_02067f9c(p, *p) == 0;
    }
    return 0;
}
