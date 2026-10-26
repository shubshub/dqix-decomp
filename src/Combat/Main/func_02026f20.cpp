#include <globaldefs.h>

extern char data_020fdccc;

// USA: func_02026f20
extern "C" ARM void func_02026f20(int a, int index) {
    (&data_020fdccc)[index << 5] = 1;
}
