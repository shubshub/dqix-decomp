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

struct Struct_0207f524;
extern "C" void func_0207f72c(struct Struct_0207f524* p);

struct Struct_02108ee0 { void* field0; void* field4; };
extern struct Struct_02108ee0 data_02108ee0;
extern int data_020f0fb0;

// USA: func_0207f524
extern "C" ARM void func_0207f524(void* param0, void* param1, struct StreamHeader* param2, int param3) {
    if (param1 != 0 && param2 != 0 && param3 != 0) {
        struct ResetStruct local;
        data_02108ee0.field0 = param1;
        data_02108ee0.field4 = param0;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0fb0);
        ((Script*)((struct StreamState*)&local))->Load(param2, param3);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
        func_0207f72c((struct Struct_0207f524*)param0);
    }
}
