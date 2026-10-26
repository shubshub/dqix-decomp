#include <globaldefs.h>

// The GameObject's flag byte (+0x1ce, jpn +0x1c2). Bit 8's setter is not identified.
#if defined(jpn)
enum { kActorFlagsOffset = 0x1c2 };
#else
enum { kActorFlagsOffset = 0x1ce };
#endif

// USA: func_02039dbc
extern "C" ARM void func_02039dbc(unsigned char* actor) {
    actor[kActorFlagsOffset] &= ~8;
}
