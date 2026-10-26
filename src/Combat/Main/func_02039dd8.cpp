#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02039dd8_462 = 0x1c2 };
#else
enum { Enum_02039dd8_462 = 0x1ce };
#endif

// USA: func_02039dd8
extern "C" ARM void func_02039dd8(unsigned char* obj) {
    obj[Enum_02039dd8_462] |= 0x10;
}
