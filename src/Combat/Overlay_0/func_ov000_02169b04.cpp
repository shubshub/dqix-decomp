#include <globaldefs.h>

struct Struct_ov000_02169b04_2 {
    int key;
    struct Struct_ov000_02169b04_2* next;
};
struct Struct_ov000_02169b04 {
    char pad[8];
    struct Struct_ov000_02169b04_2* head;
};

// USA: func_ov000_02169b04
extern "C" ARM struct Struct_ov000_02169b04_2* func_ov000_02169b04(struct Struct_ov000_02169b04* list, int key) {
    struct Struct_ov000_02169b04_2* node = list->head;
    while (node) {
        if (node->key == key) return node;
        node = node->next;
    }
    return NULL;
}
