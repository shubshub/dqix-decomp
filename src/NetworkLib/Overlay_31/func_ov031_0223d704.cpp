#include <globaldefs.h>

int SetLcdPower(int a);
extern unsigned char data_ov031_02290d40;

// USA: func_ov031_0223d704
extern "C" ARM void func_ov031_0223d704(void) {
    unsigned char flag = data_ov031_02290d40;
    volatile unsigned short* p = (volatile unsigned short*)0x27fffa8;
    if (flag != 0) {
        if ((*p & 0x8000) >> 15) return;
        if (SetLcdPower(1) == 0) return;
        data_ov031_02290d40 = 0;
    } else {
        if (((*p & 0x8000) >> 15) == 0) return;
        if (SetLcdPower(0) != 0) {
            data_ov031_02290d40 = 1;
        }
    }
}
