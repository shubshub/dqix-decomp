#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" void func_020c94e4(void);
extern "C" void func_020c383c(int arg0);

// USA: func_020c945c
extern "C" ARM void func_020c945c(void* obj) {
    SetInterruptHandler(IRQ_MASK_LCD_VCOUNTER_MATCH, (const void*)func_020c94e4);
    func_020c383c(*(short*)((char*)obj + 0x10));
    *(volatile unsigned short*)0x4000004 |= 0x20;
    EnableSpecificInterrupts(IRQ_MASK_LCD_VCOUNTER_MATCH);
}
