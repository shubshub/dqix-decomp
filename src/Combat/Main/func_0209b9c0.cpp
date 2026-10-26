#include <globaldefs.h>

struct Struct_0209ad40_3 { char pad[0x4c]; };

// USA: func_0209b9c0
extern "C" ARM struct Struct_0209ad40_3* func_0209b9c0(struct Struct_0209ad40_3 *base, int i) {
    if (i < 0 || i >= 6) return NULL;
    return &base[i];
}
