#include "NitroSDK/OverlayMD5.h"

// USA: func_ov031_02221e84
extern "C" THUMB void func_ov031_02221e84(Struct_ov031_02221e84* context) {
    context->unknown_10_[1] = 0;
    context->unknown_10_[0] = 0;
    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
}
