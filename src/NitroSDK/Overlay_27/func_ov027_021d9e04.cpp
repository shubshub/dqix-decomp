#include <globaldefs.h>

extern "C" void func_ov027_021d8c6c(int a, int b, int c);

// USA: func_ov027_021d9e04
extern "C" ARM void func_ov027_021d9e04(int a, short arg1) {
    short value = arg1;
    func_ov027_021d8c6c(a, 0xd, (int)&value);
}
