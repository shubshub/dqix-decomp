#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020465f0_2306 = 0x7d2 };
#else
enum { Enum_020465f0_2306 = 0x902 };
#endif

// USA: func_020465f0
extern "C" ARM void func_020465f0(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[Enum_020465f0_2306] = value;
    }
}
