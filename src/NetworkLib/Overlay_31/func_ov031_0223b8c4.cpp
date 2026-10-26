#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"


struct Struct_ov031_0223b8c4 {
    Struct_ov031_0223b8c4* prev;
    Struct_ov031_0223b8c4* next;
    unsigned char* buffer;
    unsigned char count;
    char pad0d[3];
};

struct Struct_ov031_0223b8c4_2 {
    char pad0[0x200];
    Struct_ov031_0223b8c4 front;
    Struct_ov031_0223b8c4 back;
    int unknown_220_;
    void* unknown_224_;
};

extern Struct_ov031_0223b8c4_2* data_ov031_02290d28;
extern "C" Struct_ov031_0223b8c4* func_ov031_0223bfa0(void*);
extern "C" void func_ov031_0223d8d8(Struct_ov031_0223b8c4*, Struct_ov031_0223b8c4*);
extern "C" void HaltSystem();

static inline Struct_ov031_0223b8c4_2* inline_ov031_0223b8c4(int index) {
    Struct_ov031_0223b8c4_2* region = data_ov031_02290d28;
    region += index;
    return region;
}

// USA: func_ov031_0223b8c4
extern "C" ARM Struct_ov031_0223b8c4* func_ov031_0223b8c4(int region, int count, int fromFront) {
    Struct_ov031_0223b8c4* result = func_ov031_0223bfa0(inline_ov031_0223b8c4(region)->unknown_224_);
    Struct_ov031_0223b8c4* node;
    unsigned int var2 = DisableSpecificInterrupts(1);
    if (fromFront) {
        node = &inline_ov031_0223b8c4(region)->front;
        if (node != &inline_ov031_0223b8c4(region)->back) {
            do {
                Struct_ov031_0223b8c4* next = node->next;
                unsigned char* start = node->buffer + node->count * 8;
                if (start + count * 8 <= next->buffer) {
                    result->buffer = start;
                    func_ov031_0223d8d8(next, result);
                    break;
                }
                node = next;
            } while (node != &data_ov031_02290d28[region].back);
        }
        if (node == &data_ov031_02290d28[region].back) HaltSystem();
    } else {
        node = &inline_ov031_0223b8c4(region)->back;
        if (node != &inline_ov031_0223b8c4(region)->front) {
            do {
                Struct_ov031_0223b8c4* prev = node->prev;
                unsigned char* start = node->buffer - count * 8;
                if (start >= prev->buffer + prev->count * 8) {
                    result->buffer = start;
                    func_ov031_0223d8d8(node, result);
                    break;
                }
                node = prev;
            } while (node != &data_ov031_02290d28[region].front);
        }
        if (node == &data_ov031_02290d28[region].front) HaltSystem();
    }
    EnableSpecificInterrupts(var2);
    result->count = count;
    return result;
}
