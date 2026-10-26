#include <globaldefs.h>

struct Struct_0201bc88;

// USA: func_0201bc88
extern "C" ARM void func_0201bc88(Struct_0201bc88* obj, unsigned short value) {
#if defined(jpn)
    *(unsigned short*)((char*)obj + 0x281a) = value;
#else
    *(unsigned short*)((char*)obj + 0x27da) = value;
#endif
}
