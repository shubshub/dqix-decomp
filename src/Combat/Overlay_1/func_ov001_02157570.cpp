#include <globaldefs.h>

struct Struct_ov001_02157570_2 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
};
struct Struct_ov001_02157570 {
    int x;
    int y;
    int z;
};

// USA: func_ov001_02157570
extern "C" ARM void func_ov001_02157570(struct Struct_ov001_02157570_2* src, struct Struct_ov001_02157570* dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
