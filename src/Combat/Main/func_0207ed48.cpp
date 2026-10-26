#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
struct Struct_0207ed48 {
    void* unknown_0_;
    void* unknown_4_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    short field_0x10;
    unsigned char kind:4;
    unsigned char flag:4;
    unsigned char unknown_13_, unknown_14_, unknown_15_;
};
struct Struct_0207f018;
struct Struct_02108ed8 { SafeAllocator* allocator; Struct_0207f018* array; };
extern Struct_02108ed8 data_02108ed8;
extern "C" void func_0207f018(Struct_0207f018*, Struct_0207ed48*);
// USA: func_0207ed48
extern "C" ARM int func_0207ed48(Script::Parameter* params) {
    Struct_0207ed48 elem;
    elem.unknown_0_ = 0;
    elem.unknown_4_ = 0;
    elem.unknown_8_ = -1;
    elem.unknown_c_ = 0;
    elem.unknown_a_ = 0;
    elem.field_0x10 = 0;
    elem.unknown_e_ = 0;
    elem.kind = 0;
    elem.flag = 0;
    elem.unknown_13_ = 0;
    elem.unknown_14_ = 0;
    elem.unknown_15_ = 0;
    elem.unknown_8_ = params[0].ToInt();
    elem.unknown_a_ = params[1].ToInt();
    elem.unknown_c_ = params[2].ToInt();
    elem.unknown_e_ = params[3].ToInt();
    elem.field_0x10 = params[4].ToInt();
    elem.kind = params[5].ToInt();
    elem.flag = (unsigned char)params[6].ToInt() == 0;
    elem.unknown_13_ = params[7].ToInt();
    elem.unknown_14_ = params[8].ToInt();
    if (elem.unknown_13_) elem.unknown_0_ = data_02108ed8.allocator->Allocate(elem.unknown_13_ * 4);
    if (elem.unknown_14_) elem.unknown_4_ = data_02108ed8.allocator->Allocate(elem.unknown_14_ * 4);
    func_0207f018(data_02108ed8.array, &elem);
    return 1;
}
