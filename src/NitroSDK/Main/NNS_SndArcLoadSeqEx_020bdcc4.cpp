#include <globaldefs.h>

extern "C" int func_020bddec(void* obj, int a, int b, int c, int d);

// Main, originally IsQueryResultZero020bdcc4 (USA 0x020bdcc4, EUR 0x020bdcd4, JPN 0x020bf790)
extern "C" ARM int NNS_SndArcLoadSeqEx(void* obj, int a, int b) {
    return func_020bddec(obj, a, b, 1, 0) == 0;
}
