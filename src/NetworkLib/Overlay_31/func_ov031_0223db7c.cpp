#include <globaldefs.h>

#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0223db7c {
    Struct_ov031_0223db7c* previous;
    Struct_ov031_0223db7c* next;
};

struct Struct_ov031_0223db7c_2 {
    Struct_ov031_0223db7c node;
    unsigned short offset;
    unsigned short length;
};

struct Struct_ov031_0223db7c_3 {
    Struct_ov031_0223db7c_2 entries[32];
    Struct_ov031_0223db7c_2 first;
    Struct_ov031_0223db7c_2 last;
    void* list;
    void* unknown_19c_;
};

struct Struct_ov031_0223db7c_4 {
    Struct_ov031_0223db7c_3 unknown_0_[2];
};

extern Struct_ov031_0223db7c_4* data_ov031_02290d64;
extern "C" void* func_ov031_0223bfa0(void*);
extern "C" void func_ov031_0223d8d8(void*, void*);
extern "C" void HaltSystem();

static inline Struct_ov031_0223db7c_3* inline_ov031_0223db7c(int index) {
    Struct_ov031_0223db7c_3* pool = data_ov031_02290d64->unknown_0_;
    pool += index;
    return pool;
}

// USA: func_ov031_0223db7c
extern "C" ARM void* func_ov031_0223db7c(int arg0, int size, unsigned char forward, int* offset) {
    Struct_ov031_0223db7c_2* entry = static_cast<Struct_ov031_0223db7c_2*>(func_ov031_0223bfa0(inline_ov031_0223db7c(arg0)->unknown_19c_));
    Struct_ov031_0223db7c_2* cursor;
    Struct_ov031_0223db7c_2* var2;
    unsigned long var3;
    int start;
    int var5 = ((size + 3) & ~3) >> 2;
    entry->length = var5;
    var3 = DisableSpecificInterrupts(1);
    if (forward) {
        cursor = &inline_ov031_0223db7c(arg0)->first;
        if (cursor != &inline_ov031_0223db7c(arg0)->last) {
            do {
                var2 = (Struct_ov031_0223db7c_2*)cursor->node.next;
                start = cursor->offset + cursor->length;
                if (start + var5 <= var2->offset) {
                    entry->offset = start;
                    func_ov031_0223d8d8(var2, entry);
                    break;
                }
                cursor = var2;
            } while (cursor != &data_ov031_02290d64->unknown_0_[arg0].last);
        }
        if (cursor == &data_ov031_02290d64->unknown_0_[arg0].last) {
            HaltSystem();
        }
    } else {
        cursor = &inline_ov031_0223db7c(arg0)->last;
        if (cursor != &inline_ov031_0223db7c(arg0)->first) {
            do {
                var2 = (Struct_ov031_0223db7c_2*)cursor->node.previous;
                start = cursor->offset - var5;
                if (start >= var2->offset + var2->length) {
                    entry->offset = start;
                    func_ov031_0223d8d8(cursor, entry);
                    break;
                }
                cursor = var2;
            } while (cursor != &data_ov031_02290d64->unknown_0_[arg0].first);
        }
        if (cursor == &data_ov031_02290d64->unknown_0_[arg0].first) {
            HaltSystem();
        }
    }
    *offset = entry->offset;
    EnableSpecificInterrupts(var3);
    return entry;
}
