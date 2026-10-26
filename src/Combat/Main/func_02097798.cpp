#include <globaldefs.h>

struct Struct_02097798 {
    unsigned char pad0[0x13];
    unsigned char bit0 : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 1;
    unsigned char unknown_13_3_ : 5;
    unsigned char unknown_14_[0x1a - 0x14];
    short order;
    unsigned char unknown_1c_[0x20 - 0x1c];
};

struct Struct_020972e0_2 {
    unsigned int unknown_0_;
    unsigned int count : 12;
    unsigned int unknown_5_4_ : 20;
    struct Struct_02097798* arr;
};

// USA: func_02097798
extern "C" ARM void func_02097798(struct Struct_020972e0_2* obj) {
    unsigned short count = obj->count;
    struct Struct_02097798* arr = obj->arr;
    short var2;
    unsigned short i;
    unsigned short j;
    unsigned short limit = count - 1;
    for (i = 0; i < limit; i++) {
        struct Struct_02097798* e = &arr[i];
        if (e->order <= 0) {
            e->unknown_13_2_ = 1;
        }
        if (!e->unknown_13_2_) {
            var2 = e->order;
            for (j = i + 1; j < count; j++) {
                if (arr[j].order == var2) {
                    arr[j].unknown_13_2_ = 1;
                }
            }
        }
    }
}
