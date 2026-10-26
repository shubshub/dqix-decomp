#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020bcde0;
extern "C" void func_020bcde0(struct Struct_020bcde0*);
struct Struct_020bce2c;
extern "C" void func_020bce2c(struct Struct_020bce2c*);

extern int data_0210fca4;
extern SignedAllocatorList data_0210fca8;

struct Struct_020bc8d0 {
    char pad0[0x8];
    void (*field8)(struct Struct_020bcde0*);
    void* fieldc;
    char pad10[0x14 - 0x10];
    void (*field14)(struct Struct_020bce2c*);
    void* field18;
    char unknown_1c_[0x24 - 0x1c];
    int field24;
    char pad28[0x44 - 0x28];
    int field44;
    int field48;
};

// USA: func_020bc8d0
extern "C" ARM void func_020bc8d0(struct Struct_020bc8d0* obj) {
    if (!data_0210fca4) {
        data_0210fca8.Initialize(0);
        data_0210fca4 = 1;
    }
    obj->field8 = func_020bcde0;
    obj->fieldc = obj;
    obj->field14 = func_020bce2c;
    obj->field18 = obj;
    obj->field44 = 0;
    obj->field48 = 0;
    obj->field24 &= ~0x1;
    obj->field24 &= ~0x2;
}
