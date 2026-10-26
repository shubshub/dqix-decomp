#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220963c_2 {
    unsigned char unknown_0_[0x32];
    unsigned short unknown_32_;
    unsigned char unknown_34_[0x88];
    unsigned char* unknown_bc_;
    unsigned char unknown_c0_[8];
    unsigned char unknown_c8_[0x104];
    unsigned char unknown_1cc_[8];
    unsigned char counter[8];
    unsigned char unknown_1dc_[0x16c];
    unsigned int unknown_348_[23];
    unsigned char unknown_3a4_[0x58];
    unsigned int unknown_3fc_[22];
};

struct Struct_ov031_0220963c {
    unsigned char type;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char payload[1];
};

extern "C" void func_ov031_0220afe0(void*);
extern "C" void func_ov031_0220b0e0(void*, void*);
extern "C" void func_ov031_0220b8a0(unsigned int*);
extern "C" void func_ov031_0220b9ac(void*, void*);
extern "C" void func_ov031_022093d0(unsigned char*);
extern "C" void func_ov031_0220b028(void*, const void*, unsigned int);
extern "C" void func_ov031_0220b8f4(void*, const void*, unsigned int);
extern "C" void func_ov031_0220bab8(void*, void*, unsigned int);

// USA: func_ov031_0220963c
extern "C" ARM int func_ov031_0220963c(Struct_ov031_0220963c_2* context, Struct_ov031_0220963c* record) {
    unsigned char pad[0x30];
    unsigned char* payload = record->payload;
    int length = (record->unknown_3_ << 8) + record->unknown_4_;
    switch (context->unknown_32_) {
    case 4:
        func_ov031_0220afe0(context->unknown_3fc_);
        func_ov031_0220b028(context->unknown_3fc_, context->unknown_bc_, 16);
        VectorizedMemset(pad, 0x36, 0x30);
        func_ov031_0220b028(context->unknown_3fc_, pad, 0x30);
        func_ov031_0220b028(context->unknown_3fc_, context->unknown_1cc_, 8);
        func_ov031_0220b028(context->unknown_3fc_, record, 1);
        func_ov031_0220b028(context->unknown_3fc_, &record->unknown_3_, length + 2);
        func_ov031_0220b0e0(context->unknown_3fc_, payload + length);
        func_ov031_0220afe0(context->unknown_3fc_);
        func_ov031_0220b028(context->unknown_3fc_, context->unknown_bc_, 16);
        VectorizedMemset(pad, 0x5c, 0x30);
        func_ov031_0220b028(context->unknown_3fc_, pad, 0x30);
        func_ov031_0220b028(context->unknown_3fc_, payload + length, 16);
        func_ov031_0220b0e0(context->unknown_3fc_, payload + length);
        length += 16;
        break;
    case 5:
        func_ov031_0220b8a0(context->unknown_348_);
        func_ov031_0220b8f4(context->unknown_348_, context->unknown_bc_, 20);
        VectorizedMemset(pad, 0x36, 0x28);
        func_ov031_0220b8f4(context->unknown_348_, pad, 0x28);
        func_ov031_0220b8f4(context->unknown_348_, context->unknown_1cc_, 8);
        func_ov031_0220b8f4(context->unknown_348_, record, 1);
        func_ov031_0220b8f4(context->unknown_348_, &record->unknown_3_, length + 2);
        func_ov031_0220b9ac(context->unknown_348_, payload + length);
        func_ov031_0220b8a0(context->unknown_348_);
        func_ov031_0220b8f4(context->unknown_348_, context->unknown_bc_, 20);
        VectorizedMemset(pad, 0x5c, 0x28);
        func_ov031_0220b8f4(context->unknown_348_, pad, 0x28);
        func_ov031_0220b8f4(context->unknown_348_, payload + length, 20);
        func_ov031_0220b9ac(context->unknown_348_, payload + length);
        length += 20;
        break;
    }
    record->unknown_3_ = length >> 8;
    record->unknown_4_ = length;
    func_ov031_0220bab8(context->unknown_c8_, record->payload, length);
    func_ov031_022093d0(context->counter);
    return length + 5;
}
