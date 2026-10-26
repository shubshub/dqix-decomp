#include <globaldefs.h>

extern const unsigned char data_020ee748[][5];

// USA: func_020dd11c
extern "C" ARM int func_020dd11c(unsigned int a, unsigned int b) {
    if (a == 0 || a >= 0xd) return 0;
    if (b >= 5) return 0;
    return data_020ee748[a][b];
}
