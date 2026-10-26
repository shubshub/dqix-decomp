#include <globaldefs.h>

// USA: func_ov024_021eb4b0
extern "C" ARM int func_ov024_021eb4b0(int a0, int flags, int mask) {
    if (flags & 0x8) return 0;
    if (flags & 0x10) return 0;
    if (flags & 0x80000) return 0;
    return (flags & mask) == 0;
}
