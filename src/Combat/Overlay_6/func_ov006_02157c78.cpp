#include <globaldefs.h>
#include "std_library_functions.h"

struct StructDE1D4;
extern "C" void ItemRecord_Clear(struct StructDE1D4* p);

struct Struct_ov006_02157a60_2 {
    void* unknown_0_;
    void* unknown_4_;
    char pad8[0x20 - 0x8];
    char field20[0x20];
    char field40[0x30];
    char unknown_70_[0x70 - 0x70];
    short unknown1_70_;
};

// USA: func_ov006_02157c78
extern "C" ARM void func_ov006_02157c78(struct Struct_ov006_02157a60_2* obj) {
    ItemRecord_Clear((struct StructDE1D4*)obj);
    memset(obj->field20, 0, 0x20);
    memset(obj->field40, 0, 0x30);
    obj->unknown_0_ = obj->field20;
    obj->unknown_4_ = obj->field40;
    obj->unknown1_70_ = -1;
}
