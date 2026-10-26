#include <globaldefs.h>

struct Struct_020db3f4_2;
extern "C" ARM void func_020dde64(struct Struct_020db3f4_2* obj);

struct Struct_020ddfb4 {
    unsigned char pad[0x18];
    int field18;
};

// USA: func_020de0c8
extern "C" ARM void func_020de0c8(struct Struct_020ddfb4* obj) {
    obj->field18 -= 0x333;
    if (obj->field18 > 0) return;
    func_020dde64((struct Struct_020db3f4_2*)obj);
}
