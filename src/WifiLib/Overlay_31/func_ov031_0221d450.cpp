#include "NitroSDK/OverlayResponse.h"

struct Struct_ov031_0224e720;
extern Struct_ov031_0224e720 data_ov031_0224e720;
extern int data_ov031_0224e6e0;
extern "C" unsigned int func_ov031_0221e610(unsigned int);
extern "C" void func_ov031_0221d060(int);
extern "C" int func_ov031_0221d82c(unsigned int*, Struct_ov031_0224e720*);
extern "C" bool func_ov031_0221dc58(int);

// USA: func_ov031_0221d450
extern "C" THUMB int func_ov031_0221d450(int error, Struct_ov031_0221d3b0_2* packet, int* arg2, Struct_ov031_0221d3b0_3* arg3) {
    if (error) {
        ++*arg2;
        return error;
    }
    Struct_ov031_0221d3b0* outer = &packet->header;
    Struct_ov031_0221d450* inner = &packet->body;
    if (func_ov031_0221d7e0(&arg3->entries[0], &outer->unknown_10_) < 0) {
        ++*arg2;
        return error;
    }
    if (!func_ov031_0221e638(inner->unknown_2_)) {
        ++*arg2;
        return error;
    }
    if (inner->type == 7) {
        if (func_ov031_0221e610(inner->status) == 0xfffffffeU) {
            func_ov031_0221d060(20);
        } else if (func_ov031_0221e610(inner->status) == 0xfffffffdU) {
            func_ov031_0221d060(21);
        } else {
            func_ov031_0221d060(24);
        }
        return -1;
    }
    if (inner->type != 1) {
        ++*arg2;
        return error;
    }
    int result = func_ov031_0221d82c(&inner->status, &data_ov031_0224e720);
    if (result < 0) {
        if (result == -2) {
            func_ov031_0221d060(22);
            return -1;
        }
        ++*arg2;
        return error;
    }
    data_ov031_0224e6e0 = func_ov031_0221dc58(func_ov031_0221e638(outer->flags));
    *arg2 = 0;
    return 1;
}
