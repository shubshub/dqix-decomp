#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_02095578 {
    char pad[0xa0];
    int unknown_a0_;
};

struct Struct_02109404_5 {
    unsigned char f0;
    unsigned char pad1[2];
    unsigned char f3;
    unsigned char f4;
    unsigned char pad5[3];
    unsigned short f8;
    unsigned char pad10[2];
    unsigned int fc;
};
extern struct Struct_02109404_5 data_02109404;
extern int data_020f1444;

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

// USA: func_0209562c
extern "C" ARM void func_0209562c(struct Struct_02095578* header, int param1, struct StreamHeader* buffer, int length, unsigned short param4, int arg5, int arg6) {
    if (param1 != 0 && buffer != 0 && length != 0) {
        data_02109404.f8 = param4;
        data_02109404.f3 = arg5;
        data_02109404.f4 = arg6;
        data_02109404.fc = param1;
        header->unknown_a0_ = 0;
        data_02109404.f0 = 0;
        struct ResetStruct local;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1444);
        ((Script*)((struct StreamState*)&local))->Load(buffer, length);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
    }
}
