#include <globaldefs.h>

struct Struct_ov031_0220fb28_3 {
    int size;
    unsigned int magic;
    int kind;
    int unknown_c_;
    int value;
};

struct Struct_ov031_0220fb28 {
    int field_0;
    int unknown_4_;
    int value;
};

struct Struct_ov031_0220fb28_2 {
    unsigned char field_0[0x24];
    Struct_ov031_0220fb28* config;
    unsigned char field_28[8];
    int value;
};

extern Struct_ov031_0220fb28_2* data_ov031_0224e580;
extern "C" void func_ov031_0220fd78(int, Struct_ov031_0220fb28_3*);
extern "C" int func_ov031_0220ff34(int*);
extern "C" int func_ov031_0220fe44(int);
extern "C" int func_ov031_0220ff18(void*);
extern "C" void func_ov031_0220fea0();
extern "C" void func_ov031_0220fed8();

// USA: func_ov031_0220fb28
extern "C" ARM void func_ov031_0220fb28() {
    unsigned char message[0x414];
    Struct_ov031_0220fb28_3* buffer = (Struct_ov031_0220fb28_3*)message;
    func_ov031_0220fd78(data_ov031_0224e580->config->value, buffer);
    buffer->size = 0x14;
    buffer->magic = 0x44535359;
    buffer->kind = 0xd0;
    buffer->unknown_c_ = data_ov031_0224e580->config->unknown_4_;
    if ((buffer->value = data_ov031_0224e580->value) == 0) return;
    if (func_ov031_0220fe44((int)func_ov031_0220ff34)) {
        if (func_ov031_0220ff18(buffer)) func_ov031_0220fea0();
    }
    func_ov031_0220fed8();
}
