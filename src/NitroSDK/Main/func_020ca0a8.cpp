#include <globaldefs.h>
#include "NitroSDK/DMA.h"
#include "NitroSDK/Interrupts.h"

#if defined(jpn)
#define func_020ca0a8 func_020cbb74
#endif

#define REG_GXSTAT (*(volatile unsigned long*)0x04000600)

typedef void (*Type_020ca0a8)(void* arg);

struct Struct_02111684
{
    volatile int unknown_0_;
    unsigned long channel;
    unsigned long src;
    unsigned long length;
    Type_020ca0a8 callback;
    void* arg;
    unsigned long unknown_18_;
    InterruptHandlerProc unknown_1c_;
};

extern Struct_02111684 data_02111684;

extern "C" void func_020ca1a0();

static inline void inline_020ca0a8(unsigned long arg0)
{
    REG_GXSTAT = (arg0 << 30) | (REG_GXSTAT & ~0xc0000000);
}

static inline void inline_020ca0a8_2(Type_020ca0a8 callback, void* arg)
{
    if (callback)
    {
        callback(arg);
    }
}

// USA: func_020ca0a8
extern "C" ARM void func_020ca0a8(unsigned long channel, const void* src, unsigned long length,
    Type_020ca0a8 callback, void* arg)
{
    if (length == 0)
    {
        inline_020ca0a8_2(callback, arg);
        return;
    }

    while (data_02111684.unknown_0_)
    {
    }

    while (!(((REG_GXSTAT & 0x07000000) >> 24) & 2))
    {
    }

    data_02111684.unknown_0_ = 1;
    data_02111684.channel = channel;
    data_02111684.src = (unsigned long)src;
    data_02111684.length = length;
    data_02111684.callback = callback;
    data_02111684.arg = arg;

    VerifyDMASource(channel, (unsigned long)src, length, 0);
    AwaitDMACompletion(channel);

    {
        int var0 = DisableIRQInterrupts();

        data_02111684.unknown_18_ = (REG_GXSTAT & 0xc0000000) >> 30;
        data_02111684.unknown_1c_ = GetInterruptHandler(0x200000);

        inline_020ca0a8(1);
        SetInterruptHandler(0x200000, (const void*)func_020ca1a0);
        EnableSpecificInterrupts(0x200000);
        func_020ca1a0();

        SetIRQInterruptState(var0);
    }
}
