#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02054234_396 = 0x180 };
#else
enum { Enum_02054234_396 = 0x18c };
#endif

// USA: func_02054234
extern "C" ARM void func_02054234(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + Enum_02054234_396);
    *flags = (*flags & ~0x80) | 0x100;
}
