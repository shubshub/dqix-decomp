#include <globaldefs.h>

// USA: func_020017a4
extern "C" ARM int abs(int x) {
    return x < 0 ? -x : x;
}
