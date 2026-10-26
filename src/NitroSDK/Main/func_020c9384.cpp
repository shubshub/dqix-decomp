#include <globaldefs.h>

struct Struct_020c9384 {
    char unknown_0_[0x14];
    struct Struct_020c9384* prev;
    struct Struct_020c9384* next;
};

struct Struct_02111654_4 {
    char unknown_0_[0xc];
    struct Struct_020c9384* head;
    struct Struct_020c9384* tail;
};

extern struct Struct_02111654_4 data_02111654;

// USA: func_020c9384
extern "C" ARM void func_020c9384(struct Struct_020c9384* node) {
    struct Struct_020c9384* prev;
    struct Struct_020c9384* next;
    if (node == NULL) {
        return;
    }
    prev = node->prev;
    next = node->next;
    if (next != NULL) {
        next->prev = prev;
    } else {
        data_02111654.tail = prev;
    }
    if (prev != NULL) {
        prev->next = next;
    } else {
        data_02111654.head = next;
    }
}
