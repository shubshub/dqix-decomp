#include <globaldefs.h>

struct Struct_02081f20 {
    unsigned short field_0;
    unsigned char unknown_2_;
};

struct Struct_02081f20_2 {
    struct Struct_02081f20 *field_0;
    unsigned short unknown_4_;
    signed char unknown_6_;
    signed char unknown_7_;
    signed char field_8;
};

// USA: func_0208203c
extern "C" ARM void func_0208203c(struct Struct_02081f20_2 *obj) {
    struct Struct_02081f20 *sub = obj->field_0;
    if (sub != NULL) {
        sub->field_0 = 0;
        sub->unknown_2_ = 0;
    }
    obj->unknown_4_ = 0;
    obj->field_8 = obj->unknown_6_;
}
