#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x57e4 };
#else
enum { kFlagsOffset = 0x55f4 };
#endif

// USA: func_ov000_02160fd4
extern "C" ARM int func_ov000_02160fd4(void* work, int mask) {
    return *(int*)((char*)work + kFlagsOffset) & mask;
}
