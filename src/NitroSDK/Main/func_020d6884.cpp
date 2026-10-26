#include <globaldefs.h>

extern "C" int func_020d1ae4(unsigned int);

// USA: func_020d6884
extern "C" ARM int func_020d6884(void *obj, int value, int base, int bits) {
    return func_020d1ae4(value & ((1 << bits) - 1)) * *(unsigned short*)((char*)obj + 0x810) + base;
}
