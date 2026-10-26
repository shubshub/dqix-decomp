#include <globaldefs.h>

#if defined(jpn)
#define func_020c9bf0 func_020cb6bc
#endif

#define IME (*(volatile unsigned short*)0x04000208)
#define IF (*(volatile unsigned long*)0x04000214)
#define IE_TIMER0 0x8
#define IE_FIFO_RECV 0x40000
#define IE_CARD_IREQ 0x100000
#define IE_ALL 0x3fffff

#define VBLANK_COUNT (*(volatile unsigned long*)0x027ffc3c)
#define BOOT_TYPE (*(volatile unsigned short*)0x027ffc40)
#define BOOT_TYPE_MULTIBOOT 2

#define DISPCNT (*(volatile unsigned int*)0x04000000)
#define DISPCNTSUB (*(volatile unsigned int*)0x04001000)

#define PM_SUCCESS 0
#define PM_LCD_ALL 2
#define PM_BACKLIGHT_OFF 0
#define PM_LCD_POWER_ON 1
#define PM_LED_ON 1
#define PM_TRIGGER_CARD 0x8
#define PM_TRIGGER_CARTRIDGE 0x10

#define BACKLIGHT_RECOVER_TOP_ON 0x40
#define BACKLIGHT_RECOVER_BOTTOM_ON 0x80

#define RETRY_WAIT_CYCLES 0xa3a47
#define LCD_POWER_WAIT_CYCLES 0x360000

struct Struct_020cef0c;

struct Struct_021117ec_5
{
    unsigned short unknown_0_;
    unsigned long unknown_4_;
    unsigned long unknown_8_;
    volatile int unknown_c_;
    unsigned long unknown_10_;
    Struct_020cef0c* unknown_14_;
    Struct_020cef0c* unknown_18_;
};

extern Struct_021117ec_5 data_021117ec;

static inline int inline_020ce89c()
{
    const unsigned short var0 = IME;
    IME = 0;
    return var0;
}

static inline int inline_020ce89c_2()
{
    const unsigned short var0 = IME;
    IME = 1;
    return var0;
}

static inline int inline_020ce89c_3(int enable)
{
    const unsigned short var0 = IME;
    IME = enable;
    return var0;
}

static inline unsigned long inline_020ce89c_4()
{
    return VBLANK_COUNT;
}

extern "C" void func_020c976c(unsigned long cycles);
extern "C" void func_020c9bf0();
extern "C" int func_020d135c();
extern "C" int func_020ceba8(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_020cef0c(Struct_020cef0c* list);
int DisableIRQInterrupts();
int SetIRQInterruptState(int);
unsigned int DisableSpecificInterrupts(unsigned int mask);
unsigned int SetSpecificInterruptsEnabled(unsigned int mask);
int Is64BitTimerInitialized();
extern "C" int IsLcdPowerOn();
extern "C" unsigned long func_020ce810(int* top, int* bottom);
extern "C" unsigned long func_020ce6d0(int target, int arg1);
extern "C" unsigned long func_020ce614(int status);
extern "C" unsigned long func_020ce45c(int trigger, int arg1);
extern "C" unsigned long func_020ce7a4();

// Main, originally func_020ce89c (USA 0x020ce89c, EUR 0x020ce8ac, JPN 0x020d0368)
extern "C" ARM void EnterSleepMode(int trigger, int logic, unsigned short keyPattern)
{
    int var0;
    int var1;
    unsigned int var2;
    int var3 = false;
    int var4;
    int var5;
    unsigned long var6;
    unsigned long var7;
    int preLCDPower;

    func_020cef0c(data_021117ec.unknown_18_);

    var0 = inline_020ce89c();
    var1 = DisableIRQInterrupts();
    var2 = DisableSpecificInterrupts(IE_ALL);
    SetSpecificInterruptsEnabled(IE_FIFO_RECV | (Is64BitTimerInitialized() ? IE_TIMER0 : 0));
    SetIRQInterruptState(var1);
    inline_020ce89c_2();

    if (trigger & PM_TRIGGER_CARD)
    {
        if (BOOT_TYPE == BOOT_TYPE_MULTIBOOT)
            trigger &= ~PM_TRIGGER_CARD;
    }
    if (trigger & PM_TRIGGER_CARTRIDGE)
    {
        if (!func_020d135c())
            trigger &= ~PM_TRIGGER_CARTRIDGE;
    }

    var6 = DISPCNT;
    var7 = DISPCNTSUB;
    preLCDPower = IsLcdPowerOn();
    if (func_020ce810(&var4, &var5) != PM_SUCCESS)
        do
            func_020c976c(RETRY_WAIT_CYCLES);
        while (func_020ce810(&var4, &var5) != PM_SUCCESS);
    if (func_020ce6d0(PM_LCD_ALL, PM_BACKLIGHT_OFF) != PM_SUCCESS)
        do
            func_020c976c(RETRY_WAIT_CYCLES);
        while (func_020ce6d0(PM_LCD_ALL, PM_BACKLIGHT_OFF) != PM_SUCCESS);

    {
        volatile unsigned long var9 = inline_020ce89c_4();
        while (var9 == inline_020ce89c_4())
        {
        }
        var9 = inline_020ce89c_4();
        DISPCNT = DISPCNT & ~0x30000;
        DISPCNTSUB = DISPCNTSUB & ~0x10000;
        while (var9 == inline_020ce89c_4())
        {
        }
        var9 = inline_020ce89c_4();
        while (var9 == inline_020ce89c_4())
        {
        }
    }

    data_021117ec.unknown_c_ = false;
    func_020ce45c(
        (unsigned short)(trigger | (var4 ? BACKLIGHT_RECOVER_TOP_ON : 0) | (var5 ? BACKLIGHT_RECOVER_BOTTOM_ON : 0)),
        (unsigned short)(logic | keyPattern));
    if (!data_021117ec.unknown_c_)
        do
            func_020c9bf0();
        while (!data_021117ec.unknown_c_);

    if ((trigger & PM_TRIGGER_CARD) && (IF & IE_CARD_IREQ))
        var3 = true;

    if (!var3)
    {
        if (preLCDPower == PM_LCD_POWER_ON)
        {
            while (func_020ceba8(PM_LCD_POWER_ON, PM_LED_ON, true, true) != true)
            {
            }
        }
        else
        {
            if (func_020ce614(PM_LED_ON) != PM_SUCCESS)
                do
                    func_020c976c(RETRY_WAIT_CYCLES);
                while (func_020ce614(PM_LED_ON) != PM_SUCCESS);
        }
        DISPCNT = var6;
        DISPCNTSUB = var7;
    }

    func_020c976c(LCD_POWER_WAIT_CYCLES);

    DisableIRQInterrupts();
    SetSpecificInterruptsEnabled(var2);
    SetIRQInterruptState(var1);
    inline_020ce89c_3(var0);

    if (var3)
        func_020ce7a4();

    func_020cef0c(data_021117ec.unknown_14_);
}
