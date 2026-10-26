#include <globaldefs.h>
#include "NitroSDK/DMA.h"
#include "NitroSDK/Interrupts.h"

extern "C" void func_020ca24c(void);

struct Struct_02111684_2 {
    char pad0[4];
    int channel;
    unsigned int unknown_8_;
    unsigned int remaining;
};
extern struct Struct_02111684_2 data_02111684;

// USA: func_020ca1a0
extern "C" ARM void func_020ca1a0(void) {
    unsigned int src;
    unsigned int var1;
    if (data_02111684.remaining == 0) return;
    var1 = data_02111684.remaining;
    if (var1 >= 0x1d8) var1 = 0x1d8;
    src = data_02111684.unknown_8_;
    unsigned int var2 = *(unsigned int*)&data_02111684.remaining - var1;
    data_02111684.remaining = var2;
    data_02111684.unknown_8_ = src + var1;
    if (var2 == 0) {
        SetDMACompletionCallback(data_02111684.channel, (DMACompletionCallback)func_020ca24c, 0);
        ConfigureDMATransferAtomic(data_02111684.channel, src, 0x04000400, 0xc4400000 | (var1 >> 2));
        AcknowledgeSpecificInterrupts(0x200000);
    } else {
        ConfigureDMATransferAtomic(data_02111684.channel, src, 0x04000400, 0x84400000 | (var1 >> 2));
        AcknowledgeSpecificInterrupts(0x200000);
    }
}
