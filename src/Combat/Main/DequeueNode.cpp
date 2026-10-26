#include <globaldefs.h>

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};

void VCountIrq_PushDisable(void);
extern "C" void VCountIrq_PopDisable(void);

// USA: func_0205e1e4
ARM struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list) {
    struct QNode0205e1e4* head;
    VCountIrq_PushDisable();
    head = list->head;
    if (head != NULL) {
        list->head = head->next;
        list->count--;
    }
    VCountIrq_PopDisable();
    return head;
}
