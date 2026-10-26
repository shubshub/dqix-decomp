#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020553ac;
extern "C" void func_020553ac(struct Struct_020553ac* obj);
extern "C" int func_020553ec(void* obj, int a1, void* alloc, int a2, int a3);

struct Struct_02057de0 {
    unsigned char pad[0x1ec];
    struct Struct_02057de0* next;
};

struct Struct_02057de0_2 {
    struct Struct_02057de0* head;
    int count;
};

// USA: func_02057de0
extern "C" ARM int func_02057de0(Struct_02057de0_2* list, int a1, SafeAllocator* alloc, int a2, int a3) {
    Struct_02057de0* node = (Struct_02057de0*)alloc->Allocate(0x1f0);
    if (node == NULL) return -1;
    func_020553ac((struct Struct_020553ac*)node);
    if (func_020553ec(node, a1, alloc, a2, a3) == 0) return -1;
    Struct_02057de0** slot = &list->head;
    while (*slot != NULL) slot = &(*slot)->next;
    *slot = node;
    return list->count++;
}
