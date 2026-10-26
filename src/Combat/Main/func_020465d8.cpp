#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020465d8_2289 = 0x7c1 };
#else
enum { Enum_020465d8_2289 = 0x8f1 };
#endif

// USA: func_020465d8
extern "C" ARM void func_020465d8(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[Enum_020465d8_2289] = value;
    }
}
