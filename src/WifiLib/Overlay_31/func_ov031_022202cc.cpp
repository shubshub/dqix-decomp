#include <globaldefs.h>

struct Struct_ov031_022202cc_2 {
    union { struct { unsigned short length; unsigned char pad2[6]; } fields; unsigned char raw[8]; } header;
    unsigned char payload[1];
};
struct Struct_ov031_022202cc {
    union { struct { unsigned short type, length, field4; } fields; unsigned char raw[6]; } header;
    unsigned char payload[1];
};
extern "C" void func_ov031_02220f0c(unsigned char*, void*, int, void*, int);
extern "C" void* memcpy(void*, const void*, unsigned int);

// USA: func_ov031_022202cc
extern "C" THUMB int func_ov031_022202cc(Struct_ov031_022202cc* destination, int type, Struct_ov031_022202cc_2* source, int length, void* transform) {
    unsigned char* end = (unsigned char*)destination;
    unsigned int var1 = 0;
    source->header.raw[0] = 0;
    unsigned short var2 = length - 8;
    source->header.raw[1] = 0;
    source->header.raw[2] = 0;
    source->header.raw[3] = 0;
    source->header.raw[4] = 0;
    source->header.raw[5] = 0;
    source->header.raw[6] = 0;
    source->header.raw[7] = 0;
    source->header.fields.length = (unsigned char)(var2 >> 8) | ((var2 << 8) & 0xff00);
    if (transform) {
        func_ov031_02220f0c(destination->payload, source, length, transform, 16);
        length += 8;
    } else memcpy(destination->payload, source, length);
    destination->header.raw[0] = 0;
    destination->header.raw[1] = 0;
    destination->header.raw[2] = 0;
    destination->header.raw[3] = 0;
    destination->header.raw[4] = 0;
    destination->header.raw[5] = 0;
    unsigned short var3 = type;
    destination->header.fields.type = (unsigned char)(var3 >> 8) | ((var3 << 8) & 0xff00);
    unsigned short var4 = length;
    destination->header.fields.length = (unsigned char)(var4 >> 8) | ((var4 << 8) & 0xff00);
    end += 6;
    end += length;
    unsigned char* cursor = (unsigned char*)destination;
    if (cursor < end) do { var1 += *cursor++; } while (cursor < end);
    unsigned short var6 = var1;
    *(unsigned short*)end = (unsigned char)(var6 >> 8) | ((var6 << 8) & 0xff00);
    return end + 2 - (unsigned char*)destination;
}
