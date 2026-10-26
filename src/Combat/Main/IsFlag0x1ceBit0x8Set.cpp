#include <globaldefs.h>

// The GameObject's flag byte (+0x1ce, jpn +0x1c2). Bit 8's setter is not identified.
#if defined(jpn)
enum { kActorFlagsOffset = 0x1c2 };
#else
enum { kActorFlagsOffset = 0x1ce };
#endif

// USA: func_02039dcc
ARM unsigned int IsFlag0x1ceBit0x8Set_02039dcc(unsigned char* actor) {
    return actor[kActorFlagsOffset] & 0x8;
}
