#include <globaldefs.h>
extern "C" int func_020ce56c(int, int, int);

// USA: func_020ce810
extern "C" ARM int func_020ce810(int *arg0, int *arg1) {
    unsigned short local;
    int ret = func_020ce56c((int)(0xf), (int)(1), (int)(&local));
    if (ret != 0) {
        return ret;
    }
    if (arg0 != NULL) {
        *arg0 = (local & 8) ? 1 : 0;
    }
    if (arg1 != NULL) {
        *arg1 = (local & 4) ? 1 : 0;
    }
    return ret;
}
