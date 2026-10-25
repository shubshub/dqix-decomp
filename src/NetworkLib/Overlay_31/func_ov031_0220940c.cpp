#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220940c_3 {
    unsigned char unknown_0_[0x32];
    unsigned short unknown_32_;
    unsigned char unknown_34_[0x1a0];
    void* unknown_1d4_;
    unsigned char unknown_1d8_[0x10c];
    unsigned char unknown_2e4_[8];
    unsigned char unknown_2ec_[8];
    unsigned char unknown_2f4_[0x54];
    unsigned int unknown_348_[45];
    unsigned int unknown_3fc_[22];
    unsigned char unknown_454_;
    unsigned char unknown_455_;
};
struct Struct_ov031_0220940c { unsigned char unknown_0_; unsigned char unknown_1_[2]; unsigned char unknown_3_; unsigned char unknown_4_; unsigned char unknown_5_[1]; };
struct Struct_ov031_0220940c_2 { unsigned char unknown_0_[0x30]; unsigned char unknown_30_[0x14]; };
extern "C" int func_ov031_022093f4(void*, void*, int);
extern "C" void func_ov031_0220afe0(void*);
extern "C" void func_ov031_0220b0e0(void*, void*);
extern "C" void func_ov031_0220b8a0(unsigned int*);
extern "C" void func_ov031_0220b9ac(void*, void*);
extern "C" void func_ov031_022093d0(unsigned char*);
extern "C" void func_ov031_0220b028(void*, const void*, unsigned int);
extern "C" void func_ov031_0220b8f4(void*, const void*, unsigned int);
extern "C" int memcmp(const void*, const void*, unsigned int);

// USA: func_ov031_0220940c
extern "C" ARM int func_ov031_0220940c(Struct_ov031_0220940c_3* arg0, Struct_ov031_0220940c* arg1) {
    int var0 = func_ov031_022093f4(arg0, arg1->unknown_5_, (arg1->unknown_3_ << 8) + arg1->unknown_4_);
    Struct_ov031_0220940c_2 var1;
    int var2;
    switch (arg0->unknown_32_) {
    case 4:
        var0 -= 0x10;
        arg1->unknown_3_ = var0 >> 8;
        arg1->unknown_4_ = var0;
        func_ov031_0220afe0(arg0->unknown_3fc_);
        func_ov031_0220b028(arg0->unknown_3fc_, arg0->unknown_1d4_, 0x10);
        VectorizedMemset(var1.unknown_0_, 0x36, 0x30);
        func_ov031_0220b028(arg0->unknown_3fc_, var1.unknown_0_, 0x30);
        func_ov031_0220b028(arg0->unknown_3fc_, arg0->unknown_2e4_, 8);
        func_ov031_0220b028(arg0->unknown_3fc_, arg1, 1);
        func_ov031_0220b028(arg0->unknown_3fc_, &arg1->unknown_3_, var0 + 2);
        func_ov031_0220b0e0(arg0->unknown_3fc_, var1.unknown_30_);
        func_ov031_0220afe0(arg0->unknown_3fc_);
        func_ov031_0220b028(arg0->unknown_3fc_, arg0->unknown_1d4_, 0x10);
        VectorizedMemset(var1.unknown_0_, 0x5c, 0x30);
        func_ov031_0220b028(arg0->unknown_3fc_, var1.unknown_0_, 0x30);
        func_ov031_0220b028(arg0->unknown_3fc_, var1.unknown_30_, 0x10);
        func_ov031_0220b0e0(arg0->unknown_3fc_, var1.unknown_30_);
        var2 = 0x10;
        break;
    case 5:
        var0 -= 0x14;
        arg1->unknown_3_ = var0 >> 8;
        arg1->unknown_4_ = var0;
        func_ov031_0220b8a0(arg0->unknown_348_);
        func_ov031_0220b8f4(arg0->unknown_348_, arg0->unknown_1d4_, 0x14);
        VectorizedMemset(var1.unknown_0_, 0x36, 0x28);
        func_ov031_0220b8f4(arg0->unknown_348_, var1.unknown_0_, 0x28);
        func_ov031_0220b8f4(arg0->unknown_348_, arg0->unknown_2e4_, 8);
        func_ov031_0220b8f4(arg0->unknown_348_, arg1, 1);
        func_ov031_0220b8f4(arg0->unknown_348_, &arg1->unknown_3_, var0 + 2);
        func_ov031_0220b9ac(arg0->unknown_348_, var1.unknown_30_);
        func_ov031_0220b8a0(arg0->unknown_348_);
        func_ov031_0220b8f4(arg0->unknown_348_, arg0->unknown_1d4_, 0x14);
        VectorizedMemset(var1.unknown_0_, 0x5c, 0x28);
        func_ov031_0220b8f4(arg0->unknown_348_, var1.unknown_0_, 0x28);
        func_ov031_0220b8f4(arg0->unknown_348_, var1.unknown_30_, 0x14);
        func_ov031_0220b9ac(arg0->unknown_348_, var1.unknown_30_);
        var2 = 0x14;
        break;
    }
    if (memcmp(packet->payload + size, scratch.digest, digestSize)) session->error = 9;
    IncrementByteCounter_022093d0(session->counter);
    return size + 5;
}
