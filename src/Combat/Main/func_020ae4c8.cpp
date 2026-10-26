#include <globaldefs.h>
#include "Resource/GameResources.h"

// USA: func_020ae4c8
extern "C" ARM bool func_020ae4c8() {
    int base = (int)GetGameResources();
#if defined(jpn)
    int p = *(int*)(base + 0x3524);
#else
    int p = *(int*)(base + 0x3734);
#endif
    return *(unsigned short*)(p + 0xa) == 4;
}
