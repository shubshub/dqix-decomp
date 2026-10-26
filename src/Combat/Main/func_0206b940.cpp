#include <globaldefs.h>

extern "C" void func_020696bc(int a, int* out, int c);

// USA: func_0206b940
extern "C" ARM int func_0206b940(int input, int* target) {
    int val;
    func_020696bc(input, &val, 1);
    *target = val;
    return 1;
}
