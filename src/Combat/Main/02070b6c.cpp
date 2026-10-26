#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

union Struct_02070b6c {
    struct Header {
        unsigned short id : 15;
        unsigned short flag : 1;
    } header;
    unsigned int data[33];
};

struct Struct_02070b6c_2 {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int unknown_3_7_ : 1;
    Struct_02070b6c* elements;
    void* extra;
};

struct Struct_02070a30;
struct Struct_02070b0c;
struct Struct_02070b0c_2;
struct Struct_02070b6c_3;
struct Struct_02070b6c_4;
struct Struct_02070b6c_5;
struct Struct_020709c8;
extern "C" int func_02070af4(Struct_02070a30*);
extern "C" int func_02070b0c(Struct_02070b0c*, void (*)(Struct_02070b0c*, Struct_02070b0c_2*));
extern "C" Struct_02070b6c_4* func_02070e60(Struct_02070b6c_3*, int, int (*)(Struct_02070b6c_4*));
extern "C" Struct_02070b6c_5* func_02070ee0(Struct_02070b6c_5*, Struct_02070b6c_5*);
extern "C" int func_020709c8(Struct_020709c8*);

// USA: func_02070b6c
extern "C" ARM void func_02070b6c(Struct_02070b6c_2* self, SafeAllocator* allocator, Struct_02070b6c_2* source, unsigned int arg3, short* ids, short arg5) {
    if (!allocator || !source || !arg3 || !ids) return;
    if (arg5 <= 0) return;
    memset(self, 0, sizeof(*self));
    Struct_02070b6c_2 list;
    memset(&list, 0, sizeof(list));
    if (source) {
        memcpy(&list, source, 4);
        list.elements = (Struct_02070b6c*)((char*)source + 4);
        list.extra = (char*)source + (func_02070af4((Struct_02070a30*)&list) + 4);
        if (!list.unknown_3_7_) {
            func_02070b0c((Struct_02070b0c*)&list, 0);
            list.unknown_3_7_ = 1;
            source->unknown_3_7_ = 1;
        }
    }
    short* id = ids;
    int var2 = 0;
    for (int idCount = arg5, i = 0; i < idCount; i++, id++) {
        if (func_02070e60((Struct_02070b6c_3*)&list, *id, (int (*)(Struct_02070b6c_4*))func_020709c8)) var2++;
    }
    self->elements = (Struct_02070b6c*)allocator->Allocate(var2 * sizeof(Struct_02070b6c));
    if (self->elements) {
        self->count = var2;
        Struct_02070b6c* out;
        id = ids;
        out = self->elements;
        for (int var6 = 0; var6 < arg5; var6++, id++) {
            Struct_02070b6c* entry = (Struct_02070b6c*)func_02070e60((Struct_02070b6c_3*)&list, *id, (int (*)(Struct_02070b6c_4*))func_020709c8);
            if (entry) {
                memcpy(out, entry, sizeof(*out));
                out++;
            }
        }
    }
    if (var2 < 2) return;
    if (!self) return;
    int count = self->count;
    if (!self->elements || !count) return;
    int last = count - 1;
    Struct_02070b6c* prev;
    int var11;
    int swapped;
    int first = 0;
    Struct_02070b6c var14;
    Struct_02070b6c var15;
    do {
        int pos = first;
        swapped = -1;
        Struct_02070b6c* entry = &self->elements[first];
        for (; pos < last; entry++, pos++) {
            if (entry->header.id > entry[1].header.id) {
                swapped = pos;
                var15 = *entry;
                func_02070ee0((Struct_02070b6c_5*)entry, (Struct_02070b6c_5*)(entry + 1));
                func_02070ee0((Struct_02070b6c_5*)(entry + 1), (Struct_02070b6c_5*)&var15);
            }
        }
        if (swapped == -1) break;
        Struct_02070b6c* var18 = &self->elements[swapped];
        last = swapped;
        var11 = -1;
        for (; swapped > first; swapped--) {
            prev = var18 - 1;
            if (prev->header.id > var18->header.id) {
                var11 = swapped;
                var14 = *var18;
                func_02070ee0((Struct_02070b6c_5*)var18, (Struct_02070b6c_5*)prev);
                func_02070ee0((Struct_02070b6c_5*)prev, (Struct_02070b6c_5*)&var14);
            }
            var18 = prev;
        }
        if (var11 != -1) first = var11;
        else break;
    } while (1);
}
