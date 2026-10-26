#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"

// USA: func_0200fba4
extern "C" ARM void* func_0200fba4(void* obj, const void* src) {
    return ZoneTransitionSettings_Copy(
        (CopyRecord0200fbb4*)((char*)obj + 0x3f8),
        (const CopyRecord0200fbb4*)src);
}
