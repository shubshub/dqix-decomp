#include <globaldefs.h>

struct Struct_020cef0c {
    void (*fn)(void*);
    void* arg;
    struct Struct_020cef0c* next;
};

// USA: func_020cef0c
extern "C" ARM void func_020cef0c(struct Struct_020cef0c* node) {
    if (node == 0) return;
    do {
        node->fn(node->arg);
        node = node->next;
    } while (node != 0);
}
