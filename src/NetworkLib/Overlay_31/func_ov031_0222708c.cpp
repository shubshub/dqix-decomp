#include <globaldefs.h>

extern "C" int func_ov031_02226fe4(void *p, int a, int b);
extern int data_ov031_02250c40;

// USA: func_ov031_0222708c
extern "C" ARM int func_ov031_0222708c(int a, int b) {
    return func_ov031_02226fe4(&data_ov031_02250c40, a, b);
}
