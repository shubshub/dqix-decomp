#include <globaldefs.h>
#include "NitroSDK/OverlayResponse.h"

struct Struct_ov031_0221de00_2 {
    signed char status;
    unsigned char reserved;
    short flags;
    short length;
};
struct Struct_ov031_0221de00 {
    unsigned char type;
    unsigned char reserved;
    unsigned short unknown_2_;
    unsigned int address;
};
struct Struct_ov031_0224e6e0_9 {
    int mode;
    unsigned char pad4[0x10];
    unsigned char* buffer;
    unsigned char pad18[0x14];
    unsigned int address;
};
extern Struct_ov031_0224e6e0_9 data_ov031_0224e6e0;
extern char data_ov031_0224b0dc[];
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" void func_ov031_0221d060(int);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" unsigned int func_ov031_0221e5d0(unsigned int);
extern "C" void func_ov031_0221dfd4(int, void*, const void*, short*, short*, signed char*);
extern "C" int func_ov031_0221e354(void*, int, const char*, int);
extern "C" void func_ov031_0221e028(void*, int, int, int, signed char, signed char, const void*);
extern "C" int func_ov031_0221e080(const void*, int, int, int);

// USA: func_ov031_0221de00
extern "C" THUMB int func_ov031_0221de00(int unused, const void* input, int channel) {
    Struct_ov031_0221d7e0 address;
    Struct_ov031_0221de00 header;
    Struct_ov031_0221de00_2 request;
    request.status = 0;
    request.length = 0;
    request.flags = 0;
    unsigned char* buffer = data_ov031_0224e6e0.buffer;
    func_ov031_0221e52c(&header, 0, 8);
    func_ov031_0221e52c(buffer, 0, 1500);
    header.type = 2;
    header.reserved = 0;
    header.unknown_2_ = func_ov031_0221e5f8(4);
    header.address = data_ov031_0224e6e0.address;
    header.address = func_ov031_0221e5d0(header.address);
    request.length = 8;
    func_ov031_0221dfd4(data_ov031_0224e6e0.mode, buffer + sizeof(Struct_ov031_0221d3b0), &header, &request.length, &request.flags, &request.status);
    func_ov031_0221e51c(&address, (const char*)input + 8, 8);
    if (func_ov031_0221e354(&address, 8, data_ov031_0224b0dc, 6)) {
        func_ov031_0221d060(2);
        return -1;
    }
    func_ov031_0221e028(buffer, 0x2000, request.length, request.flags, request.status, 0x11, &address);
    request.length += 24;
    func_ov031_0221e080(buffer, request.length, 0, channel);
    return 0;
}
