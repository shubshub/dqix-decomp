#include <globaldefs.h>

extern char data_02111818;

// USA: func_020cf854
extern "C" ARM void func_020cf854(int val) {
    *(int*)(&data_02111818 + 0x2c) = val;
}
