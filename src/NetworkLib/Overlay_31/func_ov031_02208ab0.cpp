#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/NetworkProtocolVersion.h"

struct Struct_ov031_02208ab0 {
    unsigned char unknown0[0x30];
    unsigned char resumed;
    unsigned char unknown_31_;
    unsigned short unknown_32_;
    unsigned char unknown_34_[0x20];
    unsigned char unknown54[0x401];
    unsigned char state;
};

extern "C" int func_ov031_02208a40(const unsigned char*, int, int);

// USA: func_ov031_02208ab0
extern "C" ARM int func_ov031_02208ab0(Struct_ov031_02208ab0* context, const unsigned char* data) {
    int offset;
    int var1;
    int var2;
    int result;
    int var4;
    unsigned short var5;
    result = func_ov031_02208aa0(data[0], data[1]);
    if (!result) return result;
    var1 = (data[2] << 8) + data[3];
    var5 = func_ov031_02208a40(data + 8, var1 / 3, 3);
    if (!var5) return var5;
    context->unknown_32_ = var5;
    var4 = (data[4] << 8) + data[5];
    var2 = (data[6] << 8) + data[7];
    context->resumed = 0;
    offset = 8 + var1 + var4;
    if (var2 >= 32) {
        VectorizedInvertedMemcpy(data + offset, context->unknown_34_, 32);
    } else {
        VectorizedMemset(context->unknown_34_, 0, 32 - var2);
        VectorizedInvertedMemcpy(data + offset, context->unknown_34_ + 32 - var2, var2);
    }
    context->state = 1;
    return 1;
}
