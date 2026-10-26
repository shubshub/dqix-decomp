#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020553ac;
extern "C" void func_020553ac(struct Struct_020553ac* obj);
struct Struct_02055558;
extern "C" int func_02055558(struct Struct_02055558* obj, int a2, int a3, int a4, int a5, int a6);

struct Struct_02057e6c {
    unsigned char pad[0x1ec];
    struct Struct_02057e6c* next;
};

struct Struct_02057e6c_2 {
    struct Struct_02057e6c* head;
    int count;
};

// USA: func_02057e6c
extern "C" ARM int func_02057e6c(Struct_02057e6c_2* list, int p1, SafeAllocator* alloc, int p2, int p3, int p4) {
    Struct_02057e6c* node = (Struct_02057e6c*)alloc->Allocate(0x1f0);
    if (node == NULL) return -1;
    func_020553ac((struct Struct_020553ac*)node);
    if (func_02055558((struct Struct_02055558*)node, p1, (int)alloc, p2, p3, p4) == 0) return -1;
    Struct_02057e6c** slot = &list->head;
    while (*slot != NULL) slot = &(*slot)->next;
    *slot = node;
    return list->count++;
}
