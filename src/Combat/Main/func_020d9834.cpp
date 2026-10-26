#include <globaldefs.h>

void SleepCurrentContext(unsigned int arg);
void CycleCurrentPriorityContexts(void);

// USA: func_020d9834
extern "C" ARM void func_020d9834(int flag) {
    if (flag != 0) {
        SleepCurrentContext(flag);
    } else {
        CycleCurrentPriorityContexts();
    }
}
