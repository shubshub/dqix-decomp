#include <globaldefs.h>
#include <NitroSDK/Memory.h>

struct Struct_ov031_02235cdc {
    unsigned char field_0[0x480];
    unsigned char key[16];
    unsigned char unknown_490_[0x56];
    unsigned char unknown_4e6_0_ : 2;
    unsigned char unknown_4e6_2_ : 6;
};
extern Struct_ov031_02235cdc* data_ov031_02290cfc;
extern "C" int func_ov031_0223dd34(unsigned char*, int);
extern "C" unsigned int func_ov031_02236760(unsigned int);

// USA: func_ov031_02235cdc
extern "C" ARM void func_ov031_02235cdc(unsigned char* text) {
    int i;
    VectorizedMemset(data_ov031_02290cfc->key, 0, 16);
    int length = func_ov031_0223dd34(text, 32);
    switch (length) {
    case 0:
    case 10:
    case 26:
    case 32: {
        data_ov031_02290cfc->unknown_4e6_2_ = 0;
        unsigned char* output = data_ov031_02290cfc->key;
        i = 0;
        if (i < length) do {
            unsigned char* pair = text + i;
            unsigned int high = func_ov031_02236760(text[i]);
            unsigned int low = func_ov031_02236760(pair[1]);
            *output++ = (high << 4) + low;
            i += 2;
        } while (i < length);
        break;
    }
    default:
        data_ov031_02290cfc->unknown_4e6_2_ = 1;
        VectorizedInvertedMemcpy(text, data_ov031_02290cfc->key, 16);
        break;
    }
    switch (length) {
    case 0:
        data_ov031_02290cfc->unknown_4e6_0_ = 0;
        break;
    case 5:
    case 10:
        data_ov031_02290cfc->unknown_4e6_0_ = 1;
        break;
    case 13:
    case 26:
        data_ov031_02290cfc->unknown_4e6_0_ = 2;
        break;
    default:
        data_ov031_02290cfc->unknown_4e6_0_ = 3;
        break;
    }
}
