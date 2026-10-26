#include <globaldefs.h>

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;
};
struct QList0205e18c {
    struct QNode0205e18c* head;
    struct QNode0205e18c* tail;
    int count;
};

void VCountIrq_PushDisable(void);
extern "C" void VCountIrq_PopDisable(void);

// USA: func_0205e18c
ARM void EnqueueNode(struct QList0205e18c* list, struct QNode0205e18c* node) {
    VCountIrq_PushDisable();
    if (list->head != NULL) {
        list->tail->next = node;
        list->tail = node;
    } else {
        list->head = node;
        list->tail = node;
        list->head->next = NULL;
    }
    list->count++;
    list->tail->next = NULL;
    VCountIrq_PopDisable();
}
