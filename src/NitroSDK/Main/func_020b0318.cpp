#include <globaldefs.h>

// USA: func_020b0318
extern "C" ARM void func_020b0318(int* p) {
    int i = 0;
    do {
        p[i] = -1;
        i++;
    } while (i < 3);
}
