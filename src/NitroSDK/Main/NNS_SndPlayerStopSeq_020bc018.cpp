#include <globaldefs.h>

extern "C" void* func_020bc548(void* p);

// Main, originally CallFunc020bc548OnField0_020bc018 (USA 0x020bc018, EUR 0x020bc028, JPN 0x020bdae4)
extern "C" ARM void* NNS_SndPlayerStopSeq(void* obj, int) {
    return func_020bc548(*(void**)obj);
}
