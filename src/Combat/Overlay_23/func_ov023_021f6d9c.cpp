#include <globaldefs.h>

struct Struct_ov023_021f6d9c_2 {
    char pad0[0x8];
    struct Struct_ov023_021f6d9c_2* prev;
    struct Struct_ov023_021f6d9c_2* next;
};

struct Struct_ov023_021f6d9c {
    char pad0[0x28];
    struct Struct_ov023_021f6d9c_2* cur;
};

// USA: func_ov023_021f6d9c
extern "C" ARM void func_ov023_021f6d9c(struct Struct_ov023_021f6d9c* owner, struct Struct_ov023_021f6d9c_2* node) {
    if (node == NULL) {
        return;
    }
    if (node == owner->cur) {
        owner->cur = node->next;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}
