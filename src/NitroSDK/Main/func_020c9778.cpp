#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

#if defined(jpn)
#define func_020c9bf0 func_020cb6bc
#endif

extern "C" void func_020c9bf0(void);
extern char data_027e0000;

#define INTERRUPT_MASTER_ENABLE (*(volatile unsigned short*)0x04000208)

// USA: func_020c9778
extern "C" ARM void func_020c9778(bool arg0, unsigned int mask) {
    int var0 = DisableIRQInterrupts();
    unsigned short var1 = INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = 1;

    if (arg0) {
        *(unsigned int*)((char*)&data_027e0000 + 0x3ff8) &= ~mask;
    }

    unsigned int* flags = (unsigned int*)((char*)&data_027e0000 + 0x3ff8);
    if ((mask & *(unsigned int*)((char*)&data_027e0000 + 0x3ff8)) == 0) {
        do {
            func_020c9bf0();
            EnableIRQInterrupts();
            DisableIRQInterrupts();
        } while ((mask & *flags) == 0);
    }
    *flags &= ~mask;

    (void)INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = var1;

    SetIRQInterruptState(var0);
}
