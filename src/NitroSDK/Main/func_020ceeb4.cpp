#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_020ceeb4 {
    int field0;
    int field4;
    struct Struct_020ceeb4* next;
};

// USA: func_020ceeb4
extern "C" ARM void func_020ceeb4(struct Struct_020ceeb4** head, struct Struct_020ceeb4* target) {
    unsigned int mask;
    struct Struct_020ceeb4* node;
    struct Struct_020ceeb4* prev;
    if (head == NULL) {
        return;
    }
    mask = DisableIRQInterrupts();
    node = *head;
    prev = node;
    if (node != NULL) {
        do {
            if (node == target) {
                if (node == prev) {
                    *head = node->next;
                } else {
                    prev->next = node->next;
                }
                break;
            }
            prev = node;
            node = node->next;
        } while (node != NULL);
    }
    SetIRQInterruptState(mask);
}
