#include <globaldefs.h>


void WaitWhileChannelBusy_020d1564(int);
extern "C" void HaltSystem(void);

// USA: func_020d192c
ARM void SpinDrainAfterWait_020d192c(void) {
    WaitWhileChannelBusy_020d1564(2);
    HaltSystem();
}
