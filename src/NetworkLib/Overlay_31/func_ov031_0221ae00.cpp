#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0221ae00 {
    unsigned long long first;
    unsigned long long second;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};
extern unsigned char data_ov031_0224e6ac[];
extern unsigned char data_ov031_0224e6b1[];
extern unsigned char data_ov031_0224e6b6[];
extern unsigned char data_ov031_0224e6b8[];

// USA: func_ov031_0221ae00
extern "C" ARM void func_ov031_0221ae00(Struct_ov031_0221ae00* settings) {
    VectorizedInvertedMemcpy(data_ov031_0224e6ac, &settings->first, 6);
    settings->first &= 0x7ffffffffffULL;
    VectorizedInvertedMemcpy(data_ov031_0224e6b1, &settings->second, 6);
    settings->second >>= 3;
    settings->second &= 0x7ffffffffffULL;
    VectorizedInvertedMemcpy(data_ov031_0224e6b6, &settings->unknown_10_, 2);
    settings->unknown_10_ >>= 6;
    settings->unknown_10_ &= 0x3ff;
    VectorizedInvertedMemcpy(data_ov031_0224e6b8, &settings->unknown_12_, 2);
}
