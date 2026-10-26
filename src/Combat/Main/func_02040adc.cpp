#include <globaldefs.h>

struct Struct_02040adc {
    char unk[0x2e];
    short value;
};

struct Struct_0203de84_3 {
    char unk[0x14];
    struct Struct_02040adc* sub;
};

// USA: func_02040adc
extern "C" ARM int func_02040adc(struct Struct_0203de84_3* obj) {
    struct Struct_02040adc* sub = obj->sub;
    if (sub != 0) {
        return sub->value;
    }
    return 0x3d;
}
