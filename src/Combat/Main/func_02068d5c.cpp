#include <globaldefs.h>

extern "C" int func_020680cc(int);

// USA: func_02068d5c
extern "C" ARM int func_02068d5c(int a, void* obj) {
    int* p = *(int**)((char*)obj + 0x18);
    if (p != NULL) {
        return func_020680cc(*p) == 0;
    }
    return 0;
}
