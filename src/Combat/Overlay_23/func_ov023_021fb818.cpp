#include <globaldefs.h>

struct Struct_02075db0;
extern "C" int func_02075db0(struct Struct_02075db0* s, int a, int b);

// USA: func_ov023_021fb818
extern "C" ARM int func_ov023_021fb818(void* obj) {
    unsigned char flagA = *(unsigned char*)((char*)obj + 0xb0);
    int dx = 0;
    int dy = 0;
    if (flagA != 0) {
        dx = 1;
        dy = dx;
    }
#if !defined(jpn)
    else {
        unsigned char var3 = *(unsigned char*)((char*)obj + 0xb1);
        if (var3 != 0) {
            dx = dx - 1;
            dy = 1;
        }
    }

#endif
    func_02075db0((struct Struct_02075db0*)((char*)obj + 0x20),
        *(int*)((char*)obj + 0xa8) + dx,
        *(int*)((char*)obj + 0xac) + dy);
    *(unsigned char*)((char*)obj + 0xb0) = 0;
#if !defined(jpn)
    *(unsigned char*)((char*)obj + 0xb1) = 0;
#endif
    return *(int*)((char*)obj + 0x1c);
}
