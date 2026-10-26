#include <globaldefs.h>

// USA: func_020017b0
extern "C" ARM int labs(int x) {
    return x < 0 ? -x : x;
}
