#include <globaldefs.h>

#if defined(jpn)
#define func_020c9bf0 func_020cb6bc
#endif


unsigned int DisableIRQInterrupts(void);
extern "C" void func_020c9bf0(void);

// Main, originally func_020c9be0 (USA 0x020c9be0, EUR 0x020c9bf0, JPN 0x020cb6ac)
extern "C" ARM void HaltSystem(void) {
    for (;;) {
        DisableIRQInterrupts();
        func_020c9bf0();
    }
}
