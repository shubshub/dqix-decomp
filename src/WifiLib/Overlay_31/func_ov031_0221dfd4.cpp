#include <globaldefs.h>

struct Struct_ov031_0221dfd4 {
    unsigned short length;
    unsigned short token;
    unsigned char data[1];
};
extern const unsigned char data_ov031_0224f440[8];
extern "C" int func_ov031_0221e0e8(const void*, void*, int, unsigned char*, unsigned short*, const void*, int);
extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221dfd4
extern "C" THUMB void func_ov031_0221dfd4(int mode, Struct_ov031_0221dfd4* packet, const void* source, short* length, unsigned short* header, unsigned char* status)
{
    if (mode == 1) {
        *header = 1;
        func_ov031_0221e0e8(source, packet->data, *length, status, &packet->token, data_ov031_0224f440, 8);
        packet->length = func_ov031_0221e5f8(*length);
        *length += 4;
    } else {
        func_ov031_0221e51c(packet, source, *length);
    }
}
