#include <globaldefs.h>

struct Struct_020d794c_2 {
    short unk0;
    short key;
    int value;
    struct Struct_020d794c_2* next;
};

struct Struct_020d794c {
    struct Struct_020d794c_2* head;
};

// USA: func_020d794c
extern "C" ARM int func_020d794c(struct Struct_020d794c* list, int key) {
    struct Struct_020d794c_2* node = list->head;
    while (node != 0) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}
