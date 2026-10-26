#include <globaldefs.h>


extern "C" void HaltSystem(void);
extern short data_0211214c;

// USA: func_020d18a4
extern "C" ARM void func_020d18a4(int a, int msg) {
    if ((msg & 0x3f) == 1) {
        data_0211214c = 1;
    } else {
        HaltSystem();
    }
}
