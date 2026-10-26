#include <globaldefs.h>

struct Struct_0205e1e4_2 {
    char pad[0x18];
    struct Struct_0205e1e4_2* next;
};
struct Struct_0205e1e4 {
    struct Struct_0205e1e4_2* head;
    struct Struct_0205e1e4_2* tail;
    int count;
};

extern "C" void VCountIrq_PushDisable(void);
extern "C" void VCountIrq_PopDisable(void);

// USA: func_0205e1e4
extern "C" ARM struct Struct_0205e1e4_2* func_0205e1e4(struct Struct_0205e1e4* list) {
    struct Struct_0205e1e4_2* head;
    VCountIrq_PushDisable();
    head = list->head;
    if (head != NULL) {
        list->head = head->next;
        list->count--;
    }
    VCountIrq_PopDisable();
    return head;
}
