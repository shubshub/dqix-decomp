#include <globaldefs.h>

struct ListNode02046b38 {
    char pad[4];
    struct ListNode02046b38* next;
};

struct ListHead02046b38 {
    struct ListNode02046b38* head;
};

// USA: func_02046b38
extern "C" ARM int func_02046b38(struct ListHead02046b38* list, struct ListNode02046b38* target) {
    struct ListNode02046b38* node = list->head;
    while (node != 0) {
        if (node == target) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
