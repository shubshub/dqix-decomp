#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_0209af58 {
    void* field0;
    int field4;
    int field8;
};
extern struct Struct_0209af58* data_02109bac;

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

extern char data_020f1680[];

// USA: func_0209af58
extern "C" ARM void func_0209af58(void* param0, struct StreamHeader* param1, int param2, int param3, int param4) {
    if (param1 != 0) {
        struct Struct_0209af58 local;
        char buf[0x430];

        data_02109bac = &local;
        data_02109bac->field0 = param0;
        data_02109bac->field4 = param4;
        data_02109bac->field8 = 0;

        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f1680);
        ((Script*)((struct StreamState*)buf))->Load(param1, param2);
        ((Script*)((struct Struct_0201f040_3*)buf))->Execute();
    }
}
