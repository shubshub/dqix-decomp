#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0207ed1c;
struct StreamHeader;

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

struct Struct_0201f040_3;

extern void* data_02108ed8[2];
extern int data_020f0f88;

// USA: func_0207ef74
extern "C" ARM void func_0207ef74(struct Struct_0207ed1c* param0, SafeAllocator* param1, struct StreamHeader* param2, int param3) {
    if (param1 != 0 && param2 != 0 && param3 != 0) {
        struct ResetStruct local;
        data_02108ed8[1] = param0;
        data_02108ed8[0] = param1;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0f88);
        ((Script*)((struct StreamState*)&local))->Load(param2, param3);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
    }
}
