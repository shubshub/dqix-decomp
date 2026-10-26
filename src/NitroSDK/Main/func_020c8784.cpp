#include <globaldefs.h>

struct Struct_020c8784 {
    struct Struct_020c8784* prev;
    struct Struct_020c8784* next;
};

// USA: func_020c8784
extern "C" ARM struct Struct_020c8784* func_020c8784(struct Struct_020c8784* head, struct Struct_020c8784* node) {
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev == 0) {
        head = node->next;
    } else {
        node->prev->next = node->next;
    }
    return head;
}
