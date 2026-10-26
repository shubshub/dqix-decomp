#include <globaldefs.h>

#define VBLANK_COUNT (*(volatile unsigned long*)0x027ffc3c)
#define POWCNT (*(volatile unsigned short*)0x04000304)

#define PM_SUCCESS 0
#define PM_LCD_POWER_OFF 0
#define PM_LCD_POWER_ON 1
#define PM_LED_NONE 0

#define LCD_OFF_WAIT_FRAMES 7
#define LCD_INIT_WAIT_FRAMES 2
#define RETRY_WAIT_CYCLES 0xa3a47

struct Struct_021117ec_5
{
    unsigned short unknown_0_;
    unsigned long unknown_4_;
    unsigned long unknown_8_;
    volatile int unknown_c_;
    unsigned long unknown_10_;
};

extern Struct_021117ec_5 data_021117ec;

extern "C" void func_020c976c(unsigned long cycles);
extern "C" void OS_WaitVBlankIntr();
extern "C" unsigned long func_020ce614(int status);
extern "C" unsigned long func_020ce5b0(int arg0, void (*callback)(), int* arg);
extern "C" unsigned long func_020ce7e0(int value);

// USA: func_020ceba8
extern "C" ARM int func_020ceba8(int arg0, int arg1, int arg2, int arg3)
{
    switch (arg0)
    {
    case PM_LCD_POWER_ON:
        if (!arg2 && VBLANK_COUNT - data_021117ec.unknown_4_ <= LCD_OFF_WAIT_FRAMES)
            return false;
        if (arg1 != PM_LED_NONE)
        {
            if (arg3)
            {
                if (func_020ce614(arg1) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (func_020ce614(arg1) != PM_SUCCESS);
            }
            else
            {
                if (func_020ce5b0(arg1, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (func_020ce5b0(arg1, NULL, NULL) != PM_SUCCESS);
            }
        }
        POWCNT |= 1;
        if (func_020ce7e0(data_021117ec.unknown_10_) != PM_SUCCESS)
            do
                func_020c976c(RETRY_WAIT_CYCLES);
            while (func_020ce7e0(data_021117ec.unknown_10_) != PM_SUCCESS);
        break;
    case PM_LCD_POWER_OFF:
        if (func_020ce7e0(0) != PM_SUCCESS)
            do
                func_020c976c(RETRY_WAIT_CYCLES);
            while (func_020ce7e0(0) != PM_SUCCESS);
        if (VBLANK_COUNT - data_021117ec.unknown_8_ <= LCD_INIT_WAIT_FRAMES)
        {
            OS_WaitVBlankIntr();
            OS_WaitVBlankIntr();
        }
        POWCNT &= ~1;
        data_021117ec.unknown_4_ = VBLANK_COUNT;
        if (arg1 != PM_LED_NONE)
        {
            if (arg3)
            {
                if (func_020ce614(arg1) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (func_020ce614(arg1) != PM_SUCCESS);
            }
            else
            {
                if (func_020ce5b0(arg1, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (func_020ce5b0(arg1, NULL, NULL) != PM_SUCCESS);
            }
        }
        break;
    }
    return true;
}
