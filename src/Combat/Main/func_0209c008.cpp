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

struct StreamHeader;
struct StreamState;

struct Struct_0201f040_3;

extern int data_020f16f8;

struct Struct_0209c008 {
    void* field0;
    unsigned short field4;
    unsigned short field6;
    int field8;
};
extern struct Struct_0209c008* data_02109bc8;

// USA: func_0209c008
extern "C" ARM void func_0209c008(void* obj, struct StreamHeader* buffer, int length, int arg3, int arg4, int arg5) {
    struct Struct_0209c008 local;
    local.field0 = obj;
    local.field4 = arg4 * 100 + arg5;
    local.field6 = arg3;
    local.field8 = 1;
    data_02109bc8 = &local;

    struct ResetStruct var1;
    ((Script*)&var1)->Initialize();
    ((Script*)&var1)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f16f8);
    ((Script*)((struct StreamState*)&var1))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)&var1))->Execute();
}
