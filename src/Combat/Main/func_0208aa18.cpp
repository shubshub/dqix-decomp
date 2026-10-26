#include <globaldefs.h>

struct Struct_0208aa18 {
    char unknown_0_[0xc];
    int x;
    int y;
    int z;
};

// USA: func_0208aa18
extern "C" ARM void func_0208aa18(struct Struct_0208aa18 *s, int x, int y, int z) {
    s->x = x;
    s->y = y;
    s->z = z;
}
