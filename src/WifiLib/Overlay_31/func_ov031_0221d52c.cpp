#include "NitroSDK/OverlayResponse.h"

extern unsigned char data_ov031_0224eda0[];
struct Struct_ov031_0224e720;
extern Struct_ov031_0224e720 data_ov031_0224e720;
extern unsigned char data_ov031_0224e6e0[];
extern "C" unsigned int func_ov031_0221e610(unsigned int value);
extern "C" void func_ov031_0221d060(int error);
extern "C" void func_ov031_0221e52c(void* destination, int value, unsigned int size);
extern "C" int func_ov031_0221db48(int index, Struct_ov031_0221d450* body, int arg2, void* data, void* output);

// USA: func_ov031_0221d52c
// KEEP-NAME
extern "C" THUMB int func_ov031_0221d52c(int state, Struct_ov031_0221d3b0_2* message, int* arg2, Struct_ov031_0221d3b0_3* arg3) {
    if (state != 1) {
        ++*arg2;
        return state;
    }
    Struct_ov031_0221d3b0* header = &message->header;
    Struct_ov031_0221d450* body = &message->body;
    if (func_ov031_0221d7e0(&arg3->entries[1], &header->unknown_10_) < 0) {
        ++*arg2;
        return state;
    }
    if (!func_ov031_0221e638(body->unknown_2_)) {
        ++*arg2;
        return state;
    }
    if (body->type == 7) {
        if (func_ov031_0221e610(body->status) == (unsigned int)-2)
            func_ov031_0221d060(20);
        else if (func_ov031_0221e610(body->status) == (unsigned int)-3)
            func_ov031_0221d060(21);
        else
            func_ov031_0221d060(24);
        return -1;
    }
    func_ov031_0221e52c(data_ov031_0224eda0, 0, 0x6a0);
    if (func_ov031_0221db48(0, body, func_ov031_0221e638(header->unknown_a_),
            data_ov031_0224eda0, &data_ov031_0224e720) < 0) {
        ++*arg2;
        return state;
    }
    if (!(*(unsigned int*)(data_ov031_0224e6e0 + 0x30) & *(unsigned int*)(data_ov031_0224e6e0 + 0x2c)))
        return state;
    *arg2 = 0;
    return 2;
}
