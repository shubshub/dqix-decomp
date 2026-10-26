#include <globaldefs.h>
#include "NitroSDK/OverlayResponse.h"

struct Struct_ov031_0221dcbc_2 {
    signed char status;
    unsigned char reserved;
    short flags;
    short length;
    Struct_ov031_0221d7e0 address;
};
struct Struct_ov031_0221dcbc { unsigned char type; unsigned char reserved; unsigned short length; unsigned char payload[524]; };
struct Struct_ov031_0224e6e0_8 { unsigned char reserved[0x14]; unsigned char* buffer; };
extern Struct_ov031_0224e6e0_8 data_ov031_0224e6e0;
extern unsigned char data_ov031_0224f440[8];
extern char data_ov031_0224b0dc[];
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);
extern "C" void* func_ov031_0221c49c(int);
extern "C" void func_ov031_0221d060(int);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" short func_ov031_0221df48(void*);
extern "C" void func_ov031_0221c4ac(int);
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" void func_ov031_0221dfd4(int, void*, const void*, short*, short*, signed char*);
extern "C" int func_ov031_0221e354(void*, int, const char*, int);
extern "C" void func_ov031_0221e028(void*, int, int, int, signed char, signed char, const void*);
extern "C" int func_ov031_0221e080(const void*, int, int, int);

// USA: func_ov031_0221dcbc
extern "C" THUMB int func_ov031_0221dcbc(int unused, const void* input, int channel) {
    Struct_ov031_0221dcbc_2 request;
    request.status = 0;
    request.length = 0;
    request.flags = 0;
    unsigned char* buffer = data_ov031_0224e6e0.buffer;
    func_ov031_0221e52c(buffer, 0, 1500);
    Struct_ov031_0221dcbc* packet = static_cast<Struct_ov031_0221dcbc*>(func_ov031_0221c49c(528));
    if (!packet) { func_ov031_0221d060(2); return -1; }
    func_ov031_0221e52c(packet, 0, 528);
    unsigned char* payload = buffer + sizeof(Struct_ov031_0221d3b0);
    func_ov031_0221e51c(data_ov031_0224f440, input, 8);
    func_ov031_0221e51c(&request.address, data_ov031_0224f440, 8);
    request.length = func_ov031_0221df48(packet->payload);
    if (request.length < 0) {
        func_ov031_0221d060(3);
        if (packet) func_ov031_0221c4ac((int)packet);
        return -1;
    }
    packet->type = 0;
    packet->length = func_ov031_0221e5f8(request.length);
    request.length += 4;
    func_ov031_0221dfd4(0, payload, packet, &request.length, &request.flags, &request.status);
    request.flags |= 0x10;
    if (func_ov031_0221e354(&request.address, 8, data_ov031_0224b0dc, 6)) {
        func_ov031_0221d060(2);
        if (packet) func_ov031_0221c4ac((int)packet);
        return -1;
    }
    func_ov031_0221e028(buffer, 0x1000, request.length, request.flags, request.status, 0x11, &request.address);
    request.length += 24;
    func_ov031_0221e080(buffer, request.length, 255, channel);
    if (packet) func_ov031_0221c4ac((int)packet);
    return 0;
}
