#include <globaldefs.h>

struct Struct_020c94e4 {
    char pad0[0xc];
    int fieldc;
    short field10;
    short field12;
};

// USA: func_020c965c
extern "C" ARM int func_020c965c(struct Struct_020c94e4* p, int x, int y) {
    int dx = x - p->fieldc;
    int dy = y - p->field10;
    if (dx < 0 || (dx == 0 && dy < 0)) return 0;
    if (dy < 0) dy += 0x107;
    if (dy <= p->field12) return 1;
    return 2;
}
