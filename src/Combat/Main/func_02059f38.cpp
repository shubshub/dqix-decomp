#include <globaldefs.h>

struct Struct_02059cfc_3 {
    int x;
    int y;
    int z;
};

struct Struct_02059cfc_2 {
    char unk0[0x44];
    int field44;
    int field48;
    int field4c;
};

// USA: func_02059f38
extern "C" ARM void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src) {
    dst->field44 = src->x;
    dst->field48 = src->y;
    dst->field4c = src->z;
}
