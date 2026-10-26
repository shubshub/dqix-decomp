#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020535c8_380 = 0x170 };
#else
enum { Enum_020535c8_380 = 0x17c };
#endif

// Main, originally CheckSubstructByte0x7cPositive_020535c8 (USA 0x020535c8, EUR 0x020535d8, JPN 0x02054940)
extern "C" ARM int GameObject_IsGesturing(signed char* obj) {
    return obj[Enum_020535c8_380] > 0;
}
