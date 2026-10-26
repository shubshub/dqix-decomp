#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_020db3a8_14104 = 0x3508 };
#else
enum { Enum_020db3a8_14104 = 0x3718 };
#endif


struct Struct_020db3a8 {
    unsigned char pad[0x54];
    unsigned char field54;
};

// USA: func_020db3a8
extern "C" ARM int func_020db3a8(Struct_020db3a8* s) {
    if (s->field54 == 1 && ((*(unsigned short*)0x4000304 & 0x8000) >> 15) == 1) {
        return 1;
    }
    int base = (int)GetGameResources();
    int p = *(int*)(base + Enum_020db3a8_14104);
    return *(unsigned char*)(p + 3) != 0;
}
