#include <globaldefs.h>

extern "C" int func_020680cc(int);

// USA: func_02068dbc
extern "C" ARM int func_02068dbc(int a, void* obj) {
    int* p = *(int**)((char*)obj + 0x0);
    if (p != NULL) {
        return func_020680cc(*p) == 0;
    }
    return 0;
}
