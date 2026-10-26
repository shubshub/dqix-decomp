#include "NitroSDK/OverlayResponse.h"

extern "C" unsigned int func_ov031_0221e610(unsigned int);
extern "C" void func_ov031_0221d060(int);

// USA: func_ov031_0221d604
extern "C" THUMB int func_ov031_0221d604(int state, Struct_ov031_0221d3b0_2* packet, int* counter, Struct_ov031_0221d3b0_3* arg3) {
    if (state != 2) { ++*counter; return state; }
    Struct_ov031_0221d450* record = &packet->body;
    Struct_ov031_0221d3b0* header = (Struct_ov031_0221d3b0*)((unsigned char*)packet + 12);
    if (func_ov031_0221d7e0(&arg3->entries[2], &header->unknown_10_) < 0) { ++*counter; return state; }
    if (record->type != 7) { ++*counter; return state; }
    if (func_ov031_0221e638(record->unknown_2_) == 0) { ++*counter; return state; }
    if (func_ov031_0221e610(record->status) == 0) return 100;
    if (func_ov031_0221e610(record->status) == -2) {
        func_ov031_0221d060(20);
        return -1;
    }
    if (func_ov031_0221e610(record->status) == -3) {
        func_ov031_0221d060(21);
        return -1;
    }
    func_ov031_0221d060(24);
    return -1;
}
