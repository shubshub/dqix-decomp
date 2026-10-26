#include <globaldefs.h>
typedef void (*Type_020439b0)(int, int, int, int);
extern Type_020439b0 data_020f2bf4[][2];
struct Struct_020e2bd8_2;
extern "C" void func_020e2c7c(struct Struct_020e2bd8_2* obj);
struct Struct_020439b0_4 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
    unsigned char pad3;
    char pad[0x10];
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
};
// USA: func_020e2c34
extern "C" ARM void func_020e2c34(struct Struct_020439b0_4* obj) {
    if (obj->state == 0) return;
    func_020e2c7c((struct Struct_020e2bd8_2*)obj);
    data_020f2bf4[obj->type][obj->subtype](obj->unknown_14_, obj->unknown_18_, obj->unknown_1c_, obj->unknown_20_);
}
