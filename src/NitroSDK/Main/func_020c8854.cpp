#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_020c8784;
extern "C" Struct_020c8784* func_020c8784(Struct_020c8784* head, Struct_020c8784* node);

struct Struct_020c8768;
extern "C" Struct_020c8768* func_020c8768(Struct_020c8768* arg0, Struct_020c8768* arg1);

struct Struct_020c87ac {
    struct Struct_020c87ac* prev;
    struct Struct_020c87ac* next;
    unsigned int size;
};

struct Struct_020c8854 {
    int unk0;
    struct Struct_020c87ac* unknown_4_;
    struct Struct_020c8784* unknown_8_;
};

struct Struct_020c8854_2 {
    int unknown_0_;
    char pad4[0xc];
    struct Struct_020c8854* entries;
};

extern struct Struct_020c8854_2* data_02111564[];

// USA: func_020c8854
extern "C" ARM void* func_020c8854(int tableIdx, int count, int size) {
    struct Struct_020c8854_2* table;
    struct Struct_020c8854* entry;
    struct Struct_020c87ac* cursor;
    int state;
    state = DisableIRQInterrupts();
    table = data_02111564[tableIdx];
    if (table == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    if (count < 0) {
        count = table->unknown_0_;
    }
    entry = &table->entries[count];
    cursor = entry->unknown_4_;
    size = (size + 0x3f) & ~0x1f;
    if (cursor != 0) {
        do {
            if (size <= (int)cursor->size) break;
            cursor = cursor->next;
        } while (cursor != 0);
    }
    if (cursor == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    unsigned int remaining = cursor->size - size;
    if (remaining < 0x40) {
        entry->unknown_4_ = (struct Struct_020c87ac*)func_020c8784((struct Struct_020c8784*)entry->unknown_4_, (struct Struct_020c8784*)cursor);
    } else {
        cursor->size = size;
        struct Struct_020c87ac* var5 = (struct Struct_020c87ac*)((char*)cursor + size);
        var5->size = remaining;
        var5->prev = cursor->prev;
        var5->next = cursor->next;
        if (var5->next != 0) {
            var5->next->prev = var5;
        }
        if (var5->prev != 0) {
            var5->prev->next = var5;
        } else {
            entry->unknown_4_ = var5;
        }
    }
    entry->unknown_8_ = (struct Struct_020c8784*)func_020c8768((struct Struct_020c8768*)entry->unknown_8_, (struct Struct_020c8768*)cursor);
    SetIRQInterruptState(state);
    return (char*)cursor + 0x20;
}
