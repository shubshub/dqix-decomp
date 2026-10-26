#include <globaldefs.h>
extern "C" int func_02042658(void*, int);

extern "C" int func_02042190(int x);

// USA: func_020426a4
extern "C" ARM int func_020426a4(int a, int b) {
    return func_02042658((void*)(func_02042190(a)), (int)(b));
}
