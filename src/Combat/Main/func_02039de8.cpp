#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02039de8_462 = 0x1c2 };
#else
enum { Enum_02039de8_462 = 0x1ce };
#endif

// USA: func_02039de8
extern "C" ARM unsigned int func_02039de8(unsigned char* obj) {
    return obj[Enum_02039de8_462] & 0x10;
}
