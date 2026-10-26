#include <globaldefs.h>

struct Struct_ov031_0221e1ec {
    unsigned int first;
    unsigned int second;
    unsigned char* unknown_8_;
    unsigned int length;
};

// USA: func_ov031_0221e27c
extern "C" THUMB unsigned char func_ov031_0221e27c(Struct_ov031_0221e1ec* state) {
    unsigned int length = state->length;
    unsigned char* var1 = state->unknown_8_;
    unsigned char first = (state->first + 1) % length;
    unsigned char var3 = var1[first];
    unsigned char second = (var3 + state->second) % length;
    unsigned char var5 = var1[second];
    state->first = first;
    state->second = second;
    var1[second] = var3;
    var1[first] = var5;
    return var1[(var3 + var5) % state->length];
}
