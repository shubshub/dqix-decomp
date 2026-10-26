#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void func_0208e870(char* obj);

extern char data_02108fe4;

// USA: func_020e62a0
extern "C" __declspec(initcode) ARM void __sinit_020e62a0(void) {
    func_0208e870(&data_02108fe4);
}
