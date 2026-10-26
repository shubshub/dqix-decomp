#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02054248_396 = 0x180 };
#else
enum { Enum_02054248_396 = 0x18c };
#endif

// USA: func_02054248
extern "C" ARM void func_02054248(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + Enum_02054248_396);
    unsigned int value = *flags;
    if (!(value & 0x100)) {
        return;
    }
    if (value & 0x80) {
        *flags = value | 0x1;
    } else if (value & 0x80) {
        *flags = value & ~0x1;
    }
    *flags = *flags & ~0x100;
}
