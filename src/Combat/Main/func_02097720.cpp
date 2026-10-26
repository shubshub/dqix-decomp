#include <globaldefs.h>

struct Struct_02097720 {
    unsigned char pad0[0xe];
    short value;
    unsigned char pad10[0x13 - 0x10];
    unsigned char bit0 : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 1;
    unsigned char unknown_13_3_ : 5;
    unsigned char unknown_14_[0x20 - 0x14];
};

struct Struct_020976e0_2 {
    unsigned int unknown_0_;
    unsigned int count : 12;
    unsigned int unknown_5_4_ : 20;
    struct Struct_02097720* arr;
};

// USA: func_02097720
extern "C" ARM struct Struct_02097720* func_02097720(struct Struct_020976e0_2* obj, int threshold) {
    unsigned short count = obj->count;
    struct Struct_02097720* arr = obj->arr;
    short best = 0x7fff;
    struct Struct_02097720* result = 0;
    unsigned short i;
    for (i = 0; i < count; i++) {
        struct Struct_02097720* e = &arr[i];
        if (!e->unknown_13_2_ && e->bit0) {
            if (e->value > threshold && best > e->value) {
                best = e->value;
                result = e;
            }
        }
    }
    return result;
}
