#include <globaldefs.h>

struct Struct_0210cfd0 {
    char unknown_0_[8];
    struct Struct_0210cfd0* next;
};

struct Struct_020cee54 {
    struct Struct_0210cfd0* head;
};

// USA: func_020cee54
extern "C" ARM void func_020cee54(struct Struct_020cee54* list, struct Struct_0210cfd0* node) {
    if (list != 0) {
        node->next = list->head;
        list->head = node;
    }
}
