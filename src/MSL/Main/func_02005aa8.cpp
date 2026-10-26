#include <globaldefs.h>

// USA: func_02005aa8
extern "C" ARM int func_02005aa8(unsigned short* s) {
    int n = -1;
    unsigned short c;
    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}
