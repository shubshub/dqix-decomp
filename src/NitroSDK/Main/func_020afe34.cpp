#include <globaldefs.h>

extern "C" int func_020c8854(int a, int b, int c, void* d);

// USA: func_020afe34
extern "C" ARM int func_020afe34(void* obj, int arg) {
    return func_020c8854(*(int*)((char*)obj + 8), *(int*)((char*)obj + 4), arg, obj);
}
