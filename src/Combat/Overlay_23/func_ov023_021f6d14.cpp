#include <globaldefs.h>

struct Struct_ov023_021f6d14_2 {
    unsigned int key;
    int pad4;
    struct Struct_ov023_021f6d14_2* prev;
    struct Struct_ov023_021f6d14_2* next;
};

struct Struct_ov023_021f6d14 { char pad[0x28]; struct Struct_ov023_021f6d14_2* head; };

// USA: func_ov023_021f6d14
extern "C" ARM void func_ov023_021f6d14(struct Struct_ov023_021f6d14* list, struct Struct_ov023_021f6d14_2* node) {
    if (node == NULL) return;
    node->prev = NULL;
    node->next = NULL;
    struct Struct_ov023_021f6d14_2* cur = list->head;
    if (cur == NULL) {
        list->head = node;
        return;
    }
    while (cur != NULL) {
        if (node->key < cur->key) {
            if (cur->prev != NULL) {
                cur->prev->next = node;
            }
            node->next = cur;
            node->prev = cur->prev;
            cur->prev = node;
            if (cur == list->head) {
                list->head = node;
            }
            return;
        }
        if (cur->next == NULL) {
            cur->next = node;
            node->prev = cur;
            return;
        }
        cur = cur->next;
    }
}
