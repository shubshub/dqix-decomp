#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Struct_020d27a4 {
    struct Struct_020d27a4* next;
};
struct Struct_02112780_8 {
    struct Struct_020d27a4* field0;
    struct Struct_020d27a4* field4;
    struct Struct_020d27a4* unknown_8_;
};
extern struct Struct_02112780_8 data_02112780;

// USA: func_020d27a4
// Kept as extern "C" func_020d27a4: func_020d27e0 references this symbol.
extern "C" ARM int func_020d27a4(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct Struct_020d27a4* node = data_02112780.unknown_8_;
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
