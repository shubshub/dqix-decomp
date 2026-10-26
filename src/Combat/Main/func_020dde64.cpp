#include <globaldefs.h>

struct Struct_020db3f4_2 {
    unsigned char pad0[4];
    unsigned char unknown_4_;
    unsigned char pad5[0xb];
    int field10;
    int field14;
    int field18;
    int field1c;
    unsigned char pad20[4];
    unsigned char unknown_24_;
};

// USA: func_020dde64
extern "C" ARM void func_020dde64(struct Struct_020db3f4_2* obj) {
    obj->unknown_4_ = 0;
    obj->field18 = 0;
    obj->field1c = 0;
    obj->field10 = 0;
    obj->field14 = 0;
    obj->unknown_24_ = 0;
}
