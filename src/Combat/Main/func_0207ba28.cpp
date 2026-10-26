#include <globaldefs.h>

struct Struct_0207ba28 {
    int x;
    int y;
    int z;
};

// USA: func_0207ba28
extern "C" ARM void func_0207ba28(struct Struct_0207ba28* base, int i, int* outX, int* outY, int* arg4) {
    *outX = base[i].x;
    *outY = base[i].y;
    *arg4 = base[i].z;
}
