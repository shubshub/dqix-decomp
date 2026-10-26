#include <globaldefs.h>

extern char* data_ov031_02290c44;

// USA: func_ov031_0222785c
extern "C" ARM void func_ov031_0222785c(int v) {
    *(int*)(data_ov031_02290c44 + 0x1e000 + 0x298) = v;
}
