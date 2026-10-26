#include <globaldefs.h>

struct Struct_ov031_0221e1ec {
    unsigned int first;
    unsigned int second;
    unsigned char* unknown_8_;
    unsigned int length;
};

// USA: func_ov031_0221e1ec
extern "C" THUMB void func_ov031_0221e1ec(Struct_ov031_0221e1ec* state, const unsigned char* key, unsigned int arg2, unsigned int length) {
    unsigned char* var0 = state->unknown_8_;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    state->first = state->second = 0;
    state->length = length;
    for (i = 0; i < length; i++) {
        var0[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < length; i++) {
        unsigned char value = var0[i];
        unsigned char t;
        j = (j + key[k] + value) % state->length;
        t = var0[j];
        var0[j] = value;
        var0[i] = t;
        k++;
        if (k >= arg2) {
            k = 0;
        }
    }
}
