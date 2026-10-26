#include <globaldefs.h>

struct Struct_0205e18c_2 {
    char pad[0x18];
    struct Struct_0205e18c_2* next;
};
struct Struct_0205e18c {
    struct Struct_0205e18c_2* head;
    struct Struct_0205e18c_2* tail;
    int count;
};

extern "C" void VCountIrq_PushDisable(void);
extern "C" void VCountIrq_PopDisable(void);

// USA: func_0205e18c
extern "C" ARM void func_0205e18c(struct Struct_0205e18c* list, struct Struct_0205e18c_2* node) {
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
