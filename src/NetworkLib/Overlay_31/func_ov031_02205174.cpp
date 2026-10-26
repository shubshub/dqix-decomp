#include <globaldefs.h>

extern "C" void func_020c7e0c(void *data, int a, int b);
extern int data_ov031_0224e204;

// USA: func_ov031_02205174
extern "C" ARM void func_ov031_02205174(int v) {
    if (v == 0) {
        return;
    }
    func_020c7e0c(&data_ov031_0224e204, v, 0);
}
