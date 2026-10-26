#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021fb254_66 = 0x40 };
#else
enum { Enum_ov023_021fb254_66 = 0x42 };
#endif

// USA: func_ov023_021fb254
extern "C" ARM unsigned short func_ov023_021fb254(void* obj) {
    return *(unsigned short*)((char*)obj + Enum_ov023_021fb254_66);
}
