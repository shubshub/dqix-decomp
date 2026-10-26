#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02011b50_988 = 0x17c };
#else
enum { Enum_02011b50_988 = 0x3dc };
#endif

// USA: func_02011b50
extern "C" ARM int func_02011b50(void* obj, int mask) {
    unsigned char* base = (unsigned char*)obj;
    return ((base + 0x6000)[Enum_02011b50_988] & mask) != 0;
}
