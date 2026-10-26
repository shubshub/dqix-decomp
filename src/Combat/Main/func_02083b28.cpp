#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02083b28_2284 = 0x854 };
#else
enum { Enum_02083b28_2284 = 0x8ec };
#endif

// USA: func_02083b28
extern "C" ARM void func_02083b28(unsigned char* obj, int index) {
    unsigned char* p = obj + Enum_02083b28_2284;
    p[index / 8] &= ~(1 << (index % 8));
}
