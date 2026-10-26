#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_02203fdc_2 {
    unsigned short high;
    unsigned short low;
};
struct Struct_ov031_02203fdc {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    Struct_ov031_02203fdc_2 unknown_4_;
    unsigned short seconds;
    unsigned short flags;
    Struct_ov031_02203fdc_2 unknown_c_;
    Struct_ov031_02203fdc_2 unknown_10_;
    Struct_ov031_02203fdc_2 unknown_14_;
    Struct_ov031_02203fdc_2 unknown_18_;
    unsigned char unknown_1c_[16];
    char unknown_2c_[64];
    char unknown_6c_[128];
};
struct Struct_ov031_0224c980_2 {
    unsigned char unknown0[0x50];
    unsigned int unknown_50_;
    unsigned char unknown54[0x14];
    unsigned long long unknown_68_;
    unsigned long long unknown_70_;
    unsigned long long unknown_78_;
};
extern Struct_ov031_0224c980_2 data_ov031_0224c980;
extern unsigned char data_ov031_0224ce68[];
extern const char data_ov031_02249698[];

enum Enum_ov031_02203fdc {
    Enum_ov031_02203fdc_12 = 12,
    Enum_ov031_02203fdc_53 = 53,
    Enum_ov031_02203fdc_55 = 55,
    Enum_ov031_02203fdc_61 = 61
};

// USA: func_ov031_02203fdc
extern "C" ARM unsigned char* func_ov031_02203fdc(void* buffer, int arg1, int* output) {
    unsigned char* bytes = (unsigned char*)buffer;
    Struct_ov031_02203fdc* header = (Struct_ov031_02203fdc*)buffer;
    VectorizedMemset(buffer, 0, sizeof(Struct_ov031_02203fdc));
    header->unknown_0_ = 0x101;
    header->unknown_2_ = 6;
    data_ov031_0224c980.unknown_68_ = data_ov031_0224c980.unknown_70_ * data_ov031_0224c980.unknown_68_ + data_ov031_0224c980.unknown_78_;
    unsigned int var2 = data_ov031_0224c980.unknown_68_ / 0x100000000ULL;
    if (output) *output = var2;
    int var3 = (unsigned short)(var2 / 0x10000U);
    header->unknown_4_.high = (var3 >> 8) | (var3 << 8);
    int var4 = (unsigned short)var2;
    header->unknown_4_.low = (var4 >> 8) | (var4 << 8);
    int var5 = (unsigned short)(data_ov031_0224c980.unknown_50_ / 0x10000U);
    header->unknown_c_.high = (var5 >> 8) | (var5 << 8);
    int var6 = (unsigned short)data_ov031_0224c980.unknown_50_;
    header->unknown_c_.low = (var6 >> 8) | (var6 << 8);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, header->unknown_1c_, 6);
    ((unsigned short*)(bytes + sizeof(Struct_ov031_02203fdc)))[0] = 0x8263;
    ((unsigned short*)(bytes + sizeof(Struct_ov031_02203fdc)))[1] = 0x6353;
    ((unsigned short*)(bytes + sizeof(Struct_ov031_02203fdc)))[2] = Enum_ov031_02203fdc_53 | (1 << 8);
    bytes[0xf2] = arg1;
    bytes[0xf3] = Enum_ov031_02203fdc_61;
    bytes[0xf4] = 7;
    bytes[0xf5] = 1;
    VectorizedInvertedMemcpy(data_ov031_0224ce68, bytes + 0xf6, 6);
    bytes[0xfc] = Enum_ov031_02203fdc_12;
    bytes[0xfd] = 10;
    VectorizedInvertedMemcpy(data_ov031_02249698, bytes + 0xfe, 10);
    bytes[0x108] = Enum_ov031_02203fdc_55;
    bytes[0x109] = 3;
    bytes[0x10a] = 1;
    bytes[0x10b] = 3;
    bytes[0x10c] = 6;
    return bytes + 0x10d;
}
