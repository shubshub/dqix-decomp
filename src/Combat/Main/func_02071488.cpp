#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader {
    int field0;
    int size;
};

struct Struct_0201f040_3;

extern int data_020f0b80;

struct Struct_02108d70_4 {
    short h0;
    unsigned short h2;
    short h4;
    unsigned short h6;
    char pad8[0xc - 0x8];
    int unknown_c_;
    char pad10[0x18 - 0x10];
    int unknown_18_;
    char unknown_1c_[0x20 - 0x1c];
    int unknown_20_;
};
extern struct Struct_02108d70_4 data_02108d70;

struct Struct_02071488 {
    char pad0[7];
    unsigned char unknown_7_;
    unsigned char f8;
    char unknown_9_[0x46 - 0x9];
    short f46;
};

// USA: func_02071488
extern "C" ARM int func_02071488(struct StreamHeader* buffer, int length, int arg2, struct Struct_02071488* obj) {
    char local[0x430];

    data_02108d70.unknown_20_ = (int)obj;
    data_02108d70.unknown_18_ = arg2;
    data_02108d70.unknown_c_ = 0;
    data_02108d70.h4 = 0;

    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0b80);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();

    obj->unknown_7_ = 0;
    obj->f8 = 0;
    if (arg2 >= 0x5208 && arg2 < 0x9c40) {
        obj->unknown_7_ = 1;
        if (obj->f46 >= 0) {
            obj->f46 = obj->f46 + data_02108d70.h2;
        }
    } else if (arg2 >= 0x9c40) {
        obj->f8 = 1;
        if (obj->f46 >= 0) {
            obj->f46 = obj->f46 + data_02108d70.h6;
        }
    }

    return data_02108d70.unknown_c_;
}
