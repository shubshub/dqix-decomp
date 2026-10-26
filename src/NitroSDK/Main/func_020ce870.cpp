#include <globaldefs.h>

int SendCommandToArm7(int a, int b, bool c);

// USA: func_020ce870
extern "C" ARM void func_020ce870(int arg) {
    while (SendCommandToArm7(8, arg, 0) != 0) {}
}
