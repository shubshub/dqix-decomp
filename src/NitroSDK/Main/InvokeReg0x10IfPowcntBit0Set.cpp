#include <globaldefs.h>
int RunHandlerWithFallbackDispatch020ce56c(int, int, int);

int IsLcdPowerOn(void);

// USA: func_020ce7e0
ARM int InvokeReg0x10IfPowcntBit0Set_020ce7e0(int id) {
    if (IsLcdPowerOn() == 0) {
        return 0;
    }
    return RunHandlerWithFallbackDispatch020ce56c((int)(0x10), (int)((unsigned short)id), (int)(0));
}
