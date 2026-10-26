#include <globaldefs.h>
#include "NitroSDK/DMA.h"
#include "NitroSDK/Interrupts.h"

#if defined(jpn)
#define func_020ca2ac func_020cbd78
#endif

extern "C" void func_020ca364(void);

struct Struct_02111684_4 {
    int flag;
    int channel;
    char pad8[8];
    DMACompletionCallback callback;
    int unknown_14_;
};
extern struct Struct_02111684_4 data_02111684;

// USA: func_020ca2ac
extern "C" ARM void func_020ca2ac(int channel, unsigned int src, unsigned int len, DMACompletionCallback callback, int arg4) {
    if (len == 0) {
        if (callback != 0) {
            callback(arg4);
        }
        return;
    }

    while (*(volatile int*)&data_02111684.flag != 0) ;

    *(volatile int*)&data_02111684.flag = 1;
    data_02111684.channel = channel;
    data_02111684.callback = callback;
    data_02111684.unknown_14_ = arg4;

    VerifyDMATimingChangePermitted_020c9fd0(channel, 0x38000000);
    VerifyDMASource(channel, src, len, 0);
    AwaitDMACompletion(channel);
    SetDMACompletionCallback(channel, (DMACompletionCallback)func_020ca364, 0);
    ConfigureDMATransferAtomic(channel, src, 0x4000400, 0xfc400000 | (len >> 2));
}
