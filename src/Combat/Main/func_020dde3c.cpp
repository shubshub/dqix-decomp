#include <globaldefs.h>

struct Struct_020db3f4_2;
extern "C" ARM void func_020dde64(struct Struct_020db3f4_2* obj);

struct Struct_020dafd4_3 {
    unsigned short field0;
    unsigned short field2;
    unsigned char pad4[4];
    int field8;
    int fieldc;
    unsigned char pad10[0x10];
    int field20;
};

// USA: func_020dde3c
extern "C" ARM void func_020dde3c(struct Struct_020dafd4_3* obj) {
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field0 = 0;
    obj->field2 = 0;
    obj->field20 = 0x51;
    func_020dde64((struct Struct_020db3f4_2*)obj);
}
