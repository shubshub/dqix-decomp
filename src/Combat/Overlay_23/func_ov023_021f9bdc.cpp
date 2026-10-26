#include <globaldefs.h>

struct Struct_ov004_021549e4_5 {
    char pad[0x26];
    unsigned short field26;
    unsigned short field28;
    unsigned short field2a;
};

// USA: func_ov023_021f9bdc
extern "C" ARM void func_ov023_021f9bdc(struct Struct_ov004_021549e4_5* o, int arg1) {
    o->field28 = arg1 / o->field26;
    o->field2a = arg1 % o->field26;
}
