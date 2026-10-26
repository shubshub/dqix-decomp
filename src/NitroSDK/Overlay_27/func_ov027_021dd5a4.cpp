#include <globaldefs.h>

extern "C" int _s32_div_f(int a, int b);
extern int data_ov027_021e3424;

// USA: func_ov027_021dd5a4
extern "C" ARM void func_ov027_021dd5a4(int val) {
    int diff = val - 2;
    *(int*)((char*)&data_ov027_021e3424 + 0x8) = diff;
    int q = _s32_div_f(30, diff);
    *(int*)((char*)&data_ov027_021e3424 + 0xc) = q;
    *(int*)((char*)&data_ov027_021e3424 + 0x10) = 30;
}
