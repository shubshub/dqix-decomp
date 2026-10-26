#include <globaldefs.h>

extern "C" ARM void *func_ov031_0223e218(void *a, void *b, void *c, int d);
extern "C" int func_ov031_02223478(int);
extern "C" int func_ov031_0223b61c(int, int*, int);
extern "C" void func_ov031_022373fc(void);
extern int data_ov031_0224bedc[];
extern int data_ov031_02290d04;

// USA: func_ov031_022373b4
extern "C" ARM void *func_ov031_022373b4(int idx) {
    int v = func_ov031_02223478(data_ov031_0224bedc[idx]);
    data_ov031_02290d04 = func_ov031_0223b61c(v, NULL, 4);
    return func_ov031_0223e218((void*)1, (void*)func_ov031_022373fc, 0, 0x78);
}
