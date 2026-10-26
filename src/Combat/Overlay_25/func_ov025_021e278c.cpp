#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int _s32_div_f(int a, int b);
extern const char* data_ov025_021ef520[];

// USA: func_ov025_021e278c
extern "C" ARM void func_ov025_021e278c(int value, char* buf) {
    int q = _s32_div_f(value, 1000000);
    int rem = value - q * 1000000;
    sprintf(buf, data_ov025_021ef520[q], rem);
}
