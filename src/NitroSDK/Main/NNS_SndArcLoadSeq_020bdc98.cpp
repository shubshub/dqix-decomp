#include <globaldefs.h>

extern "C" int func_020bddec(void* obj, int a, int b, int c, int d);

// Main, originally IsQueryResultZeroWildcard020bdc98 (USA 0x020bdc98, EUR 0x020bdca8, JPN 0x020bf764)
extern "C" ARM int NNS_SndArcLoadSeq(void* obj, int arg) {
    return func_020bddec(obj, 0xff, arg, 1, 0) == 0;
}
