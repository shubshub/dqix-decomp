#include <globaldefs.h>

extern "C" void func_020bf148(void*, int);

// Main, originally NotifyObjectIfPresent020bec58 (USA 0x020bec58, EUR 0x020bec68, JPN 0x020c0724)
extern "C" ARM void NNS_SndArcStrmStop(void* volatile* slot, int arg) {
    if (*slot != NULL) {
        func_020bf148(*slot, arg);
    }
}
