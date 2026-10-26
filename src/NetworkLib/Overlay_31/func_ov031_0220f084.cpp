#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov031_0220d60c(void);

// USA: func_ov031_0220f084
extern "C" ARM void* func_ov031_0220f084(unsigned short* out) {
    void* result = NULL;
    unsigned short val = 0;
    int base = func_ov031_0220d60c();
    unsigned int state = DisableIRQInterrupts();
    if (base != 0) {
        if (*(int*)((char*)base + 0x2260) == 9 && *(unsigned char*)((char*)base + 0x226b) == 0) {
            val = *(unsigned short*)((char*)base + 0x214a);
            result = (char*)base + 0x214c;
        }
    }
    SetIRQInterruptState(state);
    if (out != NULL) {
        *out = val;
    }
    return result;
}
