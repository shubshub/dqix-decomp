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

struct Struct_0209bc98 {
    void* field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};

struct Struct_02109bb0 {
    struct Struct_0209bc98* current;
};
extern struct Struct_02109bb0 data_02109bb0;
extern int data_020f16c0;

// USA: func_0209bc98
extern "C" ARM void func_0209bc98(void* param0, struct StreamHeader* param1, int param2, int param3, int arg4, int arg5, int arg6) {
    if (param1 != 0) {
        struct Struct_0209bc98 local;
        data_02109bb0.current = &local;
        data_02109bb0.current->field0 = param0;
        data_02109bb0.current->field4 = arg4;
        data_02109bb0.current->field8 = arg5;
        data_02109bb0.current->fieldc = arg6;
        data_02109bb0.current->field10 = 1;
        data_02109bb0.current->field14 = 0;

        struct ResetStruct var1;
        ((Script*)&var1)->Initialize();
        ((Script*)&var1)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f16c0);
        ((Script*)((struct StreamState*)&var1))->Load(param1, param2);
        ((Script*)((struct Struct_0201f040_3*)&var1))->Execute();
    }
}
