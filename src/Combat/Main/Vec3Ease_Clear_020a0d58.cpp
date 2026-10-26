#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally Clear0x28Bytes_020a0d58 (USA 0x020a0d58, EUR 0x020a0d68, JPN 0x020a2ad0)
ARM void Vec3Ease_Clear(void* p) {
    memset(p, 0, 0x28);
}
