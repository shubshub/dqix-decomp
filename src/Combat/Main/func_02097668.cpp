#include <globaldefs.h>

struct Struct_02097668 {
    unsigned char pad0[0x13];
    unsigned char bit0 : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 1;
    unsigned char unknown_13_3_ : 5;
    unsigned char unknown_14_[0x1a - 0x14];
    short value;
    unsigned char unknown_1c_[0x20 - 0x1c];
};

struct Struct_02097628_2 {
    unsigned int unknown_0_;
    unsigned int count : 12;
    unsigned int unknown_5_4_ : 20;
    struct Struct_02097668* arr;
};

// USA: func_02097668
extern "C" ARM struct Struct_02097668* func_02097668(struct Struct_02097628_2* obj, int threshold) {
    unsigned short count = obj->count;
    struct Struct_02097668* arr = obj->arr;
    short best = 0x7fff;
    struct Struct_02097668* result = 0;
    unsigned short i;
    for (i = 0; i < count; i++) {
        struct Struct_02097668* e = &arr[i];
        if (!e->unknown_13_2_ && e->bit0) {
            if (e->value > threshold && best > e->value) {
                best = e->value;
                result = e;
            }
        }
    }
    return result;
}
