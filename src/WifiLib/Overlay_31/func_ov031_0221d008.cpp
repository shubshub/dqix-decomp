#include <globaldefs.h>

struct Struct_ov017_021d1118 {
    unsigned short flags;
    unsigned char kind;
    unsigned char reserved;
    unsigned short length;
    unsigned char payload[1];
};
struct Struct_ov031_0224e6e0_5 {
    unsigned char pad0[0x10];
    int active;
    unsigned char unknown_14_[0x10];
    unsigned char* payload;
    int length;
    unsigned int mode;
    int offset;
    unsigned int address;
};
struct Struct_ov031_0224e700_2 {
    unsigned char pad0[0x1c];
    unsigned char unknown_1c_;
    unsigned char kind;
};
extern unsigned char data_ov031_0224f440[8];
extern Struct_ov031_0224e6e0_5 data_ov031_0224e6e0;
extern unsigned char data_ov031_0224e704[0x1c];
extern Struct_ov031_0224e700_2 data_ov031_0224e700;
extern "C" void func_ov031_0221e52c(void*, int, unsigned int);

// USA: func_ov031_0221d008
extern "C" THUMB void func_ov031_0221d008(Struct_ov017_021d1118* packet) {
    func_ov031_0221e52c(data_ov031_0224f440, 0, 8);
    data_ov031_0224e6e0.active = 1;
    func_ov031_0221e52c(data_ov031_0224e704, 0, 0x1c);
    data_ov031_0224e6e0.payload = packet->payload;
    data_ov031_0224e6e0.length = packet->length;
    data_ov031_0224e6e0.mode = packet->flags & 0xf;
    data_ov031_0224e700.kind = packet->kind;
    data_ov031_0224e6e0.offset = 0;
    data_ov031_0224e6e0.address = 0xc0a80b01;
    data_ov031_0224e700.unknown_1c_ = 0;
}
