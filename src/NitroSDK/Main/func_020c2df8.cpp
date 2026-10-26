#include <globaldefs.h>

struct Struct_020c20d4 {
    int x;
    int y;
    int z;
};

// USA: func_020c2df8
extern "C" ARM int Vector3fix_InnerProduct(struct Struct_020c20d4* a, struct Struct_020c20d4* b) {
    long long var0 = (long long)a->x * b->x + (long long)a->y * b->y + (long long)a->z * b->z;
    return (int)((var0 + 0x800) >> 12);
}
