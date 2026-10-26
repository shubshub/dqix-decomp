#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_0207f158 {
    int unknown_0_;
    short id;
    short field06;
    short unknown_8_;
    short unknown_a_;
    short field0c;
    short unknown_e_;
    short field10;
    unsigned char type;
    unsigned char lower : 4;
    unsigned char upper : 4;
    unsigned char mode : 2;
    unsigned char count : 6;
    unsigned char unknown_15_[3];
    short field18;
    short unknown_1a_;
    short field1c;
    short unknown_1e_;
    short field20;
    short unknown_22_;
    short field24;
    short unknown_26_;
    short field28;
    unsigned char field2a;
    unsigned char unknown_2b_;
    unsigned char field2c;
    unsigned char unknown_2d_;
};
struct Struct_0207f158_2;
extern "C" void func_0207f5d0(Struct_0207f158_2*, Struct_0207f158*);
extern void* data_02108ee0[2];

// USA: func_0207f158
extern "C" ARM int func_0207f158(Script::Parameter* parameters) {
    Struct_0207f158 element;
    element.unknown_0_ = 0;
    element.id = -1;
    element.unknown_8_ = 0;
    element.field06 = 0;
    element.field0c = 0;
    element.unknown_a_ = 0;
    element.unknown_e_ = -1;
    element.field10 = -1;
    element.type = 0;
    element.lower = 10;
    element.upper = 0;
    element.mode = 0;
    element.count = 3;
    element.field18 = -1;
    element.field1c = -1;
    element.field20 = -1;
    element.field24 = -1;
    element.field28 = 0;
    element.field2a = 0;
#if !defined(jpn)
    element.unknown_2b_ = 0;
    element.field2c = 0;
#endif
    element.id = parameters[0].ToInt();
    element.field06 = parameters[1].ToInt();
    element.unknown_8_ = parameters[2].ToInt();
    element.type = parameters[3].ToInt();
    switch (element.type) {
    case 0:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.unknown_e_ = parameters[6].ToInt();
        break;
    case 1:
        element.unknown_a_ = parameters[4].ToInt();
        element.field0c = parameters[5].ToInt();
        element.upper = parameters[6].ToInt();
        break;
    case 2:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.unknown_e_ = parameters[6].ToInt();
        element.field10 = parameters[7].ToInt();
        break;
    case 3:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.unknown_e_ = parameters[6].ToInt();
        element.mode = parameters[7].ToInt();
        element.count = parameters[8].ToInt();
        element.field10 = parameters[9].ToInt();
        break;
    case 4:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        break;
    case 5:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.mode = parameters[6].ToInt();
        element.count = parameters[7].ToInt();
        element.field10 = parameters[8].ToInt();
        break;
    }
    func_0207f5d0((Struct_0207f158_2*)data_02108ee0[1], &element);
    return 1;
}
