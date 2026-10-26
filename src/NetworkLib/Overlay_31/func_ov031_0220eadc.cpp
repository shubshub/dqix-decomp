#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

extern "C" int func_ov031_0220d60c(void);

// USA: func_ov031_0220eadc
extern "C" ARM void func_ov031_0220eadc(void) {
    int state = DisableIRQInterrupts();
    int base = func_ov031_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return;
    }
    char* p = (char*)base + 0x2000;
    void* arr = *(void**)(p + 0x270);
    if (arr != NULL) {
        int cnt = *(int*)(p + 0x274);
        if (cnt > 0) {
            VectorizedMemset(arr, 0, cnt);
        }
    }
    SetIRQInterruptState(state);
}
