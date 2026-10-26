#include <globaldefs.h>

#if defined(jpn)
#define func_020ca8e8 func_020cc3b4
#endif

void VerifyDMATimingChangePermitted_020c9fd0(int a, unsigned int b);
void VerifyDMASource(int channel, unsigned int source, unsigned int length, unsigned int sourceCtrlFlags);
void ConfigureDMATransferAtomic(int channel, unsigned int src, unsigned int dst, unsigned int ctrl);

// USA: func_020ca8e8
extern "C" ARM void func_020ca8e8(unsigned int chan, unsigned int addr, unsigned int len, unsigned int size) {
    VerifyDMATimingChangePermitted_020c9fd0(chan, -1);
    VerifyDMASource(chan, addr, size, 0x1000000);
    if (size == 0) return;
    volatile unsigned int* var0 = (volatile unsigned int*)(0x040000b0 + (chan * 3 + 2) * 4);
    while (*var0 & 0x80000000) {}
    ConfigureDMATransferAtomic(chan, addr, len, 0xaf000001);
}
