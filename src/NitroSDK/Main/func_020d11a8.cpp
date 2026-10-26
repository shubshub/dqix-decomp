#include <globaldefs.h>


void ResetDMAChannel(int id);
extern "C" int func_020ce7a4(void);
extern "C" void func_020c976c(unsigned int id);
extern "C" void func_020d1294(int a, int b);
extern "C" void HaltSystem(void);

// USA: func_020d11a8
extern "C" ARM void func_020d11a8(void) {
    int ok = 1;
    ResetDMAChannel(0);
    ResetDMAChannel(ok);
    ResetDMAChannel(2);
    ResetDMAChannel(3);

    int val = *(volatile unsigned short*)0x27fffa8;
    int flag = (val & 0x8000) >> 15;
    if (flag != 0) {
        int status = func_020ce7a4();
        if (status == 4) {
            do {
                func_020c976c(0xa3a47);
                status = func_020ce7a4();
            } while (status == 4);
        }
        if (status == 0) ok = 0;
    }
    if (ok != 0) {
        func_020d1294(1, 1);
    }
    HaltSystem();
}
