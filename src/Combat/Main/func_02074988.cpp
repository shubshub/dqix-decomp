#include <globaldefs.h>

extern int data_020e88e4[];

// USA: func_02074988
extern "C" ARM int func_02074988(int i) {
    if (i < 0) return 0;
    if (i > 4) return 0;
    return data_020e88e4[i];
}
