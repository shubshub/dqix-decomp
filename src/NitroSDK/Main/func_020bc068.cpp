#include <globaldefs.h>

extern "C" void* func_020bc594(void* p);

// USA: func_020bc068
extern "C" ARM void* func_020bc068(void* obj, int) {
    return func_020bc594(*(void**)obj);
}
