#include <globaldefs.h>

struct Struct_ov031_0223ff38 {
    struct Struct_ov031_0223ff38* prev; /* 0x0 */
    struct Struct_ov031_0223ff38* next; /* 0x4 */
};

// USA: func_ov031_0223ff38
extern "C" ARM struct Struct_ov031_0223ff38* func_ov031_0223ff38(struct Struct_ov031_0223ff38** list) {
    struct Struct_ov031_0223ff38* head = *list;
    if (head != NULL) {
        if (head == head->prev) {
            *list = NULL;
        } else {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            *list = head->next;
        }
    }
    return head;
}
