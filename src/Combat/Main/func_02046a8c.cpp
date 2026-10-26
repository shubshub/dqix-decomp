#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Node02046a8c {
    char unk0[2];
    unsigned char inList;
    char unknown_3_;
    struct Node02046a8c* next;
};

struct Struct_02046a8c_2 {
    struct Node02046a8c* head;
    struct Node02046a8c* tail;
};

// USA: func_02046a8c
extern "C" ARM void func_02046a8c(struct Struct_02046a8c_2* list, struct Node02046a8c* node) {
    struct Node02046a8c* cur = list->head;
    if (cur == 0) return;
    if (cur == node) {
        list->head = node->next;
    } else {
        struct Node02046a8c* next = cur->next;
        if (next == 0) return;
        while (next != node) {
            if (next == 0) return;
            cur = next;
            next = next->next;
        }
        cur->next = next->next;
    }
    cur = list->head;
    list->tail = 0;
    while (cur != 0) {
        list->tail = cur;
        cur = cur->next;
    }
    func_0204693c((struct ByteHeader0204693c*)node);
}
