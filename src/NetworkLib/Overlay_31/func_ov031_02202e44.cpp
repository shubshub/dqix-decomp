#include <globaldefs.h>
struct Struct_ov031_02202e44 {
    unsigned char header;
    unsigned char unknown_1_;
    unsigned short length;
    unsigned short unknown_4_;
    unsigned short fragment;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};
struct Struct_ov031_0224c980_4 { char unknown0[0x40]; void (*unknown_40_)(void*); char unknown44[0xc]; unsigned int address; };
extern Struct_ov031_0224c980_4 data_ov031_0224c980;
extern "C" int func_ov031_022007a4(unsigned int);
extern "C" unsigned int func_ov031_02200684(void*, unsigned int);
extern "C" void func_ov031_02200e38(void*, unsigned int, int);
extern "C" Struct_ov031_02202e44* func_ov031_02202b78(Struct_ov031_02202e44*, int*);
extern "C" void func_ov031_0220296c(Struct_ov031_02202e44*, void*, unsigned int);
extern "C" void func_ov031_02201bb4(Struct_ov031_02202e44*, void*, unsigned int);
extern "C" void func_ov031_0220284c(Struct_ov031_02202e44*, void*, unsigned int);
static inline unsigned short inline_ov031_02202e44(unsigned short value) { return (value >> 8) | (value << 8); }
#define SourceAddress02202e44(packet) (((unsigned short)((packet->unknown_c_ >> 8) | (packet->unknown_c_ << 8)) << 16) | (unsigned short)((packet->unknown_e_ >> 8) | (packet->unknown_e_ << 8)))
#define DestinationAddress02202e44(packet) (((unsigned short)((packet->unknown_10_ >> 8) | (packet->unknown_10_ << 8)) << 16) | (unsigned short)((packet->unknown_12_ >> 8) | (packet->unknown_12_ << 8)))

// USA: func_ov031_02202e44
extern "C" ARM void func_ov031_02202e44(Struct_ov031_02202e44* packet, unsigned int available) {
    unsigned int source = (inline_ov031_02202e44(packet->unknown_c_) << 16) | inline_ov031_02202e44(packet->unknown_e_);
    unsigned int destination = (inline_ov031_02202e44(packet->unknown_10_) << 16) | inline_ov031_02202e44(packet->unknown_12_);
    if (destination != source) {
        if (!func_ov031_022007a4(destination)) return;
        if (available < inline_ov031_02202e44(packet->length)) return;
        if (func_ov031_02200684(packet, (packet->header & 15) << 2) != 0xffff) return;
        if (data_ov031_0224c980.address == DestinationAddress02202e44(packet))
            func_ov031_02200e38((char*)packet - 8, SourceAddress02202e44(packet), 1);
    }
    int var2;
    packet = func_ov031_02202b78(packet, &var2);
    if (!packet) return;
    void* payload = (char*)packet + ((packet->header & 15) << 2);
    unsigned int var4 = inline_ov031_02202e44(packet->length) - ((packet->header & 15) << 2);
    if (packet->unknown_9_ == 17) func_ov031_0220296c(packet, payload, var4);
    else if (data_ov031_0224c980.address) {
        if (packet->unknown_9_ == 1) func_ov031_02201bb4(packet, payload, var4);
        else if (packet->unknown_9_ == 6) func_ov031_0220284c(packet, payload, var4);
    }
    if (var2) data_ov031_0224c980.unknown_40_((char*)packet - 14);
}
