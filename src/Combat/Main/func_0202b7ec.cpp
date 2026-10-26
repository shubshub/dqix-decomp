#include <globaldefs.h>

extern "C" int func_0202d6c8(void* obj);

// USA: func_0202b7ec
extern "C" ARM int func_0202b7ec(void* obj) {
    *(int*)obj = 2;
    return func_0202d6c8(obj);
}
