#include <globaldefs.h>

extern "C" void func_020696bc(int a, int* out, int c);

// USA: func_0206b900
extern "C" ARM int func_0206b900(int input, int* target) {
    int val;
    func_020696bc(input, &val, 1);
    *target = *target + val;
    return 0;
}
