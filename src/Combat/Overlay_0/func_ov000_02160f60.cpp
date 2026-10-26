#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02160f60_668 = 0x218, Enum_ov000_02160f60_1496 = 0x7c8 };
#else
enum { Enum_ov000_02160f60_668 = 0x29c, Enum_ov000_02160f60_1496 = 0x5d8 };
#endif

// USA: func_ov000_02160f60
extern "C" ARM void* func_ov000_02160f60(void* obj) {
    int count = *(int*)((char*)obj + 0x5000 + Enum_ov000_02160f60_1496);
    if (count == 0) return 0;
    void* base = *(void**)((char*)obj + Enum_ov000_02160f60_668);
    return base ? (char*)base + 0x21c + 0x8000 + (count - 1) * 0x28 : 0;
}
