#include <globaldefs.h>

struct Vec020311e8 {
    int x;
    int y;
    int z;
};

// Main, originally func_020311e8 (USA 0x020311e8, EUR 0x020311f8, JPN 0x02030d20)
extern "C" ARM void Vector3fix_Set(Vec020311e8* v, int x, int y, int z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
