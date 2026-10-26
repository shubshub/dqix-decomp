#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0208dc84_2;
extern "C" void func_0208e000(struct Struct_0208dc84_2* dst, struct Struct_0208dc84_2* src);

struct Struct_0208df94 {
    short field0;
    unsigned short field2;
    int field4;
#if defined(jpn)
    int unknown_8_;
#endif
    struct Struct_0208df94* next;
};

struct Struct_0208dc84 {
    struct Struct_0208df94* head;
    short count;
};

// USA: func_0208df94
extern "C" ARM void func_0208df94(struct Struct_0208dc84* list, SafeAllocator* alloc, struct Struct_0208dc84_2* src) {
    struct Struct_0208df94* node = (struct Struct_0208df94*)alloc->Allocate(sizeof(Struct_0208df94));
    struct Struct_0208df94* tail = list->head;
    if (tail != NULL) {
        while (tail->next != NULL) {
            tail = tail->next;
        }
        func_0208e000((struct Struct_0208dc84_2*)node, src);
        tail->next = node;
    } else {
        list->head = node;
        func_0208e000((struct Struct_0208dc84_2*)node, src);
    }
    list->count++;
}
