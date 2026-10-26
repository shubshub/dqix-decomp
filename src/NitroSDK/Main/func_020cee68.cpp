#include <globaldefs.h>


struct Struct_0210cfdc {
    char unknown_0_[8];
    struct Struct_0210cfdc* next;
};

struct Struct_020cee68 {
    struct Struct_0210cfdc* head;
};

// USA: func_020cee68
extern "C" ARM void func_020cee68(struct Struct_020cee68* list, struct Struct_0210cfdc* node) {
    struct Struct_0210cfdc* cur;
    struct Struct_0210cfdc* next;
    if (list == 0) return;
    cur = list->head;
    if (cur == 0) {
        node->next = 0;
        list->head = node;
        return;
    }
    next = cur->next;
    if (next != 0) {
        do {
            cur = next;
            next = next->next;
        } while (next != 0);
    }
    node->next = next;
    cur->next = node;
}
