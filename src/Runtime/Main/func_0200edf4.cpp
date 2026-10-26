#include <globaldefs.h>

struct Struct_0200edf4 {
    struct Struct_0200edf4* next;
    void (*fn)(void* arg, int flag);
    void* arg;
};
extern struct Struct_0200edf4* data_020f33b0;

// USA: func_0200edf4
extern "C" ARM void func_0200edf4(void) {
    struct Struct_0200edf4* node = data_020f33b0;
    if (node == 0) {
        return;
    }
    do {
        data_020f33b0 = node->next;
        node->fn(node->arg, -1);
        node = data_020f33b0;
    } while (node != 0);
}
