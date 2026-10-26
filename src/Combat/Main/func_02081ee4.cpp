#include <globaldefs.h>

struct Struct_02081ee4_2 {
    unsigned short field_0;
    unsigned char unknown_2_;
};

struct Struct_02081ee4 {
    struct Struct_02081ee4_2 *field_0;
    unsigned short unknown_4_;
    signed char unknown_6_;
    signed char unknown_7_;
    signed char field_8;
};

// USA: func_02081ee4
extern "C" ARM void func_02081ee4(struct Struct_02081ee4 *obj, struct Struct_02081ee4_2 *sub) {
    obj->field_0 = 0;
    if (sub != NULL) {
        obj->field_0 = sub;
        sub->field_0 = 0;
        sub->unknown_2_ = 0;
    }
    obj->unknown_4_ = 0;
    obj->unknown_6_ = 20;
    obj->unknown_7_ = 10;
    obj->field_8 = obj->unknown_6_;
}
