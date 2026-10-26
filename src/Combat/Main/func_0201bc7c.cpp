#include <globaldefs.h>

struct Struct_0201bc7c;

// USA: func_0201bc7c
extern "C" ARM void func_0201bc7c(Struct_0201bc7c* obj, unsigned short value) {
#if defined(jpn)
    *(unsigned short*)((char*)obj + 0x2818) = value;
#else
    *(unsigned short*)((char*)obj + 0x27d8) = value;
#endif
}
