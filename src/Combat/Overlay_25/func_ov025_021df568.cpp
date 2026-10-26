#include <globaldefs.h>

struct Struct_ov025_021def64_2 {
    int key;
    struct Struct_ov025_021def64_2* prev;
    struct Struct_ov025_021def64_2* next;
};

// USA: func_ov025_021df568
extern "C" ARM struct Struct_ov025_021def64_2* func_ov025_021df568(struct Struct_ov025_021def64_2* head, struct Struct_ov025_021def64_2* arg1) {
    struct Struct_ov025_021def64_2* cur = head;
    while (cur != NULL) {
        if (arg1->key < cur->key) {
            if (cur->prev != NULL) {
                cur->prev->next = arg1;
            }
            arg1->next = cur;
            arg1->prev = cur->prev;
            cur->prev = arg1;
            if (cur == head) {
                head = arg1;
            }
            return head;
        }
        if (cur->next == NULL) {
            cur->next = arg1;
            arg1->prev = cur;
            return head;
        }
        cur = cur->next;
    }
    return head;
}
