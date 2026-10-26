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

extern int data_020f0cc8;

struct Struct_02108db0_4 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldc;
    void* field10;
};
extern struct Struct_02108db0_4 data_02108db0;

// USA: func_02072928
extern "C" ARM void func_02072928(void* param0, struct StreamHeader* param1, int param2, int param3, void* arg4, unsigned char arg5) {
    data_02108db0.field10 = param0;
    data_02108db0.fieldc = 0;
    data_02108db0.field8 = &param3;
    data_02108db0.field2 = 1;
    data_02108db0.field4 = arg4;
    data_02108db0.field0 = arg5;

    struct ResetStruct local;
    ((Script*)&local)->Initialize();
    ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0cc8);
    ((Script*)((struct StreamState*)&local))->Load(param1, param2);
    ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
}
