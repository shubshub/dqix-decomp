#include <globaldefs.h>

struct Struct_ov023_021fb1c8_2 {
    int field0;
    int field4;
};

struct Struct_ov023_021fb1c8 {
    char pad[0x28];
    int field28;
    int field2c;
};

// USA: func_ov023_021fb1c8
extern "C" ARM void func_ov023_021fb1c8(struct Struct_ov023_021fb1c8* dst, struct Struct_ov023_021fb1c8_2* src) {
    dst->field28 = src->field0;
    dst->field2c = src->field4;
}
