#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02055ed0_3;
extern "C" void func_02058c88(struct Struct_02055ed0_3* obj);

struct Struct_02055ed0 {
    char pad0[0x2c];
    unsigned char unknown_2c_;
    char unknown_2d_[0x148 - 0x2d];
    struct Struct_02055ed0* next;
};

struct Struct_02055ed0_2 {
    char pad0[0x28];
    SafeAllocator* allocator;
    char pad2c[0x34 - 0x2c];
    struct Struct_02055ed0* head;
};

// USA: func_02055ed0
extern "C" ARM struct Struct_02055ed0* func_02055ed0(struct Struct_02055ed0_2* self) {
    struct Struct_02055ed0** link = &self->head;
    struct Struct_02055ed0* node;
    while ((node = *link) != 0) {
        if (node->unknown_2c_ == 0) {
            return node;
        }
        link = &node->next;
    }
    struct Struct_02055ed0* var2 = 0;
    SafeAllocator* allocator = self->allocator;
    int ok;
    if (allocator == 0) {
        ok = 0;
    } else {
        var2 = (struct Struct_02055ed0*)allocator->Allocate(sizeof(struct Struct_02055ed0));
        if (var2 == 0) {
            ok = 0;
        } else {
            func_02058c88((struct Struct_02055ed0_3*)var2);
            var2->next = 0;
            ok = 1;
        }
    }
    if (!ok) {
        return 0;
    }
    func_02058c88((struct Struct_02055ed0_3*)var2);
    var2->next = 0;
    *link = var2;
    return var2;
}
