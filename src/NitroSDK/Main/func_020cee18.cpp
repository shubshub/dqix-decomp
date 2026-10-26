#include <globaldefs.h>
extern "C" int func_020ce56c(int, int, int);

// USA: func_020cee18
extern "C" ARM int func_020cee18(int* out) {
    unsigned short v;
    int result = func_020ce56c((int)(0xf), (int)(6), (int)(&v));
    if (result != 0) {
        return result;
    }
    if (out != NULL) {
        *out = v;
    }
    return result;
}
