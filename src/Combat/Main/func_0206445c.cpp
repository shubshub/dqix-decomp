#include <globaldefs.h>

struct Struct_02061c04_25 {
    char unk[0x18];
    struct Struct_02061c04_25* next;
};

struct Struct_02061c04_26 {
    char unk[0x30];
    struct Struct_02061c04_25* head;
};

// USA: func_0206445c
extern "C" ARM void func_0206445c(int unused, struct Struct_02061c04_25* node, struct Struct_02061c04_26* list) {
    struct Struct_02061c04_25* cur;
    node->next = 0;
    cur = list->head;
    if (cur == 0) {
        list->head = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
