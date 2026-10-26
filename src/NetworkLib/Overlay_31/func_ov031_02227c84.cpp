#include <globaldefs.h>


extern "C" int func_ov031_02222adc(void *buf);
extern "C" void HaltSystem(void);
extern "C" void func_ov031_02236250(void *buf);

// USA: func_ov031_02227c84
extern "C" ARM void func_ov031_02227c84(void) {
    char buf[0xe8];
    if (func_ov031_02222adc(buf) != 1) {
        HaltSystem();
    }
    func_ov031_02236250(buf);
}
