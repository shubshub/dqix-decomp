#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021dcc64_24576 = 0x7000, Enum_ov025_021dcc64_3659 = 0x3b };
#else
enum { Enum_ov025_021dcc64_24576 = 0x6000, Enum_ov025_021dcc64_3659 = 0xe4b };
#endif

// USA: func_ov025_021dcc64
extern "C" ARM unsigned char func_ov025_021dcc64(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    return (base + Enum_ov025_021dcc64_24576)[Enum_ov025_021dcc64_3659];
}
