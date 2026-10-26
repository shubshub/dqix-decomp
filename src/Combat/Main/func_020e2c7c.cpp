#include <globaldefs.h>
typedef void (*Type_020e2bd8)(int, int);
extern Type_020e2bd8 data_020f2c04[][2];
extern Type_020e2bd8 data_020f2be4[];
struct Struct_020e2bd8_2 {
    unsigned char pad0;
    unsigned char type;
    unsigned char subtype;
    unsigned char pad3;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
};
// USA: func_020e2c7c
extern "C" ARM void func_020e2c7c(struct Struct_020e2bd8_2* obj) {
    data_020f2c04[obj->type][obj->subtype](obj->w4, obj->w8);
    data_020f2be4[obj->type](obj->unknown_c_, obj->unknown_10_);
}
