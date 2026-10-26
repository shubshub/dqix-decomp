#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_020d2404 {
    struct Struct_020d2404* next;
};
struct Struct_02112780_9 {
    struct Struct_020d2404* head;
    unsigned char pad[0xc];
    struct Struct_020d2404* tail;
};
extern struct Struct_02112780_9 data_02112780;

// USA: func_020d28a8
extern "C" ARM struct Struct_020d2404* func_020d28a8(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct Struct_020d2404* node = data_02112780.head;
    if (node == NULL) {
        SetIRQInterruptState(mask);
        return NULL;
    }
    struct Struct_020d2404* next = node->next;
    data_02112780.head = next;
    if (next == NULL) {
        data_02112780.tail = NULL;
    }
    SetIRQInterruptState(mask);
    return node;
}
