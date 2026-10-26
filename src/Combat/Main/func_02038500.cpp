#include <globaldefs.h>

struct Vec3038500 {
    int x;
    int y;
    int z;
};

// USA: func_02038500
extern "C" ARM void func_02038500(struct Vec3038500* obj, int x, int y, int z) {
    obj->x = x;
    obj->y = y;
    obj->z = z;
}
