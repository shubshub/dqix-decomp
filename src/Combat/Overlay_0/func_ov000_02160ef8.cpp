#include <globaldefs.h>
#include "Util/Random.h"

#if defined(jpn)
enum { Enum_ov000_02160ef8_668 = 0x218 };
#else
enum { Enum_ov000_02160ef8_668 = 0x29c };
#endif

// USA: func_ov000_02160ef8
extern "C" ARM struct Random* func_ov000_02160ef8(unsigned char* obj) {
    return *(struct Random**)(obj + Enum_ov000_02160ef8_668);
}
