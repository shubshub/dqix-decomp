#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02054224_396 = 0x180 };
#else
enum { Enum_02054224_396 = 0x18c };
#endif

// USA: func_02054224
extern "C" ARM void func_02054224(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + Enum_02054224_396);
    *flags |= 0x180;
}
