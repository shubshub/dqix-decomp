#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct {
    int unknown_0_;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    char pad[0x400];
    unsigned char unknown_42c_;
};

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

struct Struct_02109d94_3 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldC;
};
extern struct Struct_02109d94_3 data_02109d94;

extern int data_020f18ec;

// USA: func_020a147c
extern "C" ARM void func_020a147c(void* param0, void* param1, struct StreamHeader* param2, int param3, int param4, unsigned short arg5, unsigned char arg6) {
    if (param1 != 0 && param2 != 0 && param3 != 0) {
        struct ResetStruct local;
        data_02109d94.field4 = param0;
        data_02109d94.field8 = param1;
        data_02109d94.fieldC = param4;
        data_02109d94.field2 = arg5;
        data_02109d94.field0 = arg6;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f18ec);
        ((Script*)((struct StreamState*)&local))->Load(param2, param3);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
    }
}
