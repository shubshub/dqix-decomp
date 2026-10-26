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

extern "C" void* Zone3D_GetInstance(void);

struct Struct_02108fc8_2 {
    int field0;
    int field4;
    int field8;
};
extern struct Struct_02108fc8_2 data_02108fc8;
extern int data_020f1248;

// USA: func_0208dc00
extern "C" ARM int func_0208dc00(struct StreamHeader* param0, int param1, int param2) {
    data_02108fc8.field8 = param2;
    data_02108fc8.field0 = 0;
    data_02108fc8.field4 = *(int*)((char*)Zone3D_GetInstance() + 8);
    struct ResetStruct local;
    ((Script*)&local)->Initialize();
    ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1248);
    ((Script*)((struct StreamState*)&local))->Load(param0, param1);
    ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
    return data_02108fc8.field0;
}
