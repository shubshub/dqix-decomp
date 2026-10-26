#include <globaldefs.h>

extern int data_020e9200[][4];

// USA: func_020b11ac
extern "C" ARM int func_020b11ac(unsigned char *p) {
    return data_020e9200[p[1]][p[0]];
}
