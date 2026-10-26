#include <globaldefs.h>
#include "Resource/Script.h"

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

struct Struct_02108d98_2 {
    unsigned short h0;
    char pad0[2];
    int field4;
    int field8;
    int fieldC;
};
extern struct Struct_02108d98_2 data_02108d98;

extern int data_020f0c78;

// USA: func_02071c00
extern "C" ARM int func_02071c00(int arg0, int arg1, struct StreamHeader* header, int length) {
    struct ResetStruct local;

    data_02108d98.fieldC = arg0;
    data_02108d98.field8 = arg1;
    data_02108d98.field4 = 0;
    data_02108d98.h0 = 0;

    ((Script*)&local)->Initialize();
    ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0c78);
    ((Script*)&local)->Load(header, length);
    ((Script*)&local)->Execute();
}
