#include <globaldefs.h>

extern "C" int func_ov031_0220cdd4(int a, int b, int c);
extern int data_ov031_02245ff4[];

// USA: func_ov031_022151b0
extern "C" ARM int func_ov031_022151b0(int a, int b, int index, int flags) {
    if (index > 0xc) index = 0xc;
    int val = flags | data_ov031_02245ff4[index];
    return func_ov031_0220cdd4(a, b, val);
}
