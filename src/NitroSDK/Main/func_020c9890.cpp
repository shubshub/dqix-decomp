#include <globaldefs.h>


extern "C" void HaltSystem(void);
extern short data_02111668;

// USA: func_020c9890
extern "C" ARM void func_020c9890(int unused, unsigned int code) {
    if ((((code & 0x7f00) << 8) >> 16) == 0x10) {
        data_02111668 = 1;
        return;
    }
    HaltSystem();
}
