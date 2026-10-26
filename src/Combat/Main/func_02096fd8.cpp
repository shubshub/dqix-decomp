#include <globaldefs.h>

struct Struct_02096fd8 { unsigned short a; unsigned short b; };

// USA: func_02096fd8
extern "C" ARM int func_02096fd8(struct Struct_02096fd8 *h) {
    char *base = (char *)(h->a * 0x30);
    char *end = (char *)(((int)base + h->b * 4 + 3) & ~3);
    return (int)base + (end - base);
}
