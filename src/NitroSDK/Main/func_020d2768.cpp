#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Struct_020d2768 {
    struct Struct_020d2768* next;
};
struct Struct_02112780_7 {
    struct Struct_020d2768* head;
};
extern struct Struct_02112780_7 data_02112780;

// USA: func_020d2768
// Kept as extern "C" func_020d2768: func_020d27e0 references this symbol.
extern "C" ARM int func_020d2768(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct Struct_020d2768* node = data_02112780.head;
    int count = 0;
    if (node != NULL) {
        do {
            node = node->next;
            count++;
        } while (node != NULL);
    }
    SetIRQInterruptState(mask);
    return count;
}
