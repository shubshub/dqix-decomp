#include <globaldefs.h>

extern "C" int func_020bdce8(void* obj, int arg);

// Main, originally IsDispatchResultZero020bdc80 (USA 0x020bdc80, EUR 0x020bdc90, JPN 0x020bf74c)
extern "C" ARM int NNS_SndArcLoadGroup(void* obj, int arg) {
    return func_020bdce8(obj, arg) == 0;
}
