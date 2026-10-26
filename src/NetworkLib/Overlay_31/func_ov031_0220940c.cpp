#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220940c_3 {
    unsigned char field_0[0x32];
    unsigned short unknown_32_;
    unsigned char unknown_34_[0x1a0];
    void* unknown_1d4_;
    unsigned char unknown_1d8_[0x10c];
    unsigned char unknown_2e4_[8];
    unsigned char counter[8];
    unsigned char unknown_2f4_[0x54];
    unsigned int unknown_348_[45];
    unsigned int unknown_3fc_[22];
    unsigned char unknown_454_;
    unsigned char error;
};
struct Struct_ov031_0220940c { unsigned char type; unsigned char unknown_1_[2]; unsigned char unknown_3_; unsigned char unknown_4_; unsigned char payload[1]; };
struct Struct_ov031_0220940c_2 { unsigned char padding[0x30]; unsigned char digest[0x14]; };
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
extern "C" ARM int func_ov031_0220940c(Struct_ov031_0220940c_3* session, Struct_ov031_0220940c* packet) {
    int size = func_ov031_022093f4(session, packet->payload, (packet->unknown_3_ << 8) + packet->unknown_4_);
    Struct_ov031_0220940c_2 scratch;
    int digestSize;
    switch (session->unknown_32_) {
    case 4:
        size -= 0x10;
        packet->unknown_3_ = size >> 8;
        packet->unknown_4_ = size;
        func_ov031_0220afe0(session->unknown_3fc_);
        func_ov031_0220b028(session->unknown_3fc_, session->unknown_1d4_, 0x10);
        VectorizedMemset(scratch.padding, 0x36, 0x30);
        func_ov031_0220b028(session->unknown_3fc_, scratch.padding, 0x30);
        func_ov031_0220b028(session->unknown_3fc_, session->unknown_2e4_, 8);
        func_ov031_0220b028(session->unknown_3fc_, packet, 1);
        func_ov031_0220b028(session->unknown_3fc_, &packet->unknown_3_, size + 2);
        func_ov031_0220b0e0(session->unknown_3fc_, scratch.digest);
        func_ov031_0220afe0(session->unknown_3fc_);
        func_ov031_0220b028(session->unknown_3fc_, session->unknown_1d4_, 0x10);
        VectorizedMemset(scratch.padding, 0x5c, 0x30);
        func_ov031_0220b028(session->unknown_3fc_, scratch.padding, 0x30);
        func_ov031_0220b028(session->unknown_3fc_, scratch.digest, 0x10);
        func_ov031_0220b0e0(session->unknown_3fc_, scratch.digest);
        digestSize = 0x10;
        break;
    case 5:
        size -= 0x14;
        packet->unknown_3_ = size >> 8;
        packet->unknown_4_ = size;
        func_ov031_0220b8a0(session->unknown_348_);
        func_ov031_0220b8f4(session->unknown_348_, session->unknown_1d4_, 0x14);
        VectorizedMemset(scratch.padding, 0x36, 0x28);
        func_ov031_0220b8f4(session->unknown_348_, scratch.padding, 0x28);
        func_ov031_0220b8f4(session->unknown_348_, session->unknown_2e4_, 8);
        func_ov031_0220b8f4(session->unknown_348_, packet, 1);
        func_ov031_0220b8f4(session->unknown_348_, &packet->unknown_3_, size + 2);
        func_ov031_0220b9ac(session->unknown_348_, scratch.digest);
        func_ov031_0220b8a0(session->unknown_348_);
        func_ov031_0220b8f4(session->unknown_348_, session->unknown_1d4_, 0x14);
        VectorizedMemset(scratch.padding, 0x5c, 0x28);
        func_ov031_0220b8f4(session->unknown_348_, scratch.padding, 0x28);
        func_ov031_0220b8f4(session->unknown_348_, scratch.digest, 0x14);
        func_ov031_0220b9ac(session->unknown_348_, scratch.digest);
        digestSize = 0x14;
        break;
    }
    if (memcmp(packet->payload + size, scratch.digest, digestSize)) session->error = 9;
    func_ov031_022093d0(session->counter);
    return size + 5;
}
