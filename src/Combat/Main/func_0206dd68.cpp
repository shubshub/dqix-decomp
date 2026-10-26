#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct Struct_0206dd68 {
    char pad[0x64];
    struct Struct_0206dd68* prev;
    struct Struct_0206dd68* next;
};

// USA: func_0206dd68
extern "C" ARM void func_0206dd68(void* base, int key) {
    struct Struct_0206dd68* node = (Struct_0206dd68*)func_0206db20(base, key);
    if (node == NULL) {
        return;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *(struct Struct_0206dd68**)base = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}
