#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021fb22c_60 = 0x3a };
#else
enum { Enum_ov023_021fb22c_60 = 0x3c };
#endif

// USA: func_ov023_021fb22c
extern "C" ARM void func_ov023_021fb22c(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + Enum_ov023_021fb22c_60) = v;
}
